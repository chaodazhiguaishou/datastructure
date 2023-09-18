#include <iostream>
#include <stdio.h>
#include <ctime>

//
// 计时函数clock()
// 头文件：#include<time.h>
// 函数定义：clock_t clock( );
// clock_t 是用来保存时间的数据类型，是一个长整型。
// CLOCKS_PER_SEC是一个常量，默认为每过1毫秒，调用clock() 函数返回的值就加1；
//因此，可以使用公式clock()/CLOCKS_PER_SEC来计算程序的运行时间。

using namespace std;

class Solution
{
public:
long solve(int n)
{
    long sum = n*(n+1)/2*(n+2)/3;
    return sum;
}

};

int main(int argc, const char * argv[]) {
    // insert code here...
    clock_t t1,t2;
    int n=500;
    Solution s;
    t1=clock();
    printf("计算%d求和结果为：%ld",n,s.solve(n));
    t2=clock();
    printf("运行时间：%lus\n",(t2-t1)/CLOCKS_PER_SEC);
    return 0;
};