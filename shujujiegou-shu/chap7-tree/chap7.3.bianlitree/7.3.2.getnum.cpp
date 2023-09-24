#include <iostream>
#include <stdio.h>
#include "../chap7.2.erchatree/7.2.2.linktree.cpp"
using namespace std;

//【例7.9】假设二叉树采用二叉链存储结构存储，设计一个算法求一棵给定二叉树中的结点个数。

//从遍历算法出发
//求一棵二叉树中的结点个数是以遍历算法为基础的，任何一种遍历算法都可以出一棵二叉树中的结点个数。
//在递归的时候根遍历算法递归一样，谁序递归就把k放在哪（其实顺序不影响）

//从递归思想出发
//f(b)=0					当b=NULL
// f(b)=f(b->lchild)+f(b->rchild)+1	其他情况
//（但其实就是把遍历写法写合起来）


class Solution
{
public:
int NodeCount11(BTNode* b)
{  int m,n,k;
   if (b!=NULL)
   {  k=1;				//根结点计数1
      m=NodeCount11(b->lchild);	//遍历求左子树的结点个数
      n=NodeCount11(b->rchild);	//遍历求右子树的结点个数
      return k+m+n;
   }
   else return 0;			//空树结点个数为0
}
int NodeCount1(BTree& bt)		//基于先序遍历求结点个数
{
   return NodeCount11(bt.r);
}

int NodeCount21(BTNode* b)
{  int m,n,k;
   if (b!=NULL)
   {  m=NodeCount21(b->lchild);		//遍历求左子树的结点个数
      k=1;					//根结点计数1
      n=NodeCount21(b->rchild);		//遍历求右子树的结点个数
      return k+m+n;
   }
   else return 0;				//空树结点个数为0
}
int NodeCount2(BTree& bt)			//基于中序遍历求结点个数
{
   return NodeCount21(bt.r);
}

int NodeCount31(BTNode* b)
{  int m,n,k;
   if (b!=NULL)
   {  m=NodeCount31(b->lchild);		//遍历求左子树的结点个数
      n=NodeCount31(b->rchild);		//遍历求右子树的结点个数
      k=1;					//根结点计数1
      return k+m+n;
   }
   else return 0;				//空树结点个数为0
}
int NodeCount3(BTree& bt)			//基于后序遍历求结点个数
{
   return NodeCount31(bt.r);
}

int NodeCount41(BTNode* b)
{  if (b==NULL)
     return 0;			//空树结点个数为0
   else
     return(NodeCount41(b->lchild)+NodeCount41(b->rchild)+1);
}
int NodeCount4(BTree& bt)	//基于递归设计方法求结点个数
{
   return NodeCount41(bt.r);
}


};

int main() {
    // insert code here...
};