#include"heap.h"
void Swap(int* p1,int* p2)	//交换函数
{
	int tmp = *p2;
	*p2 = *p1;
	*p1 = tmp;
}

void AdjustDown(HPDataType* a, int n, int root)		//向下调整
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] > a[child + 1])
		{
			++child;
		}

		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void AdjustUp(HPDataType* a, int child)//向上调整
{
	//int child = n-1;
	int parent = (child - 2) / 2;
	while (child)
	{
		
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}

	}
}

void Print(Heap* hp)	//打印
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ",hp->_a[i]);
	}
	printf("\n");
}

void HeapCreate(Heap* hp, HPDataType* a, int n)  //建堆
{
	assert(hp && a);
	//Heap* hp = (Heap *)malloc(sizeof(Heap));
	hp->_a = (HPDataType *)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_capacity = n;
	hp->_size = n;
	
	for (int i = (n-2)/2; i >= 0; --i)  //从最后一个子节点找它的双亲节点。
	{
		AdjustDown(hp->_a,hp->_size	,i);
	}
}

void HeapSort(Heap* hp, int n) //堆排序	降序用小堆
{
	assert(hp);
	for (int i = (n - 2) / 2; i >= 0; --i)		//先建堆
	{
		AdjustDown(hp->_a,n,i);
	}
	int end = n-1 ;
	while (end)
	{	
		Swap(&hp->_a[0], &hp->_a[end]);
		AdjustDown(hp->_a, end, 0);
		end--;
	}

}


// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}


// 堆的数据个数
void HeapSize(Heap* hp)
{
	assert(hp);
	return printf("堆的数据个数为：%d\n",hp->_size);
}

// 堆的判空
void   HeapEmpty(Heap* hp)
{
	assert(hp);
	if (hp->_size == 0)
	{
		printf("堆为空\n");
	}
	else
	{
		printf("堆不为空\n");
	}
	
}

//增容
void Checkcapacity(Heap* hp)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		HPDataType newcapacity = hp->_capacity == 0 ? 2 : 2 * hp->_capacity;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);//要用realloc追加
		hp->_capacity = newcapacity;
	}
}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	Checkcapacity(hp);
	hp->_a[hp->_size] = x;
	
	AdjustUp(hp->_a, hp->_size);
	++hp->_size;
}
// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	--hp->_size;
	for (int i = (hp->_size - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	hp->_a = NULL;
	free(hp->_a);
	hp->_capacity = 0;
	hp->_size = 0;
}


void test()
{
	Heap hp;
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	int n = sizeof(a) / sizeof(a[0]);
	HeapCreate(&hp,a,n);
	Print(&hp);
	HeapPush(&hp, 4);
	Print(&hp);
	HeapPop(&hp);
	Print(&hp);
	/*HeapSort(&hp, n);
	Print(&hp);*/
	HeapDestory(&hp);
	Print(&hp);
	HeapEmpty(&hp);
	HeapSize(&hp);
}