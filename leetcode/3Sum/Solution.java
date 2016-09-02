/*
 * 15. 3Sum 
 *
 * Description:
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * 将时间复杂度从3次方下降到2次方。
 *
 *
 java 中如何用泛型
 */

public class Solution {
     public static List<List<Integer>> threeSum(int[] nums) {
        HashMap<Integer, Integer [2]> map = new HashMap<>();

        int[] temp; 
        for (int i = 0; i < nums.length; ++i) {
            for (int j = i+1; j < nums.length; ++j) {
            if (map.get(nums[i] + nums[j]) != null) {
                continue;
            }
            temp = new int[2];
            temp[0] = nums[i];
            temp[1] = nums[j];
            map.put((nums[i] + nums[j]), temp);
        }

       
    }
}

    public static void main(String[] args)
    {
        int[] a1 = new int[4];
		a1[0] = 2;
		a1[1] = 7;
		a1[2] = 11;
		a1[3] = 15;
    
        int[] a2;
        /*a2 = Solution.twoSum(a1, 9);

        for (int i = 0; i < 2; i++)
            System.out.printf("%d:", a2[i]);       
		System.out.println();       
        */
    }
}
