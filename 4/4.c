#include <stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
        int tmp1 = 0, tmp2 = 0, upper, lower, counter = 0;
        if(!nums1Size && !nums2Size){
                return 0;
        }
        if(!nums2Size){
                return (double)nums1[nums1Size/2] + (double)nums1[nums1Size/2] * !(nums1Size%2);
        }
        if(!nums1Size){
                return (double)nums2[nums2Size/2] + (double)nums1[nums2Size/2] * !(nums2Size%2);
        }
        upper = nums1Size;
        lower = 0;
        tmp1 = nums1Size / 2;
        do{
                tmp2 = ((nums1Size + nums2Size) / 2) - tmp1;
                if(nums1[tmp1 -1] <= nums2[tmp2] && nums2[tmp2 - 1] <= nums1[tmp1]){
                        break;
                }
                else if(nums1[tmp1 -1] <= nums2[tmp2] && nums2[tmp2 - 1] > nums1[tmp1]){
                        lower = tmp1;
                        tmp1 = (tmp1 + upper) / 2;
                }
                else{
                        upper = tmp1;
                        tmp1 = (tmp1 + lower) / 2;
                }
                counter++;
        }while(counter < nums1Size + nums2Size);

}

int main(){
        int arr1[] = {1,2,8};
        int arr2[] = {3,4,9};
        //125689
        printf("%.1f", findMedianSortedArrays(arr1, 2, arr2, 2));
}