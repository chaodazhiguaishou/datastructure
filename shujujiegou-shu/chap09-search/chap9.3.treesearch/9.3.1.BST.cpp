#include <iostream>
#include <stdio.h>
using namespace std;

//二叉排序树（简称BST）又称二叉查找（搜索）树，其定义为：二叉排序树或者是空树，或者是满足如下性质的二叉树：
// 若它的左子树非空，则左子树上所有结点值（默认为结点关键字）均小于根结点值。
// 若它的右子树非空，则右子树上所有结点值均大于根结点值。
// 左、右子树本身又各是一棵二叉排序树。
//特点：中序序列是一个递增有序序列！

//二叉排序树的每个结点含key和data
template <typename T1,typename T2>
struct BSTNode			//二叉排序树结点类
{  T1 key;			//存放关键字,假设关键字为T1类型
   T2 data;			//存放数据项,假设数据项为T2类型
   BSTNode* lchild;		//存放左孩子指针
   BSTNode* rchild;		//存放右孩子指针
   BSTNode(T1 k,T2 d)		//构造函数
   {  key=k;
      data=d;
      lchild=rchild=NULL;	//新建结点默认为叶子结点
   }
};


template <typename T1,typename T2>
class BSTClass				//二叉排序树类模板
{
public:
BSTNode<T1,T2>* r;			//二叉排序树根结点
BSTNode<T1,T2>* f;			//用于临时存放待删除结点的双亲
BSTClass()				//构造函数
{   r=NULL; f=NULL; }
~BSTClass()				//析构函数
{  
    DestroyBTree(r);		//调用DestroyBTree()函数
    r=NULL;
}
void DestroyBTree(BSTNode<T1,T2>* b){}	//释放所有的结点空间

//二叉排序树的基本运算算法

void InsertBST(T1 k,T2 d)			//插入一个(k,d)结点
{
   r=_InsertBST(r,k,d);
}

// 在根结点p的二叉排序树中插入关键字为k的结点的过程如下：（是个递归的过程）
// 若p为空，创建一个key为k的结点，返回将它作为根结点。
// 若k<p->key，将k插入p结点的左子树中并且修改p的左指针。（要满足中序遍历是递增）
// 若k>p->key，将k插入p结点的右子树中并且修改p的右指针。
// 其他情况是k=p->key，说明树中已有关键字k，修改data值并返回p。

BSTNode<T1,T2>* _InsertBST(BSTNode<T1,T2>* p,T1 k,T2 d)//在以p为根的BST中插入关键字为k的结点
{  if (p==NULL)				//原树为空,为根结点
      p=new BSTNode<T1,T2>(k,d);
   else if (k<p->key) 
      p->lchild=_InsertBST(p->lchild,k,d); 	//插入到p的左子树中
   else if (k>p->key)
      p->rchild=_InsertBST(p->rchild,k,d);	//插入到p的右子树中
   else						//相同关键字,修改data域
      p->data=d;
   return p;
}

// 创建二叉排序树r是从一个空树开始，先创建根结点，
// 以后每插入一个关键字k，就调用一次InsertBST(k,d)算法将(k,d)插入到当前的二叉排序树中。

void CreateBST(vector<T1>& a,vector<T2>& b)//由a和b向量创建一棵二叉排序树
{  r=new BSTNode<T1,T2>(a[0],b[0]);		//创建根结点
   for (int i=1;i<a.size();i++)		//创建其他结点
      InsertBST(a[i],b[i]);			//插入(a[i],b[i])
}

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

//排序二叉树的删除
// 删除关键字与删除结点是一回事（每个结点一个关键字）。
// 删除一个结点时不能简单地把以该结点为根的子树都删去，只能删除该结点本身，并且还要保证删除后的二叉树仍然满足BST性质。
// 也就是说，在二叉排序树中删除一个结点就相当于删除有序序列（即该树的中序序列）中的一个结点。
// 删除结点p分为以下几种情况
// （a）结点p为叶子结点：直接删除
// （b）结点p仅有左孩子：用左孩子q结点替代结点p
// （c）结点p仅有右孩子：用右孩子q结点替代结点p
// （d）结点p有左右孩子：找到其左孩子的最右下结点q，置p结点值为q结点值（值替代），再删除q结点（
//     q结点没有右孩子，最多只有左孩子，采用(b)删除）



};


int main() {
    // insert code here...
};

//查找说明
// 与折半查找的判定树类似，在二叉排序树中每个空指针处添加一个外部结点。
// 在二叉排序树中查找时，若查找成功，则是从根结点出发走了一条从根结点到查找到结点的路径。
// 若查找不成功，则是从根结点出发走了一条从根到某个外部结点的路径。
// 因此与折半查找类似，查找中关键字比较的次数不超过树的高度。
// 提示
// 一个关键字集合可以有多个不同顺序的关键字序列，对于不同的关键字序列，CreateBST()算法创建的二叉排序树可能不同。
// 例如，关键字序列为（5，2，1，6，7，4，3），创建的二叉排序树如图(a)所示。
// 若关键字序列为（1，2，3，4，5，6，7），创建的二叉排序树如图(b)所示。

// 那么如何分析二叉排序树的查找性能呢？有如下两种分析方法。
// 给定含n个关键字的集合，假设所有关键字不相同，对应有n!个关键字序列，每个关键字序列构造一棵二叉排序树，
// 所有这些二叉排序树中查找每个关键字的平均时间为O(log2n)。

// 给定含n个关键字的关键字序列构造一棵二叉排序树。其中查找性能最好的是高度最小的二叉排序树，最好查找性能为O(log2n)。
// 查找性能最坏的是高度为n的二叉排序树（单支树），最坏查找性能为O(n)。平均情况由具体的关键字序列来确定。
// 所以常说二叉排序树的时间复杂度在O(log2n)和O(n)之间，就是指这种分析方法。



