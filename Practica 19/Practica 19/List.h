#pragma once
#include <iostream>



template <typename T>
class TListNode
{
public:
	TListNode(T _Value)
		:m_Value(_Value)
		, m_pNext(nullptr)
	{
		printf("node constructor with value ");
		Print();

	}
	T m_Value;
	TListNode* m_pNext;
	void Print()
	{
		std::cout << m_Value << std::endl;
	}
	
};
template <typename T>
class TList
{
public:
	TList()
	{
		printf("DEFAULT CONSTRUCTOR\n");

	}
	TList(const TList& _rOther)
	{
		printf("COPY CONSTRUCTOR\n");
		if (_rOther.m_pFirst)
		{
			TListNode<T>* firstNode = new TListNode<T>(_rOther.m_pFirst->m_Value);
			m_pFirst = firstNode;
			m_pCurrent = firstNode;
			printf("Copied value: ");
			m_pFirst->Print();
			TListNode<T>* pTemp = _rOther.m_pFirst->m_pNext;
			unsigned int uIndex(0);
			m_uSize++;
			while (pTemp != nullptr)
			{
				TListNode<T>* oNewNode = new TListNode<T>(pTemp->m_Value);
				m_pCurrent->m_pNext = oNewNode;
				m_pCurrent = m_pCurrent->m_pNext;
				pTemp = pTemp->m_pNext;
				m_uSize++;
				printf("Copied value: ");
				m_pCurrent->Print();
			}
		}
		else
		{
			m_pFirst = nullptr;
		}
	}
	~TList()
	{

	}

	int Size()
	{
		return m_uSize;
	}
	int Push(const T _sValue)
	{

		TListNode<T>* pNewListNode = new TListNode<T>(_sValue);
		pNewListNode->m_pNext = m_pFirst;
		m_pFirst = pNewListNode;
		return ++m_uSize;


	}
	const T First()
	{
		m_pCurrent = m_pFirst;
		return m_pFirst->m_Value;
	}
	T* Next()
	{
		if (m_pCurrent == nullptr)
		{
			return nullptr;
		}
		m_pCurrent = m_pCurrent->m_pNext;
		if (m_pCurrent == nullptr)
		{
			return nullptr;
		}
		return &(m_pCurrent->m_Value);
	}
	T Pop()
	{
		T pRetValue(nullptr);
		if (m_pFirst)
		{
			//Store the return value
			pRetValue = m_pFirst->m_Value;
			//Fix iterator
			m_pCurrent = nullptr;
			//Delete the first and point m_pFirst to next
			TListNode<T>* pFirst(m_pFirst);
			m_pFirst = m_pFirst->m_pNext;
			delete pFirst;
			//Decrement size
			m_uSize--;
		}
		return pRetValue;
	}
	void Reset()
	{
		m_pCurrent = nullptr;
		while (Pop() != nullptr);
	}
	static void  GetReverseList(TList& _tSrc, TList& tOut_)
	{
		T SrcNode = _tSrc.First();
		bool bFinished = false;
		while (!bFinished)
		{
			tOut_.Push(SrcNode);
			T* pNext = _tSrc.Next();
			if (pNext != nullptr)
			{
				SrcNode = *pNext;

			}
			else
			{
				bFinished = true;
			}

		}
	}

private:
	TListNode<T>* m_pFirst = nullptr;
	TListNode<T>* m_pCurrent = nullptr;
	unsigned int m_uSize = 0;
};

