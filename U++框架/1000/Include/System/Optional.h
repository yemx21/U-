#pragma once
#include <type_traits>



namespace System
{

	template<typename T>
	class Optional
	{
		using data_t = typename std::aligned_storage<sizeof(T), std::alignment_of<T>::value>::type;
	public:

		typedef typename T type;

		Optional() : m_hasInit(false) {}
		Optional(const T& v)
		{
			Create(v);
		}

		Optional(T&& v) : m_hasInit(false)
		{
			Create(std::move(v));
		}

		~Optional()
		{
			Destroy();
		}

		Optional(const Optional& other) : m_hasInit(false)
		{
			if (other.IsInit())
				Assign(other);
		}

		Optional(Optional&& other) : m_hasInit(false)
		{
			if (other.IsInit())
			{
				Assign(std::move(other));
				other.Destroy();
			}
		}

		Optional& operator=(Optional &&other)
		{
			Assign(std::move(other));
			return *this;
		}

		Optional& operator=(const Optional &other)
		{
			Assign(other);
			return *this;
		}

		template<class... Args>
		void emplace(Args&&... args)
		{
			Destroy();
			Create(std::forward<Args>(args)...);
		}

		bool IsInit() const { return m_hasInit; }

		explicit operator bool() const
		{
			return IsInit();
		}

		T& operator*()
		{
			return *((T*)(&m_data));
		}

		T const& operator*() const
		{
			if (IsInit())
			{
				return *((T*)(&m_data));
			}
			throw std::exception("");
		}

		bool operator == (const Optional<T>& rhs) const
		{
			return (!bool(*this)) != (!rhs) ? false : (!bool(*this) ? true : (*(*this)) == (*rhs));
		}

		bool operator < (const Optional<T>& rhs) const
		{
			return !rhs ? false : (!bool(*this) ? true : (*(*this) < (*rhs)));
		}

		bool operator != (const Optional<T>& rhs)
		{
			return !(*this == (rhs));
		}

		void Reset()
		{
			Destroy();
		}

	private:
		template<class... Args>
		void Create(Args&&... args)
		{
			new (&m_data) T(std::forward<Args>

				(args)...);
			m_hasInit = true;
		}

		void Destroy()
		{
			if (m_hasInit)
			{
				m_hasInit = false;
				((T*)(&m_data))->~T();
			}
		}

		void Assign(const Optional& other)
		{
			if (other.IsInit())
			{
				Copy(other.m_data);
				m_hasInit = true;
			}
			else
			{
				Destroy();
			}
		}

		void Assign(Optional&& other)
		{
			if (other.IsInit())
			{
				Move(std::move(other.m_data));
				m_hasInit = true;
				other.Destroy();
			}
			else
			{
				Destroy();
			}
		}

		void Move(data_t&& val)
		{
			Destroy();
			new (&m_data) T(std::move(*((T*)

				(&val))));
		}

		void Copy(const data_t& val)
		{
			Destroy();
			new (&m_data) T(*((T*)(&val)));
		}

	private:
		bool m_hasInit;
		data_t m_data;
	};


	template<typename T>
	struct is_based_of_Optional
	{
		typedef char(&yes)[2];
		template<typename U>
		static yes check(Optional<U>*);
		static char check(...);

		static const bool value = (sizeof(check((T*)0)) == sizeof(yes));
	};

	template<typename T>
	struct is_Optional_based
	{
	private:
		typedef typename std::remove_reference<typename std::remove_pointer<typename std::remove_pointer<T>::type>::type>::type base;
	public:
		static const bool value = is_based_of_Optional<base>::value;
	};

}