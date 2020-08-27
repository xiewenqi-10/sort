#include"sort.h"

template<class T>
class shellSort:protected Sort<T>
{

public:
    shellSort(){};
    virtual ~shellSort(){};

    inline virtual void sort(vector<T>&arr)
    {
        T k=1;          /* ��������k+1������ */
        
        for(T gap=arr.size()/2;gap>0;gap/=2)
        {            
            for(T i=gap;i<arr.size();i++)
            {
                T index=arr[i];
                T j=i;

                for(;j>=gap&&index<arr[j-gap];j-=gap)

                    swap(arr[j],arr[j-gap]);

                cout<<"��"<<k++<<"��:"<<"�� gap="<<gap<<" ,index= "
                <<index<<" ,arr[j-gap]="<<j-gap<<" ʱ,"<<"�����";    /* ������� */
                print(arr);
            }
        }
    } 
};

                // cout<<"��"<<k++<<"��:"<<"�� gap="<<gap<<", i="
                // <<i<<" ,index="<<index<<", j="<<j<<", arr[j-gap]="<<j-gap<<" ʱ,"<<"�����";    /* ������� */

/* ****************************************************************** */
void printarr(int arr[],int size)
{
    /***************************************************
    *��δ���Ĺ����������i+1�˵Ľ�������������ͬ�Ľ����*
    ****************************************************/
    for(int i=0;i<size;i++){cout<<arr[i]<<" ";}
    cout<<endl;
}

template<class T>
void shellsort(T arr[],T size)
{
    for(T gap=size/2;gap>0;gap/=2)
    {
        for(T i=gap;i<size;i++)
        {
            T index=arr[i];
            T j=i;

            for(;j>=gap&&index<arr[j-gap];j-=gap)
                arr[j]=arr[j-gap];
            
            arr[j]=index;
        }
    }
}

/* ******************************************************************* */


int main(int argc, char const *argv[])
{
    
    // int arr[]={6,2,3,1,5};
    // int len=sizeof(arr)/sizeof(int);
    // shellsort(arr,len);
    // printarr(arr,len);

    shellSort<int>s;
    vector<int>arr={6,2,3,1,5};
   // vector<int>arr1={8,9,1,7,2,3,5,4,6,0};

    s.sort(arr);



    system("pause");   
}


