/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
        if(root==null)return 0;
        if(root.left==null && root.right==null)return 0;
        return preorder(root.left, root) + preorder(root.right, root);
    }
    private int preorder(TreeNode p, TreeNode ans){
        if(p==null)return 0;
        if(p.left==null && p.right==null){
            if(ans.left==p)return p.val;
            return 0;
        }
        return preorder(p.left, p) + preorder(p.right, p);
    }
}