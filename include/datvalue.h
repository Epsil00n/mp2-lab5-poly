#ifndef _DATVALUE_H_
#define _DATVALUE_H_

class TDatValue {
public:
    virtual TDatValue *GetCopy() = 0; // �������� �����
    ~TDatValue() {}
};
typedef TDatValue *PTDatValue;

#endif  // _DATVALUE_H_
