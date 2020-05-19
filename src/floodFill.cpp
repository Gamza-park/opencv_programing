#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int click_x = 0;
int click_y = 0;

void func(int event, int x, int y, int flags, void* userdata)
{
    if(event == EVENT_LBUTTONDOWN)
    {
        cout << x << "," << y << endl;

        click_x = x;
        click_y = y;
    }
}

int main()
{
    int width = 500;
    int height = 500;
    int count = 10;
    srand(time(0));

    namedWindow("img",1);

    Mat img = Mat(width,height,CV_8UC1);
    img.setTo(0);

    setMouseCallback("img",func,&img);

    int x,y,w,h;
    for(int i=0; i<count; ++i)
    {
        x = rand() % width;
        y = rand() % height;
        w = rand() % (x-width);
        h = rand() % (y-height);

        cout << i << "," << x << "," << y << "," << x+w << "," << y+h << "," << w << "," << h << endl; 
        rectangle(img,Rect(x,y,w,h),Scalar(255,255,255),1);
    }

    while(1)
    {
        if(click_x !=0 && click_y != 0)
        {
            floodFill(img,Point(click_x,click_y),Scalar(255));
            click_x = 0;
            click_y = 0;


            
        }
        imshow("img",img);
        char key = (char)cv::waitKey(1); // End Condition "Press 'q' button"
        if(key == 'q')
        {
            break;
        }
    }

    return 0;
}