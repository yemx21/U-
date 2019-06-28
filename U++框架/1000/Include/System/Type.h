#pragma once
#include "MemberInfo.h"
#include "Optional.h"
#include "DynamicArray.h"
namespace System
{
	class ClassInfo;
	class FieldInfo;
	class MethodInfo;

	class PtrType;
	class ArrayType;
	class RefType;
	class ModifiedType;
	class TypeFactory;

	/// <summary>
	/// ���ͱ�ǩ
	/// </summary>
	enum class TypeTag
	{
		/// <summary>
		/// δ֪
		/// </summary>
		Unknown,

		/// <summary>
		/// ���
		/// </summary>
		Object,
		/// <summary>
		/// �κ�
		/// </summary>
		Any,
		/// <summary>
		/// �䳤���ϣ��κΣ�
		/// </summary>
		VariadicAny,
		/// <summary>
		/// ��ʵ������ı䳤���ϣ��κΣ�
		/// </summary>
		RealVariadicAny,
		/// <summary>
		/// ��Ĭ�ϱ䳤���ϣ��κΣ�
		/// </summary>
		DefaultVariadicAny,
		/// <summary>
		/// ��ѡ�䳤���ϣ��κΣ�
		/// </summary>
		OptionalVariadicAny,
		/// <summary>
		/// ��ȫ��ָ��
		/// </summary>
		SafeVoidPtr,
		/// <summary>
		/// �����ַ���
		/// </summary>
		InertiaString,

		/// <summary>
		/// ��
		/// </summary>
		Void,
		/// <summary>
		/// �ַ���խ��
		/// </summary>
		Char,
		/// <summary>
		/// �޷����ַ���խ��
		/// </summary>
		UChar,
		/// <summary>
		/// �ַ�����
		/// </summary>
		WChar,
		/// <summary>
		/// 16λ����
		/// </summary>
		Short,
		/// <summary>
		/// �޷���16λ����
		/// </summary>
		UShort,
		/// <summary>
		/// ����
		/// </summary>
		Int,
		/// <summary>
		/// �޷�������
		/// </summary>
		UInt,
		/// <summary>
		/// 24λ����
		/// </summary>
		Int24,
		/// <summary>
		/// �޷���24λ����
		/// </summary>
		UInt24,
		/// <summary>
		/// 32λ����
		/// </summary>
		Long,
		/// <summary>
		/// �޷���32λ����
		/// </summary>
		ULong,
		/// <summary>
		/// 64λ����
		/// </summary>
		LongLong,
		/// <summary>
		/// �޷���64λ����
		/// </summary>
		ULongLong,
		/// <summary>
		/// 128λ����
		/// </summary>
		Int128,
		/// <summary>
		/// �޷���128λ����
		/// </summary>
		UInt128,
		/// <summary>
		/// 32λ�����ȸ�����
		/// </summary>
		Float,
		/// <summary>
		/// 64λ˫���ȸ�����
		/// </summary>
		Double,
		/// <summary>
		/// 128λ������
		/// </summary>
		LongDouble,
		/// <summary>
		/// ������
		/// </summary>
		Bool,

		/// <summary>
		/// ����
		/// </summary>
		Array,
		/// <summary>
		/// ��
		/// </summary>
		Struct,
		/// <summary>
		/// ָ��ָ��
		/// </summary>
		SmartPtr,
		/// <summary>
		/// ���
		/// </summary>
		Result,
		/// <summary>
		/// ��ѡ��
		/// </summary>
		Optional,
		/// <summary>
		/// ָ��
		/// </summary>
		Ptr,
		/// <summary>
		/// ����
		/// </summary>
		Ref,
		/// <summary>
		/// ����
		/// </summary>
		Modified,


		/// <summary>
		/// ����
		/// </summary>
		Method,
		/// <summary>
		/// ���캯��
		/// </summary>
		Constructor,
		/// <summary>
		/// ö��
		/// </summary>
		Enum,
		/// <summary>
		/// ����
		/// </summary>
		Property,
		/// <summary>
		/// ��Ա����
		/// </summary>
		Field,
		/// <summary>
		/// �����
		/// </summary>
		Operator,
	};

