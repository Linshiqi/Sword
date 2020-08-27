#include "../../include/catch.hpp"

#include "../p6/PrintLinkReverse.h"

using namespace code047;

TEST_CASE("print Link list in reverse order") {
	LinkList<int> list;
	list.insert(1);
	list.insert(2);
	list.insert(3);

	std::shared_ptr<ListNode<int>> head_ptr = list.head();

	PrintLinkReverse pr;
	pr.printReverse(head_ptr);
}