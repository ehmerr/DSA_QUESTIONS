/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Step 1: Store all nums in an unordered_set for O(1) lookup
        unordered_set<int> st(nums.begin(), nums.end());
        
        // Step 2: Use a dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        // Step 3: Traverse the linked list
        while (curr) {
            if (st.count(curr->val)) {
                // Node value present in nums → delete it
                prev->next = curr->next;
            } else {
                // Keep node
                prev = curr;
            }
            curr = curr->next;
        }
        
        // Step 4: Return updated head
        return dummy->next;
    }
};
