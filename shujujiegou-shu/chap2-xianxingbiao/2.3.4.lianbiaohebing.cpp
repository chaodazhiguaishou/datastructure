#include <iostream>
#include <stdio.h>
#include "2.3.1.linklist.cpp"
using namespace std;

// 有两个递增有序整数单链表A和B，
//设计一个算法采用二路归并方法将A和B的所有数据结点合并到递增有序单链表C中。
// 要求算法的空间复杂度为O(1)。

//因为是链表，未归并完的的结果可以快速直接插入！！！不需要再循环了！！

template <typename T>
class Solution
{
public:
void hebing(LinkList<T>& a,LinkList<T>& b,LinkList<T>& c)
{
    LinkNode<T> *p,*q,*t;
    p = a.head->next;
    q = b.head->next;
    t = c.head;
    while (p!=nullptr && q!=nullptr)
    {
        if (p->data<q->data) //a小
        {
            t->next = p;
            t = t->next;
            p = p->next;
        }
        else if (p->data>q->data) //b小
        {
            t->next = q;
            t = t->next;
            q = q->next;
        }
        else if (p->data==q->data) //a，b一样大
        {
            t->next = p;
            t = t->next;
            p = p->next;
            q = q->next;
        }
    }
    while (p==nullptr && q!=nullptr) //b有剩余
    {
        t->next = q;
        t = t->next;
        q = q->next;
    }
    while (p!=nullptr && q==nullptr) //a有剩余
    {
        t->next = p;
        t = t->next;
        p = p->next;
    }
    //因为是链表，未归并完的的结果可以快速直接插入！！！不需要再循环了！！
    t->next = nullptr;
}

//答案方法，看答案是如何快速处理未归并完的节点的
void Merge2(LinkList<T>& A,LinkList<T>& B,LinkList<T>& C)
{  LinkNode<T>* p=A.head->next;	
   LinkNode<T>* q=B.head->next;	
   LinkNode<T>* r=C.head;		
   while (p!=NULL && q!=NULL)		//两个单链表都没有遍历完
   {  if (p->data<q->data)		//将较小结点p链接到C的末尾
      {  r->next=p;
         r=p;
         p=p->next;
      }
      else				//将较小结点q链接到C的末尾
      {  r->next=q;
         r=q;
         q=q->next;
      }
   }
   r->next=NULL;			//尾结点next置空
   if (p!=NULL) r->next=p;		//将未归并完的结点链接到C的末尾
   if (q!=NULL) r->next=q;
    //因为是链表，未归并完的的结果可以快速直接插入！！！不需要再循环了！！
}



};

int main(int argc, const char * argv[]) {
    // insert code here...
    LinkList<int> a,b,c;
    int aa[]={1,2,5};
    int bb[]={3,4,6};
    a.CreateListR(aa,3);
    b.CreateListR(bb,3);
    a.DispList();
    b.DispList();

    Solution<int> s;
    s.hebing(a,b,c);
    c.DispList();
    return 0;
};