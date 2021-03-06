//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Dec 20 10:21:15 2016 by ROOT version 6.04/14
// from TTree SinglePhoton/SinglePhoton
// found on file: user.hwang43.10268432._000001.hist-output.root
//////////////////////////////////////////////////////////

#ifndef SinglePhoton_h
#define SinglePhoton_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <vector>
using namespace std;

// Header file for the classes stored in the TTree if any.

class SinglePhoton {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        m_mgg;
   Double_t        m_met;
   Double_t        m_sumet;
   Double_t        ph_t1;
   Double_t        ph_t2;
   Double_t        ph_z1;
   Double_t        ph_z2;
   Double_t        ph_pt1;
   Double_t        ph_pt2;
   Double_t        ph_eta1;
   Double_t        ph_eta2;
   Double_t        ph_phi1;
   Double_t        ph_phi2;
   Int_t           ph_convType1;
   Int_t           ph_convType2;
   Bool_t          ph_isTight1;
   Bool_t          ph_isTight2;
   Double_t        ph_conv_z1;
   Double_t        ph_conv_z_err1;
   Double_t        ph_calo_z1;
   Double_t        ph_calo_z_err1;
   Double_t        ph_conv_z2;
   Double_t        ph_conv_z_err2;
   Double_t        ph_calo_z2;
   Double_t        ph_calo_z_err2;
   Double_t        PV_z;
   Double_t        wt_xs;
   Double_t        wt_kf;
   Double_t        wt_ge;
   Double_t        wt_mc;
   Double_t        wt_nEvents;
   Double_t        wt_wt;
   Double_t        intlumi;
   Int_t           HLT_2g50_loose;
   Int_t           HLT_g100_loose;
   Int_t           HLT_g10_loose;
   Int_t           HLT_g120_loose;
   Int_t           HLT_g140_loose;
   Int_t           HLT_g15_loose_L1EM7;
   Int_t           HLT_g20_loose_L1EM12;
   Int_t           HLT_g25_loose_L1EM15;
   Int_t           HLT_g35_loose_L1EM15;
   Int_t           HLT_g35_loose_g25_loose;
   Int_t           HLT_g35_medium_g25_medium;
   Int_t           HLT_g40_loose_L1EM15;
   Int_t           HLT_g45_loose_L1EM15;
   Int_t           HLT_g50_loose_L1EM15;
   Int_t           HLT_g60_loose;
   Int_t           HLT_g70_loose;
   Int_t           HLT_g80_loose;

   // List of branches
   TBranch        *b_m_mgg;   //!
   TBranch        *b_m_met;   //!
   TBranch        *b_m_sumet;   //!
   TBranch        *b_ph_t1;   //!
   TBranch        *b_ph_t2;   //!
   TBranch        *b_ph_z1;   //!
   TBranch        *b_ph_z2;   //!
   TBranch        *b_ph_pt1;   //!
   TBranch        *b_ph_pt2;   //!
   TBranch        *b_ph_eta1;   //!
   TBranch        *b_ph_eta2;   //!
   TBranch        *b_ph_phi1;   //!
   TBranch        *b_ph_phi2;   //!
   TBranch        *b_ph_convType1;   //!
   TBranch        *b_ph_convType2;   //!
   TBranch        *b_ph_isTight1;   //!
   TBranch        *b_ph_isTight2;   //!
   TBranch        *b_ph_conv_z1;   //!
   TBranch        *b_ph_conv_z_err1;   //!
   TBranch        *b_ph_calo_z1;   //!
   TBranch        *b_ph_calo_z_err1;   //!
   TBranch        *b_ph_conv_z2;   //!
   TBranch        *b_ph_conv_z_err2;   //!
   TBranch        *b_ph_calo_z2;   //!
   TBranch        *b_ph_calo_z_err2;   //!
   TBranch        *b_PV_z;   //!
   TBranch        *b_wt_xs;   //!
   TBranch        *b_wt_kf;   //!
   TBranch        *b_wt_ge;   //!
   TBranch        *b_wt_mc;   //!
   TBranch        *b_wt_nEvents;   //!
   TBranch        *b_wt_wt;   //!
   TBranch        *b_intlumi;   //!
   TBranch        *b_HLT_2g50_loose;   //!
   TBranch        *b_HLT_g100_loose;   //!
   TBranch        *b_HLT_g10_loose;   //!
   TBranch        *b_HLT_g120_loose;   //!
   TBranch        *b_HLT_g140_loose;   //!
   TBranch        *b_HLT_g15_loose_L1EM7;   //!
   TBranch        *b_HLT_g20_loose_L1EM12;   //!
   TBranch        *b_HLT_g25_loose_L1EM15;   //!
   TBranch        *b_HLT_g35_loose_L1EM15;   //!
   TBranch        *b_HLT_g35_loose_g25_loose;   //!
   TBranch        *b_HLT_g35_medium_g25_medium;   //!
   TBranch        *b_HLT_g40_loose_L1EM15;   //!
   TBranch        *b_HLT_g45_loose_L1EM15;   //!
   TBranch        *b_HLT_g50_loose_L1EM15;   //!
   TBranch        *b_HLT_g60_loose;   //!
   TBranch        *b_HLT_g70_loose;   //!
   TBranch        *b_HLT_g80_loose;   //!

