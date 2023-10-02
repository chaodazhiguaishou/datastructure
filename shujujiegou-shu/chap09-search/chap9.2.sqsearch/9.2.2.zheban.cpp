#include <iostream>
#include <stdio.h>
using namespace std;

//1.折半查找算法
//基本思路：
// 查找表R[0..n-1]为递增有序顺序表
// R[low..high]是当前的非空查找区间（下界为low，上界为high），中点位置mid=[(low+high)/2]
//（或者mid=(low+high)>>1），k值与R[mid]比较：
// 若k=R[mid]，则查找成功并返回该元素的序号mid。
// 若k<R[mid]，则在左子表R[low..mid-1]中查找，即下界不变，上界改为mid-1。
// 若k>R[mid]，则在右子表R[mid+1..high]中查找，即下界改为mid+1，上界不变。
// 下一次查找是针对非空新查找区间进行的，其过程与上述过程类似。若新查找区间为空，表示查找失败，返回-1。

//对于这种多重复性操作的算法，可以使用多个“指针“指示位置或者使用递归

class Solution
{
public:
int BinSearch1(vector<int>& R,int k)	//拆半查找非递归算法
{  int n=R.size();
   int low=0,high=n-1;
   while (low<=high)			//当前区间非空时
   {  int mid=(low+high)/2;		//求查找区间的中间位置
      if (k==R[mid])			//查找成功返回其序号mid
         return mid;
      if (k<R[mid])			//继续在R[low..mid-1]中查找
         high=mid-1;
      else				//k>R[mid]
         low=mid+1;			//继续在R[mid+1..high]中查找
   }
   return -1;				//当前查找区间空时返回-1
}


int BinSearch2(vector<int>& R,int k)		//拆半查找递归算法
{
   return BinSearch21(R,0,R.size()-1,k);
}

int BinSearch21(vector<int>& R,int low,int high,int k)
//被BinSearch2方法调用
{  if (low<=high)			//当前查找区间非空时
   {  int mid=(low+high)/2;		//求查找区间的中间位置
      if (k==R[mid])			//查找成功返回其序号mid
         return mid;
      if (k<R[mid])			//递归在左区间中查找
         return BinSearch21(R,low,mid-1,k);
      else				//k>R[mid],递归在右区间中查找
         return BinSearch21(R,mid+1,high,k);
   }
   else return -1;			//当前查找区间空时返回-1
}

};

int main() {
    // insert code here...
};


// 2. 折半查找算法分析
// 借助一棵二叉判定树很容易求得折半查找的平均查找长度。
// 为讨论方便起见，不妨设内部结点的总数为n=2h-1，这样的判定树是高度为h=log2(n+1)的满二叉树（高度h不计外部结点）。
// 该满二叉树中第j（1≤j≤h）层上的结点个数为2j-1，查找该层上的每个结点需要进行j次比较。
// 因此，在等概率假设下，折半查找成功情况下的平均查找长度为：ASL成功=[(n+1)/n]log2(n+1)

// 从成功和不成功情况下的平均查找长度看出，折半查找的时间复杂度为O(log2n)，是一种高效的查找算法。

// 结论：
// 当n不等于2h-1时，其折半查找判定树不一定为满二叉树，但可以证明n个结点的判定树的高度与n个结点的完全二叉树的高度相等，
// 即h为log2(n+1)或者log2n+1。
// 查找成功时关键字比较次数最多为判定树的高度h。
// 查找不成功时关键字比较次数最多也为判定树的高度h。

// 3. STL中的折半查找算法
// 对于以数组为低层结构的有序表（如数组、vector或者deque容器等），STL中提供了一系列以折半查找为基础的快速查找通用算法：
// binary_search(beg，end，x，[comp])在[beg，end)范围内查找x，如果找到则返回true，否则返回false。
// 其中comp是与排序一致的比较函数，省略时使用底层类型的小于运算符。
// lower_bound(beg，end，x，[comp])在[beg，end)范围内查找第一个大于等于x的元素地址。
// 其中comp是与排序一致的比较函数，省略时使用底层类型的小于运算符。
// upper_bound(beg，end，x，[comp])在[beg，end)范围内查找第一个大于x的元素地址，即插入点位置。
// 其中comp是与排序一致的比较函数，省略时使用底层类型的小于运算符。
// equal_range(beg，end，x，[comp])返回一对地址，第一个即first为lower_bound的结果，
// 第二个second为upper_bound的结果。其中comp是与排序一致的比较函数，省略时使用底层类型的小于运算符。
