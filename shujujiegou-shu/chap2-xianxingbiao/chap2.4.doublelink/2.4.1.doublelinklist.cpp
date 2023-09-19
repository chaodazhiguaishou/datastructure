#include <iostream>
#include <stdio.h>
using namespace std;

// 双链表插入结点操作：将结点s插入到双链表中p结点的后面。
// s->next=p->next;
// if (p->next!=NULL) //需要判断后续为空！
//   p->next->prior=s;
// p->next=s;
// s->prior=p

// 双链表删除结点操作：删除双链表中的p结点。
// p->next->prior=p->prior
// p->prior->next=p->next
// delete p;		//释放空间!!!!!!!!!!!

template <typename T>
struct DLinkNode				//双链表结点类型
{  T data;					//存放数据元素
   DLinkNode<T>* next;			//指向后继结点的指针
   DLinkNode<T>* prior;			//指向前驱结点的指针
   DLinkNode():next(NULL),prior(NULL) {}		  //构造函数
   DLinkNode(T d):data(d),next(NULL),prior(NULL) {}  //重载构造函数
};


template <typename T>
class DLinkList			//双链表类模板
{
public:
DLinkNode<T>* dhead;		//双链表头结点

void CreateListF(T a[],int n)		//头插法建立双链表
{  DLinkNode<T>* s;
   for (int i=0;i<n;i++)		//循环建立数据结点
   {  s=new DLinkNode<T>(a[i]);	//创建数据结点s
      s->next=dhead->next;		//修改s结点的next成员
      if (dhead->next!=NULL)		//修改头结点的非空后继结点的prior。需要为非空！！！
         dhead->next->prior=s;
      dhead->next=s;			//修改头结点的next
      s->prior=dhead;			//修改s结点的prior
   }
}

void CreateListR(T a[],int n)		//尾插法建立双链表
{  DLinkNode<T> *s,*r;
   r=dhead;				//r始终指向尾结点,开始时指向头结点
   for (int i=0;i<n;i++)		//循环建立数据结点
   {  s=new DLinkNode<T>(a[i]);	//创建数据结点s
      s->prior=r;
      r->next=s;			//将s结点插入r结点之后
      r=s;
   }
   r->next=NULL;			//将尾结点的next域置为NULL
}

DLinkNode<T>* geti(int i)		//返回序号i的结点（链表序号从0-n）
{  if (i<-1) return NULL;		//i<-1返回NULL
   DLinkNode<T>* p=dhead;		//首先p指向头结点
   int j=-1;				//j置为-1(可以认为头结点序号为-1)
   while (j<i && p!=NULL)		//指针p移动i+1个结点
   {  j++;
      p=p->next;
   }
   if (i == j){return p;}////返回p
   else{return NULL;}
}

bool Insert(int i,T e)	//在双链表中序号i位置插入值为e的结点
{  if (i<0) return false; 		//参数i错误返回false
   DLinkNode<T>* s=new DLinkNode<T>(e);//建立新结点s
   DLinkNode<T>* p=geti(i-1);		//查找序号i-1的结点p
   if (p!=NULL)			//找到了序号i-1的结点 
   {  s->next=p->next;		//修改s结点的next域
      if (p->next!=NULL)		//修改p结点的非空后继结点的prior
         p->next->prior=s;
      p->next=s;			//修改p结点的next域
      s->prior=p;			//修改s结点的prior域
      return true;			//插入成功返回true
   }
   else return false;			//没有找到序号i-1的结点返回false
}

bool Delete(int i)			//在双链表中删除序号i位置的结点
{  if (i<0) return false; 		//参数i错误返回false
   DLinkNode<T>* p=geti(i);		//查找序号i的结点
   if (p!=NULL)			//找到了序号i的结点p 
   {  p->prior->next=p->next;		//修改p结点的前驱结点的next
      if (p->next!=NULL)		//修改p结点非空后继结点的prior
         p->next->prior=p->prior;
      delete p;			//释放空间 
      return true;			//删除成功返回true 
   }
   else return false;			//没有找到序号i-1的结点返回false
}

void DispList(){
    DLinkNode<T> *p=dhead->next;
    while (p!=nullptr)
    {
        cout<<p->data<<"";
        p=p->next;
    }
    cout<<endl;
}

};


int testout() {

    
    return 0;
};
