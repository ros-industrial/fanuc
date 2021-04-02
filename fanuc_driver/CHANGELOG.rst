^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package fanuc_driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.5.1 (2021-04-02)
------------------
* bump min CMake version (`#309 <https://github.com/ros-industrial/fanuc/issues/309>`_).
* mark all IKFast plugins as deprecated (`#302 <https://github.com/ros-industrial/fanuc/issues/302>`_).
* disable gitattributes temporarily (`#299 <https://github.com/ros-industrial/fanuc/issues/299>`_).
* add note to readme about performance (`#295 <https://github.com/ros-industrial/fanuc/issues/295>`_).
* point to manifest for info on package contents (`#292 <https://github.com/ros-industrial/fanuc/issues/292>`_).
* add note to readme about limitations (`#283 <https://github.com/ros-industrial/fanuc/issues/283>`_).
* add comments to movesm TP program (`#280 <https://github.com/ros-industrial/fanuc/issues/280>`_).
* remove roslaunch version requirements as they're no longer needed (`#278 <https://github.com/ros-industrial/fanuc/issues/278>`_).
* for a complete list of changes see the `commit log for 0.5.1 <https://github.com/ros-industrial/fanuc/compare/0.5.0...0.5.1>`_.

0.5.0 (2019-09-25)
------------------
* no changes.
* for a complete list of changes see the `commit log for 0.5.0 <https://github.com/ros-industrial/fanuc/compare/0.4.4...0.5.0>`_.

0.4.4 (2018-01-22)
------------------
* add custom manifest tags to make package support level explicit.
* for a complete list of changes see the `commit log for 0.4.4 <https://github.com/ros-industrial/fanuc/compare/0.4.3...0.4.4>`_.

0.4.3 (2017-10-14)
------------------
* update comment for Pressure Abnormal safety signal in Karel sources.
* for a complete list of changes see the `commit log for 0.4.3 <https://github.com/ros-industrial/fanuc/compare/0.4.2...0.4.3>`_.

0.4.2 (2017-05-22)
------------------
* add readme to explain that low-level launch files should probably not be used directly.
* increase default Karel loop rate to 42 Hz (ref: `#203 <https://github.com/ros-industrial/fanuc/issues/203>`_).
* minor: remove 'irs_in_mtn' prototype from Karel library.
* add XML schema processing instruction (`#200 <https://github.com/ros-industrial/fanuc/issues/200>`_).
* for a complete list of changes see the `commit log for 0.4.2 <https://github.com/ros-industrial/fanuc/compare/0.4.1...0.4.2>`_.

0.4.1 (2016-06-17)
------------------
* minor: sort install targets in build scripts.
* remove roslaunch test dependencies (`#185 <https://github.com/ros-industrial/fanuc/issues/185>`_).
* for a complete list of changes see the `commit log for 0.4.1 <https://github.com/ros-industrial/fanuc/compare/0.4.0...0.4.1>`_.

0.4.0 (2015-10-11)
------------------
* first Indigo release.
* upgrade manifests to package format 2 (`#115 <https://github.com/ros-industrial/fanuc/issues/115>`_).
* general cleanup of XML files (launch, manifests, roslaunch tests, xacros).
* add ROS Index tags to package manifests (`#147 <https://github.com/ros-industrial/fanuc/issues/147>`_).
* document launch file arguments (`#165 <https://github.com/ros-industrial/fanuc/issues/165>`_).
* use multi-arg install rule instead of for-loop.
* for a complete list of changes see the `commit log for 0.4.0 <https://github.com/ros-industrial/fanuc/compare/0.3.2...0.4.0>`_.

0.3.2 (2015-04-19)
------------------
* abort on missing J23_factor param (`#152 <https://github.com/ros-industrial/fanuc/issues/152>`_).
* add readmes to all packages (`#153 <https://github.com/ros-industrial/fanuc/issues/153>`_).
* for a complete list of changes see the `commit log for 0.3.2 <https://github.com/ros-industrial/fanuc/compare/0.3.1...0.3.2>`_

0.3.1 (2015-01-21)
------------------
* no changes.
* for a complete list of changes see the `commit log for 0.3.1 <https://github.com/ros-industrial/fanuc/compare/0.3.0...0.3.1>`_

0.3.0 (2015-01-08)
------------------
* promote experimental packages for M-10iA, M-16iB, M-20iA, M-430iA and LR Mate 200iC to main repository.
* Karel driver updates:

  * explicit socket close on ABORT (`#27 <https://github.com/ros-industrial/fanuc/issues/27>`_)
  * improve use of Karel built-in routines and constants (math, IO, TP keys) (`#50 <https://github.com/ros-industrial/fanuc/issues/50>`_)
  * update translator directives and header documentation
  * update copyright notices and Karel library versions
  * introduce include dir
  * include trajectory relay program status in 'motion_possible' calculation (`#108 <https://github.com/ros-industrial/fanuc/issues/108>`_)
  * fixup use of underscore suffixes to convey routine & variable scope

* explicitly declare dependencies of roslaunch tests (`#70 <https://github.com/ros-industrial/fanuc/issues/70>`_).
* for a complete list of changes see the `commit log for 0.3.0 <https://github.com/ros-industrial/fanuc/compare/0.2.0...0.3.0>`_

0.2.0 (2014-02-19)
------------------
* first Hydro release.
* Karel driver updates:

  * cleanup variable scopes at program and routine level
  * allow runtime configuration of important settings (`#71 <https://github.com/ros-industrial/fanuc/issues/71>`_, `#8 <https://github.com/ros-industrial/fanuc/issues/8>`_, `#2 <https://github.com/ros-industrial/fanuc/issues/2>`_)
  * use controller Alarm Log to post ROS-I warnings and errors (`#73 <https://github.com/ros-industrial/fanuc/issues/73>`_)
  * fix faulty detection of controller operating mode (`#3 <https://github.com/ros-industrial/fanuc/issues/3>`_)

* make all directories lowercase (`#23 <https://github.com/ros-industrial/fanuc/issues/23>`_)
* cleanup of all CMakeLists and package manifests:

  * link to simple_message as well (`#59 <https://github.com/ros-industrial/fanuc/issues/59>`_)
  * link against catkin_LIBRARIES (`#57 <https://github.com/ros-industrial/fanuc/issues/57>`_)
  * prefix CMake targets with PROJECT_NAME (`#47 <https://github.com/ros-industrial/fanuc/issues/47>`_)
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
