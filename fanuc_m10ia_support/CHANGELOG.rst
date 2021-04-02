^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package fanuc_m10ia_support
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.5.1 (2021-04-02)
------------------
* bump min CMake version (`#309 <https://github.com/ros-industrial/fanuc/issues/309>`_).
* correct missing dependency on ``industrial_robot_client`` (RViz cfg) (`#306 <https://github.com/ros-industrial/fanuc/issues/306>`_).
* specify OPW joint offsets in degrees (`#293 <https://github.com/ros-industrial/fanuc/issues/293>`_).
* point to manifest for info on package contents (`#292 <https://github.com/ros-industrial/fanuc/issues/292>`_).
* add OPW kinematics parameter files (`#284 <https://github.com/ros-industrial/fanuc/issues/284>`_).
* remove roslaunch version requirements as they're no longer needed (`#278 <https://github.com/ros-industrial/fanuc/issues/278>`_).
* migrate to JSP GUI (was split out of JSP).
* for a complete list of changes see the `commit log for 0.5.1 <https://github.com/ros-industrial/fanuc/compare/0.5.0...0.5.1>`_.
* contributors: Jeroen de Maeyer, gavanderhoorn

0.5.0 (2019-09-25)
------------------
* make ``flange`` parent of ``tool0`` (`#271 <https://github.com/ros-industrial/fanuc/issues/271>`_).
* update xacro xmlns uri (`#239 <https://github.com/ros-industrial/fanuc/issues/239>`_).
* for a complete list of changes see the `commit log for 0.5.0 <https://github.com/ros-industrial/fanuc/compare/0.4.4...0.5.0>`_.

0.4.4 (2018-01-22)
------------------
* add custom manifest tags to make package support level explicit.
* for a complete list of changes see the `commit log for 0.4.4 <https://github.com/ros-industrial/fanuc/compare/0.4.3...0.4.4>`_.

0.4.3 (2017-10-14)
------------------
* no changes.
* for a complete list of changes see the `commit log for 0.4.3 <https://github.com/ros-industrial/fanuc/compare/0.4.2...0.4.3>`_.

0.4.2 (2017-05-22)
------------------
* add 'flange' frame: attachment point for EEF xacro models (`#213 <https://github.com/ros-industrial/fanuc/pull/213>`_).
* use Jade+ xacro 'pi' constant instead of our own.
* remove redundant urdfs, consumers should use xacro macros or top-level xacros.
* add XML schema processing instruction (`#200 <https://github.com/ros-industrial/fanuc/issues/200>`_).
* migrate to in-order processing of xacros (supported on Indigo and up).
* for a complete list of changes see the `commit log for 0.4.2 <https://github.com/ros-industrial/fanuc/compare/0.4.1...0.4.2>`_.

0.4.1 (2016-06-17)
------------------
* use ``xacro`` instead of ``xacro.py`` (`#195 <https://github.com/ros-industrial/fanuc/issues/195>`_).
* remove roslaunch test dependencies (`#185 <https://github.com/ros-industrial/fanuc/issues/185>`_).
* add support for the M-10iA/7L variant (contributors: Jeremy Zoss (SwRI))
* for a complete list of changes see the `commit log for 0.4.1 <https://github.com/ros-industrial/fanuc/compare/0.4.0...0.4.1>`_.

0.4.0 (2015-10-11)
------------------
* first Indigo release.
* upgrade manifests to package format 2 (`#115 <https://github.com/ros-industrial/fanuc/issues/115>`_).
* general cleanup of XML files (launch, manifests, roslaunch tests, xacros).
* add ROS Index tags to package manifests (`#147 <https://github.com/ros-industrial/fanuc/issues/147>`_).
* document launch file arguments (`#165 <https://github.com/ros-industrial/fanuc/issues/165>`_).
* use multi-arg install rule instead of for-loop.
* use Roboguide colours for meshes where appropriate (`#166 <https://github.com/ros-industrial/fanuc/issues/166>`_).
* for a complete list of changes see the `commit log for 0.4.0 <https://github.com/ros-industrial/fanuc/compare/0.3.2...0.4.0>`_.

0.3.2 (2015-04-19)
------------------
* add readmes to all packages (`#153 <https://github.com/ros-industrial/fanuc/issues/153>`_).
* for a complete list of changes see the `commit log for 0.3.2 <https://github.com/ros-industrial/fanuc/compare/0.3.1...0.3.2>`_

0.3.1 (2015-01-21)
------------------
* no changes.
* for a complete list of changes see the `commit log for 0.3.1 <https://github.com/ros-industrial/fanuc/compare/0.3.0...0.3.1>`_

0.3.0 (2015-01-08)
------------------
* promote experimental packages for M-10iA, M-16iB, M-20iA, M-430iA and LR Mate 200iC to main repository.
* add info on specific config used for urdf/xacro (`#26 <https://github.com/ros-industrial/fanuc/issues/26>`_).
* explicitly declare dependencies of roslaunch tests (`#70 <https://github.com/ros-industrial/fanuc/issues/70>`_).
* add 'base' link (transform to World Coordinates) (`#101 <https://github.com/ros-industrial/fanuc/issues/101>`_).
* update urdfs based on DH data (`#54 <https://github.com/ros-industrial/fanuc/issues/54>`_ and `#63 <https://github.com/ros-industrial/fanuc/issues/63>`_).
* for a complete list of changes see the `commit log for 0.3.0 <https://github.com/ros-industrial/fanuc/compare/0.2.0...0.3.0>`_

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
