/*
 * 118. Pascal's Triangle.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 参数：行数， 要返回的三角形数组
 这一题的重点是：二维数组.  
*/

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
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

void main(void)
{
    int *testcase1;
    int *testcase2;
    int i, j;
    int **result;

    result = generate(5, &testcase1);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < testcase1[i]; j++) {
            printf("%d:", result[i][j]);
        }
        free(result[i]);
        printf("\n");
    }
    free(result); 
    free(testcase1); 
    
   
    printf("testcase2\n");
    result = generate(1, &testcase2);
    for (i = 0; i < 1; i++) {
        for (j = 0; j < testcase2[i]; j++) {
            printf("%d:", result[i][j]);
        }
        free(result[i]);
        printf("\n");
    }
    free(result); 
    free(testcase2); 


}
