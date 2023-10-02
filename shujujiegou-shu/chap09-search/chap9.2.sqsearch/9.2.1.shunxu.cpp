#include <iostream>
#include <stdio.h>
using namespace std;

//顺序查找思路
// 从顺序表的一端开始依次遍历，将遍历的元素关键字和给定值k相比较：
// 若两者相等，则查找成功，返回该元素的序号。
// 若遍历结束后，仍未找到关键字等于k的元素，则查找失败，返回-1。
// 默认从顺序表的前端开始遍历。


class Solution
{
public:
int SeqSearch1(vector<int>& R,int k)	//顺序查找算法1，是简单比较方法
{  int n=R.size();
   int i=0;
   while (i<n && R[i]!=k)
      i++;				//从表头往后找
   if (i>=n) return -1;		//未找到返回-1
   else return i;			//找到后返回其序号i
}

int SeqSearch2(vector<int>& R,int k)	//顺序查找算法2，在末尾设置一个哨兵
{  int n=R.size();
   R.push_back(k);			//末尾添加一个哨兵
   int i=0;
   while (R[i]!=k) i++;		//从表头往后找
   if (i==n) return -1;		//未找到返回-1
   else return i;			//找到后返回其序号i
}

//由于查找算法主要考虑关键字之间的比较，两个算法的效率差不多

};

int main() {
    // insert code here...
};