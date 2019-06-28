#pragma once 
#include "Type.h"
#include "MethodInfo.h"
#include "ConstructorInfo.h"
#include "FieldInfo.h"
#include "PropertyInfo.h"
#include "OperatorInfo.h"
#include "Attribute.h"
#include <memory>
#include "Predicates.h"
#include "Enumerators.h"


namespace System
{
	class Factory;
	
	ENUM_FLAGS(ClassFlags)
	/// <summary>
	/// ���ʶö��
	/// </summary>
	enum class ClassFlags
	{
		/// <summary>
		/// ��ͨ
		/// </summary>
		Normal = 0x0000,
		/// <summary>
		/// ����
		/// </summary>
		Abstract = 0x0001,
		/// <summary>
		/// �ڲ�
		/// </summary>
		Internal = 0x0002,
	};

	/// <summary>
	/// ����Ϣ����ö��
	/// </summary>
	enum class ClassInfoError
	{
		/// <summary>
		/// �ɹ�
		/// </summary>
		OK = 0,
		/// <summary>
		/// �޴���
		/// </summary>
		None = 0,

		/// <summary>
		/// �Ѵ���
		/// </summary>
		AlreadyExisted,
		/// <summary>
		/// Ĭ�Ϲ��캯���Ѵ���
		/// </summary>
		DefaultConstructorExisted,
		/// <summary>
		/// δ֪����
		/// </summary>
		Unknown,
		/// <summary>
		/// �ղ���
		/// </summary>
		EmptyArgument,
		/// <summary>
		/// ��Ч����
		/// </summary>
		InvalidArgument,
	};

	struct ClassInfo_impl;

	struct ClassInfo_internal;

	class BaseClassEnumerator_impl;

	/// <summary>
	/// ����ö������
	/// </summary>
	class RUNTIME_API BaseClassEnumerator final: _noncopyable
	{
	private:
		friend class ClassInfo;
		BaseClassEnumerator_impl* impl;
		BaseClassEnumerator();
	public:
		~BaseClassEnumerator();

		/// <summary>
		/// ��ȡ������
		/// </summary>
		///<return></return>
		unsigned int GetCount() const;

		/// <summary>
		/// ��ȡ��ǰ��������
		/// </summary>
		///<return></return>
		const wchar_t* GetCurrentName() const;

		/// <summary>
		/// ��ȡ��ǰ����
		/// </summary>
		///<return></return>
		const ClassInfo* GetCurrent() const;

		/// <summary>
		/// ��ȡ��ǰ�������������ռ�
		/// </summary>
		///<return></return>
		const NameSpace* GetCurrentNameSpace() const;

		/// <summary>
		/// ��ȡ��ǰ������������
		/// </summary>
		///<return></return>
		const Assembly* GetCurrentAssembly() const;

		/// <summary>
		/// ��ȡ��һ������
		/// </summary>
		///<return></return>
		void Next();

		/// <summary>
		/// ��ȡ��һ������
		/// </summary>
		///<return></return>
		void Previous();

		/// <summary>
		/// �ж��Ƿ������ĩβ
		/// </summary>
		///<return></return>
		bool GetIsEnd() const;

		/// <summary>
		/// ��ǰ��������
		/// </summary>
		__declspec(property(get = GetCurrentName)) const wchar_t* CurrentName;

		/// <summary>
		/// ��ǰ����
		/// </summary>
		__declspec(property(get = GetCurrent)) const ClassInfo* Current;

		/// <summary>
		/// ��ǰ�������������ռ�
		/// </summary>
		__declspec(property(get = GetCurrentNameSpace)) const NameSpace* CurrentNameSpace;

		/// <summary>
		/// ��ǰ������������
		/// </summary>
		__declspec(property(get = GetCurrentAssembly)) const Assembly* CurrentAssembly;

		/// <summary>
		/// ������
		/// </summary>
		__declspec(property(get = GetCount)) unsigned int Count;

		/// <summary>
		/// �Ƿ������ĩβ
		/// </summary>
		__declspec(property(get = GetIsEnd)) bool IsEnd;
	};

