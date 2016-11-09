/*
 121.  Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/


public class Solution {
    public static int maxProfit(int[] prices) {
		int profit = 0;
		int low_price , high_price;

		if (prices.length <= 1)
			return 0;

		low_price = high_price = prices[0];

		for (int i = 1; i < prices.length; i++) {
			if (prices[i] > high_price) high_price = prices[i];
			if (prices[i] < low_price) low_price = prices[i];
		}

        return profit;
    }

    public static void main(String[] args)
    {
        int[] a1 = new int[4];
        int[] a2;
        a2 = Solution.twoSum(a1, 9);

        for (int i = 0; i < 2; i++)
            System.out.printf("%d:", a2[i]);       
		System.out.println();       
    }
}
