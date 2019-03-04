int isDigit(char s) {
    char ch[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(int i = 0;i < 10;i++) {
        if(ch[i] == s) {
            return 1;
        }
    }
    return 0;
}

//去掉前面的空格符号
char* noWhite(char *str) {      
     int len = strlen(str);
	 char *result = (char *)malloc(sizeof(char)*(len + 1)); 
	 int index = 0, flag = 0;
     for(int i = 0;i < len;i++) {
        if(' ' == str[i] && flag == 0) 
            continue;
        result[index++] = str[i];     
		flag = 1;
     }
	 result[index] = '\0';
     return result;     
}

//获取数字
char* getNumberChar(char *s) {
    int len = strlen(s);
	char *result = (char *)malloc(sizeof(char)*(len + 1));
	int index = 0, flag = 0;
	int i = isDigit(s[0]) ? 0 : 1;
	for(;i < len;i++) {
		if(isDigit(s[i])) {
			if(s[i] == '0' && flag == 0) {
				continue;
			} else {
				result[index++] = s[i];
				flag = 1;
			}				
		} else {
			break;
		}
	}
    result[index] = '\0';
    return result;
}

int myAtoi(char* str) {
    char *s = noWhite(str);
    if(!isDigit(s[0]) && '+' != s[0] && '-' != s[0])
        return 0;
    char *number = getNumberChar(s);
    int len = strlen(number);
	if(0 == len)
		return 0;
    if(len > 10) 
        return s[0] == '-' ? -2147483648 : 2147483647;
    long result = 0;
    long k = 1;
    for(int i = 0;i < len;i++) {                         
        result += (number[len - 1 - i] - 48) * k;
        k *= 10;
    }
    if(s[0] == '-') {
        result = -result;
    }
	if(result > 2147483647) {
		result = 2147483647;
    }
	if(result < -2147483648){
		result = -2147483648;
	}
    return (int)result;
  
}
