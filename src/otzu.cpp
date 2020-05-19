#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    namedWindow("img",0);
    namedWindow("binary",0);

    Mat img = imread("/home/park/Opencv_practice/book.jpg");

    Mat gray, binary, binary_th, binary_ad;
    cvtColor(img,gray,COLOR_RGB2GRAY);

    threshold(gray,binary_th,128,255,THRESH_BINARY);
    adaptiveThreshold(gray,binary_ad,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,9,5);
    GaussianBlur(gray,gray,Size(7,7),0);
    threshold(gray,binary,0,255,THRESH_BINARY+THRESH_OTSU);

    imshow("img", img);
    imshow("otsu", binary);
    imshow("binary_th",binary_th);
    imshow("binary_ad",binary_ad);

    waitKey();

    return 0;

}