//选择排序
#include"sort.h"
template<class T>
class selectSort:protected Sort<T>
{
public:
    selectSort(){};
    virtual ~selectSort(){};
    inline virtual void sort(vector<T>&arr)
    {
        for(T i=0;i<arr.size()-1;i++)
        {
            T min=i;    
            for(T j=i+1;j<arr.size();j++)
            {
                if(arr[min]>arr[j])
                    min=j;
            }
                if(i!=min)
                    swap(arr[i],arr[min]);
            
            cout<<"第"<<i+1<<"趟排序结果：";    /* 求排序的过程 */     
            print(arr); /* 求排序的过程 */
        }

            // for(T i=0;i<arr.size();i++)
            // {
            //     T min=i;
            //     for(T j=i;j<arr.size();j++)
            //     {
            //         if(arr[min]>arr[j])
            //             min=j;
            //     }
            //     swap(arr[min],arr[i]);
            // }
    } 
};


/* ****************************************************************** */

void print(int arr[],int size)
{
    /***************************************************
    *这段代码的功能是输出第i+1趟的结果，但会出现相同的结果。*
    ****************************************************/
    for(int i=0;i<size;i++){cout<<arr[i]<<" ";}
    cout<<endl;
}

template<class T>
inline void selectsort(T arr[],T size)
{
    for(T i=0;i<size-1;i++)
    {
        T min=i;
        for(T j=i+1;j<size;j++)
        {
            if(arr[min]>arr[j])

                min=j;
    
        }
            if(i!=min)
                std::swap(arr[min],arr[i]);

        cout<<"第"<<i+1<<"趟排序的结果：";
        print(arr,size);
    }
}
/* ******************************************************************* */

int main()
{
    

    selectSort<int>s;
    vector<int>arr={6,2,3,1,5};

    print(arr);
    s.sort(arr);

    // int arr[]={6,2,3,1,5};
    // int len=sizeof(arr)/sizeof(int);

    // cout<<"原始序列       ：";
    // selectsort(arr,len);




    
    system("pause");
    return 0;    
}