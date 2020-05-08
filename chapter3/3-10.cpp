#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main()
{
    Mat img = imread("/home/park/opencv_programing/chapter3/lena.jpg",IMREAD_GRAYSCALE);
    if(img.empty()){
        cout << "No img" << endl;
        return -1;}

    namedWindow("img");
    imshow("img",img);
    int x = 100;
    int y = 100;
    moveWindow("image",x,y);

    int nKey;
    while(1)
    {
        nKey = waitKey(0);
        if(nKey == 0x1B){
            break;
        }
        switch(nKey){
            case 0x250000:
                x -= 10;
                break;
            case 0x270000:
                x += 10;
                break;
            case 0x260000:
                y -= 10;
                break;
            case 0x280000:
                y += 10;
                break;
        }
        moveWindow("img",x,y);
    }
    
    return 0;

}