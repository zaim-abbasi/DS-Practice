struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *temp = new ListNode(0);
        ListNode *temp1 = l1;
        ListNode *temp2 = l1;
        int length1 = 0, length2 = 0;
        while (temp1 != nullptr)
        {
            temp = temp->next;
            length1++;
        }
        while (temp2 != nullptr)
        {
            temp2 = temp2->next;
            length2++;
        }
        if (length1 == length2)
        {
            int counter = 1;
            while (counter < length1)
            {
                temp->val = l1->val + l2->val;
                temp = temp->next;
                l1 = l1->next;
                l2 = l2->next;
                counter++;
            }
        }
    }
};