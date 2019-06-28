#pragma once
#include "DateTime.h"



namespace System
{	
	/// <summary>
	/// �����㷨����ö��
	/// </summary>
	class RUNTIME_API CalendarAlgorithmType : __uobject
	{
		__uvalue_begin(CalendarAlgorithmType, UShort)
		/// <summary>
		/// δ֪
		/// </summary>
		__uvalue(Unknown)
		/// <summary>
		/// ����
		/// </summary>
			__uvalue(SolarCalendar)
		/// <summary>
		/// ����
		/// </summary>
		__uvalue(LunarCalendar)
		/// <summary>
		/// ������
		/// </summary>
			__uvalue(LunisolarCalendar)
		__uvalue_end(CalendarAlgorithmType, Unknown)
	};

	/// <summary>
	/// ��ݵ�һ�ܹ���ö��
	/// </summary>
	class RUNTIME_API CalendarWeekRule : __uobject
	{
		__uvalue_begin(CalendarWeekRule, UShort)
		/// <summary>
		/// ��һ�ܴӸ���ĵ�һ�쿪ʼ������ָ���ܵ���һ������ǰ����
		/// </summary>
		__uvalue(FirstDay)
		/// <summary>
		/// ��һ�ܴ���ָ�������յĵ�һ��ƥ���ʼ����������ĵ�һ������ĳһ��
		/// </summary>
		__uvalue(FirstFullWeek)
		/// <summary>
		/// ��һ���ǵ�һ����ָ����������ǰ�����������������
		/// </summary>
		__uvalue(FirstFourDayWeek)
		__uvalue_end(CalendarWeekRule, FirstDay)
	};

	class CalendarData;

	/// <summary>
	/// ��Ԫ�����Ϣ
	/// </summary>
	class RUNTIME_API EraInfo
	{
	public:
		/// <summary>
		/// ��Ԫֵ
		/// </summary>
		int era;

		/// <summary>
		/// ʱ��ֵ
		/// </summary>
		Int64 ticks;

		/// <summary>
		/// ���ƫ��
		/// </summary>
		int yearOffset;

		/// <summary>
		/// ��С��Ԫ���
		/// </summary>
		int minEraYear;

		/// <summary>
		/// ����Ԫ���
		/// </summary>
		int maxEraYear;

		/// <summary>
		/// ��Ԫ����
		/// </summary>
		std::wstring eraName;

		/// <summary>
		/// ��Ԫ���ƣ���д��
		/// </summary>
		std::wstring abbrevEraName;

		/// <summary>
		/// ��Ԫ���ƣ�Ӣ�ģ�
		/// </summary>
		std::wstring englishEraName;

		/// <summary>
		/// ����<see cref="EraInfo"/>ʵ��.
		/// </summary>
		/// <param name="era">��Ԫֵ</param>
		/// <param name="startYear">��ʼ���</param>
		/// <param name="startMonth">��ʼ����</param>
		/// <param name="startDay">��ʼ����</param>
		/// <param name="yearOffset">���ƫ��</param>
		/// <param name="minEraYear">��С��Ԫ���</param>
		/// <param name="maxEraYear">����Ԫ���</param>
		EraInfo(int era, int startYear, int startMonth, int startDay, int yearOffset, int minEraYear, int maxEraYear);

		/// <summary>
		/// ����<see cref="EraInfo"/>ʵ��.
		/// </summary>
		/// <param name="era">��Ԫֵ</param>
		/// <param name="startYear">��ʼ���</param>
		/// <param name="startMonth">��ʼ����</param>
		/// <param name="startDay">��ʼ����</param>
		/// <param name="yearOffset">���ƫ��</param>
		/// <param name="minEraYear">��С��Ԫ���</param>
		/// <param name="maxEraYear">����Ԫ���</param>
		/// <param name="eraName">��Ԫ����</param>
		/// <param name="abbrevEraName">��Ԫ���ƣ���д��</param>
		/// <param name="englishEraName">��Ԫ���ƣ�Ӣ�ģ�</param>
		EraInfo(int era, int startYear, int startMonth, int startDay, int yearOffset, int minEraYear, int maxEraYear, const std::wstring& eraName, const std::wstring& abbrevEraName, const std::wstring& englishEraName);