	/// <summary>
	/// ����Ϣϵ��
	/// </summary>
	class RUNTIME_API ClassInfo final: public Type
	{
	private:
		friend class System::Factory;
		friend class Object;
		friend struct ClassInfo_internal;

		ClassInfo_impl* impl;
		ClassInfo_internal* internal;

		ClassInfoError AddBaseClass(_type type);
		ClassInfoError AddDefaultConstructor_impl(const wchar_t* name, ConstructorFlags flags, ConstructorType* type);
	public:
		typedef void(*DefineMetaFunc)(ClassInfo& type);
	protected:
		/// <summary>
		/// ����<see cref="ClassInfo"/>ʵ��.
		/// </summary>
		/// <param name="name">������</param>
		/// <param name="size">���С</param>
		/// <param name="flags">���ʶ</param>
		ClassInfo(const wchar_t* name, unsigned int size, ClassFlags flags);
	public:

		/// <summary>
		/// ����<see cref="ClassInfo"/>ʵ��
		/// </summary>
		/// <param name="pointer">����Ϣָ��</param>
		/// <param name="func">����Ϣ���庯��</param>
		/// <param name="name">������</param>
		/// <param name="size">���С</param>
		/// <param name="flags">���ʶ</param>
		/// <remarks>�ڲ���ר��</remarks>
		static void Create(Type const*& pointer, DefineMetaFunc func, const wchar_t* name, unsigned int size, ClassFlags flags);

		/// <summary>
		/// ����<see cref="ClassInfo"/>ʵ��
		/// </summary>
		/// <param name="pointer">����Ϣָ��</param>
		/// <param name="name">������</param>
		/// <param name="size">���С</param>
		/// <param name="flags">���ʶ</param>
		/// <remarks>�ڲ���ר��</remarks>
		template<class T>
		static void Create(Type const*& pointer, const wchar_t* name, unsigned int size, ClassFlags flags)
		{
			Create(pointer, &T::DefineMeta, name, size, flags);
		}

		~ClassInfo();
	public:

		/// <summary>
		/// ��ȡ����ö����
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<BaseClassEnumerator> GetBaseClassEnumerator() const;

		/// <summary>
		/// ��ȡ����ö����
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<MethodEnumerator> GetMethodEnumerator() const;

		/// <summary>
		/// ��ȡ����ö����������
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<MethodReverseEnumerator> GetMethodReverseEnumerator() const;

		/// <summary>
		/// ��ȡ���캯��ö����
		/// </summary>
		/// <returns></returns>	
		std::unique_ptr<ConstructorEnumerator> GetConstructorEnumerator() const;

		/// <summary>
		/// ��ȡ���캯��ö����������
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<ConstructorReverseEnumerator> GetConstructorReverseEnumerator() const;

		/// <summary>
		/// ��ȡ����ö����
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<PropertyEnumerator> GetPropertyEnumerator() const;

		/// <summary>
		/// ��ȡ����ö����������
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<PropertyReverseEnumerator> GetPropertyReverseEnumerator() const;

		/// <summary>
		/// ��ȡ�����ö����
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<OperatorEnumerator> GetOperatorEnumerator() const;

		/// <summary>
		/// ��ȡ�����ö����������
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<OperatorReverseEnumerator> GetOperatorReverseEnumerator() const;

		/// <summary>
		/// ��ȡ��ǩö����
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<AttributeEnumerator> GetAttributeEnumerator() const;

		/// <summary>
		/// ��ȡ��ǩö����������
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<AttributeReverseEnumerator> GetAttributeReverseEnumerator() const;

		/// <summary>
		/// ��ȡ��Ա����ö����
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<FieldEnumerator> GetFieldEnumerator() const;

		/// <summary>
		/// ��ȡ��Ա����ö����������
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<FieldReverseEnumerator> GetFieldReverseEnumerator() const;

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		const wchar_t* GetName() const;		

		/// <summary>
		/// ��ȡ���С
		/// </summary>
		/// <returns></returns>
		unsigned int GetSize() const;

		/// <summary>
		/// ��ȡ���ʶ
		/// </summary>
		/// <returns></returns>
		ClassFlags GetFlags() const;

