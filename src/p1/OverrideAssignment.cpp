#include "OverrideAssignment.h"
#include <string.h>

namespace code047 {
	CMyString::CMyString(char* pData) {
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}

	/// <summary>
	/// �������캯����ʹ��һ�����󴴽�һ���¶���ִ�����
	/// </summary>
	/// <param name="str"></param>
	/// <returns></returns>
	CMyString::CMyString(const CMyString& str) {
		m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData, str.m_pData);
	}

	/// <summary>
	/// �汾һ : ������
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	CMyString& CMyString::operator=(const CMyString& other) {

		if (this != &other) {	// ��ֹ����ֵ
			// �ͷŶ�̬�ڴ棬ָ����nullptr
			delete [] m_pData;
			m_pData == nullptr;

			// �������ڴ棬��������
			m_pData = new char[strlen(other.m_pData) + 1];	// �����������ڴ�ʱ�ڴ治�㣬��ô������m_pData�Ѿ��ͷţ�ԭ�����ƻ�����û�����ɹ�
			strcpy(m_pData, other.m_pData);
		}
		return *this;
	}

	/// <summary>
	/// �汾2�� �쳣��ȫ��
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	//CMyString& CMyString::operator=(const CMyString& other) {
	//	if (this != &other) {
	//		CMyString tmp(other);	// ������ʱ�ֲ������ڿ������캯���з����ڴ棬��ʹʧ�ܣ���ô�Ͳ������ִ�У�ԭ�����ݲ����ͷţ��쳣��ȫ
	//		char* tmp_ptr = tmp.m_pData;
	//		tmp.m_pData = m_pData;
	//		m_pData = tmp_ptr;

	//		// tmp������������Զ��������������ͷ�ԭ��this->m_pData
	//	}
	//	return *this;
	//}

	CMyString::~CMyString(void) {
		delete []m_pData;
	}
}