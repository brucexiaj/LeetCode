bool isPalindrome(int x) {
    if(x < 0) {
        return false;
    }
    int ev[10];
    int index = 0;
    for(int i = 1000000000;i >= 1;i = i/10) {
        int b = x/i;
        x = x - b * i;
        if(0 == b && 0 == index) {
           continue;
        }   
        ev[index++] = b;
    }
    for(int j = 0;j < index/2;j++) {
        if(ev[j] != ev[index-j-1])
            return false;
    }
    return true;
}