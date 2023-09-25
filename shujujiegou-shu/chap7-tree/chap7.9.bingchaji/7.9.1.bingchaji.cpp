#include <iostream>
#include <stdio.h>
// #include "../chap7.2.erchatree/7.2.2.linktree.cpp"
using namespace std;

//子树高度越小越好
//在一棵高度较低的树中查找根结点的编号（即该集合的代表）所花的时间较少，如何保证构造的分离集合树较低呢？
// 两棵分离集合树A和B高度相同时：任意一个根作为另外一个根的孩子 -> 合并树的高度增加1，hC=MAX{hA，hB}+1。
// 两棵分离集合树A和B高度不相同时：将较低的根作为较高的根的孩子 -> 合并树的高度不增加，hC=MAX{hA，hB}。

const int MAXN = 10;

int parent[MAXN];		//并查集存储结构
int rnk[MAXN];			//存储结点的秩(近似于高度)

class Solution
{
public:
void Init()		//并查集初始化 时间复杂度为O(n)。
{  
    int n = MAXN;
    for (int i=1;i<=n;i++)
    {  parent[i]=i;
        rnk[i]=0;
    }
}

int Find1(int x)		 //递归算法：并查集中查找x结点的根结点,时间复杂度为O(log2n)。
{  
    if (x!=parent[x])
        parent[x]=Find1(parent[x]); //路径压缩
    return parent[x];
}

int Find2(int x)		//非递归算法：并查集中查找x结点的根结点
{  
    int rx=x;
    while (parent[rx]!=rx)	//找到x的根rx
        rx=parent[rx];
    int y=x;
    while (y!=rx)		//路径压缩
    {  int tmp=parent[y];
        parent[y]=rx;
        y=tmp;
    }
    return rx;			//返回根
}

void Union(int x,int y)	//并查集中x和y的两个集合的合并
{  int rx=Find1(x);
   int ry=Find1(y);
   if (rx==ry)			//x和y属于同一棵树的情况
      return;
   if (rnk[rx]<rnk[ry])
      parent[rx]=ry;		//rx结点作为ry的孩子
   else
   {  if (rnk[rx]==rnk[ry])	//秩相同，合并后rx的秩增1
         rnk[rx]++;
      parent[ry]=rx;		//ry结点作为rx的孩子
   }
}

};

int main() {
    // insert code here...
};