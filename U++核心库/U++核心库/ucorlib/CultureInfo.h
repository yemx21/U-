#pragma once
#include "Config.h"
#include <locale>
#include <locale.h>
#include <algorithm>

namespace System
{
	/// <summary>
	/// ����
	/// </summary>
	enum class Encodings
	{
		/// <summary>
		/// ANSI����
		/// </summary>
		Ansi,
		/// <summary>
		/// UTF8����
		/// </summary>
		Utf8,
		/// <summary>
		/// UTF16С�˱���
		/// </summary>
		Utf16LE,
		/// <summary>
		/// Ĭ��Unicode����
		/// </summary>
		Unicode = Utf16LE,
		/// <summary>
		/// UTF16��˱���
		/// </summary>
		Utf16BE,
		/// <summary>
		/// UTF32С�˱���
		/// </summary>
		Utf32LE,
		/// <summary>
		/// UTF32��˱���
		/// </summary>
		Utf32BE,
	};

	/// <summary>
	/// �ַ����Ƚ�
	/// </summary>
	enum class StringComparison
	{
		/// <summary>
		/// ��ǰ����
		/// </summary>
		CurrentCulture,
		/// <summary>
		/// ���Դ�Сд�ĵ�ǰ����
		/// </summary>
		CurrentCultureIgnoreCase,
		/// <summary>
		/// ���������
		/// </summary>
		InvariantCulture,
		/// <summary>
		/// ���Դ�Сд�ķ��������
		/// </summary>
		InvariantCultureIgnoreCase,
	};

	class EncodingHelper;

	class CultureInfo;

	class CultureInfo_impl;

	/// <summary>
	/// �����Ը�ʽ��
	/// </summary>
	enum class CultureInfoPatterns
	{
		/// <summary>
		/// ��ʱ����ֵȫ��ʽ��
		/// </summary>
		FullTimeSpanPositivePattern,
		/// <summary>
		/// ��ʱ���ֵȫ��ʽ��
		/// </summary>
		FullTimeSpanNegativePattern,
		/// <summary>
		/// ���¸�ʽ��
		/// </summary>
		YearMonthPattern,
		/// <summary>
		/// �����ڸ�ʽ��
		/// </summary>
		ShortDatePattern,
		/// <summary>
		/// �����ڸ�ʽ��
		/// </summary>
		LongDatePattern,
		/// <summary>
		/// ��ʱ���ʽ��
		/// </summary>
		ShortTimePattern,
		/// <summary>
		/// ��ʱ���ʽ��
		/// </summary>
		LongTimePattern,
		/// <summary>
		/// ���ո�ʽ��
		/// </summary>
		MonthDayPattern,

		/// <summary>
		/// �����ڶ�ʱ��ȫ��ʽ��
		/// </summary>
		FullLongDateShortTimePattern,

		/// <summary>
		/// �����ڳ�ʱ��ȫ��ʽ��
		/// </summary>
		FullLongDateLongTimePattern,

		/// <summary>
		/// �����ڶ�ʱ���ʽ��
		/// </summary>
		GeneralShortDateShortTimePattern,

		/// <summary>
		/// �����ڳ�ʱ���ʽ��
		/// </summary>
		GeneralShortDateLongTimePattern,

		/// <summary>
		/// ���ڳ�ƫ�Ƹ�ʽ��
		/// </summary>
		DateTimeOffsetPattern,
	};

	/// <summary>
	/// �����Գ������Ƽ���
	/// </summary>
	enum class CultureInfoConstNames
	{
		/// <summary>
		/// ������
		/// </summary>
		Sunday,
		/// <summary>
		/// ����һ
		/// </summary>
		Monday,
		/// <summary>
		/// ���ڶ�
		/// </summary>
		Tuesday,
		/// <summary>
		/// ������
		/// </summary>
		Wednesday,
		/// <summary>
		/// ������
		/// </summary>
		Thursday,
		/// <summary>
		/// ������
		/// </summary>
		Friday,
		/// <summary>
		/// ������
		/// </summary>
		Saturday,

		/// <summary>
		/// �����գ���д��
		/// </summary>
		Abbreviated_Sunday,
		/// <summary>
		/// ����һ����д��
		/// </summary>
		Abbreviated_Monday,
		/// <summary>
		/// ���ڶ�����д��
		/// </summary>
		Abbreviated_Tuesday,
		/// <summary>
		/// ����������д��
		/// </summary>
		Abbreviated_Wednesday,
		/// <summary>
		///  �����ģ���д��
		/// </summary>
		Abbreviated_Thursday,
		/// <summary>
		/// �����壨��д��
		/// </summary>
		Abbreviated_Friday,
		/// <summary>
		/// ����������д��
		/// </summary>
		Abbreviated_Saturday,

