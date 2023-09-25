#include <iostream>
#include <stdio.h>
#include <vector>
#include "../chap7.2.erchatree/7.2.2.linktree.cpp"
using namespace std;

//仅仅讨论先序遍历序列化和反序列化。
//         A        
//       B   C
//     D    E F
//      G
//         A        
//       B   C
//     D #  E F
//    # G  ## ##
//      ##
//序列化结果："ABD#G###CE##F##"，反序列化即反过来

class Solution
{
public:
string PreOrderSeq(BTree& bt)		//二叉树bt的序列化
{
   return PreOrderSeq1(bt.r);
}

string PreOrderSeq1(BTNode* b)	//被PreOrderSeq调用
{  if (b==NULL) return "#";
   string s(1,b->data);		//含根结点
   s+=PreOrderSeq1(b->lchild);	//产生左子树的序列化序列
   s+=PreOrderSeq1(b->rchild);	//产生右子树的序列化序列
   return s;
}

void CreateBTree3(BTree& bt,string s)
//由序列化序列s创建二叉链：反序列化
{  int i=0;
   bt.r=CreateBTree31(s,i);
}

BTNode* CreateBTree31(string s,int& i)
//被CreateBTree3调用，其中参数i相当于全局变量
{  if (i>=s.length()) return NULL;		//i超界返回NULL 
   char d=s[i]; i++;				//取s[i]的值d 
   if (d=='#') return NULL;			//若为"#"，返回NULL
   BTNode* b=new BTNode(d);			//创建根结点(结点值为d)
   b->lchild=CreateBTree31(s,i);		//递归构造左子树
   b->rchild=CreateBTree31(s,i);		//递归构造右子树
   return b;
}

};

int main() {
    // insert code here...
};

//由于反序列化构造二叉树过程中不像先序/中序和后序/中序那样需要根结点值的比较，所以适合构造结点值相同的二叉树。
// 如先序序列：EBDBBED 中序序列：DBBEEBD 就无法通过先序遍历和中序遍历构造
