# ROS 2 机器人开发从入门到实践 · 学习代码笔记

> 本仓库为《ROS 2机器人开发从入门到实践》（桑欣 著，机械工业出版社，2024）的**个人学习代码与笔记整理**，目标是**构建一套可快速复制的工程模板**，以便后续实际项目开发时直接取用。

---

## 一、项目目的

1. **代码留存与复用**：把书中每一章的示例代码、工程结构、配置文件整理成可独立构建的工作空间，方便项目开发时直接 `cp -r` 取用。
2. **知识沉淀**：每章附带 README，摘录书中的关键概念、API 用法、易错点，作为速查手册。
3. **防遗忘**：把 PDF 中的核心内容（代码清单、配置说明、命令速查）结构化整理到各章节 README 中，即使不翻书也能快速回顾。

---

## 二、书籍与代码来源

| 项目 | 信息 |
|------|------|
| 书名 | ROS 2机器人开发从入门到实践 |
| 作者 | 桑欣（小鱼） |
| 出版社 | 机械工业出版社，2024年7月第1版 |
| ISBN | 978-7-111-75806-8 |
| ROS 2 版本 | Humble Hawksbill（Ubuntu 22.04） |
| 官方配套代码 | https://gitee.com/fishros/ros2bookcode |
| 作者社区 | https://fishros.org.cn |

> **说明**：本仓库代码基于官方配套代码整理，结合个人学习过程中的修改与注释。如与官方代码有出入，以官方仓库为准。

---

## 三、章节索引

> 每章一个子目录，内含该章所有功能包、launch 文件、配置文件及一份 `README.md`（含本章知识点摘要、代码说明、常用命令速查）。

| 章节 | 主题 | 核心内容 | README | 状态 |
|------|------|----------|--------|------|
| 第1章 | 启程——让你的第一个机器人动起来 | ROS 2 架构、虚拟机安装 Ubuntu 22.04、安装 ROS 2 Humble、turtlesim 海龟、Linux 终端基础、环境变量 | [chapt1/README.md](./chapt1/README.md) | ✅ 已完成 |
| 第2章 | ROS 2 基础入门——从第一个节点开始 | Python/C++ 节点编写、功能包（ament_python / ament_cmake）、Workspace、面向对象编程、C++ 新特性、多线程与回调 | [chapt2/README.md](./chapt2/README.md) | ✅ 已完成 |
| 第3章 | 订阅和发布——话题通信探索 | 话题通信机制、Python/C++ 发布订阅、自定义消息接口、Qt 界面、Git 入门 | [chapt3/README.md](./chapt3/README.md) | ✅ 已完成 |
| 第4章 | 服务和参数——深入 ROS 2 通信 | 服务通信、参数通信、自定义服务接口、人脸检测、巡逻海龟、launch 启动脚本 | [chapt4/README.md](./chapt4/README.md) | ✅ 已完成 |
| 第5章 | ROS 2 常用开发工具 | TF 坐标变换（Python/C++）、rqt、RViz、ros2 bag、Git 进阶 | [chapt5/README.md](./chapt5/README.md) | ⬜ 待整理 |
| 第6章 | 建模与仿真——创建自己的机器人 | URDF/Xacro 建模、物理属性（碰撞/质量/惯性）、Gazebo 仿真、ros2_control | [chapt6/README.md](./chapt6/README.md) | ⬜ 待整理 |
| 第7章 | 自主导航——让机器人自己动起来 | slam_toolbox 建图、Navigation 2 配置与使用、导航接口调用、自动巡检机器人 | [chapt7/README.md](./chapt7/README.md) | ⬜ 待整理 |
| 第8章 | 使用自己的规划器和控制器导航 | pluginlib 插件机制、自定义规划器、自定义控制器 | [chapt8/README.md](./chapt8/README.md) | ⬜ 待整理 |
| 第9章 | 搭建一个实体移动机器人 | 单片机开发、电机 PID 控制、运动学正逆解、里程计、micro-ROS 接入、实体建图导航 | [chapt9/README.md](./chapt9/README.md) | ⬜ 待整理 |
| 第10章 | ROS 2 使用进阶 | QoS、执行器与回调组、生命周期节点、多节点组合、消息过滤器、DDS 进阶 | [chapt10/README.md](./chapt10/README.md) | ⬜ 待整理 |

---

图例：✅ 已完成 ⬜ 待整理

---

## 四、仓库目录结构

