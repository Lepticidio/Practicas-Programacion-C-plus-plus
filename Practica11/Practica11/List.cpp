#include "List.h"
#include <string>
TListNode::TListNode(const char* _sValue)
	:m_sValue(_sValue)
	, m_pNext(nullptr)
{

}
TListNode::TListNode(const TListNode& _rOther)
	: m_sValue(_rOther.m_sValue)
{
	//if (_rOther.m_sValue)
	//{
	//	m_sValue = new char[strlen(_rOther.m_sValue) + 1];
	//	strcpy(m_sValue, _rOther.m_sValue);
	//}
	//else
	//{
	//	m_pFirst = nullptr;
	//}
}
TList::TList()
{

}
TList::TList(const TList& _rOther)
{
	if (_rOther.m_pFirst)
	{
		TListNode firstNode(_rOther.m_pFirst->m_sValue);
		m_pFirst = &firstNode;
		m_pCurrent = &firstNode;
		printf("Copied value: %s\n", m_pFirst->m_sValue);
		TListNode* pTemp = _rOther.m_pFirst->m_pNext;
		unsigned int uIndex(0);
		while (pTemp != nullptr)
		{
			TListNode oNewNode(pTemp->m_sValue);
			m_pCurrent->m_pNext = &oNewNode;
			m_pCurrent = m_pCurrent->m_pNext;
			pTemp = pTemp->m_pNext;
			printf("Copied value: %s\n", m_pCurrent->m_sValue);
		}
	}
	else
	{
		m_pFirst = nullptr;
	}
}
TList::~TList()
{

}

int TList::Size()
{
	return m_uSize;
}
int TList::Push(const char* _sValue)
{

	TListNode* pNewListNode = new TListNode(_sValue);
	pNewListNode->m_pNext = m_pFirst;
	m_pFirst = pNewListNode;
	return ++m_uSize;


}
const char* TList::First()
{
	m_pCurrent = m_pFirst;
	return m_pFirst->m_sValue;
}
const char* TList::Next()
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
	return m_pCurrent->m_sValue;
}
const char* TList::Pop()
{
	const char* pRetValue(nullptr);
	if (m_pFirst)
	{
		//Store the return value
		pRetValue = m_pFirst->m_sValue;
		//Fix iterator
		m_pCurrent = nullptr;
		//Delete the first and point m_pFirst to next
		TListNode* pFirst(m_pFirst);
		m_pFirst = m_pFirst->m_pNext;
		delete pFirst;
		//Decrement size
		m_uSize--;
	}
	return pRetValue;
}
void TList::Reset()
{
	m_pCurrent = nullptr;
	while (Pop() != nullptr);
}