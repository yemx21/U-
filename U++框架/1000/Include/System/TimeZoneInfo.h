#pragma once
#include "TimeSpan.h"
#include "DateTime.h"
namespace System
{
	class TimeZoneInfo_impl;

	/// <summary>
	/// ʱ����Ϣ��
	/// </summary>
	class RUNTIME_API TimeZoneInfo final: __uobject
	{
	private:
		friend class TimeZoneInfo_impl;

		TimeZoneInfo_impl* impl;

		TimeZoneInfo();

	public:

		TimeZoneInfo(const TimeZoneInfo& info);

		TimeZoneInfo(TimeZoneInfo&& info);

		/// <summary>
		/// ��ȡЭ��ʱƫ��
		/// </summary>
		/// <returns></returns>
		TimeSpan GetBaseUtcOffset() const;

		/// <summary>
		/// ��ȡ����ʱ����
		/// </summary>
		/// <returns></returns>
		std::wstring GetDaylightName() const;

		/// <summary>
		/// ��ȡ��ʾ����
		/// </summary>
		/// <returns></returns>
		std::wstring GetDisplayName() const;

		/// <summary>
		/// ��ȡ��ʶ
		/// </summary>
		/// <returns></returns>
		std::wstring GetId() const;

		/// <summary>
		/// ��ȡ��׼����
		/// </summary>
		/// <returns></returns>
		std::wstring GetStandardName() const;

		/// <summary>
		/// ��ȡ�Ƿ�֧������ʱ
		/// </summary>
		/// <returns></returns>
		bool GetSupportsDaylightSavingTime() const;

		/// <summary>
		/// Э��ʱƫ��
		/// </summary>
		__uproperty(get = GetBaseUtcOffset) TimeSpan BaseUtcOffset;

		/// <summary>
		/// ����ʱ����
		/// </summary>
		__uproperty(get = GetDaylightName) std::wstring DaylightName;

		/// <summary>
		/// ��ȡ��ʾ����
		/// </summary>
		/// <returns></returns>
		__uproperty(get = GetDisplayName) std::wstring DisplayName;

		/// <summary>
		/// ��ȡ��ʶ
		/// </summary>
		/// <returns></returns>
		__uproperty(get = GetId) std::wstring Id;

		/// <summary>
		/// ��ȡ��׼����
		/// </summary>
		/// <returns></returns>
		__uproperty(get = GetStandardName) std::wstring StandardName;

		/// <summary>
		/// ��ȡ�Ƿ�֧������ʱ
		/// </summary>
		/// <returns></returns>
		__uproperty(get = GetSupportsDaylightSavingTime) bool SupportsDaylightSavingTime;

		/// <summary>
		/// ��ȡ��ǰϵͳʱ��
		/// </summary>
		/// <returns></returns>
		__uref static TimeZoneInfo Local();

		/// <summary>
		/// ��ȡ����Э��ʱʱ��
		/// </summary>
		/// <returns></returns>
		__uref static TimeZoneInfo Utc();

		/// <summary>
		/// ��ȡϵͳ���е�ʱ����Ϣ
		/// </summary>
		/// <returns></returns>
		__uref static std::vector<TimeZoneInfo> GetSystemTimeZones();

		/// <summary>
		/// ��ָ������ʱ��ת�����ض�ʱ��
		/// </summary>
		/// <param name="dateTime">ָ������ʱ��</param>
		/// <param name="destinationTimeZone">�ض�ʱ��</param>
		/// <returns></returns>
		__uref DateTime ConvertTime(const DateTime& dateTime, const TimeZoneInfo& destinationTimeZone);

		/// <summary>
		///  ��ָ������ʱ���Դʱ��ת����Ŀ��ʱ��
		/// </summary>
		/// <param name="dateTime">ָ������ʱ��</param>
		/// <param name="sourceTimeZone">Դʱ��</param>
		/// <param name="destinationTimeZone">Ŀ��ʱ��</param>
		/// <returns></returns>
		__uref DateTime ConvertTime(const DateTime& dateTime, const TimeZoneInfo& sourceTimeZone, const TimeZoneInfo& destinationTimeZone);

		/// <summary>
		/// ��Э������ʱ (UTC) ת��Ϊָ��ʱ���е�ʱ��
		/// </summary>
		/// <param name="dateTime">ָ������ʱ��</param>
		/// <param name="destinationTimeZone">ָ��ʱ��</param>
		/// <returns></returns>
		__uref DateTime ConvertTimeFromUtc(const DateTime& dateTime, const TimeZoneInfo& destinationTimeZone);

		/// <summary>
		/// ��ָ������ʱ��ת��ΪЭ������ʱ (UTC)
		/// </summary>
		/// <param name="dateTime">ָ������ʱ��</param>
		/// <returns></returns>
		__uref DateTime ConvertTimeToUtc(const DateTime& dateTime);

		/// <summary>
		/// ��ָ��ʱ���е�����ʱ��ת��ΪЭ������ʱ (UTC)
		/// </summary>
		/// <param name="dateTime">ָ������ʱ��</param>
		/// <param name="zone">ָ��ʱ��</param>
		/// <returns></returns>
		__uref DateTime ConvertTimeToUtc(const DateTime& dateTime, const TimeZoneInfo& zone);

		/// <summary>
		/// ��ȡ��ʱ���е�ʱ����Э������ʱ (UTC) ֮������ض�����ʱ���ƫ����
		/// </summary>
		/// <param name="dateTime">ָ������ʱ��</param>
		/// <returns></returns>
		__uref TimeSpan GetUtcOffset(const DateTime& dateTime) const;

		/// <summary>
		/// �жϸ�ʱ���е�ָ������ʱ���Ƿ�����ʱ�Ʒ�Χ��
		/// </summary>
		/// <param name="dateTime">ָ������ʱ��</param>
		/// <returns></returns>
		__uref bool IsDaylightSavingTime(const DateTime& dateTime) const;

		/// <summary>
		/// �жϸ�ʱ���е�ָ������ʱ���Ƿ���ȷ�Լ��Ƿ����ӳ������������Э������ʱ (UTC) ʱ��
		/// </summary>
		/// <param name="dateTime">ָ������ʱ��</param>
		/// <returns></returns>
		__uref bool IsAmbiguousTime(const DateTime& dateTime) const;

		/// <summary>
		/// �жϸ�ʱ������һ��ʱ���Ƿ������ͬ�ĵ�������
		/// </summary>
		/// <param name="otherZone">��һ��ʱ��</param>
		/// <returns></returns>
		__uref bool HasSameRules(const TimeZoneInfo& otherZone) const;

		/// <summary>
		/// �ж�ָ������ʱ���Ƿ���Ч
		/// </summary>
		/// <param name="dateTime"></param>
		/// <returns></returns>
		__uref bool IsInvalidTime(const DateTime& dateTime) const;

		REFLECT_CLASS(TimeZoneInfo)
	};

	class RUNTIME_API TimeZoneInfoConverter : public TypeConverter
	{
	private:
		static std::mutex& getlocker();
		static std::weak_ptr<TimeZoneInfoConverter> _thisWeakPtr;
	protected:
		TimeZoneInfoConverter();
		TimeZoneInfoConverter(TimeZoneInfoConverter const&);
		void operator=(TimeZoneInfoConverter const&);
	public:
		virtual ~TimeZoneInfoConverter();

		static std::shared_ptr<TimeZoneInfoConverter> GetSharedInstance();

		static TimeZoneInfoConverter& GetInstance();

		bool CanConvertFrom(_type type) const;
		bool CanConvertTo(_type type) const;

		Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
		Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

		Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
		std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
	};
}