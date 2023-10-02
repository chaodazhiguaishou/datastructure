#include <iostream>
#include <stdio.h>
#include "8.2.3.AdjGraph.cpp"
using namespace std;

// 【例8.3】一个含有n个顶点e条边的图采用邻接表存储，设计以下算法：
// （1）该图为无向图，求其中顶点v的度。
// （2）该图为有向图，求该图中顶点v的出度和入度。


class Solution
{
public:
int Degree1(AdjGraph& G,int v) 	//无向图邻接表G中求顶点v的度
{  int d=0;
   ArcNode* p=G.adjlist[v].firstarc;
   while (p!=NULL)			//统计单链表v中边结点个数
   {  d++;
      p=p->nextarc;
   }
   return d;
}

vector<int> Degree2(AdjGraph& G,int v) 
//有向图邻接表G中求顶点v的出度和入度
{  
    // vector<int> ans={0,0};   //报错'vector<int>'cannotbe initialized withan initializer list
    vector<int> ans;ans.push_back(0);ans.push_back(0);	//ans[0]累计出度,ans[1]累计入度
    ArcNode* p=G.adjlist[v].firstarc;
    while (p!=NULL)   			//统计单链表v中边结点个数
    {  ans[0]++;
        p=p->nextarc;
    }
    for (int i=0;i<G.n;i++)		//统计所有为v的边结点个数为v的入度
    {  p=G.adjlist[i].firstarc;
        while (p!=NULL)
        {  if (p->adjvex==v)
            {  ans[1]++;
                break;			//一个单链表最多只有一个这样的结点
            }
            p=p->nextarc;
        }
    }
    return ans;				//返回出度和入度
}

};

int main()
{  
    AdjGraph g1,g2;
    Solution s;
    int n=5,e=8;
    int a[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},
                {1,1,1,0,1},{1,0,1,1,0}};
    g1.CreateAdjGraph(a,n,e);
    printf("图G1(无向图)\n"); g1.DispAdjGraph();
    printf("求解结果\n");
    for (int i=0;i<g1.n;i++)
        printf("  顶点%d的度: %d\n",i,s.Degree1(g1,i));

    n=5; e=5;
    int b[MAXV][MAXV]={{0,8,INF,5,INF},{INF,0,3,INF,INF},
        {INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0}};
    g2.CreateAdjGraph(b,n,e);
    printf("图G2(有向图)\n"); g2.DispAdjGraph();
    printf("求解结果\n");
    for (int i=0;i<g2.n;i++)
    {  vector<int> ans=s.Degree2(g2,i);
        printf("  顶点%d: 出度=%d 入度=%d 度=%d\n",
                i,ans[0],ans[1],ans[0]+ans[1]);
    }
    return 0;
}
