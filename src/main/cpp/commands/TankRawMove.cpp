#include "commands/TankRawMove.h"


TankRawMove::TankRawMove(
        Drivetrain& drivetrain,
        double speedl,
        double speedr,
        double duration):
            m_drivetrain(&drivetrain),
            m_speedl(speedl),
            m_speedr(speedr),
            m_duration(duration){

    SetName("TankRawMove");
    AddRequirements({m_drivetrain});
    
}

void TankRawMove::Initialize(){

    periods = 0;
    periodTarget = m_duration * 50;

    m_drivetrain->Drive(0, 0);

}

void TankRawMove::Execute(){

    m_drivetrain->Drive(m_speedl, m_speedr);
    periods++;

}

bool TankRawMove::IsFinished(){

    return (periods >= periodTarget);

}

void TankRawMove::End(bool){

    m_drivetrain->Drive(0, 0);
    
}