		EraInfo(const EraInfo& info);
	};

	class GregorianCalendarHelper;

	class DateTimeParse;

	class CalendarHelper;

	/// <summary>
	/// ������
	/// </summary>
	 class RUNTIME_API Calendar : __uobject, _noncopyable
	{
	private:
		mutable int m_currentEraValue;
		bool m_isReadOnly;
		void SetReadOnlyState(bool readOnly);
	protected:

		friend class GregorianCalendarHelper;
		friend class DateTimeParse;
		friend class CalendarHelper;

		mutable int twoDigitYearMax;
		Calendar();

		DateTime Add(const DateTime& time, double value, int scale);

		static void CheckAddResult(Int64 ticks, const DateTime& minValue, const DateTime& maxValue);

		int GetFirstDayWeekOfYear(const DateTime& time, int firstDayOfWeek) const;

		static int GetSystemTwoDigitYearSetting(int CalID, int defaultYearValue);

		virtual int GetWeekOfYear(const DateTime& time, CalendarWeekRule rule, DayOfWeek firstDayOfWeek) const;

		int GetWeekOfYearFullDays(const DateTime& time, int firstDayOfWeek, int fullDays) const;

		int GetWeekOfYearOfMinSupportedDateTime(int firstDayOfWeek, int minimumDaysInFirstWeek) const;

		virtual bool IsValidDay(int year, int month, int day, int era) const;

		virtual bool IsValidMonth(int year, int month, int era)const;

		virtual bool IsValidYear(int year, int era)const;

		static Int64 TimeToTicks(int hour, int minute, int second, int millisecond);

		virtual bool TryToDateTime(int year, int month, int day, int hour, int minute, int second, int millisecond, int era, DateTime& result) const;

		/// <summary>
		/// ��ȡ��ǰ�����������ȸ���
		/// </summary>
		/// <returns></returns>	
		virtual Calendar* InstanceClone() const = 0;

		void VerifyWritable();

	public:

		/// <summary>
		/// ��ȡ�㷨����
		/// </summary>
		/// <returns></returns>
		virtual CalendarAlgorithmType GetAlgorithmType() const;

		/// <summary>
		/// ��ȡ����������ʶ
		/// </summary>
		/// <returns></returns>
		virtual int GetBaseCalendarID() const;

		/// <summary>
		/// ��ȡ��ǰ��Ԫֵ
		/// </summary>
		/// <returns></returns>
		virtual int GetCurrentEraValue() const;

		virtual ~Calendar();

		/// <summary>
		/// ��ȡ��С֧�����ǰ��������
		/// </summary>
		/// <returns></returns>
		virtual int GetDaysInYearBeforeMinSupportedYear() const;

		/// <summary>
		/// ��ȡ��ǰ�����еļ�Ԫ�б�
		/// </summary>
		/// <returns></returns>
		virtual std::vector<int>GetEras() const = 0;

		/// <summary>
		/// ��ȡ������ʶ
		/// </summary>
		/// <returns></returns>
		virtual int GetID() const;

		/// <summary>
		/// ��ȡ��ǰ�����Ƿ�Ϊֻ��
		/// </summary>
		/// <returns></returns>
		bool GetIsReadOnly() const;

		/// <summary>
		/// ��ȡ֧�ֵ���������ʱ��
		/// </summary>
		/// <returns></returns>
		virtual DateTime GetMaxSupportedDateTime() const;

		/// <summary>
		/// ��ȡ֧�ֵ���������ʱ��
		/// </summary>
		/// <returns></returns>
		virtual DateTime GetMinSupportedDateTime() const;

		/// <summary>
		/// ��ȡ������λ����ݱ�ʾ�� 100 �귶Χ�ڵ����һ��
		/// </summary>
		/// <returns></returns>
		virtual int GetTwoDigitYearMax() const;

		/// <summary>
		/// ���ÿ�����λ����ݱ�ʾ�� 100 �귶Χ�ڵ����һ��
		/// </summary>
		/// <param name="value">���</param>
		/// <returns></returns>
		virtual void SetTwoDigitYearMax(int value);

