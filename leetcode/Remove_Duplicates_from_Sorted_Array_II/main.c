/*
 * 80-Remove Duplicates from Sorted Array II
 */

#include <stdio.h>
#include <stdlib.h>

/*
 参数：一个数组， 数组长度
 目标: 删除数组中重复的元素, 但是允许重复的元素连续出现两次。
 条件：已经排序好的数组
*/
int removeDuplicates(int* nums, int numsSize) {
    int i;
    int j = 0;
    
    for (i = 0; i < numsSize; i++) {
        /*
         * 和已经确认的数据集进行比较, 因为是已经排序好的，所以可以少比较有很多。
         */
        if (j > 1 && nums[i] == nums[j-1] && nums[i] == nums[j-2])
            continue;

        nums[j] = nums[i];
        j++;
    }
   
    return j;
}

void main(void)
{
    int nums[2] = {1, 2};
    int nums1[5] = {3, 2, 1, 1, 2};
    int nums2[3] = {1, 1, 2};
    int nums3[4] = {0, 0, 0, 0};
    int nums4[6] = {1, 1, 1, 2, 2, 3};
    int i;
    printf("length is:%d\n", removeDuplicates(nums, 2)); 
    printf("length is:%d\n", removeDuplicates(nums1, 5)); 
    printf("length is:%d\n", removeDuplicates(nums2, 3)); 
    printf("length is:%d\n", removeDuplicates(nums3, 4)); 
    printf("length is:%d\n", removeDuplicates(nums4, 6)); 

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
    
    printf("\n");
    
    for (i = 0; i < 6; i++)
        printf("array is:%d\n", nums4[i]);
}
