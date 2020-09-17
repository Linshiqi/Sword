#pragma once
#include <iostream>

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
    ListNode(int v, ListNode* next) : m_nValue(v), m_pNext(next) {}
};

void deleteNode(ListNode** pListHead, ListNode* pToBeDeleted);

void printList(ListNode** pHead);