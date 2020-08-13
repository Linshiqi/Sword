#pragma once
#include <memory>
#include <thread>
#include <mutex>
#include <iostream>
namespace code047 {
	class Singleton {
	private:
		Singleton(int val) : _value(val) {}
		~Singleton() {
			std::cout << "析构调用" << std::endl;
		}
	private:
		// 为了析构静态指针使用
		class Foo {
		public:
			~Foo() {
				if (_instance_ptr != nullptr) {
					delete _instance_ptr;
					_instance_ptr = nullptr;
				}
			}
		};
	public:
		Singleton(const Singleton& other) = delete;
		Singleton& operator=(const Singleton& other) = delete;
	private:
		static Singleton* _instance_ptr;
		static std::mutex _mutex;
		// 静态变量在程序结束时调用自身析构
		static Foo foo;
		int _value;
	public:
		static Singleton* getInstance(int value);
		int getValue() const {
			return _value;
		}
	};
}