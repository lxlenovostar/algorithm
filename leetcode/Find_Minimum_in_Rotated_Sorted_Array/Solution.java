/*
 * 153. Find Minimum in Rotated Sorted Array
 *
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
 */

import java.util.*;

public class Solution {
	public static int findMin(int[] nums) {
        
    }

    public static void main(String[] args)
    {
        //int[] a1 = {-2, -1, 0, 0, 1, 2};
        int[] a1 = {0, 0, 0, 0, 0};
        //int[] a1 = {-3, -1, 0, 2, 4, 5};


        List<List<Integer>> result;
        result = Solution.fourSum(a1, 0);

        for (List<Integer> element: result) { 
            for (int e: element) {
                System.out.printf("%d:", e);       
            }
		    System.out.println();       
        }
    }
}
