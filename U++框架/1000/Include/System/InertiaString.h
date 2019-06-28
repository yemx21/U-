#pragma once
#ifndef SYSTEM_INERTIASTRING
#define SYSTEM_INERTIASTRING

#include "Config.h"
#include <memory>
#include <string>
#include <mutex>

namespace System
{
	/// <summary>
	/// �����ַ���
	/// </summary>
	/// <remarks>ȫ��Ψһ���ַ������ʺ��������ڽϳ��Ľ϶��ַ�������Ҫ�����Ż��ַ����ڴ�ռ��</remarks>
	class RUNTIME_API InertiaString
	{
	private:	
		std::shared_ptr<const std::wstring> handle;
	public:
		/// <summary>
		/// ����<see cref="InertiaString"/>ʵ��.
		/// </summary>
		/// <param name="str">�ַ���</param>
		InertiaString(const std::wstring& str);

		/// <summary>
		/// ����<see cref="InertiaString"/>ʵ��.
		/// </summary>
		/// <param name="str">�ַ���</param>
		InertiaString(const wchar_t* str);

		/// <summary>
		/// ����<see cref="InertiaString"/>ʵ��.
		/// </summary>
		/// <param name="str">�ַ���</param>
		/// <param name="len">�ַ�������</param>
		InertiaString(const wchar_t* str, size_t len);

		InertiaString(InertiaString const&) = default;

		/// <summary>
		/// ����<see cref="InertiaString"/>ʵ��.
		/// </summary>
		InertiaString();

		~InertiaString() = default;

		InertiaString& operator = (InertiaString const&) = default;
		const std::wstring* operator -> () const throw();
		operator const std::wstring&() const throw();
		const std::wstring& get() const throw();
		void swap(InertiaString&) throw();

		template <class ValueType, class = std::enable_if_t<!std::is_same<InertiaString, std::decay_t<ValueType>>::value>>
		InertiaString& operator = (ValueType&& value)
		{
			InertiaString{ std::forward<ValueType>(value) }.swap(*this);
			return *this;
		}
	}; 
	RUNTIME_API bool operator == (System::InertiaString const& lhs, System::InertiaString const& rhs);

	RUNTIME_API bool operator != (System::InertiaString const& lhs, System::InertiaString const& rhs);

	RUNTIME_API bool operator >= (System::InertiaString const& lhs, System::InertiaString const& rhs);

	RUNTIME_API bool operator <= (System::InertiaString const& lhs, System::InertiaString const& rhs);

	RUNTIME_API bool operator > (System::InertiaString const& lhs, System::InertiaString const& rhs);

	RUNTIME_API bool operator < (System::InertiaString const& lhs, System::InertiaString const& rhs);

	RUNTIME_API bool operator == (System::InertiaString const& lhs, std::wstring const& rhs);

	RUNTIME_API bool operator != (System::InertiaString const& lhs, std::wstring const& rhs);

	RUNTIME_API bool operator >= (System::InertiaString const& lhs, std::wstring const& rhs);

	RUNTIME_API bool operator <= (System::InertiaString const& lhs, std::wstring const& rhs);

	RUNTIME_API bool operator > (System::InertiaString const& lhs, std::wstring const& rhs);

	RUNTIME_API bool operator < (System::InertiaString const& lhs, std::wstring const& rhs);
}





namespace std
{
	using namespace System;

	template <>
	struct std::hash<InertiaString>
	{
		size_t operator ()(InertiaString const& value) const throw()
		{
			return std::hash<std::wstring> { }(value);
		}
	};

}

#endif