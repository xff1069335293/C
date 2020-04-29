//找出字符串中第一个只出现一次的字符
//
//输入描述:
//输入一个非空字符串
//
//输出描述 :
//输出第一个只出现一次的字符，如果不存在输出 - 1
//
//示例1
//输入
//复制
//asdfasdfo
//输出
//复制
//o
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (cin >> s) {
		int flag = 0;
		int count[26] = { 0 };
		for (auto ch : s) {
			count[ch - 'a']++;
		}
		for (size_t i = 0; i < s.size(); ++i) {
			if (count[s[i] - 'a'] == 1) {
				cout << s[i] << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << -1 << endl;
		}
	}
	return 0;
}