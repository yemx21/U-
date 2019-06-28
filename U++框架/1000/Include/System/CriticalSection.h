#pragma once
#include "Config.h"
namespace System
{
	/// <summary>
	/// �ٽ�����
	/// </summary>
	class RUNTIME_API CriticalSection
	{
	private:
		void* impl;
		CriticalSection(const CriticalSection&) = delete;
		CriticalSection& operator=(const CriticalSection&) = delete;
	public:
		/// <summary>
		/// ����<see cref="CriticalSection"/>ʵ��.
		/// </summary>
		CriticalSection();
		~CriticalSection();

		/// <summary>
		/// ���Խ����ٽ���
		/// </summary>
		/// <returns></returns>
		bool TryEnter();

		/// <summary>
		/// �����ٽ���
		/// </summary>
		void Enter();

		/// <summary>
		/// �뿪�ٽ���
		/// </summary>
		void Leave();
	};

}

#include <mutex>

namespace std
{
	template<>
	class lock_guard<System::CriticalSection>
	{	
	public:
		typedef System::CriticalSection mutex_type;

		explicit lock_guard(System::CriticalSection& _Mtx)
			: _Mutex(_Mtx)
		{	
			_Mutex.Enter();
		}

		lock_guard(System::CriticalSection& _Mtx, adopt_lock_t)
			: _Mutex(_Mtx)
		{
		}

		~lock_guard() noexcept
		{	
			_Mutex.Leave();
		}

		lock_guard(const lock_guard&) = delete;
		lock_guard& operator=(const lock_guard&) = delete;

	private:
		System::CriticalSection& _Mutex;
	};

}