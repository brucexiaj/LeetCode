

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows == 1 || len == 0) 
        return s;   
    char *result = (char *)malloc(sizeof(char)*(len+1));    
    
    
/********************************************method1***************************************/
//     char middle[numRows][len];
//     for(int i = 0;i < numRows;i++) {
//         for(int j = 0;j < len;j++){
//             middle[i][j] = '\n';
//         }
//     }
//     //先把字符串按照z字形存放在一个二维数组中
//     int row = 0, column = 0,flag = 0;
//     for(int k = 0;k < len;k++) {
//         middle[row][column] = s[k];
//         if (k % (numRows - 1) == 0)
//             flag = flag == 0 ? 1 : 0;        
//         if(flag == 1) {
//             row++;
//         } else {
//             row--;
//             column++;
//         }
//     }   
    
//     flag = 0;
//     for(int i = 0;i < numRows;i++) {
//         for(int j = 0;j < len;j++){
//             if(middle[i][j] != '\n')
//                 result[flag++] = middle[i][j];
//         }
//     }    /********************************************method1***************************************/
    
    
    /********************************************method2***************************************/
    //方法2直接根据数学公式求出结果，没有做存储
    int index = 0, in = 0, inj = 0;
    for(int i = 0;i < numRows;i++) {
        for(int j = 0;j < len;j=j+2) {			
            in = j * numRows - j + i;
			inj = in - 2 * i;
            if(inj > len - 1) break;
			if(j > 0 && (i%(numRows-1)) != 0) {
				if(index <= len -1) 
					result[index++] = s[inj];
			}
			if(in < 0 || in > len - 1) break;
            if(index <= len -1) result[index++] = s[in];
        }      
    }    /********************************************method2***************************************/
    
    
    
    
    
    result[len]='\0';//加上字符串结束符。  
    return result;
}