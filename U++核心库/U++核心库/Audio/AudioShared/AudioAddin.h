#pragma once
#include "Addin.h"
using namespace System;

namespace System
{
	namespace Audio
	{
		__uenum __uobjdef(asm = AudioShared, ns = System::Audio, ver = 1.0) AUDIOSHARED_API AudioDeviceError : __uobject
		{
			__uvalue_begin(AudioDeviceError, UShort)
			__uvalue(OK)
			__uvalue(Failed)
			__uvalue(UnSupportedInfo)
			__uvalue(DeviceError)
			__uvalue_end(AudioDeviceError, OK)
		};

		__uenum __uobjdef(asm = AudioShared, ns = System::Audio, ver = 1.0) AUDIOSHARED_API AudioDecoderError : __uobject
		{
			__uvalue_begin(AudioDecoderError, UShort)
			__uvalue(OK)
			__uvalue(Failed)
			__uvalue(InvalidPath)
			__uvalue(UnSupported)
			__uvalue(End)
			__uvalue_end(AudioDecoderError, OK)
		};

		typedef safe_void_ptr AudioDevicePipe;
		typedef safe_void_ptr AudioDecoderPipe;
		typedef safe_void_ptr AudioDSPPipe;
		typedef safe_void_ptr AudioEncoderPipe;
		typedef safe_void_ptr AudioVisualPipe;

		__uclass __uobjdef(asm = AudioShared, ns = System::Audio, ver = 1.0) AUDIOSHARED_API AudioDevice_base : public Addin_base
		{
		protected:
			AudioDevice_base();

			AudioDevice_base(const AudioDevice_base&) = delete;

		public:

			virtual ~AudioDevice_base();

			__uref virtual Result<AudioDevicePipe, AudioDeviceError> Open(const UInt128& owner, UInt64 desiredBufferMs, const SampleInfo& desiredInfo, SampleInfo& actualInfo, UInt64& actualBufferMs);///������Ƶ������Ϣ

			__uref virtual bool GetIsMultiPipesSupported() const; ///�Ƿ�֧�ֶ����

			__uref virtual bool GetIsCurrentExclusive() const; ///��ȡ��ǰ�Ƿ��Ƕ�ռģʽ

			__uref virtual UInt64 GetNumberOfPipes();///��ȡ��ǰ��Ч��������

			__uref virtual SampleInfo GetPipeInfo(const AudioDevicePipe& pipe); ///��ȡ�����豸�ĸ�ʽ��Ϣ

			__uref virtual Result<bool, UInt64> Write(const AudioDevicePipe& pipe, const void* buffer, UInt64 bytes);	///д�����ݣ�����д�����ݴ�С

			__uref virtual UInt64 CanWrite(const AudioDevicePipe& pipe);	///������д�������bytes����

			__uref virtual bool Drain(const AudioDevicePipe& pipe);///�ȴ�������������ϲ������Ƿ����ڲ���

			__uref virtual bool Play(const AudioDevicePipe& pipe);///����

			__uref virtual bool Pause(const AudioDevicePipe& pipe);///��ͣ

			__uref virtual bool Stop(const AudioDevicePipe& pipe);///ֹͣ

			__uref virtual void Flush(const AudioDevicePipe& pipe, UInt64 timeMS);/// ��ջ������ݲ��������ʱ��

			__uref virtual Result<bool, double> SetVolume(const AudioDevicePipe& pipe, double volume); /// 0-1.0

			__uref virtual Result<bool, double> SetPan(const AudioDevicePipe& pipe, double pan); ///  -1.0 to 1.0

			__uref virtual Result<bool, double> GetOutputTime(const AudioDevicePipe& pipe);		///�����Ѳ���ʱ�� 

			__uref virtual Result<bool, double> GetWrittenTime(const AudioDevicePipe& pipe);		///������д��ʱ�� 

			__uref virtual Result<bool, UInt64> GetWrittenPosition(const AudioDevicePipe& pipe);   ///������д���������

			REFLECT_CLASS(AudioDevice_base)

		};

