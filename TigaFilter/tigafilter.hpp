#ifndef TIGAFILTER_FILTER_HPP
#define TIGAFILTER_FILTER_HPP
#include "stdafx.h"
namespace tiga {

	/* @brief : apply embossing Filter from Original image to Output Image.
	*
	* @param src : input image of gray or RGB image (other types are not supplied)
	* @param dst : output image ater processing.
	*/
	void EmbossFilter(cv::Mat src, cv::Mat& dst);


}
#endif //TIGAFILTER_FILTER_HPP