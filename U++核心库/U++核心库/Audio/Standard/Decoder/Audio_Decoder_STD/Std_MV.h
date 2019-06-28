#pragma once
#include "Config.h"
#include "Std_Decorder.h"

using namespace System;
using namespace System::Audio;

namespace System
{
	namespace Audio
	{
		class Std_MV : public Std_Decoder
		{
		public:
			Std_MV();
			Std_MV(const Std_MV&) = delete;
			~Std_MV();

			std::vector<std::wstring> GetSupportFormats() const override;

		public:

			void OpenLocal(const wchar_t* localPath, const char* localPath2, Result<AudioDecoderPipe, AudioDecoderError>& ret) override;///���ض�ȡ������Ƶ�ļ�

			void CreateStream(Result<AudioDecoderPipe, AudioDecoderError>& ret) override;///������ʽ�������

			bool IsStream(const AudioDecoderPipe& pipe) override; ///��ȡ�Ƿ�Ϊ��ʽ�������

			bool TryGetPipeInfo(const AudioDecoderPipe& pipe, AudioInfo& info) override; ///���Զ�ȡ��Ƶ��Ϣ

			AudioDecoderError TryGetLocalAudioInfo(const wchar_t *path, const char* path2, AudioInfo& info) override;  ///����ֱ�ӻ�ȡ������Ƶ��Ϣ

			void Read(const AudioDecoderPipe& pipe, AudioBuffer& buffer, size_t desiredNumSamples, Result<UInt64, AudioDecoderError>& ret) override;///��ȡ��ƵPCM����,����ʵ�ʶ�ȡ��������

			bool TrySeek(const AudioDecoderPipe& pipe, double posMS) override;///���ö�ȡ����

			bool TryClose(const AudioDecoderPipe& pipe) override;///�رն�ȡ

			double GetCurrentMS(const AudioDecoderPipe& pipe) override;///���ض�ȡ����
		};
	}
}
