#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){
    Mat src = imread("/home/park/opencv_programing/chapter5/lena.jpg",IMREAD_GRAYSCALE);
    if(src.empty()){
        return -1;
    }

    int histSize = 32;
    float valueRange[] = {0,256};
    const float* range[] = {valueRange};
    int ch = 0;
    int dims = 1;

    Mat hist;
    calcHist(&src,1,&ch,Mat(),hist,1,&histSize,range);

    Mat histimg(512,512,CV_8U);
    normalize(hist,hist,0,histimg.rows,NORM_MINMAX,CV_32F);
    int x1,y1,x2,y2;

    for(int i=0; i < histSize; i++){
        x1 = i*binW;
        y1 = histimg.rows;
        x2 = (i+1) * binW;
        y2 = histimg.rows-cvRound(hist.at<float>(i));
        rectangle(histimg,Point(x1,y1),Point(x2,y2),Scalar(0),-1);
    }
    imshow("img",histimg);
    waitKey();
    return 0;
}