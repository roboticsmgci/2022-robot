#include "commands/ArmDown.h"

#include <utility>

#include "Robot.h"

ArmDown::ArmDown(Arm& arm): m_arm(&arm){
    
    SetName("ArmDown");
    AddRequirements({m_arm});

}

void ArmDown::Initialize(){
    m_arm->Stop();
}

void ArmDown::Execute() {
    m_arm->Rotate(speed);
}

void ArmDown::End(bool) {
    m_arm->Stop();
}
