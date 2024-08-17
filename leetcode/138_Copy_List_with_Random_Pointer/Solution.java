import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public static class Node {
        int val;
        Node next;
        Node random;

        public Node(int val) {
            this.val = val;
            this.next = null;
            this.random = null;
        }
    }

    public Node copyRandomList(Node head) {

        if (head == null)
            return null;

        Node cur = head;
        ArrayList<Node> tmpList = new ArrayList<Node>();
        Map<Node, Integer> tmpMap = new HashMap<Node, Integer>();

        int index = 0;
        while (cur != null) {
            Node newNode = new Node(cur.val);
            tmpList.add(newNode);

            tmpMap.put(cur, index); 
            ++index;

            cur = cur.next;
        }

        for (int i = 0; i < tmpList.size() - 1; ++i) {
            tmpList.get(i).next = tmpList.get(i+1);
        }
        
        cur = head;
        int i = 0;
        while (cur != null) {

            if (cur.random == null) {
                tmpList.get(i).random = null;
            } else {
                int randIndex = tmpMap.get(cur.random);
                tmpList.get(i).random = tmpList.get(randIndex); 
            }
            cur = cur.next;
            ++i;
        }

        return tmpList.get(0);
    }

    public static void main(String[] args) {
        int target = 3;
        Node a1 = new Node(7);
        Node a2 = new Node(13);
        Node a3 = new Node(11);
        Node a4 = new Node(10);
        Node a5 = new Node(1);

        a1.next = a2;
        a2.next = a3;
        a3.next = a4;
        a4.next = a5;

        a2.random = a1;
        a3.random = a5;
        a4.random = a3;
        a5.random = a1;

        Solution test = new Solution();
        test.copyRandomList(a1);
    }

}