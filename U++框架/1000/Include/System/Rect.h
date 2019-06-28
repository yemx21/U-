#pragma once
#include "Shared.h"
#include "TypeConverter.h"
#include <mutex>
#include "Point.h"
#include "Size.h"
#include <math.h>


namespace System
{
	/// <summary>
	/// ������
	/// </summary>
	class RUNTIME_API Rect : __uobject
	{
	protected:
		std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;
		double l;
		double t;
		double w;
		double h;
	public:
		/// <summary>
		/// ����<see cref="Rect"/>ʵ��.
		/// </summary>
		/// <param name="left">���X������ֵ</param>
		/// <param name="top">�ϱ�Y������ֵ</param>
		/// <param name="width">���</param>
		/// <param name="height">�߶�</param>
		__uref Rect(double left, double top, double width, double height);

		/// <summary>
		/// ����<see cref="Rect"/>ʵ��.
		/// </summary>
		/// <param name="xy">���Ͻ�����ֵ</param>
		/// <param name="size">ָ�����δ�С</param>
		__uref Rect(const Point& xy, const System::Size& size);

		/// <summary>
		/// ����<see cref="Rect"/>ʵ��.
		/// </summary>
		/// <param name="p1">���Ͻ�����ֵ</param>
		/// <param name="p2">���½�����ֵ</param>
		__uref Rect(const Point& p1, const Point& p2);

		/// <summary>
		/// ����<see cref="Rect"/>ʵ��.
		/// </summary>
		/// <param name="size">ָ�����δ�С</param>
		__uref Rect(const System::Size& size);

		/// <summary>
		/// ����<see cref="Rect"/>ʵ��.
		/// </summary>
		__uref Rect();

		~Rect();

		/// <summary>
		/// ��ȡ���X������ֵ
		/// </summary>
		/// <returns></returns>
		double GetLeft() const;

		/// <summary>
		/// ��ȡ�ұ�X������ֵ
		/// </summary>
		/// <returns></returns>
		double GetRight() const;

		/// <summary>
		/// �����ұ�X������ֵ
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetRight(double val);

		/// <summary>
		/// ��ȡ�ϱ�Y������ֵ
		/// </summary>
		/// <returns></returns>
		double GetTop() const;

		/// <summary>
		/// ��ȡ�ױ�Y������ֵ
		/// </summary>
		/// <returns></returns>
		double GetBottom() const;

		/// <summary>
		/// ���õױ�Y������ֵ
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetBottom(double val);

		/// <summary>
		/// �������X������ֵ
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetLeft(double val);

		/// <summary>
		/// �����ϱ�Y������ֵ
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetTop(double val);

		/// <summary>
		/// ��ȡ���
		/// </summary>
		/// <returns></returns>
		double GetWidth() const;

		/// <summary>
		/// ��ȡ�������
		/// </summary>
		/// <returns></returns>
		double& GetWidthRef();

		/// <summary>
		///���ÿ��
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetWidth(double val);

		/// <summary>
		/// ��ȡ�߶�
		/// </summary>
		/// <returns></returns>
		double GetHeight() const;

		/// <summary>
		/// ��ȡ�߶�����
		/// </summary>
		/// <returns></returns>
		double& GetHeightRef();

		/// <summary>
		/// ���ø߶�
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetHeight(double val);

		/// <summary>
		/// ��ȡ���Ͻ�����ֵ
		/// </summary>
		/// <returns></returns>
		Point GetLocation() const;

		/// <summary>
		/// �������Ͻ�����ֵ
		/// </summary>
		/// <param name="point">ָ�����Ͻǵ�</param>
		void SetLocation(const Point& point);

		/// <summary>
		/// ��ȡ���δ�С
		/// </summary>
		/// <returns></returns>
		System::Size GetSize() const;

		/// <summary>
		/// ���þ��δ�С
		/// </summary>
		/// <param name="size">ָ����С</param>
		void SetSize(const System::Size& size);

