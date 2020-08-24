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
		/// 给定字符str及其长度，将str中空格替换为%20
		/// 注意str要求保证后面有足够内存可以操作
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