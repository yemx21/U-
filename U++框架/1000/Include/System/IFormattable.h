#pragma once
#include "CultureInfo.h"

namespace System
{
	
	/// <summary>
	/// ��ʽ���ӿ���
	/// </summary>
	class RUNTIME_API IFormattable
	{
	protected:
		/// <summary>
		/// �Զ���ת���ַ���
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <returns></returns>
		virtual std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const = 0;

		constexpr IFormattable() {}

	public:
		/// <summary>
		/// ת��Ϊ�ַ���
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <returns></returns>
		std::wstring ToString(const wchar_t* fmt, const CultureInfo& loc) const
		{
			return CustomToString(fmt, loc);
		}

		/// <summary>
		/// ת��Ϊ�ַ���
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <returns></returns>
		std::wstring ToString(const wchar_t* fmt) const
		{
			return CustomToString(fmt, CultureInfo::Current());
		}

		/// <summary>
		/// ת��Ϊ�ַ���
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <returns></returns>
		std::wstring ToString(const CultureInfo& loc) const
		{
			return ToString(nullptr, loc);
		};

		/// <summary>
		/// ת��Ϊ�ַ���
		/// </summary>
		/// <returns></returns>
		std::wstring ToString() const
		{
			return ToString(nullptr);
		};
	};
}