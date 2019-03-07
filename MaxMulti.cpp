// MaxMulti.cpp : 定义控制台应用程序的入口点。
//牛客网
//最大乘积问题
//https://www.nowcoder.com/practice/5f29c72b1ae14d92b9c3fa03a037ac5f?tpId=90&tqId=30776&tPage=1&rp=1&ru=/ta/2018test&qru=/ta/2018test/question-ranking

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	 int max = 0, middle = 0, min = 0;
    int mmin = 0, mmiddle = 0;
    int a;
    scanf("%d",&a);
    while(scanf("%d",&a) != EOF) {
            if (a > max) {
                min = middle;
                middle = max;
                max = a;               
            } else if (a > middle) {
                min = middle;
                middle = a;
            } else if (a > min) {
                min = a;
            } else if (a < mmin) {
                mmiddle = mmin;
                mmin = a;
            } else if (a < mmiddle) {
                mmiddle = a;
            } else {
                
            }
        
    } 
    //这里注意一定要强制类型转换，因为两个int相乘会溢出，即使用long接收结果也不行
    long r1 = (long)max * (long)middle * (long)min;
    long r2 = (long)max * (long)mmiddle * (long)mmin;
    printf("%ld\n", r1 > r2 ? r1 : r2);
    return 0;
}

