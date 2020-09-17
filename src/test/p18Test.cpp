#include "../../include/catch.hpp"
#include "../p18/DeleteNode.h"

TEST_CASE("p18") {

    SECTION("指向头节点的指针为NULL") {
        ListNode* node3 = new ListNode(3, NULL);
        ListNode* pToBeDeleted = node3;

        ListNode** pHead = NULL;
        deleteNode(pHead, pToBeDeleted);
    }
    SECTION("指向待删除节点的指针为NULL") {
        ListNode* node3 = new ListNode(3, NULL);
        ListNode* pToBeDeleted = NULL;

        ListNode** pHead = &node3;
        deleteNode(pHead, pToBeDeleted);
    }
    SECTION("只有一个节点，待删除节点就是这个节点") {
        ListNode* node3 = new ListNode(3, NULL);
        ListNode* pToBeDeleted = node3;

        ListNode** pHead = &node3;
        deleteNode(pHead, pToBeDeleted);
        REQUIRE((*pHead) == NULL);
    }
    SECTION("有多个节点") {
        ListNode* node3 = new ListNode(3, NULL);
        ListNode* node2 = new ListNode(2, node3);
        ListNode* node1 = new ListNode(1, node2);

        ListNode** pHead = &node1;

        SECTION("删除首节点") {
            ListNode* pToBeDeleted = node1;
            deleteNode(pHead, pToBeDeleted);
            ListNode* cur = *pHead;
            REQUIRE((cur->m_nValue) == 2);
            cur = cur->m_pNext;
            REQUIRE(cur->m_nValue == 3);
            cur = cur->m_pNext;
            REQUIRE(cur == NULL);
        }
        SECTION("删除节点是尾节点") {
            ListNode* pToBeDeleted = node3;
            deleteNode(pHead, pToBeDeleted);
            ListNode* cur = *pHead;
            REQUIRE(cur->m_nValue == 1);
            cur = cur->m_pNext;
            REQUIRE(cur->m_nValue == 2);
            cur = cur->m_pNext;
            REQUIRE(cur == NULL);
        }
        SECTION("删除节点是中间节点") {
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