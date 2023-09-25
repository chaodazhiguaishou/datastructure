#include<iostream>
using namespace std;

// 【实战7.5 】HDU1232—畅通工程问题。
//    问题描述：某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。问最少还需要建设多少条道路？ 
//    输入格式：测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，分别是城镇数目N（N<1000）和道路数目M，随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从1到N编号。注意两个城市之间可以有多条道路相通，也就是说：
//    3 3
//    1 2
//    1 2
//    2 1
// 这种输入也是合法的。当N为0时，输入结束，该用例不被处理。

// 输出格式：对每个测试用例，在一行里输出最少还需要建设的道路数目。 
// 输入样例：
// 4 2
// 1 3
// 4 3
// 3 3
// 1 2
// 1 3
// 2 3
// 5 2
// 1 2
// 3 5
// 999 0
// 0
// 输出样例：
// 1
// 0
// 2
// 998

// 要使全省任何两个城镇间都实现交通，最少的道路是所有城镇之间都有一条路径，即全部城镇构成一棵树。
// 采用并查集求解，由输入构造并查集，每棵子树中的所有城镇是有路径的，求出其中子树的个数ans，
// 那么最少还需要建设的道路数就是ans-1。


const int MAXN=1005; 
int parent[MAXN];		        //并查集存储结构
int rnk[MAXN];			        //存储结点的秩
int n;					//n个城镇
int m;					//m条道路
void Init()				//并查集初始化
{  for (int i=1;i<=n;i++)
   {  parent[i]=i;
      rnk[i]=0;
   }
}

int Find(int x)	      		//并查集中查找x结点的根结点
{  if (x!=parent[x])
      parent[x]=Find(parent[x]);	//路径压缩 
   return parent[x];
}

void Union(int x,int y)	//并查集中x和y的两个集合的合并
{  int rx=Find(x);
   int ry=Find(y);
   if (rx==ry)			//x和y属于同一棵树的情况 
      return;
   if (rnk[rx]<rnk[ry])
      parent[rx]=ry;		//rx结点作为ry的孩子 
   else
   {  if (rnk[rx]==rnk[ry])	//秩相同，合并后rx的秩增1
        rnk[rx]++;
      parent[ry]=rx;		//ry结点作为rx的孩子  
   }
}

int main()
{  while(~scanf("%d",&n))
   {  if(n==0) break;
      scanf("%d",&m);
      Init();				//初始化
      for (int i=1;i<=m;i++)		//输入m条边
      {  int a,b;
         scanf("%d%d",&a,&b);
         Union(a,b);
      }
      int ans=0;
      for (int i=1;i<=n;i++)   	//求子树个数ans
          if (parent[i]==i)
             ans++;
      printf("%d\n",ans-1);       	//结果为ans-1
   }
}
