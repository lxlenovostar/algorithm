/*
 106. Construct Binary Tree from Inorder and Postorder Traversal

 Given inorder and postorder traversal of a tree, construct the binary tree.

 Note:
 You may assume that duplicates do not exist in the tree.

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
		if (start < end || start < 0)
			return -1;

		for (int i = start; i <= end; i++) {
			if (src[i] == key) {
				return i;
			}
		} 

		return -1;
	}

	private TreeNode help_BuildTree(int[] inorder, int instart, int inend, int[] postorder, int poststart, int postend) {
		if (instart > inend || postend < 0) {
            return null;
        }

        TreeNode root = new TreeNode(postorder[postend]);
        int position = findPosition(inorder, instart, inend, postorder[postend]);

		root.left = help_BuildTree(inorder, instart, position, postorder, poststart, poststart + (position - instart - 1)); 
		root.right = help_BuildTree(inorder, position+1, inend, postorder, poststart + (position - instart - 1) + 1, postend - 1); 

		return root;
	}

	public TreeNode buildTree(int[] inorder, int[] postorder) {
		/*
		 通过postorder可以把inorder切成左右子树，得到左子树的前序和后序，
　　　　 然后
		 */        
		if (inorder.length != postorder.length) {
            return null;
        }

        return help_BuildTree(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);

		/*int i, left_len, right_len;
		int root = postorder[postorder.length -1];
		this.put(root);

		for(i = 0; i < inorder.length; i++) {
			if (inorder[i] == root)
				break;
			else {
				//BUG
			}
		}	

		left_len = i + 1;
		right_len = inorder.length - left_len - 1;

		int[] inorder_left = new int[left_len];
		System.arraycopy(inorder, );
		int[] postorder_left = new int[left_len];

		int[] inorder_right = new int[right_len];
		int[] postorder_right = new int[right_len];

		buildTree(inorder_left, postorder_left);
		buildTree(inorder_right, postorder_right);
		*/
    }
	
    public static void main(String[] args)
    {
		int result;
		Solution so = new Solution();

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

		int[] inorder = {4, 2, 5, 1, 6, 3, 7}; 
		int[] postorder = {4, 5, 2, 6, 7, 3, 1};

	 	so.root = so.buildTree(inorder, postorder);
 
        System.out.printf("\nnew begin\n");       
		result = so.maxDepth();
        System.out.printf("maxdepth:%d\n", result);       
		 
		for (int i : so.levelOrder())
        	System.out.printf("%d:", i);       
    }
}
