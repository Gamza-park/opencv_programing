#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img;
    Mat old_img;
    Mat sub_img;

    VideoCapture cap(0);
    if(!cap.isOpened())
    {
        cout << " plz open your camera" << endl;
        return -1;
    }

    while(1)
    {
        if(!( cap.read(img)))
        {
            break;
        }

        if(old_img.empty())
        {
            old_img = img.clone();
            continue;
        }
        subtract(old_img,img,sub_img);

        imshow("img",img);
        imshow("sub_img",sub_img);

        old_img = img.clone();

        char key = (char)cv::waitKey(1); // End Condition "Press 'q' button"
        if(key == 'q')
        {
            break;
        }
    }
}