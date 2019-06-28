#pragma once
#include "Calendar.h"

namespace System
{
	/// <summary>
	/// ��˹������
	/// </summary>
	 class RUNTIME_API PersianCalendar : public Calendar
	{
	protected:
		friend class CalendarHelper;

		Calendar* InstanceClone() const override;

		virtual int GetDatePart(Int64 ticks, int part) const;

		Int64 DaysUpToPersianYear(int PersianYear) const;

		Int64 GetAbsoluteDatePersian(int year, int month, int day) const;

	public:

		/// <summary>
		/// ��ȡ�㷨����
		/// </summary>
		/// <returns></returns>
		CalendarAlgorithmType GetAlgorithmType() const override;

		/// <summary>
		/// ��ȡ����������ʶ
		/// </summary>
		/// <returns></returns>
		int GetBaseCalendarID() const override;

		/// <summary>
		/// ��ȡ��ǰ�����еļ�Ԫ�б�
		/// </summary>
		/// <returns></returns>
		std::vector<int> GetEras() const override;

		/// <summary>
		/// ��ȡ������ʶ
		/// </summary>
		/// <returns></returns>
		int GetID() const override;

		/// <summary>
		/// ��ȡ֧�ֵ���������ʱ��
		/// </summary>
		/// <returns></returns>
		DateTime GetMaxSupportedDateTime() const override;

		/// <summary>
		/// ��ȡ֧�ֵ���������ʱ��
		/// </summary>
		/// <returns></returns>
		DateTime GetMinSupportedDateTime() const override;

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
		void SetTwoDigitYearMax(int value) override;

		/// <summary>
		/// ����<see cref="PersianCalendar"/>ʵ��.
		/// </summary>
		PersianCalendar();

		virtual ~PersianCalendar();

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
		int GetDayOfMonth(const DateTime& time) const override;

		/// <summary>
		/// ��ȡ��ָ������ʱ�������ڼ�
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		DayOfWeek GetDayOfWeek(const DateTime& time) const override;

		/// <summary>
		/// ��ȡ��ָ������ʱ���Ǹ���ڼ���
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		int GetDayOfYear(const DateTime& time) const override;

		/// <summary>
		/// ��ȡָ����Ԫ��ָ���·ݺ�����е�����
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <param name="era">ָ����Ԫ</param>
		/// <returns></returns>	
		int GetDaysInMonth(int year, int month, int era) const override;

		/// <summary>
		/// ��ȡָ����Ԫ��ָ������е�����
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="era">ָ����Ԫ</param>
		/// <returns></returns>	
		int GetDaysInYear(int year, int era) const override;

		/// <summary>
		/// ��ȡָ������ʱ��ļ�Ԫֵ
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		int GetEra(const DateTime& time) const override;

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
		/// ��ȡָ����Ԫ��ָ����ݵ�������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="era">ָ����Ԫ</param>
		/// <returns></returns>
		int GetMonthsInYear(int year, int era) const override;

		/// <summary>
		/// ��ȡָ������ʱ������
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		int GetYear(const DateTime& time) const override;

		/// <summary>
		/// �ж�ָ����Ԫ�е�ָ��������������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <param name="day">ָ������</param>
		/// <param name="era">ָ����Ԫֵ</param>
		/// <returns></returns>	
		bool IsLeapDay(int year, int month, int day, int era) const override;

		/// <summary>
		/// �ж�ָ����Ԫ�е�ָ������������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <param name="era">ָ����Ԫֵ</param>
		/// <returns></returns>	
		bool IsLeapMonth(int year, int month, int era) const override;

		/// <summary>
		/// �ж�ָ����Ԫ�е�ָ�����������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="era">ָ����Ԫֵ</param>
		/// <returns></returns>	
		bool IsLeapYear(int year, int era) const override;

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
		DateTime ToDateTime(int year, int month, int day, int hour, int minute, int second, int millisecond, int era) const override;

		/// <summary>
		/// ����ָ����ݶ�Ӧ����λ�����
		/// </summary>
		/// <returns></returns>	
		int ToFourDigitYear(int year) const override;

		REFLECT_CLASS(PersianCalendar)
	};
}