#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
  // This is the way in which we define the material of the world
  G4NistManager *nist = G4NistManager::Instance();
  G4Material *worldMat = nist -> FindOrBuildMaterial("G4_AIR");

  // Now we need to define the volume of the world
  // SOLID WORLD BOX
  G4Box *solidWorld = new G4Box("solidWorld", 0.5*m,0.5*m,0.5*m);
  // The width highth and depth are expressed in meters
  // The header file for system of units must be included

  // Now we generate the Logical volume
  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
  // Definition of the physical world
  G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true);
  // PARAMETERS
  // [1] : Rotation. We want a system at rest so we put 0
  // [2] : Coordinate system of the origin of our system detector.
  // [3] : Name of the physical volume
  // [last] : Find if there are overlaps between regions of the physical worlds
  

  return physWorld;  

}
