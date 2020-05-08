#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main()
{
    Mat src = imread("/home/park/chapter3/lena.jpg",IMREAD_GRAYSCALE);
    if(src.empty()){
        cout << "No img" << endl;
        return -1;}

    cout << "Img" << endl;
    Point pt1(10,10),pt2(400,400);
    LineIterator it(src,pt1,pt2,8);

    vector<uchar> buffer(it.count);
    for(int i=0; i<it.count; i++, ++it)
    {
        buffer[i] = **it;
    }
    cout << (Mat)buffer << endl;
    line(src,pt1,pt2,Scalar(255),2);

    Mat dstImage(512,512,CV_8UC3,Scalar(255,255,255));
    pt1 = Point(0,dstImage.cols-buffer[0]);
    for(int i =1; i<buffer.size(); i++){
        pt2 = Point(i, dstImage.cols-buffer[i]);
        line(dstImage,pt1,pt2,Scalar(255),2);
        pt1 = pt2;
    } 
    imshow("src",src);
    imshow("dst",dstImage);

    waitKey();
    return 0;

}