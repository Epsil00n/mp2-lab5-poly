#ifndef  __HEADRING_H
#define  __HEADRING_H

#include "TDatList.h"

class THeadRing:public TDatList
{ 
public:
	PTDatLink pHead; // ���������, �����  pFirst �� pHead
public:
	THeadRing();
	~THeadRing();
	// ������� �������
	virtual void InsFirst(PTDatValue pVal = nullptr); // ������� ����� ���������
	// �������� �������
	virtual void DelFirst(); // ������� ������ �����
};
#endif // ! __HEADRING_H
