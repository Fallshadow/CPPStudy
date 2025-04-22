#include <iostream>

#include "basic_module_sub/basic_module_sub.h"
#include "basic_module_sub/pointer_submodule.h"

SubModule getPointModule() {

	QA qa11 = {
		"请介绍一下 C++ 指针",
		R"(
指针（Pointer）是一种特殊变量，用于存储另一个变量的内存地址。即其内容就是一个整数，存放一个内存地址。
	声明语法： 类型 *指针名; 例如： int *p;
	赋值例子： int a = 10; int* p = &a;
	解引用： *p 读写 a 的值
)",
BaseUse1
	};

	QA qa12 = {
		"指针分类？",
R"(
可分为原始指针 raw pointer 和智能指针 smart pointer。
)",
nullptr
	};

	KnowledgePoint kp1;
	kp1.name = "指针简介";
	kp1.qas.push_back(qa11);
	kp1.qas.push_back(qa12);

	SubModule subModule;
	subModule.name = "指针";
	subModule.knowledgePoints.push_back(kp1);
	return subModule;
}

void BaseUse1() {
	int* p;
	int a = 10;
	p = &a;
	*p = 1;
	std::cout << "a 的值：" << a << std::endl;
	std::cout << "p 的值：" << p << std::endl;
	std::cout << "*p 的值：" << *p << std::endl;
	std::cout << "*&*p 的值：" << *&*p << std::endl;
	int* q = &a;
	std::cout << "q 的值：" << q << std::endl;
}