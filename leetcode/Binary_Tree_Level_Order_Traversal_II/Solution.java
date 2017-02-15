/*
 107. Binary Tree Level Order Traversal II

 Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
 (ie, from left to right, level by level from leaf to root).

 TODO:
	1.理解深度和广度优先的时间空间复杂度　
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

	/* 迭代不用返回回来 */
	private int get_maxdepth(TreeNode node, int depth)
	{
		int left_depth = depth + 1;
		int right_depth = depth + 1;

		if (node == null) {
			return depth;
		}

		left_depth = get_maxdepth(node.left, depth+1);	
		right_depth = get_maxdepth(node.right, depth+1);	

        return Math.max(left_depth, right_depth);
	}

	public int maxDepth() {
		int maxdepth = get_maxdepth(root, 0);
		return maxdepth;
    }

	public int maxDepth_1(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int left = maxDepth_1(root.left);
        int right = maxDepth_1(root.right);
        return Math.max(left, right) + 1;
    }

	/* anthor way. */
	private int depth;
    
    public int maxDepth_2(TreeNode root) {
        depth = 0;
        helper(root, 1);
        
        return depth;
    }
    
    private void helper(TreeNode node, int curtDepth) {
        if (node == null) {
            return;
        }
        
        if (curtDepth > depth) {
            depth = curtDepth;
        }
        
        helper(node.left, curtDepth + 1);
        helper(node.right, curtDepth + 1);
    }	

	private int findPosition(int[] src, int start, int end, int key) {
        //System.out.printf("start:%d end:%d key:%d\n", start, end, key);       
		if (end < start || start < 0)
			return -1;

		for (int i = start; i <= end; i++) {
			if (src[i] == key) {
				return i;
			}
		} 

		return -1;
	}

	private TreeNode help_BuildTree(int[] preorder, int prestart, int preend, int[] inorder, int instart, int inend) {
		if (instart > inend || preend < 0 || prestart < 0) {
            return null;
        }

        TreeNode root = new TreeNode(preorder[prestart]);
        int position = findPosition(inorder, instart, inend, preorder[prestart]);
        //System.out.printf("instart:%d inend:%d prestart:%d preend:%d position:%d\n", instart, inend, prestart, pretend, position);       

		root.left = help_BuildTree(preorder, prestart+1, prestart + 1 + (position - instart - 1), inorder, instart, position -1 );
		root.right = help_BuildTree(preorder, prestart + 1 + (position - instart - 1) + 1, preend, inorder, position + 1, inend);

		return root;
	}

	public TreeNode buildTree(int[] preorder, int[] inorder) {
		/*
		 通过preorder可以把inorder切成左右子树，得到左子树的前序和后序，
　　　　 然后
		 */        
		if (inorder.length != preorder.length) {
            return null;
        }

        return help_BuildTree(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }

	public List<List<Integer>> levelOrderBottom(TreeNode root) {
		Queue q = new LinkedList();

		List<List<Integer>> result = new ArrayList<List<Integer>>();
		int level = 0;

		if (root == null)
			return result;

		ArrayList<TreeNode> Q1list = new ArrayList<TreeNode>();
		ArrayList<TreeNode> Q2list = new ArrayList<TreeNode>();
		Q1list.add(root);		

		while(!Q1list.isEmpty()) {
			ArrayList<Integer> q_result = new ArrayList<Integer>(); 
			Q2list.clear();

			for (int i = 0; i < Q1list.size(); i++) {
				TreeNode node = Q1list.get(i);
				q_result.add(node.val);

				if (node.left != null)
					Q2list.add(node.left);
				
				if (node.right != null)
					Q2list.add(node.right);
			}

			//swap q1 and q2 
			ArrayList<TreeNode> temp = Q1list;
			Q1list = Q2list;
			Q2list = temp;
		
			if (result.size() == 0)
               	result.add(q_result);
			else { 
               	result.add(result.size() - level - 1, q_result);
				++level;
			}
		}

		return result;
	}

    public static void main(String[] args)
    {
		/*
        System.out.printf("\nnew begin\n");       
		result = so.maxDepth();
        System.out.printf("maxdepth:%d\n", result);       
		*/

		/*
		so.put(0);
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
    }
}
