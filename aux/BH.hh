//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jul 12 13:51:12 2017 by ROOT version 6.04/14
// from TTree BH/BH
// found on file: /global/projecta/projectdirs/atlas/santpur/example/tmp/BH/output/data-myOutput/TEST.root
//////////////////////////////////////////////////////////

#ifndef BH_h
#define BH_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <vector>
using namespace std;

// Header file for the classes stored in the TTree if any.

class BH {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           RunNumber;
   Int_t           EventNumber;
   Float_t         mcweight;
   Double_t        tru_MET;
   Float_t         tru_twoph_events;
   Float_t         tru_v1_d1_x;
   Float_t         tru_v1_d1_y;
   Float_t         tru_v1_d1_z;
   Float_t         tru_v1_d1_t;
   Float_t         tru_v1_d1_r;
   Float_t         tru_v1_d2_x;
   Float_t         tru_v1_d2_y;
   Float_t         tru_v1_d2_z;
   Float_t         tru_v1_d2_t;
   Float_t         tru_v1_d2_r;
   Float_t         tru_v2_d1_x;
   Float_t         tru_v2_d1_y;
   Float_t         tru_v2_d1_z;
   Float_t         tru_v2_d1_t;
   Float_t         tru_v2_d1_r;
   Float_t         tru_v2_d2_x;
   Float_t         tru_v2_d2_y;
   Float_t         tru_v2_d2_z;
   Float_t         tru_v2_d2_t;
   Float_t         tru_v2_d2_r;
   Float_t         tru_ph1_pt;
   Float_t         tru_ph1_eta;
   Float_t         tru_ph1_phi;
   Float_t         tru_ph1_E;
   Float_t         tru_ph2_pt;
   Float_t         tru_ph2_eta;
   Float_t         tru_ph2_phi;
   Float_t         tru_ph2_E;
   Float_t         tru_G1_pt;
   Float_t         tru_G1_eta;
   Float_t         tru_G1_phi;
   Float_t         tru_G1_E;
   Float_t         tru_G2_pt;
   Float_t         tru_G2_eta;
   Float_t         tru_G2_phi;
   Float_t         tru_G2_E;
   Float_t         tru_b1_pt;
   Float_t         tru_b1_eta;
   Float_t         tru_b1_phi;
   Float_t         tru_b1_E;
   Float_t         tru_b1_vbyc;
   Float_t         tru_b2_pt;
   Float_t         tru_b2_eta;
   Float_t         tru_b2_phi;
   Float_t         tru_b2_E;
   Float_t         tru_b2_vbyc;
   Float_t         tru_glu1_pt;
   Float_t         tru_glu1_eta;
   Float_t         tru_glu1_phi;
   Float_t         tru_glu1_E;
   Float_t         tru_glu2_pt;
   Float_t         tru_glu2_eta;
   Float_t         tru_glu2_phi;
   Float_t         tru_glu2_E;
   Float_t         tru_ph1_timing;
   Float_t         tru_ph2_timing;
   Float_t         tru_ph_all_timing;
   Float_t         tru_ph1_tof;
   Float_t         tru_ph2_tof;
   Float_t         tru_ph_tof;
   Float_t         tru_ph1_pdgid;
   Float_t         tru_ph2_pdgid;
   Float_t         tru_glu1_pdgid;
   Float_t         tru_glu2_pdgid;
   Float_t         tru_b1_pdgid;
   Float_t         tru_b2_pdgid;
   Float_t         tru_G1_pdgid;
   Float_t         tru_G2_pdgid;
   Float_t         tru_b1_timing;
   Float_t         tru_b2_timing;
   Float_t         tru_b_all_timing;
   Float_t         tru_prompt1_timing;
   Float_t         tru_prompt2_timing;
   Float_t         tru_prompt_all_timing;
   Float_t         tru_ph_pointing;
   Float_t         tru_ph1_pointing;
   Float_t         tru_ph2_pointing;
   Float_t         sp_cutflow_pt;
   Float_t         sp_cutflow_eta;
   Float_t         sp_cutflow_METl20;
   Float_t         sp_cutflow_METg75;
   Float_t         sp_cutflow_METg200;
   Float_t         sp_cutflow_SR1;
   Float_t         sp_cutflow_SR1_t1p5;
   Float_t         sp_cutflow_SR1_t2;
   Float_t         sp_cutflow_SR;
   Float_t         sp_cutflow_SR_t1p5;
   Float_t         sp_cutflow_SR_t2;
   Float_t         dp_cutflow_pt;
   Float_t         dp_cutflow_eta;
   Float_t         dp_cutflow_METl20;
   Float_t         dp_cutflow_METg75;
   Float_t         dp_cutflow_SR;
   Float_t         dp_cutflow_SR_t1p5;
   Float_t         dp_cutflow_SR_t2;
   Float_t         tru_sol_var;