		__uclass __uobjdef(asm = AudioShared, ns = System::Audio, ver = 1.0) AUDIOSHARED_API AudioDecoder_base : public Addin_base
		{
		protected:
			AudioDecoder_base();

			AudioDecoder_base(const AudioDecoder_base&) = delete;

		public:

			virtual ~AudioDecoder_base();

			__uref virtual Result<AudioDecoderPipe, AudioDecoderError> OpenLocal(const wchar_t* localPath);///���ض�ȡ������Ƶ�ļ�

			__uref virtual Result<AudioDecoderPipe, AudioDecoderError> CreateStream();///������ʽ�������

			__uref virtual bool IsStream(const AudioDecoderPipe& pipe); ///��ȡ�Ƿ�Ϊ��ʽ�������

			__uref virtual UInt64 GetNumberOfPipes();///��ȡ��ǰ��Ч��������

			__uref virtual bool TryGetPipeInfo(const AudioDevicePipe& pipe, AudioInfo& info); ///���Զ�ȡ��Ƶ��Ϣ

			__uref virtual AudioDecoderError TryGetLocalAudioInfo(const wchar_t *path, AudioInfo& info);  ///����ֱ�ӻ�ȡ������Ƶ��Ϣ

			__uref virtual Result<UInt64, AudioDecoderError> Read(const AudioDevicePipe& pipe, AudioBuffer& buffer, size_t desiredNumSamples);///��ȡ��ƵPCM����,����ʵ�ʶ�ȡ��������

			__uref virtual bool TrySeek(const AudioDevicePipe& pipe, double posMS);///���ö�ȡ����

			__uref virtual bool TryClose(const AudioDevicePipe&pipe);///�رն�ȡ

			__uref virtual double GetCurrentMS(const AudioDevicePipe& pipe);///���ض�ȡ����

			REFLECT_CLASS(AudioDecoder_base)
		};

		__uclass __uobjdef(asm = AudioShared, ns = System::Audio, ver = 1.0) AUDIOSHARED_API AudioDSP_base : public Addin_base
		{
		protected:
			AudioDSP_base();

			AudioDSP_base(const AudioDSP_base&) = delete;

		public:

			virtual ~AudioDSP_base();

			__uref virtual AudioDSPPipe Create(); ///������Ч����

			__uref virtual UInt64 GetNumberOfPipes();///��ȡ��ǰ��Ч��������

			__uref virtual bool Destory(const AudioDSPPipe& pipe);///����Ч����

			__uref virtual int Run(const AudioDSPPipe& pipe, AudioBuffer& buffer);///������Ч���任

			REFLECT_CLASS(AudioDSP_base)
		};

		__uclass __uobjdef(asm = AudioShared, ns = System::Audio, ver = 1.0) AUDIOSHARED_API AudioEncoder_base : public Addin_base
		{
		protected:
			AudioEncoder_base();

			AudioEncoder_base(const AudioEncoder_base&) = delete;

		public:

			virtual ~AudioEncoder_base();

			__uref virtual AudioEncoderPipe Create(const wchar_t* path, const SampleInfo& info, const SampleInfo& encCfg);///������Ƶ�ļ�

			__uref virtual UInt64 GetNumberOfPipes();///��ȡ��ǰ��Ч��������

			__uref virtual void AddData(const AudioEncoderPipe& pipe, const AudioBuffer& buffer);///������ƵPCM����

			__uref virtual void FinshData(const AudioEncoderPipe& pipe);

			REFLECT_CLASS(AudioEncoder_base)
		};

		__uclass __uobjdef(asm = AudioShared, ns = System::Audio, ver = 1.0) AUDIOSHARED_API AudioVisual_base : public Addin_base
		{
		protected:
			AudioVisual_base();

			AudioVisual_base(const AudioVisual_base&) = delete;

		public:

			virtual ~AudioVisual_base();

			__uref virtual Result<AudioVisualPipe> Create(); ///�������ӻ�����

			__uref virtual UInt64 GetNumberOfPipes();///��ȡ��ǰ��Ч��������

			__uref virtual bool Destory(const AudioVisualPipe& pipe);///���ٿ��ӻ�����

			__uref virtual void Run(const AudioVisualPipe& pipe, const AudioBuffer& buffer); ///������ӻ�����


			REFLECT_CLASS(AudioVisual_base)
		};
	}
}


