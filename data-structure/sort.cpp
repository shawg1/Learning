#include <iostream>

const int MAX = 1000;
using namespace std;


void insertionSort(int p[] ,int l ,int r);//插入排序
void bubbleSort(int p[],int l,int r);//冒泡排序
void selectionSort(int p[],int l,int r);//选择排序

//归并排序
int L[MAX],R[MAX];
void merge(int p[],int l, int mid ,int r);
void mergeSort(int p[],int l,int r);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

//快速排序
int partition(int p[],int l,int r);
void quickSort(int p[],int l, int r);

int main()
{
    int nums[] ={3,4,56,-1,5,3,6,7,1,-2,4};
   // insertionSort(nums,0,11);
    //bubbleSort(nums,0,11);
    //selectionSort(nums,0,11);
    //mergeSort(nums,0,11);
    quickSort(nums,0,11);
    for(int i = 0; i< 11;i++)
    {
        cout<<nums[i]<<endl;
    }


    return 0;
}
/*
 * 前面的有序之后,把目标元素插入到合适的位置,使插入后仍有序
 * */
void insertionSort(int p[],int l,int r)
{
    /*
     * return @
     * param @数组指针,开始下标,长度(结束下标+1)
     * 时间复杂度 n^2
     * 依赖数据*/
    for(int i = l;i < r;i++)
    {
          int key = p[i];
          int j = i-1;
          while(j>=0 && p[j]> key)
          {
              p[j+1] = p[j];
              j--;
          }
          p[j+1] = key;
    }
}
/*
 * 每两个相比,把小的放前面
 * */
void bubbleSort(int p[],int l, int r)
{
    /*
     * param @数组,开始下标,长度(结束下标+1)
     * 时间复杂度 n^2
     * 不依赖数据*/
    for(int i = r-1;i>=l;i--)
    {
        for(int j = 0 ;j < i;j++)
        {
            if(p[j]>p[j+1])
            {
                swap(p[j],p[j+1]);
            }
        }
    }
}

/*
 *每次选择目标元素之后的所有元素中最小值和目标元素交换
 */
void selectionSort(int p[],int l,int r)
{
     /*
     * param @数组,开始下标,长度
     * 时间复杂度 n^2
     * 不依赖数据*/
    for(int i =0; i < r-1;i++)
    {
        int minIndex = i;
        for(int j = i+1 ;j< r;j++ )
        {
            if(p[minIndex]>p[j])
            {
                minIndex =j;
            }
        }
        swap(p[minIndex],p[i]);
    }
}

/*
 * 总的思想是两列已经有序的数字,每次比较最上面的放入目标数组
 * 每次取小的那个放入,最终就是有序的
 * 注意的是,两列数组可能长度不一样,如果有一组已经结束了,直接把剩下的全部放入就行
 * */
void merge(int p[],int l, int mid ,int r)
{
        /*
         * param @数组,开始,中间,结束下标+1
         * 时间复杂度nlog(n)*/
        int n1 = mid - l;
        int n2 = r - mid;
        for(int i = 0; i < n1 ;i ++)L[i]=p[l+i];
        for(int i =0 ; i < n2; i++) R[i]=p[mid+i];
    
        int i = 0,j = 0;
        for(int k = l;k <r;k++)
        {
            if( L[i] < R[j])
            {
                p[k] = L[i++];
            }else
            {
                p[k] = R[j++];
            }

            if(i == n1)//当有一列结束之后就直接把剩下的赋值并结束即可
            {
                while(k<r-1)//注意自增的使用对while结束条件的影响
                {
                    p[++k] = R[j++];
                }
                return ;//结束循环
            }
            if(j == n2)
            {
                while(k<r-1)
                {
                    p[++k] = L[i++];
                }
                return ;
            }
        }
}
/*
 * 调用递归把目标列表不断分成两列子列表
 * 再进行merge*/
void mergeSort(int p[],int l,int r)
{
    /*
     * 这是归并排序的归
     * 调用merge是并
     * 注意递归*/
    if(l < r-1)//注意递归结束条件
    {
        int m = (l+r)/2;
        mergeSort(p,l,m);
        mergeSort(p,m,r);
        merge(p,l,m,r);
    }
}


/*
 * 这是进行排序部分
`* 把小的放一边,大的放另一边,返回中间值
*/
int partition(int p[],int l,int r)
{
    /*
     * @return 中间元素下标
     * @param 数组,开始下标,结束下+1*/
    int key = p[r-1];
    int left =l-1;

    for(int j = l;j< r - 1;j++)
    {
        if(p[j] <= key)
        {
            left++;
            swap(p[left],p[j]);
        }
    }
    swap(p[left+1],p[r-1]);
    
    return left+1; 
}


void quickSort(int p[],int l, int r)
{
    if(l<r)
    {
        int q = partition(p,l,r);
        quickSort(p,l,q);
        quickSort(p,q+1,r);
    }
}

