#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;

//
// 成员函数	说明
// empty()	判断双端队列容器是否为空队
// size()	返回双端队列容器中元素个数
// front()	返回队头元素
// back()	返回队尾元素
// push_front(e)	在队头插入元素e
// push_back(e)	在队尾插入元素e
// pop_front()	删除队头元素
// pop_back()	删除队尾元素
// erase()	从双端队列容器中删除一个或几个元素
// clear()	删除双端队列容器中所有元素
// 迭代器成员函数
// begin()	该函数两个版本返回iterator或const_iterator，引用容器首元素
// end()	该函数两个版本返回iterator或const_iterator，引用容器尾元素的后一个位置
// rbegin()	该函数两个版本返回reverse_iterator或const_reverse_iterator，引用容器尾元素
// rend()	该函数两个版本返回reverse_iterator或const_reverse_iterator，引用容器首元素的前一个位置


int disp(deque<int>& dq)		//输出dq的所有元素
{  deque<int>::iterator iter;		//定义迭代器iter
   for (iter=dq.begin();iter!=dq.end();iter++)
      printf("%d ",*iter);
   printf("\n");
}
int main()
{  deque<int> dq;			//建立一个双端队列dq
   dq.push_front(1);			//队头插入1
   dq.push_back(2);			//队尾插入2
   dq.push_front(3);			//队头插入3
   dq.push_back(4);			//队尾插入4
   printf("dq: "); disp(dq);
   dq.pop_front();			//删除队头元素
   dq.pop_back();			//删除队尾元素
   printf("dq: "); disp(dq);
   return 0;
}


//用双端队列可以实现栈
//以前端作为栈底（前端保持不动），后端作为栈顶（后端动态变化），使用成员函数push_back()，pop_back()和back()。
// 以后端作为栈底（后端保持不动），前端作为栈顶（前端动态变化，使用成员函数push_front()，pop_front()和front()。
// 实际上链表容器list也可以这样作为栈

// 用双端队列实现普通队列
// 以前端作为队头，后端作为队尾，使用成员函数push_back()，pop_front()和front()。
// 以后端作为队头，前端作为队尾，使用成员函数push_front()，pop_back()和back()。
// 实际上链表容器list也可以这样作为普通队列
