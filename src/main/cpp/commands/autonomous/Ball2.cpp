#include "commands/autonomous/Ball2.h"

#include "commands/ArmMove.h"
// #include "commands/DriveMove.h"
// #include "commands/DriveTurn.h"
#include "commands/IntakeMove.h"

#include "commands/common/ArmLower.h"
#include "commands/common/GrabBall.h"
#include "commands/common/ScoreBall.h"


Ball2::Ball2(
        Arm& arm,
        Drivetrain& drivetrain,
        Intake& intake): 
            m_arm(&arm),
            m_drivetrain(&drivetrain),
            m_intake(&intake){

    SetName("Ball2");
    AddCommands(
        // Remove ball
        IntakeMove(intake, 1, 0.2),
        // Taxi out
        // TankMove(drivetrain, -2),
        // Break tape
        ArmLower(arm),
        // Turn around to face the ball
        // DriveTurn(drivetrain, 180),
        // Get the ball
        GrabBall(drivetrain, intake),
        // Turn back around to face hub
        // DriveTurn(drivetrain, 180),
        // Move towards hub
        // TankMove(drivetrain, 3),
        // Score ball
        ScoreBall(arm, drivetrain, intake)
    );

}
