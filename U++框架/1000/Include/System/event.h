#pragma once
#include "Object.h"
#include <functional>
#include <map>
#include <atomic>
#include "Common.h"
#include "Any.h"
#include "VariadicAnyVisitor.h"
#include "Delegate.h"
namespace System
{
	/// <summary>
	/// �¼�������
	/// </summary>
	class RUNTIME_API EventArgs
	{
	public:
		EventArgs();
		virtual~EventArgs();

		EventArgs(const EventArgs&);

		static EventArgs Empty();
	};
	
	

	template<class ...T>
	class EventHandler;

	/// <summary>
	/// �¼���������
	/// </summary>
	template<class TEventArgs>
	class EventHandler<TEventArgs>: public Delegate
	{
		static_assert(System::is_same_or_base_of<EventArgs, TEventArgs>::value, "TEventArgs must be based of System::EventArgs");
	public:
		/// <summary>
		/// ���� <see cref="EventHandler{TEventArgs}"/> ʵ��.
		/// </summary>
		EventHandler() : m_tokenCounter(0)
		{

		}		

		/// <summary>
		/// �ص���������
		/// </summary>
		typedef std::function<void(const Object*, const TEventArgs&)> CallbackFunction;
	public:
		/// <summary>
		/// ����
		/// </summary>
		/// <param name="sender">������</param>
		/// <param name="arg">�¼�����</param>
		void Invoke(const Object* sender, const TEventArgs& arg) const
		{
			for (auto i = m_handlerMap.begin(); i != m_handlerMap.end(); i++)
			{
				(*i).second(sender, arg);
			}
		}

		/// <summary>
		/// �ж��Ƿ��з���ֵ
		/// </summary>
		virtual bool HasReturn() const override
		{
			return false;
		}

		/// <summary>
		/// ͨ�õ���
		/// </summary>
		/// <param name="sender">������</param>
		/// <param name="args">�¼�����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		bool GenericInvoke(const Any& sender, const OptionalVariadicAny& args, bool nothrow = true) const override
		{
			try
			{
				const Object* obj = AnyVisitor<const Object*>::Get(sender);
				if (args.Size != 1)
				{
					if (!nothrow) throw std::exception("invalid argument");
					return false;
				}
				const TEventArgs& param = VariadicAnyVisitor<const TEventArgs&>::Get(args, 0);
				if (obj)
				{
					Invoke(obj, param);
					return true;
				}
			}
			catch (...)
			{
				if (!nothrow) throw;
			}
			return false;
		}

		/// <summary>
		/// ͨ�õ���
		/// </summary>
		/// <param name="result">����ֵ</param>
		/// <param name="sender">������</param>
		/// <param name="args">�¼�����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		bool GenericInvoke(Any& result, const Any& sender, const OptionalVariadicAny& args, bool nothrow = true) const override
		{
			return false;
		}

		/// <summary>
		/// ����
		/// </summary>
		/// <param name="sender">������</param>
		/// <param name="arg">�¼�����</param>
		void operator()(const Object* sender, const TEventArgs& arg) const
		{
			Invoke(sender, arg);
		}

		/// <summary>
		/// ע��ص�
		/// </summary>
		/// <param name="f">�ص�������ַ</param>
		/// <returns>�¼����</returns>
		EventToken operator += (CallbackFunction f) const
		{
			auto token = m_tokenCounter++;

			m_handlerMap[token] = f;
			return token;
		}

		/// <summary>
		/// ע���ص�
		/// </summary>
		/// <param name="token">�¼����</param>
		/// <returns>�¼����</returns>
		EventToken operator -= (EventToken token) const
		{
			m_handlerMap.erase(token);
			return token;
		}

	private:
		mutable std::atomic<EventToken> m_tokenCounter;
		mutable std::map<EventToken, CallbackFunction> m_handlerMap;
	};

	/// <summary>
	/// �¼���������
	/// </summary>
	template<class TSender, class TEventArgs>
	class EventHandler<TSender, TEventArgs>: public Delegate
	{
		static_assert(System::is_same_or_base_of<EventArgs, TEventArgs>::value, "TEventArgs must be based of System::EventArgs");
	public:
		/// <summary>
		/// ���� <see cref="EventHandler{TSender, TEventArgs}"/> ʵ��.
		/// </summary>
		EventHandler() : m_tokenCounter(0)
		{

		}	

		/// <summary>
		/// �ص���������
		/// </summary>
		typedef std::function<void(const TSender*, const TEventArgs&)> CallbackFunction;
	public:		
		/// <summary>
		/// ����
		/// </summary>
		/// <param name="sender">������</param>
		/// <param name="arg">�¼�����</param>
		void Invoke(const TSender* sender, const TEventArgs& arg) const
		{
			for (auto i = m_handlerMap.begin(); i != m_handlerMap.end(); i++)
			{
				(*i).second(sender, arg);
			}
		}

