// 书中对应章节：1.4.4 在Linux中编写C++程序
// 用途：验证 C++ 编译环境（g++）
// 编译：g++ hello_world.cpp -o hello_world
// 运行：./hello_world

#include <iostream> // 书中原文为 "iostream"，标准写法为 <iostream>

int main() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}