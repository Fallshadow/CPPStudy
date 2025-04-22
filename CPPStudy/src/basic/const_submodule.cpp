#include <iostream>  

#include "module_sub.h"
#include "basic/const_submodule.h"  

SubModule getConstModule() {
	return {
		"常量",
		{
			{
				"常量简介",
				{
					{
						"q",
						"a",
						nullptr
					},
				}
			}
		}

	};
}