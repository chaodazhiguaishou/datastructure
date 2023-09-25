#include <iostream>
#include <stdio.h>
using namespace std;

// 邻接矩阵存储方法
// 邻接矩阵是表示顶点之间邻接关系的矩阵。设G=(V，E)是含有n（设n>0）个顶点的图，各顶点的编号为0～n-1，
// 则G的邻接矩阵数组A是n阶方阵。

// （1）如果G是不带权图，则：
// A[i][j]=1     若(i，j)∈E(G)或者<i，j>∈E(G)
// A[i][j]=0     其他
// （2）如果G是带权图，则：
// A[i][j]=wij   若i≠j并且(i，j)∈E(G)或者<i，j>∈E(G)
// A[i][j]=0     若i=j
// A[i][j]=无穷大 其他

// 图的邻接矩阵表示是唯一的。！！！！
// 对于含有n个顶点的图，采用邻接矩阵存储时，无论是有向图还是无向图，也无论边的数目是多少，其存储空间均为O(n2)，
//所以邻接矩阵适合于存储边数较多的稠密图。
// 无向图的邻接矩阵一定是一个对称矩阵。因此在顶点个数n很大时可以采用对称矩阵的压缩存储方法减少存储空间。
// 对于无向图，邻接矩阵的第i行（或第i列）非零元素（或非∞元素）的个数正好是顶点i的度。
// 对于有向图，邻接矩阵的第i行（或第i列）非零元素（或非∞元素）的个数正好是顶点i的出度（或入度）。
// 用邻接矩阵方法存储图，确定任意两个顶点之间是否有边相连的时间为O(1)。

const int MAXV=100;			//图中最多的顶点数
const int INF=0x3f3f3f3f;		//用INF表示∞
class MatGraph				//图邻接矩阵类
{
public:
   int edges[MAXV][MAXV];		//邻接矩阵数组，假设元素为int类型
   int n,e;				//顶点数，边数
   string vexs[MAXV];			//存放顶点信息
   //图的基本运算算法
void CreateMatGraph(int a[][MAXV],int n,int e)
//通过a、n和e来建立图的邻接矩阵
{  this->n=n; this->e=e;		//置顶点数和边数,this代表matgrap类中的n,e
   for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
          this->edges[i][j]=a[i][j];
}

void DispMatGraph()		//输出图的邻接矩阵
{  for (int i=0;i<n;i++)
   {  for (int j=0;j<n;j++)
         if (edges[i][j]==INF)
            printf("%4s","∞");
         else
            printf("%4d",edges[i][j]);
      printf("\n");
   }
}
};

int test()
{  MatGraph g;
   int n=5,e=5;
   int a[MAXV][MAXV]={{0,8,INF,5,INF},{INF,0,3,INF,INF},
		            {INF,INF,0,INF,6},{INF,INF,9,0,INF},
                    {INF,INF,INF,INF,0}};
   g.CreateMatGraph(a,n,e);
   printf("g:\n"); 
   cout<<endl;
   g.DispMatGraph();
   return 0;
}
