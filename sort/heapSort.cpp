#include"sort.h"
template<class T>
class HeapSort:protected Sort<T>
{
public:
    HeapSort(){};
    virtual ~HeapSort(){};
    inline virtual void sort(vector<T>&arr)
    {
        for(T i=arr.size()/2;i>=0;--i)  /* 建立堆 */
            MaxHeap(arr,i,arr.size());

        for(T i=arr.size()-1;i>0;--i)   /* 取出来 */
        {
            swap(arr[0],arr[i]);
            MaxHeap(arr,0,i);
        }
    }

    void MaxHeap(vector<T>&arr,int i,int right)
    {
        T index=i;              /* 设堆顶 */
        T left=index*2;         /* 左孩子编号 */
        while (left<right)
        { 
            if(left+1<right&&arr[left]<arr[left+1]) 
                left++; 

            if(arr[left]>arr[index])
            {
                swap(arr[left],arr[index]);
                index=left;     /* 左孩子的元素为新的堆顶 */
                left=index*2;    
            }
            else{break;}   
        }   
    }
};

template<class T>
void MaxHeap(T arr[],int size,int i)
{
    
    T max=i;            /* 设最大的数为堆顶 */
    int left=2*i+1;     
    int right=2*i+2;
    
    /* 若左孩子比root大 */
    if(left<size&&arr[max]<arr[left])
        max=left;

    /* 若右孩子比root大 */
    if(right<size&&arr[max]<arr[right])
        max=right;
   

    if(max!=i)
    {
        std::swap(arr[max],arr[i]);
        MaxHeap(arr,size,max);
    }   
}

template<class T>
void Heapsort(T arr[],int size)
{
    for(int i=size/2-1;i>=0;i--) /* 建立堆 */
        MaxHeap(arr,size,i);

    for(int i=size-1;i>=0;i--)  /* 取出来 */
    {
        std::swap(arr[0],arr[i]);
        MaxHeap(arr,i,0);
    }
}

int main()
{

    HeapSort<int>H;
    vector<int>arr={6,2,3,1,5};
    H.sort(arr);
    print(arr);


    // int arr[]={6,2,3,1,5};
    // int len=sizeof(arr)/sizeof(int);
    // Heapsort(arr,len);
    // for(int i=0;i<len;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }



    system("pause");
}