#include <iostream>
#include <stdio.h>
#include "../chap7.2.erchatree/7.2.2.linktree.cpp"
#include <queue>
using namespace std;

//采用层次遍历方法设计例7.14的算法，即求二叉树中第k（1≤k≤二叉树高度）层的结点个数。

struct QNode				//队列元素类
{  int lev;				//结点的层次
   BTNode* node;			//结点指针
   QNode(int l,BTNode* p)		//构造函数
   {  lev=l;
      node=p;
   }
};

class Solution
{
public:
//解法一
// 用cnt变量计第k层结点个数（初始为0）。
// 设计队列中元素类型为QNode类，包含表示当前结点层次lev和结点地址node两个成员变量。
// 1.先将根结点进队（根结点的层次为1）。在层次遍历中出队一个结点p：
// 2.若结点p层次大于k，返回cnt（继续层次遍历不可能再找到第k层的结点）。
// 3.若结点p是第k层的结点（p.lev=k），cnt增1。
// 4.若结点p的层次小于k，将其孩子结点进队，孩子结点的层次为双亲结点的层次加1。
// 最后返回cnt。

//简而言之就是跟层次遍历的算法一样，挨个入栈进行运算

int KCount1(BTree& bt,int k)		//解法1：求二叉树第k层结点个数
{  int cnt=0;				//累计第k层结点个数
   queue<QNode> qu;			//定义一个队列qu
   qu.push(QNode(1,bt.r));		//根结点(层次为1)进队
   while (!qu.empty())		//队不空循环
   {  QNode p=qu.front(); qu.pop();	//出队一个结点
      if (p.lev>k)			//当前结点的层次大于k，返回cnt
         return cnt;
      if (p.lev==k)
         cnt++;			//当前结点是第k层的结点,cnt增1
      else				//当前结点的层次小于k
      {  if (p.node->lchild!=NULL)	//有左孩子时将其进队
            qu.push(QNode(p.lev+1,p.node->lchild));
         if (p.node->rchild!=NULL)	//有右孩子时将其进队
            qu.push(QNode(p.lev+1,p.node->rchild));
      }
   }
   return cnt;
}


// 解法二：层次遍历中某层的最右结点last
// 用cnt变量计第k层结点个数（初始为0）。
// 设计队列仅保存结点引用，置当前层次curl=1，用last变量指示当前层次的最右结点（根结点）进队。将根结点进队，队不空循环：
// 1.若curl>k，返回cnt（继续层次遍历不可能再找到第k层的结点）。
// 2.否则出队结点p，若curl=k，表示结点p是第k层的结点，cnt增1。
// 3.若结点p有左孩子q，将结点q进队，有右孩子q，将结点q进队（总是用q表示进队的结点）。
// 4，若结点p是当前层的最右结点（p=last），说明当前层处理完毕，
//而此时的q就是下一层的最右结点，置last=q，curl++进入下一层处理。

//跟解法一的区别是相当于多了一个指针用来判断一行是不是已经处理完毕

int KCount2(BTree& bt,int k)		//解法2：求二叉树第k层结点个数
{  int cnt=0;				//累计第k层结点个数
   queue<BTNode* > qu;		//定义一个队列qu
   int curl=1;				//当前层次,从1开始
   BTNode* last=bt.r,*p,*q;		//第1层最右结点
   qu.push(bt.r);		
    while (!qu.empty()) 		//队不空循环
    {  
        if (curl>k)			//当层号大于k时返回cnt,不再继续
            return cnt;
        p=qu.front(); qu.pop();		//出队一个结点p
        if (curl==k)
            cnt++;				//当前结点是第k层的结点,cnt增1
        if (p->lchild!=NULL)		//有左孩子时将其进队
        {  q=p->lchild;
            qu.push(q);
        }
        if (p->rchild!=NULL)		//有右孩子时将其进队
        {  q=p->rchild;
            qu.push(q);
        }
        if (p==last)			//当前层的所有结点处理完毕
        {  last=q;			//让last指向下一层的最右结点
            curl++;
        }
    }
    return cnt;
}


// 层次遍历是从第一层开始，访问一层的全部结点后（此时该层的全部结点已出队）再访问下一层的结点。
// 上一层遍历完毕，队中恰好是下一层的全部结点。
// 若k<1，返回0。
// 否则将根结点进队，当前层次curl=1。队不空循环：
// 若curl=k，队中恰好包含该层的全部结点，直接返回队中元素个数（即第k层结点个数）。
// 否则，求出队中元素个数n（当前层curl的全部结点个数），循环出队n次，每次出队一个结点时将其孩子结点进队。
// 置curl++，进入下一层处理。
// 最后返回0（k>二叉树高度的情况）。
int KCount3(BTree& bt,int k)		//解法3：求二叉树第k层结点个数
{  if (k<1) return 0;			//k<1返回0
   queue<BTNode* > qu;		//定义一个队列qu
   int curl=1;				//当前层次,从1开始
   qu.push(bt.r);			//根结点进队
   while (!qu.empty())		//队不空循环
   {  if (curl==k)			//当前层为第k层，返回队中元素个数
         return qu.size();
      int n=qu.size();		//求出当前层结点个数
      for (int i=0;i<n;i++)		//出队当前层的n个结点
      {  BTNode* p=qu.front();qu.pop();	//出队一个结点
         if (p->lchild!=NULL)		//有左孩子时将其进队
            qu.push(p->lchild);
         if (p->rchild!=NULL)		//有右孩子时将其进队
            qu.push(p->rchild);
      }
      curl++;
   }					//转向下一层
   return 0;
}


};

int main()
{  
    string str="A(B(D(,G)),C(E,F))";
    BTree bt;
    Solution s;
    bt.CreateBTree(str);
    cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
    printf("解法1:\n");
    for (int k=1;k<=5;k++)
        cout << "    第" << k << "层的结点个数: "<<s.KCount1(bt,k)<<endl; 
    printf("解法2:\n");
    for (int k=1;k<=5;k++)
        cout << "    第" << k << "层的结点个数: "<<s.KCount2(bt,k)<<endl; 
    printf("解法3:\n");
    for (int k=1;k<=5;k++)
        cout << "    第" << k << "层的结点个数: "<<s.KCount3(bt,k)<<endl; 
    return 0;
}