		/// <summary>
		/// ��ȡ��Ա������
		/// </summary>
		/// <returns></returns>
		unsigned int GetNumberOfFields()const;

		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		unsigned int GetNumberOfMethods()const;

		/// <summary>
		/// ��ȡ���캯��������
		/// </summary>
		/// <returns></returns>
		unsigned int GetNumberOfConstructors()const;

		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		unsigned int GetNumberOfProperties()const;

		/// <summary>
		/// ��ȡ�������
		/// </summary>
		/// <returns></returns>
		unsigned int GetNumberOfOperators()const;

		/// <summary>
		/// ��ȡ��ǩ��
		/// </summary>
		/// <returns></returns>
		unsigned int GetNumberOfAttributes()const;

		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		unsigned int GetNumberOfBaseClasses()const;

		/// <summary>
		/// �ж��Ƿ�̳���ָ������
		/// </summary>
		/// <param name="info">ָ������</param>
		/// <returns></returns>
		bool IsBaseOf(_type info)const;

		/// <summary>
		/// ���ҵ�һ��ƥ��Ĺ��캯��
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">���캯����ʶ</param>
		/// <returns></returns>
		const ConstructorInfo* FindFirstConstructor(const wchar_t* name, ConstructorFlags flags = ConstructorFlags::Public)const;

		/// <summary>
		/// ���ҵ�һ��ƥ��ķ���
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">������ʶ</param>
		/// <returns></returns>
		const MethodInfo* FindFirstMethod(const wchar_t* name, MethodFlags flags = MethodFlags::Public)const;

		/// <summary>
		/// ���ҵ�һ��ƥ�������
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">���Ա�ʶ</param>
		/// <returns></returns>
		const PropertyInfo* FindFirstProperty(const wchar_t* name, PropertyFlags flags = PropertyFlags::Public)const;

		/// <summary>
		/// ���ҵ�һ��ƥ��������
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="op">���������</param>
		/// <param name="defaultDeclaration">Ĭ������</param>
		/// <returns></returns>
		const OperatorInfo* FindFirstOperator(const wchar_t* name, Operators op, bool defaultDeclaration = true)const;

		/// <summary>
		/// ���ҵ�һ��ƥ��������
		/// </summary>
		/// <param name="op">���������</param>
		/// <param name="defaultDeclaration">Ĭ������</param>
		/// <returns></returns>
		const OperatorInfo* FindFirstOperator(Operators op, bool defaultDeclaration = true) const;

		/// <summary>
		/// ���ҵ�һ��ƥ��ı�ǩ
		/// </summary>
		/// <param name="name">����</param>
		/// <returns></returns>
		const Attribute* FindFirstAttribute(const wchar_t* name) const;

		/// <summary>
		/// ���ҵ�һ��ƥ��ı�ǩ
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��ǩ��ʶ</param>
		/// <returns></returns>
		const Attribute* FindFirstAttribute(const wchar_t* name, AttributeFlags flag) const;

		/// <summary>
		/// ���ҵ�һ��ƥ��Ĺ��캯��
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��ǩ��ʶ</param>
		/// <returns></returns>
		const Attribute* FindFirstAttribute(AttributeFlags flag) const;

		/// <summary>
		/// ���ҵ�һ��ƥ��ĳ�Ա����
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��Ա������ʶ</param>
		/// <returns></returns>
		const FieldInfo* FindFirstField(const wchar_t* name, FieldFlags flags) const;

		/// <summary>
		/// ��ȡĬ�Ϲ��캯��
		/// </summary>
		/// <returns></returns>
		const ConstructorInfo* GetDefaultConstructor() const;

		/// <summary>
		/// ��ȡ��һ��ƥ��Ĺ��캯��
		/// </summary>
		/// <param name="predicate">���캯��ƥ����</param>
		/// <returns></returns>
		const ConstructorInfo* FindFirstConstructor(ConstructorPredicate predicate)const;

		/// <summary>
		/// ��ȡ��һ��ƥ��ķ���
		/// </summary>
		/// <param name="predicate">����ƥ����</param>
		/// <returns></returns>
		const MethodInfo* FindFirstMethod(MethodPredicate predicate)const;

