#include "commands/common/GrabBall.h"

#include <frc2/command/ParallelCommandGroup.h>

<<<<<<< HEAD
#include "commands/IntakeMove.h"
#include "commands/TankMove.h"


GrabBall::GrabBall(
        Drivetrain& drivetrain, 
        Intake& intake):
=======
#include "commands/ArmMove.h"
#include "commands/IntakeMove.h"
#include "commands/TankMoveGyro.h"
#include "commands/TankRawMove.h"


GrabBall::GrabBall(
        Arm& arm,
        Drivetrain& drivetrain, 
        Intake& intake):
            m_arm(&arm),
>>>>>>> e07964651156f77bd528c6629344e66bdcff07d2
            m_drivetrain(&drivetrain),
            m_intake(&intake){

    SetName("GrabBall");
    AddCommands(
<<<<<<< HEAD
        // Move forward while intake in
        frc2::ParallelCommandGroup(
            TankMove(drivetrain, 0.5, 0.6),
            IntakeMove(intake, 0.5, 0.8))
=======
        ArmMove(arm, -0.15, 0.6),
        // Move forward while intake in
        frc2::ParallelCommandGroup(
            ArmMove(arm, -0.1, 1),
            TankRawMove(drivetrain, 0.5 * 1.1, 0.5 * 1, 1),
            IntakeMove(intake, 0.5, 1))
>>>>>>> e07964651156f77bd528c6629344e66bdcff07d2
    );

}
