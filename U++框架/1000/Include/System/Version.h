#pragma once
#include "Object.h"
#include "TypeConverter.h"
#include <mutex>
#include "ClassInfo.h"

namespace System
{
	/// <summary>
	/// �汾��
	/// </summary>
	class RUNTIME_API Version final: __uobject
	{
	private:
		int _Build;
		int _Revision;
		int _Major;
		int _Minor;
		static void DefineMeta(ClassInfo&);
		template<class T>
		friend void ClassInfo::Create(Type const*& pointer, const wchar_t* name, unsigned int size, ClassFlags flags);
	protected:
		std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const override;
	public:
		/// <summary>
		/// ����<see cref="Version"/>ʵ��.
		/// </summary>
		/// <param name="major">���汾��</param>
		/// <param name="minor">��Ҫ�汾��</param>
		/// <param name="build">�ڲ��汾��</param>
		/// <param name="revision">�޶���</param>
		__uref Version(int major, int minor, int build, int revision);		

		/// <summary>
		/// ����<see cref="Version"/>ʵ��.
		/// </summary>
		/// <param name="major">���汾��</param>
		/// <param name="minor">��Ҫ�汾��</param>
		/// <param name="build">�ڲ��汾��</param>
		__uref Version(int major, int minor, int build);

		/// <summary>
		/// ����<see cref="Version"/>ʵ��.
		/// </summary>
		/// <param name="major">���汾��</param>
		/// <param name="minor">��Ҫ�汾��</param>
		__uref Version(int major, int minor);

		/// <summary>
		/// ����<see cref="Version"/>ʵ��.
		/// </summary>
		__uref Version();

		/// <summary>
		/// ����<see cref="Version"/>�Ŀ���ʵ��.
		/// </summary>
		__uref Version(const Version& ver);

		/// <summary>
		/// ��ȡ���汾��
		/// </summary>
		/// <returns></returns>
		int GetMajor() const;

		/// <summary>
		/// ��ȡ��Ҫ�汾��
		/// </summary>
		/// <returns></returns>
		int GetMinor() const;

		/// <summary>
		/// ��ȡ�ڲ��汾��
		/// </summary>
		/// <returns></returns>
		int GetBuild() const;

		/// <summary>
		/// ��ȡ�޶���
		/// </summary>
		/// <returns></returns>
		int GetRevision() const;

		/// <summary>
		/// ��ȡ�޶��ŵĸ�16λ
		/// </summary>
		/// <returns></returns>
		short GetMajorRevision() const;

		/// <summary>
		/// ��ȡ�޶��ŵĵ�16λ
		/// </summary>
		/// <returns></returns>
		short GetMinorRevision() const;

		/// <summary>
		/// �������汾��
		/// </summary>
		/// <param name="major">���汾��</param>
		void SetMajor(int major);

		/// <summary>
		/// ���ô�Ҫ�汾��
		/// </summary>
		/// <param name="major">��Ҫ�汾��</param>
		void SetMinor(int minor);
		

		/// <summary>
		/// �����ڲ��汾��
		/// </summary>
		/// <param name="major">�ڲ��汾��</param>
		void SetBuild(int build);

		/// <summary>
		/// �����޶���
		/// </summary>
		/// <param name="major">�޶���</param>
		void SetRevision(int revision);

		/// <summary>
		/// �ж��Ƿ�Ϊ��
		/// </summary>
		/// <returns></returns>
		bool GetIsEmpty() const;

		/// <summary>
		/// ���汾��
		/// </summary>
		__uproperty(get = GetMajor, put = SetMajor) int Major;
		/// <summary>
		/// ��Ҫ�汾��
		/// </summary>
		__uproperty(get = GetMinor, put = SetMinor) int Minor;
		/// <summary>
		/// �ڲ��汾��
		/// </summary>
		__uproperty(get = GetBuild, put = SetBuild) int Build;
		/// <summary>
		/// �޶���
		/// </summary>
		__uproperty(get = GetRevision, put = SetRevision) int Revision;
		/// <summary>
		/// �޶��ŵĸ�16λ
		/// </summary>
		__uproperty(get = GetMajorRevision) short MajorRevision;
		/// <summary>
		/// �޶��ŵĵ�16λ
		/// </summary>
		__uproperty(get = GetMinorRevision) short MinorRevision;
		/// <summary>
		/// �Ƿ�Ϊ��
		/// </summary>
		__uproperty(get = GetIsEmpty)bool IsEmpty;

		__uref bool operator == (Version& ver) const;
		__uref bool operator == (const Version& ver) const;
		__uref bool operator != (Version& ver) const;
		__uref bool operator != (const Version& ver) const;
		__uref bool operator > (Version& ver) const;
		__uref bool operator > (const Version& Ver) const;
		__uref bool operator < (Version& ver) const;
		__uref bool operator < (const Version& ver) const;
		__uref bool operator >= (Version& ver) const;
		__uref bool operator >= (const Version& ver) const;
		__uref bool operator <= (Version& ver) const;
		__uref bool operator <= (const Version& ver) const;

		/// <summary>
		/// ���Խ���
		/// </summary>
		/// <param name="input">����ֵ</param>
		/// <param name="loc">��������Ϣ</param>
		/// <param name="result">���</param>
		/// <returns></returns>
		static bool TryParse(const std::wstring& input, const CultureInfo& loc, Version& result);

		_type GetType() const override;
	};

	class RUNTIME_API VersionConverter : public TypeConverter
	{
	private:
		static std::mutex& getlocker();
		static std::weak_ptr<VersionConverter> _thisWeakPtr;
	protected:
		VersionConverter();
		VersionConverter(VersionConverter const&);
		void operator=(VersionConverter const&);
	public:
		virtual ~VersionConverter();

		static std::shared_ptr<VersionConverter> GetSharedInstance();

		static VersionConverter& GetInstance();

		bool CanConvertFrom(_type type) const;
		bool CanConvertTo(_type type) const;

		Any ConvertFrom(const Any& obj, const CultureInfo& loc) const;
		Any ConvertTo(const Any& obj, _type type, const CultureInfo& loc) const;

		Any ConvertFromString(const std::wstring& str, const CultureInfo& loc) const;
		std::wstring ConvertToString(const Any& obj, const CultureInfo& loc) const;
	};

}