		/// <summary>
		/// �жϾ����Ƿ�Ϊ��
		/// </summary>
		/// <returns></returns>
		bool GetIsEmpty() const;

		/// <summary>
		/// �ж��Ƿ����ָ����
		/// </summary>
		/// <param name="x">ָ��������X������ֵ</param>
		/// <param name="y">ָ��������Y������ֵ</param>
		__uref bool Contains(double x, double y) const;

		/// <summary>
		/// �ж��Ƿ����ָ����
		/// </summary>
		/// <param name="point">ָ����</param>
		__uref bool Contains(const Point& point) const;

		/// <summary>
		/// �ж��Ƿ����ָ������
		/// </summary>
		/// <param name="rect">ָ������</param>
		__uref bool Contains(const Rect& rect) const;


		/// <summary>
		/// ���͵�ǰ����
		/// </summary>
		/// <param name="size">���ʹ�С</param>
		__uref void Inflate(const System::Size& size);

		/// <summary>
		/// ���͵�ǰ����
		/// </summary>
		/// <param name="width">ָ�����Ϳ��</param>
		/// <param name="height">ָ�����͸߶�</param>
		__uref void Inflate(double width, double height);

		/// <summary>
		/// ��ȡ�վ���
		/// </summary>
		/// <returns></returns>
		__uref static Rect Empty();

		/// <summary>
		/// ����ָ������
		/// </summary>
		/// <param name="rect">ָ������</param>
		/// <param name="size">���ʹ�С</param>
		/// <returns></returns>
		__uref static Rect Inflate(const Rect& rect, const System::Size& size);

		/// <summary>
		/// ����ָ������
		/// </summary>
		/// <param name="rect">ָ������</param>
		/// <param name="width">���Ϳ��</param>
		/// <param name="height">���͸߶�</param>
		/// <returns></returns>
		__uref static Rect Inflate(const Rect& rect, double width, double height);

		/// <summary>
		/// Ӧ������ֵ
		/// </summary>
		/// <param name="scaleX">X������ֵ</param>
		/// <param name="scaleY">Y������ֵ</param>
		__uref void Scale(double scaleX, double scaleY);

		/// <summary>
		/// �ж��Ƿ���ָ�������ཻ
		/// </summary>
		/// <param name="rect">ָ������</param>
		/// <returns></returns>
		__uref bool IntersectsWith(const Rect& rect);

		/// <summary>
		/// ��ָ������ȡ����
		/// </summary>
		/// <param name="rect">ָ������</param>
		__uref void Intersect(const Rect& rect);

		/// <summary>
		/// ȡ�������εĽ���
		/// </summary>
		/// <param name="rect1">����1</param>
		/// <param name="rect2">����2</param>
		/// <returns></returns>
		__uref static Rect Intersect(const Rect& rect1, const Rect& rect2);

		/// <summary>
		/// ��ָ������ȡ�ϼ�
		/// </summary>
		/// <param name="rect">ָ������</param>
		__uref void Union(const Rect& rect);

		/// <summary>
		/// ȡ�������εĺϼ�
		/// </summary>
		/// <param name="rect1">����1</param>
		/// <param name="rect2">����2</param>
		/// <returns></returns>
		__uref static Rect Union(const Rect& rect1, const Rect& rect2);

		/// <summary>
		/// ��ָ����ȡ�ϼ�
		/// </summary>
		/// <param name="point">ָ����</param>
		__uref void Union(const Point& point);

		/// <summary>
		/// ȡָ�����κ�ָ����ĺϼ�
		/// </summary>
		/// <param name="rect">ָ������</param>
		/// <param name="point">ָ����</param>
		/// <returns></returns>
		__uref static Rect Union(const Rect& rect, const Point& point);

		/// <summary>
		/// ƫ�Ƶ�ǰ����
		/// </summary>
		/// <param name="offsetX">X��ƫ��ֵ</param>
		/// <param name="offsetY">Y��ƫ��ֵ</param>
		__uref void Offset(double offsetX, double offsetY);

