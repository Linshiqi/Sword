#include "PrintLinkReverse.h"

namespace code047 {

	template<typename T>
	void PrintLinkReverse::printReverse(std::shared_ptr<ListNode<T>> head_ptr) {
		if (head_ptr == nullptr) {
			return;
		}
		if (head_ptr->next != nullptr) {
			this->printReverse(head_ptr->next);
		}
		std::cout << head_ptr->value << " ";
	}
}