```
ros2bookcode/
├── README.md                 # 本文件（总索引）
├── chapt1/                   # 第1章：环境搭建与Linux基础
│   ├── README.md
│   └── ...                   # 笔记、命令速查（本章以环境配置为主，无独立工作空间）
├── chapt2/                   # 第2章：节点、功能包、编程基础
│   ├── README.md
│   └── chapt2_ws/            # 工作空间
│       └── src/
│           ├── demo_python_pkg/
│           └── demo_cpp_pkg/
├── chapt3/                   # 第3章：话题通信
│   ├── README.md
│   ├── topic_ws/             # 话题基础示例
│   └── topic_practice_ws/    # 最佳实践（系统状态监视工具）
├── chapt4/                   # 第4章：服务与参数
│   ├── README.md
│   └── chapt4_ws/
│       └── src/
│           ├── chapt4_interfaces/
│           ├── demo_python_service/
│           └── demo_cpp_service/
├── chapt5/                   # 第5章：TF、rqt、RViz、ros2 bag
│   └── README.md
├── chapt6/                   # 第6章：URDF建模与Gazebo仿真
│   └── README.md
├── chapt7/                   # 第7章：Navigation 2 导航
│   └── README.md
├── chapt8/                   # 第8章：自定义规划器与控制器
│   └── README.md
├── chapt9/                   # 第9章：实体机器人
│   └── README.md
└── chapt10/                  # 第10章：ROS 2 进阶
    └── README.md
```

---

## 五、环境与依赖

### 基础环境
- **操作系统**：Ubuntu 22.04 LTS
- **ROS 2 版本**：Humble Hawksbill
- **构建工具**：colcon
- **编辑器**：VS Code（推荐安装 Python、C/C++、ROS 插件）
- **开发语言**：Python 3.10+、C++17

### 各章节额外依赖

| 章节 | 额外依赖 |
|------|----------|
| 第2章 | `rclpy`、`rclcpp`、`cpp-httplib`（多线程示例） |
| 第3章 | `example_interfaces`、`psutil`、`espeakng`、`espeak-ng`、`Qt5` |
| 第4章 | `chapt4_interfaces`（自定义）、`sensor_msgs`、`cv_bridge`、`face_recognition`、`opencv-python` |
| 第5章 | `tf2_ros`、`tf_transformations`、`transforms3d`、`rviz2`、`ros2 bag` |
| 第6章 | `gazebo`、`ros2_control`、`xacro`、`robot_state_publisher`、`joint_state_publisher` |
| 第7章 | `slam_toolbox`、`navigation2`、`nav2_bringup` |
| 第8章 | `pluginlib`、`nav2_core` |
| 第9章 | `micro-ROS`、Arduino/ESP32 开发环境 |
| 第10章 | 各 DDS 实现（Fast DDS、Cyclone DDS 等） |

> 详细安装命令见各章 README 的「环境准备」小节。

---

## 六、使用说明

### 构建单个工作空间

```bash
cd chaptX/chaptX_ws
colcon build
source install/setup.bash
```

### 只构建指定功能包

```bash
colcon build --packages-select <package_name>
```

### 运行节点

```bash
ros2 run <package_name> <executable_name>
```

### 运行 launch 文件

```bash
ros2 launch <package_name> <launch_file>.launch.py
```

### 复用代码到新项目

1. 将对应章节的 `src/<package_name>` 复制到新工作空间的 `src/` 下；
2. 检查 `package.xml` 中的依赖声明；
3. 检查 `CMakeLists.txt` / `setup.py` 中的注册项；
4. `colcon build` 即可。

---

## 七、各章 README 内容规范

为保证可移植性和可读性，每章 README 建议包含以下结构：

```
# 第X章 <章节标题>

## 1. 本章知识点速查（表格/列表）
## 2. 功能包清单与作用说明
## 3. 关键代码片段与解释（对应书中代码清单）
## 4. 常用命令速查（构建/运行/调试）
## 5. 踩坑记录与注意事项
## 6. 与官方代码的差异说明（如有）
```

---

## 八、学习进度

- [x] 第1章 启程
- [x] 第2章 ROS 2 基础入门
- [x] 第3章 话题通信
- [x] 第4章 服务与参数
- [ ] 第5章 常用开发工具
- [ ] 第6章 建模与仿真
- [ ] 第7章 自主导航
- [ ] 第8章 自定义规划器与控制器
- [ ] 第9章 实体移动机器人
- [ ] 第10章 ROS 2 进阶

---

## 九、参考资源

- **官方配套代码**：https://gitee.com/fishros/ros2bookcode
- **鱼香 ROS 社区**：https://fishros.org.cn
- **ROS 2 官方文档（Humble）**：https://docs.ros.org/en/humble/
- **ROS 2 中文文档**：https://docs.ros.org/en/humble/（可配合社区中文资料）
- **作者公众号**：鱼香 ROS
- **GitHub 代理工具（书中提供）**：http://github.fishros.org

---

## 十、声明

- 本仓库仅用于**个人学习与知识整理**，代码版权归原作者桑欣及鱼香 ROS 社区所有。
- 书中内容摘录仅用于个人复习，请勿用于商业用途。
- 如代码与官方仓库不一致，以官方仓库为准；欢迎提 Issue 交流。

---

> 📌 **建议**：每学完一章，及时补充该章 README，并把可复用的代码片段（如自定义接口、launch 模板、CMakeLists 配置）单独标注，方便项目开发时快速检索。