#include "../../include/catch.hpp"
#include "../p1/OverrideAssignment.h"

using namespace code047;

TEST_CASE("p1") {
	SECTION("һ��CMyStringʵ����ֵ����һ��ʵ��") {
		CMyString cs2("world");
		{
			CMyString cs1("hello");
			cs2 = cs1;
			REQUIRE(strcmp(cs2.getData(), cs1.getData()) == 0);
		}
		SECTION("delete cs1, cs2����") {
			REQUIRE(strcmp(cs2.getData(),"hello") == 0);
		}
	}

	SECTION("����ֵ") {
		CMyString cs1("hello");
		cs1 = cs1;
		REQUIRE(strcmp(cs1.getData(), "hello") == 0);
	}

	SECTION("������ֵ") {
		CMyString cs1("hello");
		CMyString cs2("world");
		CMyString cs3("computer");
		cs1 = cs2 = cs3;
		REQUIRE(strcmp(cs1.getData(), cs3.getData()) == 0);
	}

}