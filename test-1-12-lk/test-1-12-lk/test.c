﻿//第k个排列
//给出集合 [1, 2, 3, …, n]，其所有元素共有 n!种排列。
//按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
//
//"123"
//"132"
//"213"
//"231"
//"312"
//"321"
char * getPermutation(int n, int k) {
	int i, factorial;

	factorial = 1;
	for (i = 1; i <= n; i++) {
		factorial *= i;
	}

	char buf[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
	char* str = (char*)malloc(sizeof(char) * (n + 1));
	int j = 0;

	k = k - 1;
	while (n) {
		k = k % factorial;
		factorial = factorial / n;

		i = k / factorial;
		str[j++] = buf[i];
		for (; i + 1 < n; i++) {
			buf[i] = buf[i + 1];
		}
		n = n - 1;
	}
	str[j] = '\0';
	return str;
}