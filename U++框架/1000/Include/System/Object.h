#pragma once
#include "Type.h"
#include "IFormattable.h"
#include <memory>

namespace System
{
	typedef void(*CreateMetaFunc)(Type&);


	/// <summary>
	/// ��������
	/// </summary>
	class RUNTIME_API Object : public IFormattable
	{
	protected:
		constexpr Object() {}
		/// <summary>
		/// �Զ����ַ���ת��
		/// </summary>
		/// <param name="fmt">��ʽ��</param>
		/// <param name="loc">��������Ϣ</param>
		/// <returns></returns>
		virtual std::wstring CustomToString(const wchar_t* fmt, const CultureInfo& loc) const;

		/// <summary>
		/// Ԫ����
		/// </summary>
		__umeta Meta;

	public:

		virtual ~Object();

		/// <summary>
		/// ��ȡ��������
		/// </summary>
		/// <returns></returns>
		virtual _type GetType() const;

		/// <summary>
		/// �ж��Ƿ�ָ������
		/// </summary>
		/// <param name="type">ָ������</param>
		bool Is(_type type) const;

		/// <summary>
		/// �ж�ָ�������Ƿ��뵱ǰ������ͬ
		/// </summary>
		/// <param name="ref">ָ������</param>
		/// <returns></returns>
		virtual bool Equals(const Object* ref) const;

		/// <summary>
		/// ��ȡ��ǰ�����ϣֵ
		/// </summary>
		/// <returns></returns>
		virtual uhash GetHashCode() const;
	};

	template<class T>
	inline T* SafeCast(Object* base)
	{
		if (base != NULL && base->Is(TypeHelper<T>::GetType()))
		{
			return static_cast<T*>(base);
		}
		else
		{
			return NULL;
		}
	}

	template<class T>
	inline const T* SafeCast(const Object* base)
	{
		if (base != NULL && base->Is(TypeHelper<T>::GetType()))
		{
			return static_cast<const T*>(base);
		}
		else
		{
			return NULL;
		}
	}

	typedef std::shared_ptr<Object> ObjectPtr;

}
