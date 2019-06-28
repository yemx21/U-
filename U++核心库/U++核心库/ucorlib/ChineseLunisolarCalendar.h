#pragma once

#include "EastAsianLunisolarCalendar.h"

namespace System
{
	/// <summary>
	/// �й���������
	/// </summary>
	 class RUNTIME_API ChineseLunisolarCalendar : public EastAsianLunisolarCalendar
	{
	protected:
		friend class CalendarHelper;

		void GetCalEraInfo(std::vector<EraInfo>&) const override;

		int GetMaxCalendarYear() const override;

		DateTime GetMaxDate() const override;

		int GetMinCalendarYear()const override;

		DateTime GetMinDate() const override;

		int GetGregorianYear(int year, int era) const override;

		int GetYear(int year, const DateTime& time) const override;

		int GetYearInfo(int LunarYear, int Index) const override;

		Calendar* InstanceClone() const override;
	public:

		/// <summary>
		/// ��ȡ����������ʶ
		/// </summary>
		/// <returns></returns>
		int GetBaseCalendarID() const override;

		/// <summary>
		/// ��ȡ��С֧�����ǰ��������
		/// </summary>
		/// <returns></returns>
		int GetDaysInYearBeforeMinSupportedYear() const override;

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
		/// ����<see cref="ChineseLunisolarCalendar"/>ʵ��.
		/// </summary>
		ChineseLunisolarCalendar();

		virtual ~ChineseLunisolarCalendar();

		/// <summary>
		/// ��ȡָ������ʱ��ļ�Ԫֵ
		/// </summary>
		/// <param name="time">ָ������ʱ��</param>
		/// <returns></returns>	
		int GetEra(const DateTime& time) const override;

		REFLECT_CLASS(ChineseLunisolarCalendar)
	};
}