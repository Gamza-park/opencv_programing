#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <thread>
#include <iostream>

using namespace std;
using namespace cv;

Mat Map(1000,1000,CV_8UC1,Scalar::all(255));
int x[2];
int point_x,point_y;


void circle_thread(){
    
    for(int i=0; i<2; i++){
        x[i] = rand() %1000;
    }
        
    circle(Map,Point(x[0],x[1]),15,Scalar::all(0),-1);
    
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN)
    {   
        circle(*(Mat*)userdata,Point(x,y),1000,Scalar::all(255),-1);
        point_x=x;
        point_y=y;
        // cout << "Click Location = (" << x << ", " << y << ")" << endl;
    }

    imshow("Game",*(Mat*)userdata);
}


int main()
{   

    cout << "Please click to circle" << endl << "start in 3 seconds later " << endl;

    waitKey(3000);

    namedWindow("Game");

    int score = 0;

    for(int i =0; i<5; i++){
        thread t1(circle_thread);
        t1.join();
        // cout << "Point Location = (" << x[0] << ", " << x[1] << ")" << endl;

        setMouseCallback("Game", CallBackFunc, &Map);

        imshow("Game", Map);

        waitKey(1000);  

        
        if(abs(x[0]-point_x) < 15 & abs(x[1]-point_y)<15)
        {
            score++;
        }
    }
    
    cout << "score is [ " << score << " ]" << endl;
    return 0;
}