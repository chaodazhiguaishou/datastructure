#include <iostream>
#include <stdio.h>
#include "2.3.1.linklist.cpp"
using namespace std;

//【例2.12】有两个递增有序整数单链表A和B，假设每个单链表中没有值相同的结点，但两个单链表中存在相同值的结点，
//设计一个尽可能高效的算法建立一个新的递增有序整数单链表C，其中包含A和B相同值的结点，
//要求算法执行后不改变单链表A和B。

//因为不能改变链表，显然遇到相同的是要新建节点的
//对两个链表比大小，用两个指针分别遍历，哪边小了就下一位继续比较

template <typename T>
class Solution
{
public:
void Commnodes(LinkList<T>& A,LinkList<T>& B,LinkList<T>& C)
{  LinkNode<T>* p=A.head->next;		//p指向A的首结点
   LinkNode<T>* q=B.head->next;		//q指向B的首结点
   LinkNode<T>* r=C.head;			//r为C的尾结点
   while (p!=NULL && q!=NULL)			//两个单链表都没有遍历完
   {  if (p->data<q->data)			//跳过较小的p结点
         p=p->next;
      else if (q->data<p->data)		//跳过较小的q结点
         q=q->next;
      else					//p结点和q结点值相同
      {  LinkNode<T>* s=new LinkNode<T>(p->data);
         r->next=s;
         r=s;					//将s结点链接到C的末尾
         p=p->next;
         q=q->next;
      }
   }
   r->next=NULL;				//尾结点next置空！务必记得尾插法要处理尾节点
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