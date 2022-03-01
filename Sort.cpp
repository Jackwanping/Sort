/* ************************************************************************
> File Name:     Sort.cpp
> Author:        程序员Phil
> 微信公众号:    程序员Phil
> Created Time:  Mon 28 Feb 2022 04:44:21 PM CST
> Description:   
 ************************************************************************/


#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<algorithm>
#include<limits.h>
#include<cmath>

const int INF = 0x3f3f3f3f;
int a[5] = {4,2,5,1,8};
vector<int>Data(a,a + 5);

class Sort{
public:
    // 交换排序
    void bubbleSort(vector<int>& Data);   //冒泡排序
    void quickSort(vector<int>& Data,int left,int right); // 快速排序
    //插入排序
    void insertSort(vector<int>& Data);                   //简单的插入排序
    void shellSort(vector<int>& Data);                    //希尔排序
    //选择排序
    void selectSort(vector<int>& Data);                    //选择排序
    void adjust(vector<int>& Data,int len,int index);       //递归的方式调整大根堆
    void heapSort(vector<int>& Data,int size);                      //堆排序
    //归并排序
    void merge(vector<int>&Data,int n,int left,int mid,int right); //合并
    void mergeSort(vector<int>&Data,int n,int left,int right);     //分开
    //--------非比较类--------------//
    void countSort(vector<int>&Data);                      //计数排序
    void bucketSort(vector<int>&Data);                     //桶排序
    void radixSort(vector<int>&Data);                      //基数排序 
};

void Sort::bubbleSort(vector<int>& Data)
{
    for(int i = 0;i < Data.size();++i)
    {
        for(int j = 0;j < Data.size() - i - 1;++j)
        {
            if(Data[j + 1] < Data[j]) swap(Data[j + 1],Data[j]);
        }
    }
}

void Sort::quickSort(vector<int>&Data,int left,int right)
{
    if(left < right)
    { //
        int i = left;
        int j = right;
        int x = Data[i];
        while(i < j)
        {
           while(i < j && Data[j] > x) j--;
           if(i < j) Data[i++] = Data[j];
           while(i < j && Data[i] < x) i++;
           if(i < j) Data[j--] = Data[i];
        }
        Data[i] = x;
        quickSort(Data,left,i-1);
        quickSort(Data,i+1,right);
    }
}

void Sort::insertSort(vector<int>&Data)
{
    for(int i = 1;i < Data.size();++i)
    {
          int x = Data[i];
          int pre_index = i - 1;
          while(pre_index >= 0 && Data[pre_index] > x)
          {
              Data[pre_index + 1] = Data[pre_index];
              pre_index--;
          }
          Data[pre_index + 1] = x;

    }
}

void Sort::shellSort(vector<int>&Data)
{
    for(int gap  = Data.size() / 2;gap > 0;gap /= 2)
    {
        for(int i = 0;i < gap;++i)
        {
            for(int j = i+gap;j<Data.size();j += gap)
            {
                if(Data[j - gap] > Data[j])
                {
                    int temp = j - gap;
                    int k = Data[j];
                     while(temp >=0 && Data[temp] > k)
                     {
                          Data[temp + gap] = Data[temp];
                          temp -= gap;
                     }
                     Data[temp + gap] = k;
                }
            }
        }
    }
}


void Sort::selectSort(vector<int>&Data)
{
     for(int i = 0;i < Data.size();++i)
     {
         int min_value_index = i;
         for(int j = i + 1;j < Data.size();++j)
         {
             if(Data[j] < Data[min_value_index]) 
             {
                min_value_index = j;
             }
         }
         swap(Data[i],Data[min_value_index]);
     }
}

// 递归的方式构建大根堆，len是数组长度，index是第一个非叶子的下标
void Sort::adjust(vector<int>& Data,int len,int index)
{
      int left = 2*index + 1;  //下标index的左节点
      int right = 2*index + 2;  //下标index的右节点
      int max_index = index;
      if(left < len && Data[left] > Data[max_index]) max_index = left;
      if(right < len && Data[right] > Data[max_index]) max_index = right;

      if(max_index != index)
      {
          swap(Data[index],Data[max_index]);
      }
}
void Sort::heapSort(vector<int>&Data,int size)
{
    //构建大根堆（从倒数第二层，也就是第一个非叶子节点）
    for(int i = size / 2;i >=0;i-- )
    {
        adjust(Data,size,i);
    }

    //调整大根堆
    for(int i = size - 1;i >= 1;i--)
    {
        swap(Data[0],Data[i]);    //将当前最大数放在数据末尾
        adjust(Data,i,0);         //将剩下的数据再进行调整，进行堆排序
    }

}