		/// <summary>
		/// ��ȡ��һ��ƥ�������
		/// </summary>
		/// <param name="predicate">����ƥ����</param>
		/// <returns></returns>
		const PropertyInfo* FindFirstProperty(PropertyPredicate predicate)const;

		/// <summary>
		/// ��ȡ��һ��ƥ��������
		/// </summary>
		/// <param name="predicate">�����ƥ����</param>
		/// <returns></returns>
		const OperatorInfo* FindFirstOperator(OperatorPredicate predicate)const;

		/// <summary>
		/// ��ȡ��һ��ƥ��ı�ǩ
		/// </summary>
		/// <param name="predicate">��ǩƥ����</param>
		/// <returns></returns>
		const Attribute* FindFirstAttribute(AttributePredicate predicate)const;

		/// <summary>
		/// ��ȡ��һ��ƥ��ĳ�Ա����
		/// </summary>
		/// <param name="predicate">��Ա����ƥ����</param>
		/// <returns></returns>
		const FieldInfo* FindFirstField(FieldPredicate predicate)const;

		/// <summary>
		/// ��ȡ�Զ��幹�캯��ƥ����ö����
		/// </summary>
		/// <param name="predicate">���캯��ƥ����</param>
		/// <returns></returns>
		std::unique_ptr<ConstructorQueryEnumerator> FindConstructors(ConstructorPredicate predicate)const;

		/// <summary>
		/// ��ȡ�Զ��巽��ƥ����ö����
		/// </summary>
		/// <param name="predicate">����ƥ����</param>
		/// <returns></returns>
		std::unique_ptr<MethodQueryEnumerator> FindMethods(MethodPredicate predicate)const;

		/// <summary>
		/// ��ȡ�Զ�������ƥ����ö����
		/// </summary>
		/// <param name="predicate">����ƥ����</param>
		/// <returns></returns>
		std::unique_ptr<PropertyQueryEnumerator> FindProperties(PropertyPredicate predicate)const;

		/// <summary>
		/// ��ȡ�Զ��������ƥ����ö����
		/// </summary>
		/// <param name="predicate">�����ƥ����</param>
		/// <returns></returns>
		std::unique_ptr<OperatorQueryEnumerator> FindOperators(OperatorPredicate predicate)const;

		/// <summary>
		/// ��ȡ�Զ����ǩƥ����ö����
		/// </summary>
		/// <param name="predicate">��ǩƥ����</param>
		/// <returns></returns>
		std::unique_ptr<AttributeQueryEnumerator> FindAttributes(AttributePredicate predicate)const;

		/// <summary>
		/// ��ȡ�Զ����Ա����ƥ����ö����
		/// </summary>
		/// <param name="predicate">��Ա����ƥ����</param>
		/// <returns></returns>
		std::unique_ptr<FieldQueryEnumerator> FindFields(FieldPredicate predicate)const;

		/// <summary>
		/// ����
		/// </summary>
		__declspec(property(get = GetName)) const wchar_t* Name;

		/// <summary>
		/// Ĭ�Ϲ��캯��
		/// </summary>
		__declspec(property(get = GetDefaultConstructor)) const ConstructorInfo* DefaultConstructor;

		/// <summary>
		/// ������
		/// </summary>
		__declspec(property(get = GetNumberOfBaseClasses)) unsigned int NumberOfBaseClasses;

		/// <summary>
		/// ������
		/// </summary>
		__declspec(property(get = GetNumberOfMethods)) unsigned int NumberOfMethods;

		/// <summary>
		/// ��Ա������
		/// </summary>
		__declspec(property(get = GetNumberOfFields)) unsigned int NumberOfFields;

		/// <summary>
		/// ���캯����
		/// </summary>
		__declspec(property(get = GetNumberOfConstructors)) unsigned int NumberOfConstructors;

		/// <summary>
		/// ������
		/// </summary>
		__declspec(property(get = GetNumberOfProperties)) unsigned int NumberOfProperties;

		/// <summary>
		/// �������
		/// </summary>
		__declspec(property(get = GetNumberOfOperators)) unsigned int NumberOfOperators;

