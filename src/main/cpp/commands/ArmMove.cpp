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

    periods = 0;
    period_target = m_duration * 50;

    m_arm->Stop();

}

void ArmMove::Execute(){

    m_arm->Rotate(m_speed);
    periods++;

}

bool ArmMove::IsFinished(){

    return (periods >= period_target);

}

void ArmMove::End(bool){

    m_arm->Stop();
    
}
