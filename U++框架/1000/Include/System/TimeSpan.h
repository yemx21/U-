#pragma once
#include "Shared.h"
#include "TypeConverter.h"
#include <mutex>



namespace System
{
	class DateTimeFormat; 
	class TimeSpanFormat;
	class TimeSpanParse;
	class TimeSpanConverter;

	/// <summary>
	/// ʱ�������ö��
	/// </summary>
	class RUNTIME_API TimeSpanStyles : __uobject
	{
		__uvalue_begin(TimeSpanStyles, UInt32)
		/// <summary>
		/// ��
		/// </summary>
		__uvalue(None)
		/// <summary>
		/// ����Ϊ��
		/// </summary>
		__uvalue(AssumeNegative)
		__uvalue_end(TimeSpanStyles, None)
	};

	/// <summary>
	/// ʱ������
	/// </summary>
	class RUNTIME_API TimeSpan final:__uobject
	{
	public:
		/// <summary>
		/// �̶ȣ��죩
		/// </summary>
		static const Int64 DAYS;
		/// <summary>
		/// �̶ȣ�Сʱ��
		/// </summary>
		static const Int64 HOURS;
		/// <summary>
		/// �̶ȣ����ӣ�
		/// </summary>
		static const Int64 MINUTES;
		/// <summary>
		/// �̶ȣ��룩
		/// </summary>
		static const Int64 SECONDS;
		/// <summary>
		/// �̶ȣ����룩
		/// </summary>
		static const Int64 MILLISECONDS;
		/// <summary>
		/// �̶ȣ�΢�룩
		/// </summary>
		static const Int64 MICROSECONDS;

	private:
		friend class DateTimeFormat;
		friend class TimeSpanFormat;
		friend class TimeSpanParse;
		friend class DateTime;
		Int64 span;		
	protected:
		std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;
	public:
		/// <summary>
		/// ����<see cref="TimeSpan"/>ʵ��.
		/// </summary>
		__uref TimeSpan();

		/// <summary>
		/// ����<see cref="TimeSpan"/>ʵ��.
		/// </summary>
		/// <param name="nano100seconds">��100����Ϊ��λ��ʱ��ֵ</param>
		__uref TimeSpan(Int64 nano100seconds);

		/// <summary>
		/// ����<see cref="TimeSpan"/>ʵ��.
		/// </summary>
		/// <param name="hours">Сʱ��</param>
		/// <param name="minutes">������</param>
		/// <param name="seconds">����</param>
		__uref TimeSpan(int hours, int minutes, int seconds);

		/// <summary>
		/// ����<see cref="TimeSpan"/>ʵ��.
		/// </summary>
		/// <param name="days">����</param>
		/// <param name="hours">Сʱ��</param>
		/// <param name="minutes">������</param>
		/// <param name="seconds">����</param>
		__uref TimeSpan(int days, int hours, int minutes, int seconds);

		/// <summary>
		/// ����<see cref="TimeSpan"/>ʵ��.
		/// </summary>
		/// <param name="days">����</param>
		/// <param name="hours">Сʱ��</param>
		/// <param name="minutes">������</param>
		/// <param name="seconds">����</param>
		/// <param name="milliseconds">������</param>
		__uref TimeSpan(int days, int hours, int minutes, int seconds, int milliseconds);

		/// <summary>
		/// ����<see cref="TimeSpan"/>ʵ��.
		/// </summary>
		/// <param name="days">����</param>
		/// <param name="hours">Сʱ��</param>
		/// <param name="minutes">������</param>
		/// <param name="seconds">����</param>
		/// <param name="milliseconds">������</param>
		/// <param name="microseconds">΢����</param>
		__uref TimeSpan(int days, int hours, int minutes, int seconds, int milliseconds, int microseconds);

		/// <summary>
		/// ����<see cref="TimeSpan"/>ʵ��.
		/// </summary>
		/// <param name="days">����</param>
		/// <param name="hours">Сʱ��</param>
		/// <param name="minutes">������</param>
		/// <param name="seconds">����</param>
		/// <param name="milliseconds">������</param>
		/// <param name="microseconds">΢����</param>
		/// <param name="nano100seconds">��100����Ϊ��λ��ʱ��ֵ</param>
		__uref TimeSpan(int days, int hours, int minutes, int seconds, int milliseconds, int microseconds, int nano100seconds);

