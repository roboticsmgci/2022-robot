#include "commands/autonomous/OnlyTaxi.h"

// #include "commands/DriveMove.h"
#include "commands/IntakeMove.h"


OnlyTaxi::OnlyTaxi(
        Drivetrain& drivetrain,
        Intake& intake): 
            m_drivetrain(&drivetrain),
            m_intake(&intake){

    SetName("OnlyTaxi");
    AddCommands(
        // Remove ball
        IntakeMove(intake, 1, 0.2)
        // Taxi out
        // TankMove(drivetrain, -2)
    );

}
