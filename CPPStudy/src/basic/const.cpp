 
#include <iostream>  
#include "basic/const.h"  

namespace BasicConstDemo {
    void showConstVars() {
        const int a = 10;
        // a = 20; // error: assignment of read-only variable 'a'  
        std::cout << "const int a = " << a << std::endl;
    }

    void showPointerConst() {
        int x = 100, y = 200;
        int* const p1 = &x;      // const pointer, can't change p1  
        // p1 = &y; // error  

        const int* p2 = &x;      // pointer to const value, can't change *p2  
        // *p2 = 300; // error  
        p2 = &y; // ok  

        std::cout << "int* const p1 -> " << *p1 << std::endl;
        std::cout << "const int* p2 -> " << *p2 << std::endl;
    }
}

void test_const() {
    std::cout << "[常量 const 变量示例]" << std::endl;
    BasicConstDemo::showConstVars();
    std::cout << "[指针与 const 示例]" << std::endl;
    BasicConstDemo::showPointerConst();
}