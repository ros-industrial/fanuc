# Fanuc

[![Build Status: CI - ROS 1](https://github.com/ros-industrial/fanuc/actions/workflows/ci_ros1.yml/badge.svg?branch=melodic-devel)](https://github.com/ros-industrial/fanuc/actions/workflows/ci_ros1.yml)
[![Github Issues](https://img.shields.io/github/issues/ros-industrial/fanuc.svg)](http://github.com/ros-industrial/fanuc/issues)

[![license - apache 2.0](https://img.shields.io/:license-Apache%202.0-yellowgreen.svg)](https://opensource.org/licenses/Apache-2.0)
[![license - bsd 3 clause](https://img.shields.io/:license-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)

[![support level: community](https://img.shields.io/badge/support%20level-community-lightgray.svg)](http://rosindustrial.org/news/2016/10/7/better-supporting-a-growing-ros-industrial-software-platform)


[ROS-Industrial][] Fanuc meta-package. See the [ROS wiki][] page for more information.

The [fanuc_experimental][] repository contains additional packages.


## Contents

Branch naming follows the ROS distribution they are compatible with. `-devel` branches may be unstable. Releases are made from the distribution branches (`hydro`, `indigo`, `kinetic`).

Older releases may be found in the Github mirror of the old ROS-Industrial [subversion repository][].

### MoveIt configurations

All provided MoveIt configurations were moved to the [moveit_cfgs](/moveit_cfgs) subdirectory in [#322][].
These packages can be used as-if they were still located in the root of the repository.
Catkin will still be able to locate them.


## Status

The packages in this repository are *community supported*.
This means they do not get support from the OEM, nor from the ROS-Industrial consortia directly (see also the `support level` badge at the top of this page).

Maintenance and development is on a best-effort basis and depends on volunteers.

If you are looking for official support, ask your local Fanuc branch office for their version of the ROS 1 fanuc driver.


## Installation

Binary packages are available for ROS Kinetic, but not all packages have been released.

For installation on newer ROS versions, refer to the *Building* section below.

The following packages have been released (as of 2019-10-09):

 - `fanuc_driver`
 - `fanuc_resources`
 - all support packages (ie: `fanuc_*_support`)

They can be installed using `apt` (on Ubuntu and Debian).

The other packages (MoveIt configurations and plugins) can be built from sources (see the *Building* section below).

### Example

To install `fanuc_m10ia_support` on Ubuntu Xenial for ROS Kinetic (after having followed the normal ROS Kinetic installation tutorial):

```
sudo apt install ros-kinetic-fanuc-m10ia-support
```

This would install `ros-kinetic-fanuc-resources` and `ros-kinetic-fanuc-driver` as well (and all their dependencies).


## Building

### On newer (or older) versions of ROS

Building the packages on newer (or older) versions of ROS is in most cases possible and supported. For example: building the packages in this repository on Ubuntu Bionic/ROS Melodic or Ubuntu Focal/ROS Noetic systems is supported. This will require creating a Catkin workspace, cloning this repository, installing all required dependencies and finally building the workspace.

### Catkin tools

It is recommended to use [catkin_tools][] instead of the default [catkin][] when building ROS workspaces. `catkin_tools` provides a number of benefits over regular `catkin_make` and will be used in the instructions below. All packages can be built using `catkin_make` however: use `catkin_make` in place of `catkin build` where appropriate.

### Building the packages

The following instructions assume that a [Catkin workspace][] has been created at `$HOME/catkin_ws` and that the *source space* is at `$HOME/catkin_ws/src`. Update paths appropriately if they are different on the build machine.

These instructions build the `melodic-devel` branch on a ROS Melodic system:

```bash
# change to the root of the Catkin workspace
$ cd $HOME/catkin_ws

# retrieve the latest development version of fanuc. If you'd rather
# use the latest released version, replace 'melodic-devel' with 'kinetic'
# NOTE: 'melodic-devel' is compatible with ROS Noetic. 'kinetic' may not be
$ git clone -b melodic-devel https://github.com/ros-industrial/fanuc.git src/fanuc

# check build dependencies. Note: this may install additional packages,
# depending on the software installed on the machine
$ rosdep update

# be sure to change 'melodic' to whichever ROS release you are using
$ rosdep install --from-paths src/ --ignore-src --rosdistro melodic

# build the workspace (using catkin_tools)
$ catkin build
```

### Activating the workspace

Finally, activate the workspace to get access to the packages just built:

```bash
$ source $HOME/catkin_ws/devel/setup.bash
```

At this point all packages should be usable (ie: `roslaunch` should be able to auto-complete package names starting with `fanuc_..`). In case the workspace contains additional packages (ie: not from this repository), those should also still be available.


## Installation and usage

Refer to [Working With ROS-Industrial Robot Support Packages][] for information on how to use the files provided by the robot support and MoveIt configuration packages. See also the other pages on the [ROS wiki][].

Refer to the [tutorials][] for information on installation and configuration of the controller-specific software components.


## Disclaimer

The author of these packages is not affiliated with FANUC Corporation in any way.
All trademarks and registered trademarks are property of their respective owners, and company, product and service names mentioned in this readme or appearing in source code or other artefacts in this repository are used for identification purposes only.
Use of these names does not imply endorsement by FANUC Corporation.



[ROS-Industrial]: http://wiki.ros.org/Industrial
[ROS wiki]: http://wiki.ros.org/fanuc
[fanuc_experimental]: https://github.com/ros-industrial/fanuc_experimental
[subversion repository]: https://github.com/ros-industrial/swri-ros-pkg
[#322]: https://github.com/ros-industrial/fanuc/pull/322
[Catkin workspace]: http://wiki.ros.org/catkin/Tutorials/create_a_workspace
[catkin]: http://wiki.ros.org/catkin
[catkin_tools]: https://catkin-tools.readthedocs.io/en/latest
[Working With ROS-Industrial Robot Support Packages]: http://wiki.ros.org/Industrial/Tutorials/WorkingWithRosIndustrialRobotSupportPackages
[tutorials]: http://wiki.ros.org/fanuc/Tutorials