		/// <summary>
		/// һ��
		/// </summary>
		January,
		/// <summary>
		/// ����
		/// </summary>
		February,
		/// <summary>
		/// ����
		/// </summary>
		March,
		/// <summary>
		/// ����
		/// </summary>
		April,
		/// <summary>
		/// ����
		/// </summary>
		May,
		/// <summary>
		/// ����
		/// </summary>
		June,
		/// <summary>
		/// ����
		/// </summary>
		July,
		/// <summary>
		/// ����
		/// </summary>
		August,
		/// <summary>
		/// ����
		/// </summary>
		September,
		/// <summary>
		/// ʮ��
		/// </summary>
		October,
		/// <summary>
		/// ʮһ��
		/// </summary>
		November,
		/// <summary>
		/// ʮ����
		/// </summary>
		December,

		/// <summary>
		/// һ�£���д��
		/// </summary>
		Abbreviated_January,
		/// <summary>
		/// ���£���д��
		/// </summary>
		Abbreviated_February,
		/// <summary>
		/// ���£���д��
		/// </summary>
		Abbreviated_March,
		/// <summary>
		/// ���£���д��
		/// </summary>
		Abbreviated_April,
		/// <summary>
		/// ���£���д��
		/// </summary>
		Abbreviated_May,
		/// <summary>
		/// ���£���д��
		/// </summary>
		Abbreviated_June,
		/// <summary>
		/// ���£���д��
		/// </summary>
		Abbreviated_July,
		/// <summary>
		/// ���£���д��
		/// </summary>
		Abbreviated_August,
		/// <summary>
		/// ���£���д��
		/// </summary>
		Abbreviated_September,
		/// <summary>
		/// ʮ�£���д��
		/// </summary>
		Abbreviated_October,
		/// <summary>
		/// ʮһ�£���д��
		/// </summary>
		Abbreviated_November,
		/// <summary>
		///  ʮ���£���д��
		/// </summary>
		Abbreviated_December,

		/// <summary>
		/// һ�£����и�
		/// </summary>
		Genitive_January,
		/// <summary>
		/// ���£����и�
		/// </summary>
		Genitive_February,
		/// <summary>
		/// ���£����и�
		/// </summary>
		Genitive_March,
		/// <summary>
		/// ���£����и�
		/// </summary>
		Genitive_April,
		/// <summary>
		/// ���£����и�
		/// </summary>
		Genitive_May,
		/// <summary>
		/// ���£����и�
		/// </summary>
		Genitive_June,
		/// <summary>
		/// ���£����и�
		/// </summary>
		Genitive_July,
		/// <summary>
		/// ���£����и�
		/// </summary>
		Genitive_August,
		/// <summary>
		/// ���£����и�
		/// </summary>
		Genitive_September,
		/// <summary>
		/// ʮ�£����и�
		/// </summary>
		Genitive_October,
		/// <summary>
		/// ʮһ�£����и�
		/// </summary>
		Genitive_November,
		/// <summary>
		/// ʮ���£����и�
		/// </summary>
		Genitive_December,

		/// <summary>
		/// һ�£����и��д��
		/// </summary>
		Genitive_Abbreviated_January,
		/// <summary>
		/// ���£����и��д��
		/// </summary>
		Genitive_Abbreviated_February,
		/// <summary>
		/// ���£����и��д��
		/// </summary>
		Genitive_Abbreviated_March,
		/// <summary>
		/// ���£����и��д��
		/// </summary>
		Genitive_Abbreviated_April,
		/// <summary>
		/// ���£����и��д��
		/// </summary>
		Genitive_Abbreviated_May,
		/// <summary>
		/// ���£����и��д��
		/// </summary>
		Genitive_Abbreviated_June,
		/// <summary>
		/// ���£����и��д��
		/// </summary>
		Genitive_Abbreviated_July,
		/// <summary>
		/// ���£����и��д��
		/// </summary>
		Genitive_Abbreviated_August,
		/// <summary>
		/// ���£����и��д��
		/// </summary>
		Genitive_Abbreviated_September,
		/// <summary>
		/// ʮ�£����и��д��
		/// </summary>
		Genitive_Abbreviated_October,
		/// <summary>
		/// ʮһ�£����и��д��
		/// </summary>
		Genitive_Abbreviated_November,
		/// <summary>
		/// ʮ���£����и��д��
		/// </summary>
		Genitive_Abbreviated_December,


