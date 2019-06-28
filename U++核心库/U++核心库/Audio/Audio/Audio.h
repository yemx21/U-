#pragma once
#include "Config.h"


namespace System
{
	namespace Internal
	{
		namespace Audio
		{
			/*��Ƶ��������*/
			typedef safe_void_ptr AddinCenter;

			/*��Ƶ��������¼��ص�����*/
			typedef void(*AddinCenterEventCallBack)(const AddinCenter& sender, CoreEventFlags flag, CoreEvents id, CoreObjects mobj, CoreSubObjects sobj, double, double, const UInt128& obj, const wstring& msg, const VariadicAny& args);

			/*��Ƶ��������*/
			enum class addin_types
			{
				/*��Ƶ������*/
				AudioDecoder,
				/*��Ƶ��Ч������*/
				AudioDSP,
				/*��Ƶ�豸*/
				AudioDevice,
				/*��Ƶ���ӻ�*/
				AudioVisual,
				/*��Ƶ������*/
				AudioEncoder,

				/*��ʽ�����*/
				LryicDecoder,
				/*��ʱ�����*/
				LryicEncoder,
				/*��ʿ��ӻ�*/
				LryicVisual,
			};
			

			/*��Ƶ�������Ĺ�����*/
			struct AddinCenterMgr
			{
				/*�����������*/
				AddinCenter (*Create)();

				/*���ٲ������*/
				void(*Destory)(AddinCenter&);

				/*���ز����ָ��������Ĳ����ز��ȫ��Ψһ��ʶ���ϼ����������ֱ�ʶ*/
				Result<bool, std::vector<std::pair<UInt128, addin_types>>, safe_void_ptr>(*AddSection)(const AddinCenter&, const wchar_t*);

				/*��ȡ�Ƿ���Ƴ�ָ����ʶ�������в��*/
				Result<bool, std::vector<UInt128>>(*CanRemoveSection)(const AddinCenter&, const safe_void_ptr&);

				/*�Ƴ�ָ����ʶ�������в��������ʵ���Ƴ��Ĳ��*/
				Result<bool, std::vector<UInt128>>(*RemoveSection)(const AddinCenter&, const safe_void_ptr&);

				/*��ȡ�Ƿ���Ƴ�ָ����ʶ�Ĳ��*/
				Result<bool>(*CanRemove)(const AddinCenter&, const UInt128&);

				/*�Ƴ�ָ����ʶ�Ĳ��������һ���Ƴ��Ĳ��ֱ�ʶ*/
				Result<bool, safe_void_ptr>(*Remove)(const AddinCenter&, const UInt128&);

				/*��ȡָ����ʶ�Ĳ���汾��Ϣ*/
				Result<bool, Version>(*GetVersion)(const AddinCenter&, const UInt128&);

				/*��ȡָ����ʶ�Ĳ������*/
				Result<bool, const wchar_t*>(*GetAuthor)(const AddinCenter&, const UInt128&);

				/*��ȡָ����ʶ�Ĳ������*/
				Result<bool, const wchar_t*>(*GetDescription)(const AddinCenter&, const UInt128&);

				/*��ȡָ����ʶ�Ĳ����ʽ֧����Ϣ*/
				Result<bool, const wchar_t*>(*GetSupportFormat)(const AddinCenter&, const UInt128&);

				/*��ȡָ����ʶ�Ĳ����ǰ���е���Ч��������*/
				Result<bool, UInt>(*GetNumPipes)(const AddinCenter&, const UInt128&);

				/*��ָ���������ע���¼��ص������������¼���ʶ*/
				Result<bool, EventToken>(*RegisiterEventCallBack)(const AddinCenter&, AddinCenterEventCallBack);

				/*��ָ����������Ƴ�ָ����ʶ�¼��ص�����*/
				Result<bool>(*UnRegisiterEventCallBack)(const AddinCenter&, EventToken);

			};

			/*���ֲ�����*/
			typedef safe_void_ptr AudioPlayer;

			/*��Ƶ������*/
			enum class audio_tree_error
			{
				/*��*/
				None,
				/*����*/
				Failed,
				/*�Ƿ�·��*/
				InvalidPath,
				/*�Ƿ��������*/
				InvalidCenter,
				/*�Ƿ�ָ������Ƶ���*/
				Invalid,
				/*�Ѵ��ڲ���״̬*/
				AlreadyOnThread,
				/*��֧��*/
				Unsupported,
				/*�����ʲ�֧��*/
				UnsupportedSampleRate,
				/*λ��Ȳ�֧��*/
				UnsupportedBitsPerSample,
				/*�������ò�֧��*/
				UnsupportedChannel,
				/*�����벻֧��*/
				UnsupportedStream,
				/*��Ƶ��Ϣ��֧��*/
				UnsupportedInfo,
				/*δ֪*/
				Unknown
			};

			/*��Ƶ���ٸ���Ҷ�任���ݴ�����*/
			enum class audio_fft_window
			{
				/*��*/
				None,
				/*������*/
				HammingWindow,
				/*������*/
				HannWindow,
				/*��������-����˹��*/
				BlackmannHarrisWindow,
			};

