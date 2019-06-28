#pragma once
#include "Cloner.h"
namespace System
{
	class Type;

	/// <summary>
	/// Enum ResultTypes
	/// </summary>
	enum class ResultTypes
	{
		/// <summary>
		/// δ֪
		/// </summary>
		Unknown,
		/// <summary>
		/// һ������
		/// </summary>
		One,
		/// <summary>
		/// ��������
		/// </summary>
		Two,
		/// <summary>
		/// ��������
		/// </summary>
		Three,
		/// <summary>
		/// �ĸ�����
		/// </summary>
		Four
	};

	template<typename ...T>
	/// <summary>
	/// �����
	/// </summary>
	class Result;

	template<typename T>
	/// <summary>
	/// �����
	/// </summary>
	class Result<T>
	{
	protected:
		wchar_t* mem;
		UInt32 memsize;
	public:
		typedef typename T type1;
		/// <summary>
		/// ֵ
		/// </summary>
		T Value;
		/// <summary>
		/// ����<see cref="Result{T}"/>ʵ��.
		/// </summary>
		Result() :mem(NULL), memsize(0) {}

		Result(const Result& src)
		{
			if (src.mem && src.memsize)
			{
				memsize = src.memsize;
				mem = new wchar_t[memsize + 1];
				wcsncpy_s(mem, memsize, src.mem, _TRUNCATE);
			}
			else
			{
				memsize = 0;
				mem = NULL;
			}
			Value = src.Value;
		}
		/// <summary>
		/// ����<see cref="Result{T}"/>ʵ��.
		/// </summary>
		/// <param name="value">ֵ</param>
		Result(T value) :Value(value), mem(NULL), memsize(0) {}

		/// <summary>
		/// ����<see cref="Result{T}"/>ʵ��.
		/// </summary>
		/// <param name="value">ֵ</param>
		/// <param name="message">��Ϣ</param>
		Result(T value, const wchar_t* message) : Value(value)
		{
			mem = Cloner::Clone(message, memsize);
		}
		
		~Result()
		{
			if (mem)
			{
				SAFE_DELETE(mem);
				memsize = 0;
			}
		}

		/// <summary>
		/// д����Ϣ
		/// </summary>
		/// <param name="message">The message.</param>
		void WriteMessage(const wchar_t* message)
		{
			if (mem)
			{
				SAFE_DELETE(mem);
				memsize = 0;
			}
			mem = Cloner::Clone(message, memsize);
		}

		/// <summary>
		/// ��ȡ��Ϣ
		/// </summary>
		/// <returns></returns>
		const wchar_t* GetMem() const
		{
			return mem;
		}

		/// <summary>
		/// ��Ϣ
		/// </summary>
		_declspec(property(get = GetMem)) const wchar_t* Message;
	};


	template<typename T, typename S>	
	/// <summary>
	/// �����
	/// </summary>
	class Result<T, S>
	{
	protected:
		wchar_t* mem;
		UInt32 memsize;
	public:
		typedef typename T type1;
		typedef typename S stateType;
		/// <summary>
		///  ֵ
		/// </summary>
		T Value;
		/// <summary>
		/// ״̬
		/// </summary>
		S State;
		/// <summary>
		/// ����<see cref="Result{T, S}"/>ʵ��.
		/// </summary>
		Result() :mem(NULL), memsize(0) {}

		Result(const Result& src)
		{
			if (src.mem && src.memsize)
			{
				memsize = src.memsize;
				mem = new wchar_t[memsize + 1];
				wcsncpy_s(mem, memsize, src.mem, _TRUNCATE);
			}
			else
			{
				memsize = 0;
				mem = NULL;
			}
			Value = src.Value;
			State = src.State;
		}
		/// <summary>
		/// ����<see cref="Result{T, S}"/>ʵ��.
		/// </summary>
		/// <param name="value">ֵ</param>
		/// <param name="state">״̬</param>
		Result(T value, S state) :Value(value), State(state), mem(NULL), memsize(0) {}

		/// <summary>
		/// ����<see cref="Result{T, S}"/>ʵ��.
		/// </summary>
		/// <param name="value">ֵ</param>
		/// <param name="state">״̬</param>
		/// <param name="message">��Ϣ</param>
		Result(T value, S state, const wchar_t* message) : Value(value), State(state)
		{
			mem = Cloner::Clone(message, memsize);
		}

		~Result()
		{
			if (mem)
			{
				delete mem;
				mem = NULL;
				memsize = 0;
			}
		}

		/// <summary>
		/// д����Ϣ
		/// </summary>
		/// <param name="message">��Ϣ</param>
		void WriteMessage(const wchar_t* message)
		{
			if (mem)
			{
				delete mem;
				mem = NULL;
				memsize = 0;
			}
			mem = Cloner::Clone(message, memsize);
		}



