FROM ros:noetic
RUN apt-get -y update
COPY . .
WORKDIR "/catkin_server"
RUN /bin/bash -c ' . /opt/ros/noetic/setup.bash ; catkin_make'


