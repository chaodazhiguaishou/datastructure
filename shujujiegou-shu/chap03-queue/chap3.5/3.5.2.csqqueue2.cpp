#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

// 【例3.12】对于循环队列来说，如果知道队头指针和队列中元素个数，则可以计算出队尾指针。
// 也就是说，可以用队列中元素个数代替队尾指针。
// 设计出这种循环队列的判队空、进队、出队和取队头元素的算法。

//count=(rear-front+MaxSize)%MaxSize
//rear=(front+count)%MaxSize
// front=(rear-count+MaxSize)%MaxSize

//本例设计的循环队列中最多可保存MaxSize个元素。


const int MaxSize=100;		//队列的容量 
template <typename T>
class CSqQueue1			//循环队队列类模板
{
public:
   T* data;  				//存放队中元素
   int front;				//队头指针
   int count;				//队中元素个数
   CSqQueue1()				//构造函数
   {  data=new T[MaxSize];		//为data分配容量为MaxSize的空间
      front=0;				//队头指针置初值
      count=0;				//元素个数置初值
   }
   ~CSqQueue1()			//析构函数
   {
      delete [] data;
   }
//----------循环队基本运算算法-----------------
bool empty()				//判队空运算 
{
   return count==0; 
}
bool push(T e)				//进队列运算
{  if (count==MaxSize)		//队满上溢出
     return false;
   int rear1=(front+count)%MaxSize;	//求队尾（rear1为局部变量）,使用局部变量假装有rear
   rear1=(rear1+1) % MaxSize;		//队尾循环进1
   data[rear1]=e; 
   count++;				//元素个数增1
   return true;
}
   bool pop(T& e)			//出队列运算
   {  if (count==0)			//队空下溢出
         return false;		
      front=(front+1)%MaxSize;
      e=data[front];
      count--;				//元素个数减少1 
      return true;
   }
   bool gethead(T& e)			//取队头运算
   {  if (count==0)			//队空下溢出
         return false;
      int head=(front+1)%MaxSize;
      e=data[head];
      return true;
   }
};


int main() {

};