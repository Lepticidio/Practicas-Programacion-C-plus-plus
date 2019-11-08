#include "List.h"
#include <assert.h>

TListNode::TListNode(IListElement* _pValue)
	: m_pValue(_pValue)
	, m_pNext(nullptr)
{
}

TList::TList()
	: m_pFirst(nullptr)
	, m_uSize(0)
	, m_pCurrent(nullptr)
{
}

TList::~TList()
{
}

int TList::Size()
{
	return m_uSize;
}

int TList::Push(IListElement* _sValue)
{
	TListNode* pNewListNode = new TListNode(_sValue);
	pNewListNode->m_pNext = m_pFirst;
	m_pFirst = pNewListNode;
	return ++m_uSize;
}

IListElement* TList::First()
{
	m_pCurrent = m_pFirst;
	return m_pFirst->m_pValue;
}

IListElement* TList::Next()
{
	m_pCurrent = m_pCurrent ? m_pCurrent->m_pNext : nullptr;
	return m_pCurrent ? m_pCurrent->m_pValue : nullptr;
}

IListElement* TList::Pop()
{
	IListElement* pRetValue(nullptr);
	if (m_pFirst)
	{
		// Store the return value
		pRetValue = m_pFirst->m_pValue;
		// FIX iterator
		m_pCurrent = nullptr;
		// Delete the first and point m_pFirst to the next
		TListNode* pFirst(m_pFirst);
		m_pFirst = m_pFirst->m_pNext;
		delete pFirst;
		// Decrement size
		m_uSize--;
	}
	return pRetValue;
}

void TList::Reset()
{
	m_pCurrent = nullptr;
	while (Pop() != nullptr);
}