#!/usr/bin/env python

from distutils.core import setup
from catkin_pkg.python_setup import generate_distutils_setup

d = generate_distutils_setup(
    packages=['rqt_ros2_ros1_bridge'],
    package_dir={'': 'src'},
    scripts=['scripts/rqt_ros2_ros1_bridge']
)

setup(**d)
