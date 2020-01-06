// ÒÆ³ýÎÞÐ§µÄÀ¨ºÅ
char * minRemoveToMakeValid(char * s) {
	int i;
	int index = 0;
	int len = strlen(s);
	int *stack = (int *)malloc(sizeof(int) * len);
	for (i = 0; i < len; i++) {
		if (s[i] == '(') {
			stack[index++] = i;
		}
		else if (s[i] == ')') {
			if (index > 0) {
				index--;
			}
			else {
				s[i] = '.';
			}
		}
	}
	for (i = 0; i < index; i++) {
		s[stack[i]] = '.';
	}
	index = 0;
	for (i = 0; i < len; i++) {
		if (s[i] == '.') {
			continue;
		}
		s[index++] = s[i];
	}
	s[index] = '\0';
	return s;
}