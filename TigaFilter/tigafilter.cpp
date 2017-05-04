#include "tigafilter.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\core\core.hpp"
#include "opencv2\opencv.hpp"
using namespace cv;
namespace tiga {
	void EmbossFilter(Mat src, Mat& dst)
	{
		if (src.channels() == 3) {
			double EmbossConfig[3][3]{
				{ -1 ,  0, -1 },
				{ 0 ,  4,  0 },
				{ -1 ,  0, -1 }
			};
			ConvolutionMatrix* convMatrix = new ConvolutionMatrix(3);
			convMatrix->applyConfig(EmbossConfig);
			convMatrix->Factor = 1;
			convMatrix->Offset = 127;
			dst = computeConvolution3x3(src, *convMatrix);
		}
		else if (src.channels() == CV_8UC3) {

		}
		else {
			
			dst = Mat::zeros(Size(src.rows, src.cols), CV_8UC1);
		}
	}
}

