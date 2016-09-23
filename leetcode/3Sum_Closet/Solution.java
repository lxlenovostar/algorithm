/*
 * 16. 3Sum Closest
 *
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *	
 * 将时间复杂度从3次方下降到2次方。
 */
import java.util.*;
import java.lang.Integer;

public class Solution {
	 public static int threeSumClosest(int[] nums, int target) {
		int min_intval = Integer.MAX_VALUE;
		int result = 0;

        if(nums == null || nums.length < 3) {
            return result;
        }

        Arrays.sort(nums); 

        for (int i = 0; i < nums.length - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue; // to skip duplicate numbers; e.g [0,0,0,0]
            }

            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];

    			System.out.printf("fuck0 sum is:%d, left is:%d, rigth is:%d\n", sum, left, right);       
                if (Math.abs(sum - target) <= min_intval) {
					min_intval = Math.abs(sum - target);
					result = sum;
                } 
	
				// 如何移动left, right 是关键？？
                left++;
                right--;

				/*
				while (left < right && nums[left] == nums[left - 1]) { // to skip duplicates
                    left++;
                }

                while (left < right && nums[right] == nums[right + 1]) { // to skip duplicates
                    right--;
               	} 

				*/
            }
        }

        return result;
    }

    public static void main(String[] args)
    {
        //int[] a1 = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
        //int[] a1 = {-1, 2, 1, -4};
        //int[] a1 = {1, 1, 1, 0};
        //int[] a1 = {0, 0, 0, 0};
        int[] a1 = {0, 2, 1, -3};

        int result = Solution.threeSumClosest(a1, 1);

        System.out.printf("%d:", result);       
    	System.out.println();       
    }
}
