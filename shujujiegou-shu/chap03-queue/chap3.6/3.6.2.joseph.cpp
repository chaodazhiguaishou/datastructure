#include <iostream>
#include <stdio.h>
#include <queue>
#include "3.6.1.linkqueue.cpp"
using namespace std;

//【例3.13】 采用链队求解第2章例2.16的约瑟夫问题。
// 【例2.16】编写一个程序求解约瑟夫（Joseph）问题。有n个小孩围成一圈，给他们从1开始依次编号，
// 从编号为1的小孩开始报数，数到第m个小孩出列，
// 然后从出列的下一个小孩重新开始报数，数到第m个小孩又出列，…，
// 如此反复直到所有的小孩全部出列为止，求整个出列序列。
//     如当n=6，m=5时的出列序列是5，4，6，2，3，1。

template<typename T>
class Solution
{
public:

void joseph(int n,int m)
{
    int x;
    LinkQueue<T> J;
    for (int i = 1; i <= n; i++)    //进队编号为1到n的n个小孩
    {
        J.push(i);
    }
    for (int i = 0; i < n; i++) //共出列n个小孩
    {
        int j=1;
        while (j!=m)
        {
            J.pop(x); ////出队m-1个小孩，并将他们进队
            J.push(x);
            j++;
        }
        J.pop(x); ////出队第m个小孩
        cout<<x<<" ";      
    }
    cout<<endl;
}

};

int main() {
    // insert code here...
    Solution<int> s;
    s.joseph(6,3);
    s.joseph(8,4);
    return 0;
};
