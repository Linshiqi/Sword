#include "p6/PrintLinkReverse.h"

using namespace code047;

void testP6() {
	LinkList<int> list;
	list.insert(1);
	list.insert(2);
	list.insert(3);

	std::shared_ptr<ListNode<int>> head_ptr = list.head();
	
	PrintLinkReverse pr;
	pr.printReverse(head_ptr);
}
int main() {
	testP6();
}
