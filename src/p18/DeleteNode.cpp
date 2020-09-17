#pragma once
#include "DeleteNode.h"

void deleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
    if (pListHead == NULL || *pListHead == NULL || pToBeDeleted == NULL) {
        return;
    }

    // 删除节点不是尾节点
    if (pToBeDeleted->m_pNext != NULL) {
        // 待删除节点是首节点或中间节点, 直接复制待删除节点后面节点内容(包括数据和next指针内容)到待删除节点，然后删除后节点
        ListNode* tmp = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = tmp->m_nValue;
        pToBeDeleted->m_pNext = tmp->m_pNext;

        delete tmp;
        tmp = NULL;
    }
    else if (*pListHead == pToBeDeleted) {// 只有一个节点，待删除节点是首节点
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL;
    }
    else {
        ListNode* cur = *pListHead;
        // 尾节点只能从头节点开始找到它的前一个节点，然后修改前一个节点的next，使之指向NULL，同时delete尾节点
        while (cur->m_pNext != pToBeDeleted) {
            cur = cur->m_pNext;
        }
        // 到这里cur就是待删除节点的前一节点了
        cur->m_pNext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}
