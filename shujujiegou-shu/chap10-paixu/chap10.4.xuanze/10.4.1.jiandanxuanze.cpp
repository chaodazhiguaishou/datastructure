#include <iostream>
#include <stdio.h>
using namespace std;

//1.排序思路
//从一个无序区中选出最小的元素，最简单方法是逐个进行元素比较，例如，从无序区R[i..n-1]中选出最小元素R[minj]。


//2.排序算法
void SelectSort(vector<int>& R,int n)	//简单选择排序
{  for (int i=0;i<n-1;i++)	//做第i趟排序
   {  int minj=i;
      for (int j=i+1;j<n;j++)	//在当前无序区R[i..n-1]中选最小元素R[minj]
         if (R[j]<R[minj])
            minj=j;		//minj记下目前找到的最小元素的位置
      if (minj!=i)		//若R[minj]不是无序区首元素，如果是说明不用交换直接归入有序区就行
         swap(R[i],R[minj]);	//交换R[i]和R[minj]
   }
}


int main() {
    // insert code here...
};

//3.算法分析
//  无论初始数据序列的状态如何，在第i趟排序从无序区R[i..n-1]（含n-i个元素）中选出最小元素时，
//  内for循环需做n-i-1次比较，因此，总的比较次数为，O(n2)
// 元素的移动次数
// 当初始数据序列正序时，移动次数为0。
// 反序时每趟排序均要执行交换操作，此时总的移动次数为最大值3(n-1)。
// 最好、最坏和平均情况的时间复杂度均为O(n2)。

// 是一种不稳定的排序方法