		/// <summary>
		/// ƫ��ָ������
		/// </summary>
		/// <param name="rect">ָ������</param>
		/// <param name="offsetX">X��ƫ��ֵ</param>
		/// <param name="offsetY">Y��ƫ��ֵ</param>
		/// <returns></returns>
		__uref static Rect Offset(const Rect& rect, double offsetX, double offsetY);


		__uref Rect(const Rect& rect);

		__uref Rect & operator = (const Rect & rect);

		__uref bool operator == (Rect& rect) const;

		__uref bool operator == (const Rect& rect) const;

		__uref bool operator != (Rect& rect) const;

		__uref bool operator != (const Rect& rect) const;

		/// <summary>
		/// ��ȡδ֪����
		/// </summary>
		/// <returns></returns>
		__uref static Rect Unknown();

		/// <summary>
		/// �ж��Ƿ�δ֪
		/// </summary>
		/// <returns>bool.</returns>
		bool GetIsUnknown() const;

		/// <summary>
		/// ���X������ֵ
		/// </summary>
		__uproperty(get = GetLeft, put = SetLeft) double Left;
		/// <summary>
		/// �ϱ�Y������ֵ
		/// </summary>
		__uproperty(get = GetTop, put = SetTop) double Top;
		/// <summary>
		/// ���X������ֵ����
		/// </summary>
		__uproperty(get = GetLeftRef) double LeftRef;
		/// <summary>
		/// �ϱ�Y������ֵ����
		/// </summary>
		__uproperty(get = GetTopRef) double TopRef;
		/// <summary>
		/// �ұ�X������ֵ
		/// </summary>
		__uproperty(get = GetRight, put = SetRight) double Right;
		/// <summary>
		/// �ױ�Y������ֵ
		/// </summary>
		__uproperty(get = GetBottom, put = SetBottom) double Bottom;
		/// <summary>
		/// ���
		/// </summary>
		__uproperty(get = GetWidth, put = SetWidth) double Width;
		/// <summary>
		/// �߶�
		/// </summary>
		__uproperty(get = GetHeight, put = SetHeight) double Height;		
		/// <summary>
		/// �������
		/// </summary>
		__uproperty(get = GetWidthRef) double WidthRef;
		/// <summary>
		/// �߶�����
		/// </summary>
		__uproperty(get = GetHeightRef) double HeightRef;
		/// <summary>
		/// ���Ͻ�����ֵ
		/// </summary>
		__uproperty(get = GetLocation, put = SetLocation) Point Location;
		/// <summary>
		/// ���δ�С
		/// </summary>
		__uproperty(get = GetSize, put = SetSize) System::Size Size;
		/// <summary>
		/// �Ƿ�δ֪
		/// </summary>
		__uproperty(get = GetIsUnknown) bool IsUnknown;
		/// <summary>
		/// �Ƿ�Ϊ��
		/// </summary>
		__uproperty(get = GetIsEmpty) bool IsEmpty;

		/// <summary>
		/// ���Խ���
		/// </summary>
		/// <param name="input">����ֵ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		/// /
		static bool TryParse(const std::wstring& input, const CultureInfo& loc, Rect& result);

		REFLECT_CLASS(Rect)
	};

	class RUNTIME_API RectConverter : public TypeConverter
	{
	private:
		static std::mutex& getlocker();
		static std::weak_ptr<RectConverter> _thisWeakPtr;
	protected:
		RectConverter();
		RectConverter(RectConverter const&);
		void operator=(RectConverter const&);
	public:
		virtual ~RectConverter();

		static std::shared_ptr<RectConverter> GetSharedInstance();

		static RectConverter& GetInstance();

		bool CanConvertFrom(_type type) const;
		bool CanConvertTo(_type type) const;

		Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
		Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

		Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
		std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
	};


}
