/*
 * 18. 4Sum 
 *
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
 */

import java.util.*;

public class Solution {
     public static List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> rst = new ArrayList<List<Integer>>();
		int min_intval = Integer.MAX_VALUE;
        
		if(nums == null || nums.length < 4) {
            return rst;
        }

        Arrays.sort(nums); 

        for (int j = 0; j < nums.length - 3; j++) {
			if (j != 0 && nums[j] == nums[j - 1]) {
					continue; // to skip duplicate numbers; e.g [0,0,0,0]
				}
			for (int i = j + 1; i < nums.length - 2; i++) {
					/*if (i != 0 && nums[i] == nums[i - 1]) {
						continue; // to skip duplicate numbers; e.g [0,0,0,0]
					}*/

					int left = i + 1;
					int right = nums.length - 1;

               		System.out.printf("j:%d i:%d left:%d right:%d\n", j, i, left, right);       
               		System.out.printf("j_value:%d i_value:%d left_value:%d right_value:%d\n", nums[j], nums[i], nums[left], nums[right]);       

					 while (left < right) {
                		int sum = nums[left] + nums[right] + nums[i] + nums[j];

                //System.out.printf("sum:%d i:%d i_value:%d left:%d left_value:%d rigth:%d right_value:%d\n", sum, i, nums[i], left, nums[left], right, nums[right]);       
                		if (Math.abs(sum - target) <= min_intval) {
                    		min_intval = Math.abs(sum - target);
                    		result = sum;
                		}   
        
                		if (sum >= target) { 
                    		right--;
                    		while (left < right && nums[right] == nums[right + 1]) { // to skip duplicates
                        		right--;
                    	}   
                		} else {
                    		left++;
                    		while (left < right && nums[left] == nums[left - 1]) { // to skip duplicates
                        		left++;
                    		}   
                		}   
					}
			}
		}

        return rst;
    }

    public static void main(String[] args)
    {
        //int[] a1 = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
        //int[] a1 = {1, 0, -1, 0, -2, 2};
        int[] a1 = {-2, -1, 0, 0, 1, 2};
        //int[] a1 = {0, 0, 0, 0, 0};
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
