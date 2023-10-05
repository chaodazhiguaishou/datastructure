#include <iostream>
#include <stdio.h>
using namespace std;

//1. 排序思路
//查找采用折半查找方法，称为二分插入排序或折半插入排序。

//2. 排序算法
void BinInsertSort(vector<int>& R,int n) 	//折半插入排序
{  for (int i=1;i<n;i++)			//从R[1]开始
   {  if (R[i]<R[i-1])			//反序时
      {  int tmp=R[i];			//将R[i]保存到tmp中
         int low=0,high=i-1;
         while (low<=high)		   //折半查找tmp的插入点high+1
         {  int mid=(low+high)/2;		//取中间位置
            if (tmp<R[mid])
               high=mid-1;			//插入点在左半区
            else
               low=mid+1;			//插入点在右半区
         }
         for (int j=i-1;j>=high+1;j--)	//元素后移
            R[j+1]=R[j];
         R[high+1]=tmp;			//原R[i]插入到R[high+1]中 
      }	
   }
}


int main() {
    // insert code here...
};

//3.算法分析
//在任何情况下排序中元素移动的次数与直接插入排序的相同，不同的仅是变分散移动为集中移动。
//平均情况的时间复杂度为O(n2)。
