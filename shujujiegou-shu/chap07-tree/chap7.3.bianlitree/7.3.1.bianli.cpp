#include <iostream>
#include <stdio.h>
#include "../chap7.2.erchatree/7.2.2.linktree.cpp"
using namespace std;

//先序遍历 中序遍历 后序遍历的代码实现
BTree bt;

class Solution
{
public:
void PreOrder11(BTNode* b)		//被PreOrder函数调用
{  if (b!=NULL)
   {  cout << b->data;		//访问根结点
      PreOrder11(b->lchild);		//先序遍历左子树
      PreOrder11(b->rchild);		//先序遍历右子树
   }
}
void PreOrder1(BTree& bt)		//先序遍历的递归算法
{
   PreOrder11(bt.r);
}

void InOrder11(BTNode* b)		//被InOrder函数调用
{  if (b!=NULL)
   {  InOrder11(b->lchild);		//中序遍历左子树
      cout << b->data;		//访问根结点
      InOrder11(b->rchild);		//中序遍历右子树
   }
}
void InOrder1(BTree& bt)		//中序遍历的递归算法
{
   InOrder11(bt.r);
}

void PostOrder11(BTNode* b)		//被PostOrder函数调用
{  if (b!=NULL)
   {  PostOrder11(b->lchild);		//后序遍历左子树
      PostOrder11(b->rchild);		//后序遍历右子树
      cout << b->data;		//访问根结点
   }
}
void PostOrder1(BTree& bt)		//后序遍历的递归算法
{
   PostOrder11(bt.r);
}


};

int main() {
    // insert code here...
};