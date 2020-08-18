#include "../../include/catch.hpp"
#include "../p4/TwoDimSortedArraySearch.h"

using namespace code047;

TEST_CASE("P4 TEST") {
	SECTION("nomal data") {
		std::vector<std::vector<int>> a = {
			{1, 2, 8, 9},
			{2, 4, 9, 12},
			{4, 7, 10, 13},
			{6, 8, 11, 15}
		};


		TwoDimSortedArraySearchBase<int>* tb = new Solution1<int>();

		SECTION("keys in a") {
			for (auto items : a) {
				for (int e : items) {
					bool inArray = tb->exist(a, e);
					REQUIRE(inArray == true);
				}
			}
		}
		SECTION("key bigger than all elements in a") {
			const int key = 30;
			bool inArray = tb->exist(a, key);
			REQUIRE(inArray == false);
		}

		SECTION("key smaller than all elements in a") {
			const int key = 0;
			bool inArray = tb->exist(a, key);
			REQUIRE(inArray == false);
		}
		
	}
}
