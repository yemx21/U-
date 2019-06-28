#pragma once
#include "Config.h"

using namespace std;

namespace System
{
	/// <summary>
	/// �Ƚ���
	/// </summary>
	class RUNTIME_API ComparisonHelper
	{
	public:
		/// <summary>
		/// �������
		/// </summary>
		/// <param name="num1">����1</param>
		/// <param name="num2">����2</param>
		/// <returns></returns>
		template<typename T>
		static T Max(T num1, T num2)
		{
			return num1 >= num2 ? num1 : num2;
		}
		/// <summary>
		/// ��С����
		/// </summary>
		/// <param name="num1">����1</param>
		/// <param name="num2">����2</param>
		/// <returns></returns>
		template<typename T>
		static T Min(T num1, T num2)
		{
			return num1 < num2 ? num1 : num2;
		}
	};
}