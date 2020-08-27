#pragma once
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
#include<vector>
#define N 10000
#ifndef __SOMEFILE__H__
#define __SOMEFILE__H__

template<class T>
class Sort
{
protected:
    Sort(){};
    virtual ~Sort(){};
    virtual void sort(vector<T>&)=0;
};

template<class T>
void print(vector<T>arr)
{

    for(T printArr:arr){cout<<printArr<<" ";}

    cout<<endl;
}

#endif