#ifndef __THEADRING_H__
#define  __THEADRING_H__

#include <iostream>
#include "DatList.h"

class THeadRing : public TDatList
{
  protected:
    PTDatLink pHead;     // ���������, pFirst - ����� �� pHead
  public:
    THeadRing ();
   ~THeadRing ();
   // ������� �������
    virtual void InsFirst( PTDatValue pVal = nullptr ); // ����� ���������
    // �������� �������
    virtual void DelFirst( void );                 // ������� ������ �����
};

#endif //__THEADRING_H__