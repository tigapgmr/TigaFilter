#include "platform.hpp"
#if(SR_WIN) // Microsoft tWindows
#include "tigafilter.hpp"
#include "tchar.h"
using namespace cv;
int _tmain(int argc, _TCHAR *argv[]) {
	if (argc != 3) {
		//return EXIT_FAILURE;
	}
	Mat src = imread("lena.jpg", 0);
	Mat dst;
	tiga::EmbossFilter(src, dst);
	imshow("lenaOri", src);
	imshow("lenaEmboss", dst);
	waitKey();
	return 0;
}
#elif(SR_ANDRDID) //Android

#elif(SR_IOS) //IOS

#endif