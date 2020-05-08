#include "opencv2/opencv.hpp"


using namespace cv;
using namespace std;

int main(){
    Mat src = imread("/home/park/opencv_programing/chapter4/lena.jpg",IMREAD_COLOR);
    if(src.empty()){
        return -1;
    }

    Mat dst = Mat::zeros(src.rows,src.cols,src.type());

    int N = 2;
    int nWidth = src.cols;
    int nHeight = src.rows;
    int x,y;
    Rect rtROI;
    Mat roi;
    for(int i = 0; i<N; i++){
        for(int j=0; j<N; j++){
            x=j*nWidth;
            y=i*nHeight;
            rtROI=Rect(x,y,nWidth,nHeight);
            roi = src(rtROI);
            dst(rtROI)=mean(roi);
        }
    }
    imshow("dst",dst);
    waitKey();
    return 0;
}
