#pragma once
#include "Type.h"
#include "Any.h"
namespace System
{
	class Object;
	class PropertyInfo_impl;
	class ClassInfo;
	class EnumInfo;
	class PropertyType;

	ENUM_FLAGS(PropertyFlags)
	/// <summary>
	/// ���Ա�ʶ
	/// </summary>
	enum class PropertyFlags
	{
		/// <summary>
		/// ��̬
		/// </summary>
		Static = 0x0001,
		/// <summary>
		/// ����
		/// </summary>
		Public = 0x002,
		/// <summary>
		/// ����
		/// </summary>
		Protected = 0x004,
		/// <summary>
		/// ˽��
		/// </summary>
		Private = 0x0010,
		/// <summary>
		/// Ĭ��
		/// </summary>
		Default = Public
	};

	/// <summary>
	/// ��������
	/// </summary>
	enum class PropertyPolicy
	{
		/// <summary>
		/// ����
		/// </summary>
		All,
		/// <summary>
		/// ֻ��
		/// </summary>
		ReadOnly,
		/// <summary>
		/// ֻд
		/// </summary>
		WriteOnly
	};

	/// <summary>
	/// ������Ϣ��
	/// </summary>
	 class RUNTIME_API PropertyInfo final: public MemberInfo
	{
	private:
		friend class PropertyInfo_impl;
		PropertyInfo_impl* impl;
		friend class ClassInfo;
		friend class EnumInfo;
		PropertyInfo(const wchar_t* name, PropertyFlags flags, PropertyType* type);

	public:

		~PropertyInfo();

		bool operator ==(const PropertyInfo& info) const;
		bool operator !=(const PropertyInfo& info) const;

		/// <summary>
		/// ��ȡ����
		/// </summary>
		///<return></return>
		const wchar_t* GetName() const;

		/// <summary>
		/// ��ȡ��������
		/// </summary>
		///<return></return>
		const PropertyType* GetType() const;

		/// <summary>
		/// ��ȡ���Ա�ʶ
		/// </summary>
		///<return></return>
		PropertyFlags GetFlags() const;

		/// <summary>
		/// ��ȡ��������
		/// </summary>
		///<return></return>
		PropertyPolicy GetPolicy() const;

		/// <summary>
		/// ����
		/// </summary>
		__declspec(property(get = GetName)) const wchar_t* Name;

		/// <summary>
		/// ���Ա�ʶ
		/// </summary>
		_declspec(property(get = GetFlags)) PropertyFlags Flags;

		/// <summary>
		/// ��������
		/// </summary>
		_declspec(property(get = GetType)) const PropertyType* Type;

		/// <summary>
		/// ��������
		/// </summary>
		_declspec(property(get = GetPolicy)) PropertyPolicy Policy;

		/// <summary>
		/// ��ȡ����ֵ
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		Any Get(Object* obj, bool nothrow = true) const;

		/// <summary>
		/// ��������ֵ
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="value">ֵ</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		bool Set(Object* obj, const Any& value, bool nothrow = true) const;

		/// <summary>
		/// ��ȡ����ֵ
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		Any Get(const Object* obj, bool nothrow = true) const;

		/// <summary>
		/// ��������ֵ
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="value">ֵ</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		bool Set(const Object* obj, const Any& value, bool nothrow = true) const;

		/// <summary>
		/// ��ȡ����ֵ
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		Any Get(nullptr_t obj, bool nothrow = true) const;

		/// <summary>
		/// ��������ֵ
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="value">ֵ</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		bool Set(nullptr_t obj, const Any& value, bool nothrow = true) const;
	};
}