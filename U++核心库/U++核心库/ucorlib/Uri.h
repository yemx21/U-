#pragma once
#include "Object.h"
#include "TypeConverter.h"
#include <mutex>
#include "ClassInfo.h"
#include "EnumInfo.h"
namespace System
{
	class UriHelper;

	class RUNTIME_API Uri final: __uobject
	{
		friend class UriHelper;
	public:
#pragma region Scheme
		/// <summary>
		/// ����
		/// </summary>
		class RUNTIME_API Scheme final : __uobject
		{
		private:
			static void DefineMeta(ClassInfo&);
			template<class T>
			friend void ClassInfo::Create(Type const*& pointer, const wchar_t* name, unsigned int size, ClassFlags flags);
		private:
			friend class UriHelper;
			std::wstring value;
		protected:
			std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;
		public:
			/// <summary>
			/// ����<see cref="Scheme"/>ʵ��.
			/// </summary>
			__uref Scheme();
			/// <summary>
			/// ����<see cref="Scheme"/>�Ŀ���ʵ��.
			/// </summary>
			__uref Scheme(const std::wstring& scheme);
			/// <summary>
			/// �ж��Ƿ�Ϊ��
			/// </summary>
			/// <returns></returns>
			__uref bool GetIsEmpty() const;
			/// <summary>
			/// ��ȡֵ
			/// </summary>
			/// <returns></returns>
			__uref const std::wstring& GetValue() const;
			/// <summary>
			/// �Ƿ�Ϊ��
			/// </summary>
			__uproperty(get = GetIsEmpty)bool IsEmpty;
			/// <summary>
			/// ֵ
			/// </summary>
			__uproperty(get = GetValue) const std::wstring& Value;
			/// <summary>
			/// ���Խ���
			/// </summary>
			/// <param name="input">����ֵ</param>
			/// <param name="loc">��������Ϣ</param>
			/// <param name="result">���</param>
			/// <returns></returns>
			static bool TryParse(const std::wstring& input, const CultureInfo& loc, Scheme& result);
			_type GetType() const override;
		};

		class RUNTIME_API SchemeConverter : public TypeConverter
		{
		private:
			static std::mutex& getlocker();
			static std::weak_ptr<SchemeConverter> _thisWeakPtr;
		protected:
			SchemeConverter();
			SchemeConverter(SchemeConverter const&);
			void operator=(SchemeConverter const&);
		public:
			virtual ~SchemeConverter();

			static std::shared_ptr<SchemeConverter> GetSharedInstance();

			static SchemeConverter& GetInstance();

			bool CanConvertFrom(_type type) const;
			bool CanConvertTo(_type type) const;

			Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
			Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

			Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
			std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
		};

#pragma endregion

#pragma region HostType
		class RUNTIME_API HostType final : __uobject
		{
		public:
			typedef Int8 enumbase;
		private:
			Int8 value;
			static void DefineMeta(EnumInfo&);
			template<class T, class BASE>
			friend typename std::enable_if< std::is_integral<BASE>::value, void>::type EnumInfo::Create(System::Type const*& pointer, const wchar_t* name);
		protected:
			std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;
		public:
			_type GetType() const override;
			~HostType();
			HostType(const Int8& val);
			HostType(const HostType& t);
			HostType(HostType&& t);
			HostType& operator=(const Int8& val);
			HostType& operator=(const HostType& t);
			operator Int8() const;
			uhash GetHashCode() const override;
			bool Equals(const Object* ref) const override;

		public:
			enum __uweakenums : enumbase
			{
				Null,
				DomainName,
				IPv4Address,
				IPv6Address,
			};
		public:
			HostType();
		};
#pragma endregion

#pragma region Authority
		/// <summary>
		/// Ȩ����Ϣ(������������ϵͳ (DNS) �������� IP ��ַ�Ͷ˿ں�)
		/// </summary>
		class RUNTIME_API Authority final : __uobject
		{
		private:
			static void DefineMeta(ClassInfo&);
			template<class T>
			friend void ClassInfo::Create(Type const*& pointer, const wchar_t* name, unsigned int size, ClassFlags flags);
		protected:
			std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;
		private:
			friend class UriHelper;
			HostType hostType;
			std::wstring host;
			UShort port;
		public:
			/// <summary>
			/// ����<see cref="Authority"/>ʵ��.
			/// </summary>
			__uref Authority();
			/// <summary>
			/// ����<see cref="Authority"/>�Ŀ���ʵ��.
			/// </summary>
			__uref Authority(const std::wstring& v);
			/// <summary>
			/// �ж��Ƿ�Ϊ��
			/// </summary>
			/// <returns></returns>
			__uref bool GetIsEmpty() const;
			/// <summary>
			/// ��ȡ������
			/// </summary>
			/// <returns></returns>
			__uref const std::wstring& GetHost() const;
			/// <summary>
			/// ��ȡ��������
			/// </summary>
			/// <returns></returns>
			__uref HostType GetHostType() const;
			/// <summary>
			/// ��ȡ�˿ں�
			/// </summary>
			/// <returns></returns>
			__uref UShort GetPort() const;

