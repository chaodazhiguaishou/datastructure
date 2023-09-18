#include <iostream>
#include <stdio.h>
#include "2.2.1.sqlist.cpp"
using namespace std;

// 二路归并。有两个按元素值递增有序的整数顺序表A和B，
// 设计一个算法将顺序表A和B的全部元素合并到一个递增有序顺序表C中。并给出算法的时间复杂度和空间复杂度。

template <typename T> //模板要不然写在类前面，要不然类里面带t的都要写模板
class Solution
{
public:

//二路归并自己写，即
void erluguibing(SqList<T> &a, SqList<T> &b, SqList<T> &c)
{
    int lengtha = a.length;
    int lengthb = b.length;
    c.recap(a.capacity + b.capacity);
    int i = 0, j = 0;
    while (i < lengtha && j < lengthb)
    {
        if (a.data[i] < b.data[j])
        {
            c.Add(a.data[i]);
            i++;
        }
        else if (a.data[i] > b.data[j])
        {
            c.Add(b.data[j]);
            j++;
        }
        else if (a.data[i] == b.data[j])
        {
            c.Add(a.data[i]);
            i++;
            j++;
        }
    }
    while (i == lengtha && j < lengthb)
    {
        c.Add(b.data[j]);
        j++;
    }

    while (i < lengtha && j == lengthb)
    {
        c.Add(a.data[i]);
        i++;
    }
}

void Merge2(SqList<T> A,SqList<T> B,SqList<T>& C)
{  int i=0,j=0;			//i用于遍历A,j用于遍历B
   while (i<A.length && j<B.length)  //两个表均没有遍历完毕
   {  if (A.data[i]<B.data[j])
      {  C.Add(A.data[i]);		//归并A[i]:将较小的A[i]添加到C中
         i++; 
      }
      else				//归并B[j]:将较小的B[j]添加到C中
      {  C.Add(B.data[j]);
         j++;
      }
   }
   while (i<A.length)			//若A没有遍历完毕
   {  C.Add(A.data[i]);		//归并A中剩余元素 
      i++;
   }
   while (j<B.length)			//若B没有遍历完毕
   {  C.Add(B.data[j]);		//归并B中剩余元素
      j++;
   }
}

};

int main()
{
    SqList<int> a, b, c;
    int aa[] = {1, 2, 3};
    int bb[] = {4, 5, 6};
    a.CreateList(aa, 3);
    b.CreateList(bb, 3);
    a.DispList();
    b.DispList();
    Solution<int> s;
    s.erluguibing(a, b, c);
    c.DispList();
    return 0;
};