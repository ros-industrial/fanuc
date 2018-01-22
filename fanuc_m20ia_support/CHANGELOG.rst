^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package fanuc_m20ia_support
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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
* first Hydro release of this package.
* promote experimental packages for M-10iA, M-16iB, M-20iA, M-430iA and LR Mate 200iC to main repository.
* explicitly declare dependencies of roslaunch tests (`#70 <https://github.com/ros-industrial/fanuc/issues/70>`_).
* add 'base' link (transform to World Coordinates) (`#101 <https://github.com/ros-industrial/fanuc/issues/101>`_).
* update urdfs based on DH data (`#54 <https://github.com/ros-industrial/fanuc/issues/54>`_ and `#63 <https://github.com/ros-industrial/fanuc/issues/63>`_).
* for a complete list of changes see the `commit log for 0.3.0 <https://github.com/ros-industrial/fanuc/compare/0.2.0...0.3.0>`_
