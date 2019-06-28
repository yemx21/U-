#pragma once
#include "Shared.h"
#include "TypeConverter.h"
#include <mutex>



namespace System
{

	/// <summary>
	/// ����
	/// </summary>
	class RUNTIME_API Point : __uobject
	{
	protected:
		std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;

		double x;
		double y;
	public:
		/// <summary>
		/// ���� <see cref="Point"/>ʵ��.
		/// </summary>
		/// <param name="px">X������ֵ</param>
		/// <param name="py">Y������ֵ</param>
		__uref Point(double px, double py);

		/// <summary>
		/// ���� <see cref="Point"/>ʵ��.
		/// </summary>
		__uref Point();

		virtual ~Point();

		/// <summary>
		/// ��ȡX������ֵ
		/// </summary>
		/// <returns></returns>
		double GetX() const;

		/// <summary>
		/// ��ȡY������ֵ
		/// </summary>
		/// <returns></returns>
		double GetY() const;

		/// <summary>
		/// ��ȡX������ֵ����
		/// </summary>
		/// <returns></returns>
		double& GetXRef();

		/// <summary>
		/// ��ȡY������ֵ����
		/// </summary>
		/// <returns></returns>
		double& GetYRef();

		/// <summary>
		/// ����X������ֵ
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetX(double val);

		/// <summary>
		/// ����Y������ֵ
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetY(double val);

		__uref Point(const Point& point);

		__uref Point operator + (const Point& point) const;

		__uref Point operator - (const Point& point) const;

		__uref Point& operator += (Point& point);

		__uref Point& operator -= (Point& point);

		__uref Point & operator = (const Point & point);

		__uref bool operator == (Point& point) const;

		__uref bool operator == (const Point& point) const;

		__uref bool operator != (Point& point) const;

		__uref bool operator != (const Point& point) const;

		/// <summary>
		/// ��ȡδ֪��
		/// </summary>
		/// <returns></returns>
		__uref static Point Unknown();

		/// <summary>
		/// �ж��Ƿ�δ֪
		/// </summary>
		/// <returns>bool.</returns>
		__uref bool GetIsUnknown() const;

		/// <summary>
		/// X������ֵ
		/// </summary>
		__uproperty(get = GetX, put = SetX) double X;

		/// <summary>
		/// Y������ֵ
		/// </summary>
		__uproperty(get = GetY, put = SetY) double Y;

		/// <summary>
		/// X������ֵ����
		/// </summary>
		__uproperty(get = GetXRef) double& XRef;

		/// <summary>
		/// Y������ֵ����
		/// </summary>
		__uproperty(get = GetYRef) double& YRef;

		/// <summary>
		/// �Ƿ�δ֪
		/// </summary>
		__uproperty(get = GetIsUnknown) bool IsUnknown;

		/// <summary>
		/// ���Խ���
		/// </summary>
		/// <param name="input">����ֵ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="result">���</param>
		static bool TryParse(const std::wstring& input, const CultureInfo& loc, Point& result);

		REFLECT_CLASS(Point)
	};


	class RUNTIME_API PointConverter : public TypeConverter
	{
	private:
		static std::mutex& getlocker();
		static std::weak_ptr<PointConverter> _thisWeakPtr;
	protected:
		PointConverter();
		PointConverter(PointConverter const&);
		void operator=(PointConverter const&);
	public:
		virtual ~PointConverter();

		static std::shared_ptr<PointConverter> GetSharedInstance();

		static PointConverter& GetInstance();

		bool CanConvertFrom(_type type) const;
		bool CanConvertTo(_type type) const;

		Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
		Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

		Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
		std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
	};

}