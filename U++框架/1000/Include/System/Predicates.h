#pragma once

namespace System
{
	class ConstructorInfo;
	class MethodInfo;
	class PropertyInfo;
	class OperatorInfo;
	class Attribute;
	class FieldInfo;

	/// <summary>
	/// ���캯��ƥ��ص�����
	/// </summary>
	typedef bool(*ConstructorPredicate)(const ConstructorInfo* info);

	/// <summary>
	/// ����ƥ��ص�����
	/// </summary>
	typedef bool(*MethodPredicate)(const MethodInfo* info);

	/// <summary>
	/// ����ƥ��ص�����
	/// </summary>
	typedef bool(*PropertyPredicate)(const PropertyInfo* info);

	/// <summary>
	/// �����ƥ��ص�����
	/// </summary>
	typedef bool(*OperatorPredicate)(const OperatorInfo* info);

	/// <summary>
	/// ��ǩƥ��ص�����
	/// </summary>
	typedef bool(*AttributePredicate)(const Attribute* attr);

	/// <summary>
	/// ��Ա����ƥ��ص�����
	/// </summary>
	typedef bool(*FieldPredicate)(const FieldInfo* attr);
}