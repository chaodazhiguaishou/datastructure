#include <iostream>
#include <stdio.h>
#include "2.5.1.clinklist.cpp"
using namespace std;

//编写一个程序求解约瑟夫（Joseph）问题。
//有n个小孩围成一圈，给他们从1开始依次编号，从编号为1的小孩开始报数，数到第m（0<m<n）个小孩出列，
//然后从出列的下一个小孩重新开始报数，数到第m个小孩又出列，…，如此反复直到所有的小孩全部出列为止，求整个出列序列。
//如当n=6，m=5时的出列序列是5，4，6，2，3，1。

struct Child				//小孩结点类型
{  int no;				//小孩编号
   Child* next;			//下一个结点指针
   Child(int d):no(d),next(NULL) {}	//构造函数
};


class Joseph				//求解约瑟夫问题类
{  int n,m;
   Child* first;			//小孩循环单链表的首结点
public:	
   Joseph(int n1,int m1):n(n1),m(m1) {}	//构造函数

   void CreateList()			//创建小孩循环单链表
   {  first=new Child(1);		//循环单链表首结点
      Child* r=first,*p;		//r为尾结点指针
      for (int i=2;i<=n;i++)
      {  p=new Child(i);		//建立一个编号为i的新结点p
         r->next=p;			//将p结点链到末尾
         r=p;
      }
      r->next=first;			//构成首结点为first的循环单链表
   }
   
   void Jsequence()		//输出约瑟夫序列
   {  Child* p,*q; 
      for (int i=1;i<=n;i++)	//共出列n个小孩
      {  p=first;
         int j=1;
         while (j!=m)		//从first结点开始报数，报到第m个结点
         {  j++;			//报数递增
            p=p->next;		//移到下一个结点
         }
         cout << p->no << " ";	//该结点的小孩出列
         q=p->next;			//q指向结点p的后继结点
         p->no=q->no;			//将结点q的值复制到结点p
         p->next=q->next;		//删除q结点
         delete q;			//释放结点空间
         first=p;			//从结点p重新开始
      }
      cout << endl;
   }
};

int main()
{  int n=6,m=3;
   Joseph L(n,m);
   cout << "n=" << n << "，m=" << m << "的约瑟夫序列:" << endl;
   L.CreateList();
   L.Jsequence();
   return 0;
}
