/*
 * 15. 3Sum 
 *
 * Description:
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * 将时间复杂度从3次方下降到2次方。
 *
 *
 0.看看 arraylist
 1.迭代器的使用 ？？
 */
import java.util.*;

public class Solution {
     public static List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> threesum = new ArrayList<List<Integer>>();    
        //List<List<Integer>> 3sum = new ArrayList<>();
        HashMap<Integer, int[]> map = new HashMap<Integer, int[]>();
        
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

        for (int i = 0; i < nums.length; ++i) {
            if (map.get(-nums[i]) != null) {
                List<Integer> result = new ArrayList<Integer>();
                result.add(nums[i]);
                int[] value = map.get(-nums[i]);
                result.add(value[0]);
                result.add(value[1]);

                threesum.add(result);
            }
        }

        return threesum;
    }

    public static void main(String[] args)
    {
        int[] a1 = new int[6];
		a1[0] = -1;
		a1[1] = 0;
		a1[2] = 1;
		a1[3] = 2;
		a1[4] = -1;
		a1[5] = -4;
    
        List<List<Integer>> result;
        result = Solution.threeSum(a1);

        for (Iterator<List<Integer>> iter = result.iterator(); iter.hashNext();) {
            List<Integer> element = iter.next();
            for (Iterator<Integer> inner_iter = element.iterator(); inner_iter.hashNext();) {
                int e = inner_iter.next();
                System.out.printf("%d:", e);       
            }
		    System.out.println();       
        }
    }
}
