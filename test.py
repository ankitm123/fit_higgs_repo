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
  input = cms.untracked.int32(-1)
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
process.TFileService = cms.Service("TFileService",
  fileName = cms.string('~/ankit_storage/gem_physics/httmumu_14TeV_2019/httmumu_14TeV_2019.root')
)
#--------------------------------------------------
# VHTauTau Tree Specific
#--------------------------------------------------
process.load("VHTauTau.TreeMaker.TreeCreator_cfi")
process.load("VHTauTau.TreeMaker.TreeWriter_cfi")
process.load("VHTauTau.TreeMaker.TreeContentConfig_cff")

#-------------------------------------------------------
# PAT 
#------------------------------------------------------
process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")
process.load("PhysicsTools.PatAlgos.patSequences_cff")

#import PhysicsTools.PatAlgos.tools.tauTools as tauTools
#tauTools.switchToPFTauHPS(process) # For HPS Taus

## --
## Switch on PAT trigger
## --
import PhysicsTools.PatAlgos.tools.trigTools as trigTools
trigTools.switchOnTrigger( process, outputModule='' ) # This is optional and can be omitted.

process.p = cms.Path(
  process.treeCreator +
  process.treeContentSequence +
  process.treeWriter
)

# List File names here
#---------------------------------------
process.PoolSource.fileNames = [
'file:/home/amohapatra/ankit_storage/gem_physics/httmumu_14TeV_2015/Pythia6_Tauola_GluGluH_tautau_mumu_14TeV_RECOSIM_2015_private_pat/gluhtotautomu_nogem_14_2015_197_1_n4T.root'
]