   // List of branches
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_mcweight;   //!
   TBranch        *b_tru_MET;   //!
   TBranch        *b_tru_twoph_events;   //!
   TBranch        *b_tru_v1_d1_x;   //!
   TBranch        *b_tru_v1_d1_y;   //!
   TBranch        *b_tru_v1_d1_z;   //!
   TBranch        *b_tru_v1_d1_t;   //!
   TBranch        *b_tru_v1_d1_r;   //!
   TBranch        *b_tru_v1_d2_x;   //!
   TBranch        *b_tru_v1_d2_y;   //!
   TBranch        *b_tru_v1_d2_z;   //!
   TBranch        *b_tru_v1_d2_t;   //!
   TBranch        *b_tru_v1_d2_r;   //!
   TBranch        *b_tru_v2_d1_x;   //!
   TBranch        *b_tru_v2_d1_y;   //!
   TBranch        *b_tru_v2_d1_z;   //!
   TBranch        *b_tru_v2_d1_t;   //!
   TBranch        *b_tru_v2_d1_r;   //!
   TBranch        *b_tru_v2_d2_x;   //!
   TBranch        *b_tru_v2_d2_y;   //!
   TBranch        *b_tru_v2_d2_z;   //!
   TBranch        *b_tru_v2_d2_t;   //!
   TBranch        *b_tru_v2_d2_r;   //!
   TBranch        *b_tru_ph1_pt;   //!
   TBranch        *b_tru_ph1_eta;   //!
   TBranch        *b_tru_ph1_phi;   //!
   TBranch        *b_tru_ph1_E;   //!
   TBranch        *b_tru_ph2_pt;   //!
   TBranch        *b_tru_ph2_eta;   //!
   TBranch        *b_tru_ph2_phi;   //!
   TBranch        *b_tru_ph2_E;   //!
   TBranch        *b_tru_G1_pt;   //!
   TBranch        *b_tru_G1_eta;   //!
   TBranch        *b_tru_G1_phi;   //!
   TBranch        *b_tru_G1_E;   //!
   TBranch        *b_tru_G2_pt;   //!
   TBranch        *b_tru_G2_eta;   //!
   TBranch        *b_tru_G2_phi;   //!
   TBranch        *b_tru_G2_E;   //!
   TBranch        *b_tru_b1_pt;   //!
   TBranch        *b_tru_b1_eta;   //!
   TBranch        *b_tru_b1_phi;   //!
   TBranch        *b_tru_b1_E;   //!
   TBranch        *b_tru_b1_vbyc;   //!
   TBranch        *b_tru_b2_pt;   //!
   TBranch        *b_tru_b2_eta;   //!
   TBranch        *b_tru_b2_phi;   //!
   TBranch        *b_tru_b2_E;   //!
   TBranch        *b_tru_b2_vbyc;   //!
   TBranch        *b_tru_glu1_pt;   //!
   TBranch        *b_tru_glu1_eta;   //!
   TBranch        *b_tru_glu1_phi;   //!
   TBranch        *b_tru_glu1_E;   //!
   TBranch        *b_tru_glu2_pt;   //!
   TBranch        *b_tru_glu2_eta;   //!
   TBranch        *b_tru_glu2_phi;   //!
   TBranch        *b_tru_glu2_E;   //!
   TBranch        *b_tru_ph1_timing;   //!
   TBranch        *b_tru_ph2_timing;   //!
   TBranch        *b_tru_ph_all_timing;   //!
   TBranch        *b_tru_ph1_tof;   //!
   TBranch        *b_tru_ph2_tof;   //!
   TBranch        *b_tru_ph_tof;   //!
   TBranch        *b_tru_ph1_pdgid;   //!
   TBranch        *b_tru_ph2_pdgid;   //!
   TBranch        *b_tru_glu1_pdgid;   //!
   TBranch        *b_tru_glu2_pdgid;   //!
   TBranch        *b_tru_b1_pdgid;   //!
   TBranch        *b_tru_b2_pdgid;   //!
   TBranch        *b_tru_G1_pdgid;   //!
   TBranch        *b_tru_G2_pdgid;   //!
   TBranch        *b_tru_b1_timing;   //!
   TBranch        *b_tru_b2_timing;   //!
   TBranch        *b_tru_b_all_timing;   //!
   TBranch        *b_tru_prompt1_timing;   //!
   TBranch        *b_tru_prompt2_timing;   //!
   TBranch        *b_tru_prompt_all_timing;   //!
   TBranch        *b_tru_ph_pointing;   //!
   TBranch        *b_tru_ph1_pointing;   //!
   TBranch        *b_tru_ph2_pointing;   //!
   TBranch        *b_sp_cutflow_pt;   //!
   TBranch        *b_sp_cutflow_eta;   //!
   TBranch        *b_sp_cutflow_METl20;   //!
   TBranch        *b_sp_cutflow_METg75;   //!
   TBranch        *b_sp_cutflow_METg200;   //!
   TBranch        *b_sp_cutflow_SR1;   //!
   TBranch        *b_sp_cutflow_SR1_t1p5;   //!
   TBranch        *b_sp_cutflow_SR1_t2;   //!
   TBranch        *b_sp_cutflow_SR;   //!
   TBranch        *b_sp_cutflow_SR_t1p5;   //!
   TBranch        *b_sp_cutflow_SR_t2;   //!
   TBranch        *b_dp_cutflow_pt;   //!
   TBranch        *b_dp_cutflow_eta;   //!
   TBranch        *b_dp_cutflow_METl20;   //!
   TBranch        *b_dp_cutflow_METg75;   //!
   TBranch        *b_dp_cutflow_SR;   //!
   TBranch        *b_dp_cutflow_SR_t1p5;   //!
   TBranch        *b_dp_cutflow_SR_t2;   //!
   TBranch        *b_tru_sol_var;   //!

