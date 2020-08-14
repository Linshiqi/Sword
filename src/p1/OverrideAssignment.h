/***********************************************************************
 重载赋值运算符

 注意要点：
	本身赋值
	连续赋值
	内存管理
	异常安全
************************************************************************/
#pragma once
namespace code047 {
	class CMyString {
	public:
		CMyString(char* pData = nullptr);
		CMyString(const CMyString& str);
		CMyString& operator=(const CMyString& other);
		~CMyString(void);
	public:
		char* getData() {
			return m_pData;
		}

	private:
		char* m_pData;
	};
}