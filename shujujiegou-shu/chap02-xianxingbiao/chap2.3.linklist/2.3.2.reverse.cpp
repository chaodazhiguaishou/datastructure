#include <iostream>
#include <stdio.h>
#include "2.3.1.linklist.cpp"
using namespace std;

//有一个整数单链表L，设计一个算法逆置L中的所有结点。例如L=(1，2，3，4，5)，逆置后L=(5，4，3，2，1)。

template <typename T>
class Solution
{
public:

void Reverse1(LinkList<T>& L)		//求解算法1,利用头插法
{  LinkNode<T>* p=L.head->next,*q;	//p指向首结点
   L.head->next=NULL;			//将L置为一个空表
   while (p!=NULL)			//用p遍历所有数据结点
   {  q=p->next;			//q临时保存p结点的后继结点
      p->next=L.head->next;		//将p结点插入到表头
      L.head->next=p;
      p=q;
   }
}

void Reverse2(LinkList<T>& L)
{
    //LinkNode<T>* p,q,k;//这样子会报错！！！每个都是指针
    LinkNode<T> *p,*q,*k;
    p=nullptr;q=L.head->next;
    while (q!=nullptr)
    {
        k=q->next;
        q->next=p;
        p=q;
        q=k;
    }
    L.head->next=p;
}

};

int main() {
    LinkList<int> a,b;
    Solution<int> s;
    int aa[]={1,2,3,4,5};
    int bb[]={1,2,3,4,5};
    a.CreateListR(aa,5);
    b.CreateListR(bb,5);
    a.DispList();
    b.DispList();
    s.Reverse1(a);
    s.Reverse2(b);
    a.DispList();
    b.DispList();
    return 0;
};