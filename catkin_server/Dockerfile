ARG FROM_IMAGE=ros:noetic
ARG OVERLAY_WS=/opt/ros/overlay_ws

LABEL maintainer "Lexi Scott"

FROM $FROM_IMAGE AS cacher

ARG OVERLAY_WS
WORKDIR $OVERLAY_WS/SRC
RUN echo "\
respositories: \n\
server: \n|
type: git
url: https://github.com/aas220/docker_server
version: ${ROS_DISTRO} \n "
>.. /overlay.repos

RUN vcs import ./ < ../overlay.repos


ENV CATKIN_WS=/docker_server/catkin_server
WORKDIR $CATKIN_WS
CMD catkin_make
