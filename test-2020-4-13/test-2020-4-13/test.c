//1.字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
//
//示例 1：
//
//输入 : s = “abcdefg”, k = 2
//	输出 : “cdefgab”
//	示例 2：
//
//	输入 : s = “lrloseumgh”, k = 6
//	输出 : “umghlrlose”
//
//
	void Swap(char *pa, char *pb)
{
	char tmp = *pb;
	*pb = *pa;
	*pa = tmp;
}
void Reverse(char* s, int begin, int end)
{
	while (begin < end)
	{
		Swap(&s[begin], &s[end]);
		++begin;
		--end;
	}
}
char* reverseLeftWords(char* s, int n)
{
	int len = strlen(s);
	Reverse(s, 0, n - 1);
	Reverse(s, n, len - 1);
	Reverse(s, 0, len - 1);
	return s;
}
