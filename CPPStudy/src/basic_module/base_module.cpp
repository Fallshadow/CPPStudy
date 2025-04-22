#include "module.h"
#include "basic_module_sub//basic_module_sub.h"

Module getBaseModule() {
	Module m;
	m.name = "基础";
	m.subModules = {
		getPointModule(),
		getMemoryModule(),
	};
	return m;
}