// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TankDrive.h"

#include "subsystems/Drivetrain.h"

TankDrive::TankDrive(
    Drivetrain* subsystem, std::function<double()> leftboy,
                            std::function<double()> rightboy)
    : m_drive(subsystem),
    mLeftBoy(leftboy), mRightBoy(rightboy)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void TankDrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() 
{
  m_drive->TankDrive(mLeftBoy(), mRightBoy());
}

// Called once the command ends or is interrupted.
void TankDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool TankDrive::IsFinished() {
  return false;
}
