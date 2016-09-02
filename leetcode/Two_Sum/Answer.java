/*
 * 1.Two Sum.
 *
 * Description:
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 *
 * 使用空间换时间
 */

public class Answer {
    public static int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; ++i) {
            if (map.get(nums[i]) != null) {
                int[] result = {map.get(nums[i]), i};
                return result;
            }
            map.put(target - nums[i], i);
        }

        int[] result = {};
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
        a2 = Answer.twoSum(a1, 9);

        for (int i = 0; i < 2; i++)
            System.out.printf("%d:", a2[i]);       
		System.out.println();       
    }
}