	enum class TypeDetails: UShort
	{
		Value, 
		Pointer,
		Pointer2,
		Pointer3,
		Pointer4,
		Pointer5,
		LValueReference,
		RValueReference,
		Const_Value,
		Const_Pointer,
		Const_Pointer2,
		Const_Pointer3,
		Const_Pointer4,
		Const_Pointer5,
		Const_LValueReference,
		Const_RValueReference,
		Volatile_Value,
		Volatile_Pointer,
		Volatile_Pointer2,
		Volatile_Pointer3,
		Volatile_Pointer4,
		Volatile_Pointer5,
		Volatile_LValueReference,
		Volatile_RValueReference,
		ConstVolatile_Value,
		ConstVolatile_Pointer,
		ConstVolatile_Pointer2,
		ConstVolatile_Pointer3,
		ConstVolatile_Pointer4,
		ConstVolatile_Pointer5,
		ConstVolatile_LValueReference,
		ConstVolatile_RValueReference,

		Invalid
	};

	class Type_impl;
	class NameSpace_impl;
	class NameSpace;

	/// <summary>
	/// ����
	/// </summary>
	class RUNTIME_API Type :public MemberInfo
	{
	private:
		TypeTag _tag;
	protected:
		friend class Type_impl;
		friend class ClassInfo;
		friend class FieldInfo;
		friend class MethodInfo;
		friend class NameSpace_impl;
		friend class NameSpace;


		friend class PtrType;
		friend class RefType;
		friend class ArrayType;
		friend class ModifiedType;
		friend class ResultType;

		/// <summary>
		/// ������Դ
		/// </summary>
		void destroy();

		/// <summary>
		/// ��ϣֵ
		/// </summary>
		Optional<size_t> _hashCode;

		/// <summary>
		/// ���������ռ�
		/// </summary>
		const System::NameSpace* space;

		/// <summary>
		/// ����<see cref="Type"/>ʵ��
		/// </summary>
		/// <param name="tag">���ͱ�ǩ</param>
		Type(TypeTag tag);
	public:
		virtual ~Type();

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <return></return>
		virtual const wchar_t* GetName() const;

		/// <summary>
		/// ��ȡ���ͱ�ǩ
		/// </summary>
		/// <return></return>
		TypeTag GetTag() const;

		/// <summary>
		/// ��ȡ�Ƿ������
		/// </summary>
		/// <return></return>
		bool GetIsObject() const;

		/// <summary>
		/// ��ȡ�Ƿ�����
		/// </summary>
		/// <return></return>
		bool GetIsBuiltin() const;

		/// <summary>
		/// ��ȡ�Ƿ��Ǵ���
		/// </summary>
		/// <return></return>
		bool GetIsScalar() const;

		/// <summary>
		/// ��ȡ�Ƿ��Ǽ���
		/// </summary>
		/// <return></return>
		bool GetIsArray() const;

		/// <summary>
		/// ��ȡ�Ƿ���ָ��
		/// </summary>
		/// <return></return>
		bool GetIsPointer() const;

		/// <summary>
		/// ��ȡ�Ƿ�����
		/// </summary>
		/// <return></return>
		bool GetIsClass() const;

		/// <summary>
		/// ��ȡ�Ƿ��ǹ��캯��
		/// </summary>
		/// <return></return>
		bool GetIsConstructor() const;

		/// <summary>
		/// ��ȡ�Ƿ���ö��
		/// </summary>
		/// <return></return>
		bool GetIsEnum() const;

		/// <summary>
		/// ��ȡ�Ƿ��з���
		/// </summary>
		/// <return></return>
		bool GetIsSigned() const;

		/// <summary>
		/// ��ȡ�Ƿ�����������
		/// </summary>
		/// <return></return>
		bool GetIsReference() const;

		/// <summary>
		/// �ж��Ƿ���ָ������
		/// </summary>
		/// <param name="type">ָ������</param>
		/// <param name="ignoreModifier">�Ƿ�������η�</param>
		/// <return></return>
		bool IsType(_type type, bool ignoreModifier=true) const;

		/// <summary>
		/// �ж��Ƿ�̳���ָ������
		/// </summary>
		/// <param name="info">ָ������</param>
		/// <param name="ignoreModifier">�Ƿ�������η�</param>
		/// <returns></returns>
		bool IsBaseOf(_type info, bool ignoreModifier = true)const;

		/// <summary>
		/// �ж��Ƿ�̳���ָ�����ͻ���ָ������
		/// </summary>
		/// <param name="info">ָ������</param>
		/// <param name="ignoreModifier">�Ƿ�������η�</param>
		/// <returns></returns>
		bool IsBaseOfOrSameAs(_type info, bool ignoreModifier = true)const;

