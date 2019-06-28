#pragma once
#include "Config.h"
using namespace System;
using namespace System::Audio;

namespace System
{
	namespace Audio
	{
		class AudioDevice_XAudio2 : public AudioDevice_base
		{
		protected:
			AudioDevice_XAudio2();

			AudioDevice_XAudio2(const AudioDevice_XAudio2&) = delete;

		public:

			~AudioDevice_XAudio2();

			Result<AudioDevicePipe, AudioDeviceError> Open(const uint128& owner, ulong bufferTimeMs, const SampleInfo& info) override;///������Ƶ������Ϣ

			bool GetIsMultiPipesSupported() const override; ///�Ƿ�֧�ֶ����

			bool GetIsCurrentExclusive() const override; ///��ȡ��ǰ�Ƿ��Ƕ�ռģʽ

			unsigned int GetNumberOfPipes() override;///��ȡ��ǰ��Ч��������

			SampleInfo GetPipeInfo(const AudioDevicePipe& pipe) override; ///��ȡ�����豸�ĸ�ʽ��Ϣ

			void Write(const AudioDevicePipe& pipe, const void* buffer, uint bytes) override;	///д�����ݣ�����д�����ݴ�С

			int CanWrite(const AudioDevicePipe& pipe) override;	///������д�������bytes����

			bool WaitEnd(const AudioDevicePipe& pipe) override;///�ȴ�������������ϲ������Ƿ����ڲ���

			bool Play(const AudioDevicePipe& pipe) override;///����

			bool Pause(const AudioDevicePipe& pipe) override;///��ͣ

			bool Stop(const AudioDevicePipe& pipe) override;///ֹͣ

			void Flush(const AudioDevicePipe& pipe, int timeMS) override;/// ��ջ������ݲ��������ʱ��

			void SetVolume(const AudioDevicePipe& pipe, double volume) override; /// 0-1.0

			void SetPan(const AudioDevicePipe& pipe, double pan) override; ///  -1.0 to 1.0

			double GetOutputTime(const AudioDevicePipe& pipe) override;		///�����Ѳ���ʱ�� 

			double GetWrittenTime(const AudioDevicePipe& pipe) override;		///������д��ʱ�� 

			unsigned long GetWrittenPosition(const AudioDevicePipe& pipe) override;   ///������д���������

			REFLECT_CLASS(AudioDevice_XAudio2)

		};
	}
}