#include "Config.h"
#include <mfapi.h>
#include <mfidl.h>
#include <Shlwapi.h>
#include <Wmcontainer.h>
#include <mfreadwrite.h>
#include <stdio.h>
#include <mferror.h>
#include <string>
#include <Propvarutil.h>
#include <Propkey.h>

using namespace System;
using namespace System::Audio;

namespace System
{
	namespace Audio
	{
		__uclass __uobjdef(asm = Audio_Decoder_MF, ns = System::Audio, ver = 1.0)  AudioDecoder_MF : public AudioDecoder_base
		{
		private:
			static mutex locker;
			static AudioDecoder_MF* instance;
			static const wchar_t* _author;
			static const wchar_t* _description;
			static const wchar_t* _supports;
			static size_t pipeNum;
			AudioDecoder_MF();
			AudioDecoder_MF(const AudioDecoder_MF&) = delete;
		public:
			__udefctor static AudioDecoder_MF* Create();
			~AudioDecoder_MF();

			__uref Version GetVersion() const  override;
			__uref const wchar_t* GetAuthor() const  override;
			__uref const wchar_t* GetDescription() const  override;
			__uref const wchar_t* GetSupportFormat() const  override;

		public:

			__uref Result<AudioDecoderPipe, AudioDecoderError> OpenLocal(const wchar_t* localPath) override;///���ض�ȡ������Ƶ�ļ�

			__uref Result<AudioDecoderPipe, AudioDecoderError> CreateStream() override;///������ʽ�������

			__uref bool IsStream(const AudioDecoderPipe& pipe) override; ///��ȡ�Ƿ�Ϊ��ʽ�������

			__uref UInt64 GetNumberOfPipes() override;///��ȡ��ǰ��Ч��������

			__uref bool TryGetPipeInfo(const AudioDecoderPipe& pipe, AudioInfo& info) override; ///���Զ�ȡ��Ƶ��Ϣ

			__uref AudioDecoderError TryGetLocalAudioInfo(const wchar_t *path, AudioInfo& info) override;  ///����ֱ�ӻ�ȡ������Ƶ��Ϣ

			__uref Result<UInt64, AudioDecoderError> Read(const AudioDecoderPipe& pipe, AudioBuffer& buffer, size_t desiredNumSamples) override;///��ȡ��ƵPCM����,����ʵ�ʶ�ȡ��������

			__uref bool TrySeek(const AudioDecoderPipe& pipe, double posMS) override;///���ö�ȡ����

			__uref bool TryClose(const AudioDecoderPipe& pipe) override;///�رն�ȡ

			__uref double GetCurrentMS(const AudioDecoderPipe& pipe) override;///���ض�ȡ����

			REFLECT_CLASS(AudioDecoder_base)

		};
	}
}