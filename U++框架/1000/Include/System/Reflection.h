#pragma once

#include <vector>
#include "TypeList.h"
#include "EnumInfo.h"
#include "ConstructorTypeList.h"
#include "MethodTypeList.h"
#include "FunctionTypeList.h"
#include "PropertyTypeList.h"
#include "OperatorTypeList.h"
#include "FieldTypeList.h"
#include "Assembly.h"
#include "NameSpace.h"
#include "TypeCaches.h"

namespace System
{
	/// <summary>
	/// ��������ö��
	/// </summary>
	enum class FactoryError
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
		/// δ֪
		/// </summary>
		Unknown,
		/// <summary>
		/// ��Ч����
		/// </summary>
		InvalidAssembly,
		/// <summary>
		/// �ճ���
		/// </summary>
		EmptyAssembly,
		/// <summary>
		/// �Ѵ���
		/// </summary>
		AlreadyExist,
		/// <summary>
		/// ������
		/// </summary>
		Nonexistent,
		/// <summary>
		/// ��֧��
		/// </summary>
		UnSupported,
		/// <summary>
		/// ��֧�ֵ��ܳ�
		/// </summary>
		UnSupportedKey,
		/// <summary>
		/// ��ռ��
		/// </summary>
		Locked,
	};

	/// <summary>
	/// ������̬���ӿ����ö��
	/// </summary>
	enum class FactoryDllError
	{
		/// <summary>
		/// �ɹ�
		/// </summary>
		OK = 0,
		/// <summary>
		/// �ɹ�
		/// </summary>
		None = 0,

		/// <summary>
		/// δ�ҵ��ļ�
		/// </summary>
		FileNotFound,
		/// <summary>
		/// ����ʧ��
		/// </summary>
		DllLoadFailed,
		/// <summary>
		/// ����ʧ��
		/// </summary>
		DllFreeFailed,
		/// <summary>
		/// ���򼯳�ʼ��ʧ��
		/// </summary>
		DllInitFailed,
		/// <summary>
		/// ж�س���ʧ��
		/// </summary>
		DllExitFailed,
		/// <summary>
		/// δ�ҵ���ڵ�
		/// </summary>
		EntryNotFound,
		/// <summary>
		/// �ռ���ж�غ���
		/// </summary>
		InitExitEmpty,
		/// <summary>
		/// ������ж��
		/// </summary>
		IncompleteUninstall,
		/// <summary>
		/// ����ʧ�ܻع��ڼ�δ�ҵ���Чж�غ���
		/// </summary>
		ExitNotFoundDuringInitFailed,
		/// <summary>
		/// ����ʧ�ܻع��ڼ�ж�س���ʧ��
		/// </summary>
		DllExitFailedDuringInitFailed,
		/// <summary>
		/// δ֪
		/// </summary>
		Unknown
	};

	/// <summary>
	/// ���̰�����
	/// </summary>
	struct FactoryHelper
	{
		/// <summary>
		/// ע��ģ��
		/// </summary>
		/// <param name="nativeModule">ָ��ģ��</param>
		/// <returns></returns>
		Result<FactoryError, safe_void_ptr>(*RegisiterModule)(void* nativeModule);

		/// <summary>
		/// ���ӳ��򼯺���
		/// </summary>
		/// <param name="module">ָ��ģ��</param>
		/// <param name="assembly">ָ������</param>
		/// <param name="privateKey">˽��</param>
		/// <param name="privateKeySize">˽�׳���</param>
		/// <returns></returns>
		FactoryError(*AddAssembly)(const safe_void_ptr& module, Assembly* assembly, char* privateKey, unsigned int privateKeySize);

		/// <summary>
		/// �Ƴ�ָ������
		/// </summary>
		/// <param name="module">ָ��ģ��</param>
		/// <param name="assembly">ָ������</param>
		/// <param name="privateKey">˽��</param>
		/// <param name="privateKeySize">˽�׳���</param>
		/// <returns></returns>
		FactoryError(*RemoveAssembly)(const safe_void_ptr& mod, Assembly*& assembly, char* privateKey, unsigned int privateKeySize);


		/// <summary>
		/// ���ҳ��򼯺���
		/// </summary>
		/// <param name="name">ָ������</param>
		/// <param name="ver">ָ���汾��</param>
		/// <param name="publicKey">����</param>
		/// <param name="privateKey">˽��</param>
		/// <param name="privateKeySize">˽�׳���</param>
		/// <returns></returns>
		const Assembly*(*FindAssembly)(const wchar_t* name, System::Version ver, uGUID publicKey, char* privateKey, unsigned int privateKeySize);

	};
}

