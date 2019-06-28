#pragma once

#include "Calendar.h"

namespace System
{
	/// <summary>
	/// ��������ö��
	/// </summary>
	enum class GregorianCalendarTypes
	{
		/// <summary>
		/// ���ػ�
		/// </summary>
		Localized = 1,
		/// <summary>
		/// ����Ӣ��
		/// </summary>
		USEnglish = 2,
		/// <summary>
		/// �ж�����
		/// </summary>
		MiddleEastFrench = 9,
		/// <summary>
		/// ������
		/// </summary>
		Arabic = 10,
		/// <summary>
		/// ת��Ӣ��
		/// </summary>
		TransliteratedEnglish = 11,
		/// <summary>
		/// ת�뷨��
		/// </summary>
		TransliteratedFrench = 12
	};

	class HebrewCalendar;
	class UmAlQuraCalendar;

	/// <summary>
	/// ��������
	/// </summary>
	 class  RUNTIME_API GregorianCalendar : public Calendar
	{
	private:
		GregorianCalendarTypes m_type;

	protected:
		friend class CalendarHelper;

		virtual Int64 DateToTicks(int year, int month, int day)  const;

		virtual int GetDatePart(Int64 ticks, int part)  const;

		bool TryToDateTime(int year, int month, int day, int hour, int minute, int second, int millisecond, int era, DateTime& result) const override;

		Calendar* InstanceClone() const override;

	public:

		/// <summary>
		/// ��ȡָ�������յ�ʱ�����ֵ
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <param name="day">ָ������</param>
		/// <returns></returns>	
		static Int64 GetAbsoluteDate(int year, int month, int day);


		/// <summary>
		/// ��ȡ�㷨����
		/// </summary>
		/// <returns></returns>
		CalendarAlgorithmType GetAlgorithmType() const override;

		/// <summary>
		/// ��ȡ��������
		/// </summary>
		/// <returns></returns>
		virtual GregorianCalendarTypes GetCalendarType() const;

		/// <summary>
		/// ���ù�������
		/// </summary>
		/// <param name="value">��������</param>
		/// <returns></returns>
		virtual void SetCalendarType(GregorianCalendarTypes value);

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
		/// ����<see cref="GregorianCalendar"/>ʵ��
		/// </summary>
		/// <param name="type">��������</param>
		GregorianCalendar(GregorianCalendarTypes type);

		/// <summary>
		/// ����<see cref="GregorianCalendar"/>ʵ��
		/// </summary>
		GregorianCalendar();

		virtual ~GregorianCalendar();

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
		int GetDayOfYear(const DateTime& time) const  override;

		/// <summary>
		/// ��ȡָ����Ԫ��ָ���·ݺ�����е�����
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <param name="era">ָ����Ԫ</param>
		/// <returns></returns>	
		int GetDaysInMonth(int year, int month, int era) const  override;

		/// <summary>
		/// ��ȡָ����Ԫ��ָ������е�����
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="era">ָ����Ԫ</param>
		/// <returns></returns>	
		int GetDaysInYear(int year, int era) const  override;

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
		int GetLeapMonth(int year, int era) const  override;

		/// <summary>
		/// ��ȡָ������ʱ����·�
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		int GetMonth(const DateTime& time) const  override;

		/// <summary>
		/// ��ȡָ����Ԫ��ָ����ݵ�������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="era">ָ����Ԫ</param>
		/// <returns></returns>	
		int GetMonthsInYear(int year, int era) const  override;

		/// <summary>
		/// ��ȡָ������ʱ������
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		int GetYear(const DateTime& time)  const override;

		/// <summary>
		/// �ж�ָ����Ԫ�е�ָ��������������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <param name="day">ָ������</param>
		/// <param name="era">ָ����Ԫֵ</param>
		/// <returns></returns>	
		bool IsLeapDay(int year, int month, int day, int era) const  override;

		/// <summary>
		/// �ж�ָ����Ԫ�е�ָ������������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="month">ָ���·�</param>
		/// <param name="era">ָ����Ԫֵ</param>
		/// <returns></returns>	
		bool IsLeapMonth(int year, int month, int era) const  override;

		/// <summary>
		/// �ж�ָ����Ԫ�е�ָ�����������
		/// </summary>
		/// <param name="year">ָ�����</param>
		/// <param name="era">ָ����Ԫֵ</param>
		/// <returns></returns>	
		bool IsLeapYear(int year, int era) const  override;

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
		int ToFourDigitYear(int year)  const override;


		REFLECT_CLASS(GregorianCalendar)
	};
}