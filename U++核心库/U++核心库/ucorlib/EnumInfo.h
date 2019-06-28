#pragma once
#include "Type.h"
#include "Any.h"
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
	/// <summary>
	/// ö����Ϣö��
	/// </summary>
	enum class EnumInfoError
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
		InvalidType,
		/// <summary>
		/// Ĭ�Ϲ��캯���Ѵ���
		/// </summary>
		DefaultConstructorExisted,
	};

	struct EnumInfo_impl;
	struct EnumInfo_internal;
	class EnumReverseEnumerator_impl;
	class EnumEnumerator_impl;

	/// <summary>
	/// ö��ֵö������
	/// </summary>
	class RUNTIME_API EnumEnumerator:_noncopyable
	{
	private:
		friend class EnumInfo;
		friend class EnumEnumerator_impl;
		EnumEnumerator_impl* impl;
		EnumEnumerator();
	public:
		~EnumEnumerator();

		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		size_t GetCount() const;

		/// <summary>
		/// ��ȡ��ǰ��������
		/// </summary>
		/// <returns></returns>
		std::wstring GetCurrentName() const;

		/// <summary>
		/// ��ȡ��ǰ����
		/// </summary>
		/// <returns></returns>
		StandardInterger GetCurrentValue() const;

		/// <summary>
		/// ��ȡ��ǰ�����ϣֵ
		/// </summary>
		/// <returns></returns>
		uhash GetCurrentHashCode() const;

		/// <summary>
		/// ��ȡ��һ������
		/// </summary>
		/// <returns></returns>
		void Next();

		/// <summary>
		/// ��ȡ��һ������
		/// </summary>
		/// <returns></returns>
		void Previous();

		/// <summary>
		/// ��ȡ�Ƿ������ĩβ
		/// </summary>
		/// <returns></returns>
		bool GetIsEnd() const;

		/// <summary>
		/// ��ǰ��������
		/// </summary>
		__declspec(property(get = GetCurrentName)) std::wstring CurrentName;
		/// <summary>
		/// ��ǰ����
		/// </summary>
		__declspec(property(get = GetCurrentValue)) StandardInterger CurrentValue;
		/// <summary>
		/// ��ǰ�����ϣֵ
		/// </summary>
		__declspec(property(get = GetCurrentHashCode)) uhash CurrentHashCode;
		/// <summary>
		/// ������
		/// </summary>
		__declspec(property(get = GetCount)) size_t Count;
		/// <summary>
		/// �Ƿ������ĩβ
		/// </summary>
		__declspec(property(get = GetIsEnd)) bool IsEnd;
	};

	/// <summary>
	/// ö��ֵö�����ࣨ����
	/// </summary>
	class RUNTIME_API EnumReverseEnumerator :_noncopyable
	{
	private:
		friend class EnumInfo;
		friend class EnumReverseEnumerator_impl;
		EnumReverseEnumerator_impl* impl;
		EnumReverseEnumerator();
	public:
		~EnumReverseEnumerator();

		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		size_t GetCount() const;

		/// <summary>
		/// ��ȡ��ǰ��������
		/// </summary>
		/// <returns></returns>
		std::wstring GetCurrentName() const;

		/// <summary>
		/// ��ȡ��ǰ����
		/// </summary>
		/// <returns></returns>
		StandardInterger GetCurrentValue() const;

		/// <summary>
		/// ��ȡ��ǰ�����ϣֵ
		/// </summary>
		/// <returns></returns>
		uhash GetCurrentHashCode() const;

		/// <summary>
		/// ��ȡ��һ������
		/// </summary>
		/// <returns></returns>
		void Next();

		/// <summary>
		/// ��ȡ��һ������
		/// </summary>
		/// <returns></returns>
		void Previous();

		/// <summary>
		/// ��ȡ�Ƿ������ĩβ
		/// </summary>
		/// <returns></returns>
		bool GetIsEnd() const;

		/// <summary>
		/// ��ǰ��������
		/// </summary>
		__declspec(property(get = GetCurrentName)) std::wstring CurrentName;
		/// <summary>
		/// ��ǰ����
		/// </summary>
		__declspec(property(get = GetCurrentValue)) StandardInterger CurrentValue;
		/// <summary>
		/// ��ǰ�����ϣֵ
		/// </summary>
		__declspec(property(get = GetCurrentHashCode)) uhash CurrentHashCode;
		/// <summary>
		/// ������
		/// </summary>
		__declspec(property(get = GetCount)) size_t Count;
		/// <summary>
		/// �Ƿ������ĩβ
		/// </summary>
		__declspec(property(get = GetIsEnd)) bool IsEnd;
	};

	/// <summary>
	/// ö����Ϣ��
	/// </summary>
	class RUNTIME_API EnumInfo final: public Type
	{
	private:
		friend class System::Factory;
		friend class Object;
		EnumInfo_impl* impl; 
		EnumInfo_internal* internal;
		EnumInfoError InternalAddValue(const wchar_t* valueName, const StandardInterger& value, uhash hashCode);
	public:
		typedef void(*DefineMetaFunc)(EnumInfo& type);
	protected:
		friend struct EnumInfo_internal;
		/// <summary>
		/// ����<see cref="EnumInfo"/>ʵ��.
		/// </summary>
		/// <param name="name">ö������</param>
		/// <param name="value">ֵ����</param>
		EnumInfo(const wchar_t* name, _type valueType);

	public:
		/// <summary>
		/// ����<see cref="EnumInfo"/>ʵ��
		/// </summary>
		/// <param name="pointer">ö����Ϣָ��</param>
		/// <param name="func">ö����Ϣ���庯��</param>
		/// <param name="name">ö������</param>
		/// <param name="valueType">ö��ǿ����</param>
		/// <remarks>�ڲ���ר��</remarks>
		static void Create(Type const*& pointer, DefineMetaFunc func, const wchar_t* name, _type valueType);

		/// <summary>
		/// ����<see cref="EnumInfo"/>ʵ��
		/// </summary>
		/// <param name="pointer">ö����Ϣָ��</param>
		/// <param name="name">ö������</param>
		/// <param name="valueType">ö��ǿ����</param>
		/// <remarks>�ڲ���ר��</remarks>
		template<class T, class BASE>
		static typename std::enable_if< std::is_integral<BASE>::value, void>::type Create(Type const*& pointer, const wchar_t* name)
		{
			Create(pointer, &T::DefineMeta, name, TypeFactory::Create<BASE>());
		}

		~EnumInfo();

	public:
		template<class T>	
		typename std::enable_if<std::is_enum<T>::value, EnumInfoError>::type AddValue(const wchar_t* valueName, T value, uhash hashCode)
		{
			return InternalAddValue(valueName, static_cast<std::underlying_type<T>::type>(value), hashCode);
		};

		/// <summary>
		/// ���Խ���ָ���ַ���
		/// </summary>
		/// <param name="valueName">ָ���ַ���</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		bool TryParse(const wchar_t* valueName, StandardInterger& result) const;

		/// <summary>
		/// ���Դ�ָ�������ȡ�ַ������
		/// </summary>
		/// <param name="value">ָ������</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		bool TryGetValueName(const StandardInterger& value, std::wstring& result) const;

		/// <summary>
		/// ���Դ�ָ��ö�����͵Ķ����ȡ�ַ������
		/// </summary>
		/// <param name="enumType">ָ��ö������</param>
		/// <param name="value">ָ������</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		static bool TryGetValueName(_type enumType, const StandardInterger& value, std::wstring& result);

		/// <summary>
		/// ���Խ���ָ���ַ���
		/// </summary>
		/// <param name="hashCode">��ϣֵ</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		bool TryParse(uhash hashCode, StandardInterger& result) const;

		/// <summary>
		/// ���Դ�ָ�������ȡ�ַ������
		/// </summary>
		/// <param name="value">ָ������</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		bool TryGetHashCode(const StandardInterger& value, uhash& result) const;

		/// <summary>
		/// ���Դ�ָ��ö�����͵Ķ����ȡ��ϣֵ���
		/// </summary>
		/// <param name="enumType">ָ��ö������</param>
		/// <param name="value">ָ������</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		static bool TryGetHashCode(_type enumType, const StandardInterger& value, uhash& result);

		/// <summary>
		/// ��ȡö��ֵö����
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<EnumEnumerator> GetEnumEnumerator() const;

		/// <summary>
		/// ��ȡö��ֵö����������
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<EnumReverseEnumerator> GetEnumReverseEnumerator() const;

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
		/// ��ȡö��ֵ��
		/// </summary>
		/// <returns></returns>
		size_t GetCount() const;

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		const wchar_t* GetName() const;

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
		/// ��ȡö��ǿ����
		/// </summary>
		/// <returns></returns>
		_type GetValueType() const;

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
		/// ö��ֵ��
		/// </summary>
		__declspec(property(get = GetCount)) size_t Count;

		/// <summary>
		/// ö��ǿ����
		/// </summary>
		__declspec(property(get = GetValueType)) _type ValueType;

		/// <summary>
		///���ӹ��캯��
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��ʶ</param>
		/// <param name="type">���캯������</param>
		/// <param name="defaultParams">Ĭ�ϲ���</param>
		/// <returns></returns>
		EnumInfoError AddConstructor(const wchar_t* name, ConstructorFlags flags, ConstructorType* type, SharedDefaultVariadicAny defaultParams = nullptr);

		/// <summary>
		///����Ĭ�Ϲ��캯��
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��ʶ</param>
		/// <param name="type">���캯������</param>
		/// <returns></returns>
		EnumInfoError AddDefaultConstructor(const wchar_t* name, ConstructorFlags flags, ConstructorType* type);

		/// <summary>
		///���ӷ���
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��ʶ</param>
		/// <param name="type">��������</param>
		/// <param name="defaultParams">Ĭ�ϲ���</param>
		/// <returns></returns>
		EnumInfoError AddMethod(const wchar_t* name, MethodFlags flags, MethodType* type, SharedDefaultVariadicAny defaultParams = nullptr);

		/// <summary>
		///��������
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��ʶ</param>
		/// <param name="type">��������</param>
		/// <returns></returns>
		EnumInfoError AddProperty(const wchar_t* name, PropertyFlags flags, PropertyType* type);

		/// <summary>
		///���ӳ�Ա����
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��ʶ</param>
		/// <param name="type">��Ա��������</param>
		/// <returns></returns>
		EnumInfoError AddField(const wchar_t* name, FieldFlags flags, FieldType* type);

		/// <summary>
		///���������
		/// </summary>
		/// <param name="name">����</param>
		/// <param name="flags">��ʶ</param>
		/// <param name="type">���������</param>
		/// <returns></returns>
		EnumInfoError AddOperator(const wchar_t* name, OperatorType* type);

		/// <summary>
		///���ӱ�ǩ
		/// </summary>
		/// <param name="name">����</param>
		/// <returns></returns>
		EnumInfoError AddAttribute(Attribute* attribute);

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
		bool InvokeMethod(const wchar_t* name, MethodFlags flags, Any* result, Object* obj, const OptionalVariadicAny& params, bool nothrow = true)const;

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
		bool InvokeOperator(const wchar_t* name, Operators op, bool defaultDeclaration, Any* result, nullptr_t obj, const RealVariadicAny& params, bool nothrow = true) const;	};
}
