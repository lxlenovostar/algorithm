/*
 * 26-Remove Duplicates from Sorted Array
 */

#include <stdio.h>
#include <stdlib.h>

/*
 参数：一个数组， 数组长度
 目标: 删除数组中重复的元素
 条件：已经排序好的数组
*/
int removeDuplicates(int* nums, int numsSize) {
    int i, k;
    int j = 0;
    int flag;

    for (i = 0; i < numsSize; i++) {
        /*
         * 和已经确认的数据集进行比较, 因为是已经排序好的，所以可以少比较有很多。
         */
        k = j;
        
        /*
        while(k > 0) {
            if (nums[i] == nums[k-1]) {
                flag = 0;
                break;
            }
            k--;
        }
        */
         
        if (k > 0 && nums[i] == nums[k-1]) 
            continue;

        nums[j] = nums[i];
        j++;
    }
   
    return j;
}

void main(void)
{
    int nums[2] = {1, 2};
    int nums2[3] = {1, 1, 2};
    int nums1[5] = {3, 2, 1, 1, 2};
    int nums3[4] = {0, 0, 0, 0};
    int i;
    printf("length is:%d\n", removeDuplicates(nums, 2)); 
    printf("length is:%d\n", removeDuplicates(nums2, 3)); 
    printf("length is:%d\n", removeDuplicates(nums1, 5)); 
    printf("length is:%d\n", removeDuplicates(nums3, 4)); 

    for (i = 0; i < 2; i++)
        printf("array is:%d\n", nums[i]);
    
    printf("\n");
    
    for (i = 0; i < 3; i++)
        printf("array is:%d\n", nums2[i]);
    
    printf("\n");
    
    for (i = 0; i < 5; i++)
        printf("array is:%d\n", nums1[i]);
    
    printf("\n");
    
    for (i = 0; i < 4; i++)
        printf("array is:%d\n", nums3[i]);
}