#ifdef REFLECTION_SUPPORT
#define REFLECTION_API  __declspec(dllexport)
#else
#define REFLECTION_API  __declspec(dllimport)
#endif

#define i_CONCAT(a, b) (a ## b)
#define CONCAT(a, b) i_CONCAT(a, b)

#define i_CONCATNAME(a, b) a ## b
#define CONCATNAME(a, b) i_CONCATNAME(a, b)

#define i__uref_CLASS(T, num) \
private:\
static void DefineMeta(ClassInfo&);\
template<class T>\
friend void ClassInfo::Create(System::Type const*& pointer, const wchar_t* name, unsigned int size, System::ClassFlags flags);\
public:\
_type GetType() const override;


#define REFLECT_CLASS(T)\
	public:\
	i__uref_CLASS(T, __COUNTER__)

#define __uweakvalue  _declspec(USTR(uvalue))

#define __uvalue_begin(T, TYPE)\
public:\
typedef  std::conditional<std::is_integral<TYPE>::value, TYPE, uhash>::type enumbase;\
private:\
enumbase value; \
static void DefineMeta(EnumInfo&);\
template<class T, typename BASE>\
friend typename std::enable_if<std::is_integral<BASE>::value, void>::type EnumInfo::Create(System::Type const*& pointer, const wchar_t* name);\
protected:\
	std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;\
public:\
	_type GetType() const override;\
	~T() {}\
	constexpr T(const enumbase& val) : value(val) {}\
	T(const T& t);\
	T(T&& t);\
	T& operator=(const enumbase& val);\
	T& operator=(const T& t);\
	operator enumbase() const;\
	uhash GetHashCode() const override;\
	bool Equals(const Object* ref) const override;\
	enum __uweakvalue __uweakenums: T::enumbase {


#define __uvalue_end(T, DEFAULT)\
	};\
public:\
	constexpr T() : value(static_cast<enumbase>(DEFAULT)) {}



#define __enum_operator(T)\
inline T	operator	&	(const T& x, const T& y) { return static_cast<T>	(static_cast<std::underlying_type<T>::type>(x) & static_cast<std::underlying_type<T>::type>>(y)); } \
inline T	operator	|	(const T& x, const T& y) { return static_cast<T>	(static_cast<std::underlying_type<T>::type>>(x) | static_cast<std::underlying_type<T>::type>>(y)); } \
inline T	operator	^	(const T& x, const T& y) { return static_cast<T>	(static_cast<std::underlying_type<T>::type>>(x) ^ static_cast<std::underlying_type<T>::type>>(y)); } \
inline T	operator	~	(const T& x) { return static_cast<T>	(~static_cast<std::underlying_type<T>::type>>(x)); }\
inline T&	operator	&=	(T& x, const T& y) { x = x & y;	return x; }\
inline T&	operator	|=	(T& x, const T& y) { x = x | y;	return x; } \
inline T&	operator	^=	(T& x, const T& y) { x = x ^ y;	return x; } \


