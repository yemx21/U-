#pragma once
#include "Shared.h"
#include "TypeConverter.h"
#include <mutex>
#include "Point.h"
#include "Size.h"
#include <math.h>


#ifndef M_PI
#define M_PI       3.14159265358979323846
#endif

namespace System
{
	/// <summary>
	/// ������
	/// </summary>
	class RUNTIME_API Matrix final: __uobject
	{
	private:
		unsigned char flag;
		double _11;
		double _12;
		double _21;
		double _22;
		double _31;
		double _32;
	protected:
		std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;
	public:
		/// <summary>
		/// ����<see cref="Matrix"/>ʵ��.
		/// </summary>
		/// <param name="m11">M11</param>
		/// <param name="m12">M12</param>
		/// <param name="m21">M21</param>
		/// <param name="m22">M22</param>
		/// <param name="m31">M31</param>
		/// <param name="m32">M32</param>
		__uref Matrix(double m11, double m12, double m21, double m22, double m31, double m32);

		/// <summary>
		/// ����<see cref="Matrix"/>ʵ��.
		/// </summary>
		__uref Matrix();

		__uref Matrix(const Matrix& matrix);

		virtual ~Matrix();

		/// <summary>
		/// ��ȡ��λ����
		/// </summary>
		__uref static Matrix Identity();

		/// <summary>
		/// �ж��Ƿ�Ϊ��λ����
		/// </summary>
		/// <returns></returns>
		bool GetIsIdentity() const;

		/// <summary>
		/// ��ȡ����ʽֵ
		/// </summary>
		/// <returns></returns>
		double GetDeterminant() const;

		/// <summary>
		/// �ж��Ƿ����
		/// </summary>
		/// <returns></returns>
		bool GetHasInverse() const;

		/// <summary>
		/// ��ȡM11
		/// </summary>
		/// <returns></returns>
		double GetM11() const;

		/// <summary>
		/// ����M11
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetM11(double val);

		/// <summary>
		/// ��ȡM12
		/// </summary>
		/// <returns></returns>
		double GetM12() const;

		/// <summary>
		/// ����M12
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetM12(double val);

		/// <summary>
		/// ��ȡM21
		/// </summary>
		/// <returns></returns>
		double GetM21() const;

		/// <summary>
		/// ����M21
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetM21(double val);

		/// <summary>
		/// ��ȡM22
		/// </summary>
		/// <returns></returns>
		double GetM22() const;

		/// <summary>
		/// ����M22
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetM22(double val);

		/// <summary>
		/// ��ȡM31
		/// </summary>
		/// <returns></returns>
		double GetM31() const;

		/// <summary>
		/// ����M31
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetM31(double val);

		/// <summary>
		/// ��ȡM32
		/// </summary>
		/// <returns></returns>
		double GetM32() const;

		/// <summary>
		/// ����M32
		/// </summary>
		/// <param name="val">ֵ</param>
		void SetM32(double val);

		/// <summary>
		/// �ж��Ƿ���Ϊ��λ����
		/// </summary>
		/// <returns></returns>
		bool GetIsDistinguishedIdentity() const;

		__uref Matrix operator*(const Matrix &matrix) const;

		__uref bool operator == (const Matrix &matrix) const;

		__uref bool operator != (const Matrix &matrix) const;

		/// <summary>
		/// ����Ϊ��λ����
		/// </summary>
		__uref void SetIdentity();

		/// <summary>
		/// ������ת����
		/// </summary>
		/// <param name="angle">��ת�Ƕ�</param>
		/// <param name="centerX">���ĵ�X������ֵ</param>
		/// <param name="centerY">���ĵ�Y������ֵ</param>
		/// <returns></returns>
		__uref static Matrix CreateRotationRadians(double angle, double centerX, double centerY);

		/// <summary>
		/// ������ת����
		/// </summary>
		/// <param name="angle">��ת�Ƕ�</param>
		/// <returns></returns>
		__uref static Matrix CreateRotationRadians(double angle);

		/// <summary>
		/// �������ž���
		/// </summary>
		/// <param name="scaleX">����X�����</param>
		/// <param name="scaleY">����Y�����</param>
		/// <param name="centerX">���ĵ�X������ֵ</param>
		/// <param name="centerY">���ĵ�Y������ֵ</param>
		/// <returns></returns>
		__uref static Matrix CreateScaling(double scaleX, double scaleY, double centerX, double centerY);

		/// <summary>
		/// �������ž���
		/// </summary>
		/// <param name="centerX">���ĵ�X������ֵ</param>
		/// <param name="centerY">���ĵ�Y������ֵ</param>
		/// <returns></returns>
		__uref static Matrix CreateScaling(double scaleX, double scaleY);

		/// <summary>
		/// ����б���Ⱦ���
		/// </summary>
		/// <param name="skewX">��бX��ƫ��ֵ</param>
		/// <param name="skewY">��бY��ƫ��ֵ</param>
		/// <returns></returns>
		__uref static Matrix CreateSkewRadians(double skewX, double skewY);

		/// <summary>
		/// ����б���Ⱦ���
		/// </summary>
		/// <param name="skewX">��бX��ƫ��ֵ</param>
		/// <param name="skewY">��бY��ƫ��ֵ</param>
		/// <param name="centerX">���ĵ�X������ֵ</param>
		/// <param name="centerY">���ĵ�Y������ֵ</param>
		/// <returns></returns>
		__uref static Matrix CreateSkewRadians(double skewX, double skewY, double centerX, double centerY);