		/// <summary>
		/// ��ȡ��Ϣ
		/// </summary>
		/// <returns></returns>
		const wchar_t* GetMem() const
		{
			return mem;
		}

		/// <summary>
		/// ��Ϣ
		/// </summary>
		_declspec(property(get = GetMem)) const wchar_t* Message;
	};


	template<typename T1, typename T2, typename S>
	/// <summary>
	/// �����
	/// </summary>
	class Result<T1, T2, S>
	{
	protected:
		wchar_t* mem;
		UInt32 memsize;
	public:
		/// <summary>
		/// ֵ1
		/// </summary>
		T1 Value1;
		/// <summary>
		/// ֵ2
		/// </summary>
		T2 Value2;
		/// <summary>
		/// ״̬
		/// </summary>
		S State;
		typedef typename T1 type1;
		typedef typename T2 type2;
		typedef typename S stateType;
		/// <summary>
		/// ����<see cref="Result{T1, T2, S}"/>ʵ��.
		/// </summary>
		Result() :mem(NULL), memsize(0) {}

		Result(const Result<T1, T2, S>& src)
		{
			if (src.mem && src.memsize)
			{
				memsize = src.memsize;
				mem = new wchar_t[memsize + 1];
				wcsncpy_s(mem, memsize, src.mem, _TRUNCATE);
			}
			else
			{
				memsize = 0;
				mem = NULL;
			}
			Value1 = src.Value1;
			Value2 = src.Value2;
			State = src.State;
		}
		/// <summary>
		/// ����<see cref="Result{T1, T2, S}"/>ʵ��.
		/// </summary>
		/// <param name="value1">ֵ1</param>
		/// <param name="value2">ֵ2</param>
		/// <param name="state">״̬</param>
		Result(T1 value1, T2 value2, S state) :Value1(value1), Value2(value2), State(state), mem(NULL), memsize(0) {}

		/// <summary>
		/// ����<see cref="Result{T1, T2, S}"/>ʵ��.
		/// </summary>
		/// <param name="value1">ֵ1</param>
		/// <param name="value2">ֵ2</param>
		/// <param name="state">״̬</param>
		/// <param name="message">��Ϣ</param>
		Result(T1 value1, T2 value2, S state, const wchar_t* message) : Value1(value1), Value2(value2), State(state)
		{
			mem = Cloner::Clone(message, memsize);
		}

		~Result()
		{
			if (mem)
			{
				delete mem;
				mem = NULL;
				memsize = 0;
			}
		}

		/// <summary>
		/// д����Ϣ
		/// </summary>
		/// <param name="message">��Ϣ</param>
		void WriteMessage(const wchar_t* message)
		{
			if (mem)
			{
				delete mem;
				mem = NULL;
				memsize = 0;
			}
			mem = Cloner::Clone(message, memsize);
		}



		/// <summary>
		/// ��ȡ��Ϣ
		/// </summary>
		/// <returns></returns>
		const wchar_t* GetMem() const
		{
			return mem;
		}

		/// <summary>
		/// ��Ϣ
		/// </summary>
		_declspec(property(get = GetMem)) const wchar_t* Message;
	};

	/// <summary>
	/// �����
	/// </summary>
	template<typename T1, typename T2, typename T3, typename S>
	class Result<T1, T2, T3, S>
	{
	protected:
		wchar_t* mem;
		UInt32 memsize;
	public:
		/// <summary>
		/// ֵ1
		/// </summary>
		T1 Value1;
		/// <summary>
		/// ֵ2
		/// </summary>
		T2 Value2;
		/// <summary>
		/// ֵ3
		/// </summary>
		T3 Value3;
		/// <summary>
		/// ״̬
		/// </summary>
		S State;
		typedef typename T1 type1;
		typedef typename T2 type2;
		typedef typename T3 type3;
		typedef typename S stateType;
		/// <summary>
		/// ����<see cref="Result{T1, T2, T3, S}"/>ʵ��.
		/// </summary>
		Result() :mem(NULL), memsize(0) {}

