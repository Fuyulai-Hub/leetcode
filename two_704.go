//leetcode 704题二分法查找
func search(nums []int, target int) int {
    r:=len(nums)-1
    l:=0
    for l<=r{
        m:=l+(r-l)/2
        if target==nums[m]{
            return m
        }
        if nums[m]<target{
           l++//r++是谁想出来的，在这里写直接超出界了
        }else{
            r--
        }  
    }
  return -1//仔细审题
}
