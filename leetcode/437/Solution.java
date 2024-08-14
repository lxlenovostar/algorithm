

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

    public int pathSum(TreeNode root, int targetSum) {
        if (root == null)
            return 0;
        
        int ret = helper(root, targetSum);
        ret += pathSum(root.left, targetSum);
        ret += pathSum(root.right, targetSum);
        return ret;
    }

    private int helper(TreeNode node, long targetSum) {
        if (node == null)
            return 0;

        int ret = 0;
        //System.out.println("what0 node.val: "+node.val+" current: "+current+" flag: "+flag);
        if (node.val == targetSum) {
            //System.out.println("what 1 node.val: "+node.val+" current: "+current+" flag: " + flag);
            ret++;
        }

        ret += helper(node.left, targetSum - node.val);
        ret += helper(node.right, targetSum - node.val);
        return ret;
    }


    public static void main(String[] args) {
        /* 
        TreeNode a1 = new TreeNode(10);
        TreeNode a2 = new TreeNode(5);
        TreeNode a3 = new TreeNode(-3);
        TreeNode a4 = new TreeNode(3);
        TreeNode a5 = new TreeNode(2);
        TreeNode a6 = new TreeNode(11);
        TreeNode a7 = new TreeNode(3);
        TreeNode a8 = new TreeNode(-2);
        TreeNode a9 = new TreeNode(1);

        a1.left = a2;
        a1.right = a3;

        a2.left = a4;
        a2.right = a5;

        a3.right = a6;

        a4.left = a7;
        a4.right = a8;

        a5.right = a9;

        int target = 8;
        */
        int target = 3;
        TreeNode a1 = new TreeNode(1);
        TreeNode a2 = new TreeNode(2);
        TreeNode a3 = new TreeNode(3);
        TreeNode a4 = new TreeNode(4);
        TreeNode a5 = new TreeNode(5);

        a1.right = a2;
        a2.right = a3;
        a3.right = a4;
        a4.right = a5;

        Solution test = new Solution();
        int ret = test.pathSum(a1, target);
        
        System.out.println("ret="+ret);
    }
}
