#include <iostream>
#include <stdio.h>
#include "../chap8.2.structtu/8.2.1.MatGraph.cpp"
using namespace std;

//1. 狄克斯特拉算法过程(单源最短路径算法)
//给定一个带权图G和一个起始点即源点v，狄克斯特拉算法的具体步骤如下：
// （1）初始化：顶点集S只包含源点，即S={v}，顶点集U包含除v外的其他顶点。
// （2）从U中选取一个顶点u，它是源点v到U中最短路径长度最小的顶点，然后把顶点u加入S中    
// （此时求出了源点v到顶点u的最短路径长度）。
// （3）以顶点u为新考虑的中间点，修改顶点u的出边邻接点j的最短路径长度，此时源点v到顶点j的最短路径有两条，
//  即一条经过顶点u，一条不经过顶点u：
// （4）重复步骤（2）和（3）直到S包含所有的顶点即U为空。

//  简单来说，就是从初始点挨个考虑出边权值加入集合，与此同时同步计算初始点与每个点的最短路径长度及最短路径前缀
//  直到集合成为全集

//2. 狄克斯特拉算法设计
// （1）判断顶点i属于哪个集合，设置一个数组S，S[i]=1表示顶点i属于S集合，S[i]=0表示顶点i属于U集合。
// （2）保存最短路径长度，设置一个数组dist[0..n-1]，dist[i]用来保存从源点v到顶点i的最短路径长度。
// （3）保存最短路径，设置一个数组path[0..n-1]，其中path[i]存放从源点v到顶点i的最短路径。
//  为什么能够用一个一维数组保存多条最短路径呢？
//  path[j]只保存源点v到顶点j的最短路径上顶点j的前驱顶点
//  因为v -> ... -> u -> j 只要v->j是最短路径,v->u也一定是最短路径


void Dijkstra(MatGraph& g,int v)	//求从v到其他顶点的最短路径
{  int dist[MAXV];			//建立dist数组
   int path[MAXV];			//建立path数组
   int S[MAXV];				//建立S数组
   for (int i=0;i<g.n;i++)
   {  dist[i]=g.edges[v][i];		//距离初始化
      S[i]=0;				//S[]置空
      if (g.edges[v][i]!=0 && g.edges[v][i]<INF)
         path[i]=v;			//v到i有边时，置i的前驱顶点为v
      else
         path[i]=-1;			//v到i没边时，置i的前驱顶点为-1
   }
   S[v]=1;				//源点编号v放入S中
   int mindis,u=-1;
   for (int i=0;i<g.n-1;i++)		//循环向S中添加n-1个顶点
   {  mindis=INF;			//mindis置最小距离初值
      for (int j=0;j<g.n;j++)		//选取不在S中且具有最小距离的顶点u
         if (S[j]==0 && dist[j]<mindis) 
         {  u=j;
            mindis=dist[j];
         }
      S[u]=1;				//顶点u加入S中
      for (int j=0;j<g.n;j++)		//修改不在s中的顶点的距离
         if (S[j]==0)
            if (g.edges[u][j]<INF && dist[u]+g.edges[u][j]<dist[j])
	    {  dist[j]=dist[u]+g.edges[u][j];
               path[j]=u;
	    }
   }
   DispAllPath(dist,path,S,v,g.n);	//输出所有最短路径及长度
}

void DispAllPath(int dist[],int path[],int S[],int v,int n)
//输出从顶点v出发的所有最短路径
{  for (int i=0;i<n;i++)		//循环输出从顶点v到i的路径
     if (S[i]==1 && i!=v)
     {  vector<int> apath;		//存放一条最短逆路径
        printf("  从%d到%d最短路径长度为: %d\t路径: ",v,i,dist[i]);
        apath.push_back(i);		//添加终点i
        int pre=path[i];
        while (pre!=v)
        {  apath.push_back(pre);
           pre=path[pre];
        }
        printf("%d",v);		//先输出起点v
        for (int k=apath.size()-1;k>=0;k--)	
           printf("->%d",apath[k]);	//再反向输出路径中其他顶点
        printf("\n");
     }
     else printf("  从%d到%d没有路径\n",v,i);
}


int main() {
    // insert code here...
};


//提示：Dijkstra算法不适合含负权的图求最短路径

// 利用dist和path求最短路径长度和最短路径
// 求最短路径长度：
// 直接在dist[]中找到
// 求最短路径：
// 根据path[]前缀不断往前推直到初始点
// 结论：
// 1.按顶点进入S的先后顺序，最短路径长度越来越长。
// 2.一个顶点一旦进入S后，其最短路径长度不再改变（调整）。

// 3*. 改进的狄克斯特拉算法设计
// 前面的狄克斯特拉算法从两个方面进行优化，这里仅仅输出最短路径长度：
// 1.采用邻接表存储图，可以更快地查找到顶点u的所有邻接点并进行调整，时间为O(MAX(图中顶点的出度))。
// 2.求目前一个最短路径长度的顶点u时，Dijkstra1算法采用简单比较方法，可以改为采用优先队列（小根堆）求解。
// 由于最多e条边进队，对应的时间为O(log2e)。算法的最坏时间复杂度为O(elog2e)

