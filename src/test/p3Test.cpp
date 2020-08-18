#include "../../include/catch.hpp"
#include "../p3/DuplicateNumbers.h"
#include "../p3/D2.h"
#include <iostream>

using namespace code047;

void test(std::shared_ptr<DuplicateNum> dpt_ptr) {
	SECTION("������") {
		std::vector<int> array = { };
		int res = dpt_ptr->findDuplicate(array);
		REQUIRE(res == -1);
	}
	SECTION("��ȫ�ظ�") {
		std::vector<int> array = { 0,1,2,3,4 };
		int res = dpt_ptr->findDuplicate(array);
		REQUIRE(res == -1);
	}
	SECTION("�����а���һ�������ظ���Ԫ��") {
		SECTION("һ���ظ�Ԫ��") {
			std::vector<int> array = { 0,1,2,3,2 };
			int res = dpt_ptr->findDuplicate(array);
			REQUIRE(res == 2);
		}

		SECTION("����ظ���Ԫ��") {
			std::vector<int> array = { 0,1,2,3,2,3 };
			int res = dpt_ptr->findDuplicate(array);
			REQUIRE((res == 2 || res == 3));
		}

	}
	SECTION("��Ч���룬����Ԫ����Ԫ�ش��ڵ���n") {
		std::vector<int> array = { 0,1,2,3,10 };
		try {
			int res = dpt_ptr->findDuplicate(array);
		}
		catch (std::exception e) {
			std::cout << "�����쳣:" << e.what() << std::endl;
		}
		// ����֮ǰӦ���Ѿ��׳�Խ���쳣
	}
}

TEST_CASE("p3") {

	std::shared_ptr<DuplicateNum> dpt_ptr;
	SECTION("λͼ��") {
		dpt_ptr = std::make_shared<DuplicateNumBasic>();
		test(dpt_ptr);
	}

	SECTION("�͵ذ�") {
		dpt_ptr = std::make_shared<DuplicateNumInplace>();
		test(dpt_ptr);
	}

	//SECTION("����std::vector<bool>�ռ�ռ�����") {
	//	std::vector<bool> bitmap(10, false);
	//	bool ba[10];
	//	std::vector<int> bi(10, 0);
	//	std::cout << sizeof(bitmap) << std::endl;
	//	std::cout << sizeof(ba) << std::endl;
	//	std::cout << sizeof(bi) << std::endl;
	//}
}

TEST_CASE("�ظ�����2") {
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
