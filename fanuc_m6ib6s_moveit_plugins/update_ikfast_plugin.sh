rosrun moveit_kinematics create_ikfast_moveit_plugin.py --search_mode=OPTIMIZE_MAX_JOINT --srdf_filename=fanuc_m6ib6s.srdf --robot_name_in_srdf=fanuc_m6ib6s --moveit_config_pkg=fanuc_m6ib6s_moveit_config fanuc_m6ib6s manipulator fanuc_m6ib6s_moveit_plugins base_link tool0 /home/joao/catkin_ws/src/fanuc_m6ib6s_moveit_plugins/src/fanuc_m6ib6s_manipulator_ikfast_solver.cpp