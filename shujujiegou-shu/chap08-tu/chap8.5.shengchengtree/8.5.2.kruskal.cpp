#include <iostream>
#include <stdio.h>
#include "../chap8.2.structtu/8.2.1.MatGraph.cpp"
using namespace std;

// 克鲁斯卡尔（Kruskal）算法是一种按权值的递增次序选择合适的边来构造最小生成树的方法。
// 假设G=(V，E)是一个具有n个顶点的带权连通图，T=(U，TE)是G的最小生成树，则构造最小生成树的步骤如下：
// （1）置U的初值等于V（即包含有G中的全部顶点），TE的初值为空集（即图T中每一个顶点都构成一个分量）。
// （2）将图G中的边按权值从小到大的顺序依次选取：若选取的边未使生成树T形成回路，则加入TE；否则舍弃，
//     直到TE中包含n-1条边为止。

//简单来说，就是去掉所有边先，然后以此加入不连通的边

// 2. 克鲁斯卡尔算法设计
// 关键是如何判断选择的边是否与生成树中已有边形成回路？
// 设置一个辅助数组vset[0..n-1]，其元素vset[i]代表顶点i所属的连通分量的编号（同一个连通分量中所有顶点的vset值相同）。
// 初始时T中只有n个顶点，没有任何边，每个顶点i看成一个连通分量，该连通分量的编号就是i，即vset[i]=i。
// 将图中所有边按权值递增排序，从前向后选边（保证总是选择权值最小的边），当选择一条边（u1，v1），
// 求出这两个顶点所属连通分量的编号分别为sn1和sn2：
// 若sn1=sn2，说明顶点u1和v1属于同一个连通分量,那么不能添加该边。
// 若sn1≠sn2，说明顶点u1和v1属于不同连通分量，那么添加该边。添加后原来的两个连通分量需要合并，
// 即将两个连通分量中所有顶点的vset值改为相同（改为sn1或者sn2均可）。
// 如此这样直到在T中添加n-1条边为止。


// 从图G的邻接矩阵中获取所有边向量E：
// 由于是无向图，将邻接矩阵上三角部分的所有边存放在边向量E中，每一条边对应的列表为[u，v，w]，
// 其中u、v分别为边的头尾顶点，w为边的权值。
// 对E按权值w递增排序后做上述操作。
// E的元素类型如下：
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

void Kruskal(MatGraph& g)		//Kruskal算法输出最小生成树
{  int vset[MAXV];			//建立数组vset
   vector<Edge> E;			//建立存放所有边的向量E
   for (int i=0;i<g.n;i++)		//由图的邻接矩阵g产生边向量E
      for (int j=0;j<g.n;j++)
         if (g.edges[i][j]!=0 && g.edges[i][j]!=INF && i<j)
            E.push_back(Edge(i,j,g.edges[i][j]));
   sort(E.begin(),E.end());		//对E按权值递增排序
   for (int i=0;i<g.n;i++) vset[i]=i;	//初始化辅助数组
   int k=1;				//k是当前构造生成树第几条边,初值为1
   int j=0;				//E中边的下标,初值为0
   while (k<g.n)			//生成的边数小于n时循环
   {  int u1=E[j].u;
      int v1=E[j].v;			//取一条边的起始和终止顶点
      int sn1=vset[u1];
      int sn2=vset[v1];		//分别得到两个顶点所属的集合编号
      if (sn1!=sn2)			//两顶点属不同集合,取该边
      {  cout<<"  边("<<u1<<","<<v1<<"),权为" << E[j].w << endl;
         k++;				//生成边数增1
         for (int i=0;i<g.n;i++)	//两个集合统一编号
            if (vset[i]==sn2)		//集合编号为sn2的改为sn1
               vset[i]=sn1;
      }
      j++;				//扫描下一条边
   }
}


int main() {
    // insert code here...
};