		/// <summary>
		/// ��ȡ��ָ������ʱ�����ָ������������ʱ��
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <param name="days">ָ������</param>
		/// <returns></returns>
		virtual DateTime AddDays(const DateTime& time, int days);

		/// <summary>
		/// ��ȡ��ָ������ʱ�����ָ��Сʱ��������ʱ��
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <param name="hours">ָ��Сʱ��</param>
		/// <returns></returns>
		virtual DateTime AddHours(const DateTime& time, int hours);

		/// <summary>
		/// ��ȡ��ָ������ʱ�����ָ��������������ʱ��
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <param name="milliseconds">ָ��������</param>
		/// <returns></returns>
		virtual DateTime AddMilliseconds(const DateTime& time, double milliseconds);

		/// <summary>
		/// ��ȡ��ָ������ʱ�����ָ��������������ʱ��
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <param name="minutes">ָ��������</param>
		/// <returns></returns>
		virtual DateTime AddMinutes(const DateTime& time, int minutes);

		/// <summary>
		/// ��ȡ��ָ������ʱ�����ָ������������ʱ��
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <param name="months">ָ������</param>
		/// <returns></returns>
		virtual DateTime AddMonths(const DateTime& time, int months) = 0;

		/// <summary>
		/// ��ȡ��ָ������ʱ�����ָ������������ʱ��
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <param name="seconds">ָ������</param>
		/// <returns></returns>
		virtual DateTime AddSeconds(const DateTime& time, int seconds);

		/// <summary>
		/// ��ȡ��ָ������ʱ�����ָ������������ʱ��
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <param name="weeks">ָ������</param>
		/// <returns></returns>
		virtual DateTime AddWeeks(const DateTime& time, int weeks);

		/// <summary>
		/// ��ȡ��ָ������ʱ�����ָ������������ʱ��
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <param name="years">ָ������</param>
		/// <returns></returns>
		virtual DateTime AddYears(const DateTime& time, int years) = 0;

		/// <summary>
		/// ��ȡ��ָ������ʱ���Ǹ��µļ���
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		virtual int GetDayOfMonth(const DateTime& time) const = 0;

		/// <summary>
		/// ��ȡ��ָ������ʱ�������ڼ�
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		virtual DayOfWeek GetDayOfWeek(const DateTime& time) const = 0;

		/// <summary>
		/// ��ȡ��ָ������ʱ���Ǹ���ڼ���
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		virtual int GetDayOfYear(const DateTime& time) const = 0;

		/// <summary>
		/// ��ȡ��ǰ��Ԫ��ָ���·ݺ�����е�����
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <returns></returns>	
		virtual int GetDaysInMonth(int year, int month) const;

		/// <summary>
		/// ��ȡָ����Ԫ��ָ���·ݺ�����е�����
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <param name="era">ָ����Ԫ</param>
		/// <returns></returns>	
		virtual int GetDaysInMonth(int year, int month, int era) const = 0;

		/// <summary>
		/// ��ȡ��ǰ��Ԫ��ָ������е�����
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <returns></returns>	
		virtual int GetDaysInYear(int year) const;

		/// <summary>
		/// ��ȡָ����Ԫ��ָ������е�����
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="era">ָ����Ԫ</param>
		/// <returns></returns>	
		virtual int GetDaysInYear(int year, int era) const = 0;

		/// <summary>
		/// ��ȡָ������ʱ��ļ�Ԫֵ
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		virtual int GetEra(const DateTime& time) const = 0;
		
		/// <summary>
		/// ��ȡָ������ʱ���Сʱ��
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		virtual int GetHour(const DateTime& time) const;

		/// <summary>
		/// ��ȡ�����Ǽ�Ԫ��ָ����ݵ�����
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <returns></returns>	
		virtual int GetLeapMonth(int year) const;

		/// <summary>
		/// ��ȡָ����Ԫ��ָ����ݵ�����
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="era">ָ����Ԫ</param>
		/// <returns></returns>	
		virtual int GetLeapMonth(int year, int era) const;

