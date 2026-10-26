import rclpy
from rclpy.node import Node
from demo_python_pkg.person_node import PersonNode

class WriterNode(PersonNode):
    def __init__(self, node:str, name:str, age:str, book:str) -> None:
        print('PersonNode __init__ 方法被调用了')
        super().__init__(node,name,age)  # 调用父类的 __init__ 方法
        self.book = book
        self.get_logger().info(f'WriterNode 初始化成功，笔名：{self.book}')

def main():
    rclpy.init()
    node = WriterNode("fawaikuangtu","法外狂徒张三", 18, "论快速入狱")
    node.eat("鱼香肉丝")
    rclpy.spin(node)
    rclpy.shutdown()