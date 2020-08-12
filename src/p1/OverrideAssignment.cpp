#include "OverrideAssignment.h"
#include <string.h>

namespace code047 {
	CMyString::CMyString(char* pData) {
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}

	/// <summary>
	/// 拷贝构造函数，使用一个对象创建一个新对象，执行深拷贝
	/// </summary>
	/// <param name="str"></param>
	/// <returns></returns>
	CMyString::CMyString(const CMyString& str) {
		m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData, str.m_pData);
	}

	/// <summary>
	/// 版本一 : 基本版
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	CMyString& CMyString::operator=(const CMyString& other) {

		if (this != &other) {	// 防止自身赋值
			// 释放动态内存，指针置nullptr
			delete [] m_pData;
			m_pData == nullptr;

			// 开辟新内存，复制数据
			m_pData = new char[strlen(other.m_pData) + 1];	// 如何这里分配内存时内存不足，那么将导致m_pData已经释放，原数据破坏，又没拷贝成功
			strcpy(m_pData, other.m_pData);
		}
		return *this;
	}

	/// <summary>
	/// 版本2： 异常安全版
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	//CMyString& CMyString::operator=(const CMyString& other) {
	//	if (this != &other) {
	//		CMyString tmp(other);	// 创建临时局部对象，在拷贝构造函数中分配内存，即使失败，那么就不会继续执行，原有数据不会释放，异常安全
	//		char* tmp_ptr = tmp.m_pData;
	//		tmp.m_pData = m_pData;
	//		m_pData = tmp_ptr;

	//		// tmp作用域结束，自动调用析构函数释放原来this->m_pData
	//	}
	//	return *this;
	//}

	CMyString::~CMyString(void) {
		delete []m_pData;
	}
}