			/// <summary>
			/// ��ȡ������ַ������ʽ
			/// </summary>
			__uref std::wstring GetEncodedString() const;

			/// <summary>
			/// �Ƿ�Ϊ��
			/// </summary>
			__uproperty(get = GetIsEmpty) bool IsEmpty;
			/// <summary>
			/// ������
			/// </summary>
			__uproperty(get = GetHost) const std::wstring& Host;
			/// <summary>
			/// ��������
			/// </summary>
			__uproperty(get = GetHostType) Uri::HostType HostType;
			/// <summary>
			/// �˿ں�
			/// </summary>
			__uproperty(get = GetPort) UShort Port;
			/// <summary>
			/// ������ַ������ʽ
			/// </summary>
			__uproperty(get = GetEncodedString) std::wstring EncodedString;
			/// <summary>
			/// ���Խ���
			/// </summary>
			/// <param name="input">����ֵ</param>
			/// <param name="loc">��������Ϣ</param>
			/// <param name="result">���</param>
			/// <returns></returns>
			static bool TryParse(const std::wstring& input, const CultureInfo& loc, Authority& result);
			_type GetType() const override;
		};

		class RUNTIME_API AuthorityConverter : public TypeConverter
		{
		private:
			static std::mutex& getlocker();
			static std::weak_ptr<AuthorityConverter> _thisWeakPtr;
		protected:
			AuthorityConverter();
			AuthorityConverter(AuthorityConverter const&);
			void operator=(AuthorityConverter const&);
		public:
			virtual ~AuthorityConverter();

			static std::shared_ptr<AuthorityConverter> GetSharedInstance();

			static AuthorityConverter& GetInstance();

			bool CanConvertFrom(_type type) const;
			bool CanConvertTo(_type type) const;

			Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
			Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

			Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
			std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
		};
#pragma endregion

#pragma region Path
		/// <summary>
		/// ·��
		/// </summary>
		class RUNTIME_API Path final : __uobject
		{
		private:
			static void DefineMeta(ClassInfo&);
			template<class T>
			friend void ClassInfo::Create(Type const*& pointer, const wchar_t* name, unsigned int size, ClassFlags flags);
		protected:
			std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;
		public:
			typedef std::list<std::wstring> segments_type;
			typedef segments_type::const_iterator const_iterator;
		private:
			friend class UriHelper;
			bool absolute;
			bool isdirectory;
			segments_type segments;
		public:
			/// <summary>
			/// ����<see cref="Path"/>ʵ��.
			/// </summary>
			__uref Path();
			/// <summary>
			/// ����<see cref="Path"/>�Ŀ���ʵ��.
			/// </summary>
			/// <param name="value">�ַ������ʽ</param>
			__uref Path(const std::wstring& value);
			/// <summary>
			/// �ж��Ƿ�Ϊ��
			/// </summary>
			/// <returns></returns>
			__uref bool GetIsEmpty() const;
			/// <summary>
			/// �ж��Ƿ�Ϊ����·��
			/// </summary>
			/// <returns></returns>
			__uref bool GetIsAbsolute() const;
			/// <summary>
			/// �����Ƿ�Ϊ����·��
			/// </summary>
			__uref void SetIsAbsolute(bool v);
			/// <summary>
			/// �ж��Ƿ�Ϊ�ļ���·��
			/// </summary>
			/// <returns></returns>
			__uref bool GetIsDirectory() const;
			/// <summary>
			/// �����Ƿ�Ϊ�ļ���·��
			/// </summary>
			__uref void SetIsDirectory(bool);
			/// <summary>
			/// ��ȡ�׶˶���
			/// </summary>
			__uref const std::wstring& front() const;
			/// <summary>
			/// ��ȡĩ�˶���
			/// </summary>
			__uref const std::wstring& back() const;
			/// <summary>
			/// �Ƴ��׶˶��䲢���þ���·��״̬
			/// </summary>
			__uref void popfront();
			/// <summary>
			/// �Ƴ�ƥ���ĩ�˶��䲢���þ���·��״̬
			/// </summary>
			__uref bool popback(const Path& back);
			/// <summary>
			/// �ж�ƥ��ָ��ǰ׺·��
			/// </summary>
			__uref bool IsMatchPrefix(const Path& rhs) const;
			/// <summary>
			/// ��ն��䲢���þ���·�����ļ���״̬
			/// </summary>
			__uref void Clear();
			/// <summary>
			/// ��ȡ��������
			/// </summary>
			__uref size_t GetSize() const;
			bool operator ==(const Path& rhs) const;
			bool operator !=(const Path& rhs) const;
			bool operator <(const Path& rhs) const;
			Path operator +(const std::wstring& rhs) const;
			Path& operator +=(const std::wstring& rhs);
			Path operator +(const Path& rhs) const;
			Path& operator +=(const Path& rhs);
			/// <summary>
			/// ��ȡ������ַ������ʽ
			/// </summary>
			__uref std::wstring GetEncodedString() const;
			const_iterator begin() const;
			const_iterator end() const;

