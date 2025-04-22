#include "module.h"
#include "class_module_sub/class_module_sub.h"

Module getClassModule() {
	Module m;
	m.name = "类相关";
	m.subModules = {
		getStateModule(),
	};
	return m;
}