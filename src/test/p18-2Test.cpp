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

TEST_CASE("ɾ�������е��ظ�Ԫ��") {
	// ��������
	ListNode* pHead;
	pHead = nullptr;
	SECTION("�ձ�") {
		ListNode** ppHead;
		ppHead = nullptr;
		deDuplicateList(ppHead);
		REQUIRE(ppHead == nullptr);
	}
	SECTION("û���ظ�Ԫ�أ���ɾ������ڵ㣬ԭ������") {
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
	SECTION("ȫ�ظ�, ȫɾ����*ppheadӦ�õ���nullptr") {
		int a[] = { 1, 1, 1, 1 };
		initList(&pHead, a, len(a));
		ListNode** ppHead = &pHead;
		deDuplicateList(ppHead);
		bool res = (*ppHead == nullptr);
		REQUIRE(res == true);
		printList(ppHead);

	}
	SECTION("��ͷԪ�ؾ��ظ��� [1,1,2,3,4] -> [2,3,4]") {
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
	SECTION("�ظ�Ԫ�����м�: [1, 2, 3, 3, 4] -> [1, 2, 4]") {
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
	SECTION("�����ͬ�ظ���Ԫ��: [1,2,3,4,4,5]->[1,2,5]") {
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
	SECTION("�ظ�Ԫ����β��: [1, 2, 3, 4, 4] -> [1, 2, 3]") {
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