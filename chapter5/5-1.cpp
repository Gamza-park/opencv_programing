#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){
    Mat src = imread("/home/park/opencv_programing/chapter5/lena.jpg",IMREAD_GRAYSCALE);
    if(src.empty()){
        return -1;
    }

    Mat_<uchar> image(src);
    Mat_<uchar>dst(src.size());

    for(int y=0; y<image.rows; y++){
        for(int x=0; x<image.cols; x++){
        uchar r = image(y,x);
        dst(y,x) =255-r;
        }
    }
    imshow("dst",dst);
    waitKey();
    return 0;
}