		~TimeSpan();

		__uref TimeSpan(const TimeSpan& timeSpan);

		/// <summary>
		/// ��ȡʱ����
		/// </summary>
		/// <returns></returns>
		TimeSpan GetDuration() const;
		/// <summary>
		/// ��ȡ��ǰʱ��ĸ�ֵ
		/// </summary>
		/// <returns></returns>
		TimeSpan GetNegate() const;
		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		int GetDays() const;
		/// <summary>
		/// ��ȡСʱ��
		/// </summary>
		/// <returns></returns>
		int GetHours() const;
		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		int GetMinutes() const;
		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		int GetSeconds() const;
		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		int GetMilliseconds() const;
		/// <summary>
		/// ��ȡ΢����
		/// </summary>
		/// <returns></returns>
		int GetMicroseconds() const;
		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		double GetTotalDays() const;
		/// <summary>
		/// ��ȡ��Сʱ��
		/// </summary>
		/// <returns></returns>
		double GetTotalHours() const;
		/// <summary>
		/// ��ȡ�ܷ�����
		/// </summary>
		/// <returns></returns>
		double GetTotalMinutes() const;
		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		double GetTotalSeconds() const;
		/// <summary>
		/// ��ȡ�ܺ�����
		/// </summary>
		/// <returns></returns>
		double GetTotalMilliseconds() const;
		/// <summary>
		/// ��ȡ��΢����
		/// </summary>
		/// <returns></returns>
		double GetTotalMicroseconds() const;

		/// <summary>
		/// ��ȡ��ʱ��ֵ
		/// </summary>
		/// <returns></returns>
		Int64 GetTicks() const;


		/// <summary>
		/// ����
		/// </summary>
		__uproperty(get = GetDuration) TimeSpan Duration;
		/// <summary>
		/// ����
		/// </summary>
		__uproperty(get = GetNegate) TimeSpan Negate;
		/// <summary>
		/// ����
		/// </summary>
		__uproperty(get = GetDays) int Days;
		/// <summary>
		/// Сʱ��
		/// </summary>
		__uproperty(get = GetHours) int Hours;
		/// <summary>
		/// ������
		/// </summary>
		__uproperty(get = GetMinutes) int Minutes;
		/// <summary>
		/// ����
		/// </summary>
		__uproperty(get = GetSeconds) int Seconds;
		/// <summary>
		/// ������
		/// </summary>
		__uproperty(get = GetMilliseconds) int Milliseconds;
		/// <summary>
		/// ΢����
		/// </summary>
		__uproperty(get = GetMicroseconds) int Microseconds;
		/// <summary>
		/// ������
		/// </summary>
		__uproperty(get = GetTotalDays)double TotalDays;
		/// <summary>
		/// ��Сʱ��
		/// </summary>
		__uproperty(get = GetTotalHours) double TotalHours;
		/// <summary>
		/// �ܷ�����
		/// </summary>
		__uproperty(get = GetTotalMinutes)double TotalMinutes;
		/// <summary>
		/// ������
		/// </summary>
		__uproperty(get = GetTotalSeconds)double TotalSeconds;
		/// <summary>
		/// �ܺ�����
		/// </summary>
		__uproperty(get = GetTotalMilliseconds) double TotalMilliseconds;
		/// <summary>
		/// ��΢����
		/// </summary>
		__uproperty(get = GetTotalMicroseconds) double TotalMicroseconds;

		/// <summary>
		/// ��ȡ��ʱ��ֵ
		/// </summary>
		/// <returns></returns>
		__uproperty(get = GetTicks) Int64 Ticks;

		/// <summary>
		/// ת��Ϊʱ��ֵ
		/// </summary>
		/// <param name="days">����</param>
		/// <param name="hours">Сʱ��</param>
		/// <param name="minutes">������</param>
		/// <param name="seconds">����</param>
		/// <param name="milliseconds">������</param>
		/// <param name="microseconds">΢����</param>
		/// <param name="nano100seconds">��100����Ϊ��λ��ʱ��ֵ</param>
		__uref static Int64 TimeToTicks(int days, int hours, int minutes, int seconds, int milliseconds, int microseconds, int nano100seconds);

