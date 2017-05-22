These are the low-level launch files that control the bringup of the trajectory and state relay nodes of `fanuc_driver`.

It is unlikely that you want to use these directly.

If possible, please use the wrapper launch files (`robot_interface_streaming_X.launch` and `robot_state_visualize_X.launch`) that are distributed with the robot support packages for the particular robot variant that you'd like to use.

For robots that are not yet supported, see `fanuc_m10ia_support/launch` for examples on how to make use of the launch files in this folder.
