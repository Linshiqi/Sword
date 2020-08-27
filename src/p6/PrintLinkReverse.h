/**********************************************************************************
Function:	逆序打印链表

Date:		2020/08/25

Author:		code047
**********************************************************************************/
#pragma once
#include <memory>
#include <iostream>
namespace code047 {

	template<typename T>
	struct ListNode {
		T value;
		std::shared_ptr<ListNode> next;
		ListNode(T value, std::shared_ptr<ListNode> next = nullptr) : value(value), next(next){}
	};


	template<typename T>
	class LinkList {
	public:
		LinkList() : head_ptr(nullptr) {}
		void insert(T value) {
			std::shared_ptr<ListNode<T>> tmp_ptr = std::make_shared<ListNode<int>>(value);
			if (head_ptr == nullptr) {
				head_ptr = tmp_ptr;
			}
			else {
				tmp_ptr->next = head_ptr;
				head_ptr = tmp_ptr;
			}
		}
	public:
		std::shared_ptr<ListNode<T>> head() {
			return head_ptr;
		}
	private:
		std::shared_ptr<ListNode<T>> head_ptr;	// 头节点， 包含数据
	};



	class PrintLinkReverse {
	public:
		template<typename T>
		void printReverse(std::shared_ptr<ListNode<T>> head_ptr);
	};
}
