#include "THeadRing.h"

THeadRing::THeadRing():TDatList()
{
	InsLast();
	ListLen = 0;
	pHead = pFirst;
	pStop = pHead;
	Reset();
	pFirst->SetNextLink(pFirst);
}

THeadRing ::~THeadRing()
{
	TDatList::DelList();
	DellLink(pHead);
	pHead = nullptr;
}

void THeadRing::InsFirst(PTDatValue pVal) // �������� ����� ���������
{
	TDatList::InsFirst(pVal);
	pHead->SetNextLink(pFirst);
}

void THeadRing::DelFirst() // ������� ������ �����
{
	TDatList::DelFirst();
	pHead->SetNextLink(pFirst);
}

