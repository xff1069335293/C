#define _CRT_SECURE_NO_WARNINGS 1
//����һ�������(ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ���ransom�ܲ����ɵڶ����ַ���magazines������ַ����ɡ�������Թ��ɣ����� true �����򷵻� false��
//
//(��Ŀ˵����Ϊ�˲���¶������ּ���Ҫ����־������������Ҫ����ĸ����ɵ����������˼��)
//
//ע�⣺
//
//����Լ��������ַ�����ֻ����Сд��ĸ��
//
//canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true

bool canConstruct(char * ransomNote, char * magazine) {
	int arr[26] = { 0 };
	while (*magazine != '\0')
	{
		arr[*magazine - 'a']++;
		magazine++;
	}
	while (*ransomNote != '\0')
	{
		arr[*ransomNote - 'a']--;
		if (arr[*ransomNote - 'a'] < 0)
		{
			return false;
		}
		ransomNote++;
	}
	return true;
}