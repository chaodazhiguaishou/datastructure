#include <iostream>
#include <stdio.h>
using namespace std;

//STL中的关联容器
// 所谓关联容器就是容器中每个元素有一个key（关键字），通过key来存储和读取元素。
// STL中的关联容器有集合（set）和映射（map）两类，均采用红黑树组织数据。
// 红黑树是一种弱平衡二叉树，在维护平衡的成本上比AVL树低，插入和删除等操作都比较稳定。
// 由于树结构中没有位置的概念，所以关联容器没有提供顺序容器中的[]，
// 也没有front()、push_front()、back()、push_back()以及pop_back()操作。


class Solution
{
public:

};

int main() {
    // insert code here...
};

// 1. set（集合容器）/multiset（多重集容器）
// set和multiset都是集合类模板，其元素值称为关键字。set中元素的关键字是唯一的，multiset中元素的关键字可以不唯一，
// 而且默认情况下会对元素按关键字自动进行升序排列。
// 查找速度比较快（时间复杂度为O(log2n)），同时支持集合的交、差和并等一些集合上的运算。


// 2. map（映射容器）/multimap（多重映射容器）
// map和multimap都是映射类模板。
// 映射是指元素类型为（key，value），其中key为关键字，value是对应的值，可以使用关键字key来访问相应的值value。
// map/multimap中的key和value是一个pair结构类型。