		/// <summary>
		/// һ�£����꣩
		/// </summary>
		Leap_January,
		/// <summary>
		/// ���£����꣩
		/// </summary>
		Leap_February,
		/// <summary>
		/// ���£����꣩
		/// </summary>
		Leap_March,
		/// <summary>
		/// ���£����꣩
		/// </summary>
		Leap_April,
		/// <summary>
		/// ���£����꣩
		/// </summary>
		Leap_May,
		/// <summary>
		/// ���£����꣩
		/// </summary>
		Leap_June,
		/// <summary>
		/// ���£����꣩
		/// </summary>
		Leap_July,
		/// <summary>
		/// ���£����꣩
		/// </summary>
		Leap_August,
		/// <summary>
		/// ���£����꣩
		/// </summary>
		Leap_September,
		/// <summary>
		/// ʮ�£����꣩
		/// </summary>
		Leap_October,
		/// <summary>
		/// ʮһ�£����꣩
		/// </summary>
		Leap_November,
		/// <summary>
		/// ʮ���£����꣩
		/// </summary>
		Leap_December,



		/// <summary>
		/// ��Ԫ
		/// </summary>
		Era,

		/// <summary>
		/// ��Ԫ����д��
		/// </summary>
		Abbreviated_Era,

		/// <summary>
		/// Ӣ�Ĺ�Ԫ����д��
		/// </summary>
		Abbreviated_EnglishEra,

		/// <summary>
		/// ���ڷָ���
		/// </summary>
		DateSeparator,
		/// <summary>
		/// ʱ��ָ���
		/// </summary>
		TimeSeparator,

		/// <summary>
		/// �����־
		/// </summary>
		AMDesignator,
		/// <summary>
		/// �����־
		/// </summary>
		PMDesignator,

		/// <summary>
		/// С����
		/// </summary>
		DecimalPoint,
		/// <summary>
		/// ǧλ�ָ���
		/// </summary>
		ThousandsSeparator,
		/// <summary>
		/// ���ҷ���
		/// </summary>
		CurrencySymbol,
		/// <summary>
		/// ����С����
		/// </summary>
		MoneyDecimalPoint,
		/// <summary>
		/// ����ǧλ�ָ���
		/// </summary>
		MoneyThousandsSeparator,
		/// <summary>
		/// ��ֵ����
		/// </summary>
		PositiveSignSymbol,
		/// <summary>
		/// ��ֵ����
		/// </summary>
		NegativeSignSymbol,

	};

	/// <summary>
	/// �����Ի��ҳ���ö��
	/// </summary>
	enum class CultureInfoMoneyConsts
	{
		/// <summary>
		/// ����С����
		/// </summary>
		Fraction,
		/// <summary>
		/// ��ֵ���ҷ���λ��
		/// </summary>
		PositiveCurrencySymbolPos,
		/// <summary>
		/// ��ֵ���ҷָ���λ��
		/// </summary>
		PositiveSeparatorPos,
		/// <summary>
		/// ��������λ��
		/// </summary>
		PositiveSignSymbolPos,
		/// <summary>
		/// ��ֵ���ҷ���λ��
		/// </summary>
		NegativeCurrencySymbolPos,
		/// <summary>
		/// ��ֵ���ҷָ���λ��
		/// </summary>
		NegativeSeparatorPos,
		/// <summary>
		/// ���Ҹ���λ��
		/// </summary>
		NegativeSignSymbolPos,
	};

	/// <summary>
	/// �����Բ����ͳ���ö��
	/// </summary>
	enum class CultureInfoBooleanFlags
	{
		/// <summary>
		/// ��������Ϊ����һ
		/// </summary>
		FirstDayofWeekIsMonday,
		/// <summary>
		/// ǿ��ʹ����λ���ֱ�ʾ���
		/// </summary>
		///<remarks>�ձ���̨�����Ϊtrue</remarks>
		HasForceTwoDigitYears, 
		/// <summary>
		/// ʹ�����и�
		/// </summary>
		UseGenitiveMonth,
		/// <summary>
		/// ���е�13����
		/// </summary>
		Has13Months
	};

	class Calendar;
	class DateTimeFormat;

	/// <summary>
	/// ��������Ϣ��
	/// </summary>
	 class RUNTIME_API CultureInfo final
	{
	private:
		friend class CultureInfo_impl;
		CultureInfo_impl* impl;
		friend class EncodingHelper;
	protected:
		friend class DateTimeFormat;
		int GetInternalValue(int id) const;
	public:		

		/// <summary>
		/// ����
		/// </summary>
		static const char* america;

		/// <summary>
		/// ��� ���й���
		/// </summary>
		static const char* hongKong;

		/// <summary>
		/// ̨�壨�й���
		/// </summary>
		static const char* taiWan;

		/// <summary>
		/// �й�
		/// </summary>
		static const char* china;

		/// <summary>
		/// �ձ�
		/// </summary>
		static const char* japan;

		/// <summary>
		/// �Ϻ�
		/// </summary>
		static const char* southkorea;

		/// <summary>
		/// Ӣ��
		/// </summary>
		static const char* unitedKingdom;

