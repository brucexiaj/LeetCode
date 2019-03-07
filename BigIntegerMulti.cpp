// BigIntegerMulti.cpp : 定义控制台应用程序的入口点。
//
//来源：牛客网
//大数相乘
//https://www.nowcoder.com/practice/0f0badf5f2204a6bb968b0955a82779e?tpId=90&tqId=30777&tPage=1&rp=1&ru=/ta/2018test&qru=/ta/2018test/question-ranking
#include "stdafx.h"


//字符倒转
char *reverse(char *s) {
	int len = strlen(s);
	char *result = (char *)malloc(sizeof(char) * (len + 1));
	for (int i = 0;i < len;i++)
		result[i] = s[len - 1 - i];
	result[len] = '\0';
	return result;
}

//大数求和
char *sum(char *m, char *n) {
	int len = strlen(m) > strlen(n) ? (strlen(m) + 3) : (strlen(n) + 3);
	char *result = (char *)malloc(sizeof(char) * len);
	int mIndex = strlen(m) - 1;
	int nIndex = strlen(n) - 1;
	int enter = 0, index = 0, sum = 0;
	while (mIndex >= 0 && nIndex >= 0) {
		sum = m[mIndex--] + n[nIndex--] - 96 + enter;
		enter = sum / 10;
		result[index++] = (char)(sum - enter * 10 + 48);
	}
	while(mIndex >= 0) {
		sum = m[mIndex--] - 48 + enter;
		enter = sum / 10;
		result[index++] = (char)(sum - enter * 10 + 48);
	}
	while(nIndex >= 0) {
		sum = n[nIndex--] - 48 + enter;
		enter = sum / 10;
		result[index++] = (char)(sum - enter * 10 + 48);
	}
	if (enter != 0)
		result[index++] = (char)(enter + 48);
	result[index] = '\0';
	return reverse(result);
}

int _tmain(int argc, _TCHAR* argv[])
{	
	char *m = (char *)malloc(sizeof(char) * 1000);
    char *n = (char *)malloc(sizeof(char) * 1000);
	char *re = (char *)malloc(sizeof(char) * 1000);
	char *result = (char *)malloc(sizeof(char) * 1000);
    result[0] = '\0';
    scanf("%s", m);
    scanf("%s", n);
	for (int i = strlen(n) - 1;i >= 0;i--) {
		int enter = 0, index = 0;
		for (int k = 0;k < strlen(n) - 1 - i;k++)
			re[index++] = '0';
		for (int j = strlen(m) - 1;j >= 0;j--) {
			int rCur = (m[j] - 48) * (n[i] - 48) + enter;
			enter = rCur / 10;
			re[index++] = (char)(rCur - 10 * enter + 48);
		}
		if (0 != enter)
			re[index++] = (char)(enter + 48);
		re[index] = '\0';
		//求和
		result = sum(result, reverse(re));
	}

	printf("%s\n", result);
    return 0;
}