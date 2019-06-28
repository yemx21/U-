#pragma once
#include "Config.h"
#include <cstdint>

namespace System
{
	class Type;
	class Assembly;
	class NameSpace;

	/// <summary>
	/// ��Ա��Ϣ��
	/// </summary>
	class MemberInfo
	{
	public:

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		virtual const wchar_t* GetName() const = 0;
	};
}