#define __uenum_operator(T)\
inline T	operator	&	(const T& x, const T& y) { return static_cast<T>	(static_cast<T::enumbase>(x) & static_cast<T::enumbase>(y)); } \
inline T	operator	|	(const T& x, const T& y) { return static_cast<T>	(static_cast<T::enumbase>(x) | static_cast<T::enumbase>(y)); } \
inline T	operator	^	(const T& x, const T& y) { return static_cast<T>	(static_cast<T::enumbase>(x) ^ static_cast<T::enumbase>(y)); } \
inline T	operator	~	(const T& x) { return static_cast<T>	(~static_cast<T::enumbase>(x)); }\
inline T&	operator	&=	(T& x, const T& y) { x = x & y;	return x; }\
inline T&	operator	|=	(T& x, const T& y) { x = x | y;	return x; } \
inline T&	operator	^=	(T& x, const T& y) { x = x ^ y;	return x; } \
inline T	operator	&	(const T& x, const T::enumbase& y) { return static_cast<T>	(static_cast<T::enumbase>(x) & y); } \
inline T	operator	|	(const T& x, const T::enumbase& y) { return static_cast<T>	(static_cast<T::enumbase>(x) | y); } \
inline T	operator	^	(const T& x, const T::enumbase& y) { return static_cast<T>	(static_cast<T::enumbase>(x) ^ y); } \
inline T&	operator	&=	(T& x, const T::enumbase& y) { x = x & y;	return x; }\
inline T&	operator	|=	(T& x, const T::enumbase& y) { x = x | y;	return x; } \
inline T&	operator	^=	(T& x, const T::enumbase& y) { x = x ^ y;	return x; } \

template<typename T>
struct is__uenum_flag_support
{
	static const bool value = is_same_or_base_of<bool, T>::value || is_same_or_base_of<char, T>::value || is_same_or_base_of<UChar, T>::value || is_same_or_base_of<short, T>::value || is_same_or_base_of<UShort, T>::value || is_same_or_base_of<int, T>::value || is_same_or_base_of<UInt, T>::value || is_same_or_base_of<long, T>::value || is_same_or_base_of<ULong, T>::value || is_same_or_base_of<Int64, T>::value || is_same_or_base_of<UInt64, T>::value;
};

#define __uenum_flag(T)\
	__uenum_operator(T)\
	static_assert(is__uenum_flag_support<T::enumbase>::value, "T must be based on interger");\
namespace Enums{ inline bool Contains(const T& x, const T& testFlag) { return static_cast<T::enumbase>(x & testFlag) != static_cast<T::enumbase>(testFlag); };}

#define __enum_flag(T)\
	__enum_operator(T)\
	static_assert(std::is_enum<T>::value, "T must be enum");\
namespace Enums{ inline bool Contains(const T& x, const T& testFlag) { return static_cast<std::underlying_type<T>::type>(x & testFlag) != static_cast<std::underlying_type<T>::type>(testFlag); };}


#define i2__uref_register(REG,...)\
static struct REG{\
	REG() { __VA_ARGS__ } \
}CONCATNAME(U_PREMAIN_ENTRY, __COUNTER__);

