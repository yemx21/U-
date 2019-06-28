#pragma once
#include "Optional.h"
#include "Type.h"
namespace System
{
	class OptionalType_impl;

	/// <summary>
	/// �ɿ�����
	/// </summary>
	class RUNTIME_API OptionalType final: public Type
	{
	protected:
		friend class TypeFactory;

		/// <summary>
		/// ����<see cref="OptionalType"/>ʵ��
		/// </summary>
		/// <param name="type">����</param>
		/// <returns></returns>
		static const OptionalType* Create(_type type);
	public:

		virtual ~OptionalType();

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		virtual const wchar_t* GetName() const;

		/// <summary>
		/// ����
		/// </summary>
		__declspec(property(get = GetName)) const wchar_t* Name;

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		_type GetType() const;

		/// <summary>
		/// ����
		/// </summary>
		__declspec(property(get = GetType)) _type Type;

	private:
		friend class Type;
		friend class OptionalType_impl;
		OptionalType_impl* impl;
		OptionalType(_type type);

	};

}