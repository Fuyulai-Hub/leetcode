/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
    if root==nil {return true}
    return check(root.Left,root.Right)
}
func check(a,b*TreeNode) bool{
    if a==nil&&b==nil {return true}
    if a==nil||b==nil {return false}
    if a.Val!=b.Val {return false}
    return check(a.Left,b.Right)&&check(a.Right,b.Left)
}
