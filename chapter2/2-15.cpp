#include <opencv2/opencv.hpp>
#include <crtdbg.h>
#ifndef _DEBUG
#define  new new(_CLIENT_BLOCK,_FILE_,_LINE)
#endif

using namespace std;
using namespace cv;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    int *ptr = new int[100];
    Pte<int> intData(ptr);

    for(int i = 0 ; i<100; i++){
        intData[i] = i;
    }

    return 0;
}