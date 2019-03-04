//判断是不是回文字符串
int judge(char *s, int start, int end) {
    int step = 0;
    int st = start >= 0 ? start : 0;
    int middum = st + (end - st) / 2;
    for(int j = st;j <= middum;j++) {
        if(s[j] != s[end - step])
            return 0;
        step++;
    }
    return 1;
}

//字符串的截取
char* subS(char* ch,int pos,int length)  
 {  
      char* pch=ch;  
      char* subch=(char*)calloc(sizeof(char),length+1);  
    int i;    
     pch=pch+pos;  
     for(i=0;i<length;i++)  
     {  
         subch[i]=*(pch++);   
     }  
     subch[length]='\0';//加上字符串结束符。  
     return subch;       //返回分配的字符数组地址。  
} 

char* longestPalindrome(char* s) {
    int length = strlen(s);
    int start = 0, end = 0;
    for(int i = 1;i < length;i++) {
       int probLength = end - start + 2;
        //要么比原来的长1位，要么长两位
       if(judge(s, i - probLength + 1, i)) {
           start = i - probLength + 1;
           end = i;
       } else {
           int probLength2 = end - start + 3;
           if(judge(s, i - probLength2 + 1, i)) {
               start = i - probLength2 + 1;
               end = i;
           } 
       }
        
    }
    return subS(s, start, end - start + 1);
}
