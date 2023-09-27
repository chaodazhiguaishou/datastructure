#include <iostream>
#include <stdio.h>
#include<cstring>
#include "../chap8.2.structtu/8.2.3.AdjGraph.cpp"
using namespace std;

// 【例8.5】假设图G采用邻接表存储，设计一个算法判断顶点u到顶点v之间是否有路径。并对于以下有向图，
// 判断从顶点0到顶点5、从顶点0到顶点2是否有路径。


//运用深度优先，u到v先找u的临接点，以此深度优先
class Solution
{
public:
int visited[MAXV];				//全局数组
bool HasPath1(AdjGraph& G,int u,int v)	//被HasPath方法调用
{  
   visited[u]=1;
   ArcNode* p=G.adjlist[u].firstarc;  //准备找u的临接点
   while (p!=NULL)
   {  int w=p->adjvex;			//找到u的邻接点w
      if (w==v)				//找到目标点后返回真
         return true;				//表示u到v有路径
      else if (visited[w]==0)			//若顶点w没有访问
      {  if (HasPath1(G,w,v))			//找到路径<u,w>+w→v
            return true;
      }
      p=p->nextarc;     //根据DFS,处理了u的临接点准备处理u的下一个临接点
   }
   return false;
}

};

int main() {
    // insert code here...
};