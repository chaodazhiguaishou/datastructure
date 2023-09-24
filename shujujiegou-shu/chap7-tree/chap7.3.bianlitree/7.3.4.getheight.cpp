#include <iostream>
#include <stdio.h>
#include "../chap7.2.erchatree/7.2.2.linktree.cpp"
using namespace std;

//假设一棵二叉树采用二叉链存储结构，且所有结点值均不相同，
//设计一个算法求二叉树中指定结点值的结点所在的层次（根结点的层次计为1）。

//递归查找的时候往往会在递归左子树后验证一下再去看递归右函数，这样如果找到了就可以节省一半左右时间

class Solution1
{
int Level1(BTNode* b,char x,int h)		//被Level()算法调用
{  if (b==NULL)
      return 0;				//空树不能找到该结点
   else if (b->data==x)
      return h;				//根结点即为所找,返回其层次
   else
   {  int l=Level1(b->lchild,x,h+1);		//在左子树中查找
      if (l!=0)				//左子树中找到了
         return l;				//返回其层次l
      else					//左子树中未找到
         return Level1(b->rchild,x,h+1);	//再在右子树中查找
   }
}

int Level(BTree& bt,char x)			//求解算法
{
   return Level1(bt.r,x,1);
}
};


// 假设二叉树采用二叉链存储结构，且所有结点值均不相同，设计一个算法求二叉树中第k（1≤k≤二叉树高度）层的结点个数。 
// 采用先序遍历思路。
// 设计KCount1(b，h，k，cnt)递归算法在根结点b的二叉树中求第k层的结点个数cnt，
// 其中h表示b指向结点的层次（采用参数赋初值方法，b为根结点时，h对应的实参数为1）。


class Solution2
{
public:
void KCount1(BTNode* b,int h,int k,int& cnt)
{  if (b==NULL) return;		//空树返回
   if (h==k) cnt++;			//当前层的结点在第k层，cnt增1
   if (h<k)				//当前层次小于k，递归处理求子树
   {  KCount1(b->lchild,h+1,k,cnt);
      KCount1(b->rchild,h+1,k,cnt);
   }
}

int KCount(BTree& bt,int k)		//先序遍历求二叉树第k层结点个数
{  int cnt=0;
   KCount1(bt.r,1,k,cnt);
   return cnt;
}

};

int main()
{  string str="A(B(D(,G)),C(E,F))";
   BTree bt;
   Solution2 s2;
   bt.CreateBTree(str);
   cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
   for (int k=1;k<=5;k++)
      cout << "第" << k << "层的结点个数: " << s2.KCount(bt,k) << endl; 
   cout << "销毁二叉树\n";
   return 0;
}
