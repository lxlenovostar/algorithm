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

		System.out.println("begin print array");       
		for (int j : nums)
			System.out.printf("%d:", j);       
		System.out.println();       

		if (mid + 1 > nums.length) {
			System.out.printf("fuck0.1 mid:%d\n", mid);       
			return nums[mid];
		} else if (mid - 1 < 0) {
			System.out.printf("fuck0.2 mid:%d value nums[mid]:%d\n", mid, nums[mid]);       
			return nums[mid];
		}
		if (nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]) {
			System.out.printf("fuck0 mid:%d\n", mid);       
			return nums[mid];
		}
		else {
			if (nums[mid+1] < nums[mid-1]) {
				System.out.printf("fuck1 mid:%d\n", mid);       
				int[] dst_nums = new int[mid];
				System.arraycopy(nums, mid+1, dst_nums, 0, mid);
				
				System.out.println("print array");       
				for (int j : dst_nums)
					System.out.printf("%d:", j);       
				System.out.println();       

				result = findMin(dst_nums);
			}
			else {
				System.out.printf("fuck2 mid:%d\n", mid);       
				int[] dst_nums = new int[mid];
				System.arraycopy(nums, 0, dst_nums, 0, mid);

				System.out.println("print array");       
				for (int j : dst_nums)
					System.out.printf("%d:", j);       
				System.out.println();       
				
				result = findMin(dst_nums);
			}
		} 

		return result;
    }

    public static void main(String[] args)
    {
        //int[] a1 = {4, 5, 6, 7, 1, 2, 3};
        int[] a1 = {4, 5, 1, 2};
        //int[] a1 = {3, 4, 5, 2, 1};


        int result = Solution2.findMin(a1);

        System.out.printf("%d:\n", result);       
    }
}
