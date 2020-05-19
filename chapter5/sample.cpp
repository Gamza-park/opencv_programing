#include "opencv2/opencv.hpp"
#include "opencv2/aruco.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(void)
{
    VideoCapture capture(0);
    Mat frame;

    if(!capture.isOpened())
    {
        cout << "plz check camera. " << endl;
        return -1;
    }

    while(1)
    {
        cout << "1" << endl;
        capture >> frame;
        if(frame.empty())
        {
            break;
        }
        Sobel(frame,frame,frame.depth(),1,0);
        char key = (char)cv::waitKey(1);

        imshow("img",frame);
        if(key == 'a')
        {
            break;
        }
    }

    return 0;

}
 
