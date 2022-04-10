#include "commands/common/ArmLower.h"

#include "commands/ArmMove.h"


ArmLower::ArmLower(Arm& arm): m_arm(&arm){

    SetName("ArmLower");
    AddCommands(
        // Break tape and lower
<<<<<<< HEAD
        ArmMove(arm, -0.3, 0.5),
=======
        ArmMove(arm, -0.3, 0.4),
>>>>>>> e07964651156f77bd528c6629344e66bdcff07d2
        // Stop, let it drop by gravity
        ArmMove(arm, 0, 0.2)
    );

}
