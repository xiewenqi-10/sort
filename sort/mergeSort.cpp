#include"sort.h"
const long MAX=10086000;
#include<ctime>
#include<list>
template<class T>
class mergeSort:protected Sort<T>
{
public:
    mergeSort(){};
    virtual ~mergeSort(){};
    inline virtual void sort(vector<T>&arr)        /* 接口 */
    {
        vector<T>tempArr(arr.size());
        mergeSort(arr,tempArr,0,arr.size()-1);
    }

    mergeSort(vector<T>&arr,vector<T>&tempArr,int left,int right)
    {
        if(left<right)
        {
            int mid=(left+right)/2;             /* 折半递归 */
            mergeSort(arr,tempArr,left,mid);    
            mergeSort(arr,tempArr,mid+1,right);
            merge(arr,tempArr,left,mid+1,right);/* 合    并 */
        }
    }
    
    inline void merge(vector<T>&,vector<T>&,int left,int mid,int right);

};

/*
*1.tempArr:是临时的数组；2.left和right是序列的左边和右边；3.mid是数组的分界点。
*/
template<class T>
inline void mergeSort<T>::merge(vector<T>&arr,vector<T>&tempArr,int left,int mid,int right)
{
    T leftBegin=left;/* 左序列起点 */   T rightBegin=mid;  /* 右序列起点 */
    T leftEnd=mid-1; /* 左序列末尾 */   T rightEnd=right;  /* 右序列末尾 */

    T tempBegin=left;/* 临时数组左序列起点 */ T numberData=right-left+1; /* 元素个数 */

    /* 两段数组合并 */
    while (leftBegin<=leftEnd&&rightBegin<=rightEnd)
    {        
        if(arr[leftBegin]<=arr[rightBegin])     /* 把小的元素放在临时数组 */    
        {
            tempArr[tempBegin++]=arr[leftBegin++];
        }
        else
        {
            tempArr[tempBegin++]=arr[rightBegin++];
        }
    }

    while (leftBegin<=leftEnd)          /* 只剩下一个序列，直接放入临时数组 */
    {
        tempArr[tempBegin++]=arr[leftBegin++];
    }
    while (rightBegin<=rightEnd)
    {
        tempArr[tempBegin++]=arr[rightBegin++];
    }
        
    for(int i=0;i<numberData;i++,rightEnd--)
    {
        arr[rightEnd]=tempArr[rightEnd];           /* 把临时数组复制到 arr */
    }
}




int main()
{

    mergeSort<int>m;
    vector<int>arr={6,2,3,1,5};

    m.sort(arr);
    print(arr);


    system("pause");
    return 0;
}



/* ****************************************************************** */

// template<class T>
// void time()
//  {
//      srand(time(NULL));
//      int len;
//      while (cin>>len)
//      {  
        //int arr[len];
//         vector<int>arr(len);
//         for(int i=0;i<len;i++)
//             arr[i]=rand()%len;
//         int time_begin,time_end;
//         time_begin=clock();
//         mergesort(arr,0,len);
         //MergeSort(arr,0,arr.size());
//         time_end=clock();       
//         for(int i=0;i<len;i++){ cout<<arr[i]<<" ";  }
//         cout<<time_begin-time_end<<"ms"<<endl;
//      }
//  }

/* ******************************************************************* */



















//==========================================================
//  inline void merge(vector<T>&arr,T p,T q,T r)
//     {
//         T n1=q-p+1,n2=r-q;

//         T L[n1+1],R[n2+1];

//         for(T i=0;i<n1;i++) L[i]=arr[p+i];

//         for(T j=0;j<n2;j++) R[j]=arr[q+j+1];

//         L[n1]=MAX;
//         R[n2]=MAX;

//         for(T k=p;k<=r;k++)
//         {
//             int i=0,j=0;
//             if(L[i]<R[j]){ arr[k]=arr[i];i++;}

//             else{ arr[k]=R[j];j++;}
//         }
//     }

//     inline void mergesort(vector<T>&arr,T p,T r)
//     {
//         if(p<r)
//         {
//             T q=(p+r)/2;
//             mergesort(arr,p,q);
//             mergesort(arr,q+1,r);
//             merge(arr,p,q,r);
//         }
//     }
//=====================================================================






