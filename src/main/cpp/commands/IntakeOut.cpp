#include "commands/IntakeOut.h"

#include "Robot.h"
#include "RobotContainer.h"

IntakeOut::IntakeOut(Intake& intake) : m_intake(&intake){
    SetName("IntakeOut");
    AddRequirements({m_intake});
}

void IntakeOut::Initialize(){
    m_intake->Rotate(-speed);
}

void IntakeOut::End(bool){
    m_intake->Stop();
}
