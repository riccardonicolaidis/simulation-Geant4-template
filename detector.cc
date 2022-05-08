#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector()
{}

// Introduction of the sensitive detector informations
G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROHist)
{
  G4Track *track = aStep -> GetTrack();
  track -> SetTrackStatus(fStopAndKill);

  G4StepPoint *preStepPoint = aStep -> GetPreStepPoint();    // when photon enters the detector
  G4StepPoint *postStepPoint = aStep -> GetPostStepPoint();  // when the photon exits the detector

  G4ThreeVector posPhoton = preStepPoint -> GetPosition();
  
  const G4VTouchable *touchable = aStep -> GetPreStepPoint() -> GetTouchable();
  G4int copyNo = touchable -> GetCopyNumber();

  G4VPhysicalVolume *physVol = touchable -> GetVolume();
  G4ThreeVector posDetector = physVol -> GetTranslation();

  G4cout << "Detector pos:  " << posDetector << "  Photon pos:  " << posPhoton << "  Copy number:  " <<  copyNo << G4endl;

  return true;
}

