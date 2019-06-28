#pragma once
#include "Point.h"
#include "Size.h"
#include "Rect.h"
namespace System
{	
	/// <summary>
	/// ����������
	/// </summary>
	 class RUNTIME_API FloatingHelper
	{
	public :
		/// <summary>
		/// �ж��Ƿ�ӽ�
		/// </summary>
		/// <param name="a">�����ȸ�����A</param>
		/// <param name="b">�����ȸ�����B</param>
		/// <returns></returns>
		static bool AreClose(float a, float b) ;

		/// <summary>
		/// �ж��Ƿ�ӽ����������
		/// </summary>
		/// <param name="numerator">����</param>
		/// <param name="denominator">��ĸ</param>
		static bool IsCloseToDivideByZero(float numerator, float denominator) ;

		/// <summary>
		/// �ж��Ƿ�Ϊһ
		/// </summary>
		/// <param name="a">�����ȸ�����A</param>
		static bool IsOne(float a) ;

		/// <summary>
		/// �ж��Ƿ�Ϊ��
		/// </summary>
		/// <param name="a">�����ȸ�����A</param>
		static bool IsZero(float a) ;

		/// <summary>
		/// �ж��Ƿ�ӽ�
		/// </summary>
		/// <param name="a">˫���ȸ�����A</param>
		/// <param name="b">˫���ȸ�����B</param>
		/// <returns></returns>
		static bool AreClose(double value1, double value2) ;

		/// <summary>
		/// �ж��Ƿ�ӽ�
		/// </summary>
		/// <param name="point1">��1</param>
		/// <param name="point2">��2</param>
		/// <returns></returns>
		static bool AreClose(const Point& point1, const Point& point2) ;

		/// <summary>
		/// �ж��Ƿ�ӽ�
		/// </summary>
		/// <param name="size1">��С1</param>
		/// <param name="size2">��С2</param>
		/// <returns></returns>
		static bool AreClose(const Size& size1, const Size& size2) ;

		/// <summary>
		/// �ж��Ƿ�ӽ�
		/// </summary>
		/// <param name="rect1">����1</param>
		/// <param name="rect2">����2</param>
		/// <returns></returns>
		static bool AreClose(const Rect& rect1, const Rect& rect2) ;

		/// <summary>
		/// ˫���ȸ�����ת��������
		/// </summary>
		/// <param name="val">˫���ȸ�����</param>
		/// <returns>int.</returns>
		static int DoubleToInt(double val) ;

		/// <summary>
		/// �ж��Ƿ����
		/// </summary>
		/// <param name="value1">˫���ȸ�����1</param>
		/// <param name="value2">˫���ȸ�����2</param>
		/// <returns></returns>
		static bool GreaterThan(double value1, double value2) ;

		/// <summary>
		/// �ж��Ƿ����Լ����
		/// </summary>
		/// <param name="value1">˫���ȸ�����1</param>
		/// <param name="value2">˫���ȸ�����2</param>
		/// <returns></returns>
		static bool GreaterThanOrClose(double value1, double value2) ;

		/// <summary>
		/// �ж��Ƿ������һ֮��
		/// </summary>
		/// <param name="val">˫���ȸ�����</param>
		static bool IsBetweenZeroAndOne(double val) ;

		/// <summary>
		/// �ж��Ƿ�Ϊ������
		/// </summary>
		/// <param name="value">˫���ȸ�����</param>
		static bool IsNaN(double value) ;

		/// <summary>
		/// �ж��Ƿ�����
		/// </summary>
		/// <param name="value">˫���ȸ�����</param>
		static bool IsInfinity(double value) ;

		/// <summary>
		///�ж��Ƿ�Ϊ�����ֻ�����
		/// </summary>
		/// <param name="value">˫���ȸ�����</param>
		static bool IsNaNOrInfinity(double value) ;

		/// <summary>
		/// �ж��Ƿ�������
		/// </summary>
		/// <param name="value">˫���ȸ�����</param>
		static bool IsPositiveInfinity(double value) ;

		/// <summary>
		/// �ж��Ƿ�����
		/// </summary>
		/// <param name="value">˫���ȸ�����</param>
		static bool IsNegativeInfinity(double value) ;

		/// <summary>
		/// �ж��Ƿ�Ϊһ
		/// </summary>
		/// <param name="value">˫���ȸ�����</param>
		static bool IsOne(double value) ;

		/// <summary>
		/// �ж��Ƿ�Ϊ��
		/// </summary>
		/// <param name="value">˫���ȸ�����</param>
		static bool IsZero(double value) ;

		/// <summary>
		/// �ж�С��
		/// </summary>
		/// <param name="value1">˫���ȸ�����1</param>
		/// <param name="value2">˫���ȸ�����2</param>
		/// <returns></returns>
		static bool LessThan(double value1, double value2) ;

		/// <summary>
		/// �ж�С��Լ����
		/// </summary>
		/// <param name="value1">˫���ȸ�����1</param>
		/// <param name="value2">˫���ȸ�����2</param>
		/// <returns></returns>
		static bool LessThanOrClose(double value1, double value2) ;

		/// <summary>
		/// �жϾ����Ƿ����������
		/// </summary>
		/// <param name="rect">����</param>
		/// <returns></returns>
		static bool RectHasNaN(const Rect& rect) ;
	};
}