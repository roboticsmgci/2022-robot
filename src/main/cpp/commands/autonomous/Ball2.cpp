#include "commands/autonomous/Ball2.h"

#include "commands/common/ArmLower.h"
#include "commands/common/GrabBall.h"
#include "commands/common/ScoreBall.h"

#include "commands/TankMove.h"
#include "commands/TankMoveGyro.h"
#include "commands/TankTurn.h"
#include "commands/IntakeMove.h"


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
        IntakeMove(intake, -1, 0.3),
        // Taxi out
        TankMoveGyro(drivetrain, -1.4, 0.63),
        // Break tape
        ArmLower(arm),
        // Turn around to face the ball
        TankTurn(drivetrain, 180),
        // Get the ball
        GrabBall(arm, drivetrain, intake),
        // Turn back around to face hub
        TankTurn(drivetrain, 180),
        // Move towards hub
        TankMove(drivetrain, 1.9, 0.63),
        // Score ball
        ScoreBall(arm, drivetrain, intake)
    );

}
