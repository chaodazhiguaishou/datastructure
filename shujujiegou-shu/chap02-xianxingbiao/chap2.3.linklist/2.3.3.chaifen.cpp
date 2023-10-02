#include <iostream>
#include <stdio.h>
#include "2.3.1.linklist.cpp"
using namespace std;

//有一个含2n个整数的单链表L=（a0，b0，a1，b1，…，an-1，bn-1），设计一个算法将其拆分成两个带头结点的单链表A和B。
//   其中A=（a0，a1，…，an-1），B=（bn-1，bn-2，…，b0）。


//头插法建表
// s->next=head->next;
// head->next=s;

//尾插法建表
//  r=head;				//r指向尾结点,开始时指向头结点
//    for (int i=0;i<n;i++)		//循环建立数据结点
//    {  s=new LinkNode<T>(a[i]);	//创建数据结点s
//       r->next=s;			//将结点s插入结点r之后
//       r=s;
//    }
//    r->next=NULL;			//将尾结点的next域置为NULL


template <typename T>
class Solution
{
public:
void chaifen(LinkList<T>& l,LinkList<T>& a,LinkList<T>& b)
{
    LinkNode<T> *k,*p,*q;
    k = l.head->next; //标记表l的节点
    p =a.head; //a的尾插法的尾节点
    q = b.head; //b的头插法的头节点
    while (k != nullptr) //尾插法插a
    {
        LinkNode<T>* u = k->next;//暂存
        p->next = k;
        k->next = nullptr; //直接处理尾节点指向
        p=p->next;
        k=u;//分配完k回到表l
        if (k!=nullptr) //头插法插b
        {
            u = k->next; //暂存
            k->next = q->next;
            q->next = k;
            k = u; //处理完回到表l
        }
    };
}    

void Split(LinkList<T>& L,LinkList<T>& A,LinkList<T>& B)
//答案的方法，答案的方法不同在答案最后处理a的尾节点指向null
{  LinkNode<T>* p=L.head->next,*q;	//p指向L的首结点
   LinkNode<T>* r=A.head;		//r始终指向A的尾结点
   while (p!=NULL)			
   {  r->next=p;
      r=p;				//尾插法建立A
      p=p->next;			
      if (p!=NULL)
      {  q=p->next;			//临时保存p结点的后继结点
         p->next=B.head->next;	//头插法建立B
         B.head->next=p;
         p=q;				//p指向q结点
      }
   }
   r->next=NULL;			//尾结点next置空
}


};

int main(int argc, const char * argv[]) {
    // insert code here...
    LinkList<int> l,a,b;
    int ll[]={1,2,3,4,5,6};
    l.CreateListR(ll,6);
    l.DispList();

    Solution<int> s;
    s.chaifen(l,a,b);
    a.DispList();
    b.DispList();
    return 0;
};