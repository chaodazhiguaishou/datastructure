#include <iostream>
#include <stdio.h>
#include "2.4.1.doublelinklist.cpp"
using namespace std;

//【例2.13】设计一个算法，删除整数双链表L中第一个值为x的结点，若不存在值为x的结点，则不做任何改变。


template <typename T>
class Solution
{
public:
void deletex(DLinkList<T>& a,int x)
{
    DLinkNode<T> *p=a.dhead->next;
    int i=0;
    while (p!=nullptr && i==0)
    {
        
        if (p->data !=x)
        {
            p = p->next;
        }
        if (p->data ==x)
        {
            if (p->next!=nullptr)
            {
                p->next->prior=p->prior;
            }
            p->prior->next=p->next;
            i++;
            delete p;
        }
    }
}

};

int main(int argc, const char * argv[]) {
    // insert code here...
    DLinkList<int> a,b;
    Solution<int> s;

    int aa[]={1,2,3};
    int bb[]={4,5}; //神奇bug 一旦加了就会报错
    int x=3;
    a.CreateListR(aa,3);
    a.DispList();
    s.deletex(a,3);
    a.DispList();
    
    // int bb[]={4,5};
    // b.CreateListR(aa,3);
    // b.DispList();
    // s.deletex(b,3);
    // b.DispList();

    return 0;
};