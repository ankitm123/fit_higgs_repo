import FWCore.ParameterSet.Config as cms
                  
#channel = "BLABLA"

process = cms.Process("HTauTauTree")


## MessageLogger
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1

#from CalibCalorimetry.EcalTrivialCondModules.EcalTrivialCondRetriever_cfi import *
#process.myCond = EcalTrivialConditionRetriever.clone()
#process.es_prefer_gt = cms.ESPrefer("PoolDBESSource","GlobalTag")


## Options and Output Report
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(False) )

process.options.allowUnscheduled = cms.untracked.bool( True )

## Geometry and Detector Conditions (needed for a few patTuple production steps)
#process.load('Configuration.Geometry.GeometryExtended2017Reco_cff') 
#process.load('Configuration.Geometry.GeometryExtended2017_cff')
process.load('Configuration.Geometry.GeometryExtended2019Reco_cff')
process.load('Configuration.Geometry.GeometryExtended2019_cff')

process.load('Configuration.StandardSequences.MagneticField_38T_cff')

#process.load("RecoLocalCalo.EcalRecAlgos.EcalSeverityLevelESProducer_cfi")

process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
#process.GlobalTag.globaltag = 'STAR17_61_V5A::All'
#process.GlobalTag.globaltag = 'DES17_61_V4::All'

process.GlobalTag.globaltag = 'DES19_62_V8::All'
process.load("Configuration.StandardSequences.MagneticField_cff")
process.source = cms.Source("PoolSource", 
                            fileNames = cms.untracked.vstring(
#'root://xrootd.unl.edu//store/mc/Fall13dr/DYJetsToLL_M-50_13TeV-pythia6/AODSIM/tsg_PU40bx50_POSTLS162_V1-v1/00000/0659AA61-2175-E311-8B63-00266CFFA2B8.root'  
#'root://xrootd.unl.edu//store/mc/Summer13/VBF_HToTauTau_M-125_14TeV-powheg-pythia6/GEN-SIM-RECO/UpgradePhase1Age0DES_DR61SLHCx_NoPileUp_DES17_61_V5-v1/10000/00A38233-7E02-E311-A483-002618943964.root'
#'root://xrootd.unl.edu//store/mc/Summer13/DYToTauTau_M-20_TuneZ2star_14TeV-pythia6-tauola/GEN-SIM-RECO/UpgradePhase1Age5H_DR61SLHCx_PU140Bx25_STAR17_61_V5A-v1/10000/0005C614-5DF2-E211-9BA8-0026189438ED.root'
#'file:/afs/cern.ch/work/a/archie/public/minbias/MinBias_TuneZ2star_14TeV_pythia6_CMSSW620_slhc5_996_1_Qy8.root',
#'file:/afs/cern.ch/work/a/archie/public/minbias/MinBias_TuneZ2star_14TeV_pythia6_CMSSW620_slhc5_997_1_1yO.root',
#'file:/afs/cern.ch/work/a/archie/public/minbias/MinBias_TuneZ2star_14TeV_pythia6_CMSSW620_slhc5_998_1_Tqc.root'
##'file:/afs/cern.ch/work/a/aabdelal/public/beamspotGauss/MinBias/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_991_1_3qc.root',
##'file:/afs/cern.ch/work/a/aabdelal/public/beamspotGauss/MinBias/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_996_1_kGt.root',
##'file:/afs/cern.ch/work/a/aabdelal/public/beamspotGauss/MinBias/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_992_1_Ley.root',
##'file:/afs/cern.ch/work/a/aabdelal/public/beamspotGauss/MinBias/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_997_1_cg0.root',
##'file:/afs/cern.ch/work/a/aabdelal/public/beamspotGauss/MinBias/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_993_1_BdQ.root',
##'file:/afs/cern.ch/work/a/aabdelal/public/beamspotGauss/MinBias/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_998_1_QuQ.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluGluH_tautau_14TeV_620slhc5_v5_gaussBeamSpot_100_1_uUb.root'
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1001_1_V3z.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1002_1_8rt.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1003_1_Jyg.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1004_1_cXq.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1005_1_YZ0.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1006_3_J9v.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1007_1_QBm.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1008_1_KS4.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1009_1_puE.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_100_1_En4.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1010_1_IFd.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1011_3_hFJ.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1012_1_dwz.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1013_1_xV0.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1014_1_Icy.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1015_1_tvI.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1016_1_SkU.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1017_1_jC3.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1018_1_NFq.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1019_1_YgP.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_101_1_L9f.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1020_1_Nz2.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1021_1_pds.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1022_1_Yg6.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1023_4_cu4.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1024_2_RF2.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1025_1_f4D.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1026_1_5NT.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1027_1_T4x.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1028_1_hqF.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1029_1_Vix.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1030_1_7Aj.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1031_1_flV.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1032_1_h62.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1033_1_Kvc.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1034_1_QOT.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1035_1_mWE.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1036_1_qYF.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1038_1_8CV.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1039_1_hTe.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_103_1_7NH.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1040_1_cAT.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1041_1_4N5.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1042_1_2La.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1043_1_5F0.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1044_1_hlt.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1045_1_2Pm.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1046_1_GHO.root',
#'root://xrootd.unl.edu//store/user/aabdelal/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/aabdelal_MinBias_TuneZ2star_14TeV_pythia6_14TeV_GaussBS_RECO_aod_CMSSW_6_2_0_SLHC5/4b73dbaf4bf75a21ad171c02dcd12bab/MinBias_TuneZ2star_14TeV_GaussBS_RECO_620slhc5_1047_1_ZpV.root'

)
)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(5) )

