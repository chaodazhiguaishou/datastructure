#include <iostream>
#include <stdio.h>
#include "../chap8.2.structtu/8.2.1.MatGraph.cpp"
#include "./7.9.1.bingchaji.cpp"
using namespace std;

// 改进的克鲁斯卡尔（Kruskal）算法
//利用并查集的克鲁斯卡尔算法

int parent[MAXV];		//并查集存储结构
int rnk[MAXV];			//存储结点的秩

struct Edge					//边向量元素类型
{  int u;					//边的起始顶点
   int v;					//边的终止顶点
   int w;					//边的权值
   Edge(int u,int v,int w)			//构造函数
   {  this->u=u;
      this->v=v;
      this->w=w;
   }
   bool operator<(const Edge& s) const	//重载<运算符
   {
      return w<s.w;				//用于按w递增排序
   }
};

void Init(int n)		//并查集初始化
{  for (int i=0;i<n;i++)	//顶点编号0到n-1 
   {  parent[i]=i;
      rnk[i]=0;
   }
}
//并查集初始化、查找和合并算法


void Kruskal1(MatGraph& g)	//改进的Kruskal算法输出最小生成树
{  vector<Edge> E;			//建立存放所有边的向量E
   for (int i=0;i<g.n;i++)		//由图的邻接矩阵g产生边向量E
      for (int j=i+1;j<g.n;j++)
         if (g.edges[i][j]!=0 && g.edges[i][j]!=INF)
            E.push_back(Edge(i,j,g.edges[i][j]));
   sort(E.begin(),E.end());		//对E按权值递增排序
   Init(g.n);				//并查集初始化
   int k=1;			//k表示当前构造生成树的第几条边,初值为1
   int j=0;			//E中边的下标,初值为0
   while (k<g.n)		//生成的边数小于n时循环
   {  int u1=E[j].u;
      int v1=E[j].v;		//取一条边的起始和终止顶点
      int sn1=Find1(u1);
      int sn2=Find1(v1);	//分别得到两个顶点所属的集合编号
      if (sn1!=sn2)		//两顶点属不同集合,取该边
      {  cout<<"  边("<<u1<<","<<v1<<"),权为"<<E[j].w<<endl;
         k++;			//生成边数增1
         Union(sn1,sn2);		//合并
      }
      j++;			//扫描下一条边
   }
}


int main() {
    // insert code here...
};


