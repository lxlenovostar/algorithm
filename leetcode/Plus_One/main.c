/*
 * 66-Plus One.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 参数：一个数组表示整数， 数组长度，要返回的数组长度
 目标：将原来的整数加1
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i;
    int num = 0;
    int ary = 1;
    int *result;

    for (i = digitsSize - 1; i >= 0; i++) {
       num += digits[i] * ary;
       ary *= 10;
    }  

    num += 1;
    if (num%ary > 0) {
        *returnSize = digitsSize + 1;
    }
    else {
        *returnSize = digitsSize;
    }   

    result = (int *)malloc((*returnSize)*sizeof(int));

    ary = 1;    
    for (i = 0; i < (*returnSize) - 1; i++) {
        result[i] = num % 10;
        num /= 10;   
    }  

    return result;
}


void main(void)
{
    int size = 0;
    int testcase1[3] = {1, 2, 3};
    int testcase2[4] = {9, 9, 9, 9};
}
