#pragma once

#include "ChugUtility.h"
#include "KeyCodes.h"

namespace Chug
{
	class CHUG_API WindowCloseEvent
	{

	};

	class CHUG_API KeyEvent
	{
	public:

		KeyEvent(Key KeyCode, KeyAction action);
		Key GetKeyCode() const;
		KeyAction GetAction() const;
		void SetKeyCode(Key newKeyCode);
		void SetAction(KeyAction newAction);
	private:
		Key mKeyCode{ Key::UNDEFINED };
		KeyAction mAction{ KeyAction::UNDEFINED };
	};
}