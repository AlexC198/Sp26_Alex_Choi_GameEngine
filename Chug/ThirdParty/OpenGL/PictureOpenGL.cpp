#include"pch.h"

#include"PictureOpenGL.h"
#include"glad/glad.h"
#include "stbi.h"


namespace Chug
{
	PictureOpenGL::PictureOpenGL()
	{
	}

	PictureOpenGL::PictureOpenGL(const std::string& fileName)
	{
		//textures//
		glGenTextures(1, &mTexture);
		glBindTexture(GL_TEXTURE_2D, mTexture);
		//set the texture wrapping parameters

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	//set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* pdata = stbi_load(
			fileName.c_str(), &mDimensions.width, &mDimensions.height, 
			&nrChannels, 0);
		if (pdata) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mDimensions.width, mDimensions.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pdata);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			CHUG_ERROR("Failed to load texture");
		}
		stbi_image_free(pdata);
	}

	void PictureOpenGL::LoadImage(const std::string& fileName)
	{
		//textures//
		glGenTextures(1, &mTexture);
		glBindTexture(GL_TEXTURE_2D, mTexture);
		//set the texture wrapping parameters

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	//set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* pdata = stbi_load(
			fileName.c_str(), &mDimensions.width, &mDimensions.height,
			&nrChannels, 0);
		if (pdata) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mDimensions.width, mDimensions.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pdata);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			CHUG_ERROR("Failed to load texture");
		}
		stbi_image_free(pdata);
	}

	Dimensions PictureOpenGL::GetDimensions() const
	{
		return mDimensions;
	}
	PictureOpenGL::~PictureOpenGL()
	{
		glDeleteTextures(1, &mTexture);
	}

	void PictureOpenGL::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, mTexture);
	}
}