#include "Config.h"
#include "Extras\sndfile.h"

using namespace System;
using namespace System::Audio;

namespace System
{
	namespace Audio
	{
		class SNDAPI
		{
		public:
			static SNDFILE* 	(*sf_open)(const char *path, int mode, SF_INFO *sfinfo);
			static int(*sf_close)(SNDFILE *sndfile);
			static int(*sf_command)(SNDFILE *sndfile, int command, void *data, int datasize);

			static sf_count_t(*sf_read_short)(SNDFILE *sndfile, short *ptr, sf_count_t items);
			static sf_count_t(*sf_read_int)(SNDFILE *sndfile, int *ptr, sf_count_t items);
			static sf_count_t(*sf_read_float)(SNDFILE *sndfile, float *ptr, sf_count_t items);
			static sf_count_t(*sf_read_double)(SNDFILE *sndfile, double *ptr, sf_count_t items);
			static sf_count_t(*sf_read_raw)(SNDFILE *sndfile, void *ptr, sf_count_t bytes);
			static sf_count_t(*sf_seek)(SNDFILE *sndfile, sf_count_t frames, int whence);

			static const char* (*sf_strerror)(SNDFILE *sndfile);

			#define CHECK_API(test) if((test)==nullptr) goto ERR

			static HMODULE module;
			static Result<bool> DynmaicInit()
			{
				Result<bool> result(false);
				module = LoadLibraryW(L"libsndfile-1.dll");
				if (module)
				{
					CHECK_API(sf_open = (SNDFILE*(*)(const char *path, int mode, SF_INFO *sfinfo)) GetProcAddress(module, "sf_open"));
					CHECK_API(sf_close = (int(*)(SNDFILE *)) GetProcAddress(module, "sf_close"));
					CHECK_API(sf_command = (int(*)(SNDFILE *sndfile, int command, void *data, int datasize)) GetProcAddress(module, "sf_command"));
					CHECK_API(sf_read_raw = (sf_count_t(*)(SNDFILE *sndfile, void *ptr, sf_count_t items)) GetProcAddress(module, "sf_read_raw"));
					CHECK_API(sf_read_short = (sf_count_t(*)(SNDFILE *sndfile, short *ptr, sf_count_t items)) GetProcAddress(module, "sf_read_short"));
					CHECK_API(sf_read_int = (sf_count_t(*)(SNDFILE *sndfile, int *ptr, sf_count_t items)) GetProcAddress(module, "sf_read_int"));
					CHECK_API(sf_read_float = (sf_count_t(*)(SNDFILE *sndfile, float *ptr, sf_count_t items)) GetProcAddress(module, "sf_read_float"));
					CHECK_API(sf_read_double= (sf_count_t(*)(SNDFILE *sndfile, double *ptr, sf_count_t items)) GetProcAddress(module, "sf_read_double"));
					CHECK_API(sf_seek = (sf_count_t(*)(SNDFILE *sndfile, sf_count_t frames, int)) GetProcAddress(module, "sf_seek"));
					CHECK_API(sf_strerror = (const char*(*)(SNDFILE *sndfile))GetProcAddress(module, "sf_strerror"));
					result.Value = true;
					return result;
				ERR:
					if (FreeLibrary(module))
						module = NULL;
					else
						result.WriteMessage(L"can not free libsndfile-1.dll");
					return result;
				}
				else
				{
					result.WriteMessage(L"can not find or load libsndfile-1.dll");
				}
				return result;
			}

			static Result<bool> DynamicExit()
			{
				Result<bool> result(false);
				if (module)
				{
					if (FreeLibrary(module))
					{
						module = NULL;
						result.Value = true;
					}
					else
						result.WriteMessage(L"can not free libsndfile-1.dll");
				}
				else
				{
					result.Value = true;
					result.WriteMessage(L"already free libsndfile-1.dll");
				}
				return result;
			}
		};

		__uclass __uobjdef(asm = Audio_Decoder_SND, ns = System::Audio, ver = 1.0)  AudioDecoder_SND : public AudioDecoder_base
		{
		private:
			static mutex locker;
			static AudioDecoder_SND* instance;
			static const wchar_t* _author;
			static const wchar_t* _description;
			static const wchar_t* _supports;
			static size_t pipeNum;
			AudioDecoder_SND();
			AudioDecoder_SND(const AudioDecoder_SND&) = delete;
		public:
			__udefctor static AudioDecoder_SND* Create();
			~AudioDecoder_SND();

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