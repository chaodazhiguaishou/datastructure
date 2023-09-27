#include <iostream>
#include <stdio.h>
#include <queue>
#include "../chap8.2.structtu/8.2.3.AdjGraph.cpp"
using namespace std;

// 首先访问起始点v。
// 接着访问顶点v的所有未被访问过的邻接点v1、v2、…、vt。
// 然后再按照v1、v2、…、vt的次序，访问每一个顶点的所有未被访问过的邻接点。
// 依次类推，直到图中所有和初始点v有路径相通的顶点或者图中所有已访问顶点的邻接点都被访问过为止。

// 图采用邻接表为存储结构，其广度优先遍历算法如下：
// 时间复杂度为O(n+e)。

//相当于两个循环，外部循环是遍历每个点，内部循环是遍历点的临接点

int visited[MAXV];			//全局数组

void BFS(AdjGraph& G,int v)		//广度优先遍历(邻接表)
{  int visited[MAXV];
   memset(visited,0,sizeof(visited)); //初始化visited数组
   queue<int> qu;			//定义一个队列
   cout << v << " ";			//访问顶点v
   visited[v]=1;			//置已访问标记
   qu.push(v);				//顶点v进队 
   while (!qu.empty())		//队列不空循环
   {  int u=qu.front(); qu.pop();	//出队顶点u
      ArcNode* p=G.adjlist[u].firstarc; //找顶点u的第一个邻接点
      while (p!=NULL)
      {  if (visited[p->adjvex]==0)	    //若u的邻接点未访问
         {  cout << p->adjvex << " ";    //访问邻接点
            visited[p->adjvex]=1;	    //置已访问标记
            qu.push(p->adjvex);	    //邻接点进队
         }
         p=p->nextarc;		    //找下一个邻接点
      }
   }
}

void BFSA(AdjGraph& G)		//非连通图的BFS
{  for (int i=0;i<G.n;i++)
      if (visited[i]==0)		//若顶点i没有访问过
         BFS(G,i);			//从顶点i出发广度优先遍历
}

// 无向连通图：一次遍历能够访问到图中的所有顶点。
// 无向非连通图：一次遍历只能访问到起始点所在连通分量中的所有顶点，其他连通分量中的顶点是不可能访问到的。
// 为此需要从其他每个连通分量中选择起始点，分别进行遍历，才能够访问到图中的所有顶点。

// 有向图，若从起始点到图中的其他每个顶点都有路径，则能够访问到图中的所有顶点。
// 否则不能访问到所有顶点，为此同样需要再选起始点，继续进行遍历，直到图中的所有顶点都被访问过为止。
