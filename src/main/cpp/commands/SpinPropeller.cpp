#include "commands/SpinPropeller.h"

#include "Robot.h"

SpinPropeller::SpinPropeller(Propeller& propeller) : m_propeller(&propeller){
    SetName("SpinPropeller");
    AddRequirements({m_propeller});
}

// Called just before this Command runs the first time
void SpinPropeller::Initialize() {
  m_propeller->Rotate();
}

// Make this return true when this Command no longer needs to run execute()
bool SpinPropeller::IsFinished() {
  return false;
}

// Called once after isFinished returns true
void SpinPropeller::End(bool) {
    m_propeller->Stop();
}