		/// <summary>
		/// ����ƫ�ƾ���
		/// </summary>
		/// <param name="offsetX">X��ƫ��ֵ</param>
		/// <param name="offsetY">Y��ƫ��ֵ</param>
		/// <returns></returns>
		__uref static Matrix CreateTranslation(double offsetX, double offsetY);

		/// <summary>
		/// ��ָ���������
		/// </summary>
		/// <param name="matrix">ָ������</param>
		__uref void Multiply(const Matrix& matrix);

		/// <summary>
		/// ��תָ���Ƕ�
		/// </summary>
		/// <param name="angle">ָ���Ƕ�</param>
		__uref void Rotate(double angle);

		/// <summary>
		/// ��ָ�����ĵ���תһ���Ƕ�
		/// </summary>
		/// <param name="angle">ָ���Ƕ�</param>
		/// <param name="centerX">ָ�����ĵ�X������ֵ</param>
		/// <param name="centerY">ָ�����ĵ�Y������ֵ</param>
		__uref void RotateAt(double angle, double centerX, double centerY);

		/// <summary>
		/// Ӧ��ָ������ֵ
		/// </summary>
		/// <param name="scaleX">X������ֵ</param>
		/// <param name="scaleY">Y������ֵ</param>
		__uref void Scale(double scaleX, double scaleY);

		/// <summary>
		/// ��ָ�����ĵ�Ӧ��ָ������ֵ
		/// </summary>
		/// <param name="scaleX">X������ֵ</param>
		/// <param name="scaleY">Y������ֵ</param>
		/// <param name="centerX">ָ�����ĵ�X������ֵ</param>
		/// <param name="centerY">ָ�����ĵ�Y������ֵ</param>
		__uref void ScaleAt(double scaleX, double scaleY, double centerX, double centerY);

		/// <summary>
		/// Ӧ��ָ����бֵ
		/// </summary>
		/// <param name="skewX">X����бֵ</param>
		/// <param name="skewY">Y����бֵ</param>
		__uref void Skew(double skewX, double skewY);

		/// <summary>
		/// Ӧ��ָ��ƫ��ֵ
		/// </summary>
		/// <param name="offsetX">X��ƫ��ֵ</param>
		/// <param name="offsetY">Y��ƫ��ֵ</param>
		__uref void Translate(double offsetX, double offsetY);

		/// <summary>
		/// ��ָ�������
		/// </summary>
		/// <param name="x">ָ����X������ֵ</param>
		/// <param name="y">ָ����Y������ֵ</param>
		__uref void MultiplyPoint(double& x, double& y) const;

		/// <summary>
		/// �Ե�ǰ����任ָ����
		/// </summary>
		/// <param name="point">ָ����</param>
		/// <returns></returns>
		__uref Point Transform(const Point& point) const;

		/// <summary>
		/// �Ե�ǰ����任ָ���㼯��
		/// </summary>
		/// <param name="points">�㼯��.</param>
		/// <param name="pointCount">�����</param>
		__uref void Transform(Point* points, size_t pointCount) const;

		/// <summary>
		/// �Ե�ǰ����任ָ���㼯��
		/// </summary>
		/// <param name="points">The points.</param>
		__uref void Transform(std::vector<Point>& points) const;

		/// <summary>
		/// ��ת����
		/// </summary>
		__uref void Invert();

		/// <summary>
		/// M11
		/// </summary>
		__uproperty(get = GetM11, put = SetM11) double M11;
		/// <summary>
		/// M12
		/// </summary>
		__uproperty(get = GetM12, put = SetM12) double M12;
		/// <summary>
		/// M21
		/// </summary>
		__uproperty(get = GetM21, put = SetM21) double M21;
		/// <summary>
		/// M22
		/// </summary>
		__uproperty(get = GetM22, put = SetM22) double M22;
		/// <summary>
		/// M31
		/// </summary>
		__uproperty(get = GetM31, put = SetM31) double M31;
		/// <summary>
		/// M32
		/// </summary>
		__uproperty(get = GetM32, put = SetM32) double M32;
		/// <summary>
		/// ����ʽֵ
		/// </summary>
		__uproperty(get = GetDeterminant) double Determinant;
		/// <summary>
		/// �Ƿ�Ϊ��λ����
		/// </summary>
		__uproperty(get = GetIsIdentity) bool IsIdentity;
		/// <summary>
		///  �Ƿ���Ϊ��λ����
		/// </summary>
		__uproperty(get = GetIsDistinguishedIdentity) bool IsDistinguishedIdentity;
		/// <summary>
		/// �Ƿ����
		/// </summary>
		__uproperty(get = GetHasInverse) bool HasInverse;
		
		/// <summary>
		/// ���Խ���
		/// </summary>
		/// <param name="input">����ֵ.</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		static bool TryParse(const std::wstring& input, const CultureInfo& loc, Matrix& result);

		REFLECT_CLASS(Matrix)
	};

	class RUNTIME_API MatrixConverter : public TypeConverter
	{
	private:
		static std::mutex& getlocker();
		static std::weak_ptr<MatrixConverter> _thisWeakPtr;
	protected:
		MatrixConverter();
		MatrixConverter(MatrixConverter const&);
		void operator=(MatrixConverter const&);
	public:
		virtual ~MatrixConverter();

		static std::shared_ptr<MatrixConverter> GetSharedInstance();

		static MatrixConverter& GetInstance();

		bool CanConvertFrom(_type type) const;
		bool CanConvertTo(_type type) const;

		Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
		Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

		Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
		std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
	};
}