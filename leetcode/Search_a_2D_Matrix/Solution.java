/*
 74. Search a 2D Matrix

 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

 1. Integers in each row are sorted from left to right.
 2. The first integer of each row is greater than the last integer of the previous row.

 For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
 */

import java.util.*;

public class Solution {
    private static boolean check_value(int[] matrix, int target) {
        int length = matrix.length;
        boolean flag = false;

        if (length == 0) {
            return false;
        }
        else if (length == 1) {
            if (matrix[0] == target)
                return true;
            else 
                return false;
        }  else {
            int mid = length/2;
            
            //System.out.printf("length:%d mid:%d\n", length, mid);       

            if (target == matrix[mid])
                return true;
            else if (target > matrix[mid]) {
                //System.out.printf("here1\n");       
                
                if (mid == length - 1)
                    return false;

                int rmd = length - mid - 1;
                int[] dest = new int[rmd]; 

                System.arraycopy(matrix, mid+1, dest, 0, rmd);
                //System.out.printf("here3\n");       

                /*
                if (mid+1 == length-1) {
                    dest = new int[1];
                    System.arraycopy(matrix, mid+1, dest, 0, 1);
                    System.out.printf("here3\n");       
                }
                else { 
                    dest = new int[mid-1];
                    System.arraycopy(matrix, mid+1, dest, 0, mid-1);
                    System.out.printf("here4\n");       
                }
                */

                flag = check_value(dest, target);
            }
            else { 
                //System.out.printf("here2\n");       
                int[] dest = new int[mid];
                System.arraycopy(matrix, 0, dest, 0, mid);
                flag = check_value(dest, target);
            }
        }
    
        return flag;
    }
    
	public static boolean searchMatrix(int[][] matrix, int target) { 
        int row = matrix.length - 1;
        int col = matrix[0].length - 1;        
	
        //System.out.printf("row:%d col:%d\n", row, col);       
        if (target < matrix[0][0] || target > matrix[row][col])
            return false;

        for (int i = 0; i <= row; i++) {
            if (target <= matrix[i][col]) {
                //System.out.printf("row:%d, target:%d, matrix:%d\n", i, target, matrix[i][col]);       
                return check_value(matrix[i], target);
            }
        }        

		return false;
    }

    public static void main(String[] args)
    {
        int [][] a = {
                {1,   3,  5,  7},
                {10, 11, 16, 20},
                {23, 30, 34, 50}
                };        
        //boolean result = Solution.searchMatrix(a, 5);
        //boolean result = Solution.searchMatrix(a, 31);
        //boolean result = Solution.searchMatrix(a, 7);
        //boolean result = Solution.searchMatrix(a, 13);
        boolean result = Solution.searchMatrix(a, 6);

        //int [][] a = { {1,   3,  5}};
        //boolean result = Solution.searchMatrix(a, 5);


        System.out.printf("%d:\n", result == true ? 0: 1);       
    }
}