## Output Module Configuration (expects a path 'p')
#process.load("HighMassAnalysis.Configuration.patTupleEventContentForHiMassTau_cff")
###from HighMassAnalysis.Configuration.patTupleEventContentForHiMassTau_cff import *
###process.out = cms.OutputModule("PoolOutputModule",
###                               fileName = cms.untracked.string('skimPat.root'),
###                               # save only events passing the full path
###                               SelectEvents   = cms.untracked.PSet( SelectEvents = cms.vstring('p') ),
###                            #   outputCommands = cms.untracked.vstring('drop *', *patTupleEventContent ),
###                               fastCloning = cms.untracked.bool(False)
###                               )

from PhysicsTools.PatAlgos.patEventContent_cff import patEventContentNoCleaning
process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string('patTuple.root'),
                               ## save only events passing the full path
                               SelectEvents = cms.untracked.PSet( SelectEvents = cms.vstring('p') ),
                               ## save PAT output; you need a '*' to unpack the list of commands
                               ## 'patEventContent'
                               outputCommands = cms.untracked.vstring('drop *', *patEventContentNoCleaning )
                               #outputCommands = cms.untracked.vstring('drop *',
                               #                                       'keep *_*_*_ANA',
                               #                                       'keep *_gsfElectron*_*_*',
                               #                                       'keep *_muons_*_*',
                                #                                      'keep *_selectedPatMuons_*_*',
                                #                                      'keep *_selectedPatTaus_*_*',
                                #                                      'keep *_zmm_*_*',
                                #                                      'keep *_pfMet_*_*',
                                #                                      'keep *_tcMet_*_*',
                                #                                      'keep *_ak5PFJets_*_*',
                                #                                      'keep *_TriggerResults_*_*',
                                #                                      'keep *_gtDigis_*_*',
                                #                                      'keep *_trackCountingHighEffBJetTags_*_*',
                                #                                      'keep *_ak5CaloJets_*_*',
                                 #                                     'keep *_kt6PFJets_*_*',
                                  #                                    'keep *_kt4PFJets_*_*',
                                  #                                    'keep *_GlobalMuonPromptTight_*_*',
                                  #                                    'keep *_offlinePrimaryVerticesWithBS_*_*',
                                  #                                    'keep PileupSummaryInfos_*_*_*',
                                  #                                    'keep *_offlinePrimaryVertices_*_*',
                                  #                                    'keep *_selectedVertices_*_*',
                                  #                                    'keep *_kt6PFJets_*_*',
                                   #                                   'keep *_TriggerResults_*_*',
                                    #                                  'keep triggerTriggerEvent_*_*_*',
                                    #                                  'keep *_ak5CaloJets_*_*',
                                    #                                  'keep recoPFClusters_*_*_*',
                                    #                                  'keep *_selectedPatJets__*',
                                    #                                  'keep *_selectedPatJetsFast__*',
                                    #                                  'keep *_kt4PFJets_rho_PAT',
