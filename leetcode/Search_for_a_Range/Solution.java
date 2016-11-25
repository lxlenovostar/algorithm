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
    private static void check_array(int[] nums, int target, ArrayList<Integer> r_array, int mid) 
{
        int start = 0, end = nums.length - 1;
        int check_left = mid;
        int check_right = mid;

        while (check_left > start) {
            if (nums[check_left-1] == target) {
                r_array.add(0, check_left-1);
                check_left--;
            } else 
                break;
        }

        while (check_right < end) {
            if (nums[check_right+1] == target) {
                r_array.add(check_right+1);
                check_right++;
            } else 
                break;
        }
    }

    public static int[] searchRange(int[] nums, int target) {
        int[] err_result = {-1, -1}; 
        int[] right_result = new int[2];

        if (nums == null || nums.length == 0) {
            return err_result;
        }

        if (nums.length == 1) {
            if (nums[0] == target) {
                right_result[0] = 0;
                right_result[1] = 0;
                return right_result;
            } else  
                return err_result;
        }

        boolean flag = false;
        int start = 0, end = nums.length - 1;
        int mid = 0;
        ArrayList<Integer> result = new ArrayList<Integer>();
        while (start + 1 < end) {
            /* 计算mid的方法 */
            mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                flag = true;
                break;
            } else if (nums[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (flag == true) {
            result.add(mid);
            /* check left and right */
            check_array(nums, target, result, mid); 

            right_result[0] = result.get(0);
            right_result[1] = result.get(result.size()-1);
            return right_result;
        }
        else {
            if (nums[end] == target && nums[start] == target) {
                right_result[0] = start;
                right_result[1] = end;
                return right_result;
 
            } else if (nums[start] == target) {
                right_result[0] = start;
                right_result[1] = start;
                return right_result;
            } else if (nums[end] == target) {
                right_result[0] = end;
                right_result[1] = end;
                return right_result;
            } else {
                return err_result;
            }
        }
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
    
        /*
        int[] a =  {5, 7, 7, 8, 8, 10}; 
        //int target = 8;
        int target = 1;
        */

        int[] a =  {1, 2, 2}; 
        int target = 2;

        /*
        int[] a =  {1, 2, 3}; 
        int target = 2;
        */

        /* 
        int[] a =  {3, 3, 3}; 
        int target = 3;
        */

        int[] result = Solution.searchRange(a, target);
        
        for (int i = 0; i < result.length; i++)
            System.out.printf("%d:\n", result[i]);       
    }
}