		/// <summary>
		/// ��ǩ��
		/// </summary>
		__declspec(property(get = GetNumberOfAttributes)) unsigned int NumberOfAttributes;

		/// <summary>
		///���ӹ��캯��
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��ʶ</param>
		/// <param name="type">���캯������</param>
		/// <param name="defaultParams">Ĭ�ϲ���</param>
		/// <returns></returns>
		ClassInfoError AddConstructor(const wchar_t* name, ConstructorFlags flags, ConstructorType* type, SharedDefaultVariadicAny defaultParams = nullptr);

		template<class __C>
		/// <summary>
		///����Ĭ�Ϲ��캯��
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��ʶ</param>
		/// <param name="type">���캯������</param>
		/// <returns></returns>
		ClassInfoError AddDefaultConstructor(const wchar_t* name, ConstructorFlags flags, Object* (*func)())
		{
			return AddDefaultConstructor_impl(name, flags, ConstructorTypeAdapter<0, __C>::Create(func));
		}

		/// <summary>
		///���ӷ���
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��ʶ</param>
		/// <param name="type">��������</param>
		/// <param name="defaultParams">Ĭ�ϲ���</param>
		/// <returns></returns>
		ClassInfoError AddMethod(const wchar_t* name, MethodFlags flags, MethodType* type, SharedDefaultVariadicAny defaultParams = nullptr);

		/// <summary>
		///��������
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��ʶ</param>
		/// <param name="type">��������</param>
		/// <returns></returns>
		ClassInfoError AddProperty(const wchar_t* name, PropertyFlags flags, PropertyType* type); 

		/// <summary>
		///���ӳ�Ա����
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��ʶ</param>
		/// <param name="type">��Ա��������</param>
		/// <returns></returns>
		ClassInfoError AddField(const wchar_t* name, FieldFlags flags, FieldType* type);

		/// <summary>
		///���������
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��ʶ</param>
		/// <param name="type">���������</param>
		/// <returns></returns>
		ClassInfoError AddOperator(const wchar_t* name, OperatorType* type);

		/// <summary>
		///���ӱ�ǩ
		/// </summary>
		/// <param name="name">����</param>
		/// <returns></returns>
		ClassInfoError AddAttribute(Attribute* attribute);

		/// <summary>
		/// ���ӻ���
		/// </summary>
		/// <returns></returns>
		template<typename T>
		ClassInfoError AddBaseClass()
		{
			_type ty = TypeFactory::Create<T>();
			if (ty) return AddBaseClass(ty);
			return ClassInfoError::InvalidArgument;
		}

		/// <summary>
		/// ����ģ���������
		/// </summary>
		/// <param name="index">ģ���������</param>
		/// <param name="argumentType">��������</param>
		/// <returns></returns>
		bool DefineTemplateArgument(size_t index, _type argumentType);

		/// <summary>
		/// ���÷���
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">������ʶ</param>
		/// <param name="result">���</param>
		/// <param name="obj">��ǰ���͵�ָ������</param>
		/// <param name="params">����</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		/// <returns></returns>
		bool InvokeMethod(const wchar_t* name, MethodFlags flags, Any* result, Object* obj, const OptionalVariadicAny& params, bool nothrow=true)const;

		/// <summary>
		/// ���÷���
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">������ʶ</param>
		/// <param name="result">���</param>
		/// <param name="obj">��ǰ���͵�ָ������</param>
		/// <param name="params">����</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		/// <returns></returns>
		bool InvokeMethod(const wchar_t* name, MethodFlags flags, Any* result, const Object* obj, const OptionalVariadicAny& params, bool nothrow = true)const;

		/// <summary>
		/// ���÷���
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">������ʶ</param>
		/// <param name="result">���</param>
		/// <param name="obj">��ǰ���͵�ָ������</param>
		/// <param name="params">����</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		/// <returns></returns>
		bool InvokeMethod(const wchar_t* name, MethodFlags flags, Any* result, nullptr_t obj, const OptionalVariadicAny& params, bool nothrow = true)const;

