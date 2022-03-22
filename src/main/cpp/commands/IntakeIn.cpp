#include "commands/IntakeIn.h"

#include "Robot.h"
#include "RobotContainer.h"

IntakeIn::IntakeIn(Intake& intake) : m_intake(&intake){
    SetName("IntakeIn");
    AddRequirements({m_intake});
}

void IntakeIn::Initialize(){
    m_intake->Rotate(speed);
}

void IntakeIn::End(bool){
    m_intake->Stop();
}
