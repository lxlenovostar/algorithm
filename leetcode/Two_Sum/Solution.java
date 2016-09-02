/*
 * 1.Two Sum.
 *
 * Description:
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 *
 */

public class Solution {
    public static int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        int num1 = 0; 
        int num2 = 0;
        boolean out_flag = false;

        for (int i = 0; i < nums.length; ++i) {
            num1 = i;
            for (int j = i+1; j < nums.length; ++j) {
                if (nums[i] + nums[j] == target) {
                    num2 = j;
                    //System.out.printf("num1 %d, num2 %d", num1, num2);       
		            //System.out.println();       
                    out_flag = true;
                    break;
                }
            }
            if (out_flag)
                break;
        }
        result[0] = num1;
        result[1] = num2;

        return result;
    }

    public static void main(String[] args)
    {
        int[] a1 = new int[4];
		a1[0] = 2;
		a1[1] = 7;
		a1[2] = 11;
		a1[3] = 15;
    
        int[] a2;
        a2 = Solution.twoSum(a1, 9);

        for (int i = 0; i < 2; i++)
            System.out.printf("%d:", a2[i]);       
		System.out.println();       
    }
}
