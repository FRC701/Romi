/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TankDrive.h"

#include "subsystems/Drivetrain.h"


TankDrive::TankDrive(
    Drivetrain* subsystem, std::function<double()> left,
                    std::function<double()> right)
    : m_drive{subsystem},
      mLeft(left), mRight(right) 
{
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void TankDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() 
{
  m_drive->TankDrive(mLeft(), mRight());
}

// Called once the command ends or is interrupted.
void TankDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool TankDrive::IsFinished() { return false; }