#include <iostream>
#include <stdio.h>
#include<cstring>
#include "../chap8.2.structtu/8.2.3.AdjGraph.cpp"
using namespace std;

// 【例8.9】假设图G采用邻接表存储，设计一个算法求顶点u到顶点v之间的所有简单路径（假设两顶点之间存在一条或多条简单路径）。
// 并对于以下有向图，求从顶点0到顶点5的所有简单路径。

// 用path存放一条路径，每次找到终点就输出，这样得到所有的路径。
// 采用带回溯的深度优先遍历方法。
// 该算法跟找其中一条简单路径的唯一区别是在多了两行重制代码
// 如果找到了立刻进行回溯,重置visited[u]为0，这样递归回溯的时候会继续找下一条
// 如果没找到则在循环体外的最后！！进行回溯,重置visited[u]为0，避免程序一直循环

class Solution
{
public:
int visited[MAXV];			//全局数组

void FindallPath11(AdjGraph& G,int u,int v,vector<int> path)
//被FindallPath1调用
{  visited[u]=1;
   path.push_back(u);			//顶点u加入到路径中
   if (u==v)				//找到一条路径后输出并返回
   {  for (int i=0;i<path.size();i++)
        printf("  %d",path[i]);
      printf("\n");
      visited[u]=0;			//回溯,重置visited[u]为0
      return;
   }
   ArcNode* p=G.adjlist[u].firstarc;
   while (p!=NULL)
   {  int w=p->adjvex;		//找到u的邻接点w
      if (visited[w]==0)		//若顶点w没有访问
         FindallPath11(G,w,v,path);	//从w出发继续查找 
      p=p->nextarc;
   }
   visited[u]=0;			//回溯,重置visited[u]为0
}

void FindallPath1(AdjGraph& G,int u,int v)
//解法1：求u到v的所有简单路径
{  memset(visited,0,sizeof(visited));
   vector<int> path;			//path存放搜索路径
   FindallPath11(G,u,v,path);
}



};

int main() {
    // insert code here...
};