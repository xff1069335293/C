//结构体&&多级指针问题
//#define _CRT_SECURE_NO_WARNINGS 1
//结构体问题1.定义 2.调用3.初始化4.赋值
//struct student	//有结构体名，有结构体变量
//{
//	char* name;
//	int age;
//	int num;
//}stu;
//
//
//struct student1 //有结构体名，无结构体变量
//{
//	char name[10];
//	int age;
//	int num;
//};
//
//typedef struct student2//重新命名，有结构体名字
//{
//	char* name;
//	int age;
//	int num;
//}student22;
//
//
//typedef struct //重新命名 无结构体名字
//{
//	char* name;
//	int age;
//	int num;
//}student3;
//
//
//struct Student1
//{
//	char name[20];
//	char sex;
//	int number;
//}stu2[5] = {
//	 {"zhaozixuan",'M',12345},
//	 {"houxiaohong",'M',12306},
//	 {"qxiaoxin",'W',12546},
//	 {"wangwei",'M',14679},
//	 {"yulongjiao",'W',17857}
//};
//
//struct Student
//{
//	char name[20];
//	char sex;
//	int number;
//};
//struct Student stu1[5] = {
//	 {"zhaozixuan",'M',12345},
//	 {"houxiaohong",'M',12306},
//	 {"qxiaoxin",'W',12546},
//	 {"wangwei",'M',14679},
//	 {"yulongjiao",'W',17857}
//};


#include<stdio.h>
int main()
{
	/*struct student stu1= { "xf",13,14 };
	printf("%s %d %d\n", stu1.name,stu1.age,stu1.num);
	struct student1 stu11= { "xff",13,14 };
	printf("%s %d %d\n", stu11.name,stu11.age,stu11.num);
	student22  stu22={ "xfff",13,14 };
	printf("%s %d %d\n", stu22.name, stu22.age, stu22.num);
	struct student2 stu222 = { "xff",13,14 };
	printf("%s %d %d\n", stu222.name, stu222.age, stu222.num);
	student3 stu33 = { "xffff",13,14 };
	printf("%s %d %d\n", stu33.name, stu33.age, stu33.num);*/
	//printf("%c",stu1[0].name[2]);
	//printf("%c", stu2[0].name[2]);
	//stu2[0].name[2] = 'n';
	//printf("%c", stu2[0].name[2]);
	//struct Student
	//{
	//	char cName[20];
	//	char csex;
	//	int number;
	//	
	//}student1;
	//struct Student stu1[1] = {
	// {"zhaozixuan",'M',12345},
	// {"houxiaohong",'M',12306},
	// {"qxiaoxin",'W',12546},
	// {"wangwei",'M',14679},
	// {"yulongjiao",'W',17857}
	//};
	//struct Student*p;
	//p = &student1;//若为结构体数组则
	//p = stu1;//因为stu1为结构体数组而p=stu1直接是指向stu1的首地址，就不用再加&符
	//printf("%c %c", p->cName[2],(*p).cName[4]);
//
//	int ch = 5;													//多级指针含义
//	int* p1;//p是地址
//	p1 = &ch;
//	int** p2;
//	p2 = &p1;							
//	printf("%d %d %d %p %p %p %p %p",ch,**p2,*p1,p1,&ch,*p2,&p1,p2);
//	system("pause");
//	return 0;
//}

