//给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向(水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。
//
//找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)
//
//示例 1:
//
//[[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
//[0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
//[0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
//[0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
//[0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]]
//对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。
//
//示例 2:
//
//[[0, 0, 0, 0, 0, 0, 0, 0]]


#define MAX(a,b) ((a) > (b) ? (a) : (b))

void dfs(int **grid, int m, int n, int i, int j, int *cnt) {
	if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) {
		return;
	}

	(*cnt)++;
	grid[i][j] = 2;

	dfs(grid, m, n, i + 1, j, cnt);
	dfs(grid, m, n, i - 1, j, cnt);
	dfs(grid, m, n, i, j + 1, cnt);
	dfs(grid, m, n, i, j - 1, cnt);
	return;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
	if (gridSize == 0 || gridColSize[0] == 0) {
		return 0;
	}
	int m = gridSize;
	int n = gridColSize[0];
	int cnt, i, j;
	int max = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (grid[i][j] == 1) {
				cnt = 0;
				dfs(grid, m, n, i, j, &cnt);
				max = MAX(max, cnt);
			}
		}
	}
	return max;
}