#include <iostream>
#include <stdio.h>
#include "../chap8.2.structtu/8.2.1.MatGraph.cpp"
using namespace std;

// 普里姆（Prim）算法是一种构造性算法。假设G=(V，E)是一个具有n个顶点的带权连通图，T=(U，TE)是G的最小生成树，
// 其中U是T的顶点集，TE是T的边集，则由G构造从起始点v出发的最小生成树T的步骤如下：
// （1）初始化U={v}。以v到其他顶点的所有边为候选边。
// （2）重复以下步骤n-1次，使得其他n-1个顶点被加入到U中：
//    ① 从候选边中挑选权值最小的边加入TE（所有候选边一定是连接两个顶点集U和V-U的边），设该边在V-U中的顶点是k，
//       将顶点k加入U中。
//    ② 考察当前V-U中的所有顶点j，修改候选边：若(k，j)的权值小于原来和顶点j关联的候选边，则用(k，j)取代后者作为候选边。

// 简单来说，就是循环“候选边选最短-重新筛选候选边”逐个加点选线，直到生成最小生成树

// 2. 普里姆算法设计
// 采用邻接矩阵存储图。为了记录V-U中每个顶点j到U的最小边，建立两个数组closest和lowcost：
// closest[j]表示该最小边在U中的顶点。
// lowcost[j]表示该边的权值。


void Prim(MatGraph g,int v)		//Prim算法输出的最小生树
{  int lowcost[MAXV];			//建立数组lowcost，表示候选边的权值。
   int closest[MAXV];			//建立数组closest，表示候选边对应在U中的顶点。
   for (int i=0;i<g.n;i++)		//初始化，给lowcost[]和closest[]置初值，默认对矩阵一行遍历
   {  lowcost[i]=g.edges[v][i]; //权值即矩阵中对应的值
      closest[i]=v;             //初始的U对应顶点一定是U中目前唯一的v
   }

   //初始化完毕，开始执行算法
   for (int i=1;i<g.n;i++)		//找出(n-1)个顶点
   {  int min=INF;      //min记录最小的权值
      int k=-1;			//k记录最近顶点的编号

      for (int j=0;j<g.n;j++)		//在(V-U)中找出离U最近的顶点k
         if (lowcost[j]!=0 && lowcost[j]<min)
         {  min=lowcost[j];
            k=j;
         }
      cout << "  边("<<closest[k]<<","<<k<< "),权为"<<min<<endl;
      lowcost[k]=0;			//标记k已经加入U，权值为0不会加入上述判断
      
      //两个集合变动了，候选边也要变动
      for (int j=0;j<g.n;j++)		//修改数组lowcost和closest
         if (lowcost[j]!=0 && g.edges[k][j]<lowcost[j]) //遍历对比(k,j)和j原来相关的候选边(v,j)
         {  lowcost[j]=g.edges[k][j];                   //(k,j)更小，则长度修改为更小的长度
            closest[j]=k;                               //在U中的对应边也修改为k
         }
    }
}


int main() {
    // insert code here...
};


// 上述普里姆算法中有两重for循环，所以时间复杂度为O(n2)，其中n为图的顶点个数。
// 由于与e无关，所以普里姆算法特别适合于稠密图求最小生成树。

