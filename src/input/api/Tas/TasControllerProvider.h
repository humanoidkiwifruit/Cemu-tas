#pragma once

#include "input/api/ControllerProvider.h"

#ifndef HAS_TAS
#define HAS_TAS 1
#endif

class TasControllerProvider : public ControllerProviderBase
{
	friend class TasController;
public:
	inline static InputAPI::Type kAPIType = InputAPI::Tas;
	InputAPI::Type api() const override { return kAPIType; }

	std::vector<std::shared_ptr<ControllerBase>> get_controllers() override;
};
