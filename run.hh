#ifndef RUN_HH
#define RUN_HH

#include "G4UserRunAction.hh"
#include "G4AnalysisManager.hh"
// This last include has to be used in order to use some root functions alrerady built in in Genat without having any root dependencies

class MyRunAction : public G4UserRunAction
{
public:
    MyRunAction();
    ~MyRunAction();

    virtual void BeginOfRunAction(const G4Run* );
    virtual void EndOfRunAction(const G4Run* );
    



};

#endif