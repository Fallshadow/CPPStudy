#pragma once
#include <string>
#include <vector>
#include <functional>

struct QA {
	std::string question;
	std::string answer;
	std::function<void()> demo;
};

struct KnowledgePoint {
	std::string name;
	std::vector<QA> qas;
};

struct SubModule {
	std::string name;
	std::vector<KnowledgePoint> knowledgePoints;
};

struct Module {
	std::string name;
	std::vector<SubModule> subModules;
};

struct FlatQA {
	std::string moduleName;
	std::string subModuleName;
	std::string knowledgePointName;
	std::string question;
	std::string answer;
};