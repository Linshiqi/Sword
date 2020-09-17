#include "utils.h"
void printList(ListNode** pHead) {
    ListNode* cur = *pHead;
    while (cur != nullptr) {
        std::cout << cur->m_nValue << "->";
        cur = cur->m_pNext;
    }
    std::cout << std::endl;
}