   SinglePhoton(TTree *tree=0);
   virtual ~SinglePhoton();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef SinglePhoton_cxx
SinglePhoton::SinglePhoton(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("user.hwang43.10268432._000001.hist-output.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("user.hwang43.10268432._000001.hist-output.root");
      }
      f->GetObject("SinglePhoton",tree);

   }
   Init(tree);
}

SinglePhoton::~SinglePhoton()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t SinglePhoton::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t SinglePhoton::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void SinglePhoton::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("m_mgg", &m_mgg, &b_m_mgg);
   fChain->SetBranchAddress("m_met", &m_met, &b_m_met);
   fChain->SetBranchAddress("m_sumet", &m_sumet, &b_m_sumet);
   fChain->SetBranchAddress("ph_t1", &ph_t1, &b_ph_t1);
   fChain->SetBranchAddress("ph_t2", &ph_t2, &b_ph_t2);
   fChain->SetBranchAddress("ph_z1", &ph_z1, &b_ph_z1);
   fChain->SetBranchAddress("ph_z2", &ph_z2, &b_ph_z2);
   fChain->SetBranchAddress("ph_pt1", &ph_pt1, &b_ph_pt1);
   fChain->SetBranchAddress("ph_pt2", &ph_pt2, &b_ph_pt2);
   fChain->SetBranchAddress("ph_eta1", &ph_eta1, &b_ph_eta1);
   fChain->SetBranchAddress("ph_eta2", &ph_eta2, &b_ph_eta2);
   fChain->SetBranchAddress("ph_phi1", &ph_phi1, &b_ph_phi1);
   fChain->SetBranchAddress("ph_phi2", &ph_phi2, &b_ph_phi2);
   fChain->SetBranchAddress("ph_convType1", &ph_convType1, &b_ph_convType1);
   fChain->SetBranchAddress("ph_convType2", &ph_convType2, &b_ph_convType2);
   fChain->SetBranchAddress("ph_isTight1", &ph_isTight1, &b_ph_isTight1);
   fChain->SetBranchAddress("ph_isTight2", &ph_isTight2, &b_ph_isTight2);
   fChain->SetBranchAddress("ph_conv_z1", &ph_conv_z1, &b_ph_conv_z1);
   fChain->SetBranchAddress("ph_conv_z_err1", &ph_conv_z_err1, &b_ph_conv_z_err1);
   fChain->SetBranchAddress("ph_calo_z1", &ph_calo_z1, &b_ph_calo_z1);
   fChain->SetBranchAddress("ph_calo_z_err1", &ph_calo_z_err1, &b_ph_calo_z_err1);
   fChain->SetBranchAddress("ph_conv_z2", &ph_conv_z2, &b_ph_conv_z2);
   fChain->SetBranchAddress("ph_conv_z_err2", &ph_conv_z_err2, &b_ph_conv_z_err2);
   fChain->SetBranchAddress("ph_calo_z2", &ph_calo_z2, &b_ph_calo_z2);
   fChain->SetBranchAddress("ph_calo_z_err2", &ph_calo_z_err2, &b_ph_calo_z_err2);
   fChain->SetBranchAddress("PV_z", &PV_z, &b_PV_z);
   fChain->SetBranchAddress("wt_xs", &wt_xs, &b_wt_xs);
   fChain->SetBranchAddress("wt_kf", &wt_kf, &b_wt_kf);
   fChain->SetBranchAddress("wt_ge", &wt_ge, &b_wt_ge);
   fChain->SetBranchAddress("wt_mc", &wt_mc, &b_wt_mc);
   fChain->SetBranchAddress("wt_nEvents", &wt_nEvents, &b_wt_nEvents);
   fChain->SetBranchAddress("wt_wt", &wt_wt, &b_wt_wt);
   fChain->SetBranchAddress("intlumi", &intlumi, &b_intlumi);
   fChain->SetBranchAddress("HLT_2g50_loose", &HLT_2g50_loose, &b_HLT_2g50_loose);
   fChain->SetBranchAddress("HLT_g100_loose", &HLT_g100_loose, &b_HLT_g100_loose);
   fChain->SetBranchAddress("HLT_g10_loose", &HLT_g10_loose, &b_HLT_g10_loose);
   fChain->SetBranchAddress("HLT_g120_loose", &HLT_g120_loose, &b_HLT_g120_loose);
   fChain->SetBranchAddress("HLT_g140_loose", &HLT_g140_loose, &b_HLT_g140_loose);
   fChain->SetBranchAddress("HLT_g15_loose_L1EM7", &HLT_g15_loose_L1EM7, &b_HLT_g15_loose_L1EM7);
   fChain->SetBranchAddress("HLT_g20_loose_L1EM12", &HLT_g20_loose_L1EM12, &b_HLT_g20_loose_L1EM12);
   fChain->SetBranchAddress("HLT_g25_loose_L1EM15", &HLT_g25_loose_L1EM15, &b_HLT_g25_loose_L1EM15);
   fChain->SetBranchAddress("HLT_g35_loose_L1EM15", &HLT_g35_loose_L1EM15, &b_HLT_g35_loose_L1EM15);
   fChain->SetBranchAddress("HLT_g35_loose_g25_loose", &HLT_g35_loose_g25_loose, &b_HLT_g35_loose_g25_loose);
   fChain->SetBranchAddress("HLT_g35_medium_g25_medium", &HLT_g35_medium_g25_medium, &b_HLT_g35_medium_g25_medium);
   fChain->SetBranchAddress("HLT_g40_loose_L1EM15", &HLT_g40_loose_L1EM15, &b_HLT_g40_loose_L1EM15);
   fChain->SetBranchAddress("HLT_g45_loose_L1EM15", &HLT_g45_loose_L1EM15, &b_HLT_g45_loose_L1EM15);
   fChain->SetBranchAddress("HLT_g50_loose_L1EM15", &HLT_g50_loose_L1EM15, &b_HLT_g50_loose_L1EM15);
   fChain->SetBranchAddress("HLT_g60_loose", &HLT_g60_loose, &b_HLT_g60_loose);
   fChain->SetBranchAddress("HLT_g70_loose", &HLT_g70_loose, &b_HLT_g70_loose);
   fChain->SetBranchAddress("HLT_g80_loose", &HLT_g80_loose, &b_HLT_g80_loose);
   Notify();
}

Bool_t SinglePhoton::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void SinglePhoton::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t SinglePhoton::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef SinglePhoton_cxx