		/// <summary>
		/// ��ȡָ������ʱ��ĺ�����
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		virtual double GetMilliseconds(const DateTime& time) const;

		/// <summary>
		/// ��ȡָ������ʱ��ķ�����
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		virtual int GetMinute(const DateTime& time) const;

		/// <summary>
		/// ��ȡָ������ʱ����·�
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		virtual int GetMonth(const DateTime& time) const = 0;

		/// <summary>
		/// ��ȡ��ǰ��Ԫ��ָ����ݵ�������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <returns></returns>	
		virtual int GetMonthsInYear(int year)const;

		/// <summary>
		/// ��ȡָ����Ԫ��ָ����ݵ�������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="era">ָ����Ԫ</param>
		/// <returns></returns>	
		virtual int GetMonthsInYear(int year, int era) const = 0;

		/// <summary>
		/// ��ȡָ������ʱ��ķ�����
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		virtual int GetSecond(const DateTime& time)const;

		/// <summary>
		/// ��ȡָ������ʱ������
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		virtual int GetYear(const DateTime& time) const = 0;

		/// <summary>
		/// �жϵ�ǰ��Ԫ�е�ָ��������������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <param name="day">ָ������</param>
		/// <returns></returns>	
		virtual bool IsLeapDay(int year, int month, int day) const;

		/// <summary>
		/// �ж�ָ����Ԫ�е�ָ��������������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <param name="day">ָ������</param>
		/// <param name="era">ָ����Ԫֵ</param>
		/// <returns></returns>	
		virtual bool IsLeapDay(int year, int month, int day, int era) const = 0;

		/// <summary>
		/// �жϵ�ǰ��Ԫ�е�ָ������������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <returns></returns>	
		virtual bool IsLeapMonth(int year, int month) const;

		/// <summary>
		/// �ж�ָ����Ԫ�е�ָ������������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <param name="era">ָ����Ԫֵ</param>
		/// <returns></returns>	
		virtual bool IsLeapMonth(int year, int month, int era) const = 0;

		/// <summary>
		/// �жϵ�ǰ��Ԫ�е�ָ�����������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <returns></returns>	
		virtual bool IsLeapYear(int year) const;

		/// <summary>
		/// �ж�ָ����Ԫ�е�ָ�����������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="era">ָ����Ԫֵ</param>
		/// <returns></returns>	
		virtual bool IsLeapYear(int year, int era) const = 0;

		/// <summary>
		/// ��ȡָ�����������ֻ������
		/// </summary>
		/// <returns></returns>	
		static Calendar* GetReadOnly(const Calendar* calendar);

		/// <summary>
		/// ��ȡ��ǰ��������ķ�ֻ������
		/// </summary>
		/// <returns></returns>	
		Calendar* Clone() const;

		/// <summary>
		/// ���ص�ǰ��Ԫ�е�ָ�������պ�ʱ�������ʱ��
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <param name="day">ָ������</param>
		/// <param name="hour">ָ��Сʱ��</param>
		/// <param name="minute">ָ��������</param>
		/// <param name="second">ָ������</param>
		/// <param name="millisecond">ָ��������</param>
		/// <returns></returns>	
		virtual DateTime ToDateTime(int year, int month, int day, int hour, int minute, int second, int millisecond) const;

		/// <summary>
		/// ����ָ����Ԫ�е�ָ�������պ�ʱ�������ʱ��
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <param name="day">ָ������</param>
		/// <param name="hour">ָ��Сʱ��</param>
		/// <param name="minute">ָ��������</param>
		/// <param name="second">ָ������</param>
		/// <param name="millisecond">ָ��������</param>
		/// <param name="era">ָ����Ԫֵ</param>
		/// <returns></returns>	
		virtual DateTime ToDateTime(int year, int month, int day, int hour, int minute, int second, int millisecond, int era) const = 0;

		/// <summary>
		/// ����ָ����ݶ�Ӧ����λ�����
		/// </summary>
		/// <returns></returns>	
		virtual int ToFourDigitYear(int year) const;

		REFLECT_CLASS(Calendar)
	};

	
}