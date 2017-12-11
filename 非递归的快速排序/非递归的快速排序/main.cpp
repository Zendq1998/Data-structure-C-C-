//
//  main.cpp
//  非递归的快速排序
//
//  Created by 1 on 2017/12/11.
//  Copyright © 2017年 zendq1998. All rights reserved.
//

#include <iostream>
using namespace std;
typedef int  ElemType;
#include "SqQueue.h"
void QuickSort(ElemType A[], int low, int high);
void NRQuickSort(ElemType A[],int low,int high);
void print(int a);

int main() {
    int A[10] = {23,123,534,12,342,35,61,435,32,56};
    NRQuickSort(A, 0, 9);
    for_each(A, A+10, print);
    return 0;
}

void print(int a) {
    cout<<a;
    cout<<endl;
}

void QuickSort(ElemType A[], int low, int high) {
    //采用快速排序法对A[0]~A[n-1]排序
    int i,j;
    ElemType temp;
    i = low;            //i从区间最左端开始
    j = high;           //j从区间最右端开始
    temp = A[low];      //取区间中第一个元素为基准元素
    while (i<j) {
        while (i<j && A[j]>=temp) {
            j --;
        }//在区间右端寻找小于基准元素关键字的元素
        if (i<j) {
            A[i] = A[j];
            i ++;
        }
        while (i<j && A[i] <= temp) {
            i ++;
        }
        if (i<j) {
            A[j] = A[i];
            j --;
        }
    }
    
    A[i] = temp;
    if (low<i-1) {
        QuickSort(A, low, i-1);
    }
    if (high>i+1) {
        QuickSort(A, i+1, high);
    }
}

void NRQuickSort(ElemType A[],int low,int high) {
    SqQueue Q;
    InitQueue_Sq(Q);    //初始化队列
    ElemType temp;
    EnQueue_Sq(Q, low);   //左端点进队
    EnQueue_Sq(Q, high);   //右端点进队
    while (!QueueEmpty_Sq(Q)) {
        int i,j;
        DeQueue_Sq(Q, i);   //左端点出队
        DeQueue_Sq(Q, j);   //右端点出队
        int l = i;          //左端点的副本
        int h = j;          //右端点的副本
        temp = A[i];      //取区间中第一个元素为基准元素
        while (i<j) {
            while (i<j && A[j]>=temp) {
                j --;
            }//在区间右端寻找小于基准元素关键字的元素
            if (i<j) {
                A[i] = A[j];
                i ++;
            }
            while (i<j && A[i] <= temp) {
                i ++;
            }
            if (i<j) {
                A[j] = A[i];
                j --;
            }
        }
        A[i] = temp;
        if (l < i-1) {
            EnQueue_Sq(Q, l);   //左侧的左端点入队
            EnQueue_Sq(Q, i-1); //左侧的右端点入队
        }
        if (h > i+1) {
            EnQueue_Sq(Q, i+1); //右侧的左端点入队
            EnQueue_Sq(Q, h);   //右侧的有段对入队
        }
        
    }
}
