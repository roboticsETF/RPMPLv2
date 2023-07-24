# 1. Introduction
This repository contains Rapid Prototyping Motion Planning Library v2 (RPMPLv2) implemented in C++.

Available planners are:
- Rapidly-exploring Random Trees (RRT-Connect)
- Rapidly-exploring Bur Trees (RBT-Connect)
- Rapidly-exploring Generalized Bur Trees (RGBT-Connect)
- Dynamic Rapidly-exploring Generalized Bur Trees (DRGBT-Connect)
- Rapidly-exploring Generalized Bur Multi-Tree (RGBMT*)

The development and test environment are tested on Ubuntu 22.04 + ROS2 Humble.

# 2. How to use
## 2.1 Obtain source code of "RPMPLv2" repository
Choose the location for a target workspace, e.g.:
```
cd ~/
```
DO NOT omit "--recursive"，or the source code of dependent submodules will not be downloaded:
```
git clone https://github.com/roboticsETF/xarm6-etf-lab.git --recursive
```

## 2.2 Update "RPMPLv2" repository
```
cd ~/RPMPLv2
git pull
git submodule sync
git submodule update --init --remote
```

## 2.3 Install required packages
For planning:
```
sudo apt install libeigen3-dev libkdl-parser-dev libgflags-dev libgoogle-glog-dev liborocos-kdl-dev libyaml-cpp-dev liburdf-dev
```
For visualization:
```
pip3 install trimesh urdfpy
```

## 2.4 Install dependencies
```
cd ~/RPMPLv2
rosdep update
make dependencies
```

## 2.5 Build "RPMPLv2" repository
```
make build
```

# 3. Run the simulation
## 3.1 Set configuration parameters
On the location ```/data/configurations``` you can find the configuration yaml files, which can be modified in order to set the desired configuration parameters for each planner.

For example, open ```configuration_rgbmtstar.yaml```, and set the maximal planning time to 10 sec:
```
MAX_PLANNING_TIME: 10000
```

## 3.2 Set scenario parameters
Open the folder ```/data```, where you can find three subfolders: ```/planar_2dof```, ```/planar_10dof``` and ```/xarm6```. Inside each of them, you can find different scenario folders containing the corresponding scenario yaml files.

For example, open the file ```/data/planar_2dof/scenario_test/scenario_test.yaml```. You can set obstacles details (dimensions, translation and rotation of the box obstacle). You can set as many obstacles as you want. Moreover, some details about the used robot (robot type, urdf file location, configuration space type, dimensions of the configuration space, and start and goal configurations) can be set.

For example, if you do not want to use FCL (Flexible Collision Library) in planning, just set:
```
space: "RealVectorSpace"
```
Be aware that, in such case, robot links are approximated with capsules, thus collision checks and distance queries between primitives, capsule and box, are performed. In most cases, this executes faster than when using FCL, especially for more complicated robot mesh structures (containing too many triangles), such as xarm6 structure.

Otherwise, if you do want to use FCL, just set:
```
space: "RealVectorSpaceFCL"
```

## 3.3 Test planners
In the new tab type:
```
cd ~/RPMPLv2/install/rpmpl_library/apps
```

Test RRT-Connect:
```
./test_rrtconnect
```

Test RBT-Connect:
```
./test_rbtconnect
```

Test RGBT-Connect:
```
./test_rgbtconnect
```

Test RGBMT*:
```
./test_rgbmtstar
```

Test RGBMT* benchmark:
```
./test_rgbmtstar_benchmark
```

Test DRGBT-Connect benchmark:
```
./test_drgbtconnect_benchmark
```

After the planning is finished, all log files (containing all details about the planning) will be stored in ```/data``` folder (e.g., ```/data/planar_2dof/scenario_test/scenario_test_planner_data.log```).

## 3.4 Visualize the robot and obstacles
In the new tab type:
```
cd ~/xarm6-etf-lab/build
```

Visualize plannar_2dof robot:
```
python3 visualizer/run_visualizer_planar_2dof.py
```
![scenario2_planar_2dof](https://github.com/roboticsETF/RPMPLv2/assets/126081373/03e63cce-93ee-4436-a296-706ca1551acc)
![scenario_test_planar_2dof_nice_example](https://github.com/roboticsETF/RPMPLv2/assets/126081373/fd9f4ab3-73ee-4617-ba4d-1a887620eca0)

Visualize plannar_10dof robot:
```
python3 visualizer/run_visualizer_planar_10dof.py
```
![scenario1_planar_10dof](https://github.com/roboticsETF/RPMPLv2/assets/126081373/555087c0-83e3-4ebb-89b5-c8658d2c61e1)
![scenario2_planar_10dof](https://github.com/roboticsETF/RPMPLv2/assets/126081373/ecd2f76a-d80b-443e-b3f8-e663f31f58b7)

Visualize xarm6 robot:
```
python3 visualizer/run_visualizer_xarm6.py
```
![scenario1_xarm6_v1](https://github.com/roboticsETF/RPMPLv2/assets/126081373/d0c93b82-93cc-40ee-ba2c-04284f4fd2f2)
![scenario2_xarm6_v2](https://github.com/roboticsETF/RPMPLv2/assets/126081373/683e53fb-08da-43da-9dfa-6977490d7425)
![scenario_test_xarm6_nice_example_v2](https://github.com/roboticsETF/RPMPLv2/assets/126081373/6850facc-faf2-4f07-8e8a-34e8ec834b05)

The visualization gif files will be stored in ```/data``` folder (e.g., ```/data/planar_2dof/scenario_test/scenario_test_planar_2dof.gif```).

