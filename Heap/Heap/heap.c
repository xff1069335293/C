#include"heap.h"

//交换函数
void Swap(int* p1,int* p2)	
{
	int tmp = *p2;
	*p2 = *p1;
	*p1 = tmp;
}

//向下调整
void AdjustDown(HPDataType* a, int n, int root)		
{
	assert(a);
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

//建堆
void HeapCreate(Heap* hp, HPDataType* a, int n)  
{
	assert(hp && a);
	hp->_a = (HPDataType *)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_capacity = n;
	hp->_size = n;
	
	for (int i = (hp->_size-2)/2; i >= 0; --i)  //从最后一个子节点找它的双亲节点。
	{
		AdjustDown(hp->_a,hp->_size	,i);
	}
}

//向上调整
void AdjustUp(HPDataType* a, int n)
{
	int child = n-1;
	int parent = (child - 1) / 2;
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

//增容
void Checkcapacity(Heap* hp)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		
		HPDataType newcapacity = hp->_capacity == 0 ? 2 : 2 * hp->_capacity;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*newcapacity);//要用realloc追加
		hp->_capacity = newcapacity;
	}
}

//堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	Checkcapacity(hp);
	hp->_a[hp->_size] = x;
	++hp->_size;
	AdjustUp(hp->_a, hp->_size);
	
}

//堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	for (int i = (hp->_size - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

//打印
void HeapPrint(Heap* hp)	//打印
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

//取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}

//堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

//堆的判空
int   HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;

}

//堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

//堆排序

void HeapSort(int* a, int n) //堆排序	降序用小堆
{
	assert(a);
	for (int i = (n - 2) / 2; i >= 0; --i)		//先建堆
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}

}

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆


void TestTopk()
{
	Heap hp;
	HPDataType*a = (HPDataType*)malloc(sizeof(HPDataType)*N); 
	srand((unsigned int)time(0));
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 10;
	}
	HeapCreate(&hp, a, K); 
	for (int i = K; i < N; i++)
	{
		if ((HPDataType)HeapTop(&hp) > a[i])
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
		
	}
	HeapPrint(&hp);
	
}

TestHeap()
{
	Heap hp;
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	int n = sizeof(a) / sizeof(a[0]);
	HeapCreate(&hp,a,n);
	HeapPrint(&hp);
	HeapPush(&hp, 4);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapDestory(&hp);
	HeapPrint(&hp);
	HeapEmpty(&hp);
	HeapSize(&hp);
	HeapSort(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
	
}
