/*
 162. Find Peak Element

 A peak element is an element that is greater than its neighbors.
 Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 The array may contain multiple peaks, in that case return the index to any one of the 
 peaks is fine.
 You may imagine that num[-1] = num[n] = -∞.
 For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return 
 the index number 2.

 Note:
 Your solution should be in logarithmic complexity.
 */

import java.util.*;

public class Solution {
    public int findPeakElement(int[] nums) {
        if (nums == null || nums.length == 0 || nums.length == 1) {
            return 0;
        }

		if (nums.length == 2) {
			if (nums[0] > nums[1])
				return 0;
			else 
				return 1;
		}   

		int low = 0;
		int high = nums.length - 1;
		int index = low + (high - low)/2;

		while (low < high) {
			int mid = low + (high - low)/2;
        	System.out.printf("start mid:%d low:%d high:%d index:%d\n", mid, low, high, index);       
		
			if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) 
				return index;
			else if (nums[mid] > nums[mid-1]){ 
				low = mid + 1;
				index = low + (high - low)/2;
			} else {
				high = mid - 1;
				index = low + (high - low)/2;
			}
        	
			System.out.printf("end mid:%d low:%d high:%d index:%d\n", mid, low, high, index);       
		}
 
        return index;
    }

    public static void main(String[] args)
    {
        //int[] a =  {1, 2, 3, 1}; 
        //int result = Solution.findPeakElement(a);
        //System.out.printf("%d:\n", result);       
    }
}

