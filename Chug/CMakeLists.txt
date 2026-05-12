set(SOURCE_FILES 
	ChugApplication.h
	ChugApplication.cpp
	ChugUtility.h
	EntryPoint.h
	include/Chug.h
)

add_library(Chug SHARED ${SOURCE_FILES})

target_precompile_headers(Chug PRIVATE pch.h)

if(MSVC)
	target_compile_definitions(Chug PUBLIC CHUG_MSVC)
endif()

target_compile_definitions(Chug
	PRIVATE
		CHUG_LIB
	PUBLIC
		$<$<CONFIG:Debug>:CHUG_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:CHUG_DEBUG=1>
)

target_include_directories(Chug PUBLIC include)