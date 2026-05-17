set(SOURCE_FILES 
	ChugApplication.h
	ChugApplication.cpp
	ChugUtility.h
	EntryPoint.h
	include/Chug.h
	Window.h
	Window.cpp
	WindowImplementation.h
	ThirdParty/GLFW/WindowGLFW.h
	ThirdParty/GLFW/WindowGLFW.cpp
	Picture.h
	Picture.cpp
	PictureImplementation.h
	ThirdParty/OpenGL/PictureOpenGL.h
	ThirdParty/OpenGL/PictureOpenGL.cpp
	Shader.h
	Shader.cpp
	ShaderImplementation.h
	ThirdParty/OpenGL/ShaderOpenGL.h
	ThirdParty/OpenGL/ShaderOpenGL.cpp
	Renderer.h
	Renderer.cpp
	RendererImplementation.h
	ThirdParty/OpenGL/RendererOpenGL.h
	ThirdParty/OpenGL/RendererOpenGL.cpp
	KeyCodes.h
	ChugEvents.h
	ChugEvents.cpp
	Unit.h
	Unit.cpp
)

add_library(Chug SHARED ${SOURCE_FILES})

target_precompile_headers(Chug PRIVATE pch.h)

if(MSVC)
	target_compile_definitions(Chug PUBLIC CHUG_MSVC)
endif()

target_compile_definitions(Chug
	PRIVATE
		CHUG_LIB
		CHUG_OPENGL
	PUBLIC
		$<$<CONFIG:Debug>:CHUG_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:CHUG_DEBUG=1>
		CHUG_GLFW
)

target_include_directories(Chug PUBLIC include)
target_include_directories(Chug PRIVATE ../Chug)
target_include_directories(Chug PRIVATE ../glad/include)
target_include_directories(Chug PRIVATE ../stbi)

target_link_libraries(Chug glfw glad stbi)

file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR}/Chug)