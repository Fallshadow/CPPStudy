#include <iostream>
#include <functional>
#include <vector>

#include "qa_struct.h"
#include "module.h"



int main()
{
    std::vector<Module> modules = {
        getBaseModule()
    };

    // std::vector<FlatQA> allQA = flatAllQAs(modules);
    // std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));  
    while (true) { 
        // 一级  
        std::cout << "\n=== C++ 学习问答系统 ===\n";
        for (size_t i = 0; i < modules.size(); ++i) {
            std::cout << (i + 1) << ". " << modules[i].name << "  ";
        }
        // std::cout << (modules.size() + 1) << ". 随机抽题\n";
        std::cout << "0. 退出\n请选择模块编号：";
        int sel1 = 0;
        std::cin >> sel1;
        if (sel1 == 0) break;

        //if (sel1 == (int)modules.size() + 1) {
        //    // 随机  
        //    if (allQA.empty()) { std::cout << "题库为空\n"; continue; }
        //    auto idx = std::uniform_int_distribution<int>(0, allQA.size() - 1)(rng);
        //    const auto& q = allQA[idx];
        //    std::cout << "\n[模块:" << q.moduleName
        //        << "] [子模块:" << q.subModuleName
        //        << "] [知识点:" << q.knowledgePointName << "]\n";
        //    std::cout << "题：" << q.question << "\n答：" << q.answer << "\n";
        //    continue;
        //}

        if (sel1 < 1 || sel1 >(int)modules.size()) { std::cout << "无效选择！\n"; continue; }
        const auto& module = modules[sel1 - 1];
        while (true) { 
            // 二级  
            std::cout << "\n-- [" << module.name << "] 子模块 --\n";
            for (size_t i = 0; i < module.subModules.size(); ++i) {
                std::cout << (i + 1) << ". " << module.subModules[i].name << std::endl;
            }
            std::cout << "0. 返回\n请选择子模块：";
            int sel2 = 0;
            std::cin >> sel2;
            if (sel2 == 0) break;
            if (sel2 < 1 || sel2 >(int)module.subModules.size()) { std::cout << "无效！\n"; continue; }
            const auto& sub = module.subModules[sel2 - 1];

            while (true) { 
                // 三级  
                std::cout << "\n-- [" << module.name << "/" << sub.name << "] 知识点 --\n";
                for (size_t i = 0; i < sub.knowledgePoints.size(); ++i) {
                    std::cout << (i + 1) << ". " << sub.knowledgePoints[i].name << std::endl;
                }
                std::cout << "0. 返回\n请选择知识点：";
                int sel3 = 0;
                std::cin >> sel3;
                if (sel3 == 0) break;
                if (sel3 < 1 || sel3 >(int)sub.knowledgePoints.size()) { std::cout << "无效！\n"; continue; }
                const auto& kp = sub.knowledgePoints[sel3 - 1];

                while (true) { 
                    std::cout << "\n知识点: " << kp.name << "\n";
                    for (size_t i = 0; i < kp.qas.size(); ++i){
                        std::cout << (i + 1) << ". " << kp.qas[i].question << std::endl;
                    }
                    std::cout << "0. 返回\n请选择问题：";
                    int sel_q = 0;
                    std::cin >> sel_q;
                    if (sel_q == 0) break;
                    if (sel_q < 1 || sel_q >(int)kp.qas.size()) { std::cout << "无效！\n"; continue; }
                    std::cout << "答：" << kp.qas[sel_q - 1].answer << "\n";
                }
            }
        }
    }
    std::cout << "感谢使用，bye！\n";
    return 0;
}