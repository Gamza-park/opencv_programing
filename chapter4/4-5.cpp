#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){
    Mat src = imread("/home/park/opencv_programing/chapter4/lena.jpg");
    if(src.empty()){
        return -1;
    }

    Mat imR(src.rows,src.cols,CV_8UC1);
    Mat imG(src.rows,src.cols,CV_8UC1);
    Mat imB(src.rows,src.cols,CV_8UC1);

    Mat out[] = {imB,imG,imR};
    int fromTo[]={0,0,1,1,2,2};
    mixChannels(&src,1,out,3,fromTo,3);

    Mat dst(src.rows,src.cols,src.type());
    mixChannels(out,3,&dst,1,fromTo,3);
    
    imshow("dst",dst);
    waitKey();
    return 0;
}
