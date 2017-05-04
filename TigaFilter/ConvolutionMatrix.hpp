#ifndef TIGAFILTER_CONVOLUTION_MATRIX_HPP
#define TIGAFILTER_CONVOLUTION_MATRIX_HPP
#include "stdafx.h"
#include <memory.h>
#include <math.h>
#include <assert.h>
//For Easing of any functions using Convolutions We made 'ConvolutionMatrix' Class.
class ConvolutionMatrix {
public:
	const int SIZE = 3;
	double **Matrix;
	double Factor = 1;
	double Offset = 1;
	ConvolutionMatrix(const int size) {

		Matrix = new double*[size];
		for (int i = 0; i < size; ++i) {
			Matrix[i] = new double[size];
			memset(Matrix[i], 0, sizeof(int) * size);
		}
	};
	void setAll(double value) {
		for (int x = 0; x < SIZE; ++x) {
			for (int y = 0; y < SIZE; ++y) {
				Matrix[x][y] = value;
			}
		}
	}
	void applyConfig(double(*config)[3]) {
		for (int x = 0; x < SIZE; ++x) {
			for (int y = 0; y < SIZE; ++y) {
				Matrix[x][y] = config[x][y];
			}
		}
	}


private:
};

/*Created by Tiga
* @brief : returns convolution3X3 Image.
*
* @param input : input image of 3 channel Color image.
* @param matrix : processing feature matrix.
*/
cv::Mat computeConvolution3x3(cv::Mat input, ConvolutionMatrix matrix);


/*Created by Tiga
* @brief : sature_cast pixel values.
*
* @param input : casting value.
*/
int clipping(int value);

#endif //TIGAFILTER_CONVOLUTION_MATRIX_HPP