		/// <summary>
		/// �ж��Ƿ��з���ֵ
		/// </summary>
		virtual bool HasReturn() const override
		{
			return false;
		}

		/// <summary>
		/// ͨ�õ���
		/// </summary>
		/// <param name="sender">������</param>
		/// <param name="args">�¼�����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		bool GenericInvoke(const Any& sender, const OptionalVariadicAny& args, bool nothrow = true) const override
		{
			try
			{
				const TSender*  obj = AnyVisitor<const TSender* >::Get(sender);
				if (args.Size != 1)
				{
					if (!nothrow) throw std::exception("invalid argument");
					return false;
				}
				const TEventArgs& param = VariadicAnyVisitor<const TEventArgs&>::Get(args, 0);
				if (obj)
				{
					Invoke(obj, param);
					return true;
				}
			}
			catch (...)
			{
				if (!nothrow) throw;
			}
			return false;
		}

		/// <summary>
		/// ͨ�õ��� ����֧�֣�
		/// </summary>
		/// <param name="result">����ֵ</param>
		/// <param name="sender">������</param>
		/// <param name="args">�¼�����</param>
		/// <param name="nothrow">�޴���׽</param>
		/// <returns></returns>
		bool GenericInvoke(Any& result, const Any& sender, const OptionalVariadicAny& args, bool nothrow = true) const override
		{
			return false;
		}

		/// <summary>
		/// ����
		/// </summary>
		/// <param name="sender">������</param>
		/// <param name="arg">�¼�����</param>
		void operator()(const TSender* sender, const TEventArgs& arg) const
		{
			Invoke(sender, arg);
		}

		/// <summary>
		/// ע��ص�
		/// </summary>
		/// <param name="f">�ص�������ַ</param>
		/// <returns>�¼����</returns>
		EventToken operator += (CallbackFunction f) const
		{
			auto token = m_tokenCounter++;

			m_handlerMap[token] = f;
			return token;
		}

		/// <summary>
		/// ע���ص�
		/// </summary>
		/// <param name="token">�¼����</param>
		/// <returns>�¼����</returns>
		EventToken operator -= (EventToken token) const
		{
			m_handlerMap.erase(token);
			return token;
		}

	private:
		mutable std::atomic<EventToken> m_tokenCounter;
		mutable std::map<EventToken, CallbackFunction> m_handlerMap;
	};

	template<typename ...T>
	class MultiCastDelegate;

	template<typename __P0>
	class MultiCastDelegate<__P0>
	{
	public:
		MultiCastDelegate() : m_tokenCounter(0)
		{

		}
		typedef std::function<void(__P0)> CallbackFunction; 

	public:
		void Invoke(__P0 p0) const
		{
			for (auto i = m_handlerMap.begin(); i != m_handlerMap.end(); i++)
			{
				(*i).second(p0);
			}
		}

		void operator()(__P0 p0) const
		{
			Invoke(p0);
		}

		EventToken operator += (CallbackFunction f) const
		{
			auto token = m_tokenCounter++;

			m_handlerMap[token] = f;
			return token;
		}

		EventToken operator -= (EventToken token) const
		{
			m_handlerMap.erase(token);
			return token;
		}

	private:
		mutable std::atomic<EventToken> m_tokenCounter;
		mutable std::map<EventToken, CallbackFunction> m_handlerMap;

	};

	template<typename __P0, typename __P1>
	class MultiCastDelegate<__P0, __P1>
	{
	public:
		MultiCastDelegate() : m_tokenCounter(0)
		{

		}
		typedef std::function<void(__P0, __P1)> CallbackFunction;

	public:
		void Invoke(__P0 p0, __P1 p1) const
		{
			for (auto i = m_handlerMap.begin(); i != m_handlerMap.end(); i++)
			{
				(*i).second(p0, p1);
			}
		}

		void operator()(__P0 p0, __P1 p1) const
		{
			Invoke(p0, p1);
		}

		EventToken operator += (CallbackFunction f) const
		{
			auto token = m_tokenCounter++;

			m_handlerMap[token] = f;
			return token;
		}

		EventToken operator -= (EventToken token) const
		{
			m_handlerMap.erase(token);
			return token;
		}

	private:
		mutable std::atomic<EventToken> m_tokenCounter;
		mutable std::map<EventToken, CallbackFunction> m_handlerMap;

	};

	template<typename __P0, typename __P1, typename __P2>
	class MultiCastDelegate<__P0, __P1, __P2>
	{
	public:
		MultiCastDelegate() : m_tokenCounter(0)
		{

		}
		typedef std::function<void(__P0, __P1, __P2)> CallbackFunction;

