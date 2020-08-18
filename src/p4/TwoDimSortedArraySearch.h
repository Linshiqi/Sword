/******************************************************
给定一个二维数组，从上到下，从左到右依次递增，给定一个数
判断这个数是否在数组中
*******************************************************/

#pragma once
#include <vector>

namespace code047 {
	template<typename T>
	class TwoDimSortedArraySearchBase {
	public:
		virtual ~TwoDimSortedArraySearchBase() {};
	public:
		virtual bool exist(std::vector<std::vector<T>>& a, T key) = 0;
	};

	template<typename T>
	class Solution1 : public TwoDimSortedArraySearchBase<T> {
	public:
		bool exist(std::vector<std::vector<T>>& a, T key) override {
			if (a.empty()) {
				return false;
			}
			return exist(a, key, a[0].size()-1, 0);
		}
	private:
		/// <summary>
		/// 从右上角元素开始比较，key比它小，则可以划去所在列，因为列下面元素都比它大 
		///	key比它大，则可以划去当前行，因为行左边都是比它小的元素
		/// </summary>
		/// <param name="a"></param>
		/// <param name="key"></param>
		/// <param name="columnMax">最大列索引</param>
		/// <param name="rowStart">最小行索引</param>
		/// <returns></returns>
		bool exist(std::vector<std::vector<T>>& a, const T& key, int columnMax, int rowStart) {
			if (a.empty()) {
				return false;
			}
			bool valid = columnMax >= 0 && columnMax < a[0].size() && rowStart >= 0 && rowStart < a.size();
			if (!valid) {
				return false;
			}

			T cmpKey = a[rowStart][columnMax];
			
			/*************只用<符号，对T类型重载要求最小化**************/
			if (cmpKey < key) {
				// key比它大，则可以划去当前行，因为行左边都是比它小的元素
				return exist(a, key, columnMax, rowStart+1);
			}
			else if (key < cmpKey) {
				// ，key比它小，则可以划去所在列，因为列下面元素都比它大
				return exist(a, key, columnMax - 1, rowStart);
			}
			else {
				return true;
			}
		}
	};


}
