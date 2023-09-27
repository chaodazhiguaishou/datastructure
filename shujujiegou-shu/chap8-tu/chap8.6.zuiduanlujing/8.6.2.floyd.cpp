#include <iostream>
#include <stdio.h>
#include "../chap8.2.structtu/8.2.1.MatGraph.cpp"
using namespace std;

// 1. 弗洛伊德算法过程(多源最短路径算法)
// （1）假设有向图G=(V,E)采用邻接矩阵g表示，另外设置一个二维数组A用于存放当前顶点之间的最短路径长度，
// 即分量A[i][j]表示当前顶点i到顶点j的最短路径长度。
// （2）弗洛伊德算法的基本思想是递推产生一个矩阵序列A0、A1、…、Ak、…、An-1，
// 其中Ak[i][j]表示从顶点i到顶点j的路径上所经过的顶点编号不大于k的最短路径长度。(按顶点编号顺序进行迭代)
// 归纳起来，弗洛伊德思想可用如下的表达式来描述：
// A-1[i][j]=g.edges[i][j]
// Ak[i][j]=MIN{Ak-1[i][j],Ak-1[i][k]+Ak-1[k][j]}  0≤k≤n-1
// 另外用二维数组path保存最短路径，它与当前迭代的次数有关。
// pathk[i][j]在考虑顶点k时得到的从顶点i到顶点j的最短路径的前驱顶点。

//简单来说两个矩阵，A[][]存最短路径长度，path[][]存前驱节点
//然后加入递推节点k，比对i,j,k这个三角形，i->j哪个路径更短。遍历矩阵进行修改，而后k++。

void Floyd(MatGraph& g)		//Floyd求多源最短路径
{  int A[MAXV][MAXV];			//建立A数组
   int path[MAXV][MAXV];		//建立path数组
   for (int i=0;i<g.n;i++)		//给数组A和path置初值]
      for (int j=0;j<g.n;j++) 
      {  A[i][j]=g.edges[i][j];
         if (i!=j && g.edges[i][j]<INF)
            path[i][j]=i;		//i和j顶点之间有一条边时
         else	
            path[i][j]=-1;		//i和j顶点之间没有一条边时
      }
    
    //初始化完毕，递推k
   for (int k=0;k<g.n;k++)			//求Ak[i][j]
   {  for (int i=0;i<g.n;i++)
         for (int j=0;j<g.n;j++)
             if (A[i][j]>A[i][k]+A[k][j])
             {  A[i][j]=A[i][k]+A[k][j];
                path[i][j]= path[k][j];	//修改最短路径
             }
   }
   Dispath(A,path,g.n);			//输出最短路径和长度
}

void Dispath(int A[][MAXV],int path[][MAXV],int n)
//输出所有的最短路径和长度
{  for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
      {  if (A[i][j]!=INF && i!=j)	//若顶点i和j之间存在路径
         {  vector<int> apath;	//存放一条i到j的最短逆路径
            printf("顶点%d到%d的最短路径长度:%d\t路径:",i,j,A[i][j]);
            apath.push_back(j);	//路径上添加终点j
            int pre=path[i][j];
            while (pre!=i)		//路径上添加中间点
            {  apath.push_back(pre);	//顶点pre加入到路径中
               pre=path[i][pre];
            }
            cout << i;		      //输出起点i
            for (int k=apath.size()-1;k>=0;k--)
                printf("->%d",apath[k]);  //反向输出路径上的其他顶点
            printf("\n");
         }
      }
}


int main() {
    // insert code here...
};

//上述弗洛伊德算法中有三重循环，其时间复杂度为O(n3)。
// 提示：弗洛伊德算法适合含负权的图求最短路径；不适合含负权回路的图求最短路径
