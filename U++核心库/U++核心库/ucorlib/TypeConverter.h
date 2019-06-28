#pragma once

#include "Any.h"
namespace System
{
	/// <summary>
	/// ����ת����
	/// </summary>
	class RUNTIME_API TypeConverter : _noncopyable
	{
	protected:
		virtual ~TypeConverter();
	public:
		/// <summary>
		/// �ж��Ƿ�֧�ִ�ָ�����͵�ת��
		/// </summary>
		/// <param name="type">ָ������</param>
		virtual bool CanConvertFrom(_type type) const = 0;

		/// <summary>
		/// �ж��Ƿ�֧��ת����ָ������
		/// </summary>
		/// <param name="type">ָ������</param>
		virtual bool CanConvertTo(_type type) const = 0;

		/// <summary>
		/// ��Ŀ�����ת����ָ������
		/// </summary>
		/// <param name="obj">Ŀ�����</param>
		/// <param name="loc">��������Ϣ</param>
		/// <returns>ָ������</returns>
		virtual Any ConvertFrom(const Any& obj, const CultureInfo& info) const = 0;

		/// <summary>
		/// ��Ŀ�����ת����ָ������
		/// </summary>
		/// <param name="obj">Ŀ�����</param>
		/// <param name="type">ָ������</param>
		/// <param name="loc">��������Ϣ</param>
		/// <returns>ָ������</returns>
		virtual Any ConvertTo(const Any& obj, _type type, const CultureInfo& info) const = 0;

		/// <summary>
		/// ��ָ���ַ���������ָ������
		/// </summary>
		/// <param name="str">ָ���ַ���</param>
		/// <param name="loc">��������Ϣ</param>
		/// <returns></returns>
		virtual Any ConvertFromString(const std::wstring& str, const CultureInfo& info) const = 0;

		/// <summary>
		/// ��ָ������ת�����ַ���
		/// </summary>
		/// <param name="obj">ָ������</param>
		/// <param name="loc">��������Ϣ</param>
		/// <returns></returns>
		virtual std::wstring ConvertToString(const Any& obj, const CultureInfo& info) const = 0;
	};
}