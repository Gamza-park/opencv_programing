#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main()
{
    Mat img = imread("/home/park/opencv_programing/chapter3/lena.jpg",IMREAD_GRAYSCALE);
    if(img.empty()){
        cout << "No img" << endl;
        return -1;}

    namedWindow("img",WINDOW_NORMAL);
    imshow("img",img);
    waitKey(0);

    resizeWindow("img",320,240);
    waitKey(0);
    destroyAllWindows();
    
    return 0;

}