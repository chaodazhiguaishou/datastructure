#include <iostream>
#include <stdio.h>
using namespace std;

//1. 邻接表存储方法
//对图中每个顶点i建立一个单链表，将顶点i的所有邻接点链起来。
//然后每个单链表上添加一个表头结点（表示顶点信息）。并将所有表头结点构成一个数组，下标为i的元素表示顶点i的表头结点。
//图的邻接表存储方法是一种顺序分配与链式分配相结合的存储方法。

// 邻接表表示不唯一。
// 对于有n个顶点和e条边的无向图，其邻接表有n个表头结点和2e个边结点；
// 对于有n个顶点和e条边的有向图，其邻接表有n个表头结点和e个边结点。
// 显然，对于边数目较少的稀疏图，邻接表比邻接矩阵要节省空间。
// 对于无向图，顶点i（0≤i≤n-1）对应的单链表的边结点个数正好是顶点i的度。
// 对于有向图，顶点i（0≤i≤n-1）对应的单链表的边结点个数仅仅是顶点i的出度。
// 顶点i的入度是邻接表中所有adjvex值为i的边结点个数。
// 用邻接表存储图时，确定任意两个顶点之间是否有边相连的时间为O(m)（m为最大顶点出度，m<n）。

// 有向图的邻接表头节点后面跟着是从该节点指出去的节点。

const int MAXV=100;			//图中最多的顶点数
const int INF=0x3f3f3f3f;		//用INF表示∞

struct ArcNode			//边结点类型
{  int adjvex;			//邻接点
   int weight;			//权值
   ArcNode* nextarc;		//指向下一条边的边结点
};

struct HNode			//头结点类型
{  string info;			//顶点信息
   ArcNode* firstarc;		//指向第一条边的边结点
};

class AdjGraph				//图邻接表类
{
public:
   HNode adjlist[MAXV];		//头结点数组
   int n,e;				//顶点数，边数
   AdjGraph()				//构造函数
   {  for (int i=0;i<MAXV;i++)	//头结点的firstarc置为空
         adjlist[i].firstarc=NULL;
   }
   ~AdjGraph()				//析构函数,释放图的邻接表空间
   {  ArcNode* pre,*p;
      for (int i=0;i<n;i++)		//遍历所有的头结点
      {  pre=adjlist[i].firstarc;
         if (pre!=NULL)
         {  p=pre->nextarc;
            while (p!=NULL)		//释放adjlist[i]的所有边结点空间
            {  delete pre;
               pre=p; p=p->nextarc; 	//pre和p指针同步后移
	    }
	    delete pre;
         }
      }
   }
//图的基本运算算法
void CreateAdjGraph(int a[][MAXV],int n,int e)
//通过a、n和e来建立图的邻接表
{  ArcNode* p;
   this->n=n; this->e=e;			//置顶点数和边数
   for (int i=0;i<n;i++)			//检查邻接矩阵中每个元素
      for (int j=n-1;j>=0;j--)
         if (a[i][j]!=0 && a[i][j]!=INF)	//第i行，代表起点i，存在一条边
         {  p=new ArcNode();			//创建一个结点p
            p->adjvex=j;            //第j列，代表终点j，是临接点的值
            p->weight=a[i][j]; 
            p->nextarc=adjlist[i].firstarc;	//采用头插法插入p，插入头节点数组第i个头节点侧边
            adjlist[i].firstarc=p;
         }
}

void DispAdjGraph()			//输出图的邻接表
{  ArcNode* p;
   for (int i=0;i<n;i++)		//遍历每个头结点
   {  printf("   [%d]",i);
      p=adjlist[i].firstarc;		//p指向第一个邻接点
      if (p!=NULL)  printf("→");
      while (p!=NULL)			//遍历第i个单链表
      {  printf(" (%d,%d)",p->adjvex,p->weight);
         p=p->nextarc;		//p移向下一个邻接点
      }
      printf("\n");
   }
}

};


int test()
{  AdjGraph G;
   int n=5,e=5;
   int A[MAXV][MAXV]={{0,8,INF,5,INF},{INF,0,3,INF,INF},
	{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0}};	
   G.CreateAdjGraph(A,n,e);
   cout << "图的邻接表:\n"; G.DispAdjGraph();
   cout << "销毁图\n";
   return 0;
}


//扩展：逆邻接表
//跟邻接表相反，每个头节点后面跟着的是指向该点的节点
//方便查找每个顶点的入边
