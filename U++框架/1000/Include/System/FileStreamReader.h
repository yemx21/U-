#pragma once
#include "FileReader.h"
#include "FileStream.h"
#include "Encodings.h"
#include "CultureInfo.h"
#include <codecvt>
#include <mbstring.h>

using namespace System;

namespace System
{
	namespace IO
	{
		/// <summary>
		/// �ļ�����ȡ
		/// </summary>
		class RUNTIME_API FileStreamReader : public FileReader
		{
		private:		
			static const int DefaultFileStreamBufferSize = 4096;
			static const int MinBufferSize = 128;
			FileStream* base;

			char* byteBuffer;

			ULong byteBufferSize;

			wchar_t* charBuffer;

			int charPos;

			int charLen;

			int byteLen;

			int bytePos;

			int _maxCharsPerBuffer;

			bool _checkPreamble;

			bool _isBlocked;

			bool _closable;

			Encodings _encoding;

			CultureInfo* _loc;

			int ReadBuffer();

		public:
			~FileStreamReader();

			/// <summary>
			/// ���� <see cref="FileStreamReader"/> ʵ��
			/// </summary>
			/// <remarks>��С�ļ������СΪ128���ҽ���ʹ��Ĭ�ϵ�4096�����Զ��建���С��ѡ��128�ı���</remarks>
			/// <param name="path">�ļ�λ��</param>
			/// <param name="encoding">����</param>
			/// <param name="nothrow">�޴���׽</param>
			/// <param name="detectEncodingFromByteOrderMarks">�Զ�������.</param>
			/// <param name="loc">��������Ϣ</param>
			/// <param name="bufferSize">�ļ������С</param>	
			FileStreamReader(const wchar_t* path, Encodings encoding, bool nothrow = true, bool detectEncodingFromByteOrderMarks = true, const CultureInfo& loc = CultureInfo::Current(), int bufferSize = DefaultFileStreamBufferSize);
			
			/// <summary>
			/// ������һ�����õ��ַ�
			/// </summary>
			/// <param name="nothrow">�޴���׽</param>
			/// <returns>�ַ�</returns>
			int Peek(bool nothrow = true) override;

			/// <summary>
			/// �ж��Ѿ���ȡ����β
			/// </summary>
			bool IsEndOfStream() override;

			/// <summary>
			/// ��ȡ��һ�����õ��ַ�
			/// </summary>
			/// <param name="nothrow">�޴���׽</param>
			/// <returns>�ַ�</returns>
			int Read(bool nothrow = true) override;

			/// <summary>
			/// ��ȡ�ַ�
			/// </summary>
			/// <param name="userBuffer">�ַ�</param>
			/// <param name="userOffset">�ַ�����</param>
			/// <param name="desiredChars">�����ַ���</param>
			/// <param name="readToUserBuffer">�Ƿ�ɹ���ȡ</param>
			/// <returns>�ַ���</returns>
			ULong ReadBuffer(wchar_t* userBuffer, int userOffset, int desiredChars, bool& readToUserBuffer);

			/// <summary>
			/// ��ȡ�ַ�
			/// </summary>
			/// <param name="buffer">�ַ�</param>
			/// <param name="bufferCount">�ַ���</param>
			/// <param name="index">�ַ���ʼ����</param>
			/// <param name="count">��ȡ��</param>
			/// <param name="nothrow">�޴���׽</param>
			/// <returns>ʵ�ʶ�ȡ�ַ���</returns>
			ULong Read(wchar_t* buffer, ULong bufferCount, ULong index, ULong count, bool nothrow = true)override;

			/// <summary>
			/// ��ȡ�ַ���
			/// </summary>
			/// <param name="buffer">�ַ�</param>
			/// <param name="bufferBytes">�ַ���С</param>
			/// <param name="index">�ַ���ʼ����</param>
			/// <param name="count">��ȡ��</param>
			/// <param name="nothrow">�޴���׽</param>
			/// <returns>ʵ�ʶ�ȡ�ַ���</returns>
			ULong ReadBlock(wchar_t* buffer, ULong bufferCount, ULong index, ULong count, bool nothrow = true) override;

			/// <summary>
			/// ��ȡ��һ��
			/// </summary>
			/// <param name="nothrow">�޴���׽</param>
			/// <returns>�ַ�</returns>
			std::wstring ReadLine(bool nothrow = true) override;

			/// <summary>
			/// ��ȡ����β
			/// </summary>
			/// <param name="nothrow">�޴���׽</param>
			/// <returns>�ַ�</returns>
			std::wstring ReadToEnd(bool nothrow = true) override;

		};

	}
}