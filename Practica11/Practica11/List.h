#pragma once

class TListNode
{
public:
	TListNode(const char* _sValue);
	TListNode(const TListNode& _rOther);
	const char* m_sValue;
	TListNode* m_pNext;
	
};
class TList
{
public:
	TList();
	TList(const TList& _rOther);
	~TList();

	int Size();
	int Push(const char* _sValue);
	const char* First();
	const char* Next();
	const char* Pop();
	void Reset();
	static void  GetReverseList(TList& lstSrc, TList &  tOut_);

private:
	TListNode* m_pFirst = nullptr;
	TListNode* m_pCurrent = nullptr;
	unsigned int m_uSize = 0;
};