		/// <summary>
		/// ����
		/// </summary>
		static const char* unitedStates;
	public:
		/// <summary>
		/// ���� <see cref="CultureInfo"/>ʵ��.
		/// </summary>
		/// <param name="locName">��������</param>
		CultureInfo(const char* locName);

		CultureInfo(const CultureInfo& info);

		CultureInfo(CultureInfo&& info);

		~CultureInfo();

		CultureInfo& operator =(const CultureInfo& info);

		bool Is(const char* locname) const;

		/// <summary>
		/// ��ȡ���ַ�����
		/// </summary>
		const wchar_t* GetWidenName() const;

		/// <summary>
		/// ��ȡ����
		/// </summary>
		const char* GetName() const;

		/// <summary>
		/// ��ȡ��������Ϣ��ʾ ��C���ԣ�
		/// </summary>
		const std::locale GetLocale() const;

		/// <summary>
		/// ��ȡ������������Ϣ��ʾ ��C���ԣ�
		/// </summary>
		const std::locale GetLocale_Group() const;

		/// <summary>
		/// ��ȡ��������Ϣ��ʾ ��C++���ԣ�
		/// </summary>
		const _locale_t GetLocale_t() const;

		/// <summary>
		/// ��ȡ��ǰ��������Ϣ
		/// </summary>
		static CultureInfo Current();

		/// <summary>
		/// ��ȡ����������������Ϣ
		/// </summary>
		static CultureInfo& Invariant();

		/// <summary>
		/// ��ȡ�����Ի��ҳ�������
		/// </summary>
		/// <param name="moneyconst">���ҳ���ö��</param>
		/// <returns></returns>
		const char GetMoneyConst(CultureInfoMoneyConsts moneyconst) const;

		/// <summary>
		/// ��ȡ�����Ը�ʽ������
		/// </summary>
		/// <param name="pattern">��ʽ��ö��</param>
		/// <returns></returns>
		unsigned int GetPatternCount(CultureInfoPatterns pattern) const;

		/// <summary>
		/// ��ȡ�����Ը�ʽ��
		/// </summary>
		/// <param name="pattern">��ʽ��ö��</param>
		/// <returns></returns>
		const wchar_t* GetPattern(CultureInfoPatterns pattern, unsigned int index = 0) const;

		/// <summary>
		/// ��ȡ�����Գ���������
		/// </summary>
		/// <param name="name">������ö��</param>
		/// <returns></returns>
		unsigned int GetConstsNameCount(CultureInfoConstNames name) const;

		/// <summary>
		/// ��ȡ�����Գ�����
		/// </summary>
		/// <param name="name">������ö��</param>
		/// <returns></returns>
		const wchar_t* GetConstsName(CultureInfoConstNames name, unsigned int index=0) const;

		/// <summary>
		/// ��ȡ�����Բ����ͳ�����
		/// </summary>
		/// <param name="name">�����ͳ���ö��</param>
		/// <returns></returns>
		bool GetBooleanFlags(CultureInfoBooleanFlags flag) const;

		/// <summary>
		/// ��ȡ������Ĭ������
		/// </summary>
		/// <returns></returns>
		const System::Calendar* GetCalendar() const;

		/// <summary>
		/// ��ȡ�����Կ�ѡ������ʶ
		/// </summary>
		/// <returns></returns>
		std::vector<int> GetOptionalCalendarIds() const;

		/// <summary>
		/// ��ָ����ѡ������ʶ�в����µ���������Ϣ
		/// </summary>
		/// <returns></returns>
		CultureInfo CreateByCalendarId(int)const;

		/// <summary>
		/// ��ָ�������в����µ���������Ϣ
		/// </summary>
		/// <returns></returns>
		CultureInfo CreateByCalendar(System::Calendar* newCalendar)const;

		/// <summary>
		/// ����
		/// </summary>
		_declspec(property(get = GetName)) const char* Name;

		/// <summary>
		/// ���ַ�����
		/// </summary>
		_declspec(property(get = GetWidenName)) const wchar_t* WidenName;

		/// <summary>
		/// ��������Ϣ��ʾ ��C���ԣ�
		/// </summary>
		_declspec(property(get = GetLocale)) const std::locale CLocale;

		/// <summary>
		/// ������������Ϣ��ʾ ��C���ԣ�
		/// </summary>
		_declspec(property(get = GetLocale_Group)) const std::locale Locale_Group;

		/// <summary>
		/// ��������Ϣ��ʾ ��C++���ԣ�
		/// </summary>
		_declspec(property(get = GetLocale_t)) const _locale_t CPlusLocale;

		/// <summary>
		/// ������Ĭ������
		/// </summary>
		_declspec(property(get = GetCalendar)) const System::Calendar* Calendar;
	};
}
