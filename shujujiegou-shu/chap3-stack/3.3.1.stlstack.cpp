#include<iostream>
#include <stack>
using namespace std;

// stack容器主要的成员函数
// 成员函数	说明
// empty()	判断栈是否为空
// size()	返回栈中的实际元素个数
// push(e)	即元素e进栈
// top()	返回栈顶元素，当栈空时抛出异常
// pop()	出栈一个元素，并不返回出栈的元素，当栈空时抛出异常

int main()
{  stack<int> st;
   st.push(1); st.push(2); st.push(3);
   printf("栈顶元素: %d\n",st.top());
   printf("出栈顺序: ");
   while (!st.empty()) 		//栈不空时出栈所有元素
   {  printf("%d ",st.top());
      st.pop() ;
   }
   printf("\n");
   return 0;
}
