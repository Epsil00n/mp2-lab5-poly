
#include "HeadRing.h"

THeadRing::THeadRing() : TDatList() 
{
    InsLast();   // ?
    pHead = pFirst;
    ListLen = 0;
    pStop = pHead;
    Reset();
    pFirst->SetNextLink(pFirst);
}

THeadRing::~THeadRing()
{
    TDatList::DelList();
    DelLink(pHead);
    pHead = NULL;
}

void THeadRing::InsFirst(PTDatValue pVal) // �������� ����� ���������
{
    TDatList::InsFirst(pVal);
    if(RetCode == DataOK)
        pHead->SetNextLink(pFirst);
}

void THeadRing::DelFirst(void) // ������� ������ �����
{
    TDatList::DelFirst();
    pHead->SetNextLink(pFirst);
}