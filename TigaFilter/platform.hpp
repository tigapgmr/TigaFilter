#ifndef TIGAFILTER_PLATFORM_HPP
#define TIGAFILTER_PLATFORM_HPP

#if(defined(_WIN32) || defined(_WIN64))
#define SR_WIN 1
#else
#define SR_WIN 0
#endif
#if(defined(__APPLE__))
#define SR_IOS 1
#else
#define SR_IOS 0
#endif

#if(defined(__ANDROID__))
#define SR_ANDROID 1
#else
#define SR_ANDROID 0
#endif


#endif //TIGATILTER_PLATFORM_HPP