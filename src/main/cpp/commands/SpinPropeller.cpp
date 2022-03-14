#include "commands/SpinPropeller.h"

#include "Robot.h"
#include "RobotContainer.h"

SpinPropeller::SpinPropeller(Propeller& propeller) : m_propeller(&propeller){
    SetName("SpinPropeller");
    AddRequirements({m_propeller});
}

// Called just before this Command runs the first time
void SpinPropeller::Initialize() {
  m_propeller->Rotate();
}

// Called once after isFinished returns true
void SpinPropeller::End(bool) {
    m_propeller->Stop();
}