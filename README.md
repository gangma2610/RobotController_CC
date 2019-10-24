# RobotController_CC
C++版机械臂接口。

---
### RobotController

#### MoveByAxis
向机械臂发送0，通过关节坐标移动机械臂。

#### MoveByCar
向机械臂发送1，通过笛卡尔坐标移动机械臂。

#### MoveAxisByOffset
向机械臂发送2，通过笛卡尔坐标偏移量移动机械臂。

#### MoveCarByOffset
向机械臂发送3，通过笛卡尔坐标偏移量移动机械臂。

#### GetCurrentAxisPos
向机械臂发送6，机械臂回复六个浮点数，即关节坐标值。

#### GetCurrentCarPos
向机械臂发送7，机械臂回复六个浮点数，即笛卡尔坐标值。

#### OpenPaw
向机械臂发送4，张开夹持器。

#### ClosePaw
向机械臂发送5，闭合夹持器。

#### SetSpeed
向机械臂发送8，设置机械臂运动的速度。

#### MoveByJointTrajectory
向机械臂发送9，设置机械臂基于路点运动。


