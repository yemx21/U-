#pragma once 
#include "Type.h"
#include "InertiaString.h"
namespace System
{
	/// <summary>
	/// ��������
	/// </summary>
	enum class RefKinds
	{
		/// <summary>
		/// ��ֵ����
		/// </summary>
		Left,
		/// <summary>
		/// ��ֵ����
		/// </summary>
		Right
	};

	class RefType_impl;

	/// <summary>
	/// ��������
	/// </summary>
	class RUNTIME_API RefType final: public Type
	{
	protected:
		friend class TypeFactory;
		/// <summary>
		/// ����<see cref="RefType"/>ʵ��
		/// </summary>
		/// <param name="type">ָ��������</param>
		/// <param name="kind">��������</param>
		/// <returns></returns>
		static const RefType* Create(_type type, RefKinds kind);
	public:
			
		virtual ~RefType();

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		virtual const wchar_t* GetName() const;

		/// <summary>
		/// ��ȡ��������
		/// </summary>
		/// <returns></returns>
		RefKinds GetKind() const;

		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		_type GetBasicType() const;

		/// <summary>
		/// ����
		/// </summary>
		__declspec(property(get = GetName)) const wchar_t* Name;

		/// <summary>
		/// ��������
		/// </summary>
		__declspec(property(get = GetKind)) RefKinds Kind;

		/// <summary>
		/// ������
		/// </summary>
		__declspec(property(get = GetBasicType)) _type BasicType;

	private:
		friend class Type;
		friend class RefType_impl; 
		_type refType;
		InertiaString name;
		RefKinds refKind;
		RefType(_type type, RefKinds kind);
	};
}