#pragma once
#include "Any.h"
#include "MemberInfo.h"
#include "TypeConverter.h"
#include "InertiaString.h"
using namespace System;

namespace System
{
	ENUM_OPERATORS(AttributePolicy)
	/// <summary>
	/// ��ǩ����ö��
	/// </summary>
	enum class AttributePolicy
	{
		/// <summary>
		/// ����
		/// </summary>
		All,
		/// <summary>
		/// ����
		/// </summary>
		Assembly,
		/// <summary>
		/// �����ռ�
		/// </summary>
		NameSpace,

		/// <summary>
		/// ��
		/// </summary>
		Class,
		/// <summary>
		/// �ṹ��
		/// </summary>
		Struct,
		/// <summary>
		/// ö��
		/// </summary>
		Enum,

		/// <summary>
		/// ��Ա����
		/// </summary>
		Field,
		/// <summary>
		/// ����
		/// </summary>
		Property,
		/// <summary>
		/// ����
		/// </summary>
		Method,
		/// <summary>
		/// ���캯��
		/// </summary>
		Constructor,
				
	};

	class ClassInfo;
	class EnumInfo;


	ENUM_OPERATORSEX(AttributeFlags, UInt64)
	/// <summary>
	/// ��ǩ��ʶö��
	/// </summary>
	enum class AttributeFlags:UInt64
	{
		/// <summary>
		/// ����ת����
		/// </summary>
		TypeConverter,
		/// <summary>
		/// �Զ���
		/// </summary>
		Custom = 512,
		/// <summary>
		/// �û��Զ���
		/// </summary>
		User = 8196,
	};

	class Attribute_impl;

	/// <summary>
	/// ��ǩ��
	/// </summary>
	class RUNTIME_API Attribute :public MemberInfo
	{
	private:
		Attribute_impl* impl;
	public:
		/// <summary>
		/// ��ȡ��ǩ��ʶ
		/// </summary>
		/// <returns></returns>
		AttributeFlags GetFlag() const;

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		const wchar_t* GetName() const;

		/// <summary>
		/// ����
		/// </summary>
		__declspec(property(get = GetName)) const wchar_t* Name;

		/// <summary>
		/// ��ǩ��ʶ
		/// </summary>
		__declspec(property(get = GetFlag)) AttributeFlags Flag;
	protected:
		friend class ClassInfo;
		friend class EnumInfo;
		Attribute(const wchar_t* name, AttributeFlags flag, AttributePolicy policy, bool allowMultiple, bool inherited);

	public:
		virtual ~Attribute();
	};


	class RUNTIME_API TypeConverterAttribute final: public Attribute
	{
	private:
		std::shared_ptr<TypeConverter> _converter;
		InertiaString _name;
	public:
		template<class T>
		TypeConverterAttribute(const wchar_t* name, std::shared_ptr<T> converter) :Attribute(name, AttributeFlags::TypeConverter, AttributePolicy::Class | AttributePolicy::Struct, true, true), _name(name), _converter(std::dynamic_pointer_cast<TypeConverter>(converter))
		{
			static_assert(std::is_base_of<TypeConverter, T>::value, "T should be based on TypeConverter");
		}

		~TypeConverterAttribute();

		/// <summary>
		/// �ж��Ƿ�ɴ�ָ������ת������ǰ����
		/// </summary>
		/// <param name="type">ָ������</param>
		/// <returns></returns>
		bool CanConvertFrom(_type type) const;

		/// <summary>
		/// �ж��Ƿ�ɴ�ָ������ת����Ŀ������
		/// </summary>
		/// <param name="type">ָ������</param>
		/// <returns></returns>
		bool CanConvertTo(_type type) const;

		/// <summary>
		/// ��ָ������ת������ǰ����
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="info">��������Ϣ</param>
		/// <returns></returns>
		Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;

		/// <summary>
		/// ��ָ������ת����Ŀ������
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="type">ָ������</param>
		/// <param name="info">��������Ϣ</param>
		/// <returns></returns>
		Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

		/// <summary>
		/// ��ָ���ַ���ת������ǰ����
		/// </summary>
		/// <param name="str">ָ���ַ���</param>
		/// <param name="info">��������Ϣ</param>
		/// <returns></returns>
		Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;

		/// <summary>
		/// ��ָ������ת�����ַ�������
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="info">��������Ϣ</param>
		/// <returns></returns>
		std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
	};

}