
#include"sort.h"
template<class T>
class quickSort:protected Sort<T>
{
public:
    quickSort(){};
    virtual ~quickSort(){};

    inline virtual void sort(vector<T>&arr) /* 接口 */
    { 
        quickSort(arr,0,arr.size()-1); 
    }
    quickSort(vector<T>&,T ,T );
 
};

template<class T> 
inline quickSort<T>::quickSort(vector<T>&arr,T left,T right)
{
   while (left>=right){return;}
        
    T newLeft=left;  T newRight=right;
    T pivot=arr[left];                                  /* 设置基准 */
    while (newLeft<newRight)
    {
        while (newLeft<newRight&&pivot<=arr[newRight])  /*从右往左查找小于pivot的数*/
        {
            newRight--;
        }
        arr[newLeft]=arr[newRight]; /*小于pivot的数放在左边 */

        while (newLeft<newRight&&pivot>=arr[newLeft])   /*从左往右查找大于pivot的数*/
        {
            newLeft++;
        }
        arr[newRight]=arr[newLeft]; /*大于pivot的数放在右边 */
    }
    
    arr[newLeft]=pivot;

    quickSort(arr,left,newLeft-1);
    quickSort(arr,newRight+1,right);
}


/* ******************************************************************* */
void printarr(int arr[],int size)
{
    for(int i=0;i<size;i++){cout<<arr[i]<<" ";}
    cout<<endl;
}

template<class T>
int partition(T arr[],T left,T right)
{
    T pivot=arr[right];
    T i=left-1;

    for(int j=left;j<right;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            std::swap(arr[i],arr[j]);
        }
    }
    std::swap(arr[i+1],arr[right]);
    return i+1;
}

template<class T>
void quicksort(T arr[],T left,T right)
{   
    if(left<right)
    {
        T pivot=partition(arr,left,right);
        quicksort(arr,left,pivot-1);
        quicksort(arr,pivot+1,right);      
    }
}

template<class T>
void quicksort(T arr[])
{

    quicksort<T>(arr,0,5-1);

}
/* ******************************************************************* */


int main()
{
    int arr[]={6,2,3,1,5};
    int len=sizeof(arr)/sizeof(int);
    

    //quicksort(arr,0,len-1);
    quicksort(arr);
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }


    // vector<int>arr={6,2,3,1,5};
    // quickSort<int>q;

    // q.sort(arr);
    // print(arr);
    system("pause");
 
}


