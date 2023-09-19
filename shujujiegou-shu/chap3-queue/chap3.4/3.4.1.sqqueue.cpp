#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

//初始时置front和rear均为-1（front==rear），该顺序队的四要素如下：
// 队空条件：front==rear。
// 队满（上溢出）条件：rear==MaxSize-1（因为每个元素进队都让rear增1，当rear到达最大下标时不能再增加。
// 元素e进队操作：rear增1，将元素e放在该位置（进队的元素总是在尾部插入的）。
// 出队操作：front增1，取出该位置的元素（出队的元素总是在队头出来的）。

const int MaxSize=100;		//队列的容量
template <typename T>
class SqQueue				//非循环队队列类模板
{
public:
   T* data;  				//存放队中元素
   int front, rear;			//队头和队尾指针
   //队列的基本运算算法
SqQueue()			//构造函数
{  
    data=new T[MaxSize];	//为data分配容量为MaxSize的空间
    front=rear=-1;		//队头队尾指针置初值
}

~SqQueue()			//析构函数
{
   delete [] data;
}

bool empty()		//判队空运算 
{
   return (front==rear); 
}

bool push(T e)				//进队列运算
{  if (rear==MaxSize-1)		//队满上溢出
      return false;
   rear++;
   data[rear]=e;
   return true;
}

bool pop(T& e)			//出队列运算
{  if (front==rear)		//队空下溢出
      return false;
   front++;
   e=data[front];
   return true;
}

bool gethead(T& e)		//取队头运算
{  if (front==rear)		//队空下溢出
      return false;
   int head=front+1;
   e=data[head];
   return true;
}


};


int main() {
    // insert code here...

};