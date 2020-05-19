#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){
    Mat src = imread("/home/park/opencv_programing/chapter5/lena.jpg",IMREAD_GRAYSCALE);
    if(src.empty()){
        return -1;
    }

    Mat dst1;
    adaptiveThreshold(src,dst1,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,21,5);

    Mat dst2;
    adaptiveThreshold(src,dst2,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY,21,5);

    imshow("dst1",dst1);
    imshow("dst2",dst2);
    waitKey();
    return 0;
}