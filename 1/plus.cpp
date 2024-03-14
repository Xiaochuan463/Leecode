/*
 *给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 *你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
*/
#include<algorithm>
#include<iostream>
/**
 * Parameters: 
 *      vec: a vector to find 2 numbers that can be added to target
 *      target: finally sum
 * Returns:
 *      an array contains 2 numbers
*/
int* find_two_sum(std::vector<int>* vec, int target){
        std::sort(vec->begin(), vec->end());
        int *arr;
        auto it = std::lower_bound(vec->begin(), vec->end(), target);
        int i;
        for(i = 0; (*vec)[i] < *it; i++){
                auto tmp = it;
                while(*tmp > (*vec)[i]){
                        if(*tmp + (*vec)[i] == target){
                                arr = new int[2];
                                arr[0] = *tmp;
                                arr[1] = (*vec)[i];
                                return arr;
                        }
                        tmp--;
                }
        }
        return NULL;
}

int main(){
        int arr[] = {9,2,7,3,4,6,5};
        std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
        int* a = find_two_sum(&vec, 5);
        if(a){
                std::cout<<'('<<a[0]<<' '<<a[1]<<')'<<'\n';
                delete[] a;
        }
        else{
                std::cout<<"NOT Found!\n";
        }
}