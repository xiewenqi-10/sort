#include"sort.h"
template<class T>
class insertSort:protected Sort<T>
{
public:
    insertSort(){};
    virtual ~insertSort(){};
    inline virtual void sort(vector<T>&arr)
    {
        T j;
         /*
        *�� "i=1"��Ϊ���� "�±�0"��λ��Ϊ����,Ȼ��� "�±�1"��λ�ÿ�ʼѭ���Ƚϡ� 
        */
        for(int i=1;i<arr.size();i++)
        {
            T index=arr[i];
            for(j=i;j>0&&index<arr[j-1];j--)

                swap(arr[j],arr[j-1]);


            //cout<<"��"<<i<<"����������";    /* ������Ĺ��� */
            cout<<"i="<<i<<",index="<<index<<",j="<<j<<",�����";        
            print(arr);
        }
    }
};

/* ****************************************************************** */

void printarr(int arr[],int size)
{
    for(int i=0;i<size;i++){cout<<arr[i]<<" ";}
    cout<<endl;
}

template<class T>
void insertsort(T arr[],int size)
{

    T j;
    /*
    *�� "i=1"��Ϊ���� "�±�0"��λ��Ϊ����,Ȼ��� "�±�1"��λ�ÿ�ʼѭ���Ƚϡ� 
     */
    for(int i=1;i<size;i++)
    {
        int index=arr[i];
        for(j=i;j>0&&index<arr[j-1];j--)
            arr[j]=arr[j-1];     
        arr[j]=index;
    }
}

/* ******************************************************************* */

int main()
{
    // int arr[]={6,2,3,1,5};
    // int len=sizeof(arr)/sizeof(int);
  
    // insertsort(arr,len);
    // printarr(arr,len);

/* 8888888888888888888888888888888888888888888888888888888888888888888 */
    insertSort<int>I;
    vector<int>arr1={6,2,3,1,5};

    print(arr1);
    I.sort(arr1);
/* 8888888888888888888888888888888888888888888888888888888888888888888 */
    system("pause");
}