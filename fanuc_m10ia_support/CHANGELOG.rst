^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package fanuc_m10ia_support
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.2.0 (2014-02-19)
------------------
* first Hydro release.
* deprecate `fanuc_assets`, introduce `fanuc_resources`
* cleanup of all CMakeLists and package manifests:

  * closing keywords should have empty parenthesis (`#62 <https://github.com/ros-industrial/fanuc/issues/62>`_)
  * update CMakeLists to follow Catkin CMake coding standards (`#62 <https://github.com/ros-industrial/fanuc/issues/62>`_)
  * list run_depends in alphabetical order (`#62 <https://github.com/ros-industrial/fanuc/issues/62>`_)
  * add missing xacro run depends (`#67 <https://github.com/ros-industrial/fanuc/issues/67>`_)
  * add missing depends to support pkgs (`#64 <https://github.com/ros-industrial/fanuc/issues/64>`_)
  * ArmNav and support pkgs are architecture independent.
  * update model specifications with available information.

* introduction of roslaunch testing of launch files:

  * move roslaunch to build_depend (`#76 <https://github.com/ros-industrial/fanuc/issues/76>`_)
  * test launchfiles with roslaunch (`#30 <https://github.com/ros-industrial/fanuc/issues/30>`_)

* prefix include elements with xacro ns (`#38 <https://github.com/ros-industrial/fanuc/issues/38>`_)
* for a complete list of changes see the `commit log for 0.2.0 <https://github.com/ros-industrial/fanuc/compare/0.1.1...0.2.0>`_

0.1.1 (2013-09-27)
------------------
* fixed missing dependency

0.1.0 (2013-09-16)
------------------
* initial Groovy release
