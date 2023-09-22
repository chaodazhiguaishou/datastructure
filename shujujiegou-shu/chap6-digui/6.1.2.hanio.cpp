#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

//
// 汉诺塔问题的关键在于
// 每次n个圆盘想从x到z，需要经历n-1个圆盘从x移动到y，
// 然后1个圆盘从x移动到z
// 然后n-1个圆盘从y移动到z
// 而这样的每次移动也可以用一开始的函数

void Hanoi(int n,char x,char y,char z)   	//Hanoi递归算法
{  if (n==1)					//只有一个盘片的情况
      printf("将第%d个盘片从%c移动到%c\n",n,x,z);
   else						//有两个或多个盘片的情况
   {  Hanoi(n-1,x,z,y);
      printf("将第%d个盘片从%c移动到%c\n",n,x,z);
      Hanoi(n-1,y,x,z);
   }
}

int main() {
    // insert code here...
    char A,B,C;
    Hanoi(3,'A','B','C');
    // Hanoi(3,A,B,C); //char属性要加单引号
    return 0;    
};


// 递归模型是递归算法的抽象，它反映一个递归问题的递归结构。
// int fun(int n)
// {  if (n==1)			//语句1
//       return 1;		//语句2
//    else				//语句3
//       return fun(n-1)*n;	//语句4
// }
// 一般地，一个递归模型是由递归出口和递归体两部分组成。
// 递归出口确定递归到何时结束，即指出明确的递归结束条件。
// 递归体确定递归求解时的递推关系。


// 为了保证递归函数的正确执行，系统需设立一个工作栈。采用工作栈实现递归调用和返回。
// int S(int n)
// {  if (n<=0) return 0;
//    else return S(n-1)+n;
// }
// int main()
// {  print("%d\n",S(1));
//    return 0;
// }
//  程序执行时使用一个栈来保存调用过程的信息，这些信息用main()、S(0)和S(1)表示，
//  那么自栈底到栈顶保存的信息的顺序是怎么样呢？
// 1.调用main()，进入栈
// 2.调用S(1)，进入栈
// 3.调用S(0)，进入栈
// 4.从S(0)返回，出栈
// 5.从S(1)返回，出栈
// 6.从main()返回，出栈
