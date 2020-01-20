//����һ������ļ��ϣ���ϲ������ص������䡣
void quicksort(struct Interval *intervals, int start, int end)
{
	int i, j;
	struct Interval  temp;
	if (start > end)
	{
		return;
	}
	temp = intervals[start];
	i = start;
	j = end;
	while (i != j)
	{
		while (i < j&&intervals[j].start >= temp.start)
		{
			j--;
		}
		while (i < j&&intervals[i].start <= temp.start)
		{
			i++;
		}
		if (i < j)
		{
			struct Interval tmp = intervals[i];
			intervals[i] = intervals[j];
			intervals[j] = tmp;
		}
	}
	intervals[start] = intervals[i];
	intervals[i] = temp;
	quicksort(intervals, start, i - 1);
	quicksort(intervals, i + 1, end);
}
struct Interval *merge(struct Interval *intervals, int intervalsSize, int *returnSize)
{
	// �����㹻��С�� �㹻����
	struct Interval *target = (struct Interval *)malloc(sizeof(struct Interval *) * intervalsSize);
	if (intervalsSize <= 0)
	{
		*returnSize = 0;
		return target;
	}

	// for (int i = 0; i < intervalsSize - 1; i++)
	// {
	//     for (int j = 0; j < intervalsSize - 1 - i; j++)
	//     {
	//         if (intervals[j].start > intervals[j + 1].start)
	//         {
	//             // ����startԪ�صĴ�С���� ð������
	//             struct Interval tmp = intervals[j];
	//             intervals[j] = intervals[j + 1];
	//             intervals[j + 1] = tmp;
	//         }
	//     }
	// }
	quicksort(intervals, 0, intervalsSize - 1);

	int count = 0;
	for (int i = 0; i < intervalsSize - 1; i++)
	{
		// ����������� �ϲ�
		if (intervals[i].end >= intervals[i + 1].start)
		{
			// ����start��ֵ
			intervals[i + 1].start = intervals[i].start;
			// ����end��ֵ
			intervals[i + 1].end = intervals[i + 1].end > intervals[i].end ? intervals[i + 1].end : intervals[i].end;

		}
		else
		{
			// �������Ҫ�ϲ� ��ô������¼����
			target[count++] = intervals[i];
		}
	}
	// �������һ���ڵ�
	target[count++] = intervals[intervalsSize - 1];
	*returnSize = count;
	return target;
}