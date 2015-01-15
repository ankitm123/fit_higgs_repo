import FWCore.ParameterSet.Config as cms

metBlock = cms.EDAnalyzer("METBlock",
                          verbosity = cms.int32(0),
                          metSrc    = cms.InputTag('patMETsPFlow'),
                          #metSrc    = cms.InputTag('patMETs')
  #metSrc    = cms.InputTag('patPFMETsTypeIcorrected'), 
                          #corrmetSrc = cms.InputTag('patPFMETsTypeIcorrected'),
                          #mvametSrc = cms.InputTag('patPFMETsTypeIcorrected')  
                          )
