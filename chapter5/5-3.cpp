#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){
    Mat src = imread("/home/park/opencv_programing/chapter5/lena.jpg",IMREAD_GRAYSCALE);
    if(src.empty()){
        return -1;
    }

    Mat dst1;
    double th1 = threshold(src,dst1,100,255,THRESH_BINARY);
    cout << "th1 = " << th1 << endl;

    Mat dst2;
    double th2 = threshold(src,dst2,100,255,THRESH_BINARY  + THRESH_OTSU);
    cout << "th2 = " << th2 << endl;


    imshow("dst1",dst1);
    imshow("dst2",dst2);
    waitKey();
    return 0;
}