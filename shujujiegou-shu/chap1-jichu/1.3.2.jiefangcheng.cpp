//解二元一次方程组

//printf的使用方法
//常用占位符
//    %d              十进制有符号整数 
//    %u              十进制无符号整数 
//    %ld             整数long类型
//    %lld            整数longlong类型
//    %f              浮点数float
//    %lf             浮点数double 
//    %s              字符串 
//    %c              单个字符 
//    %p              指针的值 
//    %e              指数形式的浮点数 
//    %x, %X          无符号以十六进制表示的整数 
//    %0              无符号以八进制表示的整数 
//    %g              自动选择合适的表示法 
 
// 可以在"%"和字母之间加小写字母l, 表示输出的是长型数。 
//        %ld   表示输出long整数 
//        %lf   表示输出double浮点数

//可以在"%"和字母之间插进数字表示最大场宽。 一般用于对齐输出
//    例如:  %3d   表示输出3位整型数, 不够3位右对齐。

//另外，“.3f”和".3lf"中的点加整数代表需要保留几位小数。
// printf("one root %.lf\n",x1);//输出为-1
// printf("one root %lf\n",x1);//输出为-1.000000
// printf("one root %.3lf\n",x1);//输出为-1.000
// printf("one root %7.3lf\n",x1);//输出为 -1.00
#include <iostream>
#include <stdio.h>
#include <stack>
#include <cmath>

using namespace std;

class Solution
{

public:

int getroot(double a,double b,double c,double &x1,double &x2)
{
    double deta = b*b - 4*a*c;
    if (deta == 0 )
    {
        x1 = (-b)/(2*a);
        return 1;
    }
    else if (deta > 0)
    {
        x1 = (-b + sqrt(deta))/(2*a);
        x2 = (-b - sqrt(deta))/(2*a);
        return 2;
    }
    else
    {
        return 0;
    }
}

void solve(double a,double b,double c)
{
    double x1,x2;
    int num = getroot(a,b,c,x1,x2);
    if (num == 1)
    {
        printf("one root %.lf\n",x1);//输出为-1
        printf("one root %lf\n",x1);//输出为-1.000000
        printf("one root %.3lf\n",x1);//输出为-1.000
        printf("one root %7.3lf\n",x1);//输出为 -1.000

    }
    else if (num == 2)
    {
        printf("two root %.lf and %.lf\n",x1,x2);
    }
    else
    {
        printf("no root\n");
    }
}

};

int main(int argc, const char * argv[]) {
    Solution s;
    printf("test 1.0 2.0 1.0\n");
    s.solve(1.0,2.0,1.0);
    return 0;
};