#pragma once

#include "api/InputAPI.h"
#include "input/api/Tas/TasControllerProvider.h"
#include "input/api/Controller.h"

class TasController : public Controller<TasControllerProvider>
{
public:
	TasController();

	std::string_view api_name() const override // TODO: use constexpr virtual function with c++20
	{
		static_assert(to_string(InputAPI::Tas) == "TAS");
		return to_string(InputAPI::Tas);
	}
	InputAPI::Type api() const override { return InputAPI::Tas; }

	bool is_connected() override { return true; }

	bool has_axis() const override { return false; }

	std::string get_button_name(uint64 button) const override;

protected:
	ControllerState raw_state() override;

};
