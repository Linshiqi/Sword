#include "../../include/catch.hpp"
#include "../p18-2/DeDuplicateList.h"
#include "../utils/utils.h"


void initList(ListNode** ppHead, int a[], int N) {
	
	ListNode** cur = ppHead;

	for (int i = 0; i < N; i++) {
		if (*cur == nullptr) {
			*cur = new ListNode(a[i], nullptr);
		}
		else {
			(*cur)->m_pNext = new ListNode(a[i], nullptr);
			cur = &((*cur)->m_pNext);
		}
	}
}

TEST_CASE("删除链表中的重复元素") {
	// 构建链表
	ListNode* pHead;
	pHead = nullptr;
	SECTION("空表") {
		ListNode** ppHead;
		ppHead = nullptr;
		deDuplicateList(ppHead);
		REQUIRE(ppHead == nullptr);
	}
	SECTION("没有重复元素，不删除任务节点，原链表不变") {
		// [1->2->3->4]
		int a[] = { 1, 2, 3, 4 };

		initList(&pHead, a, len(a));
		ListNode** ppHead = &pHead;
		deDuplicateList(ppHead);

		int* res = a;
		ListNode* cur = *ppHead;
		for (int i = 0; i < len(a); i++) {
			if (cur != nullptr) {
				REQUIRE(cur->m_nValue == res[i]);
				cur = cur->m_pNext;
			}
		}
		printList(ppHead);
	}
	SECTION("全重复, 全删除，*pphead应该等于nullptr") {
		int a[] = { 1, 1, 1, 1 };
		initList(&pHead, a, len(a));
		ListNode** ppHead = &pHead;
		deDuplicateList(ppHead);
		bool res = (*ppHead == nullptr);
		REQUIRE(res == true);
		printList(ppHead);

	}
	SECTION("开头元素就重复： [1,1,2,3,4] -> [2,3,4]") {
		int a[] = { 1, 1, 2, 3, 4 };
		initList(&pHead, a, len(a));
		ListNode** ppHead = &pHead;
		deDuplicateList(ppHead);
		int res[] = { 2, 3, 4 };
		ListNode* cur = *ppHead;
		for (int i = 0; i < len(res); i++) {
			if (cur != nullptr) {
				REQUIRE(cur->m_nValue == res[i]);
				cur = cur->m_pNext;
			}
		}
		printList(ppHead);

	}
	SECTION("重复元素在中间: [1, 2, 3, 3, 4] -> [1, 2, 4]") {
		int a[] = { 1, 2, 3, 3, 4 };
		initList(&pHead, a, len(a));
		ListNode** ppHead = &pHead;
		deDuplicateList(ppHead);
		int res[] = { 1, 2, 4 };
		ListNode* cur = *ppHead;
		for (int i = 0; i < len(res); i++) {
			if (cur != nullptr) {
				REQUIRE(cur->m_nValue == res[i]);
				cur = cur->m_pNext;
			}
		}
		printList(ppHead);

	}
	SECTION("多个不同重复的元素: [1,2,3,4,4,5]->[1,2,5]") {
		int a[] = { 1,2,3,3,4,4,5 };

		initList(&pHead, a, len(a));
		ListNode** ppHead = &pHead;

		deDuplicateList(ppHead);

		int res[] = { 1, 2, 5 };

		ListNode* cur = *ppHead;

		for (int i = 0; i < len(res); i++) {
			if (cur != nullptr) {
				REQUIRE(cur->m_nValue == res[i]);
				cur = cur->m_pNext;
			}
		}
		printList(ppHead);

	}
	SECTION("重复元素在尾部: [1, 2, 3, 4, 4] -> [1, 2, 3]") {
		int a[] = { 1, 2, 3, 4, 4 };
		initList(&pHead, a, len(a));
		ListNode** ppHead = &pHead;
		deDuplicateList(ppHead);
		int res[] = { 1, 2, 3 };
		ListNode* cur = *ppHead;
		for (int i = 0; i < len(res); i++) {
			if (cur != nullptr) {
				REQUIRE(cur->m_nValue == res[i]);
				cur = cur->m_pNext;
			}
		}
		printList(ppHead);

	}

}