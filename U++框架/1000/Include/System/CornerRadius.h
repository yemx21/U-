#pragma once
#include "Shared.h"
#include "TypeConverter.h"
#include <mutex>
namespace System
{
	/// <summary>
	/// Բ�ǰ뾶��
	/// </summary>
	class RUNTIME_API CornerRadius : __uobject
	{
	protected:
		double bl;
		double br;
		double tl;
		double tr;
		std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;
	public:
		/// <summary>
		/// ����<see cref="CornerRadius"/>ʵ��.
		/// </summary>
		__uref CornerRadius();

		virtual ~CornerRadius();

		/// <summary>
		/// ����<see cref="CornerRadius"/>ʵ��.
		/// </summary>
		/// <param name="topLeft">���Ͻǰ뾶</param>
		/// <param name="topRight">���Ͻǰ뾶</param>
		/// <param name="bottomRight">���½ǰ뾶</param>
		/// <param name="bottomLeft">���½ǰ뾶</param>
		__uref CornerRadius(double topLeft, double topRight, double bottomRight, double bottomLeft);

		/// <summary>
		/// ��ȡ���Ͻǰ뾶
		/// </summary>
		/// <returns></returns>
		double GetTopLeft() const;

		/// <summary>
		/// ��ȡ���½ǰ뾶
		/// </summary>
		/// <returns></returns>
		double GetTopRight() const;

		/// <summary>
		/// ��ȡ���½ǰ뾶
		/// </summary>
		/// <returns></returns>
		double GetBottomLeft() const;

		/// <summary>
		/// ��ȡ���½ǰ뾶
		/// </summary>
		/// <returns></returns>
		double GetBottomRight() const;

		/// <summary>
		/// ��ȡ���Ͻǰ뾶����
		/// </summary>
		/// <returns></returns>
		double& GetTopLeftRef();

		/// <summary>
		/// ��ȡ���Ͻǰ뾶����
		/// </summary>
		/// <returns></returns>
		double& GetTopRightRef();

		/// <summary>
		/// ��ȡ���½ǰ뾶����
		/// </summary>
		/// <returns></returns>
		double& GetBottomLeftRef();

		/// <summary>
		/// ��ȡ���½ǰ뾶����
		/// </summary>
		/// <returns></returns>
		double& GetBottomRightRef();

		/// <summary>
		/// �������Ͻǰ뾶
		/// </summary>
		/// <param name="val">�뾶ֵ</param>
		void SetTopLeft(double val);

		/// <summary>
		/// �������Ͻǰ뾶
		/// </summary>
		/// <param name="val">�뾶ֵ</param>
		void SetTopRight(double val);

		/// <summary>
		/// �������½ǰ뾶
		/// </summary>
		/// <param name="val">�뾶ֵ</param>
		void SetBottomLeft(double val);

		/// <summary>
		/// �������½ǰ뾶
		/// </summary>
		/// <param name="val">�뾶ֵ</param>
		void SetBottomRight(double val);

		__uref bool operator == (const CornerRadius& cornerRadius) const;

		__uref bool operator == (CornerRadius& cornerRadius) const;

		__uref CornerRadius & operator = (const CornerRadius & cornerRadius);

		__uref bool operator != (const CornerRadius& cornerRadius) const;

		__uref bool operator != (CornerRadius& cornerRadius) const;

		/// <summary>
		/// ���Ͻǰ뾶
		/// </summary>
		__uproperty(get = GetTopLeft, put = SetTopLeft) double TopLeft;
		/// <summary>
		/// ���Ͻǰ뾶
		/// </summary>
		__uproperty(get = GetTopRight, put = SetTopRight) double TopRight;
		/// <summary>
		/// ���½ǰ뾶
		/// </summary>
		__uproperty(get = GetBottomLeft, put = SetBottomLeft) double BottomLeft;
		/// <summary>
		/// ���½ǰ뾶
		/// </summary>
		__uproperty(get = GetBottomRight, put = SetBottomRight) double BottomRight;
		/// <summary>
		/// ���Ͻǰ뾶����
		/// </summary>
		__uproperty(get = GetTopLeftRef) double& TopLeftRef;
		/// <summary>
		/// ���Ͻǰ뾶����
		/// </summary>
		__uproperty(get = GetTopRightRef) double& TopRightRef;
		/// <summary>
		/// ���½ǰ뾶����
		/// </summary>
		__uproperty(get = GetBottomLeftRef) double& BottomLeftRef;
		/// <summary>
		/// ���½ǰ뾶����
		/// </summary>
		__uproperty(get = GetBottomRightRef) double& BottomRightRef;

		/// <summary>
		/// ���Խ���
		/// </summary>
		/// <param name="input">����ֵ.</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		static bool TryParse(const std::wstring& input, const CultureInfo& loc, CornerRadius& result);

		REFLECT_CLASS(CornerRadius)

	};

	/// <summary>
	/// Բ�ǰ뾶��ת����
	/// </summary>
	class RUNTIME_API CornerRadiusConverter : public TypeConverter
	{
	private:
		static std::mutex& getlocker();
		static std::weak_ptr<CornerRadiusConverter> _thisWeakPtr;
	protected:
		CornerRadiusConverter();
		CornerRadiusConverter(CornerRadiusConverter const&);
		void operator=(CornerRadiusConverter const&);
	public:
		virtual ~CornerRadiusConverter();

		static std::shared_ptr<CornerRadiusConverter> GetSharedInstance();

		static CornerRadiusConverter& GetInstance();

		bool CanConvertFrom(_type type) const;
		bool CanConvertTo(_type type) const;

		Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
		Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

		Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
		std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
	};

}