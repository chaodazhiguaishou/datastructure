#include <iostream>
#include <stdio.h>
#include "../chap8.2.structtu/8.2.3.AdjGraph.cpp"
using namespace std;

//【例8.4】假设图采用邻接表存储，设计一个算法，判断一个无向图是否连通。若连通则返回true；否则返回false。


class Solution
{
public:
int visited[MAXV];			//全局数组
void DFS(AdjGraph& G,int v)		//深度优先遍历(邻接表)
{  visited[v]=1;			//置已访问标记（不输出v）
   ArcNode*p=G.adjlist[v].firstarc;	//p指向顶点v的第一个邻接点
   while (p!=NULL)
   {  int w=p->adjvex;		//邻接点为w
      if (visited[w]==0)
         DFS(G,w);			//若w顶点未访问,递归访问它
      p=p->nextarc;			//p置为下一个邻接点
   }
}

bool Connect(AdjGraph& G)		//判断无向图G的连通性
{  memset(visited,0,sizeof(visited));
   DFS(G,0);				//从0出发深度优先遍历
   for (int i=0;i<G.n;i++)
       if (visited[i]==0)		//若有顶点没有访问过
          return false;		//说明是非连通图 
   return true;			//所有顶点均访问说明是连通图
}

};

int main() {
    // insert code here...
};