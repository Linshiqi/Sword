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
			std::cout << "��������" << std::endl;
		}
	private:
		// Ϊ��������ָ̬��ʹ��
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
		// ��̬�����ڳ������ʱ������������
		static Foo foo;
		int _value;
	public:
		static Singleton* getInstance(int value);
		int getValue() const {
			return _value;
		}
	};
}