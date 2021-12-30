FROM ros:noetic
LABEL maintainer "Lexi Scott"

COPY . /app 
RUN make /app

CMD ../ catkin_make
