#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

// 二叉树的链式存储结构
// 优缺点：
// 相对于顺序存储结构，二叉链方便二叉树的修改，对于普通二叉树和完全二叉树同样适合二叉链存储。
// 在二叉链中查找一个结点的孩子十分方便，但查找一个结点的双亲结点需要遍历二叉树。

struct BTNode // 二叉链中结点类型
{
   char data;                               // 数据元素
   BTNode *lchild;                          // 指向左孩子结点
   BTNode *rchild;                          // 指向右孩子结点
   BTNode() : lchild(NULL), rchild(NULL) {} // 构造函数
   BTNode(char d)                           // 重载构造函数
   {
      data = d;
      lchild = rchild = NULL;
   }
};

// 二叉树的递归算法
// 对于二叉树r，设f(r)是求解的“大问题”。
// f(r->lchild)和f(r->rchild)为“小问题”。
//  假设f(r->lchild)和f(r->rchild)是可求的，在此基础上得出f(r)和f(r->lchild)、f(r->rchild)之间的关系，
// 从而得到递归体。
//  再考虑r=NULL或只有一个结点的特殊情况，从而得到递归出口。

int Sum(BTNode *r) // 计算以b为根的二叉树的结点值之和
{
   if (r == NULL)
      return 0;
   else
      return r->data + Sum(r->lchild) + Sum(r->rchild);
}

class BTree // 二叉树类
{
   // BTNode *r; // 二叉树的根结点r //为方便引用，从private改成public
public:
BTNode *r; // 二叉树的根结点r

   BTree() // 构造函数,建立一棵空树
   {
      r = NULL;
   }
   // 二叉树的基本运算

   void CreateBTree(string str) // 使用字符串创建树,如A(B(D(,G)),C(E,F))
   {
      stack<BTNode *> st;
      BTNode *p;
      bool flag; // flag表示将要处理左节点
      int i = 0;
      while (i < str.length())
      {
         switch (str[i])
         {
         case '(': // 说明前一个有子节点，进栈准备处理
            st.push(p);
            flag = true;
            break;
         case ')':
            st.pop(); // 子节点处理完毕，出栈
            break;
         case ',': // 左孩子处理完，开始处理右节点
            flag = false;
            break;
         default:
            p = new BTNode(str[i]); // 遇到字符，创建新节点存储！！这里是新的指针变量！！只是名字没变
            if (r == NULL)
               r = p; // 没有根节点成为根节点
            else
            {
               if (flag && !st.empty()) // 处理左节点且栈中有数据
                  st.top()->lchild = p; //此时的st.top()一定是前一个（也就是父节点）的！！
               else if (!st.empty())
                  st.top()->rchild = p; // 处理右节点
            }
            break;
         }
         i++; // 下一个字符
      }
   }
// 以使用字符串创建树,如A(B(D(,G)),C(E,F))为例
//执行到      栈       flag     指针p
//A          NULL     NULL     A   
//A(         A        true     A 
//A(B        A        true     B(A->lchild)
//A(B(       AB       true     B
//A(B(D      AB       true     D(B->lchild)
//A(B(D(     ABD      true     D
//A(B(D(,    ABD      false    D
//A(B(D(,G   ABD      false    G(D->rchild)
//此算法在最开始就创建指针，并每次直接覆盖new是因为
//栈顶的元素再每次执行完不会再需要修改，可以放心往栈底走

   void DispBTree()
   {
      DispBTree1(r);
   }

   void DispBTree1(BTNode *b)  //树的输出使用递归！
   {
      if (b != NULL) //不为空则输出
      {
         cout << b->data;
         if (b->lchild != NULL || b->rchild != NULL) //存在子树
         {
            cout << "(";
            DispBTree1(b->lchild);
            if (b->rchild != NULL) //输出了左子树，如果右子树不为空则加个逗号
               cout << ",";
            DispBTree1(b->rchild);
            cout << ")";
         }
      }
   }

   BTNode *FindNode(char x) // 查找值为x的结点算法
   {
      return FindNode1(r, x);
   }
   BTNode *FindNode1(BTNode *b, char x) // 被FindNode函数调用
   {
      BTNode *p;
      if (b == NULL)
         return NULL; // b为空时返回NULL
      else if (b->data == x)
         return b; // b所指结点值为x时返回b
      else
      {
         p = FindNode1(b->lchild, x); // 在左子树中查找
         if (p != NULL)
            return p; // 在左子树中找到p结点，返回p
         else
            return FindNode1(b->rchild, x); // 返回在右子树中查找结果
      }
   }

   int Height() // 求二叉树高度的算法
   {
      return Height1(r);
   }

   int Height1(BTNode *b) // 被Height函数调用
   {
      if (b == NULL) // 空树的高度为0
         return 0;
      else
         return max(Height1(b->lchild), Height1(b->rchild)) + 1;
   }

   void DestroyBTree(BTNode *b) // 释放所有的结点空间
   {
      if (b != NULL)
      {
         DestroyBTree(b->lchild); // 递归释放左子树
         DestroyBTree(b->rchild); // 递归释放右子树
         delete b;                // 释放根结点
      }
   }

   ~BTree() // 析构函数
   {
      DestroyBTree(r); // 调用DestroyBTree()函数
      r = NULL;        // 置为空树
   }
};

int test()
{  string str="A(B(D(,G)),C(E,F))";
   char x='e';
   BTree bt;
   bt.CreateBTree(str);
   cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
   cout << "bt的高度:" << bt.Height() << endl;
   if (bt.FindNode(x))
      cout << "bt中找到值为" << x << "的结点\n";
   else
      cout << "bt中没有找到值为" << x << "的结点\n";
   cout << "销毁二叉树\n";
   return 0;
}
