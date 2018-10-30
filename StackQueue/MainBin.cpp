//问题描述：
//设停车场内只有一个可停放 n 辆汽车的狭长通道，且只有一个大门可供汽车进出，汽车在停车场内按车辆到达时间的先后顺序
//依次由北向南排列（大门在最南端，最先到达的第一辆车停放在车场的最北端）
//若车场内已停满 n 辆汽车，则后来的汽车只能在门外的便道上等候, 一旦有车开走，则排在便道上的第一辆车即可开入
//当停车场内某辆车要离开时，在它之后开入的车辆必须先退出车场为它让路
//待该辆车开出大门外，其它车辆再按原次序进入车场
//每辆停放在车场的车在它离开停车场时必须按它停留的时间长短交纳费用
//当便道上汽车要离开时，排在它前面的汽车要先开走让路，然后再依次排到队尾，并且在便道上停车不收费。
//试为停车场编制按上述要求进行管理的模拟程序。
//基本要求：
//以栈模拟停车场，以队列模拟车场外的便道，按照从终端读入的输入数据序列管理
//每一组输入数据包括三个数据项：汽车“到达”或“离去”信息、汽车牌照号码及到达或离去的时间
//对每一组输入数据进行操作后的输出数据为： 若是车辆到达，则输出汽车在停车场内或便道上的停车位置；
//若是车辆离去，则输出汽车在停车场内停留的时间和应交纳的费用（在便递上停留的时间不收费）

//栈以顺序结构实现，队列以链表结构实现。
//实现提示：
//需另设一栈，临时停放为给要离去的汽车让路而从停车场退出来的汽车，也用顺序存储结构实现。
//输入数据按到达或离去的时刻有序。栈中每个元素表示一辆汽车，包含有两个数据项：汽车牌照号码和进入停车场的时间。

//选作内容：
//（1）两个栈共享空间，思考应开辟数组的空间是多少 ?
//（2）汽车可有不同种类，则它们的占地面积不同，收费标准也不同
//如 1 辆客车和 1.5 辆小汽车的占地面积相同，1辆十轮卡车占地面积相当于3辆小汽车的占地面积 。
//（3）停放在便道上的汽车也收费，收费标准比停放在停车场的车低，请思考如何修改结构以满足这神要求。

//Input
//输入第一行，包括两个数据
//第一个整数为停车场最多可停放车辆数
//第二个浮点数表示单位时间的停车费用。
//接下来有多行数据，每行有三个整数
//第一个为0或1，0表示进入车场，1表示离开车场
//第二个整数为车号；
//第三个整数为进入或离开的时间。
//当一行中三个数均为0时表示输入结束，所有数据之间由空格分隔。

//Output
//输出为三部分
//第一部分为按离开停车场顺序打印出的各车费用，每车一行，包括车号和费用(保留小数点后两位)。
//第二部分占一行为当前停车场中的所有车辆，从北到南顺序输出各车车号。
//第三部分占一行为当前便道上的所有车辆，从前向后顺序输出各车车号。各车号之间由一个空格分隔。

//SampleInput
//2  1.5
//0  1  5
//0  2  10
//1  1  15
//0  3  20
//0  4  25
//0  5  30
//0  6  35
//1  2  40
//0  7  45
//1  6  50
//0  0  0
//Sample Output
//1  15.00
//2  45.00
//3  4
//7  5

#include <fstream>
#include "Stack.h"
#include "Quene.h"

int main() {
	std::fstream inputfile, outputfile;
	inputfile.open("input", std::ios::in);
	outputfile.open("output", std::ios::out);

	//主体

	//读入停车场容量和每小时收费
	int car_num_parking;
	double cost_per_hour;
	inputfile >> car_num_parking;
	inputfile >> cost_per_hour;

	Stack<int> st;
	Stack<int> sttemp;
	Quene<int> que;
	que.entreQuene(123);
	que.entreQuene(11);

	//输入以及处理
	//int *cardata = new int[3];
	//while(!inputfile.eof())
	//{
	//	int location;
	//	inputfile >> cardata[0];
	//	inputfile >> cardata[1];
	//	inputfile >> cardata[2];
	//	if (cardata[0]==false)
	//	{
	//		st.Push(cardata[1], cardata[2]);
	//	}
	//	else
	//	{
	//		location=st.LocateElem(cardata[1]);
	//		for (int i = 0; i < location; i++)
	//		{
	//			//continue
	//		}
	//		location = 0;
	//	}
	//}
	//输出。

	inputfile.close();
	outputfile.close();
}