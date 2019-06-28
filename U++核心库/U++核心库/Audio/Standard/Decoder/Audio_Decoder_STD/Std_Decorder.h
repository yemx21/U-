#pragma once
#include "Config.h"

namespace System
{
	namespace Audio
	{
		class Std_Decoder
		{
		public:
			virtual std::vector<std::wstring> GetSupportFormats() const { return {}; }

		public:

			virtual void OpenLocal(const wchar_t* localPath, const char* localPath2, Result<AudioDecoderPipe, AudioDecoderError>& ret) = 0;///���ض�ȡ������Ƶ�ļ�

			virtual void CreateStream(Result<AudioDecoderPipe, AudioDecoderError>& ret) = 0;///������ʽ�������

			virtual bool IsStream(const AudioDecoderPipe& pipe) = 0; ///��ȡ�Ƿ�Ϊ��ʽ�������

			virtual bool TryGetPipeInfo(const AudioDecoderPipe& pipe, AudioInfo& info) = 0; ///���Զ�ȡ��Ƶ��Ϣ

			virtual AudioDecoderError TryGetLocalAudioInfo(const wchar_t *path, const char* path2, AudioInfo& info) = 0;  ///����ֱ�ӻ�ȡ������Ƶ��Ϣ

			virtual void Read(const AudioDecoderPipe& pipe, AudioBuffer& buffer, size_t desiredNumSamples, Result<UInt64, AudioDecoderError>& ret) = 0;///��ȡ��ƵPCM����,����ʵ�ʶ�ȡ��������

			virtual bool TrySeek(const AudioDecoderPipe& pipe, double posMS) = 0;///���ö�ȡ����

			virtual bool TryClose(const AudioDecoderPipe& pipe) = 0;///�رն�ȡ

			virtual double GetCurrentMS(const AudioDecoderPipe& pipe) = 0;///���ض�ȡ����

		};
	}
}

