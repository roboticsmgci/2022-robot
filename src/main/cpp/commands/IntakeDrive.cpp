#include "commands/IntakeDrive.h"

#include "Robot.h"
#include "RobotContainer.h"

IntakeDrive::IntakeDrive(
        Intake& intake,
        double speed): 
            m_intake(&intake),
            m_speed(speed){

    SetName("IntakeDrive");
    AddRequirements({m_intake});

}

void IntakeDrive::Initialize(){
    m_intake->Stop();
}

void IntakeDrive::Execute() {
    m_intake->Rotate(m_speed);
}

void IntakeDrive::End(bool){
    m_intake->Stop();
}
