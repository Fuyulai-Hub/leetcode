package main

import "fmt"
type ListNode struct{
    val int //Val大写，公开，表示可以被其他包访问到；小写表示私有，仅当前包内访问
    next *ListNode
}
func main(){
 dummy:=&ListNode{}
    tail:=dummy
    for i:=1;i<=5;i++{
        tail.next=&ListNode{val:i}
        tail=tail.next
    }
    // head:=dummy.next
    left,right:=2,4
    pre:=dummy
    
    for i:=0;i<left-1;i++{
        pre=pre.next
    }
    cur:=pre.next
    for i:=0;i<right-left;i++{
        //1，2，3，4，5（2到4这一段进行反转）
        next:=cur.next//将需要反转的起始节点的下一个节点先保存起来
        cur.next=next.next//跳过需要反转的初始节点的下一个节点，相当于将需反转初始的节点的下一个节点的拿出来，让它没有前置节点执指向它，但是这个节点仍然是指向下一个节点的
        next.next=pre.next//将next节点的指向pre的下一个节点就是反转的初始节点，因为改动的指向，原来next指向4的指针就被覆盖掉了
        pre.next=next//改动pre的指向，将pre指向next节点，原来指向cur的指针就被覆盖掉了
    }
    for p:=dummy.next;p!=nil;p=p.next{
        fmt.Printf("%d",p.val)
        if(p.next!=nil){
            fmt.Printf("->")
        }
    }
}
