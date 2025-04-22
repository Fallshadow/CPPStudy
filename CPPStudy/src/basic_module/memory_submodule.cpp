#include <iostream> 

#include "basic_module_sub/basic_module_sub.h"
#include "basic_module_sub/memory_submodule.h"

SubModule getMemoryModule() {

	QA qa11 = {
"请介绍一下 C++ 内存分配方式",
R"(
	在 C++ 中，有两种主要的内存分配方式：
		1：静态分配（如局部变量自动分配在栈上）
		2：动态分配（在程序运行时申请需要的内存，用于堆上分配）C++ 主要用 new 和 delete 关键字来实现动态申请和释放内存，这时候只能通过指针来访问和管理这些动态分配的内存块。
)",
nullptr
	};

	QA qa12 = {
"介绍一下内存泄漏",
R"(
	内存泄漏（Memory Leak）是指程序在申请动态内存后，没有正确释放它，导致这部分内存一直被占用但无法再次利用的现象。
	程序 “丢失” 了对动态分配内存的管理，而操作系统又无法自动回收这部分内存，结果这部分内存空间就失去了作用，但仍然被占用。
)",
nullptr
	};

	KnowledgePoint kp1;
	kp1.name = "内存简介";
	kp1.qas.push_back(qa11);
	kp1.qas.push_back(qa12);


	QA qa21 = {
"new 的时候，发生什么事了？",
R"(
	1: 在堆上申请内存
		操作系统会在 堆（heap）上动态分配一块足够大小的、可以存放指定类型变量/对象的内存空间。
		如果申请失败（比如内存不足），new会抛出std::bad_alloc异常（除非用new (std::nothrow)，此时返回nullptr）。
	2：调用构造函数
		如果用 new 创建的是类对象，还会自动调用该类型的构造函数对对象进行初始化。
		对于基本类型（如int），只有在 new int(123) 这种情况下才会初始化。
	3：返回指针
		new 返回所分配内存首地址的指针。这个指针的类型与申请类型一致（如int*、MyClass*等）。
		这个指针用于后续访问和操作这块动态分配的内存。
)",
nullptr
	};

	KnowledgePoint kp2;
	kp2.name = "申请堆内存";
	kp2.qas.push_back(qa21);


	QA qa31 = {
"内存泄漏常见原因？",
R"(
	忘记用 delete 或 delete[] 释放 new 分配的内存；
	指针丢失（指针被重赋值或作用域结束），无法再用来释放原先的内存；
	异常提前导致未释放内存（比如申请后没进到释放的代码就抛异常了）；
	多次分配、仅释放最后一次得到的指针，导致以前的指针丢失。
------------------------------------------------
	// 忘记释放动态分配的内存
	void func() {  
		int* p = new int(10);  
		// 这里忘记了 delete p;  
	} 
------------------------------------------------
	// 指针被重新赋值之前未释放原有内存
	int* p = new int(1);  
	p = new int(2); // 原本那块int内存就无法释放了  
	delete p;      // 只释放了新分配的，而第一个丢失  
------------------------------------------------
	// 指针丢失引用（作用域结束）
	int* leak() {  
		int* p = new int(99);  
		return nullptr; // 本应返回p，但返回了nullptr，p分配的内存无法访问  
	}  
------------------------------------------------
	// 多重指针导致的遗漏
	int* a = new int[3];  
	int* b = a;  
	delete[] a;  
	// 此处b继续被使用或多次delete都会出错；但如果a被重新赋值，b指向的内存会泄漏  
------------------------------------------------
	// 动态分配与异常处理不当
	void foo() {  
		int* p = new int(5);  
		throw std::runtime_error("error!"); // 没有delete p就抛异常，泄漏！  
	}  
------------------------------------------------
	// 数据结构（如链表、树）释放不全
	struct Node { Node* next; /* ... */ };  
	Node* head = new Node();  
	// 只 delete head; 没有递归delete所有节点  
------------------------------------------------
	// 容器里存放指针但没释放内存
	std::vector<int*> vec;  
	for (int i = 0; i < 10; ++i) {  
		vec.push_back(new int(i));  
	}  
	// 只清空vec，没有delete每个new出来的int  
	vec.clear(); // 只是清空指针，不会释放指针指向的内存  
------------------------------------------------
	// 不匹配的new/delete和new[]/delete[]
	int* arr = new int[10];  
	// 错用 delete arr; // 正确应为 delete[] arr;  
------------------------------------------------
	// 资源转交后没有责任约定（如原生回调或API传递）
	void setData(int* data) {  
	// 保留指针但没约定谁释放，可能遗失释放责任  
	}  
	setData(new int(44));  
------------------------------------------------
	
)",
nullptr
	};

	QA qa32 = {
"内存泄漏预防办法？",
R"(
	RAII 原则（Resource Acquisition Is Initialization）
		RAII 的含义是：资源获取即初始化。
		也就是说，把资源的申请和释放工作，放进对象的构造和析构函数里，一旦对象超出作用域或被销毁时，资源就自动被释放。
		只要让“资源管理”交给对象来负责，就不会因忘记手动释放而泄漏内存。、

	智能指针管理
		智能指针，是 C++ 标准库里的 RAII 应用，专门用于自动管理动态分配的内存。
		std::unique_ptr：独占所有权，离开作用域自动 delete
		std::shared_ptr：引用计数，最后一个指针销毁时 delete
		std::weak_ptr：配合 shared_ptr 避免循环引用

	RAII 和智能指针的本质就是“用对象来守护资源”，把手动资源管理变成自动完成。这是现代 C++ 安全、高效、高可维护的重要保证。
)",
nullptr
	};

	KnowledgePoint kp3;
	kp3.name = "内存泄漏";
	kp3.qas.push_back(qa31);
	kp3.qas.push_back(qa32);

	SubModule subModule;
	subModule.name = "内存";
	subModule.knowledgePoints.push_back(kp1);
	subModule.knowledgePoints.push_back(kp2);
	subModule.knowledgePoints.push_back(kp3);

	return subModule;
}