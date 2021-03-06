// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "IntakeSystem.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include  <iostream>

using namespace std;
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

IntakeSystem::IntakeSystem() : frc::Subsystem("IntakeSystem") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    quadratureEncoder1 = RobotMap::intakeSystemQuadratureEncoder1;
    spark2 = RobotMap::intakeSystemSpark2;
    pIDController2 = RobotMap::intakeSystemPIDController2;
    victorSP1 = RobotMap::drivingSystemVictorSPX2;
    victorSP2 = RobotMap::drivingSystemVictorSPX4;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void IntakeSystem::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void IntakeSystem::Periodic() {
	//Intake上下，不要一起按！！！
	frc::Joystick Joystick2(1);
	while(Joystick2.GetRawButton(7)){
		IntakeSystem::spark2->Set(1);
	}
	while(Joystick2.GetRawButton(8)){
		IntakeSystem::spark2->Set(-1);
	}
	IntakeSystem::spark2->Set(0);
}

void IntakeSystem::In(){
	IntakeSystem::victorSP1->Set(1);
	IntakeSystem::victorSP2->Set(-1);
}

void IntakeSystem::Out(){
	IntakeSystem::victorSP1->Set(-0.7);
	IntakeSystem::victorSP2->Set(0.7);
}

void IntakeSystem::OutSlow() {
	IntakeSystem::victorSP1->Set(-0.5);
	IntakeSystem::victorSP2->Set(0.5);
}

void IntakeSystem::Stop(){
	IntakeSystem::victorSP1->Set(0);
	IntakeSystem::victorSP2->Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

