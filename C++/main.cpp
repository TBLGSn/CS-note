#include <algorithm>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
/*
*   0. 暴力法 ， 但未使用 有序这个条件
*   1. a[0] + b[0] < a[1] + b[0], 利用有序这个条件，提前终止
*   2. 实例三: 表明不能直接依靠 k 进行循环结束条件的判定
*   3. a[0] + b[0]一定是最小的
*/

class Solution {
    typedef pair<int, int> value_type;
    struct cmp{
        bool  operator()(value_type a, value_type b) {
            return a.first + a.second < b.first + b.second;
        } 
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       
        vector<vector<int>> res;
        
        priority_queue<value_type, vector<value_type, cmp> > pq;
        
        for( const int a : nums1) {
            for(const int b : nums2) {
                pq.push({a, b});
            }
        }
        k = min<int>( nums1.size() * nums2.size(), k);
        while( k --) {
            value_type tmp = pq.top();
            res.push_back({tmp.first, tmp.second});
            pq.pop();
        }
        return res;
    }
};
