#include <iostream>
#include <stdio.h>
#include <vector>
#include "../chap7.2.erchatree/7.2.2.linktree.cpp"
using namespace std;

//a0 a1 ... an   b0 b1 ... bn
//定理7.1 任何n（n≥0）个不同结点的二又树，都可由它的中序序列b和先序序列a唯一地确定。
//证明：找到中序遍历的a0=bk！，这样a1-ak是左子树，同理b0-bk-1是左子树，右子树则是右边，
//左子树一共k个节点，右子树一共n-k-1以此递归
//定理7.2 任何n（n≥0）个不同结点的二又树，都可由它的中序序列和后序序列唯一地确定。

class Solution
{
public:
void CreateBTree1(BTree& bt,vector<char> pres,vector<char> ins)
//由先序序列pres和中序序列ins构造二叉链
{  int n=pres.size(); //n为序列长度，即二叉树的节点数
   bt.r=CreateBTree11(pres,0,ins,0,n);
}
BTNode* CreateBTree11(vector<char> pres,int i,        //被CreateBTree1调用，用来找根节点和递归子树
                      vector<char> ins,int j,int n) //i表示找根节点位置，j表示从哪开始计算左子树长度
{  if (n<=0) return NULL;
   char d=pres[i];					//取根结点值d
   BTNode* b=new BTNode(d);				//创建根结点(值为d)
   int p=j;
   while (ins[p]!=d) p++;				//ins中找根索引p
   int k=p-j;						//左子树中结点个数k
   b->lchild=CreateBTree11(pres,i+1,ins,j,k);	//递归构造左子树
   b->rchild=CreateBTree11(pres,i+k+1,ins,j+k+1,n-k-1); //递归构造右子树
   return b;
}


void CreateBTree2(BTree& bt,vector<char> posts,vector<char> ins)
//由后序序列posts和中序序列ins构造二叉链
{  int n=posts.size();
   bt.r=CreateBTree21(posts,0,ins,0,n);
}
BTNode* CreateBTree21(vector<char> posts,int i,
                      vector<char> ins,int j,int n) 
//被CreateBTree2调用
{  if (n<=0) return NULL;
   char d=posts[i+n-1];			//取后序序列尾元素即根值d
   BTNode* b=new BTNode(d);			//创建根结点(结点值为d)
   int p=j;
   while (ins[p]!=d) p++;			//在ins中找到根结点的索引p
   int k=p-j;					//确定左子树中结点个数k
   b->lchild=CreateBTree21(posts,i,ins,j,k);	//递归构造左子树
   b->rchild=CreateBTree21(posts,i+k,ins,p+1,n-k-1); //递归构造右子树
   return b;
}

};

int main() {
    // insert code here...
};