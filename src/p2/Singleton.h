#pragma once
#include <memory>
#include <thread>
#include <mutex>
namespace code047 {
	class Singleton {
	private:
		Singleton(int val) : _value(val) {}
	public:
		Singleton(const Singleton& other) = delete;
		Singleton& operator=(const Singleton& other) = delete;
		~Singleton() {}
	private:
		static std::shared_ptr<Singleton> _instance_ptr;
		static std::mutex _mutex;
		int _value;
	public:
		static std::shared_ptr<Singleton> getInstance(int value);
		int getValue() const {
			return _value;
		}
	};
}