#pragma once
#include "CultureInfo.h"
#include "Reflection.h"
namespace System
{
	/// <summary>
	/// �������ýӿ�
	/// </summary>
	class RUNTIME_API ITranslatable : __uobject
	{
	public:
		/// <summary>
		/// ��ȡ����Դ
		/// </summary>
		/// <returns></returns>
		__uref virtual InertiaString GetSource() const = 0;

		/// <summary>
		/// ��ȡ�Ƿ����÷���
		/// </summary>
		/// <returns></returns>
		__uref virtual bool GetEnabled() const = 0;

		/// <summary>
		/// �����Ƿ����÷���
		/// </summary>
		/// <returns></returns>
		__uref virtual void SetEnabled(bool)= 0;

		/// <summary>
		/// ����Դ
		/// </summary>
		__uproperty(get = GetSource) InertiaString Source;

		/// <summary>
		/// �Ƿ����÷���
		/// </summary>
		__uproperty(get = GetEnabled, put = SetEnabled) bool Enabled;

		REFLECT_CLASS(ITranslatable)
	};

	/// <summary>
	/// �������ýӿ�
	/// </summary>
	class RUNTIME_API ITranslatable1:  public ITranslatable
	{
	public:
		/// <summary>
		/// ��ȡ����Դ
		/// </summary>
		/// <returns></returns>
		__uref virtual InertiaString GetSource() const =0;

		/// <summary>
		/// ��ȡ�Ƿ����÷���
		/// </summary>
		/// <returns></returns>
		__uref virtual bool GetEnabled() const = 0;

		/// <summary>
		/// �����Ƿ����÷���
		/// </summary>
		/// <returns></returns>
		__uref virtual void SetEnabled(bool)= 0;

		/// <summary>
		/// ��ȡ�Ƿ�����ڵ�ǰȫ����������Ϣ
		/// </summary>
		/// <returns></returns>
		__uref virtual bool GetIsDependent() const = 0;

		/// <summary>
		/// ��ȡ�������������
		/// </summary>
		/// <returns></returns>
		__uref virtual InertiaString GetTranslationContext() const = 0;

		/// <summary>
		/// ����Դ
		/// </summary>
		__uproperty(get = GetSource) InertiaString Source;

		/// <summary>
		/// �Ƿ����÷���
		/// </summary>
		__uproperty(get = GetEnabled, put = SetEnabled) bool Enabled;

		/// <summary>
		/// �Ƿ�����ڵ�ǰȫ����������Ϣ
		/// </summary>
		__uproperty(get = GetIsDependent) bool IsDependent;

		/// <summary>
		/// �������������
		/// </summary>
		__uproperty(get = GetTranslationContext) InertiaString TranslationContext;

		REFLECT_CLASS(ITranslatable1)
	};

	/// <summary>
	/// ���׷�������
	/// </summary>
	class RUNTIME_API SimpleTranslationReference : public ITranslatable
	{
	private:
		InertiaString _source;
		bool _isEnabled;
	public:
		/// <summary>
		/// ���� <see cref="SimpleTranslationReference"/>ʵ��.
		/// </summary>
		/// <param name="source">����Դ</param>
		/// <param name="isEnabled">�Ƿ����÷���</param>
		__uctor SimpleTranslationReference(const InertiaString& source, bool isEnabled = true);

		/// <summary>
		/// ��ȡ����Դ
		/// </summary>
		/// <returns></returns>
		__uref InertiaString GetSource() const override;

		/// <summary>
		/// ��ȡ�Ƿ����÷���
		/// </summary>
		/// <returns></returns>
		__uref bool GetEnabled() const override;

		/// <summary>
		/// �����Ƿ����÷���
		/// </summary>
		/// <returns></returns>
		__uref void SetEnabled(bool) override;

		/// <summary>
		/// ����Դ
		/// </summary>
		__uproperty(get = GetSource) InertiaString Source;

		/// <summary>
		/// �Ƿ����÷���
		/// </summary>
		__uproperty(get = GetEnabled, put = SetEnabled) bool Enabled;


		REFLECT_CLASS(SimpleTranslationReference)
	};

	/// <summary>
	/// ���׷�������1
	/// </summary>
	class RUNTIME_API SimpleTranslationReference1 : public ITranslatable1
	{
	private:
		InertiaString _source;
		InertiaString _translationContext;
		bool _isEnabled;
		bool _isDependent;
	public:
		/// <summary>
		/// ���� <see cref="SimpleTranslationReference1"/>ʵ��.
		/// </summary>
		/// <param name="source">����Դ</param>
		/// <param name="translationContext">�������������</param>
		/// <param name="isEnabled">�Ƿ����÷���</param>
		/// <param name="isDependent">�Ƿ�����ڵ�ǰȫ����������Ϣ</param>
		__uctor SimpleTranslationReference1(const InertiaString& source, const InertiaString& translationContext, bool isEnabled = true, bool isDependent = false);

		/// <summary>
		/// ��ȡ����Դ
		/// </summary>
		/// <returns></returns>
		__uref InertiaString GetSource() const override;

		/// <summary>
		/// ��ȡ�Ƿ����÷���
		/// </summary>
		/// <returns></returns>
		__uref bool GetEnabled() const override;

		/// <summary>
		/// �����Ƿ����÷���
		/// </summary>
		/// <returns></returns>
		__uref void SetEnabled(bool) override;

		/// <summary>
		/// ��ȡ�Ƿ�����ڵ�ǰȫ����������Ϣ
		/// </summary>
		/// <returns></returns>
		__uref bool GetIsDependent() const override;

		/// <summary>
		/// ��ȡ�������������
		/// </summary>
		/// <returns></returns>
		__uref InertiaString GetTranslationContext() const override;

		/// <summary>
		/// ����Դ
		/// </summary>
		__uproperty(get = GetSource) InertiaString Source;

		/// <summary>
		/// �Ƿ����÷���
		/// </summary>
		__uproperty(get = GetEnabled, put = SetEnabled) bool Enabled;

		/// <summary>
		/// �Ƿ�����ڵ�ǰȫ����������Ϣ
		/// </summary>
		__uproperty(get = GetIsDependent) bool IsDependent;

		/// <summary>
		/// �������������
		/// </summary>
		__uproperty(get = GetTranslationContext) InertiaString TranslationContext;
		REFLECT_CLASS(SimpleTranslationReference1)
	};
}