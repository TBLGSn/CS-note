# 二分查找

    对于二分查找而言，其时间复杂度为 $lg_n$.

    其重要特征常体现为：“有序”，“有最大值与最小值”.

    “有序”： 题目不可能直接告诉你，有序这个条件，常常是隐藏起来的。
    例如告诉你“最大值与最小值”不就相当于告诉你有序吗？(最大值与最小值之间的数都可能为目标值)

    与“最小值和最大值”这个条件一起使用，常可根据额外的条件判定出：大于
    (或小于)当前元素的值不可能为目标值。←  这是二分查找的核心思想。


# 参考代码 
```c++
    template <typename T> 
    Rank binSearch(T* A, Rank lo, Rank hi, T e) {
        while(lo < hi) {
            Rank mid =(lo + hi) >>1;
            if(e < A[mid]) hi = mid;
            else if(A[mid] < e) lo = mid +1;
            else return mid; 
        }
        return -1; //没找到
    }
```

# 解题思想
剑指 Offer 53-I.在排序数组中查找元素I ，分别利用二分查找找到区间第一个和最后一个元素完成解题