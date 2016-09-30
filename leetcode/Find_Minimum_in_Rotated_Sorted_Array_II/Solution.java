/*
154. Find Minimum in Rotated Sorted Array II

Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
 */

import java.util.*;

public class Solution {
	public static int findMin(int[] nums) {
		int result = nums[0];

		for(int i = 0; i < nums.length -1; i++) {
			if (nums[i] > nums[i+1]) {
				result = nums[i+1];
				return result;		
			}
		}        

		return result;
    }

    public static void main(String[] args)
    {
        //int[] a1 = {4, 5, 6, 7, 0, 1, 2};
        int[] a1 = {4, 5, 6, 7, 7, 1, 2};
        //int[] a1 = {3, 4, 5, 2, 1};


        int result = Solution.findMin(a1);

        System.out.printf("%d:\n", result);       
    }
}
