#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){
    Mat img(512,512,CV_8UC3,Scalar::all(255));

    rectangle(img,Point(100,100),Point(400,400),Scalar(255,0,0),-1);

    vector<uchar> buf1;
    imencode(".bmp",img,buf1);
    Mat dst1 = imdecode(buf1,IMREAD_COLOR);
   
    imshow("dst1",dst1);
    ofstream outfile1("test.bmp",ios::binary);
    outfile1.write((const char*)buf1.data(),buf1.size());
    outfile1.close();

    vector<int> params;
    params.push_back(IMWRITE_JPEG_CHROMA_QUALITY);
    params.push_back(90);

    vector<uchar> buf2;
    imencode(".jpg",img,buf2,params);

    Mat dst2 = imdecode(buf2,IMREAD_COLOR);
    imshow("dst2", dst2);

    ofstream outfile2("test.jpg",ios::binary);
    outfile2.write((const char*)buf2.data(),buf2.size());
    outfile2.close();

    params.clear();
    params.push_back(IMWRITE_PNG_COMPRESSION);
    params.push_back(9);

    vector<uchar> buf3;
    imencode(".png",img,buf3,params);
    
    Mat dst3 = imdecode(buf3,IMREAD_COLOR);
    imshow("dst3",dst3);

    ofstream outfile3("test.png",ios::binary);
    outfile3.write((const char*)buf3.data(),buf3.size());
    outfile3.close();
    waitKey();
    
    return 0;
}