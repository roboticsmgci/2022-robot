#include "commands/IntakeMove.h"


IntakeMove::IntakeMove(
        Intake& intake,
        double speed,
        double duration):
            m_intake(&intake),
            m_speed(speed),
            m_duration(duration){

    SetName("IntakeMove");
    AddRequirements({m_intake});
    
}

void IntakeMove::Initialize(){

    m_periods = 0;
    m_periodTarget = m_duration * 50;

    m_intake->Stop();

}

void IntakeMove::Execute(){

    m_intake->Rotate(m_speed);
    m_periods++;

}

bool IntakeMove::IsFinished(){

    return (m_periods >= m_periodTarget);

}

void IntakeMove::End(bool){

    m_intake->Stop();
    
}
