#include "DeDuplicateList.h"

/// <summary>
/// ��ָ�뷨��pre����ָ�룬��ʼ��ָ��ͷ�ڵ�ǰ��nullptr, curָ��ͷ�ڵ�,nextָ��cur��һ����
/// </summary>
/// <param name="ppHead"></param>
void deDuplicateList(ListNode** ppHead) {
	// ����
	if (ppHead == nullptr || *ppHead == nullptr) {
		return;
	}
	ListNode* preNode = nullptr;
	ListNode* curNode = *ppHead;
	while (curNode != nullptr) {
		ListNode* nextNode = curNode->m_pNext;
		if (nextNode != nullptr && curNode->m_nValue != nextNode->m_nValue) {
			// ���ظ���cur������
			preNode = curNode;
			curNode = nextNode;
			nextNode = nextNode->m_pNext;
		}
		else if (nextNode == nullptr) {
			//ǰ��һֱ���ظ�����ͷ��
			return;
		}
		else {
			// cur��next�ظ�����Ҫɾ����ֱ��nextָ���ظ��Ľڵ�
			int value = curNode->m_nValue;
			while (nextNode != nullptr && nextNode->m_nValue == value) {
				ListNode* nodeToDeleted = curNode;
				curNode = nextNode;
				nextNode = nextNode->m_pNext;
				delete nodeToDeleted;
				nodeToDeleted = nullptr;
			}
			
			if (preNode == nullptr) { // ����ǿ�ͷ�����ڵ��ظ�����ôpreNode����ָ��ԭ����nullptr
				*ppHead = nextNode;		// nextNode����ָ���ظ��ĵ�һ���ڵ�
			}
			else {
				// ������˵�����м��β���ڵ��ظ���ֻҪpre->next = nextNode����
				preNode->m_pNext = nextNode;
			}
			curNode = nextNode;	// ��Ҫ����������������ߣ��������滹��û���ظ���Ԫ��
		}
	}
}