#                                                                      'keep *_kt4PFJetsIso_rho_PAT',
#                                     #                                 )
                               )



#process.TFileService = cms.Service("TFileService",
#  fileName = cms.string('test_53x.root')
#)


#process.scrapingVeto = cms.EDFilter("FilterOutScraping",
#                                    applyfilter = cms.untracked.bool(True),
#                                    debugOn = cms.untracked.bool(False),
#                                    numtrack = cms.untracked.uint32(10),
#                                    thresh = cms.untracked.double(0.2)
#                                    )

#process.selectedVertices = cms.EDFilter("VertexSelector",
#    src = cms.InputTag('offlinePrimaryVertices'),
#    cut = cms.string('!isFake && isValid && ndof >= 4.0 && position.Rho < 2.0 && abs(z) < 24'),
#    cut = cms.string('!isFake && isValid'),
#    filter = cms.bool(True)
#)



#process.demo = cms.EDAnalyzer('TreeMaker',
#   fillHZZInfo_  = cms.bool(True),
#   patMuons = cms.InputTag("selectedPatMuons"),
#   PFMET     = cms.InputTag("pfMet"),
#   Vertex=cms.InputTag("selectedVertices"),
#   PileUpTag = cms.InputTag("addPileupInfo"),
#   fastjetTag = cms.InputTag("kt6PFJets", "rho"),
#   rhoConeSize = cms.double(0.5),
#   rhoUEOffsetCorrection = cms.double(1.0),
#   outputCommands = cms.untracked.vstring('drop *',
#        'keep *_*_*_ANA',
#        'keep *_gsfElectron*_*_*',
#        'keep *_muons_*_*',
#        'keep *_selectedPatMuons_*_*',
#        'keep *_zmm_*_*',
#        'keep *_pfMet_*_*',
#        'keep *_tcMet_*_*',
#        'keep *_ak5PFJets_*_*',
#        'keep *_TriggerResults_*_*',
#        'keep *_gtDigis_*_*',
#        'keep *_trackCountingHighEffBJetTags_*_*',
#        'keep *_ak5CaloJets_*_*',
#        'keep *_kt6PFJets_*_*',
#        'keep *_kt4PFJets_*_*',
#        'keep *_GlobalMuonPromptTight_*_*',
#        'keep *_offlinePrimaryVerticesWithBS_*_*',
#        'keep PileupSummaryInfos_*_*_*',
#        'keep *_offlinePrimaryVertices_*_*',
#        'keep *_selectedVertices_*_*',
#        'keep *_kt6PFJets_*_*',
#        'keep *_TriggerResults_*_*',
#        'keep triggerTriggerEvent_*_*_*',
#        'keep *_ak5CaloJets_*_*',
#        'keep recoPFClusters_*_*_*',
#        'keep *_selectedPatJets__*',
#        'keep *_selectedPatJetsFast__*',
#        'keep *_kt4PFJets_rho_PAT',
#        'keep *_kt4PFJetsIso_rho_PAT',
#
#    )
#
#)

## Output Module Configuration (expects a path 'p')

#process.TFileService = cms.Service("TFileService",
#                                   fileName = cms.string("analysis.root")
#                                   )
#process.outpath = cms.EndPath(process.out)
# trigger + Skim sequence
###process.load("HighMassAnalysis.Skimming.triggerReq_cfi")
###process.load("HighMassAnalysis.Skimming.genLevelSequence_cff")