			/*���ֲ�����������*/
			struct AudioPlayerMgr
			{
				/*����������*/
				Result<bool, AudioPlayer, UInt128>(*Create)(const AddinCenter&, UInt64);

				/*���ٲ�����*/
				void(*Destory)(AudioPlayer&);

				/*��ȡָ������������������*/
				Result<bool, UInt64>(*GetBufferTimeMs)(const AudioPlayer&);

				/*����ָ������������������*/
				Result<bool>(*SetBufferTimeMs)(const AudioPlayer&, UInt64);

				/*��ָ����Ƶ�ļ���������Ƶ����ʶ*/
				Result<UInt128, audio_tree_error, CoreSubObjects, int>(*Open)(const AudioPlayer&, const wchar_t*, const UInt128&, const UInt128&, int);

				/*��ȡָ����Ƶ����Ƶ��Ϣ*/
				Result<bool, AudioInfo>(*GetInfo)(const AudioPlayer&, const UInt128&);

				/*����ָ����Ƶ��*/
				Result<bool>(*Play)(const AudioPlayer&, const UInt128&);

				/*��ָͣ����Ƶ��*/
				Result<bool>(*Pause)(const AudioPlayer&, const UInt128&);

				/*ָֹͣ������Ƶ�����ڲ��Ž����¼���ָ�����ϱ�ʶ*/
				Result<bool>(*Stop)(const AudioPlayer&, const UInt128&, int);

				/*��ȡָ����Ƶ����ǰ���Ž���*/
				Result<bool, double>(*GetCurrent)(const AudioPlayer&, const UInt128&);

				/*����ָ����Ƶ����ǰ���Ž���*/
				Result<bool>(*SetCurrent)(const AudioPlayer&, const UInt128&, double);

				/*��ȡָ����Ƶ������������*/
				Result<bool, int, int>(*GetEqConfig)(const AudioPlayer&);

				/*����ָ����Ƶ������������*/
				Result<bool, int>(*SetEqConfig)(const AudioPlayer&, int, int);

				/*��ȡָ����Ƶ��������״̬*/
				Result<bool, bool>(*GetEqActive)(const AudioPlayer&);

				/*����ָ����Ƶ��������״̬*/
				Result<bool>(*SetEqActive)(const AudioPlayer&, bool);

				/*��ȡָ����Ƶ��������ָ��Ƶ������ֵ*/
				Result<bool, double>(*GetEqGain)(const AudioPlayer&, int);

				/*����ָ����Ƶ��������ָ��Ƶ������ֵ*/
				Result<bool, double>(*SetEqGain)(const AudioPlayer&, int, double);

				/*��ȡָ����Ƶ����������ֵ*/
				Result<bool, double>(*GetPitch)(const AudioPlayer&);

				/*����ָ����Ƶ����������ֵ*/
				Result<bool>(*SetPitch)(const AudioPlayer&, double);

				/*��ȡָ����Ƶ����������ֵ*/
				Result<bool, double>(*GetTempo)(const AudioPlayer&);

				/*����ָ����Ƶ����������ֵ*/
				Result<bool>(*SetTempo)(const AudioPlayer&, double);

				/*��ȡָ����Ƶ��Ƶ������ֵ*/
				Result<bool, double>(*GetRate)(const AudioPlayer&);

				/*����ָ����Ƶ��Ƶ������ֵ*/
				Result<bool>(*SetRate)(const AudioPlayer&, double);

				/*��ȡָ����Ƶ������ֵ*/
				Result<bool, double>(*GetVolume)(const AudioPlayer&);

				/*����ָ����Ƶ������ֵ*/
				Result<bool>(*SetVolume)(const AudioPlayer&, double);

				/*��ȡָ����Ƶ������ƽ��ֵ*/
				Result<bool, double>(*GetPan)(const AudioPlayer&);

				/*����ָ����Ƶ������ƽ��ֵ*/
				Result<bool>(*SetPan)(const AudioPlayer&, double);

				/*��ȡָ����Ƶ�����ٸ���Ҷ�任����*/
				Result<bool, float**>(*GetFFTData)(const AudioPlayer&, UShort, UInt, audio_fft_window, bool, unsigned short&, unsigned int&);

				/*��ȡָ����Ƶ��������λ����*/
				Result<bool, float*>(*GetVUData)(const AudioPlayer&, UShort, UInt, unsigned short&, unsigned int&);
			};

			/*��Ƶ��ӿ�*/
			struct AudioInterface
			{
				/*��ȡ��Ƶ�������Ĺ������ӿ�*/
				AddinCenterMgr* (*GetCenterMgr)();
				/*��ȡ��Ƶ�������������ӿ�*/
				AudioPlayerMgr* (*GetPlayerMgr)();
			};

			/*��ȡ��Ƶ��ӿ�*/
			typedef AudioInterface* (*GetAudioInterface)();
		}
	}
}