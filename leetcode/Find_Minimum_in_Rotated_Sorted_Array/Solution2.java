/*
 * 153. Find Minimum in Rotated Sorted Array
 *
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

采用二分查找法, 考虑时间复杂度
 */

import java.util.*;
import java.lang.*;

public class Solution2 {
	public static int findMin(int[] nums) {
		int result = nums[0];

		int mid = nums.length / 2;

		System.out.printf("begin print array, mid:%d\n", mid);       
		for (int j : nums)
			System.out.printf("%d:", j);       
		System.out.println();       

		if (nums.length == 1) {
			System.out.printf("fuck0.1 mid:%d\n", mid);       
			return result;
		} else if (nums.length == 2) {
			System.out.printf("fuck0.2 mid:%d\n", mid);       
			if (nums[0] <= nums[1])
				return nums[0];
			else 
				return nums[1];
		} else if (nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]) {
			System.out.printf("fuck0 mid:%d\n", mid);       
			return nums[mid];
		}
		else {
			int[] dst_nums_left = new int[mid];
			System.arraycopy(nums, mid+1, dst_nums_left, 0, (nums.length -1 - mid));
				
			System.out.println("left print array");       
			for (int j : dst_nums_left)
				System.out.printf("%d:", j);       
			System.out.println();       

			int[] dst_nums_right = new int[mid];
			System.arraycopy(nums, 0, dst_nums_right, 0, mid);

			System.out.println("right print array");       
			for (int j : dst_nums_right)
				System.out.printf("%d:", j);       
			System.out.println();       
				
			int result_left = findMin(dst_nums_left);
			int result_right = findMin(dst_nums_right);

			if (result_left <= result_right)
				result = result_left;
			else 
				result = result_right;
	
		} 

		return result;
    }

    public static void main(String[] args)
    {
        //int[] a1 = {4, 5, 6, 7, 1, 2, 3};
        //int[] a1 = {3, 4, 5, 6, 1, 2 };
        //int[] a1 = {2, 3, 4, 5, 1};
        //int[] a1 = {4};
        //int[] a1 = {1, 2};
        //int[] a1 = {5, 1, 2, 3, 4};
        int[] a1 = {1, 2, 3, 4, 5, 6};


        int result = Solution2.findMin(a1);

        System.out.printf("%d:\n", result);       
    }
}
