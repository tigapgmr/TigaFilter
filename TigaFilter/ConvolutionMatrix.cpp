
#include "ConvolutionMatrix.hpp"
using namespace cv;
int clipping(int value)
{
	return value > 255 ? 255 : (value < 0 ? 0 : value);
}
void ConvertImageType(Mat src, Mat& dst)
{
	cvtColor(src, dst, CV_GRAY2RGB);
}
Mat computeConvolution3x3(Mat input, ConvolutionMatrix matrix) {
	int width = input.cols;
	int height = input.rows;
	Mat result = result = input.clone();
	int sumR, sumG, sumB;
	Vec3b pixels[3][3];
	for (int y = 0; y < height - 2; ++y) {
		for (int x = 0; x < width - 2; ++x) {
			// get pixel matrix
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					pixels[i][j] = input.at<Vec3b>(y + j, x + i);
				}
			}
			sumR = sumG = sumB = 0;

			// get sum of RGB on matrix
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					sumR += (pixels[i][j][0] * matrix.Matrix[i][j]);
					sumG += (pixels[i][j][1] * matrix.Matrix[i][j]);
					sumB += (pixels[i][j][2] * matrix.Matrix[i][j]);
				}
			}
			Vec3b resultColor;
			// get final Red
			resultColor[0] = clipping((int)(sumR / matrix.Factor + matrix.Offset));
			resultColor[1] = clipping((int)(sumG / matrix.Factor + matrix.Offset));
			resultColor[2] = clipping((int)(sumB / matrix.Factor + matrix.Offset));
			// apply new pixel
			result.at<Vec3b>(y, x) = resultColor;
		}
	}
	return result;
}