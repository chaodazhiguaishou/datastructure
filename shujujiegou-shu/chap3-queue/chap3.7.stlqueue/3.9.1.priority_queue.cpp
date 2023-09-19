#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

//优先队列就是指定队列中元素的优先级，按优先级越大越优先出队，
// 而普通队列中按进队的先后顺序出队，可以看成进队越早越优先。
// 优先队列按照根的大小分为大根堆和小根堆，大根堆的元素越大越优先出队（即元素越大优先级也越大），
// 小根堆的元素越小越优先出队（即元素越小优先级也越大）。

// 成员函数	说明
// empty()	判断优先队列容器是否为空
// size()	返回优先队列容器中实际元素个数
// push(e)	元素e进队
// top()	获取队头元素
// pop()	元素出队

// 2）type为自定义数据类型
// 方式1：在定义类或者结构体类型中重载<运算符（operator <），以指定元素比较方式，
//如priority_queue<Stud> pq1语句会调用默认的<运算符创建堆pq1（是大根堆还是小根堆由<重载函数体确定）。
// 方式2：在定义类或者结构体中重载>运算符（operator >），以指定元素比较方式，
//如priority_queue<Stud，vector<Stud>，greater<Stud> > pq2语句会调用重载>运算符创建堆pq2，
//此时需要指定优先队列的低层容器（这里为vector，也可以是deque）。
// 方式3：在单独定义的类或者结构体中重载函数调用运算符()（operator ()），以指定元素比较方式，
//如priority_queue<Stud,vector<Stud>,StudCmp> pq3语句会调用StudCmp的()运算符创建堆pq3，
//此时需要指定优先队列的低层容器（这里为vector，也可以是deque）。

class Stud				//定义类Stud
{
public:
   int no;				//学号
   string name;			//姓名
   Stud(int n,string na)		//构造函数
   {  no=n;
      name=na;
   }
   bool operator<(const Stud& s) const	//重载<比较函数
   {					//将当前对象跟对象s进行比较
       return no<s.no;		//按no越大越优先出队
   }
   bool operator>(const Stud& s) const	//重载>比较函数
   {					//将当前对象跟对象s进行比较
      return no>s.no;  		//按no越小越优先出队
   }
};

//类的比较函数,改写operator()
class StudCmp				//含重载()成员函数的类
{
public:
   bool operator()(const Stud& s,const Stud& t) const
   {					//将对象s跟对象t进行比较
       return s.name<t.name;		//按name越大越优先出队
   }
};


int main()
{  Stud a[]={Stud(2,"Mary"),Stud(1,"John"),Stud(5,"Smith")};
   int n=sizeof(a)/sizeof(a[0]);
   //************************************************
   //方式1：使用Stud类的<比较函数定义大根堆pq1
   //************************************************
   priority_queue<Stud> pq1(a,a+n);
   cout << "pq1出队顺序: ";
   while (!pq1.empty())			//按no递减输出
   {  cout << "[" << pq1.top().no << "," << pq1.top().name << "]\t";
      pq1.pop();
   }
   cout << endl;
    //************************************************
    //方式2：使用Stud类的>比较函数定义小根堆pq2
    //************************************************
    priority_queue<Stud,deque<Stud>,greater<Stud> > pq2(a,a+n);
    cout << "pq2出队顺序: ";
    while (!pq2.empty())			//按no递增输出
    {   cout << "[" << pq2.top().no << "," << pq2.top().name << "]\t";
        pq2.pop();
    }
    cout << endl;
   //************************************************
   //方式3：使用类StudCmp的比较函数定义大根堆pq3
   //************************************************
   priority_queue<Stud,deque<Stud>,StudCmp> pq3(a,a+n);
   cout << "pq3出队顺序: ";
   while (!pq3.empty())			//按name递减输出
   {  cout << "[" << pq3.top().no << "," << pq3.top().name << "]\t";
      pq3.pop();
   }
   cout << endl;
   return 0;
}


// 1）type为内置数据类型
// 对于C/C++内置数据类型，默认的functional是less<T>（小于比较函数）即建立的是大根堆（即元素值越大越优先出队）。
// 可以改为以greater<T>（大于比较函数），这样元素越小优先级的越高（称为小根堆）。
// 建立大根堆
// priority_queue<int> big_heap;								//默认方式
// priority_queue<int,vector<int>,less<int> > big_heap2;	//使用less<T>比较函数
// 建立小跟堆
// priority_queue<int,vector<int>,greater<int> > small_heap; 	//使用greater<T>比较函数
