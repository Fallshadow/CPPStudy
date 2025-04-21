#include "module_sub.h"

SubModule getPointModule() {
	return {
		"指针",
		{
			{
				"指针简介",
				{
					{
						"什么是指针？",
						"指针就是一个整数，存放一个内存地址。"
					},
					
					{
						"指针分类？",
						"可分为原始指针 raw pointer 和智能指针 smart pointer。"
					},
				}
			}
		}

	};
}