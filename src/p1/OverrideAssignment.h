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