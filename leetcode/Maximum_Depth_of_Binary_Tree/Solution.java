/*
 104. Maximum Depth of Binary Tree

 Given a binary tree, find its maximum depth.

 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 TODO:
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

public class Solution{
    public TreeNode root;
 
	public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
 	} 
	
	public void put(int key) {
		root = put(root, key);
	}

	private TreeNode put(TreeNode x, int key) {
		if (x == null) { 
        	//System.out.printf("fuck1\n");       
			return new TreeNode(key);
		}

		int cmp = key - x.val;
		if (cmp < 0) {
        	//System.out.printf("fuck2 x:%d\n", x.val);       
			x.left = put(x.left, key);
		}
		else if (cmp > 0) {
        	//System.out.printf("fuck3 x:%d\n", x.val);       
			x.right = put(x.right, key);
	    }
		else { 
        	//System.out.printf("fuck4 x:%d\n", x.val);       
			x.val = key;
		}

		return x;
	}

	public boolean get(int key) {
		return get(root, key);
	}

	private boolean get(TreeNode x, int key) {
		if (x == null) { 
        	//System.out.printf("get1\n");       
			return false;
		}

		int cmp = key - x.val;
		if (cmp < 0) { 
        	//System.out.printf("get2, x:%d\n", x.val);       
			return get(x.left, key);
		}
		else if (cmp > 0) { 
        	//System.out.printf("get3, x:%d\n", x.val);       
			return get(x.right, key);
		}
		else { 
        	//System.out.printf("get4, x:%d\n", x.val);       
			return true;
		}
	}

   /** 
     * Returns the keys in the BST in level order (for debugging).
     *
     * @return the keys in the BST in level order traversal
     */
    public Iterable<Integer> levelOrder() {
        Queue<Integer> keys = new Queue<Integer>();
        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.enqueue(root);
        while (!queue.isEmpty()) {
            TreeNode x = queue.dequeue();
            if (x == null) continue;
            keys.enqueue(x.val);
            queue.enqueue(x.left);
            queue.enqueue(x.right);
        }
        return keys;
    }  

	private int get_maxdepth(TreeNode node, int depth)
	{
		int left_depth = depth + 1;
		int right_depth = depth + 1;

		if (node == null) {
			return depth;
		}

		left_depth = get_maxdepth(node.left, depth+1);	
	
		right_depth = get_maxdepth(node.right, depth+1);	

		if (left_depth >= right_depth)
			return left_depth;
		else 
			return right_depth;
	}

	public int maxDepth() {
		int maxdepth = get_maxdepth(root, 0);
		return maxdepth;
    }

	
    public static void main(String[] args)
    {
		Solution so = new Solution();
		int result;

		so.put(0);

		/*
		so.put(2);
        System.out.printf("\n");       
		so.put(3);
        System.out.printf("\n");       
		so.put(1);

		int result = so.get(1) == true ? 1 : 0;
        System.out.printf("%d\n", result);       
		result = so.get(3) == true ? 1 : 0;
        System.out.printf("%d\n", result);       
		result = so.get(2) == true ? 1 : 0;
        System.out.printf("%d\n", result);       
		*/

        System.out.printf("\nnew begin\n");       
		result = so.maxDepth();
        System.out.printf("maxdepth:%d\n", result);       
		 
		/*
		for (int i : so.levelOrder())
        	System.out.printf("%d:", i);       
		*/
    }
}