###if(channel == "BLABLA"):
###  process.load("HighMassAnalysis.Skimming.TauSkimSequence_cff")
###  process.theSkim = cms.Sequence( )
###  process.hltFilter = cms.Sequence( )
###  process.genLevelSelection = cms.Sequence(  )
  
  # Standard pat sequences
#process.load('RecoJets.Configuration.RecoPFJets_cff')
process.load("PhysicsTools.PatAlgos.patSequences_cff")
from PhysicsTools.PatAlgos.tools.pfTools import *
postfix = "PFlow"
jetAlgo="AK5"
usePF2PAT(process,runPF2PAT=True, jetAlgo=jetAlgo, runOnMC=True, postfix=postfix)

  # --------------------Modifications for taus--------------------
###  process.load("PhysicsTools.JetMCAlgos.TauGenJets_cfi")
  
###  process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")
###  from PhysicsTools.PatAlgos.tools.tauTools import *
###  switchToPFTauHPS(process)
  
  
#from RecoJets.JetProducers.kt4PFJets_cfi import kt4PFJets
#process.kt6PFJetsForIsolation = kt4PFJets.clone( rParam = 0.6, doRhoFastjet = True )
#process.kt6PFJetsForIsolation.Rho_EtaMax = cms.double(2.5)
  
  # --------------------Modifications for jets--------------------
  
#from PhysicsTools.PatAlgos.tools.jetTools import *
## uncomment the following lines to add ak5PFJets to your PAT output
#switchJetCollection(
#    process,
#    jetSource = cms.InputTag('ak5PFJets'),
#    jetCorrections = ('AK5PF', cms.vstring(['L1FastJet', 'L2Relative', 'L3Absolute']), 'Type-2'),
#    btagDiscriminators = [
#    'combinedSecondaryVertexBJetTags',
    #   'combinedSecondaryVertexMVABJetTags',
    #   'jetBProbabilityBJetTags',
    #   'jetProbabilityBJetTags',
    #   'simpleSecondaryVertexHighEffBJetTags',
    #   'simpleSecondaryVertexHighPurBJetTags',
#    ],
#    )
#process.selectedPatJets.cut = cms.string("pt > 0 && abs(eta) < 5")
  
  # --------------------Modifications for MET--------------------
###  process.load("JetMETCorrections.Type1MET.pfMETCorrections_cff")
###  process.load("JetMETCorrections.Type1MET.pfMETCorrectionType0_cfi")
###  process.pfType1CorrectedMet.applyType0Corrections = cms.bool(False)
###  process.pfType1CorrectedMet.srcType1Corrections = cms.VInputTag(
###    cms.InputTag('pfMETcorrType0'),
###    cms.InputTag('pfJetMETcorr', 'type1')        
###    )
  
  
  # Let it run

process.load("VHTauTau.TreeMaker.TreeCreator_cfi")
process.load("VHTauTau.TreeMaker.TreeWriter_cfi")
process.load("VHTauTau.TreeMaker.TreeContentConfig_cff")

#-------------------------------------------------------
# PAT 
#------------------------------------------------------
#process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")
#process.load("PhysicsTools.PatAlgos.patSequences_cff")

#import PhysicsTools.PatAlgos.tools.tauTools as tauTools
#tauTools.switchToPFTauHPS(process) # For HPS Taus
#process.patSeq=cms.Sequence(process.patDefaultSequence)
#process.patSeq.remove(process.patJets)
#process.patDefaultSequence.remove(process.patJets) 
process.p = cms.Path(
    #      process.type0PFMEtCorrection +
    #      process.producePFMETCorrections +
    #      process.tauGenJets +
    #      process.recoTauClassicHPSSequence +
    #process.patDefaultSequence
    getattr(process,"patPF2PATSequence"+postfix) +
    process.treeCreator +
    process.treeContentSequence +
    process.treeWriter
    #      process.kt6PFJetsForIsolation + 
    #      process.demo
    )
process.outpath = cms.EndPath(process.out)
