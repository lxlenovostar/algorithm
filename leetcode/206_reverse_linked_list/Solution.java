/*
// Definition for a Node.
*/

class Solution {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode reverseList(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = null;

        ListNode cur = head;

        while (cur != null) {
            ListNode next = cur.next;
            cur.next = dummy.next;

            dummy.next = cur;
            cur = next;
        }

        return dummy.next;
    }

    public static void main(String[] args) {
        ListNode a1 = new ListNode(1);
        ListNode a2 = new ListNode(2);
        ListNode a3 = new ListNode(3);
        ListNode a4 = new ListNode(4);
        ListNode a5 = new ListNode(5);

        a1.next = a2;
        a2.next = a3;
        a3.next = a4;
        a4.next = a5;

        Solution test = new Solution();
        test.reverseList(a1);
    }

}