#include "HeadRing.h"


THeadRing :: THeadRing () : TDatList() {
	pHead = NULL;
}

THeadRing :: ~THeadRing () {
	TDatList :: DelList();
	DelLink (pHead);
	pHead = NULL;
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