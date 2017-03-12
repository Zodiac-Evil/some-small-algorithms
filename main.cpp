//
//  main.cpp
//  sort_func_realization
//
//  Created by GordonTJ on 2017/3/9.
//  Copyright © 2017年 bupt. All rights reserved.
//

#include <iostream>
#include <iomanip>

//无需临时变量的交换
void _swap_(int arr[], int i, int j)
{//差值法
    arr[i] = arr[i] - arr[j];
    arr[j] = arr[j] + arr[i];
    arr[i] = arr[j] - arr[i];
}
//冒泡排序(交换排序in place)
void const bubble_sort(int arr[], int length)
{//每次循环只比较相邻的两个元素，一次只把一个最大的或最小的冒泡，平均时间复杂度O(n^2)
    for(int j = length; j > 0; --j)
    {
        for(int i = 0; i < j - 1; ++i)
        {
            if(arr[i] > arr[i + 1])
            {
                _swap_(arr, i, i + 1);
            }
        }
    }
    
    return;
}

//快速排序(交换排序in place)
//寻找基准值二分数组，以第一个元素作为初始pivot
int divide(int arr[], int _start_, int _end_)
{
    int i = _start_, j = _end_;
    int pivot = arr[_start_];
    while(i != j)
    {
        while(arr[j] >= pivot)
        {
            if(i == j)
            {
                arr[j] = pivot;
                return i;
            }
            else --j;
        }
        arr[i] = arr[j];
        ++i;
        while(arr[i] <= pivot)
        {
            if(i == j)
            {
                arr[i] = pivot;
                return j;
            }
            else ++i;
        }
        arr[j] = arr[i];
        --j;
    }
    arr[i] = pivot;
    return i;
}

void quick_sort(int arr[], int i, int j)
{
    if(i < j)
    {
        int pivot_index = divide(arr, i, j);
        quick_sort(arr, i, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, j);
    }
    return;
}

//直接插入排序(插入排序in place)
void insertion_sort(int arr[], int length)
{//每次比较的时候用一个key记录被比较元素，每次比较都要么后移一个元素，要么将该key插入，特点是不用交换元素，平均时间复杂度O(n^2)
    for(int i = 0; i < length - 1; ++i)
    {
        int key = arr[i + 1];
        if(key >= arr[i])
        {
            continue;
        }
        else
        {
            int j = i;
            while(j >= 0 && key < arr[j])
            {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }
}

//归并排序
void merge_sort(int arr[], int length)
{
    
}

//部分匹配值表
void _partial_match_(char _sub_string_[], int _sub_length_, int *_partial_match_value_)
{
    for (int i = 0; i < _sub_length_; ++i) {
        if(0 == i)
            _partial_match_value_[i] = 0;
        else
        {
            if(_sub_string_[i] == _sub_string_[_partial_match_value_[i - 1] + 1])
                _partial_match_value_[i] = _partial_match_value_[i - 1] + 1;
            else
            {
                int k = _partial_match_value_[i - 1];
                while(k >= 0)
                {
                    if(_sub_string_[k] == _sub_string_[i] && k != 0)
                    {
                        _partial_match_value_[i] = k + 1;
                        break;
                    }
                    else if(_sub_string_[k] == _sub_string_[i] && k == 0)
                    {
                        _partial_match_value_[i] = 1;
                        break;
                    }
                    else if(k > 0)
                    {
                        k = _partial_match_value_[k];
                    }
                    else
                    {
                        _partial_match_value_[i] = 0;
                    }
                }
            }
        }
    }
}

//KMP匹配
int KMP_match(char _main_string[], char _sub_string_[], const int _main_length_, const int _sub_length_)
{
    int *_partial_ = new int[_sub_length_];
    _partial_match_(_sub_string_, _sub_length_, _partial_);
    int j = 0;
    for(int i = 0; i < _sub_length_; ++j)
    {
        if(_sub_string_[i] == _main_string[j])
        {
            if(i == _sub_length_ - 1)
            {
                return j - _sub_length_;
            }
            ++i;
            continue;
        }
        else if(j < _main_length_ - 1)
        {
            i -= (_sub_length_ - (i - _partial_[i - 1]));
            j -= (_sub_length_ - (i - _partial_[i - 1]));
        }
        else
        {
            return 0;
        }
    }
    return 9;
}

//牛顿迭代法开方
long double _newton_iterative_func_(long double a)
{
    long double x = a + 0.00001L;
    for(int i = 0; i < 501; ++i)
    {
        x = 0.5L * (x + (a/x) );
    }
    return x;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    int arr[7] = {0};
//    for(int i = 0; i < 7; ++i){
//        std::cin >> arr[i];
//    }
//    quick_sort(arr, 0, 6);
//    for(int i = 0; i < 7; ++i){
//        std::cout << arr[i];
//        if(i < 6) std::cout << "-->";
//    }
//    std::cout << std::endl;
    
    std::cout << "Input number to be squarted->";
    long double input = 0.0L;
    std::cin >> input;
    std::cout << std::setprecision(33) << _newton_iterative_func_(input) << std::endl;
    return 0;
}
