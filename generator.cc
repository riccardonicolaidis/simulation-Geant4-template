#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
  // One primary vertex per event created 
  fParticleGun = new G4ParticleGun(1);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
  delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
  G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName = "proton";
  G4ParticleDefinition *particle = particleTable->FindParticle("proton");

  G4ThreeVector pos(0.,0.,0.); // Position at which particle is generated
  G4ThreeVector mom(0.,0.,1.); // Direction of the momentum of the particle

  fParticleGun -> SetParticlePosition(pos);
  fParticleGun -> SetParticleMomentumDirection(mom);
  fParticleGun -> SetParticleMomentum(100.*GeV);
  fParticleGun -> SetParticleDefinition(particle);

  fParticleGun -> GeneratePrimaryVertex(anEvent);

  
}
