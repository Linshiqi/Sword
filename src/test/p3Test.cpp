#include "../../include/catch.hpp"
#include "../p3/DuplicateNumbers.h"
#include "../p3/D2.h"
#include <iostream>

using namespace code047;

void test(std::shared_ptr<DuplicateNum> dpt_ptr) {
	SECTION("空数组") {
		std::vector<int> array = { };
		int res = dpt_ptr->findDuplicate(array);
		REQUIRE(res == -1);
	}
	SECTION("无全重复") {
		std::vector<int> array = { 0,1,2,3,4 };
		int res = dpt_ptr->findDuplicate(array);
		REQUIRE(res == -1);
	}
	SECTION("数组中包含一个或多个重复的元素") {
		SECTION("一个重复元素") {
			std::vector<int> array = { 0,1,2,3,2 };
			int res = dpt_ptr->findDuplicate(array);
			REQUIRE(res == 2);
		}

		SECTION("多个重复的元素") {
			std::vector<int> array = { 0,1,2,3,2,3 };
			int res = dpt_ptr->findDuplicate(array);
			REQUIRE((res == 2 || res == 3));
		}

	}
	SECTION("无效输入，数组元素中元素大于等于n") {
		std::vector<int> array = { 0,1,2,3,10 };
		try {
			int res = dpt_ptr->findDuplicate(array);
		}
		catch (std::exception e) {
			std::cout << "断言异常:" << e.what() << std::endl;
		}
		// 在这之前应该已经抛出越界异常
	}
}

TEST_CASE("p3") {

	std::shared_ptr<DuplicateNum> dpt_ptr;
	SECTION("位图版") {
		dpt_ptr = std::make_shared<DuplicateNumBasic>();
		test(dpt_ptr);
	}

	SECTION("就地版") {
		dpt_ptr = std::make_shared<DuplicateNumInplace>();
		test(dpt_ptr);
	}

	//SECTION("测试std::vector<bool>空间占用情况") {
	//	std::vector<bool> bitmap(10, false);
	//	bool ba[10];
	//	std::vector<int> bi(10, 0);
	//	std::cout << sizeof(bitmap) << std::endl;
	//	std::cout << sizeof(ba) << std::endl;
	//	std::cout << sizeof(bi) << std::endl;
	//}
}

TEST_CASE("重复数组2") {
	SECTION("two duplicate") {
		int a[8] = {2, 3, 5, 4, 3, 2, 6, 7 };
		int res = getDuplicate(a, 8);
		bool pass = (res == 2 || res == 3);
		REQUIRE(pass == true);
	}
	SECTION("one duplicate") {
		int a[7] = { 3, 5, 4, 3, 2, 6, 7 };
		int res = getDuplicate(a, 7);
		REQUIRE(res == 3);
	}
	SECTION("no duplicate") {
		int a[6] = { 5, 4, 3, 2, 6, 7 };
		int res = getDuplicate(a, 6);
		REQUIRE(res == -1);
	}
	SECTION("nullptr") {
		int* a = nullptr;
		int res = getDuplicate(a, 6);
		REQUIRE(res == -1);
	}
	SECTION("length 0") {
		int a[3] = {1, 2, 3};
		int res = getDuplicate(a, 0);
		REQUIRE(res == -1);
	}
}
