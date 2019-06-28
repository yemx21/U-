#pragma once
#include "CultureInfo.h"
#include "Event.h"
#include "Version.h"
namespace System
{	
	enum class AssembliesChangedNotification
	{
		Add,
		Remove,
	};

	/// <summary>
	/// ����ӿ�
	/// </summary>
	class RUNTIME_API IApplication
	{
	private:
		friend class Factory;
		void CoreCultureChanged(const CultureInfo&, const CultureInfo&);
		bool CoreAssembliesChanging(AssembliesChangedNotification, const wchar_t* name, const System::Version& ver, const UInt128& publicKey);
		void CoreAssembliesChanged(AssembliesChangedNotification, const wchar_t* name, const System::Version& ver, const UInt128& publicKey);

	protected:
		UInt128 Identifier;
		CultureInfo DefaultCulture;
		CultureInfo CurrentCulture;
		virtual void OnCultureChanged(const CultureInfo&, const CultureInfo&);
		virtual bool OnAssembliesChanging(AssembliesChangedNotification, const wchar_t* name, const System::Version& ver, const UInt128& publicKey);
		virtual void OnAssembliesChanged(AssembliesChangedNotification, const wchar_t* name, const System::Version& ver, const UInt128& publicKey);

		/// <summary>
		/// ���� <see cref="IApplication"/>ʵ��.
		/// </summary>
		/// <param name="appGuid">����</param>
		/// <param name="defCulture">Ĭ����������Ϣ</param>
		IApplication(const UInt128& appGuid, const CultureInfo& defCulture);
		~IApplication();

	public:
		MultiCastDelegate<const CultureInfo&, const CultureInfo&> CultureChanged;
		MultiCastDelegate<AssembliesChangedNotification, const wchar_t*, const System::Version&, const UInt128&> AssembliesChanged;

	};
}