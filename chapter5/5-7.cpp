#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){
    Mat src = imread("/home/park/opencv_programing/chapter5/lena.jpg",IMREAD_GRAYSCALE);
    if(src.empty()){
        return -1;
    }

    Mat fimg;
    src.convertTo(fimg,CV_32F);

    double power = 4;
    Mat powimg;
    pow(fimg,power,powimg);

    double minVal , maxVal;
    minMaxLoc(powimg,&minVal, &maxVal);
    cout << "before normalizing in logimg" << endl;
    cout << "minVal = " << minVal << endl;
    cout << "maxVal = " << maxVal << endl;

    normalize(powimg,powimg,0,1.0,NORM_MINMAX);
    minMaxLoc(powimg,&minVal,&maxVal);
    cout << "after normalizing in logimg" << endl;
    cout << "minVal = " << minVal << endl;
    cout << "maxVal = " << maxVal << endl;


    imshow("powimg",powimg);
    waitKey();
    return 0;
}