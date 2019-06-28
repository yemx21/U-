#pragma once

#include "PropertyInfo.h"
namespace System
{
	/// <summary>
	/// Enum PropertyKinds
	/// </summary>
	enum class PropertyKinds
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
		/// ����������
		/// </summary>
		ConstRead,
		/// <summary>
		/// ����������д
		/// </summary>
		ConstRead_Write,
		/// <summary>
		/// д��������
		/// </summary>
		ConstWrite,
		/// <summary>
		/// д����������
		/// </summary>
		ConstWrite_Read,
		/// <summary>
		/// ��д��������
		/// </summary>
		ConstReadWrite,
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
	/// ����������
	/// </summary>
	class RUNTIME_API PropertyType : public Type
	{
	protected:
		friend class PropertyInfo_impl;
		friend class ClassInfo;
		_type readType;
		_type writeType;
		_type ownerClass;
		PropertyPolicy policy;
		PropertyKinds kind;

		/// <summary>
		/// ����<see cref="PropertyType"/>ʵ��
		/// </summary>
		PropertyType();
	private:
		Optional<std::wstring> description;
	public:
		virtual ~PropertyType();

		/// <summary>
		/// ��ȡ����
		/// </summary>
		///<return></return>
		const wchar_t* GetName() const;

		/// <summary>
		/// ��ȡ��������
		/// </summary>
		///<return></return>
		_type GetClassType() const;

		/// <summary>
		/// ��ȡ���ͣ�����
		/// </summary>
		///<return></return>
		_type GetReadType() const;

		/// <summary>
		/// ��ȡ���ͣ�д��
		/// </summary>
		///<return></return>
		_type GetWriteType() const;

		/// <summary>
		/// ��ȡ��������
		/// </summary>
		///<return></return>
		PropertyPolicy GetPolicy() const;

		/// <summary>
		/// ��ȡ��������
		/// </summary>
		///<return></return>
		PropertyKinds GetKind() const;

		/// <summary>
		/// ��������
		/// </summary>
		_declspec(property(get = GetKind)) PropertyKinds Kind;

		/// <summary>
		/// ��������
		/// </summary>
		_declspec(property(get = GetPolicy)) PropertyPolicy Policy;

		/// <summary>
		/// ��������
		/// </summary>
		_declspec(property(get = GetClassType)) _type ClassType;

		/// <summary>
		/// ���ͣ�����
		/// </summary>
		_declspec(property(get = GetReadType)) _type ReadType;

		/// <summary>
		/// ���ͣ�д��
		/// </summary>
		_declspec(property(get = GetWriteType)) _type WriteType;

		/// <summary>
		/// ��ȡ����ֵ
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		virtual Any Get(Object* obj, bool nothrow = true) const = 0;

		/// <summary>
		/// ��������ֵ
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="value">ֵ</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		virtual bool Set(Object* obj, const Any& value, bool nothrow = true) const = 0;

		/// <summary>
		/// ��ȡ����ֵ
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		virtual Any Get(const Object* obj, bool nothrow = true) const = 0;

		/// <summary>
		/// ��������ֵ
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="value">ֵ</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		virtual bool Set(const Object* obj, const Any& value, bool nothrow = true) const = 0;

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

		bool operator ==(const PropertyType& type) const;
		bool operator !=(const PropertyType& type) const;
	};
}