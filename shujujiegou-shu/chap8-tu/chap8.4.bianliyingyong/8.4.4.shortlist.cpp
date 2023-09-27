#include <iostream>
#include <stdio.h>
#include "../chap8.2.structtu/8.2.3.AdjGraph.cpp
#include <queue>
using namespace std;

// 【例8.10】假设图G采用邻接表存储，设计一个算法，求不带权图G中从顶点u到顶点v的一条最短路径长度。

// 图G是不带权图，一条边的长度计为1，则求顶点u到顶点v的最短路径就是求顶点u到v的边数最少的顶点序列，长度就是最短路径长度。
// 利用广度优先遍历算法，从u出发进行广度优先遍历，类似于从顶点u出发一层一层地向外伸展，
// 当第一次找到顶点v时队列中便包含了从顶点u到顶点v最短路径。
// 实际上不必在找到顶点v后再求最短路径长度，而是在求从顶点u到顶点v的伸展次数即可。

//为什么广度优先遍历找到的路径一定是最短路径呢？
// 广度优先遍历找到的路径上的每个顶点均为不同层次的顶点，所以该路径一定是最短路径。
// 深度优先遍历找到的路径上的顶点可能属于相同层次的顶点，所以不一定是最短路径。

struct QNode			//队列元素类型
{  int v;			//顶点编号
   int dis;			//源点到当前顶点的最短路径长度
   QNode() {}			//构造函数
   QNode(int v,int dis)	//重载构造函数
   {  this->v=v;
      this->dis=dis;
   }
};


class Solution
{
public:
int visited[MAXV];			//全局数组

int Shortdist(AdjGraph& G,int u,int v) 	//求u到v的最短路径长度
{  int visited[MAXV];							//访问标记数组
   memset(visited,0,sizeof(visited));
   queue<QNode> qu;								//定义一个队列qu
   visited[u]=1;									//置已访问标记
   qu.push(QNode(u,0));						//起始点u(距离为0)进队
   while (!qu.empty())							//队不空循环
   {  QNode e=qu.front(); qu.pop();		//出队一个元素e
      if (e.v==v)									//找到顶点v
         return e.dis;							//返回u到v的最短路径长度
      ArcNode* p=G.adjlist[e.v].firstarc;
      while (p!=NULL)
      {  int w=p->adjvex;						//找到u的邻接点w
         if (visited[w]==0)					//若顶点w没有访问
         {  visited[u]=1;						//置已访问标记
            qu.push(QNode(w,e.dis+1)); 	//邻接点w进队
         }
         p=p->nextarc;
      }
   }
   return INF;										//没有路径的情况
}

int Shortdist2(AdjGraph& G,int u,int v)	
//解法2：求u到v的最短路径长度
{	int visited[MAXV];							//访问标记数组
	memset(visited,0,sizeof(visited));
	int ans=0;										//存放最短路径长度(初始时为0)
	queue<int> qu;									//定义一个队列qu
	visited[u]=1;									//置已访问标记
	qu.push(u);										//起始点u进队
	while (!qu.empty())							//队不空循环
	{	int n=qu.size();							//求队列qu中元素个数n
		for(int i=0;i<n;i++)						//循环n次
		{	u=qu.front(); qu.pop();			//出队一个顶点u
			if (u==v)								//找到顶点v
				return ans;							//返回u到v的最短路径长度
			ArcNode* p=G.adjlist[u].firstarc;
			while (p!=NULL)
			{	int w=p->adjvex;					//找到u的邻接点w
				if (visited[w]==0)				//若顶点w没有访问
				{	visited[w]=1; 					//置已访问标记
					qu.push(w);						//邻接点w进队
				}
				p=p->nextarc;
			}
		}
		ans++; 										//一层的顶点扩展后ans增1
	}
	return INF;										//没有路径的情况
}

};

int main() {
    // insert code here...
};