	public:
		void Invoke(__P0 p0, __P1 p1, __P2 p2) const
		{
			for (auto i = m_handlerMap.begin(); i != m_handlerMap.end(); i++)
			{
				(*i).second(p0, p1, p2);
			}
		}

		void operator()(__P0 p0, __P1 p1, __P2 p2) const
		{
			Invoke(p0, p1, p2);
		}

		EventToken operator += (CallbackFunction f) const
		{
			auto token = m_tokenCounter++;

			m_handlerMap[token] = f;
			return token;
		}

		EventToken operator -= (EventToken token) const
		{
			m_handlerMap.erase(token);
			return token;
		}

	private:
		mutable std::atomic<EventToken> m_tokenCounter;
		mutable std::map<EventToken, CallbackFunction> m_handlerMap;

	};

	template<typename __P0, typename __P1, typename __P2, typename __P3>
	class MultiCastDelegate<__P0, __P1, __P2, __P3>
	{
	public:
		MultiCastDelegate() : m_tokenCounter(0)
		{

		}
		typedef std::function<void(__P0, __P1, __P2, __P3)> CallbackFunction;

	public:
		void Invoke(__P0 p0, __P1 p1, __P2 p2, __P3 p3) const
		{
			for (auto i = m_handlerMap.begin(); i != m_handlerMap.end(); i++)
			{
				(*i).second(p0, p1, p2, p3);
			}
		}

		void operator()(__P0 p0, __P1 p1, __P2 p2, __P3 p3) const
		{
			Invoke(p0, p1, p2, p3);
		}

		EventToken operator += (CallbackFunction f) const
		{
			auto token = m_tokenCounter++;

			m_handlerMap[token] = f;
			return token;
		}

		EventToken operator -= (EventToken token) const
		{
			m_handlerMap.erase(token);
			return token;
		}

	private:
		mutable std::atomic<EventToken> m_tokenCounter;
		mutable std::map<EventToken, CallbackFunction> m_handlerMap;

	};

	template<typename __P0, typename __P1, typename __P2, typename __P3, typename __P4>
	class MultiCastDelegate<__P0, __P1, __P2, __P3, __P4>
	{
	public:
		MultiCastDelegate() : m_tokenCounter(0)
		{

		}
		typedef std::function<void(__P0, __P1, __P2, __P3, __P4)> CallbackFunction;

	public:
		void Invoke(__P0 p0, __P1 p1, __P2 p2, __P3 p3, __P4 p4) const
		{
			for (auto i = m_handlerMap.begin(); i != m_handlerMap.end(); i++)
			{
				(*i).second(p0, p1,p2, p3, p4);
			}
		}

		void operator()(__P0 p0, __P1 p1, __P2 p2, __P3 p3, __P4 p4) const
		{
			Invoke(p0, p1, p2, p3, p4);
		}

		EventToken operator += (CallbackFunction f) const
		{
			auto token = m_tokenCounter++;

			m_handlerMap[token] = f;
			return token;
		}

		EventToken operator -= (EventToken token) const
		{
			m_handlerMap.erase(token);
			return token;
		}

	private:
		mutable std::atomic<EventToken> m_tokenCounter;
		mutable std::map<EventToken, CallbackFunction> m_handlerMap;

	};

	template<typename __P0, typename __P1, typename __P2, typename __P3, typename __P4, typename __P5>
	class MultiCastDelegate<__P0, __P1, __P2, __P3, __P4, __P5>
	{
	public:
		MultiCastDelegate() : m_tokenCounter(0)
		{

		}
		typedef std::function<void(__P0, __P1, __P2, __P3, __P4, __P5)> CallbackFunction;

	public:
		void Invoke(__P0 p0, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5) const
		{
			for (auto i = m_handlerMap.begin(); i != m_handlerMap.end(); i++)
			{
				(*i).second(p0, p1,p2, p3, p4, p5);
			}
		}

		void operator()(__P0 p0, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5) const
		{
			Invoke(p0, p1, p2, p3, p4, p5);
		}

		EventToken operator += (CallbackFunction f) const
		{
			auto token = m_tokenCounter++;

			m_handlerMap[token] = f;
			return token;
		}

		EventToken operator -= (EventToken token) const
		{
			m_handlerMap.erase(token);
			return token;
		}

	private:
		mutable std::atomic<EventToken> m_tokenCounter;
		mutable std::map<EventToken, CallbackFunction> m_handlerMap;

	};

	template<typename __P0, typename __P1, typename __P2, typename __P3, typename __P4, typename __P5, typename __P6>
	class MultiCastDelegate<__P0, __P1, __P2, __P3, __P4, __P5, __P6>
	{
	public:
		MultiCastDelegate() : m_tokenCounter(0)
		{

		}
		typedef std::function<void(__P0, __P1, __P2, __P3, __P4, __P5, __P6)> CallbackFunction;

