#include "../../include/catch.hpp"
#include "../p5/ReplaceSpace.h"
#include <memory>
#include <iostream>
using namespace code047;

TEST_CASE("P5") {
	char* str = new char[10];
	str[0] = 'A';
	str[1] = ' ';
	str[2] = 'B';
	str[3] = 'C';
	str[4] = '\0';

	// str = "A BC"

	SECTION("Replace from back") {
		std::shared_ptr<ReplaceSpaceBase> p_r = std::make_shared<ReplaceSpaceBaseFromBack>();
		p_r->replace(str, 4);
		std::string expectedStr = "A%20BC";
		for (int i = 0; i < 6; i++) {
			REQUIRE(str[i] == expectedStr[i]);
		}
		std::cout << str << std::endl;
	}

	delete[] str;
}