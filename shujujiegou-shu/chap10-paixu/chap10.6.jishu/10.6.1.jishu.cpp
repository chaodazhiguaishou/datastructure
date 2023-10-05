#include <iostream>
#include <stdio.h>
#include "2.3.1.linklist.cpp"
using namespace std;

//1.排序思路（使用最低位优先排序）
// 假设线性表由元素序列a0、a1、…、an-1构成，每个结点aj的关键字由d元组
// 其中每个元素值在0到r-1之间。排序中使用r个队列Q0，Q1，…，Qr-1。
// 对i=0、1、…，d-1（从低位到高位），依次做一次“分配”和“收集”：
// 分配：开始时，把Q0、Q1、…、Qr-1各个队列置成空队列，然后依次考察线性表中的每一个元素aj（j=1、2、…、n），
// 如果aj的关键字位   =k，就把aj插入到Qk队列中。
// 收集：将Q0、Q1、…、Qr-1各个队列中的元素依次首尾相接，得到新的元素序列，从而组成新的线性表。

//简单来说就是对于n进制，每次只看一位排序，以此类推

//2.排序算法

//由于在分配和收集中涉及大量元素移动，采用顺序表时效率较低，所以采用单链表存放排序序列，
//这里采用以h为首结点的单链表（不带头结点）
//利用第2章单链表类LinkList<T>类模板存放单链表
template <typename T>
struct LinkNode			//单链表结点类型
{  T data;				//存放数据元素
   LinkNode<T>* next;			//指向下一个结点的域
   LinkNode():next(NULL) {}		//构造函数 
   LinkNode(T d):data(d),next(NULL) {} //重载构造函数 
};

//假设元素关键字均为十进制（r=10）正整数，最大位数为d，按递增排序的最低位优先基数排序算法如下：
int geti(int key,int r,int i)	  //求基数为r的正整数key的第i位
{  int k=0;
   for (int j=0;j<=i;j++)
   {  k=key%r;
      key=key/r;
   }
   return k;
}

#define MAXR 100
void RadixSort1(LinkList<int> &L, int d, int r)
// 最低位优先基数排序算法
{
   LinkNode<int> *front[MAXR]; // 建立链队队头数组
   LinkNode<int> *rear[MAXR];  // 建立链队队尾数组
   LinkNode<int> *p, *t;
   for (int i = 0; i < d; i++) // 从低位到高位循环
   {
      for (int j = 0; j < r; j++) // 初始化各链队首、尾指针
          front[j] = rear[j] = NULL;
      p = L.head->next;
      while (p != NULL) // 分配：对于原链表中每个结点循环
      {
          int k = geti(p->data, r, i); // 提取关键字第k个位并放入第k个链队
          if (front[k] == NULL)        // 第k个链队空时，队头队尾均指向p结点
          {
              front[k] = p;
              rear[k] = p;
          }
          else // 第k个链队非空时，p结点进队
          {
              rear[k]->next = p;
              rear[k] = p;
          }
          p = p->next; // 取下一个待排序的结点
      }
      LinkNode<int> *h = NULL;    // 重新用h来收集所有结点
      for (int j = 0; j < r; j++) // 收集：对于每一个链队循环
          if (front[j] != NULL)   // 若第j个链队是第一个非空链队
          {
              if (h == NULL)
              {
                  h = front[j];
                  t = rear[j];
              }
              else // 若第j个链队是其他非空链队
              {
                  t->next = front[j];
                  t = rear[j];
              }
          }
      t->next = NULL; // 尾结点的next域置NULL
      L.head->next = h;
   }
}

int main() {
    // insert code here...
};

//3.算法分析
//基数排序的时间复杂度为O(d(n+r))
// 基数排序的空间复杂度为O(r)

// 例如( 369，367，167，239，237，138，230，139)  基数排序
// 进行第1次分配：按个位
// 进行第1次收集：230,367,167,237,138,369,239,139
// 进行第2次分配：按拾位
// 进行第2次收集：230,237,138,239,139,367,167,369
// 进行第3次分配：按百位
// 进行第3次收集：138,139,167,230,237,239,367,369
