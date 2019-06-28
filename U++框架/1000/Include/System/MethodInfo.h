#pragma once 
#include "Type.h"
#include "DefaultVariadicAny.h"
#include "OptionalVariadicAny.h"
#include <memory>

namespace System
{		
	class Object;

	class EnumInfo;
	class ClassInfo;
	class MethodType;
	class MethodInfo_impl;

	ENUM_FLAGS(MethodFlags)
	/// <summary>
	/// ������ʶ
	/// </summary>
	enum class MethodFlags
	{
		/// <summary>
		/// ��̬
		/// </summary>
		Static = 0x0001,

		/// <summary>
		/// ����
		/// </summary>
		Const = 0x0002,

		/// <summary>
		/// ����
		/// </summary>
		Public = 0x0004,

		/// <summary>
		/// ����
		/// </summary>
		Protected = 0x0010,

		/// <summary>
		/// ˽��
		/// </summary>
		Private = 0x0020,

		/// <summary>
		/// ����
		/// </summary>
		Virtual = 0x0040,

		/// <summary>
		/// Ĭ��
		/// </summary>
		Default = Public
	};

	/// <summary>
	/// ������Ϣ��
	/// </summary>
	class RUNTIME_API MethodInfo final: public MemberInfo
	{
	private:
		friend class MethodInfo_impl;
		MethodInfo_impl* impl;
		friend class ClassInfo;
		friend class EnumInfo;
		MethodInfo(const wchar_t* name, MethodFlags flags, MethodType* type, SharedDefaultVariadicAny defaultParams = nullptr);

	public:

		/// <summary>
		/// ��ȡ����
		/// </summary>
		///<return></return>
		const wchar_t* GetName() const;

		/// <summary>
		/// ��ȡ��������
		/// </summary>
		///<return></return>
		const MethodType* GetType() const;

		/// <summary>
		/// ��ȡ������ʶ
		/// </summary>
		///<return></return>
		const MethodFlags GetFlags() const;

		/// <summary>
		/// ����ָ������ĵ�ǰ����
		/// </summary>
		/// <param name="result">���</param>
		/// <param name="obj">ָ������</param>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		bool Invoke(Any* result, Object* obj, const OptionalVariadicAny& params, bool nothrow = true) const;

		/// <summary>
		/// ����ָ������ĵ�ǰ����
		/// </summary>
		/// <param name="result">���</param>
		/// <param name="obj">ָ������</param>
		/// <param name="parameters">����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		bool Invoke(Any* result, const Object* obj, const OptionalVariadicAny& parameters, bool nothrow = true) const;

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
		/// ��ȡ��������
		/// </summary>
		///<return></return>
		_type GetDeclaringClass() const;

		/// <summary>
		/// ����
		/// </summary>
		__declspec(property(get = GetName)) const wchar_t* Name;

		/// <summary>
		/// ��������
		/// </summary>
		__declspec(property(get = GetType)) const MethodType* Type;

		/// <summary>
		/// ������ʶ
		/// </summary>
		__declspec(property(get = GetFlags)) MethodFlags Flags;

		/// <summary>
		/// ��������
		/// </summary>
		__declspec(property(get = GetDeclaringClass)) const System::Type* DeclaringClass;

		~MethodInfo();

		bool operator ==(const MethodInfo& info) const;
		bool operator !=(const MethodInfo& info) const;

	};

}