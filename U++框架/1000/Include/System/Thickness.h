#pragma once
#include "Shared.h"
#include "TypeConverter.h"
#include <mutex>
namespace System
{
	/// <summary>
	/// �߾��ϸ��
	/// </summary>
	class RUNTIME_API  Thickness : __uobject
	{
	protected:
		std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;
		double l;
		double t;
		double r;
		double b;
	public:
		/// <summary>
		/// ����<see cref="Thickness"/>ʵ��.
		/// </summary>
		__uref Thickness();

		/// <summary>
		/// ����<see cref="Thickness"/>ʵ��.
		/// </summary>
		/// <param name="left">��߾�</param>
		/// <param name="top">�ϱ߾�</param>
		/// <param name="right">�ұ߾�</param>
		/// <param name="bottom">�ױ߾�</param>
		__uref Thickness(double left, double top, double right, double bottom);

		__uref Thickness(const Thickness& thickness);

		/// <summary>
		/// ��ȡ��߾�
		/// </summary>
		/// <returns></returns>
		double GetLeft() const;

		/// <summary>
		/// ��ȡ�ϱ߾�
		/// </summary>
		/// <returns></returns>
		double GetTop() const;

		/// <summary>
		/// ��ȡ�ұ߾�
		/// </summary>
		/// <returns></returns>
		double GetRight() const;

		/// <summary>
		/// ��ȡ�ױ߾�
		/// </summary>
		/// <returns></returns>		
		double GetBottom() const;

		/// <summary>
		/// ��ȡ��߾�����
		/// </summary>
		/// <returns></returns>
		double& GetLeftRef();

		/// <summary>
		/// ��ȡ�ϱ߾�����
		/// </summary>
		/// <returns></returns>
		double& GetTopRef();

		/// <summary>
		/// ��ȡ�ұ߾�����
		/// </summary>
		/// <returns></returns>
		double& GetRightRef();

		/// <summary>
		/// ��ȡ�ױ߾�����
		/// </summary>
		/// <returns></returns>
		double& GetBottomRef();

		/// <summary>
		/// ������߾�
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetLeft(double val);

		/// <summary>
		/// �����ϱ߾�
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetTop(double val);

		/// <summary>
		/// �����ұ߾�
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetRight(double val);

		/// <summary>
		/// ���õױ߾�
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetBottom(double val);

		__uref bool operator == (const Thickness& thickness) const;

		__uref bool operator == (Thickness& thickness) const;

		__uref Thickness & operator = (const Thickness & thickness);

		__uref bool operator != (const Thickness& thickness) const;

		__uref bool operator != (Thickness& thickness) const;

		/// <summary>
		/// ��߾�
		/// </summary>
		__uproperty(get = GetLeft, put = SetLeft) double Left;
		/// <summary>
		/// �ϱ߾�
		/// </summary>
		__uproperty(get = GetTop, put = SetTop) double Top;
		/// <summary>
		/// �ұ߾�
		/// </summary>
		__uproperty(get = GetRight, put = SetRight) double Right;
		/// <summary>
		/// �ױ߾�
		/// </summary>
		__uproperty(get = GetBottom, put = SetBottom) double Bottom;
		/// <summary>
		/// ��߾�����
		/// </summary>
		__uproperty(get = GetLeftRef) double& LeftRef;
		/// <summary>
		/// �ϱ߾�����
		/// </summary>
		__uproperty(get = GetTopRef) double& TopRef;
		/// <summary>
		/// �ұ߾�����
		/// </summary>
		__uproperty(get = GetRightRef) double& RightRef;
		/// <summary>
		/// �ױ߾�����
		/// </summary>
		__uproperty(get = GetBottomRef) double& BottomRef;

		/// <summary>
		/// ���Խ���
		/// </summary>
		/// <param name="input">����ֵ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		static bool TryParse(const std::wstring& input, const CultureInfo& loc, Thickness& result);

		REFLECT_CLASS(Thickness)
	};

	class RUNTIME_API ThicknessConverter : public TypeConverter
	{
	private:
		static std::mutex& getlocker();
		static std::weak_ptr<ThicknessConverter> _thisWeakPtr;
	protected:
		ThicknessConverter();
		ThicknessConverter(ThicknessConverter const&);
		void operator=(ThicknessConverter const&);
	public:
		virtual ~ThicknessConverter();

		static std::shared_ptr<ThicknessConverter> GetSharedInstance();

		static ThicknessConverter& GetInstance();

		bool CanConvertFrom(_type type) const;
		bool CanConvertTo(_type type) const;

		Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
		Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

		Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
		std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
	};
}