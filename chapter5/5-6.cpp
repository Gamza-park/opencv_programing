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
    add(fimg,Scalar(1),fimg);

    Mat logimg;
    log(fimg,logimg);

    double minVal, maxVal;
    minMaxLoc(logimg,&minVal,&maxVal);
    cout << "before normalizing in logimg" << endl;
    cout << "minVal = " << minVal << endl;
    cout << "maxVal = " << maxVal << endl;

    normalize(logimg,logimg,0,1.0,NORM_MINMAX);
    minMaxLoc(logimg,&minVal,&maxVal);
    cout << "after normalizing in logimg" << endl;
    cout << "minVal = " << minVal << endl;
    cout << "maxVal = " << maxVal << endl;

    imshow("logimg",logimg);
    waitKey();
    return 0;
}