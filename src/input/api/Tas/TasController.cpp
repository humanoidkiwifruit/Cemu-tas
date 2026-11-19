#include <boost/container/small_vector.hpp>

#include "input/api/Tas/TasController.h"
#include "WindowSystem.h"

TasController::TasController()
	: base_type("TAS", "TAS") //TODO: figure this out
{

}

std::string TasController::get_button_name(uint64 button) const
{
	return WindowSystem::GetKeyCodeName(button);
}

ControllerState TasController::raw_state()
{
	ControllerState result{};

	if (WindowSystem::GetWindowInfo().debugger_focused)
		return result;

	boost::container::small_vector<uint32, 16> pressedKeys;
	WindowSystem::GetWindowInfo().iter_keystates([&pressedKeys](const std::pair<const uint32, bool>& keyState) { if (keyState.second) pressedKeys.emplace_back(keyState.first); });
	result.buttons.SetPressedButtons(pressedKeys);
	return result;
}
