#include <LC_E_0019.hpp>

namespace lc
{
    ListNode *deleteDuplicates(ListNode *head)
    {
        for(ListNode *c = head; c && c->next;  )
            if( c->val == c->next->val )
                c->next = c->next->next;
            else
                c = c->next;
        return head;
    }
}

