# UE4-Campus-Simulation-Demo 2019.08-2019.11
2人开发一款校园模拟游戏中，初始场景位于火车站，从搭建C++框架开始。<br>
使用适合的`设计模式`，`UE4 C++`搭建框架，解决了多人开发时蓝图时不易合并、可扩展性、C++结构清晰效率更高等问题。<br>
目前包含：<br>
* GamePlay框架
  * GameMode中采用`单例模式`创建任务、Npc、奇遇事件管理器
  * 对象资源、信息存放使用`DataAsset`
  * 资源加载方式使用`FSoftObjectPtr`，防止处理不当，就会在游戏开始时加载全部资源
  * `USaveGame`实现存档，`UGameInstance`永远存在，保护存档信息
* 任务系统
  * 采用`观察者模式`，使用`Delegate`广播告知玩家任务状态的改变，UMG更新任务列表
  * 任务对象使用`虚函数`暴露接口，使任务可自定义接受、进行、完成时的操作
  * 几个简单的任务：等待一段时间、移动到目标点、A处接任务　与B对话完成任务并交任务
  * ……
* 奇遇系统
  * ……
* Npc系统
  * 采用`工厂模式`创建Npc对象，`Info Class`管理Npc数据结构体
  * 继承`UActorComponent`创建对话音波组件、任务处理组件，用于扩展不同的Npc功能
  * 播控对话时的Sequence动画
  * 完成了地铁站行人模拟
    * Detour Crowd AI Controller实现人群避障，并修正了转向不平滑问题
    * EQS与情景查询行人随机生成点、销毁点与大厅休息点
    * 寻路网格导航、黑板、行为树自定义任务控制行人运动
### CSDN技术分享<br>
* [【UE4 C++】大规模人群绕行避让的最优解DetourCrowdAIController如何开启](https://blog.csdn.net/qq_31788759/article/details/103253451)<br>
* [【UE4 AI】AI Move To寻路转向时解决突变、使得平滑过渡的方法（含C++）](https://blog.csdn.net/qq_31788759/article/details/103267162)<br>
### 行人模拟效果
![StrangerSimulate](https://github.com/ColorGalaxy/UE4-Campus-Simulation-Demo/raw/master/Screenshot/StrangerSimulate.png)<br>
### EQS与行为树
![EQS](https://github.com/ColorGalaxy/UE4-Campus-Simulation-Demo/raw/master/Screenshot/EQS.png)<br>
![BehaviorTree](https://github.com/ColorGalaxy/UE4-Campus-Simulation-Demo/raw/master/Screenshot/BehaviorTree.png)<br>
### Git协作记录
![UploadRecord](https://github.com/ColorGalaxy/UE4-Campus-Simulation-Demo/raw/master/Screenshot/UploadRecord.png)<br>
