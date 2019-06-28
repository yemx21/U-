#pragma once
#include "Config.h"
#include "CultureInfo.h"
namespace System
{
	/// <summary>
	/// ���������
	/// </summary>
	class RUNTIME_API EncodingHelper
	{
	public:
		/// <summary>
		/// ��ȡ����ַ���
		/// </summary>
		/// <param name="byteCount">�ֽ���</param>
		/// <param name="encoding">����</param>
		/// <returns>�ַ���</returns>
		static ULong GetMaxCharCount(unsigned int byteCount, Encodings encoding);

		/// <summary>
		/// UTF8ת����UCS
		/// </summary>
		/// <param name="bytes">�ֽ�</param>
		/// <param name="byteCount">�ֽ���</param>
		/// <param name="chars">�ַ�</param>
		/// <param name="charCount">�ַ���</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns>ULong.</returns>
		static ULong Utf8GetUCS(char* bytes, ULong byteCount, wchar_t* chars, ULong charCount, const CultureInfo& loc, bool nothrow = true);

		/// <summary>
		/// UTF16С��ת����UCS
		/// </summary>
		/// <param name="bytes">�ֽ�</param>
		/// <param name="byteCount">�ֽ���</param>
		/// <param name="chars">�ַ�</param>
		/// <param name="charCount">�ַ���</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns>�ַ���</returns>
		static ULong Utf16LEGetUCS(char* bytes, ULong byteCount, wchar_t* chars, ULong charCount, const CultureInfo& loc, bool nothrow = true);

		/// <summary>
		/// UTF16���ת����UCS
		/// </summary>
		/// <param name="bytes">�ֽ�</param>
		/// <param name="byteCount">�ֽ���</param>
		/// <param name="chars">�ַ�</param>
		/// <param name="charCount">�ַ���</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns>�ַ���</returns>
		static ULong Utf16BEGetUCS(char* bytes, ULong byteCount, wchar_t* chars, ULong charCount, const CultureInfo& loc, bool nothrow = true);

		/// <summary>
		/// UTF32С��ת����UCS
		/// </summary>
		/// <param name="bytes">�ֽ�</param>
		/// <param name="byteCount">�ֽ���</param>
		/// <param name="chars">�ַ�</param>
		/// <param name="charCount">�ַ���</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns>�ַ���</returns>
		static ULong Utf32LEGetUCS(char* bytes, ULong byteCount, wchar_t* chars, ULong charCount, const CultureInfo& loc, bool nothrow = true);

		/// <summary>
		/// UTF32���ת����UCS
		/// </summary>
		/// <param name="bytes">�ֽ�</param>
		/// <param name="byteCount">�ֽ���</param>
		/// <param name="chars">�ַ�</param>
		/// <param name="charCount">�ַ���</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns>�ַ���</returns>
		static ULong Utf32BEGetUCS(char* bytes, ULong byteCount, wchar_t* chars, ULong charCount, const CultureInfo& loc, bool nothrow = true);

		/// <summary>
		/// UCS�ֽ�ת��
		/// </summary>
		/// <param name="bytes">�ֽ�</param>
		/// <param name="byteSize">�ֽڴ�С</param>
		/// <param name="byteIndex">�ֽڿ�ʼ����</param>
		/// <param name="byteCount">�ֽ���</param>
		/// <param name="chars">The chars.</param>
		/// <param name="charSize">�ַ���С</param>
		/// <param name="charIndex">�ַ���ʼ����</param>
		/// <param name="encoding">����</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns>�ַ���</returns>
		static ULong GetUCS(char* bytes, ULong byteSize, ULong byteIndex, unsigned int byteCount, wchar_t* chars, ULong charSize, ULong charIndex, Encodings encoding, const CultureInfo& loc, bool nothrow = true);

	};
}