#include <iostream>
#include <stdio.h>
#include<cstring>
#include "../chap8.2.structtu/8.2.3.AdjGraph.cpp
using namespace std;

// 【例8.6】假设图G采用邻接表存储，设计一个算法求顶点u到顶点v之间的一条简单路径（假设两顶点之间存在一条或多条简单路径）。
// 并对于以下有向图，求从顶点0到顶点4的一条简单路径。
// 简单路径定义：若一条路径上除开始点和结束点可以相同外，其余顶点均不相同，则称此路径为简单路径。

//思路：使用vector向量path存放一条路径

class Solution
{
public:
int visited[MAXV];			//全局数组
void FindaPath11(AdjGraph& G,int u,int v,vector<int> path)
//被FindaPath1调用
{  visited[u]=1;
   path.push_back(u);			//顶点u加入到路径中
   if (u==v)				//找到一条路径后输出并返回
   {  for (int i=0;i<path.size();i++)
          printf("%d ",path[i]);
      printf("\n");
      return;
   }
   ArcNode* p=G.adjlist[u].firstarc; //准备找u的临接点
   while (p!=NULL)
   {  int w=p->adjvex;		//找到u的邻接点w
      if (visited[w]==0)		//若顶点w没有访问
         FindaPath11(G,w,v,path);	//从w出发继续查找
      p=p->nextarc;
   }
}

void FindaPath1(AdjGraph& G,int u,int v)
//求u到v的一条简单路径:直接输出
{  memset(visited,0,sizeof(visited)); //初始化数组
   vector<int> path;			 //path存放搜索路径
   FindaPath11(G,u,v,path);
}


};

int main() {
    // insert code here...
};