#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

//循环双链表！注意头插法和尾插法不仅要注意尾节点->next指向dhead，也要注意dhead->prior指向尾节点

//【例2.18】有一个带头结点的循环双链表L，其结点data成员值为整数，
//设计一个算法，判断其所有元素是否对称。
//如果从前向后读和从后向前读得到的数据序列相同，表示是对称的；
//否则不是对称的。

template <typename T>
struct DLinkNode				//双链表结点类型
{  T data;					//存放数据元素
   DLinkNode<T>* next;			//指向后继结点的指针
   DLinkNode<T>* prior;			//指向前驱结点的指针
   DLinkNode():next(NULL),prior(NULL) {}		  //构造函数
   DLinkNode(T d):data(d),next(NULL),prior(NULL) {}  //重载构造函数
};

template <typename T>
class CDLinkList		  //循环双链表类模板
{
public:
   DLinkNode<T>* dhead;	  //循环双链表头结点

CDLinkList() 		  //构造函数,创建空表
{  
    dhead=new DLinkNode<T>();
    dhead->next=dhead;	  //构成循环的空链表
    dhead->prior=dhead; 
}

~CDLinkList() 	  	  //析构函数,销毁
{  
    DLinkNode<T>* pre,*p;
    pre=dhead;p=pre->next;
    while (p!=dhead)	  	  //p遍历并释放前驱结点 
    {  
        delete pre;	         //释放pre结点 
        pre=p;p=p->next;	  //pre,p同步后移一个结点 
    }
    delete pre;		  //此时释放尾结点
}

//基本运算算法
void CreateListF(T a[],int n)		//头插法建立双链表
{  
    DLinkNode<T>* s;
    for (int i=0;i<n;i++)		//循环建立数据结点
    {  
        s=new DLinkNode<T>(a[i]);	//创建数据结点s
        s->next=dhead->next;		//修改s结点的next成员
        if (dhead->next!=dhead)		//修改头结点的非空后继结点的prior。
            dhead->next->prior=s;
        if(dhead->next==dhead)
            dhead->prior = s;
        dhead->next=s;			//修改头结点的next
        s->prior=dhead;			//修改s结点的prior
    }
}

void CreateListR(T a[],int n)
{
    DLinkNode<T>* s;
    DLinkNode<T>* pre=dhead;
    for (int i=0;i<n;i++)
    {
        s = new DLinkNode<T>(a[i]);
        s->prior = pre;
        pre->next = s;
        pre = s;
    }
    pre->next=dhead;
    dhead->prior=pre;
}

void DispList(){
    DLinkNode<T> *p=dhead->next;
    while (p!=dhead)
    {
        cout<<p->data<<"";
        p=p->next;
    }
    cout<<endl;
}


};

template <typename T>
class Solution
{
public:

bool Symm(CDLinkList<T>& L)		//求解算法
{  bool flag=true;			//flag表示L是否对称，初始时为真
   DLinkNode<T>* p=L.dhead->next;	//p指向首结点
   DLinkNode<T>* q=L.dhead->prior;	//q指向尾结点
   while (flag)
   {  if (p->data!=q->data)		//对应结点值不相同，置flag为假
         flag=false;
      else
      {  if (p==q || p==q->prior)	//满足结束条件退出循环
            break;
         q=q->prior;			//q前移一个结点
         p=p->next;			//p后移一个结点
      }
   }
   return flag;
}


};

int main() {
    // insert code here...
    CDLinkList<int> a;
    int aa[] = {1,2,3,2,1};
    a.CreateListF(aa,5);
    a.DispList();
    Solution<int> s;
    cout<<s.Symm(a)<<endl;

};


