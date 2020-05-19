#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    namedWindow("img",0);
    namedWindow("threshold",0);
    namedWindow("mean_thres",0);
    namedWindow("gauss_thres",0);

    Mat img = imread("/home/park/Opencv_practice/book.jpg");

    Mat gray,binary,binary1,binary2;
    cvtColor(img,gray,COLOR_RGB2GRAY);

    threshold(gray,binary,128,255,THRESH_BINARY);
    adaptiveThreshold(gray,binary1,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,15,5);
    adaptiveThreshold(gray,binary2,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY,15,5);

    imshow("img",img);
    imshow("threshold",binary);
    imshow("mean_thres",binary1);
    imshow("gauss_thres",binary2);

    waitKey();

    return 0;
}