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

public class Solution {
    public static int searchInsert(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        if (target <= nums[0])
            return 0;
        else if (target >= nums[nums.length - 1])
            return nums.length;
        else {
            for (int i = 1; i < nums.length ; i ++) {
                if (target <= nums[i])
                    return i;
                else 
                    continue;
            }
        }
    }

    public static void main(String[] args)
    {
    
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

        int result = Solution.searchInsert(a, target);
        
        System.out.printf("%d:\n", result);       
    }
}

