#include <iostream>

#include "class_module_sub/class_module_sub.h"
#include "class_module_sub/statement_submodule.h"

SubModule getStateModule() {

	QA qa11 = {
		"如何定义一个类？并创建对象？",
		R"(
class Person{
public:
	// 构造函数
	Person(const std::string& name, int age) : name(name), age(age) {}

	// 成员函数
	void sayHello() const {
		std::cout << "Hello, I'm " << name << " and I'm " << age << " years old." << std::endl;
	}
private:
	// 成员变量
	std::string name;
	int age;
}

// 栈上创建
Person p1("Tom", 20);
p1.sayHello();

// 堆上创建
Person* p2 = new Person("Alice", 18);
p2->sayHello();
delete p2;
)",
nullptr
	};

	KnowledgePoint kp1;
	kp1.name = "声明、定义和创建";
	kp1.qas.push_back(qa11);

	SubModule subModule;
	subModule.name = "类的基本用法";
	subModule.knowledgePoints.push_back(kp1);
	return subModule;
}
