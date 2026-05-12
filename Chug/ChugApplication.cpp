#include "pch.h"

#include "ChugApplication.h"

namespace Chug
{
	void ChugApplication::Update()
	{
	}

	void ChugApplication::Initialize()
	{
	}

	void ChugApplication::Shutdown()
	{
	}

	void ChugApplication::Run()
	{
		Initialize();

		while (true)
		{
			Update();
		}

		Shutdown();
	}


	ChugApplication::~ChugApplication()
	{
	}
}