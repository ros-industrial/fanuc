^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package fanuc_lrmate200ic_moveit_config
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.5.1 (2021-04-02)
------------------
* bump min CMake version (`#309 <https://github.com/ros-industrial/fanuc/issues/309>`_).
* point to manifest for info on package contents (`#292 <https://github.com/ros-industrial/fanuc/issues/292>`_).
* for a complete list of changes see the `commit log for 0.5.1 <https://github.com/ros-industrial/fanuc/compare/0.5.0...0.5.1>`_.

0.5.0 (2019-09-25)
------------------
* disable db tests for now (`#269 <https://github.com/ros-industrial/fanuc/pull/269>`_).
* for a complete list of changes see the `commit log for 0.5.0 <https://github.com/ros-industrial/fanuc/compare/0.4.4...0.5.0>`_.

0.4.4 (2018-01-22)
------------------
* add custom manifest tags to make package support level explicit.
* for a complete list of changes see the `commit log for 0.4.4 <https://github.com/ros-industrial/fanuc/compare/0.4.3...0.4.4>`_.

0.4.3 (2017-10-14)
------------------
* enable use of Jade+ xacro when loading MoveIt configuration packages. (`#217 <https://github.com/ros-industrial/fanuc/issues/217>`_).
* for a complete list of changes see the `commit log for 0.4.3 <https://github.com/ros-industrial/fanuc/compare/0.4.2...0.4.3>`_.

0.4.2 (2017-05-22)
------------------
* push trajectory execution parameters down into namespace (`#211 <https://github.com/ros-industrial/fanuc/issues/211>`_).
* switch to Jade+ xacro processing.
* load top-level xacros instead of urdfs (`#169 <https://github.com/ros-industrial/fanuc/issues/169>`_).
* add XML schema processing instruction (`#200 <https://github.com/ros-industrial/fanuc/issues/200>`_).
* for a complete list of changes see the `commit log for 0.4.2 <https://github.com/ros-industrial/fanuc/compare/0.4.1...0.4.2>`_.

0.4.1 (2016-06-17)
------------------
* make RRTConnect the default planner (`#179 <https://github.com/ros-industrial/fanuc/issues/179>`_).
* update package manifests with missing dependencies (found with roslaunch tests).
* add basic roslaunch tests (`#104 <https://github.com/ros-industrial/fanuc/issues/104>`_).
* for a complete list of changes see the `commit log for 0.4.1 <https://github.com/ros-industrial/fanuc/compare/0.4.0...0.4.1>`_.

0.4.0 (2015-10-11)
------------------
* first Indigo release.
* upgrade manifests to package format 2 (`#115 <https://github.com/ros-industrial/fanuc/issues/115>`_).
* general cleanup of XML files (launch, manifests, roslaunch tests, xacros).
* add ROS Index tags to package manifests (`#147 <https://github.com/ros-industrial/fanuc/issues/147>`_).
* document launch file arguments (`#165 <https://github.com/ros-industrial/fanuc/issues/165>`_).
* document potential poor planning perf of LBKPIECE1 in MoveIt configuration packages.
* update MoveIt configurations for Indigo release.
* for a complete list of changes see the `commit log for 0.4.0 <https://github.com/ros-industrial/fanuc/compare/0.3.2...0.4.0>`_.

0.3.2 (2015-04-19)
------------------
* add readmes to all packages (`#153 <https://github.com/ros-industrial/fanuc/issues/153>`_).
* for a complete list of changes see the `commit log for 0.3.2 <https://github.com/ros-industrial/fanuc/compare/0.3.1...0.3.2>`_

0.3.1 (2015-01-21)
------------------
* make warehouse db location user configurable (`#142 <https://github.com/ros-industrial/fanuc/issues/142>`_).
* for a complete list of changes see the `commit log for 0.3.1 <https://github.com/ros-industrial/fanuc/compare/0.3.0...0.3.1>`_

0.3.0 (2015-01-08)
------------------
* first Hydro release of this package.
* promote experimental packages for M-10iA, M-16iB, M-20iA, M-430iA and LR Mate 200iC to main repository.
* for a complete list of changes see the `commit log for 0.3.0 <https://github.com/ros-industrial/fanuc/compare/0.2.0...0.3.0>`_
