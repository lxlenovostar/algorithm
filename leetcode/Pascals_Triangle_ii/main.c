/*
 * 119. Pascal's Triangle II.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 参数：
 第k行, 
 返回的数组的长度 : (k + 1)
 
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int i, j; 
    int *result0;
    int *result1;

    if (rowIndex < 0) {
        *returnSize = 0;
        return NULL;
    }

    if (rowIndex == 0) {
        *returnSize = 1;
        result0 = (int *)malloc((rowIndex + 1)*sizeof(int));    
        result0[0] = 1;
        return result0;
    }

    *returnSize = rowIndex + 1;
    result0 = (int *)malloc((rowIndex + 1)*sizeof(int));    
    result1 = (int *)malloc((rowIndex + 1)*sizeof(int));    

    memset(result0, 0, (rowIndex+1));   
    memset(result1, 0, (rowIndex+1));   
 
    for (i = 1; i <= (rowIndex+1); i++) {

        /***************just test*****************/ 
        /*int z; 
        printf("\norder is:%d\n", i);
        for (z = 0; z < (rowIndex + 1); z++) {
            printf("%d:", result0[z]);
        }       
        printf("\n");
        for (z = 0; z < (rowIndex + 1); z++) {
            printf("%d:", result1[z]);
        }*/ 
        /***************just test*****************/ 
 
        for (j = 0; j <= (i - 1); j++) {
            if (j == 0 || j == (i - 1)) {
                if (i%2 == 0)
                    result0[j] = 1; 
                else 
                    result1[j] = 1; 
            }
            else {
                if (i%2 == 0)
                    result0[j] = result1[j] + result1[j-1]; 
                else
                    result1[j] = result0[j] + result0[j-1]; 
            } 
        }
    }
    
    /***************just test*****************/ 
    //printf("\n");
    /***************just test*****************/ 

    if ((rowIndex + 1)%2 ==0) {
        free(result1);
        return result0;
    } else {
        free(result0);
        return result1;
    }
}

/*
int** generate(int numRows, int** columnSizes) {
    int i, j; 
    int **result;

    if (numRows <= 0) {
        *columnSizes = NULL;
        return NULL;
    }

    int *columns = (int *)malloc(sizeof(int)*numRows);

    result = (int **)malloc(numRows*sizeof(int *));    
    for (i = 1; i <= numRows; i++) {
        columns[i-1] = i;
        result[i - 1] = (int *)malloc(i*sizeof(int));
        
        for (j = 0; j <= (i - 1); j++) {
            if (j == 0 || j == (i - 1)) {
                result[i - 1][j] = 1; 
            }
            else {
                result[i - 1][j] = result[i - 2][j] + result[i - 2][j-1]; 
            } 
        }
    }

    *columnSizes = columns;

    return result;
}
*/

void main(void)
{
    int testcase;
    int i, j;
    int *result;

    result = getRow(0, &testcase);
    printf("\ntestcase1 size is:%d\n", testcase);
    for (i = 0; i < testcase; i++) {
        printf("%d:", result[i]);
    }
    free(result); 
    printf("\n");
   

    result = getRow(5, &testcase);
    printf("\ntestcase2 size is:%d\n", testcase);
    for (i = 0; i < testcase; i++) {
        printf("%d:", result[i]);
    }
    free(result); 
    printf("\n");
 
}
