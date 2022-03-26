#include "commands/ArmUp.h"

#include <utility>

#include "Robot.h"

ArmUp::ArmUp(Arm& arm): m_arm(&arm){
    
    SetName("ArmUp");
    AddRequirements({m_arm});

}

void ArmUp::Initialize(){
    m_arm->Stop();
}

void ArmUp::Execute() {
    m_arm->Rotate(speed);
}

void ArmUp::End(bool) {
    m_arm->Stop();
}
