/*****************************************************************************
题目3：		找出数组中重复的元素
 
题目概要:	长度为n，范围在[0, n-1]的数组，有几个重复数字，不知道哪几个重复，随便找出一个

时间：		2020/08/14

作者：		code047
******************************************************************************/

#pragma once
#include <vector>
namespace code047 {
	class DuplicateNum {
	public:
		DuplicateNum() {}
		DuplicateNum(const DuplicateNum&) = delete;
		DuplicateNum& operator=(const DuplicateNum&) = delete;
		virtual ~DuplicateNum() {}
	public:
		virtual int findDuplicate(std::vector<int>& array) = 0;
	};

	class DuplicateNumBasic : public DuplicateNum {
	public:
		DuplicateNumBasic() {}
		DuplicateNumBasic(const DuplicateNumBasic*) = delete;
		DuplicateNumBasic& operator=(const DuplicateNumBasic*) = delete;
		~DuplicateNumBasic() {}
	public:
		int findDuplicate(std::vector<int>& array) override {
			return findOneDuplicateNum(array);
		}
	private:
		int findOneDuplicateNum(std::vector<int>& array);
	};

	class DuplicateNumInplace : public DuplicateNum {
	public:
		DuplicateNumInplace() {}
		DuplicateNumInplace(const DuplicateNumInplace*) = delete;
		DuplicateNumInplace& operator=(const DuplicateNumInplace*) = delete;
		~DuplicateNumInplace() {}
	public:
		int findDuplicate(std::vector<int>& array) override {
			return findOneDuplicateNumInPlace(array);
		}
	private:
		int findOneDuplicateNumInPlace(std::vector<int>& array);
	};

}