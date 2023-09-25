#include <iostream>
#include <stdio.h>
#include "../chap7.2.erchatree/7.2.2.linktree.cpp"
#include <queue>
using namespace std;

//         A
//       B   C
//     D    E F
//      G
// 对此二叉树进行层次遍历ABCDEFG

// 在二叉树层次遍历中，对一层的结点访问完后，再按照它们的访问次序对各个结点的左、右孩子顺序访问，这样一层一层进行，
// 先访问的结点其左、右孩子也要先访问，这样与队列的先进先出特点吻合。因此层次遍历算法采用一个队列qu来实现。
// 思路：先将根结点b进队，在队不空时循环：从队列中出队一个结点p，访问它；若它有左孩子结点，将左孩子结点进队；
// 若它有左孩子结点，将左孩子结点进队。如此操作直到队空为止。

//简而言之，保证队列里按照层次遍历的顺序

class Solution
{
public:
void LevelOrder(BTree& bt)		//二叉树的层次遍历
{  
    BTNode* p;
    queue<BTNode*> qu;			//定义一个队列
    qu.push(bt.r);			//根结点r进队
    while (!qu.empty())		//队不空时循环 
    {  
        p=qu.front();   //取队首元素
        qu.pop();		//出队首元素p 
        cout << p->data;		//访问结点p
        if (p->lchild!=NULL)		//有左孩子时将其进队
            qu.push(p->lchild);
        if (p->rchild!=NULL)		//有右孩子时将其进队
            qu.push(p->rchild);
   }
}
};

int main() {
    // insert code here...
};