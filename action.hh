#ifndef ACTION_HH
#define ACTION_HH

// Geant 4 include

#include "G4VUserActionInitialization.hh"

// User defined classes include

#include "generator.hh"

// Class definition - declaration

class MyActionInitialization : public  G4VUserActionInitialization
{
public:
  MyActionInitialization();
  ~MyActionInitialization();

  virtual void Build() const;
};

#endif
