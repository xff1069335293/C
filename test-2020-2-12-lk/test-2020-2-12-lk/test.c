#define _CRT_SECURE_NO_WARNINGS 1
//给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。
//字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。
//输入：text = "nlaebolko"
//输出：1    
int maxNumberOfBalloons(char* text) {
	int ret = 0;
	int chnum[26] = { 0 };

	while (*text != '\0')
	{
		chnum[*text - 'a']++;
		text++;
	}

	while (chnum['b' - 'a'] >= 1
		&& chnum['a' - 'a'] >= 1
		&& chnum['l' - 'a'] >= 2
		&& chnum['o' - 'a'] >= 2
		&& chnum['n' - 'a'] >= 1)
	{
		chnum['b' - 'a']--;
		chnum['a' - 'a']--;
		chnum['l' - 'a'] -= 2;
		chnum['o' - 'a'] -= 2;
		chnum['n' - 'a']--;
		ret++;
	}
	return ret;
}