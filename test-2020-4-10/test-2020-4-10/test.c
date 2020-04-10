//.请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
//
//示例 1：
//
//输入：s = “We are happy.”
//输出：“We % 20are % 20happy.”
//
//限制：
//
//0 <= s 的长度 <= 10000



char* replaceSpace(char* s)
{
	int count = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ' ')
		{
			++count;
		}
	}
	char* arr = (int *)malloc(sizeof(int)*(len + 2 * count));
	arr[len + 2 * count] = 0;
	count = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] != ' ')
		{
			arr[i + count] = s[i];
		}
		else
		{

			arr[i + count] = '%';
			arr[i + 1 + count] = '2';
			arr[i + 2 + count] = '0';
			count += 2;
		}
	}
	return arr;
}
