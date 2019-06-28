#pragma once 

#include "RealVariadicAny.h"
#include "Operators.h"
namespace System
{

	class Object;
	class ClassInfo;
	class OperatorInfo_impl;

	/// <summary>
	/// ��������
	/// </summary>
	enum class OperatorKinds
	{
		/// <summary>
		/// ��ͨ
		/// </summary>
		Normal,
		/// <summary>
		/// ����
		/// </summary>
		Const,
		/// <summary>
		/// ���޸�
		/// </summary>
		Volatile,
		/// <summary>
		/// �������޸�
		/// </summary>
		ConstVolatile,
		/// <summary>
		/// ��̬
		/// </summary>
		Static,
	};


	/// <summary>
	/// �����������
	/// </summary>
	class RUNTIME_API OperatorType : public Type
	{
	private:
		Optional<std::wstring> description;
	public:

		/// <summary>
		/// ����ָ������ĵ�ǰ�����
		/// </summary>
		/// <param name="result">���</param>
		/// <param name="obj">ָ������</param>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		virtual bool Invoke(Any* result, Object* obj, const RealVariadicAny& parameters, bool nothrow = true) const;

		/// <summary>
		/// ����ָ������ĵ�ǰ�����
		/// </summary>
		/// <param name="result">���</param>
		/// <param name="obj">ָ������</param>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		virtual bool Invoke(Any* result, const Object* obj, const RealVariadicAny& parameters, bool nothrow = true) const;

		/// <summary>
		/// ����ָ������ĵ�ǰ�����
		/// </summary>
		/// <param name="result">���</param>
		/// <param name="obj">ָ������</param>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		virtual bool Invoke(Any* result, volatile Object* obj, const RealVariadicAny& parameters, bool nothrow = true) const;

		/// <summary>
		/// ����ָ������ĵ�ǰ�����
		/// </summary>
		/// <param name="result">���</param>
		/// <param name="obj">ָ������</param>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		virtual bool Invoke(Any* result, const volatile Object* obj, const RealVariadicAny& parameters, bool nothrow = true) const;

		/// <summary>
		/// ����ָ������ĵ�ǰ�����
		/// </summary>
		/// <param name="result">���</param>
		/// <param name="obj">ָ������</param>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		bool Invoke(Any* result, nullptr_t obj, const RealVariadicAny& parameters, bool nothrow = true) const;

		/// <summary>
		/// ��ȡ����
		/// </summary>
		///<return></return>
		const wchar_t* GetName() const;

		/// <summary>
		/// ��ȡ��������
		/// </summary>
		///<return></return>
		_type GetClassType() const;

		/// <summary>
		/// ��ȡ����ֵ����
		/// </summary>
		///<return></return>
		_type GetReturnType() const;

		/// <summary>
		/// ��ȡ�������ͼ���
		/// </summary>
		///<return></return>
		const TypeCollection* GetParameterTypes() const;

		/// <summary>
		/// ��ȡ������
		/// </summary>
		///<return></return>
		unsigned int GetNumberOfParameters() const;

		/// <summary>
		/// ��������
		/// </summary>
		_declspec(property(get = GetClassType)) _type ClassType;

		/// <summary>
		/// ����ֵ����
		/// </summary>
		_declspec(property(get = GetReturnType)) _type ReturnType;
		
		/// <summary>
		/// �������ͼ���
		/// </summary>
		_declspec(property(get = GetParameterTypes)) const TypeCollection* ParameterTypes;
		
		/// <summary>
		/// ������
		/// </summary>
		_declspec(property(get = GetNumberOfParameters)) unsigned int NumberOfParameters;

		virtual ~OperatorType();

		bool operator ==(const OperatorType& type) const;
		bool operator !=(const OperatorType& type) const;
	protected:
		friend class OperatorInfo;
		friend class OperatorInfo_impl;
		friend class ClassInfo;
		OperatorType();
		_type  returnType;
		TypeCollection* paramTypes;
		_type operatorClass;
		Operators op;
		OperatorKinds kind;
	};

	template<int N, Operators __OP, class __C, class __RT>
	class OperatorTypeAdapter;

}