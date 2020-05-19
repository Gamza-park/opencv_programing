#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){
    Mat src = imread("/home/park/opencv_programing/chapter5/lena.jpg",IMREAD_GRAYSCALE);
    if(src.empty()){
        return -1;
    }

    double minVal, maxVal;
    Point minLoc, maxLoc;
    minMaxLoc(src,&minVal,&maxVal,&minLoc,&maxLoc);
    cout << "In src " << endl;
    cout << "minVal = " << minVal << endl;
    cout << "maxVal = " << maxVal << endl;
    cout << "minLoc = " << minLoc << endl;
    cout << "maxLoc = " << maxLoc << endl;

    Mat dst;
    double scale = 100.0;
    src.convertTo(dst,-1,scale,-scale*minVal) ;

    minMaxLoc(dst,&minVal,&maxVal, &minLoc, &maxLoc);
    cout << "In dst " << endl;
    cout << "minVal = " << minVal << endl;
    cout << "maxVal = " << maxVal << endl;
    cout << "minLoc = " << minLoc << endl;
    cout << "maxLoc = " << maxLoc << endl;

    imshow("dst",dst);
    waitKey();
    return 0;
}