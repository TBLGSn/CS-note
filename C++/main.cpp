#include <algorithm>
#include <deque>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
// 找到最小的连续字符串使得长度为  n - k
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        int n = nums.size();
        int len = n -k; // 当前区间的长度
        if( len <= 0)  return total;
        int sum = 0; // 当前区间的总和
        for(int i = 0; i < len; ++i) {
            sum += nums[i];
        }
        int min_sum = sum;
        int left = 0; 
        for(int i = len; i < n; ++i) {
            sum += nums[i];
            sum -= nums[left];
            min_sum = min(min_sum, sum);
            left ++;
        }
        return total - min_sum;
    }
};