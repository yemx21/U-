#pragma once
#include "Config.h"
#include <exception>

namespace System
{
	/// <summary>
	/// ����ϵͳ�汾
	/// </summary>
	enum class OSVersion
	{
		/// <summary>
		/// XP
		/// </summary>
		XP_0 = 10,
		/// <summary>
		/// XP sp1
		/// </summary>
		XP_1,
		/// <summary>
		/// XP sp2
		/// </summary>
		XP_2,
		/// <summary>
		/// XP sp3
		/// </summary>
		XP_3,

		/// <summary>
		/// Vista
		/// </summary>
		Vista_0 = 20,
		/// <summary>
		/// Vista sp1
		/// </summary>
		Vista_1,
		/// <summary>
		/// Vista sp2
		/// </summary>
		Vista_2,

		/// <summary>
		/// Win7
		/// </summary>
		Win7_0 = 30,
		/// <summary>
		/// Win7 sp1
		/// </summary>
		Win7_1,

		/// <summary>
		/// Win8
		/// </summary>
		Win8_0 = 40,
		/// <summary>
		/// Win8 sp1
		/// </summary>
		Win8_1,
		/// <summary>
		/// Win10
		/// </summary>
		Win10,

		/// <summary>
		/// ��֧��
		/// </summary>
		UnSupported = 0x10000,
	};

	/// <summary>
	/// ��ȫУ��ָ��
	/// </summary>
	class RUNTIME_API safe_void_ptr final
	{
	private:
		void* _ptr;
	public:
		safe_void_ptr();
		safe_void_ptr(void* ptr);
		safe_void_ptr(const safe_void_ptr& ptr);
		safe_void_ptr(safe_void_ptr&& ptr);
		~safe_void_ptr();
		safe_void_ptr& operator = (void* newPtr);
		safe_void_ptr& operator = (const safe_void_ptr& ptr);
		/// <summary>
		/// У�鲢��ȡʵ�ʵ�ֵַ
		/// </summary>
		/// <param name="checkSize">��ַ����</param>
		void* get(UInt64 checkSize) const;
		template <typename T>
		typename std::add_pointer<typename std::decay<T>::type>::type get() const
		{
			return (typename std::add_pointer<std::decay<T>::type>::type)get(sizeof(typename std::decay<T>::type));
		}
		size_t getHash() const;
		bool operator == (const safe_void_ptr& ptr) { return _ptr == ptr._ptr; }
		operator bool() const { return _ptr != nullptr; }
		void* operator*() const noexcept;
	};

	template<typename T, size_t N>
	struct add_pointer_ex
	{
		typedef typename add_pointer_ex<T*, N - 1>::type type;
	};

	template<typename T>
	struct add_pointer_ex<T, 0U>
	{
		typedef typename T type;
	};

	/// <summary>
	/// ����ϵͳ������
	/// </summary>
	 class RUNTIME_API OSHelper
	{
		template<typename T, size_t START, size_t END, bool SAME>
		struct AddressChecker
		{
			__inline static bool Check(typename add_pointer_ex<T, START>::type mem, bool readWrite = true)
			{
				if (!OSHelper::IsValidAddress(mem, sizeof(std::conditional<std::is_void<deduce<T>::type>::value, void*, deduce<T>::type>::type), readWrite)) return false;
				return AddressChecker<T, START - 1, END, START - 1 == END>::Check(mem[0], readWrite);
			}
		};

		template<typename T, size_t START, size_t END>
		struct AddressChecker<T, START, END, true>
		{
			__inline static bool Check(typename add_pointer_ex<T, START>::type mem, bool readWrite = true)
			{
				return OSHelper::IsValidAddress(mem, sizeof(std::conditional<std::is_void<deduce<T>::type>::value, void*, deduce<T>::type>::type), readWrite);
			}
		};

	public:
		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <param name="errorCode">�������</param>
		/// <returns></returns>
		static std::exception GetErrorException(ULong errorCode);

		/// <summary>
		/// ��ȡ����Ĵ���
		/// </summary>
		/// <returns></returns>
		static std::exception GetLastErrorException();

		/// <summary>
		/// У���ַ�ɶ�д��
		/// </summary>
		/// <param name="lp">��ַ</param>
		/// <param name="nBytes">��ַ����</param>
		/// <param name="readWrite">�ɶ�д��</param>
		/// <returns></returns>
		static bool IsValidAddress(const void* lp, UInt64 nBytes, bool readWrite = true);

		/// <summary>
		/// У���ַ�ɶ�д��
		/// </summary>
		/// <param name="mem">��ַ</param>
		/// <param name="readWrite">�ɶ�д��</param>
		/// <returns></returns>
		template<typename T, size_t START, size_t END>
		__inline static bool IsValidAddress(typename add_pointer_ex<T, START>::type mem, bool readWrite = true)
		{
			return AddressChecker<T, START, END, START == END>::Check(mem, readWrite);
		}

		/// <summary>
		/// ��ȡ����ϵͳ�汾
		/// </summary>
		/// <returns></returns>
		static OSVersion GetOSVersion();
	};
}

#include <xhash>
namespace std
{
	template <>
	struct std::hash<System::safe_void_ptr>
	{
		inline size_t operator()(const System::safe_void_ptr& obj) const
		{
			return obj.getHash();
		}
	};
}