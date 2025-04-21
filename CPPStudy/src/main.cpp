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
        // һ��  
        std::cout << "\n=== C++ ѧϰ�ʴ�ϵͳ ===\n";
        for (size_t i = 0; i < modules.size(); ++i) {
            std::cout << (i + 1) << ". " << modules[i].name << "  ";
        }
        // std::cout << (modules.size() + 1) << ". �������\n";
        std::cout << "0. �˳�\n��ѡ��ģ���ţ�";
        int sel1 = 0;
        std::cin >> sel1;
        if (sel1 == 0) break;

        //if (sel1 == (int)modules.size() + 1) {
        //    // ���  
        //    if (allQA.empty()) { std::cout << "���Ϊ��\n"; continue; }
        //    auto idx = std::uniform_int_distribution<int>(0, allQA.size() - 1)(rng);
        //    const auto& q = allQA[idx];
        //    std::cout << "\n[ģ��:" << q.moduleName
        //        << "] [��ģ��:" << q.subModuleName
        //        << "] [֪ʶ��:" << q.knowledgePointName << "]\n";
        //    std::cout << "�⣺" << q.question << "\n��" << q.answer << "\n";
        //    continue;
        //}

        if (sel1 < 1 || sel1 >(int)modules.size()) { std::cout << "��Чѡ��\n"; continue; }
        const auto& module = modules[sel1 - 1];
        while (true) { 
            // ����  
            std::cout << "\n-- [" << module.name << "] ��ģ�� --\n";
            for (size_t i = 0; i < module.subModules.size(); ++i) {
                std::cout << (i + 1) << ". " << module.subModules[i].name << std::endl;
            }
            std::cout << "0. ����\n��ѡ����ģ�飺";
            int sel2 = 0;
            std::cin >> sel2;
            if (sel2 == 0) break;
            if (sel2 < 1 || sel2 >(int)module.subModules.size()) { std::cout << "��Ч��\n"; continue; }
            const auto& sub = module.subModules[sel2 - 1];

            while (true) { 
                // ����  
                std::cout << "\n-- [" << module.name << "/" << sub.name << "] ֪ʶ�� --\n";
                for (size_t i = 0; i < sub.knowledgePoints.size(); ++i) {
                    std::cout << (i + 1) << ". " << sub.knowledgePoints[i].name << std::endl;
                }
                std::cout << "0. ����\n��ѡ��֪ʶ�㣺";
                int sel3 = 0;
                std::cin >> sel3;
                if (sel3 == 0) break;
                if (sel3 < 1 || sel3 >(int)sub.knowledgePoints.size()) { std::cout << "��Ч��\n"; continue; }
                const auto& kp = sub.knowledgePoints[sel3 - 1];

                while (true) { 
                    std::cout << "\n֪ʶ��: " << kp.name << "\n";
                    for (size_t i = 0; i < kp.qas.size(); ++i){
                        std::cout << (i + 1) << ". " << kp.qas[i].question << std::endl;
                    }
                    std::cout << "0. ����\n��ѡ�����⣺";
                    int sel_q = 0;
                    std::cin >> sel_q;
                    if (sel_q == 0) break;
                    if (sel_q < 1 || sel_q >(int)kp.qas.size()) { std::cout << "��Ч��\n"; continue; }
                    std::cout << "��" << kp.qas[sel_q - 1].answer << "\n";
                }
            }
        }
    }
    std::cout << "��лʹ�ã�bye��\n";
    return 0;
}