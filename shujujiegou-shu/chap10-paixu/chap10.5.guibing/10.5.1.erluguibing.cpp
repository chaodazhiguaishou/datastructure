#include <iostream>
#include <stdio.h>
using namespace std;

//自底向上的二路归并排序

//1.排序思路
// 两两归并形成归并树，平衡归并
// 有清晰的趟数（同一趟产生的归并段优先归并）
// 归并树高度h=log2n+1
// 归并的趟数=h-1

//2.排序算法
//（1）将两个位置相邻的有序子序列归并为一个有序序列。
//将R[low..mid]和R[mid+1..high]两个有序段归并为一个有序段R[low..high]
void Merge(vector<int>& R,int low,int mid,int high)
{  vector<int> R1;
   R1.resize(high-low+1);	    //设置R1的长度为high-low+1
   int i=low,j=mid+1,k=0;	    //k是R1的下标,i、j分别为第1、2段的下标
   while (i<=mid && j<=high)	    //在第1段和第2段均未扫描完时循环
   {  if (R[i]<=R[j])		    //将第1段中的元素放入R1中
      {  R1[k]=R[i];
         i++; k++;
      }
      else			    //将第2段中的元素放入R1中
      {  R1[k]=R[j];
         j++; k++; 
      }
   }
   while (i<=mid)		    //将第1段余下部分复制到R1
   {  R1[k]=R[i];
      i++; k++;
   }
   while (j<=high)		    //将第2段余下部分复制到R1
   {  R1[k]=R[j];
      j++; k++;
   }
   for (k=0,i=low;i<=high;k++,i++) //将R1复制回R中
      R[i]=R1[k];
}

//（2）进行一趟二路归并
void MergePass(vector<int>& R,int length)	//对整个数序进行一趟归并
{  int n=R.size(),i;
   for (i=0;i+2*length-1<n;i+=2*length) //归并length长的两相邻子表
       Merge(R,i,i+length-1,i+2*length-1);
   if (i+length<n)			//余下两个子表,后者长度小于length
       Merge(R,i,i+length-1,n-1);	//归并这两个子表
}

//（3）二路归并排序
void MergeSort1(vector<int>& R,int n) 	//自底向上的二路归并排序
{  for (int length=1;length<n;length=2*length) //进行log2n趟归并
     MergePass(R,length);
}


int main() {
    // insert code here...
};

//3.算法分析
// 二路归并排序中，长度为n的排序表需做log2n趟，对应的归并树高度为log2n，每趟归并时间为O(n)。
// 时间复杂度的最好、最坏和平均情况都是O(nlog2n)。
// 归并排序过程中每次调用Merge都需要使用局部数组R1，但执行完后其空间被释放，
// 但最后一趟排序一定是全部n个元素参与归并，所以总的辅助空间复杂度为O(n)。


//扩展：二路归并可以推广为多路归并
// 三路归并的归并树的高度为log3n，同样一次三路归并的时间为O(n)，所以三路归并排序的时间复杂度为O(nlog3n)。
// 而nlog3n=nlog2n/log23，即O(nlog3n)=O(nlog2n)，也就是说，三路归并排序与二路归并排序的时间复杂度相同。
