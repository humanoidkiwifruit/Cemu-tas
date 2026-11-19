#include "input/api/Tas/TasControllerProvider.h"

#include "input/api/Tas/TasController.h"

std::vector<std::shared_ptr<ControllerBase>> TasControllerProvider::get_controllers()
{
	std::vector<std::shared_ptr<ControllerBase>> result;
	result.emplace_back(std::make_shared<TasController>());
	return result;
}