		/// <summary>
		/// �ж��Ƿ����ָ������ת��
		/// </summary>
		/// <param name="type">ָ������</param>
		/// <return></return>
		bool IsConvertible(_type type)const;

		/// <summary>
		/// ��ȡ�Ƿ��Ǵ���
		/// </summary>
		/// <return></return>
		size_t GetHashCode() const;

		/// <summary>
		/// �ж��Ƿ����ַ���
		/// </summary>
		/// <param name="iswiden">�Ƿ��ǿ��ַ�</param>
		/// <param name="ignoreModifier">�Ƿ�������η�</param>
		/// <return></return>
		bool GetIsRawString(bool& iswiden, bool ignoreModifier = true) const;

		/// <summary>
		/// �ж��Ƿ��Ǳ�׼���ַ���
		/// </summary>
		/// <param name="iswiden">�Ƿ��ǿ��ַ�</param>
		/// <param name="ignoreModifier">�Ƿ�������η�</param>
		/// <return></return>
		bool GetIsSTDString(bool& iswiden, bool ignoreModifier = true) const;

		/// <summary>
		/// �ж��Ƿ����ַ������׼���ַ���
		/// </summary>
		/// <param name="iswiden">�Ƿ��ǿ��ַ�</param>
		/// <param name="ignoreModifier">�Ƿ�������η�</param>
		/// <return></return>
		bool GetIsRawOrSTDString(bool& iswiden, bool& israw, bool ignoreModifier = true) const;

		/// <summary>
		/// �ж��Ƿ����ַ���
		/// </summary>
		/// <param name="ignoreModifier">�Ƿ�������η�</param>
		/// <return></return>
		bool DirectGetIsRawString(bool ignoreModifier = true) const;

		/// <summary>
		/// �ж��Ƿ��Ǳ�׼���ַ���
		/// </summary>
		/// <param name="ignoreModifier">�Ƿ�������η�</param>
		/// <return></return>
		bool DirectGetIsSTDString(bool ignoreModifier = true) const;

		/// <summary>
		/// �ж��Ƿ����ַ������׼���ַ���
		/// </summary>
		/// <param name="ignoreModifier">�Ƿ�������η�</param>
		/// <return></return>
		bool DirectGetIsRawOrSTDString(bool ignoreModifier = true) const;

		/// <summary>
		/// ��ȡ���������ռ�
		/// </summary>
		/// <return></return>
		const System::NameSpace* GetNameSpace() const;

		/// <summary>
		/// ��ȡ��������
		/// </summary>
		/// <return></return>
		const System::Assembly* GetAssembly() const;

		/// <summary>
		/// ��ȡ��ע�����������
		/// </summary>
		/// <return></return>
		static UInt64 GetCount();

		/// <summary>
		/// ��ȡ������ϸ����
		/// </summary>
		/// <return></return>
		TypeDetails GetDetail() const;

		/// <summary>
		/// ���������ռ�
		/// </summary>
		_declspec(property(get = GetNameSpace)) const System::NameSpace* NameSpace;

		/// <summary>
		/// ��������
		/// </summary>
		_declspec(property(get = GetAssembly)) const System::Assembly* Assembly;

		/// <summary>
		/// ���ͱ�ǩ
		/// </summary>
		_declspec(property(get = GetTag)) TypeTag Tag;

		/// <summary>
		/// ����
		/// </summary>
		_declspec(property(get = GetName)) const wchar_t* Name;

		/// <summary>
		/// �Ƿ�����
		/// </summary>
		_declspec(property(get = GetIsBuiltin)) bool IsBuiltin;

		/// <summary>
		/// �Ƿ��з���
		/// </summary>
		_declspec(property(get = GetIsSigned)) bool IsSigned;

		/// <summary>
		/// �Ƿ������
		/// </summary>
		_declspec(property(get = GetIsObject)) bool IsObject;

		/// <summary>
		/// �Ƿ��Ǵ���
		/// </summary>
		_declspec(property(get = GetIsScalar)) bool IsScalar;

		/// <summary>
		/// �Ƿ��Ǽ���
		/// </summary>
		_declspec(property(get = GetIsArray)) bool IsArray;

		/// <summary>
		/// �Ƿ���ָ��
		/// </summary>
		_declspec(property(get = GetIsPointer)) bool IsPointer;

		/// <summary>
		/// �Ƿ�������
		/// </summary>
		_declspec(property(get = GetIsReference)) bool IsReference;

		/// <summary>
		/// �Ƿ�����
		/// </summary>
		_declspec(property(get = GetIsClass)) bool IsClass;

