#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
  // This is the way in which we define the material of the world
  G4NistManager *nist = G4NistManager::Instance();

  // AEROGEL composed of H2O, SiO2, C
  G4Material *SiO2 = new G4Material("SiO2", 2.201*g/cm3, 2); // Define SiO2
  SiO2 -> AddElement(nist -> FindOrBuildElement("Si"), 1);   // Add element Si
  SiO2 -> AddElement(nist -> FindOrBuildElement("O"), 2);    // Add element O

  G4Material *H2O     = new G4Material("H2O",1.000*g/cm3, 2); // Define H2O
  H2O -> AddElement(nist -> FindOrBuildElement("H"),2);       // Add element H
  H2O -> AddElement(nist -> FindOrBuildElement("O"),1);       // Add element O

  G4Element *C = nist -> FindOrBuildElement("C");  // Define element C

  G4Material *Aerogel = new G4Material("Aerogel", 0.200*g/cm3,3); // Define material Aerogel
  Aerogel -> AddMaterial(SiO2, 62.5*perCent);                     // Add material SiO2
  Aerogel -> AddMaterial(H2O,37.4*perCent);                       // Add material  H2O
  Aerogel -> AddElement(C,0.1*perCent);                           // Add element C

  G4double energy[2]        = {1.239841939*eV/0.9 , 1.239841939*eV/0.2};
  G4double rindexAerogel[2] = {1.1 , 1.1};
  G4double rindexWorld[2] = {1.0 , 1.0};

  G4MaterialPropertiesTable *mptAerogel = new G4MaterialPropertiesTable();
  mptAerogel -> AddProperty("RINDEX", energy, rindexAerogel, 2);

  Aerogel -> SetMaterialPropertiesTable(mptAerogel);
  
  
  G4Material *worldMat = nist -> FindOrBuildMaterial("G4_AIR");

  G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
  mptWorld -> AddProperty("RINDEX", energy, rindexWorld, 2);

  worldMat -> SetMaterialPropertiesTable(mptWorld);
  // Now we need to define the volume of the world
  // SOLID WORLD BOX
  // The width highth and depth are expressed in meters
  // The header file for system of units must be included
  
  G4Box *solidWorld = new G4Box("solidWorld", 0.5*m,0.5*m,0.5*m);
  
  // Now we generate the Logical volume
  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
  
  // Definition of the physical world
  G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true);
  // PARAMETERS
  // [1] : Rotation. We want a system at rest so we put 0
  // [2] : Coordinate system of the origin of our system detector.
  // [3] : Name of the physical volume
  // [last] : Find if there are overlaps between regions of the physical worlds
  


  // RADIATOR DEFINITION
  // - Geometry
  // - logical volume
  // - physical volume
  // -- This is a daughter volume and therefore we need to specify the mother volume.

  G4Box *solidRadiator             = new G4Box("solidRadiator",0.4*m, 0.4*m, 0.01*m);
  G4LogicalVolume   *logicRadiator = new G4LogicalVolume(solidRadiator, Aerogel, "logicRadiator");
  G4VPhysicalVolume *physRadiator  = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.25*m), logicRadiator, "physRadiator", logicWorld, false, 0, true);
  
  
  // ***************************************************
  // SENSITIVE DETECTOR PART
  // ***************************************************
  
  G4Box *solidDetector = new G4Box("solidDetector", 0.005*m, 0.005*m, 0.01*m);    // Solid definition of detector
  logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector");  // Logic volume of the deterctor (see construction.hh "private members")

  for(G4int i = 0 ; i< 100; i++)
  {
    for(G4int j = 0 ; j < 100 ; j++)
    {
      G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(-0.5*m+(i+0.5)*m/100, -0.5*m+(j+0.5)*m/100, (0.5-0.01)*m), logicDetector, "physDetector", logicWorld, false, j+i*100, true);
    }
  }

  return physWorld;  

}


void MyDetectorConstruction::ConstructSDandField()
{
  MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
  logicDetector -> SetSensitiveDetector(sensDet);
}

