#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

//【例6.6】假设有一个不带头结点的单链表p，完成以下两个算法设计：
// （1）设计一个算法正向输出所有结点值。
// （2）设计一个算法反向输出所有结点值。


template <typename T>
struct LinkNode				//单链表结点类型
{  T data;					//存放数据元素
   LinkNode<T>* next;				//下一个结点的指针
   LinkNode():next(NULL) {}			//构造函数
   LinkNode(T d):data(d),next(NULL) {}	//重载构造函数
};

template <typename T>
class LinkList			//单链表类模板
{
public:
LinkNode<T>* head;		//单链表头结点

void Positive(LinkNode<int>* p)	//正向输出所有结点值
{  if (p==NULL)
     return;
   else
   {  printf("%d ",p->data); //先执行后递归，回溯后是正向的
      Positive(p->next);
   }
}

void Invert(LinkNode<int>* p) 	//反向输出所有结点值
{  if (p==NULL)
      return;
   else
   {  Invert(p->next);      //先递归再执行，回溯后是反向的
      printf("%d ",p->data);
   }
}



void CreateListR(T a[],int n)		//尾插法建立单链表,需要一个尾指针。链表顺序是和数组相同
{  LinkNode<T>* s,*r;
   r=head;				
   for (int i=0;i<n;i++)		
   {  s=new LinkNode<T>(a[i]);	
      r->next=s;			
      r=s;
   }
   r->next=NULL;			
}

LinkList() 		//构造函数,创建一个空单链表
{
   head=new LinkNode<T>();
}

};

int main() {
    // insert code here...
    int tx,ty;
    unsigned ux=-1,uy=1;
    cout<<ux<<endl<<uy<<endl;
    tx = (int)ux;
    uy = (unsigned)ty;
    
};