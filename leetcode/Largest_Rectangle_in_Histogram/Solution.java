/*
	84. Largest Rectangle in Histogram
 */

import java.util.*;

public class Solution {
	public static int largestRectangleArea(int[] heights) { 
		int result = 0;

		if (heights.length <= 0)
			return result;
		else if (heights.lengt == 1)
			return heights[0];
	
		/*
         应该从大到小排序，然后计算最大值旁边的长方形面积，依次降低。
         */			

		return result;
    }

    public static void main(String[] args)
    {
        int[] a = {2, 1, 5, 6, 2, 3};

        int result = Solution.largestRectangleArea(a);

        System.out.printf("%d:\n", result);       
    }
}
