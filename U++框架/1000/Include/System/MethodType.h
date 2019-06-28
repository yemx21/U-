#pragma once 

#include "Anys.h"
namespace System
{
	
	class Object;
	class ClassInfo;
	class EnumInfo;
	class MethodInfo_impl;
	
	/// <summary>
	/// ��������
	/// </summary>
	enum class MethodKinds
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
	/// ��������
	/// </summary>
	class RUNTIME_API MethodType : public Type
	{
	private:
		Optional<std::wstring> description;
	public:
		/// <summary>
		/// ����ָ������ĵ�ǰ����
		/// </summary>
		/// <param name="result">���</param>
		/// <param name="obj">ָ������</param>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		virtual bool Invoke(Any* result, Object* obj, const OptionalVariadicAny& params, bool nothrow = true) const;

		/// <summary>
		/// ����ָ������ĵ�ǰ����
		/// </summary>
		/// <param name="result">���</param>
		/// <param name="obj">ָ������</param>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		virtual bool Invoke(Any* result, const Object* obj, const OptionalVariadicAny& parameters, bool nothrow = true) const;


		/// <summary>
		/// ����ָ������ĵ�ǰ����
		/// </summary>
		/// <param name="result">���</param>
		/// <param name="obj">ָ������</param>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		virtual bool Invoke(Any* result, volatile Object* obj, const OptionalVariadicAny& parameters, bool nothrow = true) const;


		/// <summary>
		/// ����ָ������ĵ�ǰ����
		/// </summary>
		/// <param name="result">���</param>
		/// <param name="obj">ָ������</param>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		virtual bool Invoke(Any* result, const volatile Object* obj, const OptionalVariadicAny& parameters, bool nothrow = true) const;


		/// <summary>
		/// ����ָ������ĵ�ǰ����
		/// </summary>
		/// <param name="result">���</param>
		/// <param name="obj">ָ������</param>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		bool Invoke(Any* result, nullptr_t obj, const OptionalVariadicAny& parameters, bool nothrow = true) const;

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
		/// ��ȡ��������
		/// </summary>
		///<return></return>
		MethodKinds GetKind() const;

		/// <summary>
		/// ��ȡ������
		/// </summary>
		///<return></return>
		unsigned int GetNumberOfParameters() const;

		/// <summary>
		/// ��������
		/// </summary>
		_declspec(property(get = GetKind)) MethodKinds Kind;

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

		virtual ~MethodType();

		bool operator ==(const MethodType& type) const;
		bool operator !=(const MethodType& type) const;
	protected:
		friend class MethodInfo; 
		friend class MethodInfo_impl;
		friend class ClassInfo;
		friend class EnumInfo;
		MethodType();
		_type  returnType;
		TypeCollection* paramTypes;
		SharedDefaultVariadicAny defaultParams;
		_type methodClass;
		MethodKinds kind;
	};

	template<int N, class...>
	class MethodTypeAdapter;

}