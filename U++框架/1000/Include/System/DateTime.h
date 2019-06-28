#pragma once
#include "TimeSpan.h"

namespace System
{
	/// <summary>
	/// ����ʱ������
	/// </summary>
	class RUNTIME_API DateTimeKind : __uobject
	{
		__uvalue_begin(DateTimeKind, UInt32)
		/// <summary>
		/// ���޶�
		/// </summary>
			__uvalue(Unspecified)
		/// <summary>
		/// Э������ʱ
		/// </summary>
		__uvalue(Utc)
		/// <summary>
		/// ����ʱ
		/// </summary>
		__uvalue(Local)
		__uvalue_end(DateTimeKind, Unspecified)
	};

	/// <summary>
	/// ���ڣ����ڣ�
	/// </summary>
	class RUNTIME_API DayOfWeek : __uobject
	{
		__uvalue_begin(DayOfWeek, UInt32)
		/// <summary>
		/// ������
		/// </summary>
			__uvalue(Sunday)
		/// <summary>
		/// ����һ
		/// </summary>
		__uvalue(Monday)
		/// <summary>
		/// ���ڶ�
		/// </summary>
		__uvalue(Tuesday)
		/// <summary>
		/// ������
		/// </summary>
		__uvalue(Wednesday)
		/// <summary>
		/// ������
		/// </summary>
		__uvalue(Thursday)
		/// <summary>
		/// ������
		/// </summary>
		__uvalue(Friday)
		/// <summary>
		/// ������
		/// </summary>
		__uvalue(Saturday)
		__uvalue_end(DayOfWeek, Monday)
	};

	/// <summary>
	/// ���ڷ��ö��
	/// </summary>
	class RUNTIME_API DateTimeStyles : __uobject
	{
		__uvalue_begin(DateTimeStyles, UInt32)
		/// <summary>
		/// ��
		/// </summary>
		__uvalue(None, 0U)
		/// <summary>
		/// �ڷ����ڼ�������ǰ���հ��ַ�
		/// </summary>
		__uvalue(AllowLeadingWhite, 1U)
		/// <summary>
		/// �ڷ����ڼ�������β��հ��ַ�
		/// </summary>
		__uvalue(AllowTrailingWhite, 2U)
		/// <summary>
		/// �ڷ����ڼ��������ַ����м�Ķ���հ��ַ�
		/// </summary>
		__uvalue(AllowInnerWhite, 4U)
		/// <summary>
		/// �ڷ����ڼ��������ַ�������λ�õĶ���հ��ַ������հ��ַ������� DateTimeFormatInfo ��ʽģʽ�е�������⡣
		/// </summary>
		/// <remarks>��ֵ�� AllowLeadingWhite��AllowTrailingWhite �� AllowInnerWhite ֵ�����</remarks>
		__uvalue(AllowWhiteSpaces, 7U)
		/// <summary>
		/// ����������ַ���ֻ����ʱ������������ڣ������������ٶ����¹������ڣ��� = 1���� = 1 ������ = 1�� ���û��ʹ�ô�ֵ����ٶ�Ϊ��ǰ���ڡ�
		/// </summary>
		__uvalue(NoCurrentDateDefault, 8U)
		/// <summary>
		/// ��Э������ʱ (UTC) ��ʽ�������ں�ʱ�䡣 ��������ַ�����ʾ����ʱ�䣨ͨ��ʱ��˵������ AssumeLocal������Ὣ���ں�ʱ��ӱ���ʱ��ת��Ϊ UTC�� ��������ַ�����ʾ UTC ʱ�䣨ͨ��ʱ��˵������ AssumeUniversal�����򲻽����κ�ת���� ��������ַ�������ʾ����ʱ��� UTC ʱ�䣬�򲻽����κ�ת�����������ɵ� Kind ����Ϊ Unspecified��
		/// </summary>
		/// <remarks>��ֵ������ RoundtripKind һ��ʹ��</remarks>
		__uvalue(AdjustToUniversal, 16U)
		/// <summary>
		/// ����������ַ�����δָ���κ�ʱ������ٶ����ַ�����ʾ����ʱ�䡣
		/// </summary>
		/// <remarks>��ֵ������ AssumeUniversal �� RoundtripKind һ��ʹ��</remarks>
		__uvalue(AssumeLocal, 32U)
		/// <summary>
		/// ����������ַ�����δָ���κ�ʱ������ٶ����ַ�����ʾ UTC
		/// </summary>
		/// <remarks>��ֵ������ AssumeLocal �� RoundtripKind һ��ʹ��</remarks>
		__uvalue(AssumeUniversal, 64U)
		/// <summary>
		/// ��ʹ�á�o����r����׼��ʽ˵������ DateTime ������ת��Ϊ�ַ�����Ȼ���ٽ����ַ���ת���� DateTime ����ʱ�����������ڵ� DateTimeKind �ֶΡ�
		/// </summary>
		__uvalue(RoundtripKind, 128U)
		__uvalue_end(DateTimeStyles, None)
	};
	__uenum_operator(DateTimeStyles)

