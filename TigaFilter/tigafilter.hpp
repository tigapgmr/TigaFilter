#ifndef TIGAFILTER_FILTER_HPP
#define TIGAFILTER_FILTER_HPP
#include "ConvolutionMatrix.hpp"
namespace tiga {

	/* @brief : apply embossing Filter from Original image to Output Image.
	*
	* @param src : input image of gray or RGB image (other types are not supplied)
	* @param dst : output image ater processing.
	*/
	void EmbossFilter(cv::Mat src, cv::Mat& dst);

	void InversionFilter(cv::Mat src, cv::Mat& dst);

	void EngraveFilter(cv::Mat src, cv::Mat& dst);

	void HDR(cv::Mat src, cv::Mat& dst);
}
#endif //TIGAFILTER_FILTER_HPP