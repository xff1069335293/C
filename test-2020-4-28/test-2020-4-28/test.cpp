//�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
//
//��������:
//����һ���ǿ��ַ���
//
//������� :
//�����һ��ֻ����һ�ε��ַ��������������� - 1
//
//ʾ��1
//����
//����
//asdfasdfo
//���
//����
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