			/// <summary>
			/// �Ƿ�Ϊ��
			/// </summary>
			__uproperty(get = GetIsEmpty) bool IsEmpty;
			/// <summary>
			/// �Ƿ�Ϊ����·��
			/// </summary>
			__uproperty(get = GetIsAbsolute, put = SetIsAbsolute) bool IsAbsolute;
			/// <summary>
			/// �Ƿ�Ϊ�ļ���·��
			/// </summary>
			__uproperty(get = GetHostType, put = SetIsDirectory) bool IsDirectory;
			/// <summary>
			/// ��ȡ��������
			/// </summary>
			__uproperty(get = GetSize) size_t Size;
			/// <summary>
			/// ������ַ������ʽ
			/// </summary>
			__uproperty(get = GetEncodedString) std::wstring EncodedString;
			/// <summary>
			/// ���Խ���
			/// </summary>
			/// <param name="input">����ֵ</param>
			/// <param name="loc">��������Ϣ</param>
			/// <param name="result">���</param>
			/// <returns></returns>
			static bool TryParse(const std::wstring& input, const CultureInfo& loc, Path& result);
			_type GetType() const override;
		};

		class RUNTIME_API PathConverter : public TypeConverter
		{
		private:
			static std::mutex& getlocker();
			static std::weak_ptr<PathConverter> _thisWeakPtr;
		protected:
			PathConverter();
			PathConverter(PathConverter const&);
			void operator=(PathConverter const&);
		public:
			virtual ~PathConverter();

			static std::shared_ptr<PathConverter> GetSharedInstance();

			static PathConverter& GetInstance();

			bool CanConvertFrom(_type type) const;
			bool CanConvertTo(_type type) const;

			Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
			Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

			Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
			std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
		};
#pragma endregion

#pragma region Query
		/// <summary>
		/// ��ѯ��Ϣ
		/// </summary>
		class RUNTIME_API Query final : __uobject
		{
		private:
			static void DefineMeta(ClassInfo&);
			template<class T>
			friend void ClassInfo::Create(Type const*& pointer, const wchar_t* name, unsigned int size, ClassFlags flags);
		protected:
			std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;
		public:
			typedef std::vector<std::pair<std::wstring, std::wstring>> valuestype;
			typedef valuestype::const_iterator const_iterator;
			typedef valuestype::iterator iterator;
			typedef valuestype::value_type value_type;
		private:
			friend class UriHelper;
			bool sorted;
			valuestype values;
		public:
			/// <summary>
			/// ����<see cref="Query"/>ʵ��.
			/// </summary>
			__uref Query();
			/// <summary>
			/// ����<see cref="Query"/>�Ŀ���ʵ��.
			/// </summary>
			/// <param name="value">�ַ������ʽ</param>
			__uref Query(const std::wstring& value, bool dosort = false);

