/*****************************************************************************
��Ŀ3��		�ҳ��������ظ���Ԫ��

��Ŀ��Ҫ:	����Ϊn����Χ��[0, n-1]�����飬�м����ظ����֣���֪���ļ����ظ�������ҳ�һ��

ʱ�䣺		2020/08/14

���ߣ�		code047
******************************************************************************/
#pragma once
#include <stdexcept>
#include "DuplicateNumbers.h" 
#include <iostream>

namespace code047 {

	/// <summary>
	/// ˼��:
	///		�����������n��[0,n-1]֮����������Խ�Ԫ����Ϊ��Ӱ����λͼ��Ӧλ��Ϊtrue
	///		λͼ����λ�ó�ʼΪfalse��ֻҪ�ҵ�һ��Ϊtrue��˵��֮ǰ�Ѿ������Ԫ�����ù���
	/// ���Ӷȣ�
	///		ʱ�� O(N)->��Ҫ�������� �ռ�O(N)->ע����O(N)λ����λ�����ֽ�
	/// </summary>
	/// <param name="array">����ΪN��Ԫ�ش�С����[0, N-1]������</param>
	/// <returns></returns>
	int DuplicateNumBasic::findOneDuplicateNum(std::vector<int>& array) {
		int n = array.size();
		std::vector<bool> bitMap(n, false);
		
		// ���λͼ
		for (int i = 0; i < n; i++) {
			if (array[i] >= n) {
				throw std::out_of_range("����Ԫ��Ӧ����[0, n-1]֮��");
			}
			if (bitMap[array[i]] == false) {
				bitMap[array[i]] = true;
			}
			else {
				return array[i];	// �ҵ�һ��
			}
		}

		return -1;	// û���ҵ�
	}

	/// <summary>
	/// ˼�룺 
	///		�����������n��[0,n-1]֮����������û���ظ�Ԫ�أ��������iλ��Ԫ��Ӧ��Ϊi��
	///		���ظ�Ԫ�ؾ�˵����Щλ��jԪ�ز���j,�Ǻã��Ȱ�jλ�õ�Ԫ�ر�����e����eӦ����
	///		��λ������e���Ƚϣ����Ƿ�һ�£���˵���ҵ��ظ�Ԫ�أ����򽻻�����j��e����Ԫ�أ�
	///		��e��λ��Ȼ������жϵ�ǰj�ǲ���j�����Ǽ�������...
	/// ���Ӷ�:
	///		ʱ�� O(N)-> ��Ȼ������ѭ��������while����һ�ξͱ�֤һ��Ԫ�ؾ�λ,
	///				�´����Ԫ�ؾ���Ƚ�һ�Σ�����ǰԪ�ض�Ƚ�һ�Σ�
	///				����ƽ��������ÿ��Ԫ����whileѭ�������Ƚ�2��
	///		�ռ� O(1)-> ��ԭ�����в���
	/// </summary>
	/// <param name="array"></param>
	/// <returns></returns>
	int DuplicateNumInplace::findOneDuplicateNumInPlace(std::vector<int>& array) {
		int n = array.size();
		for (int i = 0; i < n; i++) {
			if (array[i] >= n) {
				throw std::out_of_range("����Ԫ��Ӧ����[0,n-1]֮��");
			}
			while (i != array[i]) {	// array[i]Ԫ��û���ڱ���λ����
				if (array[i] == array[array[i]]) {	
					// �ҵ�һ���ظ�Ԫ��
					return array[i];
				}
				else {
					// ����i��array[i]λ��
					/*int tmp = array[array[i]];
					array[array[i]] = array[i];
					array[i] = tmp;*/

					std::swap(array.begin() + i, array.begin() + array[i]);
				}
			}
		}

		// ����˵�����Ѿ����͸�λ��û���ҵ��ظ�Ԫ��
		return -1;
	}
}