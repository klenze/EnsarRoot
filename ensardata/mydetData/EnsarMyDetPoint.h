// -------------------------------------------------------------------------
// -----                  EnsarMyDetPoint header file                  -----
// -----                Created 11/09/12  by P.Cabanelas               -----
// -------------------------------------------------------------------------


/**  EnsarMyDetPoint.h
 **/


#ifndef ENSARMYDETPOINT_H
#define ENSARMYDETPOINT_H


#include "TObject.h"
#include "TVector3.h"

#include "FairMCPoint.h"


class EnsarMyDetPoint : public FairMCPoint 
{

 public:

  /** Default constructor **/
  EnsarMyDetPoint();


  /** Constructor with arguments
   *@param trackID         Index of MCTrack
   *@param volumeID        Active Volume ID
   *@param fTrackPID;      particle identification
   *@param fParentTrackID; parent track index
   *@param fUniqueID;      particle unique id (e.g. if Delta electron, fUniqueID=9)
   *@param posIn           Ccoordinates at entrance to active volume [cm]
   *@param posOut          Coordinates at exit of active volume [cm]
   *@param momIn           Momentum of track at entrance [GeV]
   *@param momOut          Momentum of track at exit [GeV]
   *@param tof             Time since event start [ns]
   *@param length          Track length since creation [cm]
   *@param eLoss           Energy deposit [GeV]
   **/
  EnsarMyDetPoint(Int_t trackID, Int_t volumeID,
              Int_t trackPID, Int_t parentTrackID, Int_t uniqueID, 
              TVector3 posIn, TVector3 posOut, TVector3 momIn, TVector3 momOut,
	      Double_t tof, Double_t length, Double_t eLoss);


  /** Copy constructor **/
  EnsarMyDetPoint(const EnsarMyDetPoint& point) { *this = point; };


  /** Destructor **/
  virtual ~EnsarMyDetPoint();


  /** Accessors **/
  Double_t GetXIn()   const { return fX; }
  Double_t GetYIn()   const { return fY; }
  Double_t GetZIn()   const { return fZ; }
  Double_t GetXOut()  const { return fX_out; }
  Double_t GetYOut()  const { return fY_out; }
  Double_t GetZOut()  const { return fZ_out; }
  Double_t GetPxOut() const { return fPx_out; }
  Double_t GetPyOut() const { return fPy_out; }
  Double_t GetPzOut() const { return fPz_out; }
  void PositionIn(TVector3& pos)  { pos.SetXYZ(fX, fY, fZ); }
  void PositionOut(TVector3& pos) { pos.SetXYZ(fX_out,fY_out,fZ_out); }
  void MomentumOut(TVector3& mom) { mom.SetXYZ(fPx_out,fPy_out,fPz_out); }


  /** Point coordinates at given z from linear extrapolation **/
  Double_t GetX(Double_t z) const;
  Double_t GetY(Double_t z) const;


  /** Check for distance between in and out **/
  Bool_t IsUsable() const;


  /** Modifiers **/
  void SetPositionOut(TVector3 pos);
  void SetMomentumOut(TVector3 mom);


  /** Output to screen **/
  virtual void Print(const Option_t* opt) const;



 protected:

  Double32_t fX_out,  fY_out,  fZ_out;
  Double32_t fPx_out, fPy_out, fPz_out;

  Int_t fTrackID;        //track index
  Int_t fVolumeID;       //volume index
  Int_t fParentTrackID;  //parent track index
  Int_t fTrackPID;       //particle identification
  Int_t fTrackUniqueID;  //particle unique id

  ClassDef(EnsarMyDetPoint,1)

};



inline void EnsarMyDetPoint::SetPositionOut(TVector3 pos) {
  fX_out = pos.X();
  fY_out = pos.Y();
  fZ_out = pos.Z();
}


inline void EnsarMyDetPoint::SetMomentumOut(TVector3 mom) {
  fPx_out = mom.Px();
  fPy_out = mom.Py();
  fPz_out = mom.Pz();
}



#endif
