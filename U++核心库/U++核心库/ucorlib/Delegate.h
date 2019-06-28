#pragma once
#include "Any.h"

namespace System
{
	/// <summary>
	/// ί�нӿ���
	/// </summary>
	class RUNTIME_API Delegate
	{
	public:
		virtual bool GenericInvoke(const Any& sender, const OptionalVariadicAny& args, bool nothrow) const;
		virtual bool GenericInvoke(Any& result, const Any& sender, const OptionalVariadicAny& args, bool nothrow) const;
		virtual bool HasReturn() const;
	};

	typedef std::shared_ptr<Delegate> DelegatePtr;
}
