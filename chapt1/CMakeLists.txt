# 书中对应章节：1.4.4 在Linux中编写C++程序
# 用途：演示 CMake 编译 C++ 工程的标准流程
# 构建：mkdir build && cd build && cmake .. && make

cmake_minimum_required(VERSION 3.8)
project(HelloWorld)

# 生成可执行文件 learn_cmake
add_executable(learn_cmake hello_world.cpp)