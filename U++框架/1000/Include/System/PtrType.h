#pragma once 
#include "Type.h"
#include "InertiaString.h"
namespace System
{
	class PtrType_impl;

	/// <summary>
	/// ָ������
	/// </summary>
	class RUNTIME_API PtrType final: public Type
	{
	protected:
		friend class TypeFactory;

		/// <summary>
		/// ����<see cref="PtrType"/>ʵ��
		/// </summary>
		/// <param name="type">ָ��������</param>
		/// <param name="dimension">ά��</param>
		/// <returns></returns>
		static const PtrType* Create(_type type, UInt dimension);
	public:

		virtual ~PtrType();

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		virtual const wchar_t* GetName() const;

		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		_type GetBasicType() const;

		/// <summary>
		/// ��ȡά��
		/// </summary>
		/// <returns></returns>
		UInt8 GetDimension() const;

		/// <summary>
		/// ����
		/// </summary>
		__declspec(property(get = GetName)) const wchar_t* Name;

		/// <summary>
		/// ������
		/// </summary>
		__declspec(property(get = GetBasicType)) _type BasicType;

		/// <summary>
		/// ά��
		/// </summary>
		__declspec(property(get = GetDimension)) UInt8 Dimension;

	private:
		friend class Type; 
		friend class PtrType_impl;
		_type ptrType;
		UInt rank;
		InertiaString name;
		PtrType(_type type, UInt rank);

	};
}