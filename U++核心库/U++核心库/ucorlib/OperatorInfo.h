#pragma once 
#include "Type.h"
#include "Operators.h"
#include "RealVariadicAny.h"
#include <memory>

namespace System
{
	class Object;
	class ClassInfo;
	class EnumInfo;
	class OperatorType;
	class OperatorInfo_impl;

	/// <summary>
	/// �������Ϣ��
	/// </summary>
	class RUNTIME_API OperatorInfo final
	{
	private:
		friend class ClassInfo; 
		friend class EnumInfo;
		friend class OperatorInfo_impl;
		OperatorInfo_impl* impl;
		friend class ClassInfo;
		OperatorInfo(const wchar_t* name, OperatorType* type);

	public:

		/// <summary>
		/// ��ȡ����
		/// </summary>
		///<return></return>
		const wchar_t* GetName() const;

		/// <summary>
		/// ��ȡ���������
		/// </summary>
		///<return></return>
		Operators GetOperator() const;

		/// <summary>
		/// ��ȡ���������
		/// </summary>
		///<return></return>
		const OperatorType* GetType() const;

		/// <summary>
		/// ��ȡ��������
		/// </summary>
		///<return></return>
		_type GetDeclaringClass() const;

		/// <summary>
		/// ����ָ������ĵ�ǰ�����
		/// </summary>
		/// <param name="result">���</param>
		/// <param name="obj">ָ������</param>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		bool  Invoke(Any* result, Object* obj, const RealVariadicAny& parameters, bool nothrow = true) const;
		
		/// <summary>
		/// ����ָ������ĵ�ǰ�����
		/// </summary>
		/// <param name="result">���</param>
		/// <param name="obj">ָ������</param>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		bool  Invoke(Any* result, const Object* obj, const RealVariadicAny& parameters, bool nothrow = true) const;

		/// <summary>
		/// ����ָ������ĵ�ǰ�����
		/// </summary>
		/// <param name="result">���</param>
		/// <param name="obj">ָ������</param>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		bool Invoke(Any* result, nullptr_t obj, const RealVariadicAny& parameters, bool nothrow) const;

		/// <summary>
		/// ��������
		/// </summary>
		_declspec(property(get = GetDeclaringClass)) _type DeclaringClass;

		/// <summary>
		/// ���������
		/// </summary>
		_declspec(property(get = GetType)) const OperatorType* Type;

		/// <summary>
		/// ���������
		/// </summary>
		_declspec(property(get = GetOperator)) Operators Operator;

		/// <summary>
		/// ����
		/// </summary>
		__declspec(property(get = GetName)) const wchar_t* Name;

		~OperatorInfo();

		bool operator ==(const OperatorInfo& info) const;
		bool operator !=(const OperatorInfo& info) const;
	};
}