#include <iostream>
#include <stdio.h>
using namespace std;

//

template <typename T>
struct LinkNode				//链栈结点类型
{  T data;					//数据域
   LinkNode* next;				//指针域
   LinkNode():next(NULL) {} 			//构造函数
   LinkNode(T d):data(d),next(NULL) {} 	//重载构造函数
};

template <typename T>
class LinkStack		//链栈类模板
{
public:
   LinkNode<T>* head;		//链栈头结点

LinkStack()		//构造函数
{	
   head=new LinkNode<T>();
}

~LinkStack()		//析构函数
{  LinkNode<T>* pre=head,*p=pre->next;
   while (p!=NULL)
   {  delete pre;
      pre=p; p=p->next;	//pre、p同步后移
   }
   delete pre;
}

bool empty()    		//判断栈是否为空
{
    return head->next==NULL;
}

bool push(T e)					//进栈算法
{  LinkNode<T>* p=new LinkNode<T>(e);	//新建结点p
   p->next=head->next;			//插入结点p作为首结点,头插法处理
   head->next=p;
   return true;
}

bool pop(T& e)				//出栈算法
{  LinkNode<T>* p;
   if (head->next==NULL)		//栈空的情况
      return false;
   p=head->next;			//p指向开始结点
   e=p->data;
   head->next=p->next;		//删除结点p
   delete p;				//释放结点p
   return true;
}

bool gettop(T& e)			//取栈顶元素
{  LinkNode<T>* p;
   if (head->next==NULL)		//栈空的情况
      return false;
   p=head->next;			//p指向开始结点
   e=p->data;
   return true;
}


};


int main() {
    // insert code here...
    string exp="2+3";
    char ch1=exp[0];
    char ch2=exp[1];
    char ch3=exp[2];
    cout<<exp[0]<<exp[1]<<exp[2]<<endl;
    cout<<ch1<<ch2<<ch3<<endl;
    return 0;
};