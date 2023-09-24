#include <iostream>
#include <stdio.h>
#include "../chap7.2.erchatree/7.2.2.linktree.cpp"
using namespace std;

//假设二叉树采用二叉链存储结构，且所有结点值均不相同，设计一个算法输出值为x的结点的所有祖先。


// 根据二叉树中祖先的定义可知，若一个结点的左孩子或右孩子值为x时，则该结点是x结点的祖先结点；
// 若一个结点的左孩子或右孩子为x结点的祖先结点时，则该结点也为x结点的祖先结点。
// 设f(b，x，res)表示b结点是否为结点x的祖先结点，
// vector<char>容器res存放结点x的祖先结点（从根结点到结点x双亲的结点序列）


//递归！！！依旧是递归！！
//首先考虑到输出所有节点所以显然需要容器装这些点
//为了保证回溯到时候每个都会被输出，所以采用bool值作为标志！

class Solution1
{
public:
bool Ancestor11(BTNode* b, char x,vector<char>& res)
{  if (b==NULL)				//空树返回false
      return false;
   if (b->lchild!=NULL && b->lchild->data==x)
   {  res.push_back(b->data);			//结点b是x结点的祖先
      return true;
   }
   if (b->rchild!=NULL && b->rchild->data==x)
   {  res.push_back(b->data);			//结点b是x结点的祖先
      return true;
   }
   if (Ancestor11(b->lchild,x,res) || Ancestor11(b->rchild,x,res))
   {  res.push_back(b->data);	  //结点b的孩子是x的祖先，则它是x的祖先
      return true;
   }
   return false;				//其他情况返回false
}

void Ancestor1(BTree& bt,char x,vector<char>& res)
 //算法1：返回x结点的祖先
{  Ancestor11(bt.r,x,res);
   reverse(res.begin(),res.end()); //逆置res→按根结点到结点x双亲的顺序
}
};

// 二叉树中x结点的祖先恰好是根结点到x结点的路径上除了x结点外的所有结点，用全局变量res向量表示。
// 采用先序遍历的思路，采用一个path向量存放路径，当找到x结点时，将path中x结点（最后添加的结点）删除，
// 再将path复制到答案中。

//这道题这样解法不会出错是因为，每次递归调用path的时候都是复制调用！！！
//而非对同一个指针的path进行修改，如果是指针那这道题会输出其余很多东西
class Solution2
{
public:
void Ancestor21(BTNode* b,char x,vector<char> path,vector<char>&res)
{  
    if (b==NULL) //空树返回
        return;			
    path.push_back(b->data); //不为空，则加入容器
    if (b->data==x)
    {  path.pop_back();			//删除x结点
        res=path;				//复制path到res
        return;					//找到路径后返回
    }
    Ancestor21(b->lchild,x,path,res);		//在左子树中查找
    Ancestor21(b->rchild,x,path,res);		//在右子树中查找
}
void Ancestor2(BTree& bt,char x,vector<char>& res)
 //算法2：返回x结点的祖先
{  vector<char> path;
   Ancestor21(bt.r,x,path,res);
}
};

int main()
{  string str="A(B(D(,G)),C(E,F))";
   BTree bt;
   Solution1 s1;
   Solution2 s2;
   bt.CreateBTree(str);
   cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
   for (char ch='A';ch<='G';ch++)
   {  cout <<  ch << "结点的所有祖先:";
      vector<char> res;				//存放祖先
      s1.Ancestor1(bt,ch,res);
      for (int i=0;i<res.size();i++)
          cout << " " << res[i];
      cout << endl;
   }
   cout << endl;
   for (char ch='A';ch<='G';ch++)
   {  cout <<  ch << "结点的所有祖先:";
      vector<char> res;				//存放祖先
      s2.Ancestor2(bt,ch,res);
      for (int i=0;i<res.size();i++)
          cout << " " << res[i];
      cout << endl;
   }
   cout << "销毁二叉树\n";
   return 0;
}
