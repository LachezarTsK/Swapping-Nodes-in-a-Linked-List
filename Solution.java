
public class Solution {

    public ListNode swapNodes(ListNode head, int k) {

        ListNode current = head;
        ListNode k_distanceFromStart = head;
        ListNode k_distanceFromEnd = null;

        int countNodes = 0;
        while (current != null) {
            if (k_distanceFromEnd != null) {
                k_distanceFromEnd = k_distanceFromEnd.next;
            }
            if (++countNodes == k) {
                k_distanceFromStart = current;
                k_distanceFromEnd = head;
            }
            current = current.next;
        }

        //the requirement is to swap only values
        int temp = k_distanceFromStart.val;
        k_distanceFromStart.val = k_distanceFromEnd.val;
        k_distanceFromEnd.val = temp;

        return head;
    }
}

// Class ListNode is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this class.
class ListNode {

    int val;
    ListNode next;

    ListNode() {}

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
