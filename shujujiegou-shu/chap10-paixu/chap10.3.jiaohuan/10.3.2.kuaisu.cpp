#include <iostream>
#include <stdio.h>
using namespace std;

//1.排序思路
//每趟使表的第1个元素放入适当位置（归位），将表一分为二，对子表按递归方式继续这种划分，
//直至划分的子表长为0或1（递归出口）。

//快速排序过程 就是生成递归树的过程


//2.排序算法

int Partition3(vector<int>& R,int s,int t)//划分算法
{

}

void _QuickSort(vector<int>& R,int s,int t)  //对R[s..t]快速排序
{  if (s<t)				//表中至少存在两个元素的情况
   {  int i=Partition3(R,s,t);	//可用3种划分算法任意一种
      _QuickSort(R,s,i-1);		//对左子表递归排序
      _QuickSort(R,i+1,t);		//对右子表递归排序
   }
}

void QuickSort(vector<int>& R,int n)	 //快速排序
{
   _QuickSort(R,0,n-1);
}


int main() {
    // insert code here...
};

//3.算法分析
//1）最好情况分析：如果初始数据序列随机分布，使得每次划分恰好分为两个长度相同的子表，此时递归树的高度最小，性能最好。
//最好情况下的时间复杂度为O(nlog2n)。
//2）最坏情况分析：如果初始数据序列正序或者反序，使得每次划分的两个子表中一个为空一个长度为n-1，
//此时递归树的高度最高，性能最差。最坏情况下的时间复杂度为O(n的二次方)。
//3）平均情况分析：平均情况的时间复杂度为O(nlog2n)。


