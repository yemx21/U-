#pragma once 
#include "Type.h"
#include "Common.h"
#include <array>
namespace System
{
	class ArrayType_impl;

	/*
	Array T[N]:  FixedSize=N,0,0,0,0  ItemType=T
	Array T[N1][N2]:  FixedSize=N1,N2,0,0,0  ItemType=T
	Array T[N1][N2][N3]:  FixedSize=N1,N2,N3,0,0  ItemType=T
	Array T[N1][N2][N3][N4]:  FixedSize=N1,N2,N3,N4,0 ItemType=T
	Array T[N1][N2][N3][N4][N5]:  FixedSize=N1,N2,N3,N4,N5 ItemType=T

	STL_array<T, N>:  FixedSize=N, ItemType=T
	STL_valarray<T>:  FixedSize=0, ItemType=T

	STL_vector<T, std::allocator<T>> :   FixedSize=0, ItemType=T, ItemAllocatorType=std::allocator<T>
	STL_deque<T, std::allocator<T>>:   FixedSize=0, ItemType=T, ItemAllocatorType=std::allocator<T>
	STL_forward_list<T, std::allocator<T>>:   FixedSize=0, ItemType=T, ItemAllocatorType=std::allocator<T>
	STL_list<T, std::allocator<T>>:   FixedSize=0, ItemType=T, ItemAllocatorType=std::allocator<T>

	STL_set<Key, std::less<Key>, std::allocator<Key>>:   FixedSize=0, KeyType=Key, KeyCompareType=std::less<Key>, KeyAllocatorType=std::allocator<T>
	STL_multiset<Key, std::less<Key>, std::allocator<Key>>:   FixedSize=0, KeyType=Key, KeyCompareType=std::less<Key>, KeyAllocatorType=std::allocator<T>

	STL_unordered_set<Key, std::hash<Key>, std::equal_to<Key>, std::allocator<Key>> :   FixedSize=0, KeyType=Key, KeyHashType=std::hash<Key>, KeyEqualType=std::equal_to<Key>, KeyAllocatorType=std::allocator<T>
	STL_unordered_multiset<Key, std::hash<Key>, std::equal_to<Key>, std::allocator<Key>> :   FixedSize=0, KeyType=Key, KeyHashType=std::hash<Key>, KeyEqualType=std::equal_to<Key>, KeyAllocatorType=std::allocator<T>
		
	STL_map<Key, T, std::less<Key>, std::allocator<std::pair<const Key, T>>>:   FixedSize=0, KeyType=Key, ItemType=T, KeyCompareType= std::less<Key>, KeyAllocatorType=std::allocator<std::pair<const Key, T>>
	STL_multimap<Key, T, std::less<Key>, std::allocator<std::pair<const Key, T>>>:   FixedSize=0, KeyType=Key, ItemType=T, KeyCompareType= std::less<Key>, KeyAllocatorType=std::allocator<std::pair<const Key, T>>

	STL_unordered_map<Key, T, std::hash<Key>, std::equal_to<Key>, std::allocator<std::pair<const Key, T>>>:   FixedSize=0, KeyType=Key, ItemType=T, KeyHashType= std::hash<Key>, KeyCompareType= std::equal_to<Key>, KeyAllocatorType=std::allocator<std::pair<const Key, T>>
	STL_unordered_multimap<Key, T, std::hash<Key>, std::equal_to<Key>, std::allocator<std::pair<const Key, T>>>:   FixedSize=0, KeyType=Key, ItemType=T, KeyHashType= std::hash<Key>, KeyCompareType= std::equal_to<Key>, KeyAllocatorType=std::allocator<std::pair<const Key, T>>
		
	STL_stack<T, std::deque<T>>:   FixedSize=0, ItemType=T, ItemContainerType=std::deque<T>
	STL_queue<T, std::deque<T>>:   FixedSize=0, ItemType=T, ItemContainerType=std::deque<T>
	STL_priority_queue<T, std::vector<T>, std::less<typename Container::value_type>>:   FixedSize=0, ItemType=T, ItemContainerType=std::vector<T>, ItemCompareType=std::less<typename Container::value_type>

	ObservableCollection<T>: FixedSize=0, ItemType=T
	*/

	/// <summary>
	/// ��������
	/// </summary>
	class RUNTIME_API ArrayType final: public Type
	{
	protected:
		friend class TypeFactory;
		static const ArrayType* ArrayType::Create(_type keyType, _type keyHashType, _type keyEqualType, _type keyCompareType, _type keyAllocatorType, _type itemType, _type itemAllocatorType, _type itemContainerType, _type itemCompareType, ContainerTypes arrayType, UInt8 dimension = 0, size_t fixedSize1 = 0, size_t fixedSize2 = 0, size_t fixedSize3 = 0, size_t fixedSize4 = 0, size_t fixedSize5 = 0);
	public:
		virtual ~ArrayType();

