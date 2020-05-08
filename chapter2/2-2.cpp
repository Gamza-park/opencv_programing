#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;
// ex2-2 point template class
int main(){
    Point2f pt1(0.1f,0.2f),pt2(0.3f,0.4f);

    Point pt3 = (pt1+pt2)*10.0f;
    Point2f pt4 = (pt1-pt2)*10.0f;
    Point pt5 = Point(10,10);
    Point2f pt6 = Point2f(10.0f,10.0f);

    cout << pt1 << endl;
    cout << pt2 << endl;
    cout << pt3 << endl;
    cout << pt4 << endl;
    cout << pt5 << endl;
    cout << pt6 << endl;

    if(pt1 ==pt2){
        cout << "pt1 is equal to pt2" << endl;
    }
    else{
        cout << "pt1 is not equal to pt2" << endl;
    }

float fValue = pt1.dot(pt2);
cout << "fValue = " << fValue << endl;
double normValue = norm(pt1);
cout << "normValue = " << normValue << endl;

Point pt (150,150);
Rect rect(100,100,200,200);

if(pt.inside(rect)){
    cout << " pt is an inside point in rect" << endl;
}
else {
    cout << " pt is not an inside point in rect" << endl;
}

return 0;
}