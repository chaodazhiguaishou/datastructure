#include <iostream>
#include <stdio.h>
using namespace std;

// 1.排序思路
// d=n/2
// 将排序序列分为d个组，在各组内进行直接插入排序
// 递减d=d/2，重复② ，直到d=0为止

//2.排序算法
void ShellSort(vector<int>& R,int n) 	//希尔排序
{  int d=n/2;				//增量置初值
   while (d>0)              //int是舍尾法
   {  for (int i=d;i<n;i++)		//相隔d位置的元素组直接插入排序
      {  if (R[i]<R[i-d])		//反序时
         {  int tmp=R[i];
            int j=i-d;
            do
            {  R[j+d]=R[j];		//将大于tmp的元素同组中后移
               j=j-d;			//继续向前比较
            } while (j>=0 && R[j]>tmp);
            R[j+d]=tmp;		//在j+d处插入R[i]
         }
      }
      d=d/2;				//减小增量
   }
}


int main() {
    // insert code here...
};

// 3. 算法分析
// d1=n/2，di+1=di/2（i≥1），也就是说，每趟后一个增量是前一个增量的1/2，则经过t=log2n-1趟后dt=1，
// 再经过一趟最后直接插入排序使整数数序变为有序的。
// 希尔算法的时间复杂度难以分析，一般认为其平均时间复杂度为O(n1.58)。希尔排序的速度通常要比直接插入排序快。


// 希尔排序是一种不稳定的排序算法
// 一般地，相距位置较大的两个元素发生交换 会导致 不稳定！