	public:
		void Invoke(__P0 p0, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5, __P6 p6) const
		{
			for (auto i = m_handlerMap.begin(); i != m_handlerMap.end(); i++)
			{
				(*i).second(p0, p1, p2, p3, p4, p5, p6);
			}
		}

		void operator()(__P0 p0, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5, __P6 p6) const
		{
			Invoke(p0, p1, p2, p3, p4, p5, p6);
		}

		EventToken operator += (CallbackFunction f) const
		{
			auto token = m_tokenCounter++;

			m_handlerMap[token] = f;
			return token;
		}

		EventToken operator -= (EventToken token) const
		{
			m_handlerMap.erase(token);
			return token;
		}

	private:
		mutable std::atomic<EventToken> m_tokenCounter;
		mutable std::map<EventToken, CallbackFunction> m_handlerMap;

	};

	template<typename __P0, typename __P1, typename __P2, typename __P3, typename __P4, typename __P5, typename __P6, typename __P7>
	class MultiCastDelegate<__P0, __P1, __P2, __P3, __P4, __P5, __P6, __P7>
	{
	public:
		MultiCastDelegate() : m_tokenCounter(0)
		{

		}
		typedef std::function<void(__P0, __P1, __P2, __P3, __P4, __P5, __P6, __P7)> CallbackFunction;

	public:
		void Invoke(__P0 p0, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5, __P6 p6, __P7 p7) const
		{
			for (auto i = m_handlerMap.begin(); i != m_handlerMap.end(); i++)
			{
				(*i).second(p0, p1, p2, p3, p4, p5, p6, p7);
			}
		}

		void operator()(__P0 p0, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5, __P6 p6, __P7 p7) const
		{
			Invoke(p0, p1, p2, p3, p4, p5, p6, p7);
		}

		EventToken operator += (CallbackFunction f) const
		{
			auto token = m_tokenCounter++;

			m_handlerMap[token] = f;
			return token;
		}

		EventToken operator -= (EventToken token) const
		{
			m_handlerMap.erase(token);
			return token;
		}

	private:
		mutable std::atomic<EventToken> m_tokenCounter;
		mutable std::map<EventToken, CallbackFunction> m_handlerMap;

	};

	template<typename __P0, typename __P1, typename __P2, typename __P3, typename __P4, typename __P5, typename __P6, typename __P7, typename __P8>
	class MultiCastDelegate<__P0, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8>
	{
	public:
		MultiCastDelegate() : m_tokenCounter(0)
		{

		}
		typedef std::function<void(__P0, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8)> CallbackFunction;

	public:
		void Invoke(__P0 p0, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5, __P6 p6, __P7 p7, __P8 p8) const
		{
			for (auto i = m_handlerMap.begin(); i != m_handlerMap.end(); i++)
			{
				(*i).second(p0, p1, p2, p3, p4, p5, p6, p7, p8);
			}
		}

		void operator()(__P0 p0, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5, __P6 p6, __P7 p7, __P8 p8) const
		{
			Invoke(p0, p1, p2, p3, p4, p5, p6, p7, p8);
		}

		EventToken operator += (CallbackFunction f) const
		{
			auto token = m_tokenCounter++;

			m_handlerMap[token] = f;
			return token;
		}

		EventToken operator -= (EventToken token) const
		{
			m_handlerMap.erase(token);
			return token;
		}

	private:
		mutable std::atomic<EventToken> m_tokenCounter;
		mutable std::map<EventToken, CallbackFunction> m_handlerMap;

	};

	template<typename __P0, typename __P1, typename __P2, typename __P3, typename __P4, typename __P5, typename __P6, typename __P7, typename __P8, typename __P9>
	class MultiCastDelegate<__P0, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8,  __P9>
	{
	public:
		MultiCastDelegate() : m_tokenCounter(0)
		{

		}
		typedef std::function<void(__P0, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9)> CallbackFunction;

	public:
		void Invoke(__P0 p0, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5, __P6 p6, __P7 p7, __P8 p8, __P9 p9) const
		{
			for (auto i = m_handlerMap.begin(); i != m_handlerMap.end(); i++)
			{
				(*i).second(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
			}
		}

		void operator()(__P0 p0, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5, __P6 p6, __P7 p7, __P8 p8, __P9 p9) const
		{
			Invoke(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
		}

		EventToken operator += (CallbackFunction f) const
		{
			auto token = m_tokenCounter++;

			m_handlerMap[token] = f;
			return token;
		}

		EventToken operator -= (EventToken token) const
		{
			m_handlerMap.erase(token);
			return token;
		}

	private:
		mutable std::atomic<EventToken> m_tokenCounter;
		mutable std::map<EventToken, CallbackFunction> m_handlerMap;

	};

}