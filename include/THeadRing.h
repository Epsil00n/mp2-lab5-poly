#ifndef __THEADRING__
#define __THEADRING__
#include "TDatList.h"

class THeadRing : public TDatList{
  protected:
    PTDatLink pHead;     // ���������, pFirst - ����� �� pHead
  public:
    THeadRing ();
   ~THeadRing ();
   // ������� �������
    virtual void InsFirst( PTDatValue pVal=NULL ); // ����� ���������
    // �������� �������
    virtual void DelFirst( void );                 // ������� ������ �����
};

#endif // __THEADRING__
