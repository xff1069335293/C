#define _CRT_SECURE_NO_WARNINGS 1
//输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
//
//序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
//
//
//
//示例 1：
//
//输入：target = 9
//输出：[[2, 3, 4], [4, 5]]
//示例 2：
//
//输入：target = 15
//输出：[[1, 2, 3, 4, 5], [4, 5, 6], [7, 8]]
//
//
//限制：
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
		/* tmpTar大于0时, 继续减 */
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