/*
 * 66-Plus One.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 参数：一个数组表示整数， 数组长度，要返回的数组长度
 目标：将原来的整数加1
*/

/*
 整型 能表示的最大数是？ 

 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i;
    long long num = 0;
    long long ary = 1;
    int *result;

    printf("what0\n");
    for (i = digitsSize - 1; i >= 0; i--) {
       num += digits[i] * ary;
       ary *= 10;
    }  

    printf("what1\n");
    num += 1;
    printf("num is:%ld, ary is:%ld\n", num, ary);
    if (num/ary > 0) {
        *returnSize = digitsSize + 1;
    }
    else {
        *returnSize = digitsSize;
    }   

    printf("what2\n");
    result = (int *)malloc((*returnSize)*sizeof(int));

    ary = 1;    
    for (i = (*returnSize) - 1; i >= 0; i--) {
        result[i] = num % 10;
        num /= 10;   
    }  

    printf("what3\n");
    return result;
}


void main(void)
{
    int i;
    int testcase1[3] = {1, 2, 3};
    int size1 = 0;
    int *result1;
    int testcase2[4] = {9, 9, 9, 9};
    int size2 = 0;
    int *result2;
    //int testcase3[] = {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};
    int testcase3[] = {7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};
    int size3 = 0;
    int *result3;
    /*
    result1 = plusOne(testcase1, 3, &size1);
    printf("size is:%d\n", size1);
    for (i = 0; i < size1; i++) {
        printf("%d:", result1[i]);
    }
    printf("\n");
    free(result1);

    result2 = plusOne(testcase2, 4, &size2);
    printf("size is:%d\n", size2);
    for (i = 0; i < size2; i++) {
        printf("%d:", result2[i]);
    }
    printf("\n");
    free(result2);
    */ 
    
    printf("size array is:%d, and ulong_max is:%u\n", sizeof(testcase3)/sizeof(testcase3[0]), ULONG_MAX);
    result3 = plusOne(testcase3, sizeof(testcase3)/sizeof(testcase3[0]), &size3);
    printf("size is:%d\n", size3);
    for (i = 0; i < size3; i++) {
        printf("%d:", result3[i]);
    }
    printf("\n");
    free(result3);
}
