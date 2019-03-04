int reverse(int x) {
    long result = 0, k = 1;
    int flag = 0;
    for(int i = 1000000000;i >= 1;i = i / 10) {
        int m = x/i;
        if((flag == 0 && m != 0) || flag == 1){
            flag = 1;
            result += m * k;
            k = k * 10;
            x = x - m * i;
        }
    }                                                                                             if(result > 2147483647 || result < -2147483648) {
        return 0;
    } else {
        return (int)result;
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                       
}