#import os
#os.environ["PYOPENGL_PLATFORM"] = "osmesa"

from trimesh.creation import box
import trimesh.transformations as transforms
from planar_10dof.planar_10dof import Planar10DOF
from math import pi
import time

def visualize(q=None, obstacles=None, image_file=None, is_trajectory=False, is_dynamic=False, fps=10.0):
    #obstacles = [box([0.2, 1.2, 0.1])]
    #obstacles[0].apply_translation([1.3+0.25, 0, 0])
    obstacles = obstacles['obstacles']
    for i, obs in enumerate(obstacles):
        obs = obs['box']
        dim = obs['dim']
        trans = obs['trans']
        rot = obs['rot']
        obstacles[i] = box(dim)
        M = transforms.quaternion_matrix(rot)
        M[0:3,3] = trans
        # print(M)
        obstacles[i].apply_transform(M)

    planar_10dof = Planar10DOF(obstacles)
    robot = planar_10dof.robot
    for link in robot.actuated_joints:
        print(link.name)
    print("Number of joints: ", len(robot.actuated_joints))

    if is_dynamic:
        planar_10dof.animate_dynamic(q, obstacles=obstacles, fps=fps, image_file=image_file)
    elif not is_trajectory:
        planar_10dof.show(q, obstacles, image_file)
    else:
        planar_10dof.animate(q, obstacles=obstacles, fps=fps, image_file=image_file)
    