//����ƥ���㷨ʵ��

bool isValid(char * s) {
	if (s == NULL || s[0] == '\0') return true;
	char *stack = (char*)malloc(strlen(s) + 1); int top = 0;
	for (int i = 0; s[i]; ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') stack[top++] = s[i];
		else {
			if ((--top) < 0)                      return false;//�ȼ�������topָ��ջ��Ԫ��
			if (s[i] == ')' && stack[top] != '(') return false;
			if (s[i] == ']' && stack[top] != '[') return false;
			if (s[i] == '}' && stack[top] != '{') return false;
		}
	}
	return (!top);//��ֹ�����������������
}
