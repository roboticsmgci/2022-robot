#include "commands/ArmMove.h"


ArmMove::ArmMove(
        Arm& arm,
        double speed,
        double duration):
            m_arm(&arm),
            m_speed(speed),
            m_duration(duration){

    SetName("ArmMove");
    AddRequirements({m_arm});
    
}

void ArmMove::Initialize(){

    m_periods = 0;
    m_periodTarget = m_duration * 50;

    m_arm->Stop();

}

void ArmMove::Execute(){

    m_arm->Rotate(m_speed);
    m_periods++;

}

bool ArmMove::IsFinished(){

    return (m_periods >= m_periodTarget);

}

void ArmMove::End(bool){

    m_arm->Stop();
    
}
