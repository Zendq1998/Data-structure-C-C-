//
//  main.cpp
//  6-1排序算法比较
//
//  Created by 1 on 2017/12/20.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
using namespace std;

void output(int a);//打印元素
void inser_sort(int arr[],int n);//插入排序
void shell(int*data,unsigned int len);//希尔排序
void select_sort(int arr[],int n);//选择排序
void bubble_sort(int arr[],int n);//冒泡排序

void MinHeapFixup(int a[], int i);//堆的插入调整
void MinHeapAddNumber(int a[], int n, int nNum);//堆的插入
void MinHeapFixdown(int a[], int i, int n);//从i结点开始调整，n为结点个数
void MinHeapDeleteNumber(int a[], int n);//在小根堆删除第0个数据
void MakeMinHeap(int a[], int n);//建立小根堆
void MinheapsortTodescendarray(int a[], int n);//堆排序

void quick_sort_recursive(int arr[], int start, int end);
void quick_sort(int arr[], int len);//快速排序

void mergearray(int a[], int first, int mid, int last, int temp[]);
void mergesort(int a[], int first, int last, int temp[]);
bool MergeSort(int a[], int n);//归并排序

void getPosCount(int *array, int length, int *posCount);//得到数组元素中最大数，并且计算其位数个数
void radixSort(int *array, int length);//基数排序
#define LEN 10
#define NUM 100000
int main() {
    int arr[NUM];
    clock_t start,ends;
    for (int i=0; i<NUM; i++) {
        arr[i] = rand()%NUM;
    }
    start=clock();
    inser_sort(arr,NUM);
    cout<<"插入排序";
//
//    shell(arr, NUM);
//    cout<<"希尔排序";
//
//    select_sort(arr, NUM);
//    cout<<"选择排序";
//
//    bubble_sort(arr, NUM);
//    cout<<"冒泡排序";
//
//    MakeMinHeap(arr,NUM);
//    MinheapsortTodescendarray(arr,NUM);
//    cout<<"堆排序";
//
//    quick_sort(arr,NUM);
//    cout<<"快速排序";
//
//    MergeSort(arr,NUM);
//    cout<<"归并排序";
//
//    radixSort(arr,NUM);
//    cout<<"基数排序";
    
    ends=clock();
    for_each(arr, arr+NUM, output);
    cout<<"插入排序用时："<<(double)(ends-start)/CLOCKS_PER_SEC<<"seconds"<<endl;
    return 0;
}

void output(int a){
    cout<<a<<" ";
}

void inser_sort(int arr[],int n) {
    int i,j;
    for(i=0;i<n;i++) {
        for(j=i;j>0;j--) {
            if (arr[j]<arr[j-1]) {
                swap(arr[j], arr[j-1]);
            }
            else {
                break;
            }
        }
    }
}


void shell(int*data,unsigned int len)
{
    if(len<=1||data==NULL)
        return;
    for(int div=len/2;div>=1;div=div/2)//定增量div，并不断减小
    {
        for(int i=0;i<=div;++i)//分组成div组
        {
            for(int j=i;j<len-div;j+=div)//对每组进行插入排序
                for(int k=j;k<len;k+=div)
                    if(data[j]>data[k])
                        swap(data[j],data[k]);//交换两个数的值
        }
    }
}

void select_sort(int arr[],int n) {
    int i,j;
    for (i=0; i<n; i++) {
        int min = i;
        for (j=i+1; j<n; j++) {
            if (arr[j]<arr[min]) {
                min = j;
            }
        }
        if (min>i) {
            swap(arr[i], arr[min]);
        }
    }
}

