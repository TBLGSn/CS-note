# 题目:
    统计一个数字在排序数组中出现的次数。

# 示例:
    >输入: nums = [5,7,7,8,8,10], target = 8
    >输出: 2

# 思路
    二分查找
# 解答:
```c++
class Solution {
private:
    // 找到>=target的左边界，就是满足 nums[i] >= target里的i的最小值
     int BinaryLeft(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()  - 1;
        while (lo <= hi)
        {
           
            int mid  = lo  + ((hi -  lo) >> 1);
            
            if (nums[mid] < target){
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }

public:
    int search(vector<int>& nums, int target) {
       
        return BinaryLeft(nums, target+1) - BinaryLeft(nums, target);
    }
};
```
# 标准答案
```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return count(nums.begin(), nums.end(), target);
    }
};
```
# 总结
   - 库函数就能实现
   - >> 运算符 比 '+'优先级低 