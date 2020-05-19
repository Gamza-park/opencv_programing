#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){
    Mat src = imread("/home/park/opencv_programing/chapter5/lena.jpg",IMREAD_GRAYSCALE);
    if(src.empty()){
        return -1;
    }

    Mat_<uchar> lut(1,256);
    for(int i=0; i<256; i++){
        lut(i) = 256-i;
    }

    Mat dst;
    LUT(src,lut,dst);
    imshow("dst",dst);
    waitKey();
    return 0;
}