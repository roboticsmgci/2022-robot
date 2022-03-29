#include "commands/IntakeYeet.h"

#include "Robot.h"
#include "RobotContainer.h"

IntakeYeet::IntakeYeet(Intake& intake) : m_intake(&intake){
    SetName("IntakeYeet");
    AddRequirements({m_intake});
}

void IntakeYeet::Initialize(){
    m_intake->Stop();
}

void IntakeYeet::Execute() {
    m_intake->Rotate(speed);
}

void IntakeYeet::End(bool){
    m_intake->Stop();
}