	class TimeZoneInfo;
	struct TimeZoneInfoComparer;

	class DateTime;
	class DateTimeFormat;

	/// <summary>
	/// ����ʱ����
	/// </summary>
	class RUNTIME_API DateTime final: __uobject
	{
	protected:
		virtual std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const;
	protected:
		Int64 dateData;
		DateTimeKind _kind;
		bool _iadst;

		int GetDatePart(int part)  const;

		static bool IsLeapYear(int year);

		Int64 DateToTicks(int year, int month, int day)  const;

		Int64 TimeToTicks(int hour, int minute, int second)  const;

		DateTime Add(double value, Int64 scale)  const;

	public:

		static DateTime const MinValue;
		static DateTime const MaxValue;


		/// <summary>
		/// ��ȡ��ǰ����ʱ��
		/// </summary>
		/// <returns></returns>
		__uref static DateTime Now();

		/// <summary>
		/// ��ȡ��ǰЭ��ʱ����ʱ��
		/// </summary>
		/// <returns></returns>
		__uref static DateTime UtcNow();

		/// <summary>
		/// ��ȡ���ڣ����ڣ�
		/// </summary>
		/// <param name="loc">��������Ϣ</param>
		/// <returns></returns>
		__uref System::DayOfWeek GetDayOfWeek(const CultureInfo& loc) const;

		/// <summary>
		/// ��ȡ������ָ���·�λ��
		/// </summary>
		/// <param name="year">���</param>
		/// <param name="year">�·�</param>
		/// <returns></returns>
		__uref static int DaysInMonth(int year, int month);

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		DateTime GetDate() const;

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		int GetDay() const;

		/// <summary>
		/// ��ȡ����( �꣩
		/// </summary>
		/// <returns></returns>
		int GetDayOfYear() const;

		/// <summary>
		/// ��ȡ����( �£�
		/// </summary>
		/// <returns></returns>
		int GetDayOfMonth() const;

		/// <summary>
		/// ��ȡСʱ��
		/// </summary>
		/// <returns></returns>
		int GetHour() const;

		/// <summary>
		/// ��ȡ����ʱ������
		/// </summary>
		/// <returns></returns>
		DateTimeKind GetKind() const;

		/// <summary>
		/// ����ָ������ʱ�����͵�
		/// </summary>
		/// <param name="value">ָ������ʱ�����</param>
		/// <param name="kind">ָ������ʱ������.</param>
		/// <returns></returns>
		__uref static DateTime SpecifyKind(const DateTime& value, DateTimeKind kind);

		/// <summary>
		/// ��ȡ΢����
		/// </summary>
		/// <returns></returns>
		int GetMicrosecond() const;

		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		int GetMillisecond() const;

		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		int GetMinute() const;

		/// <summary>
		/// ��ȡ���
		/// </summary>
		/// <returns></returns>
		int GetYear() const;

		/// <summary>
		/// ��ȡ���
		/// </summary>
		/// <returns></returns>
		int GetMonth() const;

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		int GetSecond() const;

		/// <summary>
		/// ��ȡ��΢����
		/// </summary>
		/// <returns></returns>
		long long GetTicks() const;

		/// <summary>
		/// ������΢����
		/// </summary>
		/// <returns></returns>
		void SetTicks(long long ticks);

		/// <summary>
		/// ��ȡ��ǰ������ʱ��
		/// </summary>
		/// <returns></returns>
		TimeSpan GetTimeOfDay() const;

		/// <summary>
		/// ��ȡ�Ƿ����ģ����̬ʱ��������ʱ
		/// </summary>
		/// <returns></returns>
		bool GetIsAmbiguousDaylightSavingTime()const;

		/// <summary>
		/// ����<see cref="DateTime"/>ʵ��.
		/// </summary>
		__uref DateTime();

		/// <summary>
		///  ����<see cref="DateTime"/>ʵ��.
		/// </summary>
		/// <param name="ticks">ʱ�䣨΢�룩</param>
		__uref DateTime(long long ticks);

		/// <summary>
		///  ����<see cref="DateTime"/>ʵ��.
		/// </summary>
		/// <param name="ticks">ʱ�䣨΢�룩</param>
		/// <param name="isAmbiguousDst">����ģ����̬ʱ��</param>
		__uref DateTime(long long ticks, bool isAmbiguousDst);

