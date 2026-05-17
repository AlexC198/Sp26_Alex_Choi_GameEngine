#include "pch.h"

#include "ChugEvents.h"

namespace Chug
{
	KeyEvent::KeyEvent(Key keyCode, KeyAction action) : mKeyCode(keyCode), mAction(action)
	{

	}

	Key KeyEvent::GetKeyCode() const
	{
		return mKeyCode;
	}

	KeyAction KeyEvent::GetAction() const
	{
		return mAction;
	}

	void KeyEvent::SetKeyCode(Key newKeyCode)
	{
		mKeyCode = newKeyCode;
	}
	void KeyEvent::SetAction(KeyAction newAction)
	{
		mAction = newAction;
	}
}