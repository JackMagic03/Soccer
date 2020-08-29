# create libraries
add_library
(
	Libraries 
		Params/params.hpp

		Imu/mors_imu.hpp Imu/mors_imu.cpp Imu/mors_imuHandler.hpp Imu/mors_imuHandler.cpp

		Joint/mors_joints.hpp Joint/mors_joints.cpp Joint/mors_drive.hpp Joint/mors_drive.cpp

		Line/mors_line.hpp Line/mors_line.cpp Line/mors_lineHandler.hpp Line/mors_lineHandler.cpp

		Pid/mors_pid.hpp Pid/mors_pid.cpp

		Pixy/mors_pixyHandler.hpp Pixy/mors_pixyHandler.cpp
		
		Planner/mors_planner.hpp Planner/mors_attackPlanner.hpp Planner/mors_attackPlanner.cpp Planner/mors_defensePlanner.hpp Planner/mors_defensePlanner.cpp
)