#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture capture(0);
    Mat frame;

    if(!capture.isOpened())
    {
        cout << "plz check camera. " << endl;
        return -1;
    }

    while(1)
    {

        capture >> frame;
        if(frame.empty())
        {
            break;
        }


        // using data
        for(int i=frame.rows/10*3; i< frame.rows/10*4; i++){
            for(int j=frame.cols/10*3; j < frame.cols/10*4; j++){
                unsigned char r,g,b;

                b= frame.data[i*frame.step+j*frame.elemSize()+0];
                g= frame.data[i*frame.step+j*frame.elemSize()+1];
                r= frame.data[i*frame.step+j*frame.elemSize()+2];

                frame.data[i*frame.step+j*frame.elemSize()+0] = 255-b;
                frame.data[i*frame.step+j*frame.elemSize()+1] = 255-g;
                frame.data[i*frame.step+j*frame.elemSize()+2] = 255-r;
            }
        }

        //using at
        for(int i=frame.rows/10*5; i< frame.rows/10*6; i++){
            for(int j=frame.cols/10*5; j < frame.cols/10*6; j++){

                unsigned char b = frame.at<Vec3b>(i,j)[0];
                unsigned char g = frame.at<Vec3b>(i,j)[1];
                unsigned char r = frame.at<Vec3b>(i,j)[2];

                frame.at<Vec3b>(i,j)[0] = 255-b;
                frame.at<Vec3b>(i,j)[1] = 255-g;
                frame.at<Vec3b>(i,j)[2] = 255-r;       
            }
        }
        
        //using ptr
        for(int i=frame.rows/10*7; i< frame.rows/10*8; i++){
            cv::Vec3b* ptr = frame.ptr<cv::Vec3b>(i);
            for(int j=frame.cols/10*7; j < frame.cols/10*8; j++){

                unsigned b = (ptr[j][0]);
                unsigned g = (ptr[j][1]);
                unsigned r = (ptr[j][2]);

                ptr[j] = cv::Vec3b(255-b,255-g, 255-r);
            }
        }

        //using iterator
        cv::MatIterator_<cv::Vec3b> itd = frame.begin<cv::Vec3b>(),itd_end = frame.end<cv::Vec3b>();
        for(int i=0; itd != itd_end; itd++, i++){
            cv::Vec3b bgr = (*itd);

            (*itd)[0] = 255-bgr[0];
            (*itd)[1] = 255-bgr[1];
            (*itd)[2] = 255-bgr[2];
            
        }

        char key = (char)cv::waitKey(1); // End Condition "Press 'q' button"
        imshow("img",frame);
        if(key == 'q')
        {
            break;
        }
    } 
}