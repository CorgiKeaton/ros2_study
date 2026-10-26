# 第1章 启程——让你的第一个机器人动起来

> 对应《ROS 2机器人开发从入门到实践》第1章（P1–P42）。  
> **本章定位**：环境搭建完成后的**命令与知识速查层**。本章不产生独立 ROS 2 功能包，但沉淀了后续所有章节都会反复用到的 `ros2 run`、`rqt`、Linux 终端、Python/C++ 编译、环境变量等基础操作，是项目开发时最常“回头翻”的一章。  
> **复用提示**：本章的「命令速查」「编程模板」「环境变量排查」三节可直接复制到新项目笔记中。

---

## 1. ROS introduction

### 1.1 ROS 2 系统架构（五层）

| 层级 | 作用 | 关键词 |
|------|------|--------|
| 操作系统层 | 提供硬件驱动与系统基础 | Linux / Windows / macOS |
| DDS 实现层 | 第三方通信中间件，基于 RTPS | Fast DDS、Cyclone DDS 等 |
| DDS 接口层 | 统一不同 DDS 的调用接口 | RMW（ROS Middleware Interface） |
| ROS 2 客户端层 | 提供不同语言的客户端库 | rclpy、rclcpp |
| 应用层 | 基于 RCL 开发的程序与工具 | turtlesim、rqt、自定义节点 |

> **复用点**：写项目架构文档时，可直接引用这五层结构说明“ROS 2 在哪里、你的节点在哪一层”。

### 1.2 ROS 2 版本选择

本书基于 **Humble Hawksbill**（2022 年 5 月发布，维护至 2027 年 5 月），环境搭配 **Ubuntu 22.04**。版本表见 PDF 表 1-1。

> **复用点**：新项目 `README` 的“环境要求”一节可直接写：`ROS 2 Humble + Ubuntu 22.04`。

### 1.3 ROS 2 四大通信机制

| 机制 | 模式 | 方向 | 典型用途 | 后续章节 |
|------|------|------|----------|----------|
| 话题 Topic | 发布/订阅 | 单向 | 传感器数据、控制指令 | 第3章 |
| 服务 Service | 请求/响应 | 双向 | 图像识别、坐标查询 | 第4章 |
| 参数 Parameter | 基于服务 | 双向 | 节点配置动态调整 | 第4章 |
| 动作 Action | 长时任务 | 双向+反馈 | 导航、机械臂运动 | 本书未展开 |

### 1.4 海龟例子的节点关系

- `turtlesim_node`：订阅 `/turtle1/cmd_vel`（`geometry_msgs/msg/Twist`），发布 `/turtle1/pose`（`turtlesim/msg/Pose`）等。
- `turtle_teleop_key`：发布 `/turtle1/cmd_vel`。
- 二者通过**话题通信**连接，可用 `rqt` 的 **Node Graph** 插件可视化。

> **复用点**：“发布者—话题—订阅者”最小闭环的标准示例，写任何话题通信文档时可直接引用该关系图

---

## 2. ROS2 基础

> 本节是本章最核心的“复制粘贴区”。建议按场景检索。

### 2.1 海龟示例（最小可运行验证）

```bash
ros2 run turtlesim turtlesim_node     # 终端1：启动海龟模拟器
ros2 run turtlesim turtle_teleop_key  # 终端2：键盘控制
ros2 node list                        # 终端3：查看节点
rqt                                   # 终端4：打开 rqt
```

`ros2 run` 命令结构

```bash
ros2 run <package_name> <executable_name>
```

| 部分 | 含义 | 海龟示例 |
|------|------|----------|
| `ros2 run` | 运行 ROS 2 功能包可执行文件 | — |
| `package_name` | 功能包名 | `turtlesim` |
| `executable_name` | 可执行文件名 | `turtlesim_node` / `turtle_teleop_key` |

> **复用点**：后续所有章节运行节点都是这个结构，可直接套用。

### 2.2 Linux 终端常用命令

```bash
pwd                     # 查看当前目录
cd /                    # 进入根目录
cd ~                    # 回到主目录
cd chapt1               # 进入 chapt1
ls                      # 查看当前目录
ls -a                   # 查看包含隐藏文件
mkdir chapt1            # 创建目录
touch hello_world.txt   # 创建空文件
nano hello_world.txt    # 编辑文件（Ctrl+O 保存，Ctrl+X 退出）
cat hello_world.txt     # 查看文件内容
rm hello_world.txt      # 删除文件
命令 --help             # 查看任意命令帮助
```

### 2.3 Linux 软件安装

```bash
# 1) dpkg 安装本地 deb 包
sudo dpkg -i ./xxx.deb
sudo apt -f install          # 修复依赖（dpkg 报依赖错误时用）

# 2) apt 安装仓库软件
sudo apt install git

# 3) 脚本安装（以 VirtualBox 增强功能为例）
cd /media/$USER/VBox_GAs_*
sudo ./autorun.sh
```

> **复用点**：新机器装依赖时，这三条命令覆盖 95% 场景。

### 2.3 Linux Python

运行：

```bash
python3 hello_world.py
```

### 2.4 Linux C++

直接编译：

```bash
g++ hello_world.cpp
./a.out
```

CMake 模板构建（书中写法）：

```bash
cmake .
make
./learn_cmake
```

