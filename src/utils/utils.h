#pragma once
#include <iostream>
#define len(x) (sizeof(x) / sizeof(*x))
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
    ListNode(int v, ListNode* next) : m_nValue(v), m_pNext(next) {}
};

void printList(ListNode** pHead);