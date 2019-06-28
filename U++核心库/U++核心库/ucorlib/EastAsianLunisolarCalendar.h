#pragma once
#include "Calendar.h"
#include "GregorianCalendar.h"
namespace System
{
	/// <summary>
	/// ������������
	/// </summary>
	 class  RUNTIME_API EastAsianLunisolarCalendar : public Calendar
	{
	protected:
		friend class CalendarHelper;

		virtual void GetCalEraInfo(std::vector<EraInfo>&) const = 0;

		virtual int GetMaxCalendarYear() const = 0;

		virtual DateTime GetMaxDate() const = 0;

		virtual int GetMinCalendarYear() const = 0;

		virtual DateTime GetMinDate() const = 0;

		EastAsianLunisolarCalendar();

		void CheckEraRange(int era) const;

		void CheckTicksRange(Int64 ticks) const;

		int CheckYearMonthRange(int year, int month, int era) const;

		int CheckYearRange(int year, int era) const;

		int GetCelestialStem(int sexagenaryYear) const;

		virtual int GetGregorianYear(int year, int era) const = 0;

		virtual int GetSexagenaryYear(const DateTime& time) const;

		int GetTerrestrialBranch(int sexagenaryYear) const;

		virtual int GetYear(int year, const DateTime& time) const = 0;

		virtual int GetYearInfo(int LunarYear, int Index) const = 0;
	public:

		/// <summary>
		/// ��ȡ�㷨����
		/// </summary>
		/// <returns></returns>
		CalendarAlgorithmType GetAlgorithmType() const override;

		/// <summary>
		/// ��ȡ������λ����ݱ�ʾ�� 100 �귶Χ�ڵ����һ��
		/// </summary>
		/// <returns></returns>
		int GetTwoDigitYearMax() const override;

		/// <summary>
		/// ���ÿ�����λ����ݱ�ʾ�� 100 �귶Χ�ڵ����һ��
		/// </summary>
		/// <param name="value">���</param>
		/// <returns></returns>
		void SetTwoDigitYearMax(int value)  override;

		virtual ~EastAsianLunisolarCalendar();

		/// <summary>
		/// ��ȡ��ָ������ʱ�����ָ������������ʱ��
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <param name="months">ָ������</param>
		/// <returns></returns>
		DateTime AddMonths(const DateTime& time, int months) override;

		/// <summary>
		/// ��ȡ��ָ������ʱ�����ָ������������ʱ��
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <param name="years">ָ������</param>
		/// <returns></returns>
		DateTime AddYears(const DateTime& time, int years) override;

		/// <summary>
		/// ��ȡ��ָ������ʱ���Ǹ��µļ���
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		int GetDayOfMonth(const DateTime& time)  const override;

		/// <summary>
		/// ��ȡ��ָ������ʱ�������ڼ�
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		DayOfWeek GetDayOfWeek(const DateTime& time)  const override;

		/// <summary>
		/// ��ȡ��ָ������ʱ���Ǹ���ڼ���
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		int GetDayOfYear(const DateTime& time)  const override;

		/// <summary>
		/// ��ȡָ����Ԫ��ָ���·ݺ�����е�����
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <param name="era">ָ����Ԫ</param>
		/// <returns></returns>	
		int GetDaysInMonth(int year, int month, int era)  const override;

		/// <summary>
		/// ��ȡָ����Ԫ��ָ������е�����
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="era">ָ����Ԫ</param>
		/// <returns></returns>	
		int GetDaysInYear(int year, int era)  const override;

		/// <summary>
		/// ��ȡָ����Ԫ��ָ����ݵ�����
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="era">ָ����Ԫ</param>
		/// <returns></returns>	
		int GetLeapMonth(int year, int era) const override;

		/// <summary>
		/// ��ȡָ������ʱ����·�
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		int GetMonth(const DateTime& time) const override;

		/// <summary>
		/// ��ȡ��ǰ��Ԫ��ָ����ݵ�������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <returns></returns>	
		int GetMonthsInYear(int year, int era) const override;

		/// <summary>
		/// ��ȡָ������ʱ������
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		int GetYear(const DateTime& time)  const override;

	private:
		static int GregorianIsLeapYear(int y);

		void GregorianToLunar(int nSYear, int nSMonth, int nSDate, int& nLYear, int& nLMonth, int& nLDate) const;

		int InternalGetDaysInMonth(int year, int month) const;

		bool InternalIsLeapYear(int year) const;

		bool IsLeapDay(int year, int month, int day, int era)  const override;

		bool IsLeapMonth(int year, int month, int era)  const override;

		bool IsLeapYear(int year, int era)  const override;

		bool LunarToGregorian(int nLYear, int nLMonth, int nLDate, int& nSolarYear, int& nSolarMonth, int& nSolarDay) const;

		DateTime LunarToTime(const DateTime& time, int year, int month, int day) const;

		int MaxEraCalendarYear(int era) const;

		int MinEraCalendarYear(int era) const;

		void TimeToLunar(const DateTime& time, int& year, int& month, int& day) const;

		DateTime ToDateTime(int year, int month, int day, int hour, int minute, int second, int millisecond, int era)  const override;

		int ToFourDigitYear(int year)  const override;

		REFLECT_CLASS(EastAsianLunisolarCalendar)
	};
}