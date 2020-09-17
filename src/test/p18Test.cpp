#include "../../include/catch.hpp"
#include "../p18/DeleteNode.h"

TEST_CASE("p18") {

    SECTION("ָ��ͷ�ڵ��ָ��ΪNULL") {
        ListNode* node3 = new ListNode(3, NULL);
        ListNode* pToBeDeleted = node3;

        ListNode** pHead = NULL;
        deleteNode(pHead, pToBeDeleted);
    }
    SECTION("ָ���ɾ���ڵ��ָ��ΪNULL") {
        ListNode* node3 = new ListNode(3, NULL);
        ListNode* pToBeDeleted = NULL;

        ListNode** pHead = &node3;
        deleteNode(pHead, pToBeDeleted);
    }
    SECTION("ֻ��һ���ڵ㣬��ɾ���ڵ��������ڵ�") {
        ListNode* node3 = new ListNode(3, NULL);
        ListNode* pToBeDeleted = node3;

        ListNode** pHead = &node3;
        deleteNode(pHead, pToBeDeleted);
        REQUIRE((*pHead) == NULL);
    }
    SECTION("�ж���ڵ�") {
        ListNode* node3 = new ListNode(3, NULL);
        ListNode* node2 = new ListNode(2, node3);
        ListNode* node1 = new ListNode(1, node2);

        ListNode** pHead = &node1;

        SECTION("ɾ���׽ڵ�") {
            ListNode* pToBeDeleted = node1;
            deleteNode(pHead, pToBeDeleted);
            ListNode* cur = *pHead;
            REQUIRE((cur->m_nValue) == 2);
            cur = cur->m_pNext;
            REQUIRE(cur->m_nValue == 3);
            cur = cur->m_pNext;
            REQUIRE(cur == NULL);
        }
        SECTION("ɾ���ڵ���β�ڵ�") {
            ListNode* pToBeDeleted = node3;
            deleteNode(pHead, pToBeDeleted);
            ListNode* cur = *pHead;
            REQUIRE(cur->m_nValue == 1);
            cur = cur->m_pNext;
            REQUIRE(cur->m_nValue == 2);
            cur = cur->m_pNext;
            REQUIRE(cur == NULL);
        }
        SECTION("ɾ���ڵ����м�ڵ�") {
            ListNode* pToBeDeleted = node2;
            deleteNode(pHead, pToBeDeleted);
            ListNode* cur = *pHead;
            REQUIRE(cur->m_nValue == 1);
            cur = cur->m_pNext;
            REQUIRE(cur->m_nValue == 3);
            cur = cur->m_pNext;
            REQUIRE(cur == NULL);
        }
    }
}