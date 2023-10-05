#include <iostream>
#include <stdio.h>
#include "10.5.1.erluguibing.cpp"
using namespace std;

//自顶向下的二路归并排序

//1.排序思路
// 排序区间是R[s..t]（为大问题），当其长度为0或者1时，本身就是有序的，不做任何处理。
// 否则，其中间位置m，采用相同方法对R[s..m]和R[m+1..t]排好序（分解为两个小问题），
// 再调用前面的二路归并算法Merge(s，m，t)得到整个有序表（合并）。


//2.排序算法
void MergeSort2(vector<int>& R,int n)  //自顶向下的二路归并排序
{
   _MergeSort2(R,0,n-1);
}

void _MergeSort2(vector<int>& R,int s,int t) //被MergeSort2调用
{  if (s>=t) return;			//R[s..t]的长度为0或者1时返回
   int m=(s+t)/2;			//取中间位置m
   _MergeSort2(R,s,m);		//对前子表排序
   _MergeSort2(R,m+1,t);		//对后子表排序
   Merge(R,s,m,t);			//将两个有序子表合并成一个有序表
}

int main() {
    // insert code here...
};

//3.算法分析