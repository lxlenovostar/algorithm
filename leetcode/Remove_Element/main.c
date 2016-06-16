/*
 * 27-Remove Element.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 参数：一个数组， 数组长度，要删除的值
 目标：将后面的值，移动到前面要删除的位置。
 *(nums + numsSize - 1 - i)
*/
int removeElement(int* nums, int numsSize, int val) {
    int i, j;
    int length = 0;
    
    for (i = 0; i < numsSize; i++) {
        if (*(nums + i) != val) {
            length++;
        }
    }
   
    j = 0; 
    for (i = 0; i < length; i++) {
        if (*(nums + i) == val) {
            while(numsSize - 1 - j >= length)
            {
                if (*(nums + numsSize - 1 - j) != val) {
                    *(nums + i) = *(nums + numsSize - 1 - j);
                    j++;
                    break;
                }
                j++;
            }
        }
    }
   
    return length;
}

void main(void)
{
    int nums[4] = {3, 2, 2, 3};
    int nums1[5] = {3, 3, 1, 2, 3};
    int i;
    removeElement(nums, 4, 3); 
    removeElement(nums1, 5, 3); 

    for (i = 0; i < 4; i++)
        printf("array is:%d\n", nums[i]);
        
    printf("\n");
    
    for (i = 0; i < 5; i++)
        printf("array is:%d\n", nums1[i]);
}
