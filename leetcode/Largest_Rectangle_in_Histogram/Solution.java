/*
	84. Largest Rectangle in Histogram
 */

import java.util.*;

public class Solution {
	public static int largestRectangleArea(int[] heights) { 
		int result = 0;
		int len = heights.length;
	
		for (int i = 0; i < len; i++) {
			int area = 0;
			int length = 0;

			for (int j =0; j < len; j++) {
					if (heights[j] >= heights[i]) 
						length++;
					else {
						if (j <= i) {
							length = 0;
							continue;
						}
						else 
							break;
					}
			}
				area = length * heights[i];
        		System.out.printf("ares:%d\n", area);       
				if (area >= result)
					result = area;
		}			
		

		return result;
    }

    public static void main(String[] args)
    {
        //int[] a = {2, 1, 5, 6, 2, 3};
        //int[] a = {1};
        //int[] a = {0};
        int[] a = {2, 0, 2};

        int result = Solution.largestRectangleArea(a);

        System.out.printf("%d:\n", result);       
    }
}
