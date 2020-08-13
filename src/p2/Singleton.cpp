#include "Singleton.h"

namespace code047 {

	// static member must defined out of class
	Singleton* Singleton::_instance_ptr;
	std::mutex Singleton::_mutex;
	Singleton::Foo Singleton::foo;

	Singleton* Singleton::getInstance(int value) {
		if (_instance_ptr == nullptr) {
			std::lock_guard<std::mutex> lock(_mutex);
			if (_instance_ptr == nullptr) {
				_instance_ptr = new Singleton(value);
			}
		}
		return _instance_ptr;
	}
}