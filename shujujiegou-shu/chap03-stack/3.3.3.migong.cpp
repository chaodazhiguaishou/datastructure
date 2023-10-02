#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

//涉及while循环++，一定要考虑是先++再执行，还是先执行再++
//迷宫选择当前块方向，为了避免重蹈覆辙，一定要先++再执行

//4*4的迷宫
//数组名[ 行数 ][列数] 
int MAX=4;
int mg[4][4]=
{{0,1,0,0},
 {0,0,1,1},
 {0,1,0,0},
 {0,0,0,0}
};
int m=4,n=4;

//规定从12点钟方向为方向0，顺时针以此为1，2，3
int dx[]={-1,0,1,0};   	//x方向的偏移量
int dy[]={0,1,0,-1};   	//y方向的偏移量


struct Box				//方块类型
{  int i;				//方块的行号
   int j;				//方块的列号
   int di;				//di是下一个相邻可走方位的方位号
   Box() {}				//构造函数
   Box(int i1,int j1,int d1):
	i(i1),j(j1),di(d1) {}  	//重载构造函数
};

class Solution
{
public:

bool mgpath(int xi,int yi,int xe,int ye)
//求一条从(xi,yi)到(xe,ye)的迷宫路径
{  int i,j,di,i1,j1;
   bool find;
   Box b,b1;
   stack<Box> st;			//建立一个栈
   b=Box(xi,yi,-1);
   st.push(b);				//入口方块进栈
   mg[xi][yi]=-1;			//为避免来回找相邻方块置mg值为-1
   
   while (!st.empty())		//栈不空时循环
   {  b=st.top();			//取栈顶方块,称为当前方块
      if (b.i==xe && b.j==ye)		//输出栈中所有方块构成一条路径
      {  disppath(st);
         return true;			//找到一条路径后返回true
      }
     find=false;			//否则继续找路径
     di=b.di;
     while (di<3 && find==false)	//找b的一个相邻可走方块
     {  di++;				//找下一个方位的相邻方块
     //!!!!!
     //为什么di初值要赋为-1，且是先++再运算
     //表示先进行换方向再检验，
     //如果初值0先运算再++可能会出现找到下一个有效临块但是不是答案，回到当前块后重蹈覆辙又去
     //
        i=b.i+dx[di];			//找b的di方位的相邻方块(i,j)
        j=b.j+dy[di];
        if (i>=0 && i<m && j>=0 && j<n && mg[i][j]==0)
           find=true;			//(i,j)方块有效且可走
     }

     if (find)				//找到一个相邻可走方块(i,j)
     {  st.top().di=di;		//修改栈顶方块的di为新值
        b1=Box(i,j,-1);		//建立相邻可走方块(i,j)的对象b1
        st.push(b1);			//b1进栈 
        mg[i][j]=-1;			//为避免来回找相邻方块置mg值为-1
     }
     else				//栈顶方块没有找到任何相邻可走方块
     {  mg[b.i][b.j]=0;		//恢复栈顶方块的迷宫值
        st.pop();			//将栈顶方块退栈
     }
   }
   return false;			//没有找到迷宫路径,返回false
}

void disppath(stack<Box>& st)	  //输出栈中所有方块构成一条迷宫路径
{  Box b;
   vector<Box> apath;			  //存放一条迷宫路径
   while (!st.empty())		  //出栈所有的方块
   {  b=st.top(); st.pop();
      apath.push_back(b);
   }
//    reverse(apath.begin(),apath.end());//逆置apath(也可反向输出apath)
//    cout << "一条迷宫路径: ";
//    for (int i=0;i<apath.size();i++)
//       cout << "[" << apath[i].i << "," << apath[i].j << "]  "; 
//    cout << endl;
    cout << "一条迷宫路径: ";
    for(int i=apath.size()-1;i>-1;i--)
        cout << "[" << apath[i].i << "," << apath[i].j << "]  ";
}


};

int main()
{  
    Solution s;
    int xi=0,yi=0,xe=3,ye=3;
    printf("求(%d,%d)到(%d,%d)的迷宫路径\n",xi,yi,xe,ye);
    if (!s.mgpath(xi,yi,xe,ye))
        cout << "不存在迷宫路径\n";
    return 0;
};
