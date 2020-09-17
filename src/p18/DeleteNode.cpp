#pragma once
#include "DeleteNode.h"

void deleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
    if (pListHead == NULL || *pListHead == NULL || pToBeDeleted == NULL) {
        return;
    }

    // ɾ���ڵ㲻��β�ڵ�
    if (pToBeDeleted->m_pNext != NULL) {
        // ��ɾ���ڵ����׽ڵ���м�ڵ�, ֱ�Ӹ��ƴ�ɾ���ڵ����ڵ�����(�������ݺ�nextָ������)����ɾ���ڵ㣬Ȼ��ɾ����ڵ�
        ListNode* tmp = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = tmp->m_nValue;
        pToBeDeleted->m_pNext = tmp->m_pNext;

        delete tmp;
        tmp = NULL;
    }
    else if (*pListHead == pToBeDeleted) {// ֻ��һ���ڵ㣬��ɾ���ڵ����׽ڵ�
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL;
    }
    else {
        ListNode* cur = *pListHead;
        // β�ڵ�ֻ�ܴ�ͷ�ڵ㿪ʼ�ҵ�����ǰһ���ڵ㣬Ȼ���޸�ǰһ���ڵ��next��ʹָ֮��NULL��ͬʱdeleteβ�ڵ�
        while (cur->m_pNext != pToBeDeleted) {
            cur = cur->m_pNext;
        }
        // ������cur���Ǵ�ɾ���ڵ��ǰһ�ڵ���
        cur->m_pNext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}
