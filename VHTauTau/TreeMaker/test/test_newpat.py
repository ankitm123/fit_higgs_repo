import FWCore.ParameterSet.Config as cms

process = cms.Process("PAT")

## MessageLogger
process.load("FWCore.MessageLogger.MessageLogger_cfi")

## Options and Output Report
process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

## Source
process.source = cms.Source("PoolSource",
                                fileNames = cms.untracked.vstring()
                            )
## Maximal Number of Events
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

## Geometry and Detector Conditions (needed for a few patTuple production steps)
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

## Output Module Configuration (expects a path 'p')

from PhysicsTools.PatAlgos.patEventContent_cff import patEventContentNoCleaning
process.out = cms.OutputModule("PoolOutputModule",
                                                              fileName = cms.untracked.string('patTuple.root'),
                                                              ## save only events passing the full path
                                                              #SelectEvents = cms.untracked.PSet( SelectEvents = cms.vstring('p') ),
                                                              ## save PAT output; you need a '*' to unpack the list of commands
                                                              ## 'patEventContent'
                                                              outputCommands = cms.untracked.vstring('drop *', *patEventContentNoCleaning )
                                                              )

process.outpath = cms.EndPath(process.out)

#from PhysicsTools.PatAlgos.mcMatchLayer0 import *
#process.load("PhysicsTools.PatAlgos.patSequences_cff")
#process.load('PhysicsTools.PatAlgos.mcMatchLayer0.muonMatch_cfi')
process.load('PhysicsTools.PatAlgos.producersLayer1.muonProducer_cff')
#process.muMatch1 = process.muonMatch.clone(mcStatus = [1])

# verbose flags for the PF2PAT modules
process.options.allowUnscheduled = cms.untracked.bool(True)
#process.Tracer = cms.Service("Tracer")


# Configure PAT to use PF2PAT instead of AOD sources
# this function will modify the PAT sequences.
from PhysicsTools.PatAlgos.tools.pfTools import *
postfix = "PFlow"
jetAlgo="AK5"
usePF2PAT(process,runPF2PAT=True, jetAlgo=jetAlgo, runOnMC=True, postfix=postfix)


# to turn on type-1 MET corrections, use the following call
#usePF2PAT(process,runPF2PAT=True, jetAlgo=jetAlgo, runOnMC=True, postfix=postfix, typeIMetCorrections=True)

# to switch default tau (HPS) to old default tau (shrinking cone) uncomment
# the following:
# note: in current default taus are not preselected i.e. you have to apply
# selection yourself at analysis level!
#adaptPFTaus(process,"shrinkingConePFTau",postfix=postfix)

# Add PF2PAT output to the created file
from PhysicsTools.PatAlgos.patEventContent_cff import patEventContentNoCleaning
#process.load("CommonTools.ParticleFlow.PF2PAT_EventContent_cff")
#process.out.outputCommands =  cms.untracked.vstring('drop *')
process.out.outputCommands = cms.untracked.vstring('drop *',
                                                   'keep recoPFCandidates_particleFlow_*_*',
						   'keep *_selectedPatJets*_*_*',
						   'drop *_selectedPatJets*_caloTowers_*',
						   'keep *_selectedPatElectrons*_*_*',
						   'keep *_selectedPatMuons*_*_*',
						   'keep *_selectedPatTaus*_*_*',
						   'keep *_patMETs*_*_*',
						   'keep *_selectedPatPhotons*_*_*',
						   'keep *_selectedPatTaus*_*_*',
                                                   'keep *_generalTracks_*_*',
                                                   'keep *_genParticles_*_*',
                                                   'keep *_offlineBeamSpot_*_*',
                                                   'keep *_offlinePrimaryVertices_*_*',
                                                   'keep *_gtDigis_*_*'
                                                   )


# top projections in PF2PAT:
#getattr(process,"pfNoPileUp"+postfix).enable = True
#getattr(process,"pfNoMuon"+postfix).enable = True
#getattr(process,"pfNoElectron"+postfix).enable = True
#getattr(process,"pfNoTau"+postfix).enable = False
#getattr(process,"pfNoJet"+postfix).enable = True
# to use tau-cleaned jet collection uncomment the following:
#getattr(process,"pfNoTau"+postfix).enable = True

# verbose flags for the PF2PAT modules
#getattr(process,"pfNoMuon"+postfix).verbose = False

# enable delta beta correction for muon selection in PF2PAT?
#getattr(process,"pfIsolatedMuons"+postfix).doDeltaBetaCorrection = cms.bool(False)
#MCTruthMatching
#getattr(process,muMatch1).enable = True
process.p=cms.Path(
    process.muonMatch +
    getattr(process,"pfNoPileUp"+postfix)+
    getattr(process,"pfNoMuon"+postfix)+
    getattr(process,"pfNoElectron"+postfix)+
    #getattr(process,"pfNoTau"+postfix).enable =
    getattr(process,"pfNoJet"+postfix)
    #process.analyzePatMCMatching
    )

#process.patDefaultSequence.replace(process.patDefaultSequence,
#    getattr(process,"pfNoPileUp"+postfix)+
#    getattr(process,"pfNoMuon"+postfix)+
#    getattr(process,"pfNoElectron"+postfix)+
    #getattr(process,"pfNoTau"+postfix).enable =
#    getattr(process,"pfNoJet"+postfix)
#    process.muonMatch
#    )

#process.p=cms.Path(process.patDefaultSequence)


## ------------------------------------------------------
#  In addition you usually want to change the following
#  parameters:
## ------------------------------------------------------
#
#   process.GlobalTag.globaltag =  ...    ##  (according to https://twiki.cern.ch/twiki/bin/view/CMS/SWGuideFrontierConditions)
#                                         ##
#from PhysicsTools.PatAlgos.patInputFiles_cff import filesRelValProdTTbarAODSIM
#process.source.fileNames = filesRelValProdTTbarAODSIM
process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
    'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluGluH_tautau_14TeV_620slhc5_v5_gaussBeamSpot_100_1_uUb.root'
#    'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluGluH_tautau_14TeV_620slhc5_v5_gaussBeamSpot_101_1_2qJ.root',
#    'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluGluH_tautau_14TeV_620slhc5_v5_gaussBeamSpot_102_2_Rqu.root',
#    'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluGluH_tautau_14TeV_620slhc5_v5_gaussBeamSpot_103_1_d85.root',
#    'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluGluH_tautau_14TeV_620slhc5_v5_gaussBeamSpot_104_1_yTR.root',
#    'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluGluH_tautau_14TeV_620slhc5_v5_gaussBeamSpot_105_1_BFe.root',
#    'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluGluH_tautau_14TeV_620slhc5_v5_gaussBeamSpot_106_1_z6e.root',
#    'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluGluH_tautau_14TeV_620slhc5_v5_gaussBeamSpot_107_1_bhH.root',
#    'file:/home/amohapatra/work/test/CMSSW_6_2_0_SLHC5/src/GluGluH_tautau_14TeV_620slhc5_v5_gaussBeamSpot_108_3_AIL.root'
    )
                            )

#                                         ##
#process.maxEvents.input = 10
#                                         ##
#   process.out.outputCommands = [ ... ]  ##  (e.g. taken from PhysicsTools/PatAlgos/python/patEventContent_cff.py)
#                                         ##
process.out.fileName = 'patTuple_PF2PAT.root'
#                                         ##
#   process.options.wantSummary = False   ##  (to suppress the long output at the end of the job)
