#include <iostream>
#include <stdio.h>
using namespace std;

//在哈希表中，虽然哈希冲突很难避免，但发生冲突的可能性却有大有小。这主要与三个因素有关：
// 1.与装填因子有关。所谓装填因子α是指哈希表中已存入的元素数n与哈希地址空间大小m的比值，即α=n/m。
// α越小，冲突的可能性就越小； 但α越小，存储空间的利用率就越低。
// 2.与所采用的哈希函数有关。
// 3.与解决冲突的方法有关。

// 1. 开放定址法解决哈希冲突
// 发生冲突时查找周围一个空位置存放元素（记录）。
// 设置一个查找周围一个空位置的函数。
// （1）线性探测法
// 从发生冲突的地址（设为d）开始，依次循环探测d的下一个地址（当到达下标为m-1的哈希表表尾时，下一个探测的地址是表首地址0），
// 直到找到一个空闲单元为止。描述公式为： d0=h(k)，di=(di-1+1) mod m  (1≤i≤m-1)。但可能出现堆积现象！
// （2）平方探测法
// 发生冲突时前后查找空位置。描述公式为：d0=h(k)， di=(d0±i2) mod m  (1≤i≤m-1)


#define NULLKEY -1
template<typename T> //哈希表元素类型
struct HNode
{
    int key;  //关键字
    T value; //数据值
    HNode():key(NULLKEY){} //构造函数
    HNode(int k,T v) //重载构造函数
    {
        key = k; value = v;
    }
};

#define MAXM 100 
template<typename T>
class HashTable1
{
    int n; //元素个数
    int m; //哈希表的长度
    int p; //哈希函数取模的值
    HNode<T> ha[MAXM]; //存放哈希表元素
public:
    HashTable1(int m,int p)
    {
        this->m=m;
        this->p=p;
        for(int i=0;i<m;i++) //初始化为空哈希表
            ha[i].key=NULLKEY;
        n=0;
    }

    void insert(int k,T v) //在哈希表中插入
    {
        int d=k%p;
        while (ha[d].key!=NULLKEY)
        {
            d=(d+1)%m;   //使用线性探测法查找空位置
        }
        ha[d]=HNode<T>(k,v)
        n++;
    }

    int search(int k)  ////1. 采用开放定址法建立的哈希表的查找
    {
        int d=k%p; //求哈希函数值
        while (ha[d].key!=NULLKEY && ha[d].key!=k) //如果第一遍没找到说明有哈希冲突，根据构造时使用的方法找
        {
            d=(d+1)%m; //用线性探测法查找空位置
        }
        if (ha[d].key==k) //查找成功返回
        {
            return d;
        }
        else return -1;
    }
};

int main() {
    // insert code here...
};