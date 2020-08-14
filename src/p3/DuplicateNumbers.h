/*****************************************************************************
��Ŀ3��		�ҳ��������ظ���Ԫ��
 
��Ŀ��Ҫ:	����Ϊn����Χ��[0, n-1]�����飬�м����ظ����֣���֪���ļ����ظ�������ҳ�һ��

ʱ�䣺		2020/08/14

���ߣ�		code047
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