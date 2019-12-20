# fanuc_driver


## Overview

This package is part of the [ROS-Industrial][] program. See the main [fanuc][] page on the ROS wiki for more information on usage.


## Performance

This is a minimal implementation of a ROS driver for Fanuc controllers and could be improved quite significantly.
This is especially true for the motion performance, both in terms of maximum attainable robot velocity as well as in the trade-off between smoothness and accuracy (or: path / trajectory reproduction).

With the current understanding of Fanuc controller internals it would appear that the trade-off between motion smoothness and trajectory reproduction accuracy (ie: `CNT`) will *always* be a limiting factor when not using options such as Stream Motion (J519).

Dense trajectories will cause significant slowdown of the robot leading to total path execution duration significantly exceeding the specified timestamps.
Coarse trajectories will lead to inaccurate motions, but higher maximum robot velocity attained.

The current implementation (with a single point buffer and a minimum TP program to execute the motion) does not permit the controller to make use of its look-ahead functionality, which severely bottlenecks it and leads to suboptimal motion in almost all cases (in terms of velocity and continuity: the robot will still reach the commanded position(s), depending on the CNT value configured).

This driver is therefore better suited to pick-and-place type of applications (ie: discrete motions in which the goal positions are more important than the path itself) and less for applications that require accurate control over all aspects of the motion at all times (ie: continuous applications in which the path itself is as-important or more important than the final destination).


## Limitations

The main limitation of this driver is in how it overrides joint velocities requested by ROS to a hard-coded value.

Users interested in using commanded joint velocity could take a look at [fanuc_driver_exp][], but certain limitations remain.
Refer to the readme of that package for information on performance and features.



[ROS-Industrial]: http://wiki.ros.org/Industrial
[fanuc]: http://wiki.ros.org/fanuc
[fanuc_driver_exp]: https://github.com/gavanderhoorn/fanuc_driver_exp
