#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){
    Mat img(512,512,CV_8UC3,Scalar(255,255,255));

    Point pts1[4] = {Point(100,100),Point(200,100),Point(200,200),Point(100,200)};
    Point pts2[3] = {Point(300,200),Point(400,100),Point(400,200)};

    const Point *polygons[2] = {pts1,pts2};
    int npts[2] = {4,3};

    polylines(img,polygons,npts,2,true,Scalar(255,0,0));

    imshow("img",img);
    waitKey();

    return 0;
}