void bubble_sort(int arr[],int n) {
    int i,j;
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void MinHeapFixup(int a[], int i)
{
    for (int j = (i - 1) / 2; (j >= 0 && i != 0)&& a[i] > a[j]; i = j, j = (i - 1) / 2)
        swap(a[i], a[j]);
}
void MinHeapAddNumber(int a[], int n, int nNum)
{
    a[n] = nNum;
    MinHeapFixup(a, n);
}

//  从i节点开始调整,n为节点总数 从0开始计算 i节点的子节点为 2*i+1, 2*i+2
void MinHeapFixdown(int a[], int i, int n)
{
    int j, temp;
    
    temp = a[i];
    j = 2 * i + 1;
    while (j < n)
    {
        if (j + 1 < n && a[j + 1] < a[j]) //在左右孩子中找最小的
            j++;
        
        if (a[j] >= temp)
            break;
        
        a[i] = a[j];     //把较小的子结点往上移动,替换它的父结点
        i = j;
        j = 2 * i + 1;
    }
    a[i] = temp;
}
//在最小堆中删除数
void MinHeapDeleteNumber(int a[], int n)
{
    swap(a[0], a[n - 1]);
    MinHeapFixdown(a, 0, n - 1);
}
//建立最小堆
void MakeMinHeap(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        MinHeapFixdown(a, i, n);
}
//堆排序
void MinheapsortTodescendarray(int a[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        swap(a[i], a[0]);
        MinHeapFixdown(a, 0, i);
    }
}

void quick_sort_recursive(int arr[], int start, int end) {
    if (start >= end)
        return; // 這是為了防止宣告堆疊陣列時當機
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(arr[left], arr[right]);
        }
    if (arr[left] >= arr[end])
        swap(arr[left], arr[end]);
    else
        left++;
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
    }
void quick_sort(int arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}

//将有二个有序数列a[first...mid]和a[mid...last]合并。
void mergearray(int a[], int first, int mid, int last, int temp[])
{
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    int k = 0;
    
    while (i <= m && j <= n)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    
    while (i <= m)
        temp[k++] = a[i++];
    
    while (j <= n)
        temp[k++] = a[j++];
    
    for (i = 0; i < k; i++)
        a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergesort(a, first, mid, temp);    //左边有序
        mergesort(a, mid + 1, last, temp); //右边有序
        mergearray(a, first, mid, last, temp); //再将二个有序数列合并
    }
}

bool MergeSort(int a[], int n)
{
    int *p = new int[n];
    if (p == NULL)
        return false;
    mergesort(a, 0, n - 1, p);
    delete[] p;
    return true;
}

// 得到数组元素中最大数，并且计算其位数个数
void getPosCount(int *array, int length, int *posCount)
{
    int max, index;
    for (max = *array, index = 0; index < length; index++){
        if ( max < *(array + index)) max = *(array + index);
    }
    
    *posCount = 0;
    while(max){
        max = max / 10;
        (*posCount)++;
    }
}

void radixSort(int *array, int length)
{
    int* tmpArray[LEN];// 定义桶个数 0～9 共10个
    int index, pos, posCount, element, elementNum, tmp, log = 1;
    
    for (element = 0; element < LEN; element++){// 每个桶最大能装length个元素，预防所有元素都是同一个数
        tmpArray[element] = (int*)malloc((sizeof(int))*(length + 1));
        tmpArray[element][0] = 0;// 初始化为0
    }
    
    getPosCount(array, length, &posCount);// 把最高位数存放到posCount中
    
    for (pos = 0; pos < posCount; pos++){// 从个位 ～ 十位 ～ 百位 。。。依次排序
        
        for (element = 0; element < length; element++){// 把元素放到桶里  分配动作
            tmp = ++tmpArray[ (array[element] / log ) % 10][0];
            tmpArray[ (array[element] / log) % 10][tmp] = array[element];
        }
        
        for (index = 0, element = 0; (element < LEN) && (index < length); element++){
            for (elementNum = 1; elementNum <= tmpArray[element][0]; elementNum++)
                array[index++] = tmpArray[element][elementNum];
            tmpArray[element][0] = 0;
        }
        log = log * 10;
    }
}
