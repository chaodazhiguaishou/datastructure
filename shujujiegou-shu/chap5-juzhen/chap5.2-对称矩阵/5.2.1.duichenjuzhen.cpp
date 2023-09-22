#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

//对称矩阵（a[i][j]=a[j][i]）如果采用按行优先存储
//那么以下三角+主对角线压缩存储而言 a[i][j] 想存储到 b[k]
//k = i(i + 1)/2 +j（即看对于aij而言前面有多少个元素）
//k = j(j + 1)/2 +i（直接对称）

//设计算法，实现两个用压缩形式存储的对称矩阵A和B的加法和乘法。

#define N 4
#define M 10
int value(int a[],int i,int j)
{
    if (i>=j)
        return a[(i*(i+1))/2+j];
    else
        return a[(j*(j+1))/2+i];
}
void madd(int a[],int b[],int c[][N])
{
    int i,j;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            c[i][j]=value(a,i,j)+value(b,i,j);
}
void mult(int a[],int b[],int c[][N])
{
    int i,j,k,s;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            s=0;
            for (k=0; k<N; k++)
                s=s+value(a,i,k)*value(b,k,j);
            c[i][j]=s;
        }
}
void disp1(int a[])
{
    int i,j;
    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
            printf("%4d",value(a,i,j));
        printf("\n");
    }
}
void disp2(int c[][N])
{
    int i,j;
    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
            printf("%4d",c[i][j]);
        printf("\n");
    }
}
int main()
{
    int a[M]= {1,2,3,4,5,6,7,8,9,10};  //a表示压缩存储的对称矩阵
    int b[M]= {1,1,1,1,1,1,1,1,1,1};
    int c1[N][N],c2[N][N];
    madd(a,b,c1);
    mult(a,b,c2);
    printf("a矩阵:\n");
    disp1(a);
    printf("b矩阵:\n");
    disp1(b);
    printf("a+b:\n");
    disp2(c1);
    printf("a×b:\n");
    disp2(c2);
    printf("\n");
    return 0;
}


//n阶下（上）三角矩阵指的是矩阵的上（下）三角部分全是常数
//那么压缩存储而言 a[i][j] 想存储到 b[k]
//上三角矩阵
// k=i(2n-i+1)/2+j-i i<=j （第一行n个 第二行n-1）
// k=n(n+1)/2 i>j

// k=i(i+1)/2+j i>=j
// k=n(n+1)/2 i<j