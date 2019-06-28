#pragma once 
#include "Type.h"
#include "DefaultVariadicAny.h"
#include "OptionalVariadicAny.h"
#include <memory>

namespace System
{
	class Object;

	class ClassInfo;
	class EnumInfo;
	class ConstructorType;
	class ConstructorInfo_impl;


	ENUM_FLAGS(ConstructorFlags)
	/// <summary>
	/// Enum ���캯����ʶ
	/// </summary>
	enum class ConstructorFlags
	{
		/// <summary>
		/// ����
		/// </summary>
		Public = 0x0001,
		/// <summary>
		/// ����
		/// </summary>
		Protected = 0x0002,
		/// <summary>
		/// ˽��
		/// </summary>
		Private = 0x0004,
		/// <summary>
		/// ����
		/// </summary>
		Virtual = 0x0010,
		/// <summary>
		/// Ĭ��
		/// </summary>
		Default = Public
	};

	/// <summary>
	/// ���캯����Ϣ
	/// </summary>
	class RUNTIME_API ConstructorInfo final: public MemberInfo
	{
	private:
		friend class ConstructorInfo_impl;
		ConstructorInfo_impl* impl;
		friend class ClassInfo;
		friend class EnumInfo;
		ConstructorInfo(const wchar_t* name, ConstructorFlags flags, ConstructorType* type, SharedDefaultVariadicAny defaultParams = nullptr);

	public:

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		const wchar_t* GetName() const;

		/// <summary>
		/// ��ȡ��������
		/// </summary>
		/// <returns></returns>
		const ConstructorType* GetType() const;

		/// <summary>
		/// ��ȡ���캯����ʶ
		/// </summary>
		/// <returns></returns>
		const ConstructorFlags GetFlags() const;

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		Object* Invoke(bool nothrow = true) const;

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		Object* Invoke(const OptionalVariadicAny& parameters, bool nothrow = true) const;

		/// <summary>
		/// ��ȡ���캯��������
		/// </summary>
		/// <returns></returns>
		_type GetDeclaringClass() const;

		/// <summary>
		/// ��ȡ���캯���Ƿ��в���
		/// </summary>
		/// <returns></returns>
		bool GetHasParameters() const;

		/// <summary>
		/// ����
		/// </summary>
		__declspec(property(get = GetName)) const wchar_t* Name;
		/// <summary>
		/// ���캯������
		/// </summary>
		__declspec(property(get = GetType)) const ConstructorType* Type;
		/// <summary>
		/// ���캯����ʶ
		/// </summary>
		__declspec(property(get = GetFlags)) ConstructorFlags Flags;
		/// <summary>
		/// ���캯��������
		/// </summary>
		__declspec(property(get = GetDeclaringClass)) const System::Type* DeclaringClass;
		/// <summary>
		/// ��ȡ���캯���Ƿ��в���
		/// </summary>
		__declspec(property(get = GetHasParameters)) bool HasParameters;

		~ConstructorInfo();

		bool operator ==(const ConstructorInfo& info) const;
		bool operator !=(const ConstructorInfo& info) const;
	};
}