> **复用建议**：实际项目推荐独立 build 目录，避免污染源码：
> ```bash
> mkdir build && cd build && cmake .. && make

### 2.5 Linux 环境变量

```bash
echo $ROS_DISTRO             # 当前 ROS 版本，应为 humble
echo $AMENT_PREFIX_PATH      # ROS 2 查找功能包的路径
ros2 pkg prefix turtlesim    # 查看某功能包安装路径
```
#### 2.5.1 环境自检脚本
保存为 `chapt1/scripts/check_ros2_env.sh`：

```bash
#!/usr/bin/env bash
set -e

echo "== ROS_DISTRO =="
echo "${ROS_DISTRO:-未设置}"

echo "== which ros2 =="
which ros2 || true

echo "== AMENT_PREFIX_PATH =="
echo "${AMENT_PREFIX_PATH:-未设置}"

echo "== turtlesim 路径 =="
ros2 pkg prefix turtlesim || true
```

> **复用点**：换机器、换工作空间后先跑一遍，快速定位“找不到包”类问题。

---

#### 2.5.2 环境变量机制

关键环境变量

| 变量 | 作用 | 查看命令 |
|------|------|----------|
| `ROS_DISTRO` | 当前 ROS 版本 | `echo $ROS_DISTRO` |
| `AMENT_PREFIX_PATH` | 功能包与可执行文件查找路径集合 | `echo $AMENT_PREFIX_PATH` |

`ros2 run` 的查找逻辑

1. 读取 `AMENT_PREFIX_PATH`；
2. 到 `<路径>/lib/<package_name>/` 下查找可执行文件；
3. 找不到则报 `Package '<name>' not found`。

验证示例（书中）：

```bash
# 正常情况
$AMENT_PREFIX_PATH/lib/turtlesim/turtlesim_node

# 覆盖后测试
export AMENT_PREFIX_PATH=/opt/ros/humble
ros2 run turtlesim turtlesim_node
# 报错：Package 'turtlesim' not found
```

★ 使用注意

- 环境变量只对**当前终端上下文**有效，新终端需重新 `source`。
- 工作空间构建后必须 `source install/setup.bash`，否则 `ros2 run` 找不到自建功能包。
- 不要随意 `export AMENT_PREFIX_PATH=...` 覆盖原值，正确做法是 `source` 对应 `setup.bash`。

> **复用点**：写项目部署文档时，把“source 顺序”写清楚：先 `/opt/ros/humble/setup.bash`，再工作空间 `install/setup.bash`。

---

## 3. 踩坑记录与排查清单

| 现象 | 原因 | 解决 |
|------|------|------|
| `ros2: command not found` | 新终端未加载环境 | `source /opt/ros/humble/setup.bash` |
| `Package 'xxx' not found` | `AMENT_PREFIX_PATH` 不含该包 | `source install/setup.bash`；检查是否覆盖了变量 |
| `sudo apt update` 失败 | 源网络问题 | 换国内源（fishros 工具可选换源） |
| `dpkg -i` 依赖错误 | 缺少依赖 | `sudo apt -f install` |
| 终端输入密码无显示 | Linux 安全设计 | 正常输入后回车即可 |
| 当前目录运行程序失败 | 缺少 `./` | `./a.out` 而非 `a.out` |
| 虚拟机复制粘贴/分辨率异常 | 未装增强功能 | 设备 → 安装增强功能 → `./autorun.sh` |
| Tab 无法补全 | 命令拼写错误或未安装补全 | 输入 `ros2 r` 后按 Tab 验证 |
| 书中目录名 `chatp1` | 笔误 | 实际统一用 `chapt1` |

> **复用点**：新项目 `README` 的“常见问题”一节可直接搬运本表。

---

## 4. 本章可复用资产清单

- [ ] `chapt1/scripts/check_ros2_env.sh`：新机器环境自检脚本。
- [ ] `chapt1/notes/linux-cheatsheet.md`：Linux 终端命令速查。
- [ ] `hello_world.py` / `hello_world.cpp` / `CMakeLists.txt`：最小编译模板。
- [ ] `ros2 run` 命令结构模板：`ros2 run <pkg> <exe>`。
- [ ] 环境变量排查清单：`ROS_DISTRO`、`AMENT_PREFIX_PATH`。
- [ ] 海龟话题关系：`/turtle1/cmd_vel`（`geometry_msgs/msg/Twist`）发布/订阅最小闭环。

---

## 5. 本章验收标准（自测）

完成本章后，应能独立完成：

1. 运行海龟模拟器并用键盘控制；
2. 用 `ros2 node list` 和 `rqt` Node Graph 查看节点关系；
3. 使用 Linux 终端完成目录切换、文件创建/编辑/删除；
4. 用 `g++` 和 CMake 编译简单 C++ 程序；
5. 解释 `ROS_DISTRO` 与 `AMENT_PREFIX_PATH` 的作用；
6. 遇到 `Package 'xxx' not found` 时能定位到环境变量问题。

---

## 6. 与后续章节的衔接

| 本章内容 | 后续使用场景 |
|----------|--------------|
| `ros2 run` 结构 | 第2章起所有节点运行 |
| 话题通信最小闭环 | 第3章话题通信展开 |
| `AMENT_PREFIX_PATH` | 第2章功能包构建后 `source` |
| Python/C++/CMake 模板 | 第2章节点编写、第6章功能包构建 |
| `rqt` Node Graph | 第2章、第4章调试节点关系 |
| Linux 终端命令 | 全书通用 |

---

> 📌 下一章：[第2章 ROS 2 基础入门——从第一个节点开始](../chapt2/README.md)  
> 📌 返回总索引：[README.md](../README.md)