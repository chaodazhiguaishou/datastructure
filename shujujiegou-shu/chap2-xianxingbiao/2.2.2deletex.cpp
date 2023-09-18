#include <iostream>
#include <stdio.h>
#include "2.2.1.sqlist.cpp"

// 对于含有n个整数元素的顺序表L，设计一个算法用于删除其中所有值为x的元素。
// 例如L=(1，2，1，5，1)，若x=1，删除后L=(2，5)。并给出算法的时间复杂度和空间复杂度。


using namespace std;

class Solution
{
public:

template <typename T>
void Deletex0(SqList<T>& L,int x) //直接删除也是一种方法，但是用了delete函数
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == x)
        {
            L.Delete(i);
            i--; //删除完得回退一位，i++后继续检测
        }    
    }
};

template <typename T>
void Deletex1(SqList<T>& L, int x)	//求解算法1，两个标记顺序插入不为x的
{  int k=0;
   for (int i=0;i<L.length;i++)
      if (L.data[i]!=x)		//将不为x的元素插入到data中
      {  L.data[k]=L.data[i];
         k++;
      }
    L.length=k;			//重置L的长度为k
};

template <typename T>
void Deletex2(SqList<T>& L, int x)	//求解算法2前移法
{  int k=0;				//累计等于x的元素个数
   for (int i=0;i<L.length;i++)
      if (L.data[i]!=x)		//将不为x的元素前移k个位置
         L.data[i-k]=L.data[i];
      else				//累计删除的元素个数k
         k++;
   L.length-=k;			//将L的长度减少k
};

};

int main(int argc, const char * argv[]) {
    // insert code here...
    SqList<int> L;
    L.Add(0);
    L.Add(1);
    L.Add(2);
    L.Add(0);
    L.Add(0);
    L.Add(3);
    L.DispList();
    Solution s;
    s.Deletex0(L,0);
    L.DispList();
    return 0;
};