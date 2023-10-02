#include <iostream>
#include <stdio.h>
#include "8.2.1.linjiejuzhentu.cpp"
using namespace std;

// 【例8.2】一个含有n个顶点e条边的图采用邻接矩阵g存储，设计以下算法：
// （1）该图为无向图，求其中顶点v的度。
// （2）该图为有向图，求该图中顶点v的出度和入度。

//该题目意思是已知邻接矩阵g，且要求出每个顶点的度
//那么显然无向图中有n个1，就有n条边，其中一半是矩阵对称的；而i行的1数量就是i的度
//无向图有n个1，就有n条边；同样的，i行的1数量就是i的出度，j列的1数量就是j的入度

class Solution
{
public:
int Degree1(MatGraph& g,int v)  //无向图邻接矩阵g中求顶点v的度
{  int d=0;
   for (int j=0;j<g.n;j++)	   //统计第v行的非0非∞元素个数，注意矩阵初始化后的有效大小
      if (g.edges[v][j]!=0 && g.edges[v][j]!=INF)
         d++;
   return d;
}

vector<int> Degree2(MatGraph& g,int v) 
//有向图邻接矩阵g中求顶点v的出度和入度
{  
    vector<int> ans;
    ans.push_back(0);ans.push_back(0);		//ans[0]累计出度,ans[1]累计入度
    for (int j=0;j<g.n;j++)		//统计第v行的非0非∞元素个数为出度
        if (g.edges[v][j]!=0 && g.edges[v][j]!=INF)
            ans[0]++;
    for (int i=0;i<g.n;i++)		//统计第v列的非0非∞元素个数为入度
        if (g.edges[i][v]!=0 && g.edges[i][v]!=INF)
            ans[1]++;
    return ans;				//返回出度和入度
}

};

int main()
{  
    MatGraph g1,g2;
    Solution s;
    int n=5,e=8;
    int a[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},
                {1,1,1,0,1},{1,0,1,1,0}};
    g1.CreateMatGraph(a,n,e);
    printf("图G1(无向图)\n"); g1.DispMatGraph();
    printf("求解结果\n");
    for (int i=0;i<g1.n;i++)
        printf("  顶点%d的度: %d\n",i,s.Degree1(g1,i));

    n=5; e=5;
    int b[MAXV][MAXV]={{0,8,INF,5,INF},{INF,0,3,INF,INF},
        {INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0}};
    g2.CreateMatGraph(b,n,e);
    printf("图G2(有向图)\n"); g2.DispMatGraph();
    printf("求解结果\n");
    for (int i=0;i<g2.n;i++)
    {  vector<int> ans=s.Degree2(g2,i);
        printf("  顶点%d: 出度=%d 入度=%d 度=%d\n",
                i,ans[0],ans[1],ans[0]+ans[1]);
    }
    return 0;
}
