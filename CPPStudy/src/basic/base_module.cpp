#include "module.h"
#include "module_sub.h"

Module getBaseModule() {
	Module m;
	m.name = "����";
	m.subModules = {
		getPointModule()
	};
	return m;
}