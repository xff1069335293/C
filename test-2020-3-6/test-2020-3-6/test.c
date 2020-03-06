#define _CRT_SECURE_NO_WARNINGS 1
//����һ�������� target ��������к�Ϊ target ���������������У����ٺ�������������
//
//�����ڵ�������С�������У���ͬ���а����׸����ִ�С�������С�
//
//
//
//ʾ�� 1��
//
//���룺target = 9
//�����[[2, 3, 4], [4, 5]]
//ʾ�� 2��
//
//���룺target = 15
//�����[[1, 2, 3, 4, 5], [4, 5, 6], [7, 8]]
//
//
//���ƣ�
//
//1 <= target <= 10 ^ 5



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes)
{
	int n = target / 2;
	int **res = (int**)malloc(sizeof(int*) * n);
	*returnColumnSizes = (int*)malloc(sizeof(int) * n);
	*returnSize = 0;
	int i, j, k, tmpTar;
	for (i = 1; i <= n; i++) {
		tmpTar = target;
		j = i;
		/* tmpTar����0ʱ, ������ */
		while (tmpTar > 0) {
			tmpTar -= j;
			j++;
		}
		if (tmpTar == 0) {
			res[*returnSize] = (int*)malloc(sizeof(int) * (j - i));
			for (k = i; k < j; k++) {
				res[*returnSize][k - i] = k;
				(*returnColumnSizes)[*returnSize] = j - i;
			}
			(*returnSize)++;
		}
	}
	return res;
}