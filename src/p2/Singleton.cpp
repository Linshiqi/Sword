#include "Singleton.h"

namespace code047 {

	// static member must defined out of class
	std::shared_ptr<Singleton> Singleton::_instance_ptr;
	std::mutex Singleton::_mutex;

	std::shared_ptr<Singleton> Singleton::getInstance(int value) {
		if (_instance_ptr == nullptr) {
			std::lock_guard<std::mutex> lock(_mutex);
			if (_instance_ptr == nullptr) {
				_instance_ptr = std::make_shared<Singleton>(value);
			}
		}
		return _instance_ptr;
	}
}