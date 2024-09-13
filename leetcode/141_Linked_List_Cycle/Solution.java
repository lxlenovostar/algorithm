import java.util.Set;
import java.util.HashSet;

public class Solution {
    public static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null)
            return false;
        
        Set<ListNode> visited = new HashSet<>();

        while (head != null) {
            if (!visited.contains(head)) {
                visited.add(head);
            } else {
                return true;
            }

            head = head.next;
        }

        return false;
    }

    public static void main(String[] args) {
        ListNode a1 = new ListNode(1);
        ListNode a2 = new ListNode(2);
        ListNode a3 = new ListNode(3);
        ListNode a4 = new ListNode(4);
        a1.next = a2;
        a2.next = a3;
        a3.next = a4;
        a4.next = a1;

        Solution test = new Solution();
        System.out.println(test.hasCycle(a1));     
    }
}