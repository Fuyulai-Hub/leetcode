func twoSum(nums []int, target int) []int {
    var m map[int]int
    m=make(map[int]int)
    for i:=0;i<len(nums);i++{
        ans:=target-nums[i];
        if p,ok:=m[ans];ok{
            return []int{p,i}
        }
        m[nums[i]]=i
    }
    return nil
}
