
// Function ListNode is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this function.
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var swapNodes = function (head, k) {
    let current = head;
    let k_distanceFromStart = head;
    let k_distanceFromEnd = null;

    let countNodes = 0;
    while (current !== null) {
        if (k_distanceFromEnd !== null) {
            k_distanceFromEnd = k_distanceFromEnd.next;
        }
        if (++countNodes === k) {
            k_distanceFromStart = current;
            k_distanceFromEnd = head;
        }
        current = current.next;
    }

    //the requirement is to swap only values
    let temp = k_distanceFromStart.val;
    k_distanceFromStart.val = k_distanceFromEnd.val;
    k_distanceFromEnd.val = temp;

    return head;
};
