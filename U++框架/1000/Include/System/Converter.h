#pragma once
#include <string>
#include <locale>
#include <codecvt>
#include "Config.h"

namespace System
{
	/// <summary>
	/// ת������
	/// </summary>
	 class RUNTIME_API Converter
	{
	public:		
		/// <summary>
		/// ת���ַ���
		/// </summary>
		/// <param name="str">�ַ���</param>
		/// <param name="wresult">���ֽ��ַ���</param>
		/// <param name="loc">��������Ϣ</param>
		/// <returns></returns>
		static bool Convert(const char* str, std::wstring& wresult, const std::locale& loc) ;

		/// <summary>
		/// ת���ַ���
		/// </summary>
		/// <param name="str">���ֽ��ַ���</param>
		/// <param name="aresult">�ַ���</param>
		/// <param name="loc">��������Ϣ</param>
		/// <returns></returns>
		static bool Convert(const wchar_t* str, std::string& aresult, const std::locale& loc) ;

		/// <summary>
		/// ת���ַ���
		/// </summary>
		/// <param name="str">�ַ���</param>
		/// <param name="wresult">���ֽ��ַ���</param>
		/// <param name="loc">��������Ϣ</param>
		/// <returns></returns>
		static bool Convert(std::string const& str, std::wstring& wresult, const std::locale& loc) ;

		/// <summary>
		/// ת���ַ���
		/// </summary>
		/// <param name="str">���ֽ��ַ���</param>
		/// <param name="aresult">�ַ���</param>
		/// <param name="loc">��������Ϣ</param>
		/// <returns></returns>
		static bool Convert(std::wstring const& str, std::string& aresult, const std::locale& loc) ;

		/// <summary>
		/// Cs the plus new.
		/// </summary>
		/// <param name="str">�ַ���</param>
		/// <param name="loc_t">��������Ϣ</param>
		/// <returns>���ֽ��ַ���</returns>
		static wchar_t* CPlusNew(const char* str, const _locale_t & loc_t) ;

		/// <summary>
		/// ת�������ַ���
		/// </summary>
		/// <param name="str">���ֽ��ַ���</param>
		/// <param name="loc_t">��������Ϣ</param>
		/// <returns>�ַ���</returns>
		static char* CPlusNew(const wchar_t* str, const _locale_t & loc_t) ;

		/// <summary>
		/// ת���ַ���
		/// </summary>
		/// <param name="str">�ַ���</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="loc_t">��������Ϣ</param>
		/// <returns>���ֽ��ַ���</returns>
		static std::wstring Convert(const char* str, const std::locale& loc, const _locale_t& loc_t) ;

		/// <summary>
		/// ת���ַ���
		/// </summary>
		/// <param name="str">���ֽ��ַ���</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="loc_t">��������Ϣ</param>
		/// <returns>�ַ���</returns>
		static std::string Convert(const wchar_t* str, const std::locale& loc, const _locale_t& loc_t) ;

		/// <summary>
		/// ת�������ַ���
		/// </summary>
		/// <param name="str">�ַ���</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="loc_t">��������Ϣ</param>
		/// <returns>���ֽ��ַ���</returns>
		static wchar_t* ConvertNew(const char* str, const std::locale& loc, const _locale_t& loc_t) ;

		/// <summary>
		/// ת�������ַ���
		/// </summary>
		/// <param name="str">���ֽ��ַ���</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="loc_t">��������Ϣ</param>
		/// <returns>�ַ���</returns>
		static char* ConvertNew(const wchar_t* str, const std::locale& loc, const _locale_t& loc_t) ;

		/// <summary>
		///ת��UCS�����ַ���ת����UTF8����
		/// </summary>
		/// <param name="src">���ֽ��ַ���</param>
		/// <returns>�ַ���</returns>
		static std::string StringToUTF8(const std::wstring& src) ;

		/// <summary>
		/// ת��UTF8�����ַ���ת����UCS����
		/// </summary>
		/// <param name="src">�ַ���</param>
		/// <returns>���ֽ��ַ���</returns>
		static std::wstring UTF8ToString(const std::string& src) ;

		/// <summary>
		/// ת��UCS�����ַ���ת����UTF16����
		/// </summary>
		/// <param name="src">���ֽ��ַ���</param>
		/// <returns>�ַ���</returns>
		static std::string StringToUTF16(const std::wstring& src) ;

		/// <summary>
		/// ת��UTF16�����ַ���ת����UCS����
		/// </summary>
		/// <param name="src">�ַ���</param>
		/// <returns>���ֽ��ַ���</returns>
		static std::wstring UTF16ToString(const std::string& src) ;

	};
}