		/// <summary>
		/// ����<see cref="DateTime"/>ʵ��.
		/// </summary>
		/// <param name="ticks">ʱ�䣨΢�룩</param>
		/// <param name="kind">����ʱ������</param>
		__uref DateTime(long long ticks, DateTimeKind kind);

		/// <summary>
		/// I����<see cref="DateTime"/>ʵ��.
		/// </summary>
		/// <param name="year">���.</param>
		/// <param name="month">�·�</param>
		/// <param name="day">����</param>
		__uref DateTime(int year, int month, int day);

		/// <summary>
		/// ����<see cref="DateTime"/>ʵ��.
		/// </summary>
		/// <param name="year">���</param>
		/// <param name="month">�·�</param>
		/// <param name="day">����</param>
		/// <param name="hour">Сʱ��</param>
		/// <param name="minute">������</param>
		/// <param name="second">����</param>
		__uref DateTime(int year, int month, int day, int hour, int minute, int second);

		/// <summary>
		/// ����<see cref="DateTime"/>ʵ��.
		/// </summary>
		/// <param name="year">���</param>
		/// <param name="month">�·�</param>
		/// <param name="day">����</param>
		/// <param name="hour">Сʱ��</param>
		/// <param name="minute">������</param>
		/// <param name="second">����</param>
		/// <param name="kind">����ʱ������</param>
		__uref DateTime(int year, int month, int day, int hour, int minute, int second, DateTimeKind kind);

		/// <summary>
		/// ����<see cref="DateTime"/>ʵ��.
		/// </summary>
		/// <param name="year">���</param>
		/// <param name="month">�·�</param>
		/// <param name="day">����</param>
		/// <param name="hour">Сʱ��</param>
		/// <param name="minute">������</param>
		/// <param name="second">����</param>
		/// <param name="millisecond">������</param>
		__uref DateTime(int year, int month, int day, int hour, int minute, int second, int millisecond);

		/// <summary>
		/// ����<see cref="DateTime"/>ʵ��.
		/// </summary>
		/// <param name="year">���</param>
		/// <param name="month">�·�</param>
		/// <param name="day">����</param>
		/// <param name="hour">Сʱ��</param>
		/// <param name="minute">������</param>
		/// <param name="second">����</param>
		/// <param name="millisecond">������</param>
		/// <param name="kind">����ʱ������</param>
		__uref DateTime(int year, int month, int day, int hour, int minute, int second, int millisecond, DateTimeKind kind);

		/// <summary>
		/// ����<see cref="DateTime"/>ʵ��.
		/// </summary>
		/// <param name="year">���</param>
		/// <param name="month">�·�</param>
		/// <param name="day">����</param>
		/// <param name="hour">Сʱ��</param>
		/// <param name="minute">������</param>
		/// <param name="second">����</param>
		/// <param name="millisecond">������</param>
		/// <param name="microsecond">΢����</param>
		__uref DateTime(int year, int month, int day, int hour, int minute, int second, int millisecond, int microsecond);

		/// <summary>
		/// ����<see cref="DateTime"/>ʵ��.
		/// </summary>
		/// <param name="year">���</param>
		/// <param name="month">�·�</param>
		/// <param name="day">����</param>
		/// <param name="hour">Сʱ��</param>
		/// <param name="minute">������</param>
		/// <param name="second">����</param>
		/// <param name="millisecond">������</param>
		/// <param name="microsecond">΢����</param>
		/// <param name="kind">����ʱ������</param>
		__uref DateTime(int year, int month, int day, int hour, int minute, int second, int millisecond, int microsecond, DateTimeKind kind);

		DateTime AddDays(double value) const;

		DateTime AddHours(double value) const;

		DateTime AddMilliseconds(double value) const;

		DateTime AddMinutes(double value) const;

		DateTime AddMonths(int months) const;

		DateTime AddSeconds(double value) const;

		DateTime AddTicks(Int64 value) const;

		DateTime AddYears(int value) const;

		DateTime ToUniversalTime() const;

		/// <summary>
		/// �Ƿ����ģ����̬ʱ��������ʱ
		/// </summary>
		__uproperty(get = GetIsAmbiguousDaylightSavingTime) bool IsAmbiguousDaylightSavingTime;

		/// <summary>
		/// ����ʱ������
		/// </summary>
		__uproperty(get = GetKind) DateTimeKind Kind;

		/// <summary>
		/// ��΢����
		/// </summary>
		__uproperty(get = GetTicks, put = SetTicks) long long Ticks;

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		__uproperty(get = GetDate) DateTime Date;

