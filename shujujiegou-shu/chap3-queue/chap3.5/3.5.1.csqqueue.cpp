#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

//把data数组的前端和后端连接起来，形成一个循环数组，
//即把存储队列元素的表从逻辑上看成一个环，称为循环队列（也称为环形队列）。

//在代码上的区别大概就每次修改front和rear都要&maxsize
//并且在出现（...-...)/maxsize的时候括号里面要多加一个maxsize修正负数情况

//规定队列中最多只有m-1个元素
// 队空条件：rear==front。
// 队满条件：(rear+1)%MaxSize==front（相当于试探进队一次，若rear达到front，则认为队满了）。
// 元素e进队：rear=(rear+1)%MaxSize，将元素e放置在该位置。
// 元素出队：front=(front+1)%MaxSize，取出该位置的元素。


const int MaxSize=100;		//队列的容量 
template <typename T>
class CSqQueue				//循环队队列类模板
{
public:
   T* data;  				//存放队中元素
   int front, rear;			//队头和队尾指针
   //队列的基本运算算法

CSqQueue()			//构造函数
{  
    data=new T[MaxSize];	//为data分配容量为MaxSize的空间
    front=rear=0;		//队头队尾指针置初值
}

~CSqQueue()			//析构函数
{
   delete [] data;
}

bool empty()		//判队空运算 
{
   return (front==rear); 
}

bool push(T e)				//进队列运算
{  if ((rear+1)%MaxSize==front)	//队满上溢出
      return false;
   rear=(rear+1)%MaxSize;
   data[rear]=e;
   return true;
}

bool pop(T& e)			//出队列运算
{  if (front==rear)		//队空下溢出
      return false;
   front=(front+1)%MaxSize;
   e=data[front];
   return true;
}

bool gethead(T& e)		//取队头运算
{  if (front==rear)		//队空下溢出
      return false;
   int head=(front+1)%MaxSize;
   e=data[head];
   return true;
}


//【例3.11】在CSqQueue循环队列类中增加一个求元素个数的算法getlength()。
//对于一个整数循环队列qu，利用队列基本运算和getlength()算法
//设计进队和出队第k（k≥1，队头元素的序号为1）个元素的算法。
//进队第k个指的是再k位置加入某个元素
int getlength()		//返回队中元素个数
{
   return (rear-front+MaxSize)%MaxSize; //因为循环了所以可能有负的！
}

//因为要根据题意利用以上运算，所以采取遍历处理。
//其实也可以直接对data数组进行修改
bool pushk(CSqQueue<int>& qu,int k,int e) //进队第k个元素e
{  int x;
   int n=qu.getlength();
   if (k<1 || k>n+1)
      return false;			//参数k错误返回False
   if (k<=n)
   {  for (int i=1;i<=n;i++)		//循环处理队中所有元素
      {  if (i==k)
            qu.push(e);		//将e元素进队到第k个位置
         qu.pop(x);			//出队元素x
         qu.push(x);			//进队元素x
      }
   }
   else	qu.push(e);			//k=n+1时直接进队e
   return true;
}

bool popk(CSqQueue<int>& qu,int k,int& e)	//出队第k个元素
{  int x;
   int n=qu.getlength();
   if (k<=1 || k>n) return false;	//参数k错误返回false 
   for (int i=1;i<=n;i++)		//循环处理队中所有元素
   {  qu.pop(x);			//出队元素x
      if (i!=k)
         qu.push(x);			//将非第k个元素进队
      else
         e=x;				//取第k个出队的元素
   }
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