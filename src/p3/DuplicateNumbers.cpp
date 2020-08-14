/*****************************************************************************
题目3：		找出数组中重复的元素

题目概要:	长度为n，范围在[0, n-1]的数组，有几个重复数字，不知道哪几个重复，随便找出一个

时间：		2020/08/14

作者：		code047
******************************************************************************/
#pragma once
#include <stdexcept>
#include "DuplicateNumbers.h" 
#include <iostream>

namespace code047 {

	/// <summary>
	/// 思想:
	///		针对输入特征n个[0,n-1]之间的数，可以将元素作为缩影设置位图相应位置为true
	///		位图所有位置初始为false，只要找到一个为true就说明之前已经有相等元素设置过了
	/// 复杂度：
	///		时间 O(N)->需要遍历数组 空间O(N)->注意是O(N)位，单位不是字节
	/// </summary>
	/// <param name="array">长度为N，元素大小都在[0, N-1]的数组</param>
	/// <returns></returns>
	int DuplicateNumBasic::findOneDuplicateNum(std::vector<int>& array) {
		int n = array.size();
		std::vector<bool> bitMap(n, false);
		
		// 填充位图
		for (int i = 0; i < n; i++) {
			if (array[i] >= n) {
				throw std::out_of_range("数组元素应该在[0, n-1]之间");
			}
			if (bitMap[array[i]] == false) {
				bitMap[array[i]] = true;
			}
			else {
				return array[i];	// 找到一个
			}
		}

		return -1;	// 没有找到
	}

	/// <summary>
	/// 思想： 
	///		针对输入特征n个[0,n-1]之间的数，如果没有重复元素，则排序后i位置元素应该为i，
	///		有重复元素就说明有些位置j元素不是j,那好，先把j位置的元素比如是e，与e应该在
	///		的位置索引e处比较，看是否一致，是说明找到重复元素，否则交换索引j和e处的元素，
	///		让e归位，然后继续判断当前j是不是j，不是继续交换...
	/// 复杂度:
	///		时间 O(N)-> 虽然有两个循环，但是while都走一次就保证一个元素就位,
	///				下次这个元素就需比较一次，而当前元素多比较一次，
	///				所以平均下来，每个元素在while循环里最多比较2次
	///		空间 O(1)-> 在原数组中操作
	/// </summary>
	/// <param name="array"></param>
	/// <returns></returns>
	int DuplicateNumInplace::findOneDuplicateNumInPlace(std::vector<int>& array) {
		int n = array.size();
		for (int i = 0; i < n; i++) {
			if (array[i] >= n) {
				throw std::out_of_range("数组元素应该在[0,n-1]之间");
			}
			while (i != array[i]) {	// array[i]元素没有在本来位置上
				if (array[i] == array[array[i]]) {	
					// 找到一个重复元素
					return array[i];
				}
				else {
					// 交换i与array[i]位置
					/*int tmp = array[array[i]];
					array[array[i]] = array[i];
					array[i] = tmp;*/

					std::swap(array.begin() + i, array.begin() + array[i]);
				}
			}
		}

		// 到这说明都已经各就各位，没有找到重复元素
		return -1;
	}
}