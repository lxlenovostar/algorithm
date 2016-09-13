/*
 * 15. 3Sum 
 *
 * Description:
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * 将时间复杂度从3次方下降到2次方。
 *
 */
import java.util.*;

public class Solution {
     public static List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> threesum = new ArrayList<List<Integer>>();    

        if (nums.length < 3)
            return threesum;

        HashMap<Integer, int[]> map = new HashMap<Integer, int[]>();
        
        int[] temp; 
        for (int i = 0; i < nums.length; ++i) {
            for (int j = i+1; j < nums.length; ++j) {
                if (map.get(nums[i] + nums[j]) != null) {
                    continue;
                }
            temp = new int[2];

            if (nums[i] <= nums[j]) {
                temp[0] = nums[i];
                temp[1] = nums[j];
            } else {
                temp[0] = nums[j];
                temp[1] = nums[i];
            }

            map.put((nums[i] + nums[j]), temp);
            }
        }

       //just test.
       /*
       for (int e: map.keySet()) {
            System.out.printf("key:%d, value0:%d, value1:%d", e, map.get(e)[0], map.get(e)[1]);       
		    System.out.println();       
       }
       */

        for (int i = 0; i < nums.length; ++i) {
            if (map.get(-nums[i]) != null) {
                List<Integer> result = new ArrayList<Integer>();
            
               int[] value = map.get(-nums[i]);
               if (nums[i] <= value[0]) {
                    result.add(nums[i]);
                    result.add(value[0]);
                    result.add(value[1]);
               } else if (nums[i] <= value[1]) {
                    result.add(value[0]);
                    result.add(nums[i]);
                    result.add(value[1]);
                } else {     
                    result.add(value[0]);
                    result.add(value[1]);
                    result.add(nums[i]);
                }

                if (threesum.indexOf(result) == -1)
                    threesum.add(result);

                //just test.
                /*
                System.out.printf("new version %d:\n", nums[i]);       
                for (List<Integer> element: threesum) { 
                    for (int e: element) {
                        System.out.printf("%d:", e);       
                    }
		            System.out.println();       
                }
		        System.out.println("end version");       
                */
            }
        }

        return threesum;
    }

    public static void main(String[] args)
    {
        /*
        int[] a1 = new int[6];
		a1[0] = -1;
		a1[1] = 0;
		a1[2] = 1;
		a1[3] = 2;
		a1[4] = -1;
		a1[5] = -4;
        */
       
        /* 
        int[] a1 = new int[3];
        a1[0] = -1;
        a1[1] = 1;
        a1[2] = 0;
        */

        int[] a1 = new int[4];
        a1[0] = 1;
        a1[1] = 2;
        a1[2] = -2;
        a1[3] = -1;
        List<List<Integer>> result;
        result = Solution.threeSum(a1);

        /*
        for (Iterator<List<Integer>> iter = result.iterator(); iter.hasNext();) {
            List<Integer> element = iter.next();
            for (Iterator<Integer> inner_iter = element.iterator(); inner_iter.hasNext();) {
                int e = inner_iter.next();
                System.out.printf("%d:", e);       
            }
		    System.out.println();       
        }
        */

        for (List<Integer> element: result) { 
            for (int e: element) {
                System.out.printf("%d:", e);       
            }
		    System.out.println();       
        }
    }
}
