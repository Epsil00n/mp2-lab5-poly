#include "HeadRing.h"


THeadRing :: THeadRing () : TDatList () {
	InsLast();
	pHead = pFirst;
	pStop = pHead;
	Reset();
	pFirst -> SetNextLink(pFirst);
	ListLen = 0;
}

THeadRing :: ~THeadRing () {
	TDatList :: DelList();
	DelLink (pHead);
	pHead = nullptr;
}
   // ������� �������
void THeadRing :: InsFirst (PTDatValue pVal) { // ����� ���������
	TDatList :: InsFirst (pVal);
	pHead -> SetNextLink (pFirst);
}
    // �������� �������
void THeadRing :: DelFirst (void) {                // ������� ������ �����
	TDatList :: DelFirst ();
	pHead -> SetNextLink (pFirst);
}

