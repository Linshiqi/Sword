/*
n+1��[1, n]֮���Ԫ�����飬�ҳ�һ���ظ�Ԫ��
*/

#include <iostream>
namespace {
	/// <summary>
	/// ͳ��[lo, hi]֮��Ԫ����a�г��ֵĴ���
	/// </summary>
	/// <param name="a"></param>
	/// <param name="length"></param>
	/// <param name="lo"></param>
	/// <param name="hi"></param>
	/// <returns></returns>
	int count(const int* a, int length, int lo, int hi) {
		bool valid = (lo >= 0 && hi < length);
		if (!valid) {
			std::cerr << "count() : arguments out of range" << std::endl;
			return -1;
		}
		int cnt = 0;
		for (int i = 0; i < length; i++) {
			if (a[i] >= lo && a[i] <= hi) {
				cnt++;
			}
		}

		return cnt;
	}
	int recursiveVersion(const int* a, int length, int lo, int hi) {
		if (lo >= hi) {
			int cnt = count(a, length, lo, lo);
			if (cnt > 1) {
				return lo;
			}
			else {
				return -1;
			}
		}
		int mid = ((hi - lo) >> 1) + lo;
		int leftRes = recursiveVersion(a, length, lo, mid);
		if (leftRes != -1) {
			return leftRes;
		}
		int rightRes = recursiveVersion(a, length, mid + 1, hi);
		if (rightRes != -1) {
			return rightRes;
		}
		return -1;
		
	}
	int getDuplicate(const int* a, int length) {
		if (a == nullptr || length == 0) {
			return -1;
		}
		return recursiveVersion(a, length, 1, length - 1);
	}
}