		/// <summary>
		/// ��ȡ����
		/// </summary>
		/// <returns></returns>
		virtual const wchar_t* GetName() const;

		/// <summary>
		/// ��ȡ��������
		/// </summary>
		/// <returns></returns>
		ContainerTypes GetContainerTypes() const;

		/// <summary>
		/// ��ȡ�Ƿ�̶���С
		/// </summary>
		/// <returns></returns>
		bool GetIsFixed() const;

		/// <summary>
		/// ��ȡָ��ά���Ĵ�С
		/// </summary>
		/// <returns></returns>
		size_t GetFixedSize(UInt8 dimension) const;

		/// <summary>
		/// ��ȡά��
		/// </summary>
		/// <returns></returns>
		UInt8 GetDimension() const;

		/// <summary>
		/// ��ȡ��ֵ����
		/// </summary>
		/// <returns></returns>
		_type GetKeyType() const;

		/// <summary>
		/// ��ȡ��ֵ��ϣ����
		/// </summary>
		/// <returns></returns>
		_type GetKeyHashType() const;

		/// <summary>
		/// ��ȡ��ֵ�������
		/// </summary>
		/// <returns></returns>
		_type GetKeyEqualType() const;

		/// <summary>
		/// ��ȡ��ֵ�Ƚ�������
		/// </summary>
		/// <returns></returns>
		_type GetKeyCompareType() const;

		/// <summary>
		/// ��ȡ��ֵ����������
		/// </summary>
		/// <returns></returns>
		_type GetKeyAllocatorType() const;

		/// <summary>
		/// ��ȡֵ����
		/// </summary>
		/// <returns></returns>
		_type GetItemType() const;

		/// <summary>
		/// ��ȡֵ����������
		/// </summary>
		/// <returns></returns>
		_type GetItemAllocatorType() const;

		/// <summary>
		/// ��ȡֵ��������
		/// </summary>
		/// <returns></returns>
		_type GetItemContainerType() const;

		/// <summary>
		/// ��ȡֵ�Ƚ�������
		/// </summary>
		/// <returns></returns>
		_type GetItemCompareType() const;

		/// <summary>
		/// �Ƿ�̶���С
		/// </summary>
		__declspec(property(get = GetIsFixed)) bool IsFixed;

		/// <summary>
		/// ά����С
		/// </summary>
		__declspec(property(get = GetFixedSize)) size_t FixedSize[];

		/// <summary>
		/// ά��
		/// </summary>
		__declspec(property(get = GetDimension)) UInt8 Dimension;

		/// <summary>
		/// ��ֵ����
		/// </summary>
		/// <returns></returns>
		__declspec(property(get = GetKeyType)) _type KeyType;

		/// <summary>
		/// ��ֵ��ϣ����
		/// </summary>
		__declspec(property(get = GetKeyHashType)) _type KeyHashType;

		/// <summary>
		/// ��ֵ�������
		/// </summary>
		__declspec(property(get = GetKeyEqualType)) _type KeyEqualType;

		/// <summary>
		/// ��ֵ�Ƚ�������
		/// </summary>
		__declspec(property(get = GetKeyCompareType)) _type KeyCompareType;

		/// <summary>
		/// ��ֵ����������
		/// </summary>
		__declspec(property(get = GetKeyAllocatorType)) _type KeyAllocatorType;

		/// <summary>
		/// ֵ����
		/// </summary>
		__declspec(property(get = GetItemType)) _type ItemType;

		/// <summary>
		/// ֵ��������
		/// </summary>
		__declspec(property(get = GetItemContainerTypes)) ContainerTypes ItemContainerType;

		/// <summary>
		/// ֵ�Ƚ�������
		/// </summary>
		__declspec(property(get = GetItemCompareType)) _type ItemCompareType;
	private:
		friend class Type;
		friend class ArrayType_impl;

		ArrayType_impl* impl;
		ArrayType(_type keyType, _type keyHashType, _type keyEqualType, _type keyCompareType, _type keyAllocatorType, _type itemType, _type itemAllocatorType, _type itemContainerType, _type itemCompareType, ContainerTypes arrayType, UInt8 dimension, size_t fixedSize1, size_t fixedSize2, size_t fixedSize3, size_t fixedSize4, size_t fixedSize5);
	};
}