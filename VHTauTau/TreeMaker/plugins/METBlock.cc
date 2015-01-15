#include <iostream>

#include "TTree.h"
#include "TClonesArray.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/PatCandidates/interface/MET.h"

#include "VHTauTau/TreeMaker/plugins/METBlock.h"
#include "VHTauTau/TreeMaker/interface/Utility.h"

METBlock::METBlock(const edm::ParameterSet& iConfig) :
  _verbosity(iConfig.getParameter<int>("verbosity")),
  _pfInputTag(iConfig.getParameter<edm::InputTag>("metSrc"))
  // _corrinputTag(iConfig.getParameter<edm::InputTag>("corrmetSrc")),
  //_mvainputTag(iConfig.getParameter<edm::InputTag>("mvametSrc"))
{
}
//METBlock::~METBlock(){
//}
void METBlock::beginJob() 
{
  // Get TTree pointer
  TTree* tree = vhtm::Utility::getTree("vhtree");

  clonePFMET = new TClonesArray("vhtm::MET");
  tree->Branch("MET", &clonePFMET, 32000, 2);
  tree->Branch("nMET", &fnPFMET,  "fnPFMET/I");

  /*cloneCorrMET = new TClonesArray("vhtm::MET");
  tree->Branch("corrMET", &cloneCorrMET, 32000, 2);
  tree->Branch("corrnMET", &fnCorrMET,  "fnCorrMET/I");

  cloneMVAMET = new TClonesArray("vhtm::MET");
  tree->Branch("mvaMET", &cloneMVAMET, 32000, 2);
  tree->Branch("mvanMET", &fnMVAMET,  "fnMVAMET/I");*/
}
void METBlock::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  //fillMET(iEvent, iSetup, clonePFMET, fnPFMET, _pfinputTag, pfmetB);
  //fillMET(iEvent, iSetup, cloneCorrMET, fnCorrMET, _corrinputTag, corrmetB);
  //fillMET(iEvent, iSetup, cloneMVAMET, fnMVAMET, _mvainputTag, mvametB);



  // Reset the TClonesArray and the nObj variables
  clonePFMET->Clear();
  fnPFMET = 0;
  
  edm::Handle<std::vector<pat::MET> > mets;
  iEvent.getByLabel(_pfInputTag, mets);

  if (mets.isValid()) {
    edm::LogInfo("METBlock") << "Total # PAT METs: " << mets->size();

    for (std::vector<pat::MET>::const_iterator it = mets->begin(); 
                                              it != mets->end(); ++it) {
      if (fnPFMET == kMaxMET) {
	edm::LogInfo("METBlock") << "Too many PAT MET, nMET = " << fnPFMET 
                                 << ", label: " << _pfInputTag; 
	break;
      }
      metB = new ((*clonePFMET)[fnPFMET++]) vhtm::MET();

      // fill in all the vectors
      metB->met          = it->pt();
      metB->metphi       = it->phi();
      metB->metx         = it->px();
      metB->mety         = it->py();
      metB->sumet        = it->sumEt();
      metB->metuncorr    = it->uncorrectedPt(pat::MET::uncorrALL);
      metB->metphiuncorr = it->uncorrectedPhi(pat::MET::uncorrALL);
      metB->sumetuncorr  = it->sumEt() - it->corSumEt(pat::MET::uncorrALL);
    }
  } 
  else {
    edm::LogError("METBlock") << "Error >> Failed to get pat::MET collection for label: " 
                              << _pfInputTag;
  }
}
#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(METBlock);