			/// <summary>
			/// �ж��Ƿ�Ϊ��
			/// </summary>
			/// <returns></returns>
			__uref bool GetIsEmpty() const;
			/// <summary>
			/// ����
			/// </summary>
			__uref void Sort();
			/// <summary>
			/// �ж��Ƿ�������
			/// </summary>
			/// <returns></returns>
			__uref bool GetIsSorted() const;
			/// <summary>
			/// ��ȡ������ַ������ʽ
			/// </summary>
			/// <returns></returns>
			__uref std::wstring GetEncodedString() const;
			/// <summary>
			/// ��ѯָ����ֵ
			/// </summary>
			/// <returns></returns>
			const_iterator Find(const std::wstring& key) const;
			/// <summary>
			/// ��ѯָ����ֵ
			/// </summary>
			/// <returns></returns>
			iterator Find(const std::wstring& key);
			/// <summary>
			/// �Ƿ�Ϊ��
			/// </summary>
			__uproperty(get = GetIsEmpty) bool IsEmpty;
			/// <summary>
			/// �Ƿ�������
			/// </summary>
			__uproperty(get = GetIsSorted) bool IsSorted;
			/// <summary>
			/// ������ַ������ʽ
			/// </summary>
			__uproperty(get = GetEncodedString) std::wstring EncodedString;
			/// <summary>
			/// ���Խ���
			/// </summary>
			/// <param name="input">����ֵ</param>
			/// <param name="loc">��������Ϣ</param>
			/// <param name="result">���</param>
			/// <returns></returns>
			static bool TryParse(const std::wstring& input, const CultureInfo& loc, Query& result);
			_type GetType() const override;
		};
		class RUNTIME_API QueryConverter : public TypeConverter
		{
		private:
			static std::mutex& getlocker();
			static std::weak_ptr<QueryConverter> _thisWeakPtr;
		protected:
			QueryConverter();
			QueryConverter(QueryConverter const&);
			void operator=(QueryConverter const&);
		public:
			virtual ~QueryConverter();

			static std::shared_ptr<QueryConverter> GetSharedInstance();

			static QueryConverter& GetInstance();

			bool CanConvertFrom(_type type) const;
			bool CanConvertTo(_type type) const;

			Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
			Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

			Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
			std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
		};
#pragma endregion

#pragma region Fragment
		/// <summary>
		/// Ƭ����Ϣ
		/// </summary>
		class RUNTIME_API Fragment final : __uobject
		{
		private:
			static void DefineMeta(ClassInfo&);
			template<class T>
			friend void ClassInfo::Create(Type const*& pointer, const wchar_t* name, unsigned int size, ClassFlags flags);
		protected:
			std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;
		private:
			friend class UriHelper;
			std::wstring value;
		public:
			/// <summary>
			/// ����<see cref="Fragment"/>ʵ��.
			/// </summary>
			__uref Fragment();
			/// <summary>
			/// ����<see cref="Fragment"/>�Ŀ���ʵ��.
			/// </summary>
			/// <param name="value">�ַ������ʽ</param>
			__uref Fragment(const std::wstring& value);
			/// <summary>
			/// �ж��Ƿ�Ϊ��
			/// </summary>
			/// <returns></returns>
			__uref bool GetIsEmpty() const;
			/// <summary>
			/// ��ȡ������ַ������ʽ
			/// </summary>
			__uref const std::wstring& GetDecodedString() const;
			/// <summary>
			/// ��ȡ������ַ������ʽ
			/// </summary>
			__uref std::wstring GetEncodedString() const;
			/// <summary>
			/// �Ƿ�Ϊ��
			/// </summary>
			__uproperty(get = GetIsEmpty) bool IsEmpty;
			/// <summary>
			/// ������ַ������ʽ
			/// </summary>
			__uproperty(get = GetDecodedString) const std::wstring& DecodedString;
			/// <summary>
			/// ������ַ������ʽ
			/// </summary>
			__uproperty(get = GetEncodedString) std::wstring EncodedString;
			/// <summary>
			/// ���Խ���
			/// </summary>
			/// <param name="input">����ֵ</param>
			/// <param name="loc">��������Ϣ</param>
			/// <param name="result">���</param>
			/// <returns></returns>
			static bool TryParse(const std::wstring& input, const CultureInfo& loc, Fragment& result);
			_type GetType() const override;
		};
		class RUNTIME_API FragmentConverter : public TypeConverter
		{
		private:
			static std::mutex& getlocker();
			static std::weak_ptr<FragmentConverter> _thisWeakPtr;
		protected:
			FragmentConverter();
			FragmentConverter(FragmentConverter const&);
			void operator=(FragmentConverter const&);
		public:
			virtual ~FragmentConverter();

			static std::shared_ptr<FragmentConverter> GetSharedInstance();

			static FragmentConverter& GetInstance();

			bool CanConvertFrom(_type type) const;
			bool CanConvertTo(_type type) const;

			Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
			Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

			Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
			std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
		};
#pragma endregion

	private:
		static void DefineMeta(ClassInfo&);
		template<class T>
		friend void ClassInfo::Create(Type const*& pointer, const wchar_t* name, unsigned int size, ClassFlags flags);
		Scheme scheme;
		Authority authority;
		Path path;
		Query query;
		Fragment fragment;
	protected:
		std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;
	public:
		__uref Uri();
		__uref Uri(const std::wstring& str);

