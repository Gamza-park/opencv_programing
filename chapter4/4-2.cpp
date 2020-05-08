#include "opencv2/opencv.hpp"


using namespace cv;
using namespace std;

int main(){
    Mat src = imread("/home/park/opencv_programing/chapter4/lena.jpg",IMREAD_GRAYSCALE);
    if(src.empty()){
        cout << "No Img" << endl;
        return -1;
    }

    Rect rtROI(0,0,256,256);
    Mat roi = src(rtROI);
    rectangle(src,rtROI,Scalar::all(0));
    imshow("src",src);

    Mat dst = repeat(roi,2,2);
    imshow("dst",dst);
    waitKey();

    return 0;
}
