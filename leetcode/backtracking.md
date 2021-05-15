# 回溯算法

## 经常题解
    - 22.md
## 八皇后问题
```c++
class Queen{
public:
    int x, y; //皇后在棋盘上的位置坐标

    bool operator==(const Queen& q ) {
        return (x == q.x) //行冲突
            || (y == q.y) //列冲突
            || (x + y == q.x + q.y) // 正对角线冲突
            || (x - y == q.x - q.y); // 反对角线冲突
    } 
    bool operator!=(const Queen& q) {return !(*this == q;)}
};
void placeQueens(int N) { //棋盘大小 == 皇后总数
    Stack<Queen> solu; //存放解的栈
    Queen q(0,0); //起点
    do { //不断进行试探
        if( N <= solu.size() || N <= q.y) {
            q = solu.pop(); q.y ++; // 回溯一行,并继续试探下一列
        } else { //否则,试探下一行
            while((q.y < N ) && (0 <= solu.find(q)))
            { q.y++; nCheck++; }
            if(N > q.y) {
                solu.push(q);
                if(N <= solu.size()) nSolu++;
                q.x++; q.y= 0;
            }
        }

    }while( (0<qx) || (q.y < N));

}
```
    