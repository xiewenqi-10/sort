//#pragma once

#include"sort.h"
template<class T>
class BubbleSort:protected Sort<T>
{
public:
    BubbleSort(){};
    virtual ~BubbleSort(){};
    inline virtual void sort(vector<T>&arr)
    {
        bool isbool=true;
        for(int i=0;i<arr.size()&&isbool;i++)  /*��isboolΪ�棬���˳�ѭ�� */
        {
            isbool=false;                      /* ��ʼΪfalse */
            for(int j=0;j<arr.size()-i-1;j++)
            {
                if(arr[j]>arr[j+1])

                    swap(arr[j],arr[j+1]);
                    isbool=true;               /* �������ݽ��ӣ�isboolΪtrue */
            }
            
            cout<<"��"<<i+1<<"����������";    /* ������Ĺ��� */        
            print(arr);
        }
    }
};


// void print1()
// {
//     BubbleSort<int> B;
//     int arr[]={2,4,15,6,11,100,9,10,0,88, 7,5,11,45,54,12,11,8,12,3,6};
//     int len=sizeof(arr)/sizeof(int);
//     vector<int>v(arr,arr+len);
//     cout<<"ð������"<<endl;
//     B.sort(v);
//     for(int i=0;i<v.size();i++)
//     {
//         cout<<v[i]<<" ";
//     }
// }







/* ****************************************************************** */

// void printarr(int arr[],int size)
// {
//     /***************************************************
//     *��δ���Ĺ����������i+1�˵Ľ�������������ͬ�Ľ����*
//     ****************************************************/
//     for(int i=0;i<size;i++){cout<<arr[i]<<" ";}
//     cout<<endl;
// }

// template<class T>
// void bubbleSort(T arr[],T size)
// {
//     for(T i=0;i<size;i++)
//     {
//         for(T j=0;j<size-i-1;j++)
//         {
//             if(arr[j]>arr[j+1])
//                 std::swap(arr[j],arr[j+1]);
//         }
        
//         cout<<"��"<<i+1<<"������Ľ����";
//         printarr(arr,size);
//     }

// }
/* ******************************************************************* */


int main()
{
    
    BubbleSort<int>B1;
    BubbleSort<char>B2;

    vector<int>arr1={6,2,3,1,5};
    vector<char>arr2={'a','p','p','l','e'};
    
    print(arr1);
    B1.sort(arr1);

    // print(arr2);
    // B2.sort(arr2);

    // cout<<endl;
    // int arr[]={6,2,3,1,5},len=sizeof(arr)/sizeof(int);
    // bubbleSort(arr,len);

    
    // for(vector<char>::iterator it=arr2.begin();it!=arr2.end();it++)
    // {
    //     cout<<*it<<"��";
    // }
    
    system("pause");
    return 0;    
}