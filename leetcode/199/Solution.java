import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Map;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
 
    public List<Integer> rightSideView(TreeNode root) {
        ArrayList<Integer> ret = new ArrayList<>();

        if (root == null)
            return ret;
        
        int currentLevel = 0;
        helper(root, currentLevel, ret);

        return ret;
    }
    
    private Map<Integer, Boolean> check = new HashMap<>();

    private void helper(TreeNode node, int level, ArrayList<Integer> returnValue) {
        if (node == null)
            return;
        
        if (check.containsKey(level) == false) {
            check.put(level, true);
            returnValue.add(node.val);
        }

        helper(node.right, level+1, returnValue);
        helper(node.left, level+1, returnValue);
    } 

    public static void main(String[] args) {
        TreeNode a1 = new TreeNode(1);
        TreeNode a2 = new TreeNode(2);
        TreeNode a3 = new TreeNode(3);
        TreeNode a4 = new TreeNode(4);
        TreeNode a5 = new TreeNode(5);

        a1.left = a2;
        a1.right = a3;

        a2.right = a5;
        a3.right = a4;

        Solution test = new Solution();
        List<Integer> ret = test.rightSideView(a1);

        for (Integer r : ret) {
            System.out.println(r);
        }
    }

}