void Sort::merge(vector<int>&Data,int n,int left,int mid,int right)
{
      int n1 = mid - left;
      int n2 = right - mid;
      vector<int>Data_left(n1,0);
      vector<int>Data_right(n2,0);
      for(int i = 0;i<n1;++i) Data_left[i] = Data[left + i];
      for(int j = 0;j<n2;++j) Data_right[j] = Data[mid + j];
      Data_left[n1] = Data_right[n2] = INF;
      int count1 = 0;
      int count2 = 0;
     for(int k = left;k<right;++k)
     {
        if(Data_left[count1] <= Data_right[count2]) Data[k] = Data_left[count1++];
        else Data[k] = Data_right[count2++];
     }
}
  
void Sort::mergeSort(vector<int>&Data,int n,int left,int right)
{
    if(left + 1 < right)
    {
         int mid = (left + right) / 2;
         mergeSort(Data,n,left,mid);
         mergeSort(Data,n,mid,right);
         merge(Data,n,left,mid,right);
   }
}

void Sort::countSort(vector<int>&Data)
{
    // 先找到数组中的最大值，申请空间
    int max_value = INT_MIN;
    for(int i = 0;i<Data.size();++i)
    {
        if(Data[i] > max_value) max_value = Data[i];
    }
    vector<int>Demo(max_value + 1,0);
    for(int i = 0;i<Data.size();++i)
    {
        Demo[Data[i]]++;                 //数为Data[i] 的个数加1
    }
    int index = 0;
    for(int i = 0;i<Demo.size();++i)
    {
        while(Demo[i] > 0)
        {
            Data[index++] = i;
            Demo[i]--;
        }
    }
}

void Sort::bucketSort(vector<int>&Data)
{
    int minValue = Data[0];
    int maxValue = Data[0];
    for(int i = 1;i<Data.size();++i)
    {
        if(Data[i] > maxValue) maxValue = Data[i];
        if(Data[i] < minValue) minValue = Data[i];
    }

    int buckerSize = 5;                                                   //桶的个数
    int bucketCount = floor((maxValue - minValue) / buckerSize); //桶内的取值范围
    vector<vector<int>>buckets(buckerSize,vector<int>(bucketCount,INT_MIN));
    for(int i = 0;i<Data.size();++i)
    {
        buckets[floor((Data[i] - minValue) / buckerSize)].push_back(Data[i]); 
    }
    int count = 0;
    for(int i = 0;i<buckets.size();++i)
    {
        insertSort(buckets[i]);
        for(int j = 0;j<buckets[i].size();j++)
        {
            if(buckets[i][j]!=INT_MIN) Data[count++] = buckets[i][j];
        }
    }
    
}


void Sort::radixSort(vector<int>& Data)
{
    int length = Data.size();
    // 求最大值的位数
    int max_value = INT_MIN;
    for(int i = 0;i<length;++i)
    {
        if(Data[i] > max_value) max_value = Data[i]; 
    }
    int digit = 1;
    while(max_value/10 > 0)
    {
        ++digit;
        max_value /= 10;
    }

    vector<list<int>>bucket_list;
    bucket_list.resize(10);
    for(int i = 1;i<=digit;++i)
    {
        for(int j = 0;j<length;++j)
        {
            int radix =static_cast<int>(Data[j] / pow(10,i-1)) % 10;
            bucket_list[radix].push_back(Data[j]);
        }
        int k = 0;
        for(int n = 0;n<10;++n)
        {
            for(auto value:bucket_list[n])
            {
                Data[k++] = value;
            }
            bucket_list[n].clear();
        }
    }
}

int main()
{
    Sort s;
    //s.bubbleSort(Data);
    //s.quickSort(Data,0,Data.size()-1);
    //s.insertSort(Data);
    //s.shellSort(Data);
    //s.selectSort(Data);
    //s.heapSort(Data,Data.size());
    //s.mergeSort(Data,Data.size(),0,Data.size());
    //s.countSort(Data);
    //s.bucketSort(Data);
    s.radixSort(Data);
    for(int i = 0;i<Data.size();++i) cout<<Data[i]<<" ";
    return 0;
}
