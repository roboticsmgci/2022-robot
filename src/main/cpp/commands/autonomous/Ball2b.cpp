#include "commands/autonomous/Ball2b.h"

#include "commands/common/ArmLower.h"
#include "commands/common/GrabBall.h"
#include "commands/common/ScoreBall.h"

#include "commands/TankMoveGyro.h"
#include "commands/TankTurn.h"
#include "commands/IntakeMove.h"


Ball2b::Ball2b(
        Arm& arm,
        Drivetrain& drivetrain,
        Intake& intake): 
            m_arm(&arm),
            m_drivetrain(&drivetrain),
            m_intake(&intake){

    SetName("Ball2b");
    AddCommands(
        TankMoveGyro(drivetrain, 0.6, 0.5),
        GrabBall(arm, drivetrain, intake),
        TankMoveGyro(drivetrain, -2.35, 0.5),
        TankTurn(drivetrain, 158),
        TankMoveGyro(drivetrain, 0.25, 0.45),
        // Score ball
        ScoreBall(arm, drivetrain, intake)
    );

}
