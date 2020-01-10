﻿//找到小镇的法官
//在一个小镇里，按从 1 到 N 标记了 N 个人。传言称，这些人中有一个是小镇上的秘密法官。
//如果小镇的法官真的存在，那么：
//
//小镇的法官不相信任何人。
//每个人（除了小镇法官外）都信任小镇的法官。
//只有一个人同时满足属性 1 和属性 2 。
//给定数组 trust，该数组由信任对 trust[i] = [a, b] 组成，表示标记为 a 的人信任标记为 b 的人。
//
//如果小镇存在秘密法官并且可以确定他的身份，请返回该法官的标记。否则，返回 - 1。

int findJudge(int N, int** trust, int trustSize, int* trustColSize) {
	int a[N + 1], b[N + 1];
	memset(a, 0, (N + 1) * sizeof(int)); //投
	memset(b, 0, (N + 1) * sizeof(int)); //被投
	for (int i = 0; i < trustSize; i++)
	{
		a[trust[i][0]]++;
		b[trust[i][1]]++;
	}
	//成为法官的条件：被投数为总数-1，并且投票数为0
	for (int i = 1; i <= N; i++)
		if (b[i] == N - 1 && !a[i])
			return i;
	return -1;
}