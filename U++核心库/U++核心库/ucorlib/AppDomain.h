#pragma once
#include "Config.h"
#include "Reflection.h"
#include "IApplication.h"
namespace System
{
	class AppDomain;

	class Factory;

	class AssemblyEnumerator_impl;

	/// <summary>
	/// ����ö������
	/// </summary>
	class RUNTIME_API AssemblyEnumerator: _noncopyable
	{
	private:
		friend class AppDomain;
		friend class AssemblyEnumerator_impl;
		AssemblyEnumerator_impl* impl;
		AssemblyEnumerator();
	public:
		~AssemblyEnumerator();

		unsigned int GetCount() const;

		const wchar_t* GetCurrentName() const;

		Version GetCurrentVersion() const;

		uGUID GetCurrentPublicKey() const;

		const Assembly* GetCurrent(char* privateKey = nullptr, unsigned int privateKeySize = 0) const;

		void Next();

		void Previous();

		bool GetIsEnd() const;

		__declspec(property(get = GetCurrentName)) const wchar_t* CurrentName;
		__declspec(property(get = GetCurrentVersion)) Version CurrentVersion;
		__declspec(property(get = GetCurrentPublicKey)) uGUID CurrentPublicKey;
		__declspec(property(get = GetCount)) unsigned int Count;
		__declspec(property(get = GetIsEnd)) bool IsEnd;
	};

	class AppDomain_impl;

	/// <summary>
	/// ��������
	/// </summary>
	class RUNTIME_API AppDomain final: _noncopyable
	{
	protected:
		friend class Factory;
		friend class AppDomain_impl;
		static AppDomain_impl* impl;
	private:
		AppDomain();
	public:
		/// <summary>
		/// ����ָ��·���Ļ���U++�Ķ�̬���ӿ�(.dll)
		/// </summary>
		/// <param name="path">����·��</param>
		/// <returns></returns>
		static Result<FactoryDllError, safe_void_ptr> LoadDll(const wchar_t* path);

		/// <summary>
		/// ж��ָ������U++��ģ��
		/// </summary>
		/// <param name="module">ָ��ģ��</param>
		/// <returns></returns>
		static Result<FactoryDllError> UnLoadDll(const safe_void_ptr& module);

		/// <summary>
		/// ��ȡ��ǰ������ĳ���ö����
		/// </summary>
		/// <returns></returns>
		static std::unique_ptr<AssemblyEnumerator> GetAssemblyEnumerator();

		/// <summary>
		/// ��ȡָ��ģ��ĳ���ö����
		/// </summary>
		/// <param name="module">ָ��ģ��</param>
		/// <returns></returns>
		static std::unique_ptr<AssemblyEnumerator> GetAssemblyEnumerator(const safe_void_ptr& module);

		/// <summary>
		/// ����ָ������
		/// </summary>
		/// <param name="name">ָ������</param>
		/// <param name="ver">ָ���汾��</param>
		/// <returns></returns>
		static const Assembly* FindAssembly(const wchar_t* name, const System::Version& ver);

		/// <summary>
		/// ����ָ������
		/// </summary>
		/// <param name="name">ָ������</param>
		/// <param name="ver">ָ���汾��</param>
		/// <param name="privateKey">˽��</param>
		/// <param name="privateKeySize">˽�׳���</param>
		/// <returns></returns>
		static const Assembly* FindAssembly(const wchar_t* name, const System::Version& ver, char* privateKey, unsigned int privateKeySize);

		/// <summary>
		/// ����ָ������
		/// </summary>
		/// <param name="name">ָ������</param>
		/// <param name="ver">ָ���汾��</param>
		/// <param name="publicKey">����</param>
		/// <param name="privateKey">˽��</param>
		/// <param name="privateKeySize">˽�׳���</param>
		/// <returns></returns>
		static const Assembly* FindAssembly(const wchar_t* name, const System::Version& ver, uGUID publicKey, char* privateKey, unsigned int privateKeySize);


		/// <summary>
		/// ����128λ�Ĺ�ϣֵ
		/// </summary>
		///<remarks>����0��˵���ڲ�����</remarks>
		/// <returns></returns>
		static UInt128 GenerateHashId128();

		/// <summary>
		/// ע��128λ�Ĺ�ϣֵ
		/// </summary>
		static void DestoryHashId128(const UInt128& id);

		/// <summary>
		/// �������԰�
		/// </summary>
		/// <returns></returns>
		static Result<bool> LoadLanguagePackage(const wchar_t* path);


		~AppDomain();
	};
}