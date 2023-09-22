#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

//二叉树的链式存储结构
//优缺点：
//相对于顺序存储结构，二叉链方便二叉树的修改，对于普通二叉树和完全二叉树同样适合二叉链存储。
//在二叉链中查找一个结点的孩子十分方便，但查找一个结点的双亲结点需要遍历二叉树。


struct BTNode					//二叉链中结点类型
{  char data;					//数据元素
   BTNode* lchild;				//指向左孩子结点
   BTNode* rchild;				//指向右孩子结点
   BTNode():lchild(NULL),rchild(NULL) {}	//构造函数
   BTNode(char d)				//重载构造函数
   {  data=d;
      lchild=rchild=NULL;
   }
};

//二叉树的递归算法
//对于二叉树r，设f(r)是求解的“大问题”。
//f(r->lchild)和f(r->rchild)为“小问题”。
// 假设f(r->lchild)和f(r->rchild)是可求的，在此基础上得出f(r)和f(r->lchild)、f(r->rchild)之间的关系，
//从而得到递归体。
// 再考虑r=NULL或只有一个结点的特殊情况，从而得到递归出口。

int Sum(BTNode* r)		//计算以b为根的二叉树的结点值之和
{  if (r==NULL) return 0;
   else return r->data+Sum(r->lchild)+Sum(r->rchild);
}

class BTree			//二叉树类
{  BTNode* r;			//二叉树的根结点r
public:
    BTree()			//构造函数,建立一棵空树
    {  r=NULL;  }
   //二叉树的基本运算
    
void CreateBTree(string str)
{
    stack<BTNode*> st;
    BTNode* p;
    bool flag;
    int i =0;
    while (i<str.length())
    {
        
    }
    
}

void DispBTree()
{

}


BTNode* FindNode(char x)		     //查找值为x的结点算法
{
   return FindNode1(r,x);
}
BTNode* FindNode1(BTNode* b,char x)	      //被FindNode函数调用
{  BTNode* p;
   if (b==NULL) return NULL;		      //b为空时返回NULL
   else if (b->data==x) return b;	      //b所指结点值为x时返回b
   else
   {  p=FindNode1(b->lchild,x);	      //在左子树中查找
      if (p!=NULL)
         return p;			//在左子树中找到p结点，返回p
      else
         return FindNode1(b->rchild,x);   //返回在右子树中查找结果
   }
}

int Height()				//求二叉树高度的算法
{
   return Height1(r);
}

int Height1(BTNode* b)		//被Height函数调用
{  if (b==NULL)			//空树的高度为0
      return 0;
   else
      return max(Height1(b->lchild),Height1(b->rchild))+1;
}

void DestroyBTree(BTNode* b)		//释放所有的结点空间
{  if (b!=NULL)
   {  DestroyBTree(b->lchild);	//递归释放左子树
      DestroyBTree(b->rchild);	//递归释放右子树
      delete b;			//释放根结点
   }
}

~BTree()				//析构函数
{  DestroyBTree(r);			//调用DestroyBTree()函数
   r=NULL;				//置为空树
}


};

int main() {
    // insert code here...
    
};