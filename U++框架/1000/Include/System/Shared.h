#pragma once
#include "Reflection.h"
#include "Object.h"
namespace System
{
	/// <summary>
	/// ���Ķ�̬��ӿ�
	/// </summary>
	struct CoreDllMain
	{
		/// <summary>
		/// ��ʼ������
		/// </summary>
		Result<bool, safe_void_ptr> (*Init)();

		/// <summary>
		/// �˳�����
		/// </summary>
		Result<bool> (*Exit)();
		
		/// <summary>
		///  ��������
		/// </summary>
		const FactoryHelper* Helper;
	};
	/// <summary>
	/// ��ʼ������
	/// </summary>
	typedef CoreDllMain* (*CoreDllMainEntry)();       ///�����ӿں�����ַ

}
