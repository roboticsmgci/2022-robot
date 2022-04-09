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

    periods = 0;
    period_target = m_duration * 50;

    m_intake->Stop();

}

void IntakeMove::Execute(){

    m_intake->Rotate(m_speed);
    periods++;

}

bool IntakeMove::IsFinished(){

    return (periods >= period_target);

}

void IntakeMove::End(bool){

    m_intake->Stop();
    
}
