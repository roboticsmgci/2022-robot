// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"

#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "rev/CANSparkMax.h"

#include "frc/SPI.h"

Drivetrain::Drivetrain() {

    // Restores factory defaults, does not persist
    // m_leftLeadMotor.RestoreFactoryDefaults();
    // m_rightLeadMotor.RestoreFactoryDefaults();
    // m_leftFollowMotor.RestoreFactoryDefaults();
    // m_rightFollowMotor.RestoreFactoryDefaults();

    // Inverts one side of the drivetrain
    m_leftLeadMotor.SetInverted(true);
    // m_leftFollowMotor.SetInverted(true);

    // Configures the motors to follow each other
    m_leftFollowMotor.Follow(m_leftLeadMotor);
    m_rightFollowMotor.Follow(m_rightLeadMotor);
   
    SetName("Drivetrain");
  
}

/*
It was a fine Thursday afternoon of March Break. The clouds were gone and it was a comfy 17C 
outside. However, Anthony said to start working on gyro code and SmartDashboard code. It was 
the beginning of the end.

C++ is very finicky, and the below code is the epitome of it. Back when I first started 
learning C++ for FRC, I had a very unusual encounter. One day, I had written some simple code
to learn about CLI based IO (i.e. cout, cin). It did not work. The next day, I consulted a
friend knowledgeable in C++. Lo and behold, the code worked, and I didn't change anything.
The same day, I tested some WPILib stuff and saved my work. Aaaaand then, the next day, it 
broke. I had not change a single letter.

My experience with working with gyro and SmartDashboard closely mimicked the story above. As
they say, history repeats itself. The following code broke, worked, and broke without any
indication of the cause. I implore the Gacha Gods to let it work more often than not.

So, does it work? Yes*

The asterisk after "yes" would symbolize a condition thats written in small print, but it
reminded me of another annoying part of C++: pointers. If you ever encounter a pointer in
this code and found the need to troubleshoot, I wish you best of luck.
*/

void Drivetrain::Log() {
    frc::SmartDashboard::PutNumber("Gyro", m_navX.GetYaw());
}

void Drivetrain::Periodic() {
    // Implementation of subsystem periodic method goes here.
    Log();
}

void Drivetrain::Drive(double left, double right) {
    m_robotDrive.TankDrive(left, right);
}
