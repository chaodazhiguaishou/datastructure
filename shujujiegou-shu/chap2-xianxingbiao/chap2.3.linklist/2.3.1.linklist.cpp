#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

// 插入结点操作：将结点s插入到单链表中p结点的后面。
// s->next=p->next;
// p->next=s;

// 删除结点操作：删除单链表中p结点的后继结点。
// q=p->next;		//q指向被删结点
// p->next=q->next;	//从单链表中删除结点q
// delete q;		//释放空间!!!!!!!!!!!

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

void CreateListF(T a[],int n)			//头插法建立单链表,链表顺序是和数组相反
{  for (int i=0;i<n;i++)			//循环建立数据结点
   {  LinkNode<T>*  s=new LinkNode<T>(a[i]);//创建数据结点s
      s->next=head->next;			//将结点s插入head结点之后 
      head->next=s;
   }
}

void CreateListR(T a[],int n)		//尾插法建立单链表,需要一个尾指针。链表顺序是和数组相同
{  LinkNode<T>* s,*r;
   r=head;				//r指向尾结点,开始时指向头结点
   for (int i=0;i<n;i++)		//循环建立数据结点
   {  s=new LinkNode<T>(a[i]);	//创建数据结点s
      r->next=s;			//将结点s插入结点r之后
      r=s;
   }
   r->next=NULL;			//将尾结点的next域置为NULL！！单链表尾节点指向null！！！
}

LinkList() 		//构造函数,创建一个空单链表
{
   head=new LinkNode<T>();
}

~LinkList() 			//析构函数,销毁单链表
{  LinkNode<T>* pre,*p;
   pre=head;p=pre->next;
   while (p!=NULL)		//用p遍历结点并释放其前驱结点 
   {  delete pre;		//释放pre结点 
      pre=p; p=p->next;	//pre,p同步后移一个结点 
   }
   delete pre;			//p为空时pre指向尾结点,此时释放尾结点
}

void Add(T e)			//在单链表末尾添加一个值为e的结点 
{  LinkNode<T>* s=new LinkNode<T>(e);	//新建结点s
   LinkNode<T>* p=head;
   while (p->next!=NULL)			//查找尾结点p
      p=p->next;
   p->next=s;					//在尾结点之后插入结点s
}

int Getlength()			//求单链表中数据结点个数
{  LinkNode<T>* p=head;
   int cnt=0;
   while (p->next!=NULL)		//找到尾结点为止
   {  cnt++;
      p=p->next;
   }
   return cnt;
}
//若像顺序表中一样，在单链表中设置一个长度length，插入时length++，删除时length--。
//那么求长度的时间复杂度为O(1)了。

LinkNode<T>* geti(int i)		//返回序号i的结点（链表序号从0-n）
{  if (i<-1) return NULL;		//i<-1返回NULL
   LinkNode<T>* p=head;		//首先p指向头结点
   int j=-1;				//j置为-1(可以认为头结点序号为-1)
   while (j<i && p!=NULL)		//指针p移动i+1个结点
   {  j++;
      p=p->next;
   }
   if (i == j){return p;}////返回p
   else{return NULL;}
}

bool GetElem(int i,T& e)		//求单链表中序号i的结点值
{  if (i<0) return false;		//参数i错误返回false
   LinkNode<T>* p=geti(i);		//查找序号i的结点
   if (p!=NULL)			//找到了序号i的结点p
   {  e=p->data;
      return true;			//成功找到返回true 
   }
   else					//不存在序号i的结点
      return false;			//参数i错误返回false 
}

bool SetElem(int i,T e)		//设置序号i的结点值
{  if (i<0) return false;		//参数i错误返回false
   LinkNode<T>* p=geti(i);		//查找序号i的结点
   if (p!=NULL)			//找到了序号i的结点p 
   {  p->data=e;
      return true;
   }
   else					//不存在序号i的结点
      return false;			//参数i错误返回false
}

int GetNo(T e)				//查找第一个为e的元素的序号
{  int j=0;				//j置为0，p指向首结点
   LinkNode<T>* p=head->next;
   while (p!=NULL && p->data!=e)	//查找第一个值为e的结点p
   {  j++;	
      p=p->next;
   }
   if (p==NULL) return -1;		//未找到时返回-1
   else return j;			//找到后返回其序号
}

bool Insert(int i,T e)		//在序号i位置插入值为e的结点
{  if (i<0) return false; 		//参数i错误返回false
   LinkNode<T>* s=new LinkNode<T>(e);//建立新结点s
   LinkNode<T>* p=geti(i-1);		//查找序号i-1的结点
   if (p!=NULL)			//找到了序号i-1的结点p 
   {  s->next=p->next;		//在p结点后面插入s结点
      p->next=s;
      return true;			//插入成功返回true 
   }
   else					//没有找到序号i-1的结点 
      return false;			//参数i错误返回false
}

bool Delete(int i)		  //在单链表中删除序号i位置的结点
{  if (i<0) return false; 	  //参数i错误返回false
   LinkNode<T>* p=geti(i-1);	  //查找序号i-1的结点
   if (p!=NULL)		  //找到了序号i-1的结点p 
   {  LinkNode<T>* q=p->next;	  //q指向序号i的结点(被删结点) 
      if (q!=NULL)		  //存在序号i的结点时删除它 
      {  p->next=q->next;	  //删除p结点的后继结点
         delete q;		  //释放空间 
         return true;		  //删除成功返回true 
      }
      else			  //没有找到序号i的结点
         return false;	  //参数i错误返回false
   }
   else				  //没有找到序号i-1的结点 
      return false;		  //参数i错误返回false
}

void DispList()			//输出单链表所有结点值
{  LinkNode<T>* p;
   p=head->next;			//p指向开始结点
   while (p!=NULL)			//p不为NULL,输出p结点的data域
   {  cout << p->data << " ";
      p=p->next;			//p移向下一个结点
   }
   cout << endl;
}

};


int testout() {
    LinkNode<int>* a;
    a->data = 3;
    LinkNode<int>* b = new LinkNode<int>(3);
    
    cout<<a->data<<endl;
    printf("%d\n",a->data);
    //printf(a->data); 这样写是不行的，printf使用格式为printf("格式化字符串",输出表列)
    cout<<b->data<<endl;
    
    return 0;
};
