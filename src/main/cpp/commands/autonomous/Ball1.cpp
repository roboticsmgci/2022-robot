#include "commands/autonomous/Ball1.h"

#include "commands/TankMove.h"
#include "commands/IntakeMove.h"


Ball1::Ball1(
        Drivetrain& drivetrain,
        Intake& intake): 
            m_drivetrain(&drivetrain),
            m_intake(&intake){

    SetName("Ball1");
    AddCommands(
        // Remove ball
        IntakeMove(intake, -1, 0.3),
        // Taxi out
        TankMove(drivetrain, -3, 0.5)
    );

}