		/// <summary>
		/// ������������<see cref="TimeSpan"/>ʵ��.
		/// </summary>
		/// <param name="value">������</param>
		/// <returns></returns>
		__uref static TimeSpan FromDays(double value);

		/// <summary>
		/// ����С��������<see cref="TimeSpan"/>ʵ��.
		/// </summary>
		/// <param name="value">��Сʱ��</param>
		/// <returns></returns>
		__uref static TimeSpan FromHours(double value);

		/// <summary>
		/// ���ܷ���������<see cref="TimeSpan"/>ʵ��.
		/// </summary>
		/// <param name="value">�ܷ�����</param>
		/// <returns></returns>
		__uref static TimeSpan FromMinutes(double value);

		/// <summary>
		/// ������������<see cref="TimeSpan"/>ʵ��.
		/// </summary>
		/// <param name="value">������</param>
		/// <returns></returns>
		__uref static TimeSpan FromSeconds(double value);

		/// <summary>
		/// ���ܺ���������<see cref="TimeSpan"/>ʵ��.
		/// </summary>
		/// <param name="value">�ܺ�����</param>
		/// <returns></returns>
		__uref static TimeSpan FromMilliseconds(double value);

		/// <summary>
		/// ����΢��������<see cref="TimeSpan"/>ʵ��.
		/// </summary>
		/// <param name="value">��΢����</param>
		/// <returns></returns>
		__uref static TimeSpan FromMicroseconds(double value);

		/// <summary>
		/// ����100����Ϊ��λ��ʱ��ֵ����<see cref="TimeSpan"/>ʵ��.
		/// </summary>
		/// <param name="value">��100����Ϊ��λ��ʱ��ֵ</param>
		/// <returns></returns>
		__uref static TimeSpan TimeSpan::FromNano100seconds(Int64 value);


		__uref TimeSpan & operator=(const TimeSpan & timeSpan);

		__uref TimeSpan operator + (const TimeSpan& timeSpan) const;

		__uref TimeSpan operator - (const TimeSpan& timeSpan) const;

		__uref TimeSpan& operator += (TimeSpan& timeSpan);

		__uref TimeSpan& operator -= (TimeSpan& timeSpan);

		__uref bool operator == (TimeSpan&  timeSpan) const;

		__uref bool operator == (const TimeSpan&  timeSpan) const;

		__uref bool operator != (TimeSpan&  timeSpan) const;

		__uref bool operator != (const TimeSpan&  timeSpan) const;

		__uref bool operator > (TimeSpan&  timeSpan) const;

		__uref bool operator >= (TimeSpan&  timeSpan) const;

		__uref bool operator < (TimeSpan&  timeSpan) const;

		__uref bool operator <= (TimeSpan&  timeSpan) const;

		__uref TimeSpan operator - () const;

		/// <summary>
		/// ���Խ���
		/// </summary>
		/// <param name="input">����ֵ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		static bool TryParse(const std::wstring& input, const CultureInfo& loc, TimeSpan& result);

		/// <summary>
		/// ���Խ���
		/// </summary>
		/// <param name="input">����ֵ</param>
		/// <param name="format">��ʽ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="style">ָ�����</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		static bool TryParseExact(const std::wstring& input, const std::wstring& format, const CultureInfo& loc, TimeSpanStyles style, TimeSpan& result);


		REFLECT_CLASS(TimeSpan)

	};

	class RUNTIME_API TimeSpanConverter: public TypeConverter
	{
	private:
		static std::mutex& getlocker();
		static std::weak_ptr<TimeSpanConverter> _thisWeakPtr;
	protected:
		TimeSpanConverter(); 
		TimeSpanConverter(TimeSpanConverter const&); 
		void operator=(TimeSpanConverter const&); 
	public:
		virtual ~TimeSpanConverter();

		static std::shared_ptr<TimeSpanConverter> GetSharedInstance();

		static TimeSpanConverter& GetInstance();

		bool CanConvertFrom(_type type) const;
		bool CanConvertTo(_type type) const;

		Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
		Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

		Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
		std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
	};

}