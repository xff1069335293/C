#define _CRT_SECURE_NO_WARNINGS 1
//你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
//
//你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
//
//
//
//示例 1：
//
//输入：name = "alex", typed = "aaleex"
//输出：true
//解释：'alex' 中的 'a' 和 'e' 被长按。
//示例 2：
//
//输入：name = "saeed", typed = "ssaaedd"
//输出：false
//解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
//示例 3：
//
//输入：name = "leelee", typed = "lleeelee"
//输出：true
//示例 4：
//
//输入：name = "laiden", typed = "laiden"
//输出：true
//解释：长按名字中的字符并不是必要的。
//
//
//提示：
//
//name.length <= 1000
//typed.length <= 1000
//name 和 typed 的字符都是小写字母。
bool isLongPressedName(char* name, char* typed)
{
	int i = 0, j = 0;
	char repeat;
	while (typed[j]) {
		if (name[i] == typed[j])
		{
			i++;
			j++;
			repeat = typed[j];
		}
		else if (typed[j] == repeat)
		{
			j++;
		}
		else
		{
			return false;
		}
	}
	return !name[i];
}

bool isLongPressedName(char* name, char* typed)
{
	// int arr[26] = {0};   //错误解法，本题要保证顺序正确
	// while (*typed != '\0')
	// {
	//     arr[*typed - 'a']++;
	//     typed++;
	// }

	// while (*name != '\0')
	// {
	//     arr[*(name) - 'a']--;
	//     if (arr[*(name) - 'a'] <0)
	//     {
	//         return false;
	//     }
	//     name++;
	// }
	// return true;
	while (*name != '\0' && *typed != '\0')
	{
		if (*name == *typed)
		{
			++name;
		}
		++typed;
	}
	if (*name == '\0')
	{
		return true;
	}
	return false;
}