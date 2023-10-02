#include <iostream>
#include <stdio.h>
#include "../chap7.2.erchatree/7.2.2.linktree.cpp"
using namespace std;

//假设二叉树中每个结点值为单个字符，采用二叉链存储结构存储。设计一个算法交换二叉树bt的所有左右子树。



class Solution
{
public:
void Swap11(BTNode *&b)		//基于先序遍历
{  if (b!=NULL)
   {  swap(b->lchild,b->rchild);	//交换根结点b的左右孩子指针 
      Swap11(b->lchild);		//递归交换左子树
      Swap11(b->rchild); 		//递归交换右子树
   }
}

void Swap1(BTree &bt)			//求解算法1
{
   Swap11(bt.r);
}

void Swap21(BTNode *&b)		//基于后序遍历
{  if (b!=NULL)
   {  Swap21(b->lchild);		//递归交换左子树
      Swap21(b->rchild); 		//递归交换右子树
      swap(b->lchild,b->rchild);	//交换根结点b的左右孩子指针 
   }
}

void Swap2(BTree &bt)			//求解算法2 
{
   Swap21(bt.r);
}

// 基于中序遍历算法得到交换结果是错误的。
// 因为中序遍历先访问左孩子，对它交换，然后访问父节点，交换后访问右孩子，
// 但此时的右孩子是交换前的左孩子，相当于对右孩子没有进行交换,而左节点被交换了两次也没变
void Swap31(BTNode *&b)		//基于中序遍历。基于中序遍历算法得到交换结果是错误的。

{  if (b!=NULL)
   {  Swap31(b->lchild);		//递归交换左子树
      swap(b->lchild,b->rchild);	//交换根结点b的左右孩子指针 
      Swap31(b->rchild); 		//递归交换右子树
   }
}

void Swap3(BTree &bt)			//求解算法3
{
   Swap31(bt.r);
}

};

int main() {
    // insert code here...
};