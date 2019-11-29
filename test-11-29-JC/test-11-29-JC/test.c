#include"proceeding.h"
struct Node
{
	char name;//进程名
	int Tarrive;//到达时间
	int Tservice;//服务时间	
	int Tsurplus;//剩余时间
	int Tstart;//开始时间
	int Taccomplish;//完成时间
	int prio;//优先级
	int if_finish; //是否完成
	int num;//进程数
}job[10];

int main()
{
	int num;
	char jname;//进程名
	int arrive;//到达时间	
	int service;//服务时间
	int accomplish;//完成时间
	scanf("%d",&num);//进程数
	printf("请输入进程名 到达时间 服务时间\n");
	for (int i = 0; i < num; i++)
	{
	
		scanf("%c", &jname);
		job[i].name = jname;
		scanf("%d", &arrive);
		job[i].Tarrive = arrive;
		scanf("%d", &service);
		job[i].Tservice = service;
	}
	display(num);
	return 0;
}
