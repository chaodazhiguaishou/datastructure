#include <iostream>
#include <stdio.h>
using namespace std;

//1.排序思路
//将无序区中最小元素放在有序区R[i]


//2.排序算法
//在冒泡排序算法，若某一趟没有出现任何元素交换，说明所有元素已排好序了，就可以结束本算法。
//因为一边交换一边j--，所以如果是初始递减排序，执行冒泡排序就相当于把最后最小的一下下移到最前面

void BubbleSort(vector<int>& R,int n) 	//冒泡排序
{  for (int i=0;i<n-1;i++) 
   {  bool exchange=false;		//本趟前将exchange置为false
      for (int j=n-1;j>i;j--)		//在无序区找出最小元素
          if (R[j]<R[j-1])		//反序时交换
          {  swap(R[j],R[j-1]);
             exchange=true;		//本趟发生交换置exchange为true
          }
      if (!exchange)			//本趟没有发生交换，中途结束算法
         return;
   }
}


int main() {
    // insert code here...
};

// 3.算法分析
// 1）最好情况分析：初始数据序列正序，最好情况下的时间复杂度为O(n)。
// 2）最坏情况分析：初始数据序列反序，最坏情况下的时间复杂度为O(n的二次方)。
// 3）平均情况分析：算法可能在中间的某一趟排序完成后就结束，但平均的排序趟数仍是O(n)。
// 每一趟的关键字比较次数和元素移动次数为O(n)，所以平均时间复杂度为O(n2)。平均情况的时间复杂度为O(n的二次方)。





