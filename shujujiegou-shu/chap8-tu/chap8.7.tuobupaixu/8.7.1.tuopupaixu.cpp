#include <iostream>
#include <stdio.h>
#include <stack>
#include "../chap8.2.structtu/8.2.3.AdjGraph.cpp"
using namespace std;

// 1.拓扑排序算法原理
// （1）从有向图中选择一个没有前驱（即入度为0）的顶点并且输出它。
// （2）从图中删去该顶点，并且删去从该顶点发出的全部有向边。
// （3）重复上述两步，直到剩余的图中不再存在没有前驱的顶点为止。

//2.拓扑排序算法设计
// 在设计拓扑排序算法时，假设给定的有向图采用邻接表作为存储结构。
// 需要考虑顶点的入度，为此设计一个ind数组，ind[i]存放顶点i的入度，先通过邻接表G求出ind。
// 拓扑排序是设计要点如下：
// （1）在某个时刻，可以有多个入度为0的顶点，为此设置一个栈st，以存放多个入度为0的顶点，栈中的顶点的都是入度为0的顶点。
// （2）出栈顶点i时，将顶点i输出，同时删去该顶点的所有出边，实际上没有必要真的删去这些出边，
//     只需要将顶点i的所有出边邻接点的入度减1就可以了。

void TopSort(AdjGraph& G)		//拓扑排序
{  stack<int> st;			//定义一个栈
   int ind[MAXV];			//记录每个顶点的入度
   memset(ind,0,sizeof(ind));
   ArcNode* p;
   for (int i=0;i<G.n;i++)		//求所有顶点的入度
   {  p=G.adjlist[i].firstarc;
      while (p!=NULL)			//处理顶点i的所有出边
      {  int w=p->adjvex;		//存在有向边<i,w>
         ind[w]++;			//顶点w的入度增1
         p=p->nextarc;
      }
   }

   for (int i=0;i<G.n;i++)		//将所有入度为0的顶点进栈
      if (ind[i]==0)
         st.push(i);
   while (!st.empty())		//栈不为空时循环
   {  int i=st.top(); st.pop();	//出栈一个顶点i
      printf("%d ",i);		//输出拓扑序列中的一个顶点i
      p=G.adjlist[i].firstarc;	//找顶点i的第一个邻接点
      while (p!=NULL)
      {  int w=p->adjvex;		//邻接点为w 
         ind[w]--;			//顶点w的入度减1
         if (ind[w]==0)		//入度为0的邻接点w进栈
            st.push(w);
         p=p->nextarc;		//找下一个邻接点
      }
   }
}


int main() {
    // insert code here...
};


//时间复杂度为O(n+e)。
//提示：拓扑排序中栈仅仅用于存放所有入度为0的顶点，不必考虑先后顺序，可以用队列替代栈。
