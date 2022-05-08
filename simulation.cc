#include <iostream>

// Include files from Geant4 libraries

#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UImanager.hh"

// User defined classes

#include "construction.hh" // Build the detector and the sensors
#include "physics.hh"      // Physics list 
#include "action.hh"       // Define the particle gun and the actions

int main(int argc, char** argv)
{
  // DEFINE THE RUN MANAGER 

  G4RunManager *runManager = new G4RunManager();

  runManager -> SetUserInitialization(new MyDetectorConstruction());
  runManager -> SetUserInitialization(new MyPhysicsList());
  runManager -> SetUserInitialization(new MyActionInitialization());

  // ********************************
  // The following command has to be uncommented
  // only when the geometry of the detector, particles,
  // and Physics have been defined 

  runManager -> Initialize(); // ATTENTION HERE!

  // ********************************

  G4UIExecutive *ui         = new G4UIExecutive(argc,argv);
  G4VisManager  *visManager = new G4VisExecutive();

  visManager -> Initialize();

  G4UImanager *UImanager =  G4UImanager::GetUIpointer();

  // Commands feeded to the User Interface Manager
  
  UImanager -> ApplyCommand("/vis/open OGL");
  UImanager -> ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
  UImanager -> ApplyCommand("/vis/drawVolume");
  UImanager -> ApplyCommand("/vis/viewer/set/autoRefresh true");
  UImanager -> ApplyCommand("/vis/scene/add/trajectories smooth");
  UImanager -> ApplyCommand("/vis/scene/endOfEventAction accumulate");

  // Begin the session
  
  ui ->SessionStart();

  return 0;
}
