#pragma once
#include "Version.h"
//#include <guiddef.h>
#include <vector>
#include "Common.h"
namespace System
{
	class NameSpace;
	class Factory;

	/// <summary>
	/// ���򼯴���ö��
	/// </summary>
	enum class AssemblyError
	{
		/// <summary>
		/// �ɹ�
		/// </summary>
		Success,

		/// <summary>
		/// �������ռ�
		/// </summary>
		EmptyNameSpace,

		/// <summary>
		/// ��Ч�����ռ�
		/// </summary>
		InvalidNameSpace,

		/// <summary>
		/// �Ѵ���
		/// </summary>
		Existed,

		/// <summary>
		/// �ѱ���һ����������
		/// </summary>
		OwnedByOther,
	};

	class Assembly_impl;

	class NameSpaceEnumerator_impl;

	/// <summary>
	/// �����ռ�ö������
	/// </summary>
	class RUNTIME_API NameSpaceEnumerator : _noncopyable
	{
	private:
		friend class NameSpace;
		friend class Assembly;
		friend class NameSpaceEnumerator_impl;
		NameSpaceEnumerator_impl* impl;
		NameSpaceEnumerator();
	public:
		~NameSpaceEnumerator();

		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		unsigned int GetCount() const;

		/// <summary>
		/// ��ȡ��ǰ��������
		/// </summary>
		/// <returns></returns>
		const wchar_t* GetCurrentName() const;

		/// <summary>
		/// ��ȡ��ǰ����
		/// </summary>
		/// <returns></returns>
		const NameSpace* GetCurrent() const;

		/// <summary>
		/// ��ȡ������������
		/// </summary>
		/// <returns></returns>
		const Assembly* GetCurrentAssembly() const;

		/// <summary>
		/// ��һ����
		/// </summary>
		void Next();

		/// <summary>
		/// �ж��Ƿ������ĩβ
		/// </summary>
		bool GetIsEnd() const;

		/// <summary>
		/// ��ǰ��������
		/// </summary>
		__declspec(property(get = GetCurrentName)) const wchar_t* CurrentName;

		/// <summary>
		/// ��ǰ����
		/// </summary>
		__declspec(property(get = GetCurrent)) const NameSpace* Current;

		/// <summary>
		/// ��ǰ������������
		/// </summary>
		__declspec(property(get = GetCurrentAssembly)) const Assembly* CurrentAssembly;

		/// <summary>
		/// ������
		/// </summary>
		__declspec(property(get = GetCount)) unsigned int Count;

		/// <summary>
		/// �Ƿ������ĩβ
		/// </summary>
		__declspec(property(get = GetIsEnd)) bool IsEnd;
	};

	/// <summary>
	/// ����
	/// </summary>
	class RUNTIME_API Assembly final: _noncopyable
	{
	private:
		friend class Factory;
		friend class Assembly_impl;
		Assembly_impl*  internal; 
		Assembly(); 
	public:
		/// <summary>
		/// ��ȡ�����ռ�ö����
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<NameSpaceEnumerator> GetNameSpaceEnumerator(bool subNameSpace) const;

		/// <summary>
		/// ���������ռ�
		/// </summary>
		/// <returns></returns>
		AssemblyError AddNameSpace(NameSpace* space);

		/// <summary>
		/// ɾ�������ռ�
		/// </summary>
		/// <returns></returns>
		AssemblyError RemoveNameSpace(NameSpace* space);

		/// <summary>
		/// ��������
		/// </summary>
		/// <param name="name">ָ������</param>
		/// <returns></returns>
		static Assembly* Create(const wchar_t* name);

		/// <summary>
		/// ��������
		/// </summary>
		/// <param name="name">ָ������</param>
		/// <param name="ver">�汾��</param>
		/// <returns></returns>
		static Assembly* Create(const wchar_t* name, const System::Version& ver);

		/// <summary>
		/// ��������
		/// </summary>
		/// <param name="name">ָ������</param>
		/// <param name="ver">�汾��</param>
		/// <param name="publicKey">����</param>
		/// <returns></returns>
		static Assembly* Create(const wchar_t* name, const System::Version& ver, uGUID publicKey);

		/// <summary>
		/// ����ָ�����Ƶ������ռ�
		/// </summary>
		/// <param name="name">ָ������</param>
		/// <returns></returns>
		const NameSpace* FindNameSpace(const wchar_t* name) const;

		~Assembly();

		const wchar_t* GetName() const;
		const uGUID GetToken() const;
		const System::Version* GetVersion() const;

		_declspec(property(get = GetName)) const wchar_t* Name;
		_declspec(property(get = GetToken)) const uGUID Token;
		_declspec(property(get = GetVersion)) const System::Version* Version;

		bool operator ==(const Assembly& assembly) const;
		bool operator !=(const Assembly& assembly) const;

	};
}