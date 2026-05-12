#pragma once

#ifdef CHUG_MSVC
	#ifdef CHUG_LIB
		#define CHUG_API __declspec(dllexport)
	#else
		#define CHUG_API __declspec(dllimport)
	#endif
#else
	#define CHUG_API
#endif


#ifdef CHUG_DEBUG==2
	#define CHUG_LOG(text) std::cout<<text<<std::endl;
	#define CHUG_ERROR(text) std::cerr<<text<<std::endl;
#elif CHUG_DEBUG==1
	#define CHUG_LOG(text) 
	#define CHUG_ERROR(text) std::cerr<<text<<std::endl;
#else
	#define CHUG_LOG(text)
	#define CHUG_ERROR(text)
#endif