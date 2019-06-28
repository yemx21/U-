#pragma once 
#include "Type.h"
#include "Any.h"
namespace System
{
	class Object;

	ENUM_FLAGS(FieldFlags)
	/// <summary>
	/// ��Ա������ʶ
	/// </summary>
	enum class FieldFlags
	{
		/// <summary>
		/// ʵ��
		/// </summary>
		Instance = 0x0001,

		/// <summary>
		/// ��̬
		/// </summary>
		Static = 0x0002,

		/// <summary>
		/// ����
		/// </summary>
		Const = 0x0004,

		/// <summary>
		/// ����
		/// </summary>
		Public = 0x0010,

		/// <summary>
		/// ����
		/// </summary>
		Protected = 0x0020,

		/// <summary>
		/// ˽��
		/// </summary>
		Private = 0x0040,

		/// <summary>
		/// �ױ�ģ��̣߳�
		/// </summary>
		Volatile = 0x0100,

		/// <summary>
		/// �ױ�ģ�ʵ����
		/// </summary>
		Mutable = 0x0200,

		/// <summary>
		/// Ĭ��
		/// </summary>
		Default = Instance
	};

	/// <summary>
	/// ��Ա��������ö��
	/// </summary>
	enum class FieldPolicy
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

	class FieldType;
	class FieldInfo_impl;

	/// <summary>
	/// ��Ա������Ϣ��
	/// </summary>
	class RUNTIME_API FieldInfo final: public MemberInfo
	{
	private:
		friend class FieldInfo_impl;
		FieldInfo_impl* impl;
		friend class ClassInfo;
		friend class EnumInfo;
		FieldInfo(const wchar_t* name, FieldFlags flags, FieldType* type);

	public:
		/// <summary>
		/// ��ȡ����
		/// </summary>
		///<return></return>
		const wchar_t* GetName() const;

		/// <summary>
		/// ��ָ�������ȡ�ó�Ա������ֵ
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		///<return></return>
		Any Get(const Object* obj, bool nothrow = true) const;

		/// <summary>
		/// ����ָ������ó�Ա������ֵ
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="value">ָ��ֵ</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		///<return></return>
		bool Set(Object* obj, const Any& value, bool nothrow = true) const;

		/// <summary>
		/// ��ȡ��Ա��������
		/// </summary>
		///<return></return>
		const FieldType* GetType()const;

		/// <summary>
		/// ��ȡ��Ա������ʶ
		/// </summary>
		///<return></return>
		FieldFlags GetFlags() const;

		/// <summary>
		/// ��ȡ��Ա��������
		/// </summary>
		///<return></return>
		FieldPolicy GetPolicy() const;

		~FieldInfo();

		/// <summary>
		/// ����
		/// </summary>
		__declspec(property(get = GetName)) const wchar_t* Name;

		/// <summary>
		/// ��Ա��������
		/// </summary>
		_declspec(property(get = GetFlags)) FieldFlags Flags;

		/// <summary>
		/// ��Ա������ʶ
		/// </summary>
		_declspec(property(get = GetType)) const FieldType* Type;

		/// <summary>
		/// ��Ա��������
		/// </summary>
		_declspec(property(get = GetPolicy)) FieldPolicy Policy;

		bool operator ==(const FieldInfo& info) const;
		bool operator !=(const FieldInfo& info) const;
	};
}