		/// <summary>
		/// ���
		/// </summary>
		__uproperty(get = GetYear) int Year;
		/// <summary>
		/// �·�
		/// </summary>
		__uproperty(get = GetMonth) int Month;
		/// <summary>
		/// ����
		/// </summary>
		__uproperty(get = GetDay) int Day;
		/// <summary>
		/// Сʱ��
		/// </summary>
		__uproperty(get = GetHour) int Hour;
		/// <summary>
		/// ������
		/// </summary>
		__uproperty(get = GetMinute) int Minute;
		/// <summary>
		/// ����
		/// </summary>
		__uproperty(get = GetSecond) int Second;
		/// <summary>
		/// ������
		/// </summary>
		__uproperty(get = GetMillisecond) int Millisecond;
		/// <summary>
		/// ΢����
		/// </summary>
		__uproperty(get = GetMicrosecond) int Microsecond;
		/// <summary>
		/// �������£�
		/// </summary>
		__uproperty(get = GetDayOfMonth) int DayOfMonth;
		/// <summary>
		/// �������꣩
		/// </summary>
		__uproperty(get = GetDayOfYear) int DayOfYear;
		/// <summary>
		/// ʱ�䣨�죩
		/// </summary>
		__uproperty(get = GetTimeOfDay) TimeSpan TimeOfDay;

		__uref DateTime(const DateTime& dateTime);

		__uref DateTime & operator=(const DateTime & dateTime);

		__uref DateTime operator + (const DateTime& dateTime) const;

		__uref DateTime operator - (const DateTime& dateTime) const;

		__uref DateTime operator + (const TimeSpan& timeSpan) const;

		__uref DateTime operator - (const TimeSpan& timeSpan) const;

		__uref DateTime& operator += (DateTime& dateTime);

		__uref DateTime& operator -= (DateTime& dateTime);

		__uref DateTime& operator += (TimeSpan& timeSpan);

		__uref DateTime& operator -= (TimeSpan& timeSpan);

		__uref bool operator == (DateTime&  dateTime) const;

		__uref bool operator == (const DateTime&  dateTime) const;

		__uref bool operator != (DateTime&  dateTime) const;

		__uref bool operator != (const DateTime&  dateTime) const;

		__uref bool operator > (const DateTime&  dateTime) const;

		__uref bool operator < (const DateTime&  dateTime) const;

		__uref bool operator >=(const DateTime&  dateTime) const;

		__uref bool operator <= (const DateTime&  dateTime) const;
		
		/// <summary>
		/// ���Դ���<see cref="DateTime"/>ʵ��
		/// </summary>
		/// <param name="year">���</param>
		/// <param name="month">�·�</param>
		/// <param name="day">����</param>
		/// <param name="hour">Сʱ��</param>
		/// <param name="minute">������</param>
		/// <param name="second">����</param>
		/// <param name="millisecond">������</param>
		/// <param name="microsecond">΢����</param>
		/// <param name="kind">����ʱ������</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		static bool TryCreate(int year, int month, int day, int hour, int minute, int second, int millisecond, int microsecond, DateTimeKind kind, DateTime& result);

		/// <summary>
		/// ���Խ���
		/// </summary>
		/// <param name="input">����ֵ.</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		static bool TryParse(const std::wstring& input, const CultureInfo& loc, DateTime& result);

		/// <summary>
		/// ���Խ���
		/// </summary>
		/// <param name="input">����ֵ.</param>
		/// <param name="format">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="style">ָ�����</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		static bool TryParseExact(const std::wstring& input, const std::wstring& format, const CultureInfo& loc, DateTimeStyles style, DateTime& result);

		/// <summary>
		/// ���Խ���
		/// </summary>
		/// <param name="input">����ֵ.</param>
		/// <param name="formats">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="style">ָ�����</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		static bool TryParseExactMultiple(const std::wstring& input, const std::vector<std::wstring>& formats, const CultureInfo& loc, DateTimeStyles style, DateTime& result);

		REFLECT_CLASS(DateTime)
	};

	class RUNTIME_API DateTimeConverter : public TypeConverter
	{
	private:
		static std::mutex& getlocker();
		static std::weak_ptr<DateTimeConverter> _thisWeakPtr;
	protected:
		DateTimeConverter();
		DateTimeConverter(DateTimeConverter const&);
		void operator=(DateTimeConverter const&);
	public:
		virtual ~DateTimeConverter();

		static std::shared_ptr<DateTimeConverter> GetSharedInstance();

		static DateTimeConverter& GetInstance();

		bool CanConvertFrom(_type type) const;
		bool CanConvertTo(_type type) const;

		Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
		Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

		Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
		std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
	};

}