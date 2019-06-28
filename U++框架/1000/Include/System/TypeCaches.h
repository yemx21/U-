#pragma once

#include "NameSpace.h"

//#include <objbase.h>
#include <algorithm>

namespace System
{
	class TypeCaches_impl;

	/// <summary>
	/// ���ͼ��ϣ����棩
	/// </summary>
	class RUNTIME_API TypeCaches
	{
	protected:
		friend class TypeCaches_impl;
		TypeCaches_impl* impl;
	public:

		/// <summary>
		/// ����<see cref="TypeCaches"/>ʵ��
		/// </summary>
		TypeCaches();
		~TypeCaches();

		/// <summary>
		/// ����ָ������
		/// </summary>
		/// <param name="type">ָ������</param>
		/// <returns></returns>
		NameSpaceError Insert(_type type);

		/// <summary>
		/// �Ƴ�ָ������
		/// </summary>
		/// <param name="type">ָ������</param>
		/// <returns></returns>
		void Remove(_type type);

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <param name="index">����</param>
		/// <returns></returns>
		_type GetItem(size_t index) const;

		/// <summary>
		/// ��ȡ������
		/// </summary>
		/// <returns></returns>
		size_t GetItemSize() const;

		/// <summary>
		/// ������
		/// </summary>
		_declspec(property(get = GetItemSize)) size_t ItemSize;
		/// <summary>
		/// ����
		/// </summary>
		_declspec(property(get = GetItem)) _type Items[];
	};
}