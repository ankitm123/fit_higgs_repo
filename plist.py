import FWCore.ParameterSet.Config as cms
process = cms.Process("HTauTauTree")
#------------------------
# Message Logger Settings
#------------------------
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1
#--------------------------------------
# Event Source & # of Events to process
#---------------------------------------
process.source = cms.Source("PoolSource",
  fileNames = cms.untracked.vstring()
)
process.maxEvents = cms.untracked.PSet(
  input = cms.untracked.int32(1)
)
process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(False) )

#-----------------------------
# Geometry
#-----------------------------
process.load("Configuration.StandardSequences.Geometry_cff")
#-----------------------------
# Magnetic Field
#-----------------------------
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
#-------------
# Global Tag
#-------------
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'START53_V11::All'
#-------------
# Output ROOT file
#-------------

process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
process.printTree = cms.EDAnalyzer("ParticleListDrawer",
                                     maxEventsToPrint = cms.untracked.int32(1),
                                     printVertex = cms.untracked.bool(False),
                                     src = cms.InputTag("genParticles")
                                   )
process.p = cms.Path(process.printTree)

process.PoolSource.fileNames = [
#'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/htotautomu_test.root',
#'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu_2/htotautomu_test_1_1_Hii.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/VHTauTau/TreeMaker/test/00E903E2-9FE9-E111-8B1E-003048FF86CA.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu_1/htotautomu_test_1_1_uIk.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu_1/htotautomu_test_3_1_wvk.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_1_1_zfD.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_2_1_1KO.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_6_1_Iwi.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_5_1_bow.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_12_1_DKN.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_13_1_lxR.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_7_1_r99.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_14_1_Y2O.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_4_1_7d9.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_10_1_72r.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_11_1_dgO.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_9_1_06x.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_15_1_36z.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_19_1_5Lg.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_22_1_Mi5.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_20_1_Fzy.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_17_1_O0L.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_16_1_fYJ.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_8_1_OgL.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_21_1_8jw.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_23_1_IkX.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_29_1_To5.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_28_1_zWe.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_30_1_WXO.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_18_1_ilY.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_25_1_UfF.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_24_1_j6W.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_26_1_csG.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_27_1_9DE.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_31_1_VR9.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_40_1_Eeb.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_38_1_ZYz.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_39_1_dq7.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_32_1_e7e.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_35_1_KDG.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_33_1_PJV.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_36_1_Nxk.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_37_1_Nq9.root',
'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluHTauMuMu/htotautomu_test_34_1_6uG.root',
]
