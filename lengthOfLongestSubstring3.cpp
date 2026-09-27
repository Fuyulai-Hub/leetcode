class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int left=0,right=0,maxlen=0;
        for(int right=0;right<s.size();right++){
            char c=s[right];
            //写法一
            // if(m.count(c)&&m[c]>=left){//count方法：
            //     left=m[c]+1;
            // }
            //写法二：
            if(m.find(c)!=m.end()&&m[c]>=left){
                left=m[c]+1;
            }
            m[c]=right;
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};
// m.count(c) 判断 key 是否存在于 map 中：
// 存在 → 返回 1
// 不存在 → 返回 0
