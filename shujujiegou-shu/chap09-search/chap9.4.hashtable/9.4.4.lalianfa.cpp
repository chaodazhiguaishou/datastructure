#include <iostream>
#include <stdio.h>
using namespace std;

// 2.拉链法处理哈希冲突
// 拉链法是把所有的同义词用单链表链接起来的方法。
// 在这种方法中，哈希表每个单元中存放的不再是元素本身，而是相应同义词单链表的首结点指针。
// 由于单链表中可插入任意多个结点，所以此时装填因子α根据同义词的多少既可以设定为大于1，
// 也可以设定为小于或等于1，通常取α=0.75。

// 用拉链法构造哈希表，有点像之前用数组存链表头节点，冲突的被加入对应位置链表

template<typename T> 
struct HNode    //拉链法中哈希表元素变为单链表结点类
{
    int key;  //关键字
    T value; //数据值
    HNode<T>* next; //下一个结点指针
    HNode(){} //构造函数
    HNode(int k,T v) //重载构造函数
    {
        key = k; value = v; next = NULL;
    }
};

#define MAXM 100
template<typename T>
class HashTable2
{
    int n; //元素个数
    int m; //哈希表的长度
    HNode<T>* ha[MAXM]; //存放哈希表中单链表的首结点抵制
public:
    HashTable2(int m,int p)
    {
        this->m=m;
        for(int i=0;i<m;i++) //初始化为空哈希表
            ha[i]=NULL;
        n=0;
    }
    ~HashTable2() //析构函数，释放整个哈希表空间
    {
        HNode<T>* pre,*p;
        for (int i = 0; i < m; i++)
        {
            pre=ha[i];
            if (p!=NULL)
            {
                p=pre->next;
                while (p!=NULL)
                {
                    delete pre;
                    pre = p;
                    p = p->next;
                }
                delete pre;
            }
        }
        delete [] ha;
    }

    void insert(int k,T v) //在哈希表中插入
    {
        int d=k % m; //求哈希函数值
        HNode<T> p = new HNode<T>(k,v); //新建关键字k的结点p
        p->next = ha[d]; //采用头插法插入ha[d]单链表中
        ha[d]=p;
        n++;
    }
    
    HNode<T>* search(int k)
    {
        int d=k%m; //求哈希函数值
        HNode<T>* p =ha[d]; //找到对应首结点
        while (p!=NULL && p->key!=k) //查找结点
        {
            p=p->next
        }
        return p; //找到的时候返回节点，找不到的时候p=NULL
    }
};

int main() {
    // insert code here...
    return 0;
};