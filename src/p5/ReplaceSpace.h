#pragma once

namespace code047 {
	class ReplaceSpaceBase {
	public:
		ReplaceSpaceBase() {}
		ReplaceSpaceBase(const ReplaceSpaceBase&) = delete;
		ReplaceSpaceBase& operator=(const ReplaceSpaceBase&) = delete;
		virtual ~ReplaceSpaceBase(){}
	public:
		/// <summary>
		/// �����ַ�str���䳤�ȣ���str�пո��滻Ϊ%20
		/// ע��strҪ��֤�������㹻�ڴ���Բ���
		/// </summary>
		virtual void replace(char* str, int length) = 0;
	};

	/// <summary>
	/// Time: O(N) N is 2*number of space + number of non space char
	/// Space : O(1) only two pointer p1, p2
	/// </summary>
	class ReplaceSpaceBaseFromBack : public ReplaceSpaceBase {
	public:
		ReplaceSpaceBaseFromBack() {}
		~ReplaceSpaceBaseFromBack() {}
		ReplaceSpaceBaseFromBack(const ReplaceSpaceBaseFromBack&) = delete;
		ReplaceSpaceBaseFromBack& operator=(const ReplaceSpaceBaseFromBack&) = delete;
	public:
		void replace(char* str, int length) override;
	};
}