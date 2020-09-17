#include "DeDuplicateList.h"

/// <summary>
/// 三指针法，pre是虚指针，初始化指向头节点前面nullptr, cur指向头节点,next指向cur下一个。
/// </summary>
/// <param name="ppHead"></param>
void deDuplicateList(ListNode** ppHead) {
	// 特判
	if (ppHead == nullptr || *ppHead == nullptr) {
		return;
	}
	ListNode* preNode = nullptr;
	ListNode* curNode = *ppHead;
	while (curNode != nullptr) {
		ListNode* nextNode = curNode->m_pNext;
		if (nextNode != nullptr && curNode->m_nValue != nextNode->m_nValue) {
			// 不重复，cur继续走
			preNode = curNode;
			curNode = nextNode;
			nextNode = nextNode->m_pNext;
		}
		else if (nextNode == nullptr) {
			//前面一直不重复，到头了
			return;
		}
		else {
			// cur与next重复，需要删除，直到next指向不重复的节点
			int value = curNode->m_nValue;
			while (nextNode != nullptr && nextNode->m_nValue == value) {
				ListNode* nodeToDeleted = curNode;
				curNode = nextNode;
				nextNode = nextNode->m_pNext;
				delete nodeToDeleted;
				nodeToDeleted = nullptr;
			}
			
			if (preNode == nullptr) { // 如果是开头几个节点重复，那么preNode还是指向原来的nullptr
				*ppHead = nextNode;		// nextNode现在指向不重复的第一个节点
			}
			else {
				// 到这里说明是中间或尾部节点重复，只要pre->next = nextNode即可
				preNode->m_pNext = nextNode;
			}
			curNode = nextNode;	// 不要忘记这里继续往后走，看看后面还有没有重复的元素
		}
	}
}
