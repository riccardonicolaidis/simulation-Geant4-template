#include "run.hh"

MyRunAction::MyRunAction()
{}

MyRunAction::~MyRunAction()
{}

// Now we want to think about the informations we want to store into the ROOT files

void MyRunAction::BeginOfRunAction(const G4Run* )
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man -> OpenFile("output.root"); // Open file
    
    // Ntuple creation 
    man -> CreateNtuple("Hits","Hits");
    man -> CreateNtupleIColumn("fEvent");
    man -> CreateNtupleDColumn("fX");
    man -> CreateNtupleDColumn("fY");
    man -> CreateNtupleDColumn("fZ");
    man -> FinishNtuple(0); // Finish the 0 Ntuple
}

void MyRunAction::EndOfRunAction(const G4Run* )
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    man -> Write(); // Write the file IMPORTANT
    man -> CloseFile("output.root"); // Close the file in the end
}