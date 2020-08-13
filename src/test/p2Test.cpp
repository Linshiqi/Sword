#include "../../include/catch.hpp"
#include "../p2/Singleton.h"
#include <iostream>

using namespace code047;

void threadFoo() {
	// Following code emulates slow initialization.
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	Singleton* foo_ptr = Singleton::getInstance(100);
	std::cout << "Foo: " << foo_ptr->getValue() << std::endl;
}

void threadBar() {
	// Following code emulates slow initialization.
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	Singleton* bar_ptr = Singleton::getInstance(99);
	std::cout << "Bar: " << bar_ptr->getValue() << std::endl;
}

TEST_CASE("p2 test") {
	std::cout << "If you see the same value, then singleton was reused (yay!\n" <<
		"If you see different values, then 2 singletons were created (booo!!)\n\n" <<
		"RESULT:\n";
	std::thread t1(threadFoo);
	std::thread t2(threadBar);

	t1.join();
	t2.join();
}
