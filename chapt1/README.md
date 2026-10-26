# 第1章 启程——让你的第一个机器人动起来

> 对应《ROS 2机器人开发从入门到实践》第1章（P1–P42）。
> 注：1.2节（开发环境搭建）属于一次性操作，此处直接略过，默认已安装好 Ubuntu 22.04 与 ROS 2 Humble。

## 1.1 ROS 部落的自我介绍

### 1.1.1 机器人与ROS
ROS 本质上就是用于**快速搭建机器人的软件库（核心是通信）和工具集**。
ROS 2 采用第三方的通信组件（DDS）代替了 ROS 1 的通信组件，使得数据传输更加稳定和强大。

### 1.1.2 ROS 2 系统架构
ROS 2 的系统架构分为 5 层：
1. **操作系统层**：Linux、Windows 或 macOS。
2. **DDS 实现层**：基于 RTPS 协议的数据分发服务（如 Fast DDS）。
3. **DDS 接口层**：RMW（ROS Middleware Interface），统一调用接口。
4. **ROS 2 客户端层**：提供不同语言的客户端库（rclpy、rclcpp）。
5. **应用层**：基于 RCL 开发的程序（如海龟模拟器、我们自己写的节点）。

### 1.1.3 ROS 2 的已发布版本
本书基于 **Humble Hawksbill** 版本进行讲解（Ubuntu 22.04 对应版本）。

### 1.1.4 ROS 2 机器人开发特色
- **四大核心通信机制**：话题（Topic）、服务（Service）、参数（Parameter）、动作（Action）。
- **丰富的调试工具**：RViz、rqt、ros2 bag。
- **建模与运动学工具**：TF、URDF。
- **强大的开源社区**：Gazebo、Navigation 2、Moveit 2 等。

---

## 1.3 运行你的第一个机器人

### 1.3.1 启动海龟模拟器
打开终端，输入：
```bash
ros2 run turtlesim turtlesim_node
```
> 命令结构：`ros2 run <package_name> <executable_name>`。

### 1.3.2 使用键盘控制海龟
保持海龟模拟器终端打开，新开一个终端：
```bash
ros2 run turtlesim turtle_teleop_key
```
输入该命令后，**鼠标点击该终端**，然后按方向键即可控制海龟。

### 1.3.3 海龟例子的简单分析
打开新终端，输入 `rqt` 打开图形界面。在菜单栏选择 `Plugins` → `Introspection` → `Node Graph`，点击刷新。
可以看到一条从 `/teleop_turtle` 指向 `/turtlesim` 的线，线上标着 `/turtle1/cmd_vel`。这就是**话题通信**的最小闭环。

---

## 1.4 ROS 2 基础之 Linux

### 1.4.1 Linux 终端基础操作
常用命令速记：
- `pwd`：查看当前目录
- `cd ~`：回到主目录
- `ls`：查看文件列表
- `mkdir chapt1`：创建文件夹
- `touch hello_world.txt`：创建空白文件
- `nano hello_world.txt`：编辑文件（Ctrl+O 保存，Ctrl+X 退出）
- `cat hello_world.txt`：查看文件内容
- `rm hello_world.txt`：删除文件
> 提示：任何命令后加 `--help` 可以查看帮助。

### 1.4.2 在 Linux 中安装软件
- `sudo dpkg -i xxx.deb`：安装本地 deb 包。
- `sudo apt install <包名>`：自动下载并安装。

### 1.4.3 在 Linux 中编写 Python 程序
在 `chapt1` 目录下新建 `hello_world.py`，代码如下：
👉 对应代码文件：[hello_world.py](./hello_world.py)

运行方式：
```bash
python3 hello_world.py
```

### 1.4.4 在 Linux 中编写 C++ 程序
在 `chapt1` 目录下新建 `hello_world.cpp`，代码如下：
👉 对应代码文件：[hello_world.cpp](./hello_world.cpp)

**编译方式一（简单代码）：**
```bash
g++ hello_world.cpp -o hello_world
./hello_world
```

**编译方式二（工程化，使用 CMake）：**
对于复杂代码，使用 CMake 更加方便。在同级目录新建 `CMakeLists.txt`：
👉 对应代码文件：[CMakeLists.txt](./CMakeLists.txt)

构建流程：
```bash
mkdir build && cd build
cmake ..
make
./learn_cmake
```

### 1.4.5 Linux 基础之环境变量
- `ROS_DISTRO`：存储当前 ROS 版本（如 `humble`）。
- `AMENT_PREFIX_PATH`：存储功能包查找路径。
- 当运行 `ros2 run turtlesim turtlesim_node` 时，ROS 2 会先读取 `AMENT_PREFIX_PATH`，然后到对应目录的 `lib` 文件夹下寻找可执行文件。
- `source install/setup.bash` 的本质就是修改 `AMENT_PREFIX_PATH` 环境变量，以便让系统找到我们自己编译的功能包。

## 1.5 小结与点评
本章我们认识了 ROS 2 的架构，运行了第一个海龟机器人，并掌握了 Linux 终端基础操作以及 Python、C++ 和 CMake 的编译流程。下一章我们将正式进入功能包的世界，开始编写自己的 ROS 2 节点。