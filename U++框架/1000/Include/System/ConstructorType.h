#pragma once 
#include "OptionalVariadicAny.h"
#include "DefaultVariadicAny.h"
namespace System
{
	class Object;
	class ClassInfo; 
	class EnumInfo;
	class ConstructorInfo;
	class ConstructorInfo_impl;

	/// <summary>
	/// ���캯������
	/// </summary>
	class RUNTIME_API ConstructorType : public Type
	{
	private:
		Optional<std::wstring> description;
	public:
		/// <summary>
		/// ���õ�ǰ���캯��
		/// </summary>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		virtual Object* Invoke(const OptionalVariadicAny& parameters, bool nothrow = true) const = 0;

		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		_type GetClassType() const;

		/// <summary>
		/// ��ȡ����ֵ����
		/// </summary>
		/// <returns></returns>
		_type GetReturnType() const;

		/// <summary>
		/// ��ȡ�������ͼ���
		/// </summary>
		/// <returns></returns>
		const TypeCollection* GetParameterTypes() const;

		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		unsigned int GetNumberOfParameters() const;

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		const wchar_t* GetName() const;

		/// <summary>
		/// ������
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

		virtual ~ConstructorType();

		bool operator ==(const ConstructorType& type) const;
		bool operator !=(const ConstructorType& type) const;
	protected:
		friend class ConstructorInfo;
		friend class ConstructorInfo_impl;
		friend class ClassInfo;
		friend class EnumInfo;
		ConstructorType();
		_type  returnType;
		TypeCollection* paramTypes;
		SharedDefaultVariadicAny defaultParams;
		_type constructorClass;
		bool       isStatic;
	};

	template<int N, class __C>
	class ConstructorTypeAdapter;

}