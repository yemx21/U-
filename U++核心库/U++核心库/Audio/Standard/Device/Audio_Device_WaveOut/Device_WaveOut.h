#pragma once
#include "Config.h"
#include <MMReg.h>
#include <Ks.h>
#include <Ksmedia.h>

#define MAX_WAVEBLOCKS    256

namespace System
{
	namespace Audio
	{
		struct WOBuffer : ZeroStruct<WOBuffer>
		{
			ulong WaitEndTime; ///��̬�ȴ����ų�ʱʱ��
			ulong SampleTime;///������������
			ulong BufferBytes;    ///�����������ݴ�С
			ulong WriteOffset;
			ulong OutputWrittenPointer;
			WAVEFORMATEXTENSIBLE WFE;///���θ�ʽ��չ
			SampleInfo Info;
			HANDLE Mutex;
			uint128 ID;
			int WaitEndFlag;
			bool WritePlay;
			double Vol;
			double Pan;
			bool DestroyDEV;

			HWAVEOUT dev = NULL;
			unsigned int  ScheduledBlocks;
			int   PlayedWaveHeadersCount;
			WAVEHDR*  PlayedWaveHeaders[MAX_WAVEBLOCKS];

			WOBuffer()
			{

			}

			~WOBuffer()
			{

			}

		};


		__uclass __uobjdef(asm = Audio_Device_WaveOut, ns = System::Audio, ver = 1.0)  AudioDevice_WaveOut : public AudioDevice_base
		{
		private:
			static const wchar_t* _author;
			static const wchar_t* _description;
			static const wchar_t* _supports;
			static mutex locker;
			static CRITICAL_SECTION cs;
			static AudioDevice_WaveOut * instance;
			std::vector<WOBuffer*> Pipes;

			static void CALLBACK wave_callback(HWAVE hWave, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2);

			void Free(WOBuffer* bufffer);

		protected:
			AudioDevice_WaveOut();

			AudioDevice_WaveOut(const AudioDevice_WaveOut&) = delete;

		public:
			__udefctor static AudioDevice_WaveOut* Create();

			~AudioDevice_WaveOut();

			__uref Version GetVersion() const  override;
			__uref const wchar_t* GetAuthor() const  override;
			__uref const wchar_t* GetDescription() const  override;
			__uref const wchar_t* GetSupportFormat() const  override;

		public:
			__uref Result<AudioDevicePipe, AudioDeviceError> Open(const uint128& owner, ulong bufferTimeMs, const SampleInfo& info) override;///������Ƶ������Ϣ

			__uref bool GetIsMultiPipesSupported() const override; ///�Ƿ�֧�ֶ����

			__uref bool GetIsCurrentExclusive() const override; ///��ȡ��ǰ�Ƿ��Ƕ�ռģʽ

			__uref unsigned int GetNumberOfPipes() override;///��ȡ��ǰ��Ч��������

			__uref SampleInfo GetPipeInfo(const AudioDevicePipe& pipe) override; ///��ȡ�����豸�ĸ�ʽ��Ϣ

			__uref void Write(const AudioDevicePipe& pipe, const void* buffer, uint bytes) override;	///д�����ݣ�����д�����ݴ�С

			__uref int CanWrite(const AudioDevicePipe& pipe) override;	///������д�������bytes����

			__uref bool WaitEnd(const AudioDevicePipe& pipe) override;///�ȴ�������������ϲ������Ƿ����ڲ���

			__uref bool Play(const AudioDevicePipe& pipe) override;///����

			__uref bool Pause(const AudioDevicePipe& pipe) override;///��ͣ

			__uref bool Stop(const AudioDevicePipe& pipe) override;///ֹͣ

			__uref void Flush(const AudioDevicePipe& pipe, int timeMS) override;/// ��ջ������ݲ��������ʱ��

			__uref Result<bool, double> SetVolume(const AudioDevicePipe& pipe, double volume) override; /// 0-1.0

			__uref Result<bool, double> SetPan(const AudioDevicePipe& pipe, double pan) override; ///  -1.0 to 1.0

			__uref Result<bool, double> GetOutputTime(const AudioDevicePipe& pipe) override;		///�����Ѳ���ʱ�� 

			__uref Result<bool, double> GetWrittenTime(const AudioDevicePipe& pipe) override;		///������д��ʱ�� 

			__uref Result<bool, unsigned long> GetWrittenPosition(const AudioDevicePipe& pipe) override;   ///������д���������

			REFLECT_CLASS(AudioDevice_WaveOut)

		};
	}
}