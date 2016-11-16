/*
 34. Search for a Range

 Given a sorted array of integers, find the starting and ending position of a given target value.

 Your algorithm's runtime complexity must be in the order of O(log n).

 If the target is not found in the array, return [-1, -1].

 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].
 */

import java.util.*;

public class Solution {
    public static int[] searchRange(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return {-1, -1};
        }
        
        boolean flag = false;
        int start = 0, end = nums.length - 1;
        while (start + 1 < end) {
            /* 计算mid的方法 */
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                flag = true;
                break;
            } else if (nums[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (flag == false) {
            if (nums[end] == target) {
                //row = end;
            } else if (nums[start] == target) {
                //row = start;
            } else {
                return {-1, -1};
            }
        }
        
        return {-1, -1};
    }

    public static void main(String[] args)
    {
        /*int [][] a = {
                {1,   3,  5,  7},
                {10, 11, 16, 20},
                {23, 30, 34, 50}
        boolean result = Solution.searchMatrix(a, 6);
        System.out.printf("%d:\n", result == true ? 0: 1);       
        */
    }
}

