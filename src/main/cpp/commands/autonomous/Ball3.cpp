#include "commands/autonomous/Ball3.h"

#include "commands/ArmMove.h"
// #include "commands/DriveMove.h"
// #include "commands/DriveTurn.h"
#include "commands/IntakeMove.h"

#include "commands/common/ArmLower.h"
#include "commands/common/GrabBall.h"
#include "commands/common/ScoreBall.h"


Ball3::Ball3(
        Arm& arm,
        Drivetrain& drivetrain,
        Intake& intake): 
            m_arm(&arm),
            m_drivetrain(&drivetrain),
            m_intake(&intake){

    SetName("Ball3");
    AddCommands(
        // Remove ball
        IntakeMove(intake, 1, 0.2),
        // Taxi out
        // TankMove(drivetrain, -0.5),
        // Break tape
        ArmLower(arm),
        // Turn to face ball 1
        // DriveTurn(drivetrain, -133),
        // Move to ball 1
        // TankMove(drivetrain, 2),
        // Get ball 1
        GrabBall(drivetrain, intake),
        // Turn to face ball 2
        // DriveTurn(drivetrain, )
        // DriveTurn(drivetrain, 180),
        // Move towards hub
        // TankMove(drivetrain, 3),
        // Score ball
        ScoreBall(arm, drivetrain, intake)
    );

}
