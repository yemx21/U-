#pragma once 
#include "Type.h"
#include "Common.h"
namespace System
{
	class MemoryPtrType_impl;

	/*

	std::shared_ptr<T>:  HoldType=T
	std::weak_ptr<T>:  HoldType=T
	std::unique_ptr<T>:  HoldType=T
	auto_ptr<T>:  HoldType=T
	*/

	/// <summary>
	/// �ڴ�ָ������
	/// </summary>
	class RUNTIME_API MemoryPtrType final: public Type
	{
	protected:
		friend class TypeFactory;

		/// <summary>
		/// ����<see cref="MemoryPtrType"/>ʵ��.
		/// </summary>
		/// <param name="holdType">������</param>
		/// <param name="ptype">�ڴ�ָ������</param>
		/// <returns></returns>
		static const MemoryPtrType* MemoryPtrType::Create(_type holdType, MemoryPtrTypes ptype);
	public:
		virtual ~MemoryPtrType();

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		virtual const wchar_t* GetName() const;

		/// <summary>
		/// ��ȡ�ڴ�ָ������
		/// </summary>
		/// <returns></returns>
		MemoryPtrTypes GetPtrType() const;

		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		_type GetHoldType() const;

		/// <summary>
		/// ������
		/// </summary>
		__declspec(property(get = GetHoldType)) _type HoldType;

		/// <summary>
		/// �ڴ�ָ������
		/// </summary>
		__declspec(property(get = GetPtrTypes)) MemoryPtrTypes PtrType;
	private:
		friend class Type;
		friend class MemoryPtrType_impl;

		MemoryPtrType_impl* impl;
		MemoryPtrType(_type holdType, MemoryPtrTypes ptype);
	};
}