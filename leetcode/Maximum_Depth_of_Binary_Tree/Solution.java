/*
 104. Maximum Depth of Binary Tree

 Given a binary tree, find its maximum depth.

 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 1. 如何新建一个树
 2. 定义一个树的类
 */

import java.util.*;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
	public int find_left(TreeNode node, depth) {
			if (node->left == null)
				return depth;
			else 
				maxDepth(node->left);
	}

	public int find_right(TreeNode node, depth) {
			if (node->right == null)
				return depth;
			else 
				maxDepth(node->right);
	}

	public int maxDepth(TreeNode root) {
		int left_max, right_max;

		left_max = find_left(root->left, 0);
		right_max = find_right(root->right, 0);

		if (left_max >= right_max)
			return left_max;
		else 
			return right_max;
    }

	
    public static void main(String[] args)
    {
        //int[] a =  {1, 2, 3, 1}; 
        //int result = Solution.findPeakElement(a);
        //System.out.printf("%d:\n", result);       
    }
}

