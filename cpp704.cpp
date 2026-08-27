class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r=size(nums)-1;
        int l=0;
        while(l<=r){
            int m=(r+l)/2;
            if(nums[m]==target) return m;
            if(nums[m]>target){
               r=m-1;
            }else{
                l=m+1;//l++;//之前的写法退化成了线性扫描，复杂度成On，不是正常的二分法，现在是需要正常的二分法，复杂度是Ologn
            }
        }
        return -1;
    }
};
/* 核心原理：为什么是 O(log n)？
二分查找每次循环都会将搜索区间缩小为原来的一半，而不是减少固定数量。

循环次数	搜索区间大小
第 1 次	n
第 2 次	n/2
第 3 次	n/4
第 4 次	n/8
...	...
第 k 次	n / 2^(k-1)
当搜索区间缩小到 1 时，循环结束，所以：

n / 2^(k-1) = 1
n = 2^(k-1)
k = log₂(n) + 1
所以时间复杂度为 O(log n)。
*/
