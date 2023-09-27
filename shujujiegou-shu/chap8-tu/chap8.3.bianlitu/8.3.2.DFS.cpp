#include <iostream>
#include <stdio.h>
#include "../chap8.2.structtu/8.2.3.AdjGraph.cpp"

using namespace std;


// 从图中某个起始点v出发进行深度优先搜索—DFS(v) ，首先访问初始顶点v。
// 然后选择一个与顶点v邻接且没被访问过的顶点w为初始顶点，再从w出发进行深度优先搜索—DFS(w)，
// 直到图中与当前顶点v邻接的所有顶点都被访问过为止。

// 图采用邻接表为存储结构，其深度优先遍历算法如下（其中，v是起始点编号，visited是全局数组）：
// 时间复杂度为O(n+e)。


int visited[MAXV];			//全局数组
void DFS(AdjGraph& G,int v)		//深度优先遍历(邻接表)
{  cout << v << " ";			//访问顶点v
   visited[v]=1;			//置已访问标记
   ArcNode*p=G.adjlist[v].firstarc;	//p指向顶点v的第一个邻接点
   while (p!=NULL)
   {  int w=p->adjvex;		//邻接点为w
      if (visited[w]==0) DFS(G,w);	//若w顶点未访问,递归访问它
      p=p->nextarc;			//p置为下一个邻接点
   }
}


void DFSA(AdjGraph& G)		//非连通图的DFS
{  for (int i=0;i<G.n;i++)
      if (visited[i]==0)		//若顶点i没有访问过
         DFS(G,i);			//从顶点i出发深度优先遍历
}

// 无向连通图：一次遍历能够访问到图中的所有顶点。
// 无向非连通图：一次遍历只能访问到起始点所在连通分量中的所有顶点，其他连通分量中的顶点是不可能访问到的。
// 为此需要从其他每个连通分量中选择起始点，分别进行遍历，才能够访问到图中的所有顶点。

// 有向图，若从起始点到图中的其他每个顶点都有路径，则能够访问到图中的所有顶点。
// 否则不能访问到所有顶点，为此同样需要再选起始点，继续进行遍历，直到图中的所有顶点都被访问过为止。
int main(){
    return 0;
}