
#include <vector>
using namespace std;

// Struct ListNode is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this struct.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
    
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* current = head;
        ListNode* k_distanceFromStart = head;
        ListNode* k_distanceFromEnd = nullptr;

        int countNodes = 0;
        while (current != nullptr) {
            if (k_distanceFromEnd != nullptr) {
                k_distanceFromEnd = k_distanceFromEnd->next;
            }
            if (++countNodes == k) {
                k_distanceFromStart = current;
                k_distanceFromEnd = head;
            }
            current = current->next;
        }

        //the requirement is to swap only values
        int temp = k_distanceFromStart->val;
        k_distanceFromStart->val = k_distanceFromEnd->val;
        k_distanceFromEnd->val = temp;

        return head;
    }
};