   BH(TTree *tree=0);
   virtual ~BH();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef BH_cxx
BH::BH(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/global/projecta/projectdirs/atlas/santpur/example/tmp/BH/output/data-myOutput/TEST.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/global/projecta/projectdirs/atlas/santpur/example/tmp/BH/output/data-myOutput/TEST.root");
      }
      f->GetObject("BH",tree);

   }
   Init(tree);
}

BH::~BH()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t BH::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t BH::LoadTree(Long64_t entry)
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

void BH::Init(TTree *tree)
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

   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("mcweight", &mcweight, &b_mcweight);
   fChain->SetBranchAddress("tru_MET", &tru_MET, &b_tru_MET);
   fChain->SetBranchAddress("tru_twoph_events", &tru_twoph_events, &b_tru_twoph_events);
   fChain->SetBranchAddress("tru_v1_d1_x", &tru_v1_d1_x, &b_tru_v1_d1_x);
   fChain->SetBranchAddress("tru_v1_d1_y", &tru_v1_d1_y, &b_tru_v1_d1_y);
   fChain->SetBranchAddress("tru_v1_d1_z", &tru_v1_d1_z, &b_tru_v1_d1_z);
   fChain->SetBranchAddress("tru_v1_d1_t", &tru_v1_d1_t, &b_tru_v1_d1_t);
   fChain->SetBranchAddress("tru_v1_d1_r", &tru_v1_d1_r, &b_tru_v1_d1_r);
   fChain->SetBranchAddress("tru_v1_d2_x", &tru_v1_d2_x, &b_tru_v1_d2_x);
   fChain->SetBranchAddress("tru_v1_d2_y", &tru_v1_d2_y, &b_tru_v1_d2_y);
   fChain->SetBranchAddress("tru_v1_d2_z", &tru_v1_d2_z, &b_tru_v1_d2_z);
   fChain->SetBranchAddress("tru_v1_d2_t", &tru_v1_d2_t, &b_tru_v1_d2_t);
   fChain->SetBranchAddress("tru_v1_d2_r", &tru_v1_d2_r, &b_tru_v1_d2_r);
   fChain->SetBranchAddress("tru_v2_d1_x", &tru_v2_d1_x, &b_tru_v2_d1_x);
   fChain->SetBranchAddress("tru_v2_d1_y", &tru_v2_d1_y, &b_tru_v2_d1_y);
   fChain->SetBranchAddress("tru_v2_d1_z", &tru_v2_d1_z, &b_tru_v2_d1_z);
   fChain->SetBranchAddress("tru_v2_d1_t", &tru_v2_d1_t, &b_tru_v2_d1_t);
   fChain->SetBranchAddress("tru_v2_d1_r", &tru_v2_d1_r, &b_tru_v2_d1_r);
   fChain->SetBranchAddress("tru_v2_d2_x", &tru_v2_d2_x, &b_tru_v2_d2_x);
   fChain->SetBranchAddress("tru_v2_d2_y", &tru_v2_d2_y, &b_tru_v2_d2_y);
   fChain->SetBranchAddress("tru_v2_d2_z", &tru_v2_d2_z, &b_tru_v2_d2_z);
   fChain->SetBranchAddress("tru_v2_d2_t", &tru_v2_d2_t, &b_tru_v2_d2_t);
   fChain->SetBranchAddress("tru_v2_d2_r", &tru_v2_d2_r, &b_tru_v2_d2_r);
   fChain->SetBranchAddress("tru_ph1_pt", &tru_ph1_pt, &b_tru_ph1_pt);
   fChain->SetBranchAddress("tru_ph1_eta", &tru_ph1_eta, &b_tru_ph1_eta);
   fChain->SetBranchAddress("tru_ph1_phi", &tru_ph1_phi, &b_tru_ph1_phi);
   fChain->SetBranchAddress("tru_ph1_E", &tru_ph1_E, &b_tru_ph1_E);
   fChain->SetBranchAddress("tru_ph2_pt", &tru_ph2_pt, &b_tru_ph2_pt);
   fChain->SetBranchAddress("tru_ph2_eta", &tru_ph2_eta, &b_tru_ph2_eta);
   fChain->SetBranchAddress("tru_ph2_phi", &tru_ph2_phi, &b_tru_ph2_phi);
   fChain->SetBranchAddress("tru_ph2_E", &tru_ph2_E, &b_tru_ph2_E);
   fChain->SetBranchAddress("tru_G1_pt", &tru_G1_pt, &b_tru_G1_pt);
   fChain->SetBranchAddress("tru_G1_eta", &tru_G1_eta, &b_tru_G1_eta);
   fChain->SetBranchAddress("tru_G1_phi", &tru_G1_phi, &b_tru_G1_phi);
   fChain->SetBranchAddress("tru_G1_E", &tru_G1_E, &b_tru_G1_E);
   fChain->SetBranchAddress("tru_G2_pt", &tru_G2_pt, &b_tru_G2_pt);
   fChain->SetBranchAddress("tru_G2_eta", &tru_G2_eta, &b_tru_G2_eta);
   fChain->SetBranchAddress("tru_G2_phi", &tru_G2_phi, &b_tru_G2_phi);
   fChain->SetBranchAddress("tru_G2_E", &tru_G2_E, &b_tru_G2_E);
   fChain->SetBranchAddress("tru_b1_pt", &tru_b1_pt, &b_tru_b1_pt);
   fChain->SetBranchAddress("tru_b1_eta", &tru_b1_eta, &b_tru_b1_eta);
   fChain->SetBranchAddress("tru_b1_phi", &tru_b1_phi, &b_tru_b1_phi);
   fChain->SetBranchAddress("tru_b1_E", &tru_b1_E, &b_tru_b1_E);
   fChain->SetBranchAddress("tru_b1_vbyc", &tru_b1_vbyc, &b_tru_b1_vbyc);
   fChain->SetBranchAddress("tru_b2_pt", &tru_b2_pt, &b_tru_b2_pt);
   fChain->SetBranchAddress("tru_b2_eta", &tru_b2_eta, &b_tru_b2_eta);
   fChain->SetBranchAddress("tru_b2_phi", &tru_b2_phi, &b_tru_b2_phi);
   fChain->SetBranchAddress("tru_b2_E", &tru_b2_E, &b_tru_b2_E);
   fChain->SetBranchAddress("tru_b2_vbyc", &tru_b2_vbyc, &b_tru_b2_vbyc);
   fChain->SetBranchAddress("tru_glu1_pt", &tru_glu1_pt, &b_tru_glu1_pt);
   fChain->SetBranchAddress("tru_glu1_eta", &tru_glu1_eta, &b_tru_glu1_eta);
   fChain->SetBranchAddress("tru_glu1_phi", &tru_glu1_phi, &b_tru_glu1_phi);
   fChain->SetBranchAddress("tru_glu1_E", &tru_glu1_E, &b_tru_glu1_E);
   fChain->SetBranchAddress("tru_glu2_pt", &tru_glu2_pt, &b_tru_glu2_pt);
   fChain->SetBranchAddress("tru_glu2_eta", &tru_glu2_eta, &b_tru_glu2_eta);
   fChain->SetBranchAddress("tru_glu2_phi", &tru_glu2_phi, &b_tru_glu2_phi);
   fChain->SetBranchAddress("tru_glu2_E", &tru_glu2_E, &b_tru_glu2_E);
   fChain->SetBranchAddress("tru_ph1_timing", &tru_ph1_timing, &b_tru_ph1_timing);
   fChain->SetBranchAddress("tru_ph2_timing", &tru_ph2_timing, &b_tru_ph2_timing);
   fChain->SetBranchAddress("tru_ph_all_timing", &tru_ph_all_timing, &b_tru_ph_all_timing);
   fChain->SetBranchAddress("tru_ph1_tof", &tru_ph1_tof, &b_tru_ph1_tof);
   fChain->SetBranchAddress("tru_ph2_tof", &tru_ph2_tof, &b_tru_ph2_tof);
   fChain->SetBranchAddress("tru_ph_tof", &tru_ph_tof, &b_tru_ph_tof);
   fChain->SetBranchAddress("tru_ph1_pdgid", &tru_ph1_pdgid, &b_tru_ph1_pdgid);
   fChain->SetBranchAddress("tru_ph2_pdgid", &tru_ph2_pdgid, &b_tru_ph2_pdgid);
   fChain->SetBranchAddress("tru_glu1_pdgid", &tru_glu1_pdgid, &b_tru_glu1_pdgid);
   fChain->SetBranchAddress("tru_glu2_pdgid", &tru_glu2_pdgid, &b_tru_glu2_pdgid);
   fChain->SetBranchAddress("tru_b1_pdgid", &tru_b1_pdgid, &b_tru_b1_pdgid);
   fChain->SetBranchAddress("tru_b2_pdgid", &tru_b2_pdgid, &b_tru_b2_pdgid);
   fChain->SetBranchAddress("tru_G1_pdgid", &tru_G1_pdgid, &b_tru_G1_pdgid);
   fChain->SetBranchAddress("tru_G2_pdgid", &tru_G2_pdgid, &b_tru_G2_pdgid);
   fChain->SetBranchAddress("tru_b1_timing", &tru_b1_timing, &b_tru_b1_timing);
   fChain->SetBranchAddress("tru_b2_timing", &tru_b2_timing, &b_tru_b2_timing);
   fChain->SetBranchAddress("tru_b_all_timing", &tru_b_all_timing, &b_tru_b_all_timing);
   fChain->SetBranchAddress("tru_prompt1_timing", &tru_prompt1_timing, &b_tru_prompt1_timing);
   fChain->SetBranchAddress("tru_prompt2_timing", &tru_prompt2_timing, &b_tru_prompt2_timing);
   fChain->SetBranchAddress("tru_prompt_all_timing", &tru_prompt_all_timing, &b_tru_prompt_all_timing);
   fChain->SetBranchAddress("tru_ph_pointing", &tru_ph_pointing, &b_tru_ph_pointing);
   fChain->SetBranchAddress("tru_ph1_pointing", &tru_ph1_pointing, &b_tru_ph1_pointing);
   fChain->SetBranchAddress("tru_ph2_pointing", &tru_ph2_pointing, &b_tru_ph2_pointing);
   fChain->SetBranchAddress("sp_cutflow_pt", &sp_cutflow_pt, &b_sp_cutflow_pt);
   fChain->SetBranchAddress("sp_cutflow_eta", &sp_cutflow_eta, &b_sp_cutflow_eta);
   fChain->SetBranchAddress("sp_cutflow_METl20", &sp_cutflow_METl20, &b_sp_cutflow_METl20);
   fChain->SetBranchAddress("sp_cutflow_METg75", &sp_cutflow_METg75, &b_sp_cutflow_METg75);
   fChain->SetBranchAddress("sp_cutflow_METg200", &sp_cutflow_METg200, &b_sp_cutflow_METg200);
   fChain->SetBranchAddress("sp_cutflow_SR1", &sp_cutflow_SR1, &b_sp_cutflow_SR1);
   fChain->SetBranchAddress("sp_cutflow_SR1_t1p5", &sp_cutflow_SR1_t1p5, &b_sp_cutflow_SR1_t1p5);
   fChain->SetBranchAddress("sp_cutflow_SR1_t2", &sp_cutflow_SR1_t2, &b_sp_cutflow_SR1_t2);
   fChain->SetBranchAddress("sp_cutflow_SR", &sp_cutflow_SR, &b_sp_cutflow_SR);
   fChain->SetBranchAddress("sp_cutflow_SR_t1p5", &sp_cutflow_SR_t1p5, &b_sp_cutflow_SR_t1p5);
   fChain->SetBranchAddress("sp_cutflow_SR_t2", &sp_cutflow_SR_t2, &b_sp_cutflow_SR_t2);
   fChain->SetBranchAddress("dp_cutflow_pt", &dp_cutflow_pt, &b_dp_cutflow_pt);
   fChain->SetBranchAddress("dp_cutflow_eta", &dp_cutflow_eta, &b_dp_cutflow_eta);
   fChain->SetBranchAddress("dp_cutflow_METl20", &dp_cutflow_METl20, &b_dp_cutflow_METl20);
   fChain->SetBranchAddress("dp_cutflow_METg75", &dp_cutflow_METg75, &b_dp_cutflow_METg75);
   fChain->SetBranchAddress("dp_cutflow_SR", &dp_cutflow_SR, &b_dp_cutflow_SR);
   fChain->SetBranchAddress("dp_cutflow_SR_t1p5", &dp_cutflow_SR_t1p5, &b_dp_cutflow_SR_t1p5);
   fChain->SetBranchAddress("dp_cutflow_SR_t2", &dp_cutflow_SR_t2, &b_dp_cutflow_SR_t2);
   fChain->SetBranchAddress("tru_sol_var", &tru_sol_var, &b_tru_sol_var);
   Notify();
}

Bool_t BH::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void BH::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t BH::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef BH_cxx
