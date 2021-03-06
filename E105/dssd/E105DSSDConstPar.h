 /** E105DSSDConstPar.h
 ** @author M.Al-Turany
 ** @since 30.01.2007
 ** @version 1.0
 **
 ** Parameter set for the region between Solenoid and dipole. For the runtime database.
 **/

#ifndef E105DSSDConstPAR_H
#define E105DSSDConstPAR_H 1
#include "E105DSSDMapPar.h"
class FairParamList;

class E105DSSDConstPar : public E105DSSDMapPar
{

  public:


    /** Standard constructor  **/
    E105DSSDConstPar(const char* name, const char* title, const char* context);

    /** default constructor  **/
    E105DSSDConstPar();

    /** Destructor **/
    ~E105DSSDConstPar();

    void putParams(FairParamList* list);


    /** Get parameters **/
    Bool_t getParams(FairParamList* list);


    /** Set parameters from FairField  **/
    //    void SetParameters(FairField* field);


    Double_t GetBx()        const { return fBx; }
    Double_t GetBy()        const { return fBy; }
    Double_t GetBz()        const { return fBz; }

  protected:

    /** Field values in [kG] **/
    Double_t fBx, fBy, fBz;

    ClassDef(E105DSSDConstPar,1);

};


#endif
