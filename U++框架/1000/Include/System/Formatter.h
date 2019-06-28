#pragma once

//#include <Windows.h>
#include <wchar.h>
#include <locale>
#include <locale.h>
#include <algorithm>
#include <regex>
#include "Shared.h"
#include "IFormattable.h"
#include <sstream>
#include <ostream>
#include "VariadicAny.h"




namespace System
{
	/// <summary>
	/// ��ʽ����
	/// </summary>
	 class RUNTIME_API Formatter final
	{
	private:
		typedef size_t pos;
		static const pos npos = -1;

		enum class MemberNumberFormats
		{
			Unknown,
			General,
			Currency,
			Decimal,
			Scientific,
			FixedPoint,
			NumberWithCommasForThousands,
			Percent,
			RoundTrippable,
			Hexadecimal,
			FloatHexadecimal,
			Custom,
		};

		struct MemberInfo :ZeroStruct<MemberInfo>
		{
			int Index; 
			MemberNumberFormats NumberFormat;
			unsigned int NumberFormatPrecision;
			std::wstring CustomNumberFormatString;
		};

		enum class ToStringFlags
		{
			Normal,
			FloatingPoint,
			Significant,
			Scientific,
			Hex
		};

		enum class FormatStyle
		{
			All,
			OnlyCustomIgnoreBracket
		};

		static pos ResolveNumberFormat(const wchar_t* format, MemberInfo& info, pos begin, const CultureInfo& loc, FormatStyle style, pos& found);

		static std::wstring  _format(bool  _Val, const CultureInfo& loc);

		static std::wstring  _format(long  _Val, const CultureInfo& loc, ToStringFlags flag = ToStringFlags::Normal, bool group = false);

		static std::wstring  _format(unsigned long  _Val, const CultureInfo& loc, ToStringFlags flag = ToStringFlags::Normal, bool group = false);

		static std::wstring  _format(int  _Val, const CultureInfo& loc, ToStringFlags flag = ToStringFlags::Normal, bool group = false);

		static std::wstring  _format(unsigned int  _Val, const CultureInfo& loc, ToStringFlags flag = ToStringFlags::Normal, bool group = false);

		static std::wstring  _format(long long  _Val, const CultureInfo& loc, ToStringFlags flag = ToStringFlags::Normal, bool group = false);

		static std::wstring  _format(unsigned long long  _Val, const CultureInfo& loc, ToStringFlags flag = ToStringFlags::Normal, bool group = false);

		static std::wstring  _format(long double _Val, unsigned int precision, const CultureInfo& loc, ToStringFlags flag = ToStringFlags::FloatingPoint, bool group = false);

		static std::wstring  _format(const Int128& _Val, const CultureInfo& loc, bool isHex);

		static std::wstring  _format(const UInt128& _Val, const CultureInfo& loc, bool isHex);

		static void _format(bool value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(Int8 value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(UInt8 value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(Int16 value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(UInt16 value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(const Int24& value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(const UInt24& value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(Int32 value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(UInt32 value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(long value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(ULong value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(Int64 value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(UInt64 value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(const Int128& value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(const UInt128& value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(Float32 value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(Float64 value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);
		static void _format(Float128 value, const MemberInfo& info, std::wstring& result, const CultureInfo& loc);

	public:
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="vals">����չֵ��</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, const VariadicAny& vals);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, bool val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, Int8 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, UInt8 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, Int16 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, UInt16 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, const Int24& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, const UInt24& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, Int32 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, UInt32 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, long val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, ULong val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, Int64 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, UInt64 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, const Int128& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, const UInt128& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, Float32 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, Float64 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, Float128 val);
		/// <summary>
		/// ��ʽ�����ֽ��ַ���
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring FormatWidenChar(const wchar_t* fmt, const CultureInfo& loc, wchar_t val);
		/// <summary>
		/// ��ʽ���ַ���
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring FormatString(const wchar_t* fmt, const CultureInfo& loc, const std::wstring& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="refVal">�ɸ�ʽ��ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const CultureInfo& loc, IFormattable* refVal);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, bool val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, Int8 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, UInt8 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, Int16 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, UInt16 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const Int24& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const UInt24& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, Int32 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, UInt32 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, long val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, ULong val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, Int64 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, UInt64 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const Int128& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, const UInt128& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, Float32 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, Float64 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, Float128 val);
		/// <summary>
		/// ��ʽ�����ֽ��ַ���
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring FormatWidenChar(const wchar_t* fmt, wchar_t val);
		/// <summary>
		/// ��ʽ���ַ���
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring FormatString(const wchar_t* fmt, const std::wstring& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="fmt">��ʽ</param>
		/// <param name="refVal">�ɸ�ʽ��ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const wchar_t* fmt, IFormattable* refVal);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, bool val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, Int8 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, UInt8 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, Int16 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, UInt16 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, const Int24& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, const UInt24& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, Int32 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, UInt32 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, long val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, ULong val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, Int64 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, UInt64 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, const Int128& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, const UInt128& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, Float32 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, Float64 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, Float128 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="refVal">�ɸ�ʽ��ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const CultureInfo& loc, IFormattable* refVal);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(bool val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(Int8 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(UInt8 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(Int16 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(UInt16 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const Int24& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const UInt24& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(Int32 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(UInt32 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(long val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(ULong val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(Int64 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(UInt64 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const Int128& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(const UInt128& val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(Float32 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(Float64 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="val">ֵ</param>
		/// <returns></returns>
		static std::wstring Format(Float128 val);
		/// <summary>
		/// ��ʽ��
		/// </summary>
		/// <param name="refVal">�ɸ�ʽ��ֵ</param>
		/// <returns></returns>
		static std::wstring Format(IFormattable* refVal);
	};
}