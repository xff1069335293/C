#define _CRT_SECURE_NO_WARNINGS 1
//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
//
//
//
//示例 1：
//
//输入：s = "We are happy."
//输出："We%20are%20happy."

char* replaceSpace(char* s) {
	int len = strlen(s);
	char* ans = (char*)calloc(len * 3 + 1, sizeof(char));
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] != ' ')
			ans[count++] = s[i];
		else
		{
			ans[count++] = '%';
			ans[count++] = '2';
			ans[count++] = '0';
		}
	}
	ans[count] = '\0';
	return ans;
}