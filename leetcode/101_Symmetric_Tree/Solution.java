/*
 101. Symmetric Tree

 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

 Note:
 Bonus points if you could solve it both recursively and iteratively.

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
			return new TreeNode(key);
		}

		int cmp = key - x.val;
		if (cmp < 0) {
			x.left = put(x.left, key);
		}
		else if (cmp > 0) {
			x.right = put(x.right, key);
	    }
		else { 
			x.val = key;
		}

		return x;
	}

	public boolean get(int key) {
		return get(root, key);
	}

	private boolean get(TreeNode x, int key) {
		if (x == null) { 
			return false;
		}

		int cmp = key - x.val;
		if (cmp < 0) { 
			return get(x.left, key);
		}
		else if (cmp > 0) { 
			return get(x.right, key);
		}
		else { 
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
            if (x == null) {
				/* -1 stands for null node. */
				keys.enqueue(-1);
				continue;
			}
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

	public boolean isSymmetric(TreeNode root) {
		if (root == null) 
			return true;
				         
		ArrayList<TreeNode> Q1 = new ArrayList<TreeNode>();
		ArrayList<TreeNode> Q2 = new ArrayList<TreeNode>();
		
		Q1.add(root);
		while (Q1.size() != 0) {
	    	ArrayList<Integer> level = new ArrayList<Integer>();
		    Q2.clear();

		    for (int i = 0; i < Q1.size(); i++) {
		    	TreeNode node = Q1.get(i);
				if (node == null) {
					level.add(-1);
				} else {
					level.add(node.val);
				
					if (node.left != null) {
				    	Q2.add(node.left);
					} else {
						Q2.add(null);
					} 

					if (node.right != null) {
						Q2.add(node.right);
					} else {
						Q2.add(null);
					}
				}
			}
				
			ArrayList<TreeNode> temp = Q1;
			Q1 = Q2;
			Q2 = temp;

			for (int i = 0; i < level.size(); i++) 
				System.out.printf(";%d\n", level.get(i));

			int j = level.size() - 1;	
			for (int i = 0; i < level.size()/2; i++) {
				if (level.get(i) != level.get(j))
					return false;
				j--;
			}
		}

		return true;
	}

	private boolean help_symmetric(TreeNode left, TreeNode right) {
		if (left == null && right == null)
			return true;

		if (left == null || right == null)
			return false;

		boolean cond1 = (left.val == right.val);
		boolean cond2 = help_symmetric(left.left, right.right);
		boolean cond3 = help_symmetric(left.right, right.left);

		return (cond1 && cond2 && cond3);
	}

	public boolean r_isSymmetric(TreeNode root) {
		if (root == null)
			return true;

		return help_symmetric(root.left, root.right);
	}
    	
	public boolean i_isSymmetric(TreeNode root) {
		if (root == null)
			return true;
	
		if (root.left == null && root.right == null)	
			return true;

		if (root.left == null || root.right == null)	
			return false;

		ArrayList<TreeNode> Q1 = new ArrayList<TreeNode>();
		ArrayList<TreeNode> Q2 = new ArrayList<TreeNode>();

		Q1.add(root.left);
		Q2.add(root.right);

		while(!Q1.isEmpty() && !Q2.isEmpty()) {
			TreeNode left = Q1.get(0);
			TreeNode right = Q2.get(0);
					
			Q1.remove(0);
			Q2.remove(0);

			if ((left == null && right != null) || (right == null && left != null))
					return false;

			if (left == null && right == null) {
				continue;
			}
			else  {
				if (left.val != right.val)
					return false;
			
				Q1.add(left.left);	
				Q1.add(left.right);	
				Q2.add(right.right);	
				Q2.add(right.left);	
			}
		}

		return true;
	}
 
	public static void main(String[] args)
    {
    }
}