		/// <summary>
		/// �ж��Ƿ�Ϊ��
		/// </summary>
		/// <returns></returns>
		__uref bool GetIsEmpty() const;
		/// <summary>
		/// �ж��Ƿ����
		/// </summary>
		/// <returns></returns>
		bool GetIsRelative() const;
		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		const Scheme& GetScheme() const;
		/// <summary>
		/// ��ȡ��������
		/// </summary>
		/// <returns></returns>
		Scheme& GetSchemeRef();
		/// <summary>
		/// ��ȡȨ����Ϣ
		/// </summary>
		/// <returns></returns>
		const Authority& GetAuthority() const;
		/// <summary>
		/// ��ȡȨ����Ϣ����
		/// </summary>
		/// <returns></returns>
		Authority& GetAuthorityRef();
		/// <summary>
		/// ��ȡ·��
		/// </summary>
		/// <returns></returns>
		const Path& GetPath();
		/// <summary>
		/// ��ȡ·������
		/// </summary>
		/// <returns></returns>
		Path& GetPathRef();
		/// <summary>
		/// ��ȡ��ѯ��Ϣ
		/// </summary>
		/// <returns></returns>
		const Query& GetQuery() const;
		/// <summary>
		/// ��ȡ��ѯ��Ϣ����
		/// </summary>
		/// <returns></returns>
		Query& GetQueryRef();
		/// <summary>
		/// ��ȡƬ����Ϣ
		/// </summary>
		/// <returns></returns>
		const Fragment& GetFragment() const;
		/// <summary>
		/// ��ȡƬ����Ϣ����
		/// </summary>
		/// <returns></returns>
		Fragment& GetFragmentRef();
		/// <summary>
		/// ��ȡ������ַ������ʽ
		/// </summary>
		__uref std::wstring GetEncodedString() const;
		/// <summary>
		/// �Ƿ�Ϊ��
		/// </summary>
		__uproperty(get = GetIsEmpty) bool IsEmpty;
		/// <summary>
		/// �Ƿ����
		/// </summary>
		__uproperty(get = GetIsRelative) bool IsRelative;
		/// <summary>
		/// ��������
		/// </summary>
		__uproperty(get = GetSchemeRef) Uri::Scheme& SchemePropertyRef;
		/// <summary>
		/// ����
		/// </summary>
		__uproperty(get = GetScheme) const Uri::Scheme& SchemeProperty;
		/// <summary>
		/// Ȩ����Ϣ����
		/// </summary>
		__uproperty(get = GetAuthorityRef) Uri::Authority& AuthorityPropertyRef;
		/// <summary>
		/// Ȩ����Ϣ
		/// </summary>
		__uproperty(get = GetAuthority) const Uri::Authority& AuthorityProperty;
		/// <summary>
		/// ·������
		/// </summary>
		__uproperty(get = GetPathRef) Uri::Path& PathPropertyRef;
		/// <summary>
		/// ·��
		/// </summary>
		__uproperty(get = GetPath) const Uri::Path& PathProperty;
		/// <summary>
		/// ��ѯ��Ϣ����
		/// </summary>
		__uproperty(get = GetQueryRef) Uri::Query& QueryPropertyRef;
		/// <summary>
		/// ��ѯ��Ϣ
		/// </summary>
		__uproperty(get = GetQuery) const Uri::Query& QueryProperty;
		/// <summary>
		/// Ƭ����Ϣ����
		/// </summary>
		__uproperty(get = GetFragmentRef) Uri::Fragment& FragmentPropertyRef;
		/// <summary>
		/// Ƭ����Ϣ
		/// </summary>
		__uproperty(get = GetFragment) const Uri::Fragment& FragmentProperty;
		/// <summary>
		/// ������ַ������ʽ
		/// </summary>
		__uproperty(get = GetEncodedString) std::wstring EncodedString;

		/// <summary>
		/// ���Խ���
		/// </summary>
		/// <param name="input">����ֵ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		static bool TryParse(const std::wstring& input, const CultureInfo& loc, Uri& result);

		_type GetType() const override;
	};

	class RUNTIME_API UriConverter : public TypeConverter
	{
	private:
		static std::mutex& getlocker();
		static std::weak_ptr<UriConverter> _thisWeakPtr;
	protected:
		UriConverter();
		UriConverter(UriConverter const&);
		void operator=(UriConverter const&);
	public:
		virtual ~UriConverter();

		static std::shared_ptr<UriConverter> GetSharedInstance();

		static UriConverter& GetInstance();

		bool CanConvertFrom(_type type) const;
		bool CanConvertTo(_type type) const;

		Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
		Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

		Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
		std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
	};

}