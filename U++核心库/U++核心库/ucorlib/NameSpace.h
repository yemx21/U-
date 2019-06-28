#pragma once
#include "Config.h"
#include <vector>
#include "Common.h"
namespace System
{
	class Assembly;
	class NameSpaceEnumerator_impl;
	class NameSpaceEnumerator;
	class Type;
	class NameSpace_impl;
	class TypeEnumerator_impl;

	/// <summary>
	/// �����ռ����
	/// </summary>
	enum class NameSpaceError
	{
		/// <summary>
		/// �ɹ�
		/// </summary>
		Success,

		/// <summary>
		/// �޴���
		/// </summary>
		None,

		/// <summary>
		/// ������
		/// </summary>
		EmptyType,

		/// <summary>
		/// ��Ч����
		/// </summary>
		InvalidType,

		/// <summary>
		/// �Ѵ���
		/// </summary>
		Existed,

		/// <summary>
		/// δ֪����
		/// </summary>
		Unknown,

		/// <summary>
		/// �������ռ�
		/// </summary>
		EmptyNameSpace,

		/// <summary>
		/// ��Ч�����ռ�
		/// </summary>
		InvalidNameSpace,

		/// <summary>
		/// �ѱ���һ����������
		/// </summary>
		OwnedByOther,
	};

	/// <summary>
	/// ����ö������
	/// </summary>
	class RUNTIME_API TypeEnumerator:_noncopyable
	{
	private:
		friend class NameSpace;
		TypeEnumerator_impl* impl;
		TypeEnumerator();
	public:
		~TypeEnumerator();
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
		_type GetCurrent() const;

		/// <summary>
		/// ��ȡ��ǰ�������������ռ�
		/// </summary>
		/// <returns></returns>
		const NameSpace* GetCurrentNameSpace() const;

		/// <summary>
		/// ��ȡ��ǰ������������
		/// </summary>
		/// <returns></returns>
		const Assembly* GetCurrentAssembly() const;

		/// <summary>
		/// ��ȡ��һ������
		/// </summary>
		/// <returns></returns>
		void Next();

		/// <summary>
		/// ��ȡ��һ������
		/// </summary>
		/// <returns></returns>
		void Previous();

		/// <summary>
		/// ��ȡ�Ƿ������ĩβ
		/// </summary>
		/// <returns></returns>
		bool GetIsEnd() const;

		/// <summary>
		/// ��ǰ��������
		/// </summary>
		__declspec(property(get = GetCurrentName)) const wchar_t* CurrentName;

		/// <summary>
		/// ��ǰ����
		/// </summary>
		__declspec(property(get = GetCurrent)) _type Current;

		/// <summary>
		/// ��ǰ�������������ռ�
		/// </summary>
		__declspec(property(get = GetCurrentNameSpace)) const NameSpace* CurrentNameSpace;

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
	/// �����ռ�
	/// </summary>
	class RUNTIME_API NameSpace final: _noncopyable
	{
	private:
		friend class Assembly;
		friend class NameSpace_impl;
		friend class NameSpaceEnumerator_impl;
		NameSpace_impl* internal;
	public:		

		/// <summary>
		/// ��ȡ����ö����
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<TypeEnumerator> GetTypeEnumerator() const;

		/// <summary>
		/// ��ȡ�����ռ�ö����
		/// </summary>
		/// <returns></returns>
		std::unique_ptr<NameSpaceEnumerator> GetNameSpaceEnumerator(bool subNameSpace) const;

		/// <summary>
		/// ���������ռ�
		/// </summary>
		/// <returns></returns>
		NameSpaceError AddNameSpace(NameSpace* space);

		/// <summary>
		/// ע��ָ������
		/// </summary>		
		/// <param name="type">ָ������</param>
		/// <returns></returns>
		NameSpaceError Register(_type type);

		/// <summary>
		/// ж��ָ������
		/// </summary>		
		/// <param name="type">ָ������</param>
		/// <returns></returns>
		NameSpaceError UnRegister(_type type);

		/// <summary>
		/// ж��ָ������
		/// </summary>		
		/// <param name="subnamespace">�������ռ�����</param>
		/// <param name="type">ָ������</param>
		/// <returns></returns>
		NameSpaceError UnRegister(const wchar_t* subnamespace, _type type);


		/// <summary>
		/// ����<see cref="NameSpace"/>ʵ��.
		/// </summary>
		/// <param name="name">����</param>
		NameSpace(const wchar_t* name);

		~NameSpace();

		/// <summary>
		/// ����ָ�����Ƶ�����
		/// </summary>
		/// <param name="name">����</param>
		/// <returns></returns>
		_type FindType(const wchar_t* name) const;

		/// <summary>
		/// ����ָ�����Ƶ������ռ�
		/// </summary>
		/// <param name="name">ָ������</param>
		/// <returns></returns>
		const NameSpace* FindNameSpace(const wchar_t* name) const;

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		const wchar_t* GetName() const;

		/// <summary>
		/// ��ȡ��������
		/// </summary>
		/// <returns></returns>
		const Assembly* GetAssembly() const;

		/// <summary>
		/// ��ȡ���������ռ�
		/// </summary>
		/// <returns></returns>
		const NameSpace* GetParent() const;

		/// <summary>
		/// ����
		/// </summary>
		/// <returns></returns>
		_declspec(property(get = GetName)) const wchar_t* Name;

		/// <summary>
		///��������
		/// </summary>
		/// <returns></returns>
		_declspec(property(get = GetAssembly)) const System::Assembly* Assembly;

		/// <summary>
		///���������ռ�
		/// </summary>
		/// <returns></returns>
		_declspec(property(get = GetParent)) const NameSpace* Parent;

		bool operator ==(const NameSpace& space) const;
		bool operator !=(const NameSpace& space) const;

	};
}