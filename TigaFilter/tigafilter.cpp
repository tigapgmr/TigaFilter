
#include "tigafilter.hpp"
#include "ConvolutionMatrix.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\core\core.hpp"
#include "opencv2\opencv.hpp"
using namespace cv;
namespace tiga {

	void EmbossFilter(Mat src, Mat& dst)
	{
		if (src.type() == CV_8UC3) {
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
		else {
			printf("Color Image needed\n");
			dst = src.clone();
			return;
		}
	}

	void InversionFilter(cv::Mat input, cv::Mat& output) {
		int imageType = input.type();
		output = input.clone();
		for (int h = 0; h < input.rows; ++h) {
			for (int w = 0; w < input.cols*input.channels(); w += input.channels()) {
				for (int i = 0; i < input.channels(); ++i) {
					output.at<uchar>(h, w + i) = 255 - input.at<uchar>(h, w + i);
				}
			}
		}
	}

	void EngraveFilter(cv::Mat src, cv::Mat & dst)
	{
	}


	void ColorizeIntensity(cv::Mat input, cv::Mat & output)
	{
		Mat ycrcb;
		cvtColor(input, ycrcb, CV_BGR2YCrCb);
		std::vector<Mat> channels;
		split(ycrcb, channels);
		equalizeHist(channels[0], channels[0]);
		merge(channels, ycrcb);
		cvtColor(ycrcb, output, CV_YCrCb2BGR);
	}
	//created by YEJI
	void brightness(cv::Mat input, cv::Mat& output, int value) {

		if (value > -50 && value < 50) {
			output = input.clone();
			for (int h = 0; h < input.rows; h++)
			{
				for (int w = 0; w < input.cols; w++) {
					Vec3b color = input.at<Vec3b>(h, w);
					for (int i = 0; i < 3; i++) {
						color[i] = clipping(color[i] + value);
					}
					output.at<Vec3b>(h, w) = color;
				}
			}
		}
		else {
			output = input.clone();
		}
	}

	//created by YEJI
	void contrast(cv::Mat input, cv::Mat & output, int value)
	{
		if (value > -50 && value < 50) {
			output = input.clone();
			int mValue = pow((100 + value) / 100, 2);

			for (int h = 0; h < input.rows; h++)
			{
				for (int w = 0; w < input.cols; w++) {
					Vec3b color = input.at<Vec3b>(h, w);
					for (int i = 0; i < 3; i++) {
						color[i] = clipping(((((color[i] / 255.0) - 0.5) * mValue) + 0.5) * 255.0);
					}
					output.at<Vec3b>(h, w) = color;
				}
			}
		}
		else {
			output = input.clone();
		}

	}

	void sharpen(cv::Mat input, cv::Mat & output, int value)
	{
		if (value > -50 && value < 50) {
			Mat tmp;
			output = input.clone();

			GaussianBlur(input, tmp, Size(0, 0), 0.8);
			addWeighted(input, (double)value + 0.5, tmp, 1.0 - ((double)value + 0.5), 0, output);
		}
		else {
			output = input.clone();
		}
	}
}