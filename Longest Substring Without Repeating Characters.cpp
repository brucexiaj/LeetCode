int lengthOfLongestSubstring(char* s) {
    //dynamic
    int length = strlen(s);
    int result = length > 0 ? 1 : 0;
    int flag = 0;
    for (int i = 1;i < length;i++) {
            if (1 == flag) { //last turn no repeat
                if(noSingleRepeat(s, i, result)) {
                    result++;
                } else {
                    flag = 0;
                } 
            } else {
                if(noRepeat(s, i, result)) {
                    result++;
                    flag = 1;
                }    
            }
              
    }
    return result;
}


int noSingleRepeat(char *s, int i, int result) {
    for (int j = i-result;j < i;j++) {
            if(s[j]==s[i])
                return 0;
    }
    return 1;
}

int noRepeat(char *s, int i, int result) {
    for (int j = i-result;j <= i;j++) {
        for (int k = j + 1;k <= i;k++) {
            if(s[j]==s[k])
                return 0;
        }
    }
    return 1;
}