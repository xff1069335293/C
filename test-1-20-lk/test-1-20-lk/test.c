//给出一个区间的集合，请合并所有重叠的区间。
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
	// 创建足够大小的 足够返回
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
	//             // 根据start元素的大小排序 冒泡排序
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
		// 如果满足条件 合并
		if (intervals[i].end >= intervals[i + 1].start)
		{
			// 更新start的值
			intervals[i + 1].start = intervals[i].start;
			// 更新end的值
			intervals[i + 1].end = intervals[i + 1].end > intervals[i].end ? intervals[i + 1].end : intervals[i].end;

		}
		else
		{
			// 如果不需要合并 那么把它记录下来
			target[count++] = intervals[i];
		}
	}
	// 处理最后一个节点
	target[count++] = intervals[intervalsSize - 1];
	*returnSize = count;
	return target;
}