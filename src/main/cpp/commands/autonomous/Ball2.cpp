#include "commands/autonomous/Ball2.h"

#include "commands/ArmMove.h"
#include "commands/TankMove.h"
#include "commands/TankMoveGyro.h"
#include "commands/TankTurn.h"
#include "commands/IntakeMove.h"

#include "commands/TankStop.h"

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
        IntakeMove(intake, -1, 0.3),
        // Taxi out
        TankMoveGyro(drivetrain, -1.3, 0.6),
        // Break tape
        ArmLower(arm),
        // Turn around to face the ball
        TankTurn(drivetrain, 165),
        // Get the ball
        GrabBall(drivetrain, intake),
        // Turn back around to face hub
        TankTurn(drivetrain, -165),
        TankStop(drivetrain, 0.2),
        // Move towards hub
        TankMoveGyro(drivetrain, 1.8, 0.6),
        // Score ball
        ScoreBall(arm, drivetrain, intake)
    );

}
