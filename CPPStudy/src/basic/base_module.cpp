#include "module.h"
#include "module_sub.h"

Module getBaseModule() {
	Module m;
	m.name = "基础";
	m.subModules = {
		getPointModule(),
		getMemoryModule(),
	};
	return m;
}