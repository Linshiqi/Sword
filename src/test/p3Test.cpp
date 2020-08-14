#include "../../include/catch.hpp"
#include "../p3/DuplicateNumbers.h"
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