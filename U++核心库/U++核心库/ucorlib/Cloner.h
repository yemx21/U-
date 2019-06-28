#pragma once
#include <string>
#include "Config.h"

namespace System
{
	/// <summary>
	/// ��¡��
	/// </summary>
	 class RUNTIME_API Cloner
	{
	public:
		/// <summary>
		/// ��¡�ַ���
		/// </summary>
		/// <param name="str">�ַ���</param>
		/// <returns></returns>
		static wchar_t* Clone(const wchar_t* str);

		/// <summary>
		/// ��¡���ֽ��ַ���
		/// </summary>
		/// <param name="str">���ֽ��ַ���</param>
		/// <returns></returns>
		static char* Clone(const char* str);

		/// <summary>
		/// ��¡���ֽ��ַ���
		/// </summary>
		/// <param name="str">���ֽ��ַ���</param>
		/// <returns></returns>
		static wchar_t* Clone(const std::wstring& str);

		/// <summary>
		/// ��¡ָ���ַ���
		/// </summary>
		/// <param name="str">�ַ���</param>
		/// <returns></returns>
		static char* Clone(const std::string& str);

		/// <summary>
		/// ��¡ָ�����ֽ��ַ���
		/// </summary>
		/// <param name="str">���ֽ��ַ���</param>
		/// <param name="memSize">�ֽڴ�С</param>
		/// <returns></returns>
		static wchar_t* Clone(const wchar_t* str, UInt32& memSize);

		/// <summary>
		/// ��¡ָ���ַ���
		/// </summary>
		/// <param name="str">�ַ���</param>
		/// <param name="memSize">�ֽڴ�С</param>
		/// <returns></returns>
		static char* Clone(const char* str, UInt32& memSize);

		/// <summary>
		/// ��¡ָ�����ֽ��ַ���
		/// </summary>
		/// <param name="str">���ֽ��ַ���</param>
		/// <param name="memSize">�ֽڴ�С</param>
		/// <returns></returns>
		static wchar_t* Clone(const std::wstring& str, UInt32& memSize);

		/// <summary>
		/// ��¡ָ���ַ���
		/// </summary>
		/// <param name="str">�ַ���</param>
		/// <param name="memSize">�ֽڴ�С</param>
		/// <returns></returns>
		static char* Clone(const std::string& str, UInt32& memSize);

	};
}