		/// <summary>
		/// ��ȡ����ֵ
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">���Ա�ʶ</param>
		/// <param name="result">���</param>
		/// <param name="obj">��ǰ���͵�ָ������</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		/// <returns></returns>
		bool GetProperty(const wchar_t* name, PropertyFlags flags, Any* result, Object* obj, bool nothrow = true)const;

		/// <summary>
		/// ��ȡ����ֵ
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">���Ա�ʶ</param>
		/// <param name="result">���</param>
		/// <param name="obj">��ǰ���͵�ָ������</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		/// <returns></returns>
		bool GetProperty(const wchar_t* name, PropertyFlags flags, Any* result, const Object* obj, bool nothrow = true)const;

		/// <summary>
		/// ��ȡ����ֵ
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">���Ա�ʶ</param>
		/// <param name="result">���</param>
		/// <param name="obj">��ǰ���͵�ָ������</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		/// <returns></returns>
		bool GetProperty(const wchar_t* name, PropertyFlags flags, Any* result, nullptr_t obj, bool nothrow = true)const;

		/// <summary>
		/// ��������ֵ
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">���Ա�ʶ</param>
		/// <param name="value">ֵ</param>
		/// <param name="obj">��ǰ���͵�ָ������</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		/// <returns></returns>
		bool SetProperty(const wchar_t* name, PropertyFlags flags, const Any& value, Object* obj, bool nothrow = true)const;

		/// <summary>
		/// ��������ֵ
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">���Ա�ʶ</param>
		/// <param name="value">ֵ</param>
		/// <param name="obj">��ǰ���͵�ָ������</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		/// <returns></returns>
		bool SetProperty(const wchar_t* name, PropertyFlags flags, const Any& value, const Object* obj, bool nothrow = true)const;

		/// <summary>
		/// ��������ֵ
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">���Ա�ʶ</param>
		/// <param name="value">ֵ</param>
		/// <param name="obj">��ǰ���͵�ָ������</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		/// <returns></returns>
		bool SetProperty(const wchar_t* name, PropertyFlags flags, const Any& value, nullptr_t obj, bool nothrow = true)const;


		/// <summary>
		/// ��ȡ��Ա����ֵ
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��Ա������ʶ</param>
		/// <param name="result">���</param>
		/// <param name="obj">��ǰ���͵�ָ������</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		/// <returns></returns>
		bool GetField(const wchar_t* name, FieldFlags flags, Any* result, nullptr_t obj, bool nothrow = true)const;

		/// <summary>
		/// ���ó�Ա����ֵ
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��Ա������ʶ</param>
		/// <param name="value">ֵ</param>
		/// <param name="obj">��ǰ���͵�ָ������</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		/// <returns></returns>
		bool SetField(const wchar_t* name, FieldFlags flags, const Any& value, Object* obj, bool nothrow = true)const;

		/// <summary>
		/// ���������
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="op">���������</param>
		/// <param name="defaultDeclaration">Ĭ������</param>
		/// <param name="result">���</param>
		/// <param name="obj">��ǰ���͵�ָ������</param>
		/// <param name="params">����</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		/// <returns></returns>
		bool InvokeOperator(const wchar_t* name, Operators op, bool defaultDeclaration, Any* result, Object* obj, const RealVariadicAny& params, bool nothrow = true) const;

		/// <summary>
		/// ���������
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="op">���������</param>
		/// <param name="defaultDeclaration">Ĭ������</param>
		/// <param name="result">���</param>
		/// <param name="obj">��ǰ���͵�ָ������</param>
		/// <param name="params">����</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		/// <returns></returns>
		bool InvokeOperator(const wchar_t* name, Operators op, bool defaultDeclaration, Any* result, const Object* obj, const RealVariadicAny& params, bool nothrow = true) const;

		/// <summary>
		/// ���������
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="op">���������</param>
		/// <param name="defaultDeclaration">Ĭ������</param>
		/// <param name="result">���</param>
		/// <param name="obj">��ǰ���͵�ָ������</param>
		/// <param name="params">����</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		/// <returns></returns>
		bool InvokeOperator(const wchar_t* name, Operators op, bool defaultDeclaration, Any* result, nullptr_t obj, const RealVariadicAny& params, bool nothrow = true) const;
	};
}