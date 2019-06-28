#pragma once
#include "Result.h"
#include "Type.h"
namespace System
{
	class ResultType_impl;

	/// <summary>
	/// �������
	/// </summary>
	class RUNTIME_API ResultType final: public Type
	{
	protected:
		friend class TypeFactory;

		/// <summary>
		/// ����<see cref="ResultType"/>ʵ��
		/// </summary>
		/// <param name="type1">����1</param>
		/// <param name="type2">����2</param>
		/// <param name="type3">����3</param>
		/// <param name="stype">״̬����</param>
		/// <param name="rtype">�����������</param>
		/// <returns></returns>
		static const ResultType* Create(_type type1, _type type2, _type type3, _type stype, ResultTypes rtype);
	public:

		virtual ~ResultType();

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		virtual const wchar_t* GetName() const;

		/// <summary>
		/// ����
		/// </summary>
		__declspec(property(get = GetName)) const wchar_t* Name;

		/// <summary>
		/// ��ȡ����1
		/// </summary>
		/// <returns></returns>
		_type GetType1() const;

		/// <summary>
		/// ����1
		/// </summary>
		__declspec(property(get = GetType1)) _type Type1;
		
		/// <summary>
		/// ��ȡ����2
		/// </summary>
		/// <returns></returns>
		_type GetType2() const;

		/// <summary>
		/// ����2
		/// </summary>
		__declspec(property(get = GetType2)) _type Type2;	

		/// <summary>
		/// ��ȡ����3
		/// </summary>
		/// <returns></returns>
		_type GetType3() const;

		/// <summary>
		/// ����3
		/// </summary>
		__declspec(property(get = GetType3)) _type Type3;

		/// <summary>
		/// ��ȡ״̬����
		/// </summary>
		/// <returns></returns>
		_type GetStateType() const;

		/// <summary>
		/// ״̬����
		/// </summary>
		__declspec(property(get = GetStateType)) _type StateType;

		/// <summary>
		/// ��ȡ�����������
		/// </summary>
		/// <returns></returns>
		ResultTypes GetResultType() const;

		/// <summary>
		/// �����������
		/// </summary>
		__declspec(property(get = GetResultType)) ResultTypes RTypes;
	private:
		friend class Type;
		friend class ResultType_impl;
		ResultType_impl* impl;
		ResultType(_type type1, _type type2, _type type3, _type stype, ResultTypes rtype);

	};

}