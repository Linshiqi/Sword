/******************************************************
����һ����ά���飬���ϵ��£����������ε���������һ����
�ж�������Ƿ���������
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
		/// �����Ͻ�Ԫ�ؿ�ʼ�Ƚϣ�key����С������Ի�ȥ�����У���Ϊ������Ԫ�ض������� 
		///	key����������Ի�ȥ��ǰ�У���Ϊ����߶��Ǳ���С��Ԫ��
		/// </summary>
		/// <param name="a"></param>
		/// <param name="key"></param>
		/// <param name="columnMax">���������</param>
		/// <param name="rowStart">��С������</param>
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
			
			/*************ֻ��<���ţ���T��������Ҫ����С��**************/
			if (cmpKey < key) {
				// key����������Ի�ȥ��ǰ�У���Ϊ����߶��Ǳ���С��Ԫ��
				return exist(a, key, columnMax, rowStart+1);
			}
			else if (key < cmpKey) {
				// ��key����С������Ի�ȥ�����У���Ϊ������Ԫ�ض�������
				return exist(a, key, columnMax - 1, rowStart);
			}
			else {
				return true;
			}
		}
	};


}
