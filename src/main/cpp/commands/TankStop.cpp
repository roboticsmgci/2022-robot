#include "commands/TankStop.h"

TankStop::TankStop(
        Drivetrain& drivetrain, double duration):
            m_drivetrain(&drivetrain),
            m_duration(duration){

    SetName("TankStop");
    AddRequirements({m_drivetrain});
    
}

void TankStop::Initialize(){

    periods = 0;
    period_target = m_duration * 50;

    m_drivetrain->Drive(0, 0);

}

void TankStop::Execute(){

    m_drivetrain->Drive(0, 0);
    periods++;

}

bool TankStop::IsFinished(){

    return (periods >= period_target);

}

void TankStop::End(bool){

    m_drivetrain->Drive(0, 0);
    
}
