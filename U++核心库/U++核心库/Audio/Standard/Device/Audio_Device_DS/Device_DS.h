#pragma once
#include "Config.h"

namespace System
{
	namespace Audio
	{
		struct DSBuffer : ZeroStruct<DSBuffer>
		{
			UInt64 WaitEndTime;
			UInt64 SampleTime;
			size_t BufferBytes;
			UInt64 WriteOffset;
			UInt64 OutputWrittenPointer;
			void* DSB;
			void* DsNotify;
			SampleInfo Info;
			void* NotifyEvent;
			void* Mutex;
			bool DestroyDS;
			UInt128 ID;
			int WaitEndFlag;
			bool WritePlay;
			double Vol;
			double Pan;
		};

		__uclass __uobjdef(asm = Audio_Device_DS, ns = System::Audio, ver = 1.0)  AudioDevice_DS : public AudioDevice_base
		{
		private:				
			static const wchar_t* _author;
			static const wchar_t* _description;
			static const wchar_t* _supports;
			static std::mutex locker;
			CriticalSection cs;
			static AudioDevice_DS * instance;
			std::vector<DSBuffer*> Pipes;
			void* m_DS;///DirectSound����

			bool ClearBuffer(DSBuffer* Handle);///��ջ�������

		protected:
			AudioDevice_DS();

			AudioDevice_DS(const AudioDevice_DS&) = delete;

		public:
			__udefctor static AudioDevice_DS* Create();

			~AudioDevice_DS();

			__uref Version GetVersion() const  override;
			__uref const wchar_t* GetAuthor() const  override;
			__uref const wchar_t* GetDescription() const  override;
			__uref const wchar_t* GetSupportFormat() const  override;

		public:
			__uref Result<AudioDevicePipe, AudioDeviceError> Open(const UInt128& owner, UInt64 desiredBufferMs, const SampleInfo& desiredInfo, SampleInfo& actualInfo, UInt64& actualBufferMs) override;///������Ƶ������Ϣ

			__uref bool GetIsMultiPipesSupported() const override; ///�Ƿ�֧�ֶ����

			__uref bool GetIsCurrentExclusive() const override; ///��ȡ��ǰ�Ƿ��Ƕ�ռģʽ

			__uref UInt64 GetNumberOfPipes() override;///��ȡ��ǰ��Ч��������

			__uref SampleInfo GetPipeInfo(const AudioDevicePipe& pipe) override; ///��ȡ�����豸�ĸ�ʽ��Ϣ

			__uref Result<bool, UInt64> Write(const AudioDevicePipe& pipe, const void* buffer, UInt64 bytes) override;	///д�����ݣ�����д�����ݴ�С

			__uref UInt64 CanWrite(const AudioDevicePipe& pipe) override;	///������д�������bytes����

			__uref bool Drain(const AudioDevicePipe& pipe) override;///�ȴ�������������ϲ������Ƿ����ڲ���

			__uref bool Play(const AudioDevicePipe& pipe) override;///����

			__uref bool Pause(const AudioDevicePipe& pipe) override;///��ͣ

			__uref bool Stop(const AudioDevicePipe& pipe) override;///ֹͣ

			__uref void Flush(const AudioDevicePipe& pipe, UInt64 timeMS) override;/// ��ջ������ݲ��������ʱ��

			__uref Result<bool, double> SetVolume(const AudioDevicePipe& pipe, double volume) override; /// 0-1.0

			__uref Result<bool, double> SetPan(const AudioDevicePipe& pipe, double pan) override; ///  -1.0 to 1.0

			__uref Result<bool, double> GetOutputTime(const AudioDevicePipe& pipe) override;		///�����Ѳ���ʱ�� 

			__uref Result<bool, double> GetWrittenTime(const AudioDevicePipe& pipe) override;		///������д��ʱ�� 

			__uref Result<bool, UInt64> GetWrittenPosition(const AudioDevicePipe& pipe) override;   ///������д���������

			REFLECT_CLASS(AudioDevice_DS)

		};
	}
}