		/// <summary>
		/// �Ƿ��ǹ��캯��
		/// </summary>
		_declspec(property(get = GetIsConstructor)) bool IsConstructor;

		/// <summary>
		/// �Ƿ���ö��
		/// </summary>
		_declspec(property(get = GetIsEnum)) bool IsEnum;

		/// <summary>
		/// ������ϸ����
		/// </summary>
		_declspec(property(get = GetDetail)) TypeDetails Detail;

		/// <summary>
		/// ��ϣֵ
		/// </summary>
		_declspec(property(get = GetHashCode)) size_t HashCode;

		/// <summary>
		/// δ֪����
		/// </summary>
		static Type* const unknownType;

		/// <summary>
		/// �������
		/// </summary>
		static Type* const objectType;

		/// <summary>
		/// �κ�����
		/// </summary>
		static Type* const anyType;

		/// <summary>
		/// �������ͣ��κΣ�
		/// </summary>
		static Type* const variadicAnyType;
		
		/// <summary>
		/// ��ʵ������ı䳤���ϣ��κΣ�
		/// </summary>
		static Type* const realVariadicAnyType;

		/// <summary>
		/// ��Ĭ�ϵı䳤���ϣ��κΣ�
		/// </summary>
		static Type* const defaultVariadicAnyType;

		/// <summary>
		/// ��ѡ�ı䳤���ϣ��κΣ�
		/// </summary>
		static Type* const optionalVariadicAnyType;

		/// <summary>
		/// ��ȫ��ָ������
		/// </summary>
		static Type* const safeVoidPtrType;

		/// <summary>
		/// �����ַ�������
		/// </summary>
		static Type* const inertiaStringType;

		/// <summary>
		/// ��������
		/// </summary>
		static Type* const boolType;

		/// <summary>
		/// ������
		/// </summary>
		static Type* const voidType;

		/// <summary>
		/// �ַ����ͣ�խ��
		/// </summary>
		static Type* const charType;

		/// <summary>
		/// �޷����ַ����ͣ�խ��
		/// </summary>
		static Type* const ucharType;

		/// <summary>
		/// �ַ����ͣ���
		/// </summary>
		static Type* const wcharType;

		/// <summary>
		/// 16λ��������
		/// </summary>
		static Type* const shortType;

		/// <summary>
		/// �޷���16λ��������
		/// </summary>
		static Type* const UShortType;

		/// <summary>
		/// ��������
		/// </summary>
		static Type* const intType;

		/// <summary>
		/// �޷�����������
		/// </summary>
		static Type* const UIntType;

		/// <summary>
		/// 24λ��������
		/// </summary>
		static Type* const Int24Type;

		/// <summary>
		/// �޷���24λ��������
		/// </summary>
		static Type* const UInt24Type;

		/// <summary>
		/// 32λ��������
		/// </summary>
		static Type* const longType;

		/// <summary>
		/// �޷���32λ��������
		/// </summary>
		static Type* const ULongType;

		/// <summary>
		/// 64λ��������
		/// </summary>
		static Type* const longlongType;

		/// <summary>
		/// �޷���64λ��������
		/// </summary>
		static Type* const ULonglongType;		

		/// <summary>
		/// 128λ��������
		/// </summary>
		static Type* const Int128Type;

		/// <summary>
		/// �޷���128λ��������
		/// </summary>
		static Type* const UInt128Type;

		/// <summary>
		/// 32λ�����ȸ���������
		/// </summary>
		static Type* const floatType;

		/// <summary>
		/// 64λ˫���ȸ���������
		/// </summary>
		static Type* const doubleType;

		/// <summary>
		/// 128λ����������
		/// </summary>
		static Type* const longdoubleType;
	};

	/// <summary>
	/// ��׼�����ͼ���
	/// </summary>
	class RUNTIME_API STDTypes
	{
	public:
		/// <summary>
		/// �ַ�����խ��
		/// </summary>
		static _type stringType;
		/// <summary>
		/// �ַ�������
		/// </summary>
		static _type wstringType;
	};

	/// <summary>
	/// �������ͼ���
	/// </summary>
	class RUNTIME_API BUILTINTypes
	{
	public:
		/// <summary>
		/// ��������Ϣ����
		/// </summary>
		static _type cultureInfoType;
	};


	/// <summary>
	/// ���ͼ���
	/// </summary>
	typedef DynamicArray<_type> TypeCollection;

}