#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main()
{
    Mat src1 = imread("/home/park/opencv_programing/chapter3/lena.jpg", -1);
    if(src1.empty()){
        return -1;
    }

    cout << "src1.type " << src1.type() << endl;
    cout << "src1.depth " << src1.depth() << endl;
    cout << "src1.channels " << src1.channels() << endl;

    Mat src2 = imread("/home/park/chapter3/lena.jpg", IMREAD_COLOR);
    if(src2.empty()){
        return -1;
    }

    cout << "src2.type " << src2.type() << endl;
    cout << "src2.depth " << src2.depth() << endl;
    cout << "src2.channels " << src2.channels() << endl;

    Mat src3 = imread("/home/park/chapter3/lena.jpg", IMREAD_GRAYSCALE);
    if(src3.empty()){
        return -1;
    }

    cout << "src3.type " << src3.type() << endl;
    cout << "src3.depth " << src3.depth() << endl;
    cout << "src3.channels " << src3.channels() << endl;

    imwrite("lena.bmp",src1);

    vector<int> params;
    params.push_back(IMWRITE_JPEG_QUALITY);
    params.push_back(100);
    imwrite("lena2.jpg",src2,params);

    params.clear();
    params.push_back(IMWRITE_PNG_COMPRESSION);
    params.push_back(9);
    imwrite("lena.png",src3,params);

    imshow("src1",src1);
    imshow("src2",src2);
    imshow("src3",src3);
    
    waitKey();

    return 0;

}