		Result(const Result<T1, T2, T3, S>& src)
		{
			if (src.mem && src.memsize)
			{
				memsize = src.memsize;
				mem = new wchar_t[memsize + 1];
				wcsncpy_s(mem, memsize, src.mem, _TRUNCATE);
			}
			else
			{
				memsize = 0;
				mem = NULL;
			}
			Value1 = src.Value1;
			Value2 = src.Value2;
			Value3 = src.Value3;
			State = src.State;
		}
		/// <summary>
		/// ����<see cref="Result{T1, T2, T3, S}"/>ʵ��.
		/// </summary>
		/// <param name="value1">ֵ1</param>
		/// <param name="value2">ֵ2</param>
		/// <param name="value3">ֵ3</param>
		/// <param name="state">״̬</param>
		Result(T1 value1, T2 value2, T3 value3, S state) :Value1(value1), Value2(value2), Value3(value3), State(state), mem(NULL), memsize(0) {}
		/// <summary>
		/// ����<see cref="Result{T1, T2, T3, S}"/>ʵ��.
		/// </summary>
		/// <param name="value1">ֵ1</param>
		/// <param name="value2">ֵ2</param>
		/// <param name="value3">ֵ3</param>
		/// <param name="state">״̬</param>
		/// <param name="message">��Ϣ</param>
		Result(T1 value1, T2 value2, T3 value3, S state, const wchar_t* message) : Value1(value1), Value2(value2), Value3(value3), State(state)
		{
			mem = Cloner::Clone(message, memsize);
		}

		~Result()
		{
			if (mem)
			{
				delete mem;
				mem = NULL;
				memsize = 0;
			}
		}

		/// <summary>
		/// д����Ϣ
		/// </summary>
		/// <param name="message">��Ϣ</param>
		void WriteMessage(const wchar_t* message)
		{
			if (mem)
			{
				delete mem;
				mem = NULL;
				memsize = 0;
			}
			mem = Cloner::Clone(message, memsize);
		}



		/// ��ȡ��Ϣ
		/// </summary>
		/// <returns></returns>
		const wchar_t* GetMem() const
		{
			return mem;
		}

		/// <summary>
		/// ��Ϣ
		/// </summary>
		_declspec(property(get = GetMem)) const wchar_t* Message;
	};

	template<typename T>
	struct is_based_of_Result1
	{
		typedef char(&yes)[2];
		template<typename U>
		static yes check(Result<U>*);
		static char check(...);

		static const bool value = (sizeof(check((T*)0)) == sizeof(yes));
	};

	template<typename T>
	struct is_based_of_Result2
	{
		typedef char(&yes)[2];
		template<typename U, typename S>
		static yes check(Result<U, S>*);
		static char check(...);

		static const bool value = (sizeof(check((T*)0)) == sizeof(yes));
	};

	template<typename T>
	struct is_based_of_Result3
	{
		typedef char(&yes)[2];
		template<typename U1, typename U2, typename S>
		static yes check(Result<U1, U2, S>*);
		static char check(...);

		static const bool value = (sizeof(check((T*)0)) == sizeof(yes));
	};

	template<typename T>
	struct is_based_of_Result4
	{
		typedef char(&yes)[2];
		template<typename U1, typename U2, typename U3, typename S>
		static yes check(Result<U1, U2, U3, S>*);
		static char check(...);

		static const bool value = (sizeof(check((T*)0)) == sizeof(yes));
	};

	template<typename T>
	struct is_Result_based
	{
	private:
		typedef typename std::remove_reference<typename std::remove_pointer<typename std::remove_pointer<T>::type>::type>::type base;
	public:
		static const bool value = is_based_of_Result1<base>::value || is_based_of_Result2<base>::value || is_based_of_Result3<base>::value || is_based_of_Result4<base>::value;
	};

	template<bool ONE, bool TWO, bool THREE, bool FOUR>
	struct DetectResult_impl
	{
		static const ResultTypes value = ResultTypes::Unknown;
	};

	template<>
	struct DetectResult_impl<true, false, false, false>
	{
		static const ResultTypes value = ResultTypes::One;
	};

	template<>
	struct DetectResult_impl<false, true, false, false>
	{
		static const ResultTypes value = ResultTypes::Two;
	};

	template<>
	struct DetectResult_impl< false, false, true, false>
	{
		static const ResultTypes value = ResultTypes::Three;
	};

	template<>
	struct DetectResult_impl< false, false, false, true>
	{
		static const ResultTypes value = ResultTypes::Four;
	};


	template<typename T>
	/// <summary>
	/// �����������
	/// </summary>
	struct DetectResult
	{
	private:
		typedef typename std::remove_reference<typename std::remove_pointer<typename std::remove_pointer<T>::type>::type>::type base;
	public:
		static const bool isOne = is_based_of_Result1<base>::value;
		static const bool isTwo = is_based_of_Result2<base>::value;
		static const bool isThree = is_based_of_Result3<base>::value;
		static const bool isFour = is_based_of_Result4<base>::value;
		static const ResultTypes value = DetectResult_impl<isOne, isTwo, isThree, isFour>::value;
	};



}