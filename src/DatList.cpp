#include "DatList.h"

	PTDatLink TDatList :: GetLink ( PTDatValue pVal, PTDatLink pLink)  
{
	return pLink->GetNextDatLink(); //??????????????????????????
}

    void TDatList :: DelLink ( PTDatLink pLink )   // �������� �����
	{
		Reset(); //������������� �� ������ ������
		while (pCurrLink != pLink && !IsListEnded())
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
    PTDatValue TDatList :: GetDatValue (TLinkPos mode = CURRENT) const  // ��������
	{
		switch (mode) {
		case CURRENT: 
			return pCurrLink -> GetDatValue();
		case FIRST:
			return pFirst -> GetDatValue();
		case LAST:
			return pLast -> GetDatValue();
		default: 
			throw -1;
		}
	}
    // ���������
    int TDatList :: SetCurrentPos ( int pos )         // ���������� ������� �����
	{
		if ((pos<0)||(pos>=GetListLength()))
			throw -1;
		Reset();
		PTDatLink link = pFirst;
		for (int i=0; i<pos-1; i++)
			link = link -> GetNextDatLink();
		pPrevLink = link;
		pCurrLink = link -> GetNextDatLink();
		CurrPos = pos;
		return 0;
	}
    int TDatList :: GetCurrentPos ( void ) const       // �������� ����� ���. �����
	{
		return CurrPos;
	}
    int TDatList :: Reset ( void ) { // ���������� �� ������ ������
		CurrPos = 0;
		pCurrLink = pFirst;
		pPrevLink = NULL;
		return 0;
	}
	int TDatList :: IsListEnded ( void ) const { // ������ �������� ?
		return (pCurrLink == pLast);
	}
    int TDatList :: GoNext ( void ) {                   // ����� ������ �������� �����
                // (=1 ����� ���������� GoNext ��� ���������� ����� ������)
		if (IsListEnded()) 
			return 1;
		else {
			pPrevLink = pCurrLink;
			pCurrLink = pCurrLink -> GetNextDatLink();
			CurrPos++;
			return 0;
		}
	}
    // ������� �������
    void TDatList :: InsFirst  ( PTDatValue pVal=NULL ) { // ����� ������
		PTDatLink link = new TDatLink(pVal, pFirst);
		pFirst = link;



		CurrPos++;
		
	}
    void TDatList :: InsLast   ( PTDatValue pVal=NULL ) { // �������� ��������� 
		PTDatLink link = new TDatLink(pVal, pLast);
		pLast = link;



		CurrPos++;
	}
    void TDatList :: InsCurrent( PTDatValue pVal=NULL ) { // ����� ������� 
		PTDatLink link = new TDatLink(pVal, pCurrLink);
		pCurrLink = link;



		CurrPos++;
	}
    // �������� �������
    void TDatList :: DelFirst  ( void ) {    // ������� ������ ����� 
		if (pFirst == NULL) throw -1;

		PTDatLink link = pFirst;
		pFirst = pFirst -> GetNextDatLink();

		
	}
    void TDatList :: DelCurrent( void ) {    // ������� ������� ����� 
		PTDatLink link = pCurrLink;
		pCurrLink = pCurrLink -> GetNextDatLink();
		DelLink (pCurrLink);
	}
    void TDatList :: DelList   ( void ) {    // ������� ���� ������
		Reset();
		for (int i=0; i<GetListLength(); i++) {
			DelCurrent();
		}

	}