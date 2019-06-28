#pragma once
#include "FieldInfo.h"
namespace System
{
	/// <summary>
	/// ��Ա��������ö��
	/// </summary>
	enum class FieldKinds
	{
		/// <summary>
		/// ��
		/// </summary>
		Read,
		/// <summary>
		/// д
		/// </summary>
		Write,
		/// <summary>
		/// ��д
		/// </summary>
		ReadWrite,
		/// <summary>
		/// ������̬��
		/// </summary>
		StaticRead,
		/// <summary>
		/// д����̬��
		/// </summary>
		StaticWrite,
		/// <summary>
		/// ��д����̬��
		/// </summary>
		StaticReadWrite,
	};

	/// <summary>
	/// ��Ա����������
	/// </summary>
	class RUNTIME_API FieldType : public Type
	{
	protected:
		friend class FieldInfo_impl;
		friend class ClassInfo;
		friend class EnumInfo;
		_type fieldType;
		_type ownerClass;
		FieldPolicy policy;
		FieldKinds kind;
		FieldType();
	private:
		Optional<std::wstring> description;
	public:
		virtual ~FieldType() {};

		/// <summary>
		/// ��ȡ��Ա��������
		/// </summary>
		///<return></return>
		FieldPolicy GetPolicy() const;

		/// <summary>
		/// ��ȡ����
		/// </summary>
		///<return></return>
		const wchar_t* GetName() const;

		/// <summary>
		/// ��ȡ����������
		/// </summary>
		///<return></return>
		const System::Type* GetClassType() const;

		/// <summary>
		/// ��ȡ��Ա��������
		/// </summary>
		///<return></return>
		const System::Type* GetFieldType() const;

		/// <summary>
		/// ��Ա��������
		/// </summary>
		_declspec(property(get = GetPolicy)) FieldPolicy Policy;

		/// <summary>
		/// ��Ա����������
		/// </summary>
		_declspec(property(get = GetClassType)) _type ClassType;

		/// <summary>
		/// ��Ա��Ա��������
		/// </summary>
		_declspec(property(get = GetFieldType)) const System::Type* Type;

		/// <summary>
		/// ��ָ�������ȡ�ó�Ա������ֵ
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		///<return></return>
		virtual Any Get(const Object* obj, bool nothrow = true) const = 0;

		/// <summary>
		/// ����ָ������ó�Ա������ֵ
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="value">ָ��ֵ</param>
		/// <param name="nothrow">�޴��󱨸�</param>
		///<return></return>
		virtual bool Set(Object* obj, const Any& value, bool nothrow = true) const = 0;


		bool operator ==(const FieldType& type) const;
		bool operator !=(const FieldType& type) const;
	};
}