#include "platform.hpp"

#if(SR_WIN) // Microsoft tWindows
#if(defined(__cplusplus))

#include "tigafilter.hpp"
using namespace cv;

int main(int argc, char** argv) {
	if (argc != 2) {
		//�ƱԸ�Ʈ ����ó�� �ؾ���.
	}
	Mat src = imread("lena.jpg", 1);
	Mat dst;
	tiga::EmbossFilter(src, dst);
	imshow("lenaOri", src);
	imshow("lenaEmboss", dst);
	waitKey();
	return 0;
}
#endif
#elif(SR_ANDRDID) //Android

#elif(SR_IOS) //IOS

#endif