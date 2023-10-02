#include <iostream>
#include <stdio.h>
using namespace std;

//既保持BST性质又保证树的高度较小，通过这样的平衡规则和操作来维护O(log2n)高度的二叉排序树称为平衡二叉树，
//平衡二叉树有多种。较为著名的有AVL树。
//AVL树的高度平衡性质：树中每个结点的左、右子树的高度至多相差1。
//也就是说，如果树T中结点v有孩子结点x和y，则|h(x)-h(y)|≤1，h(x)表示以结点x为根的子树高度。

//AVL树中结点类型设计为AVLNode<T1，T2>类模板，每个结点存放[key，data]，其中关键字key为T1类型，数据项data为T2类型。

template <typename T1,typename T2>
struct AVLNode 		//AVL树结点类模板
{  T1 key;			//关键字k
   T2 data;			//关键字对应的值d
   int ht;			//当前结点的子树高度
   AVLNode* lchild,*rchild;	//左右指针
   AVLNode(T1 k,T2 d)		//构造函数，新建结点均为叶子，高度为1
   {  key=k; 
      data=d;
      ht=1;			//当前结点的子树高度
      lchild=rchild=NULL;
   }
};

//设计对应的AVL树类模板为AVLTree<T1，T2>，其中省略的析构函数与前面BSTClass<T1，T2>中析构函数完全相同。
template <typename T1,typename T2>
class AVLTree				//AVL树类模板
{  AVLNode* r;				//AVL的根结点
public:
   AVLTree():r(NULL) {}		//构造函数
   int getht(AVLNode* p)		//返回结点p的子树高度
   {  if (p==NULL) return 0;
      return p->ht;
   }
//AVL树的其他基本运算算法

//如何使构造的二叉排序树是一棵AVL树呢？
// 关键是每次向树中插入新结点时使所有结点的平衡因子满足高度平衡性质，这就要求插入后一旦哪些结点失衡就要进行调整。
//1. AVL树插入结点的调整方法

//（a）LL型调整
AVLNode* right_rotate(AVLNode* a)   		 //以结点a为根做右旋转
{  AVLNode* b=a->lchild;
   a->lchild=b->rchild;
   b->rchild=a;
   a->ht=max(getht(a->rchild),getht(a->lchild))+1; //更新A结点的高度
   b->ht=max(getht(b->rchild),getht(b->lchild))+1; //更新B结点的高度
   return b;
}
AVLNode* LL(AVLNode* a)		//LL型调整
{
   return right_rotate(a);
}

//（b）RR型调整
AVLNode* left_rotate(AVLNode* a)	//以结点a为根做左旋转
{  AVLNode* b=a->rchild;
   a->rchild=b->lchild;
   b->lchild=a;
   a->ht=max(getht(a->rchild),getht(a->lchild))+1; //更新A结点的高度
   b->ht=max(getht(b->rchild),getht(b->lchild))+1; //更新B结点的高度
   return b;
}
AVLNode* RR(AVLNode* a)		//RR型调整
{
   return left_rotate(a);
}

//（c）LR型调整LR双旋转：A的左子树B先左旋转，再按根结点A右旋转！
AVLNode* LR(AVLNode* a)			//LR型调整
{  AVLNode* b=a->lchild;
   a->lchild=left_rotate(b);			//结点b左旋
   return right_rotate(a);			//结点a右旋
}


//（d）RL型调整。RL双旋转：A的左子树B先右旋转，再按根结点A左旋转！
AVLNode* RL(AVLNode* a)		//RL型调整
{  AVLNode* b=a->rchild;
   a->rchild=right_rotate(b);		//结点b右旋
   return left_rotate(a);		//结点a左旋
}

//2. AVL树删除结点的调整方法
// 删除结点p分为以下几种情况
// （a）结点p为叶子结点：直接删除
// （b）结点p仅有左孩子：用左孩子q结点替代结点p
// （c）结点p仅有右孩子：用右孩子q结点替代结点p
// （d）结点p有左右孩子：通过值替换间接删除

//3．AVL树的查找（和二叉排序树BST查找过程完全相同）
//排序二叉树的查找
BSTNode<T1,T2>* SearchBST(T1 k)  //在二叉排序树中查找关键字为k的结点
{
   return _SearchBST(r,k);		//r为二叉排序树的根结点
}

BSTNode<T1,T2>* _SearchBST(BSTNode<T1,T2>* p,T1 k) 
//被SearchBST方法调用
{  if (p==NULL) return NULL;		 //空树返回NULL
   if (p->key==k) return p;		 //找到后返回p
   if (k<p->key)
      return _SearchBST(p->lchild,k); //在左子树中递归查找
   else
      return _SearchBST(p->rchild,k); //在右子树中递归查找
}

//含有n个结点的AVL树对应的查找时间复杂度为O(log2n)。

};

int main() {
    // insert code here...
};

// 补充：红黑树
// 红黑树是一棵二叉排序树，每个结点有一个表示颜色的标志，增加外部结点（通常用nil表示），同时满足以下性质：
// 1.每个结点的颜色为红色或者黑色。
// 2.根结点的颜色为黑色。
// 3.所有外部结点的颜色为黑色。（外部节点没有键和子节，叶子结点算外部节点）
// 4.如果一个结点是红色，则它的所有孩子结点为黑色。
// 5.对于每个结点，从该结点出发的所有路径上包含相同个数的黑色结点。路径特指从一个结点到其子孙结点中某个外部结点的路径。

// 红黑树是一种弱平衡二叉树，查找性能为O(log2n)
// 第4条性质（如果一个结点是红色，则它的所有孩子结点为黑色）可以得到任何一条路径上不能有两个相邻的红色结点，
// 这样最短的可能路径均由黑色结点构成，最长的可能路径由交替的红色和黑色结点构成。
// 第5条性质（从每个结点出发的所有路径上包含相同个数的黑色结点）可以得到所有最长的路径都有相同个数的黑色结点。
// 从根结点到叶子结点的最长路径的长度不大于最短路径长度的两倍。
// 含n个结点的红黑树的高度至多为2log2(n+1)，因此红黑树查找算法的平均时间复杂度为O(log2n)。

