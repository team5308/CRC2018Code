# 2018 off-season Code <5308 FAFA>
 
## 项目结构
    src
     |
     | -- OI.cpp/h
     | -- Robot.cpp/h
     | -- RobotMap.cpp/h
     |
     | -- Commands
     |      | 
     |      | -- AutonomousCommand.cpp/h
     |      | -- CompressorOffCommand.cpp/h
     |      | -- CompressorOffCommand.cpp/h
     |      | -- DrivingCommand.cpp/h
     |      | -- HangingCommand.cpp/h
     |      | -- IntakeCommand.cpp/h
     |      | -- IntakeInCommand.cpp/h
     |      | -- IntakeOutCommand.cpp/h
     |      | -- SolenoidCommand1.cpp/h
     |      | -- SolenoidCommand2.cpp/h
     |      | -- SolenoidCommand3.cpp/h
     |      \ -- SolenoidCommand4.cpp/h
     |
     \ -- Subsystems
            |
            | -- AutonomousSystem.cpp/h
            | -- DrivingSystem.cpp/h
            | -- HangingSystem.cpp/h
            | -- IntakeSystem.cpp/h
            \ -- PneumaticsSystem.cpp/h

### 文件作用

#### AutonomusCommand .cpp / .h 
自动命令， 在此更改自动对象  

函数原型：void AutonomousCommand::Execute(void);  
使用方法：
```
    void AutonomusCommand::Excute()
    {
        /*
            @targetMode 
            3 mode : switch, scale, crossline
            modify this varible to change auto mode
        */
        std::String targetmode = "scale";

        /*
            @GameDate Init
            function: store specific Game Data of direction of switch/scale
        */
        std::String GameData = "LLL";

        // get specific data from driverstation
        GameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

        if(targetMode == "switch") //do switch 
        {
            if(GameData[0] == 'L')  // if our switch is on left 
            {
                /*
                    call corresponding auto function 
                    all avaiable functions on AutonomousSystem Doc
                */
                printf("left switch 2 case\n");
                Robot::autonomusSystem->leftSwitch2Case(); 
            }
            else // if our switch is on right
            {
                /*
                    call corresponding auto function 
                    all avaiable functions on AutonomousSystem Doc
                */
                printf("right switch 2 case\n");
                Robot::autonomusSystem->rightSwitch2Case(); 
            }
        }
        else if(targetmode == "scale") //do scale thing
        {
            if(GameData[1] == 'L')  // if our scale is on left 
            {
                /*
                    call corresponding auto function 
                    all avaiable functions on AutonomousSystem Doc
                */
                printf("left scale\n");
                Robot::autonomusSystem->leftScale(); 
            }
            else // if our scale is on right
            {
                /*
                    call corresponding auto function 
                    all avaiable functions on AutonomousSystem Doc
                */
                printf("right scale\n");
                Robot::autonomusSystem->rightScale(); 
            } 
        }
        else //default mode (current cross line)
        {
            printf("cross line\n");
            Robot::autonomusSystem->setRunDfsMode(750, true);
        }
    }
```