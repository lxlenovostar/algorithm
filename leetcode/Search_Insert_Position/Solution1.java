/*
 35. Search Insert Position

 Given a sorted array and a target value, return the index if the target is found. 
 If not, return the index where it would be if it were inserted in order.

 You may assume no duplicates in the array.

 Here are few examples.
 [1,3,5,6], 5 → 2
 [1,3,5,6], 2 → 1
 [1,3,5,6], 7 → 4
 [1,3,5,6], 0 → 0
 */

import java.util.*;

public class Solution1 {
    public static int searchInsert(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

		if (nums.length == 1) {
			if (target <= nums[0])
				return 0;
			else 
				return 1;
		}

		int low = 0;
		int high = nums.length - 1;
		int index = low + (high - low)/2;
		while (low <= high) {
			int mid = low + (high - low)/2;

			if (nums[mid] == target) 
				return index;
			else if (nums[mid] > target) {
				high = mid - 1;
				index = low + (high - low)/2;
			}
			else { 
				low = mid + 1;
				index = low + (high - low)/2;
			}
		}
    
        return index;
    }

    public static void main(String[] args)
    {
        int[] a =  {1, 3}; 
        int target = 3;

		/*
        int[] a =  {1, 3, 5, 6}; 
        int target = 5;
		*/

		/*
        int[] a =  {1, 3, 5, 6}; 
        int target = 2;
		*/

		/*
        int[] a =  {1, 3, 5, 6}; 
        int target = 7;
		*/

		/*
        int[] a =  {1, 3, 5, 6}; 
        int target = 0;
		*/

        int result = Solution1.searchInsert(a, target);
        
        System.out.printf("%d:\n", result);       
    }
}

