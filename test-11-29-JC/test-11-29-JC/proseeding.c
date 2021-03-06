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

void display(int num)
{
	int input = 0;
	printf("—————————————————————————\n");
	printf("——————————1、FCFS算法 —————————\n");
	printf("——————————2、SJF算法——————————\n");
	printf("——————————3、RR算法 ——————————\n");
	printf("——————————4、优先级算法 ————————\n");
	printf("——————————5、退出 ———————————\n");
	printf("—————————————————————————\n");
	do {
		printf("请选择你想要的算法：");
		scanf("%d",&input);
		switch (input) 
		{
		case 1:
			Arrive_sort(num);
			fcfs(num);
			print(num);
			break;
		case 2:
			Arrive_Short_sort(num);
			sjf(num);
			print(num);
			break;
		case 3:
			RR(num);
			break;
		//case 4:
			//priority(num);
			//break;
		case 0:
			exit;
		default:
			printf("输入错误，请重新输入!\n");
			break;
		}
	} while (input);
}
//按到达时间排序
void Arrive_sort(int num)
{
	int temp1, temp2, temp3;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tarrive > job[j].Tarrive)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
			}
		}
	}
}
//按服务时间排序
void Service_sort(int num)
{
	int temp1, temp2, temp3;
	for (int i = 1; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tservice > job[j].Tservice)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
			}
		}
	}

}
void Priority_sort(int num)//按优先级减小排序
{
	int temp1, temp2, temp3, temp4;
	for (int i = 1; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].prio < job[j].prio)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
				temp4 = job[j].prio;
				job[j].prio = job[i].prio;
				job[i].prio = temp3;
			}
		}
	}
}
//如果到达时间相等，服务时间按从小到大排序
void Arrive_Short_sort(int num)
{
	int temp1, temp2, temp3;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tarrive >= job[j].Tarrive)
			{
				if (job[i].Tarrive > job[j].Tarrive)
				{
					temp1 = job[j].name;
					job[j].name = job[i].name;
					job[i].name = temp1;
					temp2 = job[j].Tarrive;
					job[j].Tarrive = job[i].Tarrive;
					job[i].Tarrive = temp2;
					temp3 = job[j].Tservice;
					job[j].Tservice = job[i].Tservice;
					job[i].Tservice = temp3;
				}
				else
				{
					if (job[i].Tservice > job[j].Tservice)
					{
						temp1 = job[j].name;
						job[j].name = job[i].name;
						job[i].name = temp1;
						temp2 = job[j].Tarrive;
						job[j].Tarrive = job[i].Tarrive;
						job[i].Tarrive = temp2;
						temp3 = job[j].Tservice;
						job[j].Tservice = job[i].Tservice;
						job[i].Tservice = temp3;
					}
				}
			}
		}
	}
}
void fcfs(int num)//先来先服务
{
	for (int i = 0; i < num; i++)
	{
		job[i].Tstart = job[i - 1].Taccomplish;//上一个作业结束时间
		if (job[i].Tstart < job[i].Tarrive)
		{
			job[i].Tstart = job[i].Tarrive;
		}
		else
		{
			job[i].Tstart = job[i - 1].Taccomplish;
		}
		job[i].Taccomplish = job[i].Tstart + job[i].Tservice;
	}
}
void sjf(int num)//短作业优先
{
	for (int i = 0; i < num; i++)
	{
		job[i].Tstart = job[i - 1].Taccomplish;//上一个作业结束时间
		if (job[i].Tstart < job[i].Tarrive)//该作业的开始时间小于到达时间
		{
			job[i].Tstart = job[i].Tarrive;
		}
		else
		{
			job[i].Tstart = job[i - 1].Taccomplish;
		}
		job[i].Taccomplish = job[i].Tstart + job[i].Tservice;
	}
}
void RR(int num)//RR算法
{
	int q;
	printf("请输入时间片长度：");
	scanf("%d",&q);
	int flag = 1;//标志队列中是否还有进程
	int finish_pro = 0;//完成的进程数
	printf("进程名称  开始时间   运行时间  剩余服务时间  结束时间");
	int time;//记录当前时刻时间
	int c = 0;
	while (finish_pro < num)
	{
		flag = 0;//就绪队列里没进程
		for (int i = c; i < num; i++)
		{
			Arrive_sort(num);
			job[i].Tsurplus = job[i].Tservice;
			job[i].Tstart = job[i - 1].Taccomplish;//上一个作业结束时间
			if (job[i].Tstart < job[i].Tarrive)//该作业的开始时间小于到达时间
			{
				job[i].Tstart = job[i].Tarrive;
			}
			else
			{
				job[i].Tstart = job[i - 1].Taccomplish;
			}
			time = job[i].Tstart;
			if (job[i].if_finish == 1) continue;//该进程已完成
			else
			{
				if (job[i].Tsurplus <= q && time >= job[i].Tarrive)//未完成且少于一个时间片
				{
					flag = 1;
					time = time + job[i].Tsurplus;
					job[i].if_finish = 1;//该进程完成
					job[i].Taccomplish = time;
					printf(" job[i].name  job[i].Taccomplish - job[i].Tsurplusjob[i].Tsurplus  job[i].Taccomplish" );
					job[i].Tsurplus = 0;
				}
				else if (job[i].Tsurplus > q && time >= job[i].Tarrive)
				{
					flag = 1;
					time = time + q;
					job[i].Tsurplus -= q;
					job[i].Taccomplish = time;
					printf(" job[i].name time - q  q  job[i].Tsurplus  job[i].Taccomplish ");
					job[num].name = job[i].name;
					job[num].Tarrive = time;
					job[num].Tservice = job[i].Tsurplus;
					num++;
				}
				if (job[i].if_finish == 1) finish_pro++;//一个进程完成加一
			}
			c++;
		}break;
		if (flag == 0 && finish_pro < num)//没执行完且没进入就绪队列
		{
			for (int i = 0; i < num; i++)
			{
				if (job[i].if_finish == 0)
				{
					time = job[i].Tarrive;
					break;
				}
			}
		}
	}
}
void print(int num)
{
	printf("进程名  到达时间   服务时间  完成时间");

	for (int i = 0; i < num; i++)
	{
		printf(" job[i].name  job[i].Tarrive  job[i].Tservice  job[i].Taccomplish");
	}
}
