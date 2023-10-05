#include <iostream>
#include <stdio.h>
using namespace std;

//1. 排序思路
// 初始时，有序区只有一个元素R[0]
// i＝1~n-1，共经过n-1趟排序
// 一趟直接插入排序：在有序区中插入R[i]的过程。


void InsertSort(vector<int>& R,int n) 	//直接插入排序
{  for (int i=1;i<n;i++)			//从R[1]开始
   {  if (R[i]<R[i-1])			//反序时
      {  int tmp=R[i];			//取出无序区的第一个元素
         int j=i-1;		//有序区R[0..i-1]中向前找R[i]的插入位置
         do
         {  R[j+1]=R[j];			//将大于tmp的元素后移
            j--;				//继续向前比较
         } while (j>=0 && R[j]>tmp);
         R[j+1]=tmp;				//在j+1处插入R[i]
      }
   }
}

// 【算法扩展】在排序中通常利用“<”比较实现递增排序，可以自定义比较函数cmp(x,y)，
// 如x<y时，该函数返回true，否则返回false，这样将上述算法中R[j]<=tmp转换为!tmp<R[j]即!cmp(tmp，R[j])，

bool cmp(int x,int y)	   //实现递增排序的自定义比较函数
{  if (x<y) return true;
   else return false;
}
void InsertSort2(vector<int>& R,int n) 	//直接插入排序（递增）
{  for (int i=1;i<n;i++)			//从R[1]开始
   {  if (cmp(R[i],R[i-1]))			//反序时
      {  int tmp=R[i];			//取出无序区的第一个元素
         int j=i-1;		//有序区R[0..i-1]中向前找插入位置
         do
         {  R[j+1]=R[j];			//将大于tmp的元素后移
            j--;				//继续向前比较
         } while (j>=0 && !cmp(R[j],tmp));
         R[j+1]=tmp;				//在j+1处插入R[i]
      }
   }
}

bool cmpdown(int x,int y)	  //实现递减排序的自定义比较函数
{  if (x>y) return true;
   else return false;
}
// InsertSort算法不变即可递减排序R
// 后面讨论的各种排序算法都可以这样转换为递减排序或者按定制的方式排序


int main() {
    // insert code here...
};

// 3.算法分析
// 1）最好情况分析
// 初始数据序列正序，最好情况下的时间复杂度为O(n)。
// 2）最坏情况分析
// 初始数据序列反序，最坏情况下的时间复杂度为O(n2)。
// 3）平均情况分析
// 将R[i]插入到R[0..i-1]（含i个元素）的中间位置，平均情况的时间复杂度为O(n2)。
