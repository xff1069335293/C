#include"heap.h"

//��������
void Swap(int* p1,int* p2)	
{
	int tmp = *p2;
	*p2 = *p1;
	*p1 = tmp;
}

//���µ���
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

//����
void HeapCreate(Heap* hp, HPDataType* a, int n)  
{
	assert(hp && a);
	hp->_a = (HPDataType *)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_capacity = n;
	hp->_size = n;
	
	for (int i = (hp->_size-2)/2; i >= 0; --i)  //�����һ���ӽڵ�������˫�׽ڵ㡣
	{
		AdjustDown(hp->_a,hp->_size	,i);
	}
}

//���ϵ���
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

//����
void Checkcapacity(Heap* hp)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		
		HPDataType newcapacity = hp->_capacity == 0 ? 2 : 2 * hp->_capacity;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*newcapacity);//Ҫ��realloc׷��
		hp->_capacity = newcapacity;
	}
}

//�ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	Checkcapacity(hp);
	hp->_a[hp->_size] = x;
	++hp->_size;
	AdjustUp(hp->_a, hp->_size);
	
}

//�ѵ�ɾ��
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

//��ӡ
void HeapPrint(Heap* hp)	//��ӡ
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

//ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}

//�ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

//�ѵ��п�
int   HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;

}

//�ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

//������

void HeapSort(int* a, int n) //������	������С��
{
	assert(a);
	for (int i = (n - 2) / 2; i >= 0; --i)		//�Ƚ���
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

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��


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
