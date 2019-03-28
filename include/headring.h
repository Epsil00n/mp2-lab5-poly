#ifndef _HEADRING_H_
#define _HEADRING_H_
#include "datlist.h"

class THeadRing : public TDatList {
protected:
    PTDatLink pHead;     // ���������, pFirst - ����� �� pHead
public:
    THeadRing();
    ~THeadRing();
    // ������� �������
    virtual void InsFirst(PTDatValue pVal = nullptr); // ����� ���������
    // �������� �������
    virtual void DelFirst();                 // ������� ������ �����
};

#endif  // _HEADRING_H_
