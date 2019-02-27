#include "DatList.h"

	PTDatLink TDatList :: GetLink (PTDatValue pVal, PTDatLink pLink)  
{
	PTDatLink link = new TDatLink(pVal, pLink);
	return link;
}

    void TDatList :: DelLink (PTDatLink pLink)   // �������� �����
	{
		Reset(); //������������� �� ������ ������
		while ((pCurrLink != pLink)&&(!IsListEnded()))
			GoNext();
		if (IsListEnded()) 
			throw -1;
		else {
			DelCurrent();
		}
	}
	TDatList :: TDatList()
	{
		pFirst = NULL;    // ������ �����
		pLast = NULL;     // ��������� �����
		pCurrLink = NULL; // ������� �����
		pPrevLink = NULL; // ����� ����� �������
		pStop = NULL;     // �������� ���������, ����������� ����� ������ 
		CurrPos = -1;         // ����� �������� ����� (��������� �� 0)
		ListLen = 0;         // ���������� ������� � ������
	}

    // ������
    PTDatValue TDatList :: GetDatValue (TLinkPos mode) const  // ��������
	{
		switch (mode) {
		case CURRENT: 
			return pCurrLink -> GetDatValue();
		case BEGIN:
			return pFirst -> GetDatValue();
		case END:
			return pLast -> GetDatValue();
		default: 
			throw -1;
		}
	}
    // ���������
    int TDatList :: SetCurrentPos (int pos)         // ���������� ������� �����
	{
		if ((pos<0)||(pos>=GetListLength()))
			throw -1;
		Reset();
		pCurrLink = pFirst;
		for (int i=0; i<pos-1; i++)
			pCurrLink = pCurrLink -> GetNextDatLink();
		pPrevLink = pCurrLink;
		pCurrLink = pCurrLink -> GetNextDatLink();
		CurrPos = pos;
		return 0;
	}
    int TDatList :: GetCurrentPos (void) const       // �������� ����� ���. �����
	{
		return CurrPos;
	}
    int TDatList :: Reset (void) { // ���������� �� ������ ������
		CurrPos = 0;
		pCurrLink = pFirst; 
		pPrevLink = NULL;
		return 0;
	}
	int TDatList :: IsListEnded (void) const { // ������ �������� ?
		return (pCurrLink == pStop);
	}
    int TDatList :: GoNext (void) {                   // ����� ������ �������� �����
                // (=1 ����� ���������� GoNext ��� ���������� ����� ������)
		if (pCurrLink == pStop)  //��� � ����� ������
			return 1;
		else if (pCurrLink == pLast) { //�� ��������� ��������
			pPrevLink = NULL;
			pCurrLink = pCurrLink -> GetNextDatLink(); //NULL
			CurrPos = 0;
		}
		else {
			pPrevLink = pCurrLink;
			pCurrLink = pCurrLink -> GetNextDatLink();
			CurrPos++;
			return 0;
		}
	}
    // ������� �������
    void TDatList :: InsFirst (PTDatValue pVal) { // ����� ������
		PTDatLink link = new TDatLink(pVal, pFirst);
		if ((pFirst == pCurrLink)&&(pFirst != NULL)) {
			pFirst = link;
			pPrevLink = link;
			pFirst -> SetNextLink(pCurrLink);
		}
		else {
			PTDatLink p = pFirst;
			pFirst = link;
			if (pFirst != NULL) pFirst -> SetNextLink (p);
		}
		if (pLast == NULL) {
			pLast = pFirst;
			pLast->SetNextLink(pStop);
		}
		if (pCurrLink == NULL) {
			pCurrLink = pFirst;
		}
		ListLen++;
		CurrPos++;
	}
    void TDatList :: InsLast (PTDatValue pVal) { // �������� ��������� 
		PTDatLink link = new TDatLink(pVal, pStop);
		if (pLast != NULL) pLast -> SetNextLink (link);
		pLast = link;
		pLast->SetNextLink(pStop);
		if (pFirst == NULL) pFirst = pLast;
		if (pCurrLink == NULL) {
			pCurrLink = pLast;
			CurrPos++;
		}
		ListLen++;
	}
    void TDatList :: InsCurrent (PTDatValue pVal) { // ����� ������� 
		if ((pCurrLink == NULL)||(pPrevLink == NULL))
			InsFirst (pVal);
		else  {
			PTDatLink link = new TDatLink(pVal, pCurrLink);
			pPrevLink -> SetNextLink (link);
			pPrevLink = link;
			//pPrevLink -> SetNextLink (pCurrLink);
			ListLen++;
			CurrPos++;
		}
		
	}
    // �������� �������
    void TDatList :: DelFirst (void) {    // ������� ������ ����� 
		if (pFirst == NULL) throw -1;
		if (pFirst == pCurrLink) pCurrLink = NULL;
		if (pFirst == pLast) pLast = NULL;
		if (pFirst == pPrevLink) pPrevLink = NULL;
		PTDatLink link = pFirst;
		pFirst = pFirst -> GetNextDatLink();
		delete link;
		ListLen--;
		CurrPos--;
	}
    void TDatList :: DelCurrent (void) {    // ������� ������� ����� 
		if (pCurrLink == NULL) throw -1;
		if (pCurrLink == pFirst) DelFirst();
		else {
			if (pCurrLink == pLast) {
				pLast = pPrevLink;
				pLast -> SetNextLink(pStop);
			}
			PTDatLink link = pCurrLink;
			pCurrLink = pCurrLink -> GetNextDatLink();
			pPrevLink -> SetNextLink(pCurrLink);
			delete link;
			if (pCurrLink == NULL) pPrevLink = NULL;
			ListLen--;
			CurrPos--;
		}
	}
    void TDatList :: DelList (void) {    // ������� ���� ������
		Reset();
		for (int i=0; i<GetListLength(); i++) {
			DelFirst();
		}
	}