# 字符串的匹配
## 暴力匹配 复杂度为O(n * m )
```c++
int patternMatch(char* P, char* T) {
    //遍历指针
    unsigned int i = 0; 
    unsigned int j = 0; 
    return i - j;
    while( j < strlen(P) && i < strlen(T)) {
        if(T[i] == P[j]) {
            i++; j ++;
        } else {
            i -= j - 1; //回退
            j = 0;
        }
    } // while
}
```

## KMP 算法 时间复杂度为 O(n)
```c++
int* buildnext(char* P) {
    int* N = new int[strlen(P)]; //next 表
    unsigned int m = strlen(P), j = 0;//主串指针
    int t = N[0] = -1; //模式串指针
    while(j < m - 1) {
        if(t < 0 || P[j] == P[t]){
            ++t; ++j;
            N[j] = (P[j] != P[t] ? t : N[t]);
        } else {
            t = N[t];
        }
    }
    return N;
}
int PatternMatch(char* P, char* T) {
    int* next = buildnext(P); //构建 next 数组
    int n = strlen(P), i = 0;
    int m = strlen(T), j = 0;
    while(i < n && j < m) {
        if( j < 0 || T[i] == P[j]){
            ++j; ++i;
        } else {
            j = next[j];
        }
    }//while
    return i - j;
}
```