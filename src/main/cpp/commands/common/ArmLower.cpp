#include "commands/common/ArmLower.h"

#include "commands/ArmMove.h"


ArmLower::ArmLower(Arm& arm): m_arm(&arm){

    SetName("ArmLower");
    AddCommands(
        // Break tape and lower
        ArmMove(arm, -0.3, 0.3),
        // Stop, let it drop by gravity
        ArmMove(arm, 0, 0.2)
    );

}
