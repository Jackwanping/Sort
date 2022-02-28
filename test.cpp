/* ************************************************************************
> File Name:     test.cpp
> Author:        程序员Phil
> 微信公众号:    程序员Phil
> Created Time:  Tue 15 Feb 2022 03:11:43 PM CST
> Description:   
 ************************************************************************/


#include<iostream>
using namespace std;
#include<vector>
#define rep(i, a, b) for(int i = a;i < (b); ++i)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int>pii;
typedef pair<long, long>pll;
#include<memory>

int fuc(int x){
    int count_1 = 0;
    while(x){
        count_1 ++;
        x = x & (x - 1);
    }
    return count_1;
}

void static_func(int a)
{
    static const int b = a;
    cout<<b<<endl;
}
class Person
{
public:
    static int age;
};
int Person::age = 10;

class B;
class A{
public:
    weak_ptr<B>pb_;
    ~A() 
    { 
        cout<<"A delete"<<endl;
    }
};

class B{
public:
    shared_ptr<A>pa_;
    ~B()
    {
        cout<<"B delete"<<endl;
    }
};

void fun()
{
    shared_ptr<B> pb(new B());
    shared_ptr<A> pa(new A());
    pb->pa_ = pa;
    pa->pb_ = pb;
    cout<<"use_count:"<<pb.use_count()<<endl;
    cout<<"use_count;"<<pa.use_count()<<endl;
}


class Father{
public:
    virtual void func()
    {
        cout<<"Father!"<<endl;
    }
};

class Son:public Father{
public:
    void func()
    {
        cout<<"Son!"<<endl;
    }
};
int main()
{
    int m = 123456;
    string result;
    result.push_back(m-'0');
    string s1 = "hello";
    string s2 = "world";
    s1 += s2;
    cout<<s1<<endl;
    return 0;
}













