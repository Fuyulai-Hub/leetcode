func lengthOfLongestSubstring(s string) int {
    //思路，双指针加map来做，从前往后进行遍历，并将值存到map中，如果有重复就就进行跳过，没有重复的就加1，然后跟新最大值
    m:=make(map[string]int)
    left:=0 
    right:=0
    maxlen:=0
    for right=0;right<len(s);right++{
        c:=string(s[right])
        if index,ok:=m[c];ok&&index>=left{//这里index大于等于left是窗口可以正常移动，例如abba
            left=index+1
        }
        m[c]=right
        // if(right-left+1>maxlen){
        //     maxlen=right-left+1
        // }    
        maxlen=max(maxlen,right-left+1)
    }
    return maxlen
}
