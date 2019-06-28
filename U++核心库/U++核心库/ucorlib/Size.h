#pragma once
#include "Shared.h"
#include "TypeConverter.h"
#include <mutex>



namespace System
{
	/// <summary>
	/// Class Size.
	/// </summary>
	class RUNTIME_API Size : __uobject
	{
	protected:
		std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;
		double w;
		double h;
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="Size"/> class.
		/// </summary>
		/// <param name="pw">The pw.</param>
		/// <param name="ph">The ph.</param>
		__uref Size(double pw, double ph);

		/// <summary>
		/// Initializes a new instance of the <see cref="Size"/> class.
		/// </summary>
		__uref Size();

		/// <summary>
		/// Finalizes an instance of the <see cref="Size"/> class.
		/// </summary>
		/// <returns>__uref.</returns>
		__uref ~Size();

		/// <summary>
		/// ��ȡ���
		/// </summary>
		/// <returns></returns>
		double GetWidth() const;

		/// <summary>
		/// ��ȡ�߶�
		/// </summary>
		/// <returns></returns>
		double GetHeight() const;

		/// <summary>
		/// ���ÿ��
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetWidth(double val);

		/// <summary>
		/// ���ø߶�
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetHeight(double val);

		/// <summary>
		/// ��ȡ�������
		/// </summary>
		/// <returns></returns>

		double& GetWidthRef();

		/// <summary>
		/// ��ȡ�߶�����
		/// </summary>
		/// <returns></returns>

		double& GetHeightRef();

		/// <summary>
		/// ����Ӧ��ָ������ֵ���´�С����
		/// </summary>
		/// <param name="scale">ָ������ֵ</param>
		/// <returns>�´�С����</returns>
		__uref Size Scale(double scale) const;

		/// <summary>
		/// Ӧ��ָ������ֵ
		/// </summary>
		/// <param name="scale">ָ������ֵ</param>
		/// <returns>__uref void.</returns>
		__uref void Scale(double scale);

		__uref Size(const Size& size);

		__uref Size operator + (const Size& size) const;

		__uref Size operator - (const Size& size) const;

		__uref Size& operator += (Size& size);

		__uref Size& operator -= (Size& size);

		__uref Size & operator = (const Size & size);

		__uref bool operator == (Size& size) const;

		__uref bool operator == (const Size& size) const;

		__uref bool operator != (Size& size) const;

		__uref bool operator != (const Size& size) const;

		/// <summary>
		/// ��ȡδ֪��С
		/// </summary>
		/// <returns></returns>
		__uref static Size Unknown();

		/// <summary>
		/// ��ȡ���޴�С
		/// </summary>
		/// <returns></returns>
		__uref static Size Infitite();

		/// <summary>
		/// �ж��Ƿ�Ϊ��
		/// </summary>
		/// <returns></returns>
		bool GetIsUnknown() const;

		/// <summary>
		/// �ж��Ƿ�����������һ����ֵ
		/// </summary>
		/// <returns></returns>
		bool GetIsOneDimensionalOrEmpty() const;

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
		__uproperty(get = GetWidthRef) double& WidthRef;
		/// <summary>
		/// �߶�����
		/// </summary>
		__uproperty(get = GetHeightRef) double& HeightRef;
		/// <summary>
		/// �Ƿ�δ֪
		/// </summary>
		__uproperty(get = GetIsUnknown) bool IsUnknown;
		/// <summary>
		/// �Ƿ�������Ϊ��һ����ֵ
		/// </summary>
		__uproperty(get = GetIsOneDimensionalOrEmpty) bool IsOneDimensionalOrEmpty;

		static bool TryParse(const std::wstring& input, const CultureInfo& loc, Size& result);

		REFLECT_CLASS(Size)
	};

	class RUNTIME_API SizeConverter : public TypeConverter
	{
	private:
		static std::mutex& getlocker();
		static std::weak_ptr<SizeConverter> _thisWeakPtr;
	protected:
		SizeConverter();
		SizeConverter(SizeConverter const&);
		void operator=(SizeConverter const&);
	public:
		virtual ~SizeConverter();

		static std::shared_ptr<SizeConverter> GetSharedInstance();

		static SizeConverter& GetInstance();

		bool CanConvertFrom(_type type) const;
		bool CanConvertTo(_type type) const;

		Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
		Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

		Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
		std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
	};

}