#define i__uref_register_class(T, num, flags)\
	static _type CONCATNAME(GLOBAL_UMETA_, num);\
	_type T::GetType() const { return CONCATNAME(GLOBAL_UMETA_, num);}\
	template<> \
	REFLECTION_API _type TypeHelper<T>::GetType() { ClassInfo::Create<T>(CONCATNAME(GLOBAL_UMETA_, num), L## #T, sizeof(T), flags); return CONCATNAME(GLOBAL_UMETA_, num);  }\
	i2__uref_register(CONCATNAME(CONCATNAME(REFLECT_PREMAIN_CLASS, T), __COUNTER__), ClassInfo::Create<T>(CONCATNAME(GLOBAL_UMETA_, num), L## #T, sizeof(T), flags);)\
	void T::DefineMeta(ClassInfo& type)

#define i__uref_register_class1(T, T1, num, flags)\
	static _type CONCATNAME(GLOBAL_UMETA_, num);\
	_type T::GetType() const { return CONCATNAME(GLOBAL_UMETA_, num);}\
	template<> \
	REFLECTION_API _type TypeHelper<T>::GetType() { ClassInfo::Create<T>(CONCATNAME(GLOBAL_UMETA_, num), L## #T, sizeof(T), flags); return CONCATNAME(GLOBAL_UMETA_, num);  }\
	i2__uref_register(CONCATNAME(CONCATNAME(REFLECT_PREMAIN_CLASS, T1), __COUNTER__), ClassInfo::Create<T>(CONCATNAME(GLOBAL_UMETA_, num), L## #T, sizeof(T), flags);)\
	void T::DefineMeta(ClassInfo& type)

#define __uregister_class(T, flags)   i__uref_register_class(T, __COUNTER__, flags)
#define __uregister_class1(T, T1, flags)   i__uref_register_class1(T, T1, __COUNTER__, flags)

#define i__uref_register_enum(T, num)\
	static _type CONCATNAME(GLOBAL_UMETA_, num);\
	std::wstring T::CustomToString(const wchar_t* fmt, const CultureInfo& loc) const{std::wstring result; if (EnumInfo::TryGetValueName(_typeof(T), *const_cast<enumbase*>(&value), result)) return result; return std::wstring();}\
	_type T::GetType() const { return CONCATNAME(GLOBAL_UMETA_, num);}\
	T::T(const T& t): value(t.value) {}\
	T::T(T&& t): value(t.value) {}\
	T& T::operator=(const T::enumbase& val) { this->value = val; return *this; }\
	T& T::operator=(const T& t) { this->value = t.value; return *this;}\
	T::operator T::enumbase() const { return this->value; }\
	uhash T::GetHashCode() const { uhash code=0; EnumInfo::TryGetHashCode(_typeof(T), *const_cast<enumbase*>(&value), code); return code; }\
	bool T::Equals(const Object* ref) const{\
		if (!ref) return false;\
		if (ref == this) return true;\
		try{\
	    const T* realT = dynamic_cast<const T*>(ref); \
		if (realT) return realT->value == value;\
		return false;}catch (...){return false;}}\
	template<> \
	REFLECTION_API _type TypeHelper<T>::GetType() { EnumInfo::Create<T, T::enumbase>(CONCATNAME(GLOBAL_UMETA_, num), L## #T); return CONCATNAME(GLOBAL_UMETA_, num); }\
	i2__uref_register(CONCATNAME(CONCATNAME(XAUL_PREMAIN_ENUM, T), __COUNTER__), EnumInfo::Create<T, T::enumbase>(CONCATNAME(GLOBAL_UMETA_, num), L## #T);)\
	void T::DefineMeta(EnumInfo& type)

#define i__uref_register_enum1(T, T1, num)\
	static _type CONCATNAME(GLOBAL_UMETA_, num);\
	std::wstring T::CustomToString(const wchar_t* fmt, const CultureInfo& loc) const{std::wstring result; if (EnumInfo::TryGetValueName(_typeof(T), *const_cast<enumbase*>(&value), result)) return result; return std::wstring();}\
	_type T::GetType() const { return CONCATNAME(GLOBAL_UMETA_, num);}\
	T::T1(const T& t): value(t.value) {}\
	T::T1(T&& t): value(t.value) {}\
	T& T::operator=(const T::enumbase& val) { this->value = val; return *this; }\
	T& T::operator=(const T& t) { this->value = t.value; return *this;}\
	T::operator T::enumbase() const { return this->value; }\
	uhash T::GetHashCode() const { uhash code=0; EnumInfo::TryGetHashCode(_typeof(T), *const_cast<enumbase*>(&value), code); return code; }\
	bool T::Equals(const Object* ref) const{\
		if (!ref) return false;\
		if (ref == this) return true;\
		try{\
	    const T* realT = dynamic_cast<const T*>(ref); \
		if (realT) return realT->value == value;\
		return false;}catch (...){return false;}}\
	template<> \
	REFLECTION_API _type TypeHelper<T>::GetType() { EnumInfo::Create<T, T::enumbase>(CONCATNAME(GLOBAL_UMETA_, num), L## #T); return CONCATNAME(GLOBAL_UMETA_, num); }\
	i2__uref_register(CONCATNAME(CONCATNAME(XAUL_PREMAIN_ENUM, T1), __COUNTER__), EnumInfo::Create<T, T::enumbase>(CONCATNAME(GLOBAL_UMETA_, num), L## #T);)\
	void T::DefineMeta(EnumInfo& type)


#define __uregister_enum(T)   i__uref_register_enum(T, __COUNTER__)
#define __uregister_enum1(T, T1)   i__uref_register_enum1(T, T1, __COUNTER__)
