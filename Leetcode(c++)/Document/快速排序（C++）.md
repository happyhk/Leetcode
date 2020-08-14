# 快速排序（C++）
## 思路解说
快速排序采用的是分治算法，首先选择一个基准base，一般可以选择数组的start位置的元素，然后将整个数组的所有比基准元素小的放在基准元素的左边，比他大的放在基准元素的右边，然后不断递归base左边的和右边的，代码如下：<br>

```c++
#include <iostream>
#include <vector>
using namespace std;

void QuickSort(int left, int right, vector<int> &arr){
    if(left >= right) return;
    int base = arr[left];
    int pleft = left;
    int pright = right;
    while(pleft < pright){
        while(arr[pright] >= base && pleft < pright) pright--;
        while(arr[pleft] <= base && pleft < pright) pleft++;
        if(pleft < pright)
            swap(arr[pleft], arr[pright]);
    }
    swap(arr[left], arr[pleft]);
    QuickSort(left, pleft-1, arr);
    QuickSort(pleft+1, right, arr);
}


int main()
{
    vector<int> arr;
        for(int i = 0; i < 10;i++)
        arr.push_back(rand()%10);
        cout<<"排序前： ";
        for(int i = 0; i < arr.size();i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        QuickSort(0,arr.size()-1,arr);
        cout<<"排序后： ";
        for(int i = 0; i < arr.size();i++)
            cout<<arr[i]<<" ";
        return 0;
}
```



