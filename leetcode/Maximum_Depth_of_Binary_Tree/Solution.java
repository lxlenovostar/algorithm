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

public class Solution <Key extends Comparable<Key>>{
    public TreeNode root;
 
	public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
 	} 
	
	public void put(Key key) {
		root = put(root, key);
	}

	private TreeNode put(Node x, Key key) {
		if (x == null) return new TreeNode(key);

		int cmp = key.compareTo(x.key);
		if (cmp < 0)
			return x.left = put(x.left, key);
		else if (cmp > 0)
			return x.right = put(x.right, key);
		else 
			x.val = val;

		return x;
	}


	public int maxDepth(TreeNode root) {
    }

	
    public static void main(String[] args)
    {
        //int[] a =  {1, 2, 3, 1}; 
        //int result = Solution.findPeakElement(a);
        //System.out.printf("%d:\n", result);       
    }
}

