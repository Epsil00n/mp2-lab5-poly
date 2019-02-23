#pragma once
#include<iostream>
#include "DatValue.h"
class TMonom;
typedef TMonom* PTMonom;
class TMonom : public TDatValue
{
  protected:
    float Coeff; // коэффициент монома
    int Index; // индекс (свертка степеней)
  public:
    TMonom(float cval = 1, int ival = 0)
    {
        Coeff = cval;
        Index = ival;
    };
    virtual TDatValue *GetCopy(); // изготовить копию
    void SetCoeff(int cval) { Coeff = cval; }
    int GetCoeff(void) { return Coeff; }
    void SetIndex(int ival) { Index = ival; }
    int GetIndex(void) { return Index; }
    TMonom &operator=(const TMonom &tm)
    {
        Coeff = tm.Coeff;
        Index = tm.Index;
        return *this;
    }
    int operator==(const TMonom &tm)
    {
        return (Coeff == tm.Coeff) && (Index == tm.Index);
    }
    int operator<(const TMonom &tm)
    {
        return Index < tm.Index;
    }
    friend std::ostream &operator<<(std::ostream &os, TMonom &q);
    friend class TPolinom;
};