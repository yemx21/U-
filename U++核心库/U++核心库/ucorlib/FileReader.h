#pragma once
#include "Config.h"
#include <string>


namespace System
{
	namespace IO
	{
		/// <summary>
		/// �ļ���ȡ��
		/// </summary>
		 class RUNTIME_API FileReader
		{
		public:
			/// <summary>
			/// ������һ�����õ��ַ�
			/// </summary>
			/// <param name="nothrow">�޴���׽</param>
			/// <returns>�ַ�</returns>
			virtual int Peek(bool nothrow = true);

			/// <summary>
			/// ��ȡ��һ�����õ��ַ�
			/// </summary>
			/// <param name="nothrow">�޴���׽</param>
			/// <returns>�ַ�</returns>
			virtual int Read(bool nothrow = true);

			/// <summary>
			/// ��ȡ�ַ�
			/// </summary>
			/// <param name="buffer">�ַ�</param>
			/// <param name="bufferCount">�ַ���</param>
			/// <param name="index">�ַ���ʼ����</param>
			/// <param name="count">��ȡ��</param>
			/// <param name="nothrow">�޴���׽</param>
			/// <returns>ʵ�ʶ�ȡ�ַ���</returns>
			virtual ULong Read(wchar_t* buffer, ULong bufferCount, ULong index, ULong count, bool nothrow = true);

			/// <summary>
			/// ��ȡ�ַ���
			/// </summary>
			/// <param name="buffer">�ַ�</param>
			/// <param name="bufferBytes">�ַ���С</param>
			/// <param name="index">�ַ���ʼ����</param>
			/// <param name="count">��ȡ��</param>
			/// <param name="nothrow">�޴���׽</param>
			/// <returns>ʵ�ʶ�ȡ�ַ���</returns>
			virtual ULong ReadBlock(wchar_t* buffer, ULong bufferBytes, ULong index, ULong count, bool nothrow = true);

			/// <summary>
			/// ��ȡ��һ��
			/// </summary>
			/// <param name="nothrow">�޴���׽</param>
			/// <returns>�ַ�</returns>
			virtual std::wstring ReadLine(bool nothrow = true);

			/// <summary>
			/// ��ȡ����β
			/// </summary>
			/// <param name="nothrow">�޴���׽</param>
			/// <returns>�ַ�</returns>
			virtual std::wstring ReadToEnd(bool nothrow = true);

			/// <summary>
			/// �ж��Ѿ���ȡ����β
			/// </summary>
			virtual bool IsEndOfStream();

		};
	}
}