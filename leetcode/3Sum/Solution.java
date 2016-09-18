/*
 * 15. 3Sum 
 *
 * Description:
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * hashmap 后面的值会覆盖前面的值。
 *
 * 将时间复杂度从3次方下降到2次方。
 */
import java.util.*;

public class Solution {
     public static List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> rst = new ArrayList<List<Integer>>();

        if(nums == null || nums.length < 3) {
            return rst;
        }

        Arrays.sort(nums); //?? 这个sort的意思。。

        for (int i = 0; i < nums.length - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue; // to skip duplicate numbers; e.g [0,0,0,0]
            }

            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];

                if (sum == 0) {
                    ArrayList<Integer> tmp = new ArrayList<Integer>();
                    tmp.add(nums[i]);
                    tmp.add(nums[left]);
                    tmp.add(nums[right]);

                    rst.add(tmp);

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) { // to skip duplicates
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1]) { // to skip duplicates
                        right--;
                    }

                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return rst;

        /* 
        List<List<Integer>> threesum = new ArrayList<List<Integer>>();    

        if (nums.length < 3)
            return threesum;

        HashMap<Integer, int[][]> map = new HashMap<Integer, int[][]>();
        
        int[][] temp; 
        for (int i = 0; i < nums.length; ++i) {
            for (int j = i+1; j < nums.length; ++j) {
                if (map.get(nums[i] + nums[j]) != null) {
                    continue;
                }
            temp = new int[2][2];

            if (nums[i] <= nums[j]) {
                temp[0][0] = nums[i];
                temp[0][1] = i;
                temp[1][0] = nums[j];
                temp[1][1] = j;
            } else {
                temp[0][0] = nums[j];
                temp[0][1] = j;
                temp[1][0] = nums[i];
                temp[1][1] = i;
            }

            map.put((nums[i] + nums[j]), temp);
            }
        }

       //just test.
       for (int e: map.keySet()) {
            System.out.printf("key:%d, value0:%d, index0:%d, value1:%d, index1:%d", e, map.get(e)[0][0], map.get(e)[0][1], map.get(e)[1][0], map.get(e)[1][1]);       
		    System.out.println();       
       }

        for (int i = 0; i < nums.length; ++i) {
            if (map.get(-nums[i]) != null) {
               int[][] value = map.get(-nums[i]);
               
               if (i == value[0][1] || i == value[1][1])
                    continue;
 
               List<Integer> result = new ArrayList<Integer>();
            
               if (nums[i] <= value[0][0]) {
                    result.add(nums[i]);
                    result.add(value[0][0]);
                    result.add(value[1][0]);
               } else if (nums[i] <= value[1][0]) {
                    result.add(value[0][0]);
                    result.add(nums[i]);
                    result.add(value[1][0]);
                } else {     
                    result.add(value[0][0]);
                    result.add(value[1][0]);
                    result.add(nums[i]);
                }

                if (threesum.indexOf(result) == -1)
                    threesum.add(result);

                //just test.
                System.out.printf("new version %d:\n", nums[i]);       
                for (List<Integer> element: threesum) { 
                    for (int e: element) {
                        System.out.printf("%d:", e);       
                    }
		            System.out.println();       
                }
		        System.out.println("end version");       
            }
        }

        return threesum;
        */
    }

    public static void main(String[] args)
    {
        /*int[] a1 = new int[6];
		a1[0] = -1;
		a1[1] = 0;
		a1[2] = 1;
		a1[3] = 2;
		a1[4] = -1;
		a1[5] = -4;
        */

        int[] a1 = new int[3];
        a1[0] = -1;
        a1[1] = 1;
        a1[2] = 0;

        /*int[] a1 = new int[4];
        a1[0] = 1;
        a1[1] = 2;
        a1[2] = -2;
        a1[3] = -1;
        */

        //int[] a1 = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};

        List<List<Integer>> result;
        result = Solution.threeSum(a1);

        for (List<Integer> element: result) { 
            for (int e: element) {
                System.out.printf("%d:", e);       
            }
		    System.out.println();       
        }
    }
}
