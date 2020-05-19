#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int g_slider; // pos value
int g_slider_max; // max value

int main()
{
    Mat edges;
    VideoCapture cap = VideoCapture(0);

    if(!cap.isOpened())
    {
        return -1;
    }

    g_slider = 0 ;
    g_slider_max = 255;
    namedWindow("edges",1);

    createTrackbar("TrackbarName","edges",&g_slider,g_slider_max);

    while(1)
    {
        Mat frame;
        cap >> frame;
        cvtColor(frame,edges,COLOR_BGR2GRAY);
        GaussianBlur(edges,edges,Size(7,7),1.5,1.5);
        Canny(edges,edges,g_slider,30,3);
        char key = (char)cv::waitKey(1); // End Condition "Press 'q' button"
        imshow("edges",edges);
        if(key == 'q')
        {
            break;
        }
    }

}