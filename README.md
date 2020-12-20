[![indoor](https://img.youtube.com/vi/dwrhQN8UU5Y/0.jpg)](https://youtu.be/dwrhQN8UU5Y)
[Youtube Link(Click)]
# Indoor_Robot_Project

>## 프로젝트 목차

#### 1. 프로젝트 목적
#### 2. 프로젝트 계획표
#### 3. 사용된 장비
#### 4. 설치(installing)
#### 5. 실행(operating)
#### 6. 블록다이어그램
#### 7. 참고자료


> ## 1. 프로젝트 목적

로봇에 카메라를 부착하고 A에서 B지점으로 찍는 실내 네비게이션 로봇을 만들어라. </br>AR마커를 이용한 도킹스테이션을 기점으로 도착지점을 찍고 다시 돌아오게 설계해야한다.

> ## 2. 프로젝트 계획표

<table border="1">
	<th>주차</th>
	<th>기간</th>
    <th>실습</br>시간</th>
    <th>실습주제</th>
    <th>필요장비</th>
    <th>담당</th>
	<tr>
	    <td>1주</td>
	    <td>8/3~7</td>
        <td>40</td>
        <td>Introduction to ROS</td>
        <td>Linux PC </br> ROS robot programming (책</br> 저자 표윤석)</td>
        <td>권지욱</td>
	</tr>
	<tr>
	    <td>2주</td>
	    <td>8/10~14</td>
        <td>40</td>
        <td>Introduction to Robotics</td>
        <td>Linux PC </td>
        <td>권지욱</td>
	</tr>
    <tr>
	    <td>3주</td>
	    <td>8/17~21</td>
        <td>40</td>
        <td>ROS navi-stack AtoB</br> 장애물 지도 생성 및</br> 장애물 감지</td>
        <td>Linux PC</td>
        <td>권지욱</td>
	</tr>
    <tr>
	    <td>4주</td>
	    <td>8/24~28</td>
        <td>40</td>
        <td>SLAM & Localization</br>ROS navi-stack +</br> google(카토그래퍼)</br>(Localiztion)</td>
        <td>Linux PC </br>Robot</td>
        <td>권지욱</td>
	</tr>
    <tr>
	    <td>5주</td>
	    <td>8/31~9/4</td>
        <td>40</td>
        <td>Path planner (global &</br>local)</br>ROS navi-stack +</br> google(카토그래퍼)</br>(Localiztion) +</br>(A*/DWA/TEB/(Timed</br> Elastic Band)</td>
        <td>Linux PC</br>Robot</br>2D LiDAR</td>
        <td>도구공간</td>
	</tr>
    <tr>
	    <td>6주</td>
	    <td>9/7~11</td>
        <td>40</td>
        <td>Docking control</br>(April marker detection)</br>(Visual servo control)</td>
        <td>Linux PC</br>Robot</br>2D LiDAR</br>rgb camera</td>
        <td>도구공간</td>
	</tr>
    <tr>
	    <td>7주</td>
	    <td>9/14~18</td>
        <td>40</td>
        <td>A to B mission</br>(behavior control)</br>(docking station에서</br>출발 후 목적지 도달 이후</br> 다시 출발 도킹 스테이션에</br>도킹)</td>
        <td>Linux PC</br>Robot</br>2D LiDAR</br>rgb camera</td>
        <td>도구공간</td>
	</tr>
</table>

> ## 3.사용된 장비
+ 터틀봇3(Turtlebot3)</br>
![turtlebot3](https://user-images.githubusercontent.com/29765871/94400928-d3867200-01a4-11eb-8527-f40bc9f931c0.jpg)</br>
+ raspberry pi camera</br>
![raspicamera](https://user-images.githubusercontent.com/29765871/94400925-d3867200-01a4-11eb-8a44-bfaabb81b42a.jpg)</br>
+ Linux PC(OS : ubuntu 18.04)</br>
![ubuntu](https://user-images.githubusercontent.com/29765871/94400930-d41f0880-01a4-11eb-80d4-02589925b234.png)</br>
+ ROS 1(melodic)</br>
![melodic](https://user-images.githubusercontent.com/29765871/94400921-d2eddb80-01a4-11eb-98b5-83e3f3dd4acb.jpeg)</br>

> ## 4.설치(installing)
+ remote PC</br>
    + ROS 1 설치[Link](http://wiki.ros.org/melodic/Installation/Ubuntu)를 통해 설치한다.

    + 필요한 Depandancy 설치</br>
    <pre>
        <code>
            sudo apt-get install ros-melodic-joy ros-melodic-teleop-twist-joy ros-melodic-teleop-twist-keyboard ros-melodic-laser-proc ros-melodic-rgbd-launch ros-melodic-depthimage-to-laserscan ros-melodic-rosserial-arduino ros-melodic-rosserial-python ros-melodic-rosserial-server ros-melodic-rosserial-client ros-melodic-rosserial-msgs ros-melodic-amcl ros-melodic-map-server ros-melodic-move-base ros-melodic-urdf ros-melodic-xacro ros-melodic-compressed-image-transport ros-melodic-rqt-image-view ros-melodic-gmapping ros-melodic-navigation ros-melodic-interactive-markers
        </code>
    </pre>
    + Turtlebot3 패키지 설치(melodic version)</br>
    <pre>
        <code>
            cd ~/catkin_ws/src/
            git clone https://github.com/ROBOTIS-GIT/turtlebot3_msgs.git
            git clone -b melodic-devel https://github.com/ROBOTIS-GIT/turtlebot3.git
            cd ~/catkin_ws && catkin_make
        </code>
    </pre>
    + Turtlebot3 application 패키지 설치(melodic version)</br>
    <pre>
        <code>
            cd ~/catkin_ws/src
            git clone https://github.com/ros-perception/ar_track_alvar.git
            git clone https://github.com/ROBOTIS-GIT/turtlebot3_applications.git
            git clone https://github.com/ROBOTIS-GIT/turtlebot3_applications_msgs.git
            cd ~/catkin_ws && catkin_make
        </code>
    </pre>
    + 통합 launch 파일 패키지 설치</br>
    <pre>
        <code>
            cd ~/catkin_ws/src
            git clone https://github.com/DonGikS/behavior_controller.git
            cd behavior_controller/turtlebot3_navigation/launch
            mv move_base.launch ../../../turtlebot3/turtlebot3_navigation/launch
            cd ~/catkin_ws/src/behavior_controller/turtlebot3_description/urdf
            mv turtlebot3_burger.urdf.xacro ../../../turtlebot3/turtlebot3_description/urdf
            cd ~/catkin_ws && catkin_make
        </code>
    </pre>
    + ROBOT(turtlebot3에서)</br>
        터틀봇 라즈베리파이 활성화[Link](https://emanual.robotis.com/docs/en/platform/turtlebot3/appendix_raspi_cam/)참고
        + turtlebot3_bringup/launch/turtlebot3_rpicamera.launch 파일 수정
        <launch>
            <node type="raspicam_node" pkg="raspicam_node" name="raspicam_node" output="screen">
                
                <param name="framerate" type="int" value="30" />
                <param name="exposure_mode" value="antishake" />
                <param name="shutter_speed" value="0" />
                <param name="quality" type="int" value="10" />
                <param name="width" type="int" value="320" />
                <param name="height" type="int" value="240" />
                <!--뒤집혀있으면 넣는다
                <param name="hFlip" type="int" value="true" />
                <param name="vFlip" type="int" value="true" />
                -->

                <param name="camera_frame_id" value="camera" />
                <!--이거 있으면 카메라전송 속도가 빨라짐-->
                <param name="/raspicam_node/quality"  value="9"/>
            </node>
        </launch>

    + Calibration with raspicam_node</br>
        + Remote PC에서</br>
        <pre>
            <code>
                roscore
            </code>
        </pre>
        + ROBOT(turtlebot3에서)</br>
        <pre>
            <code>
                roslaunch turtlebot3_bringup turtlebot3_rpicamera.launch
            </code>
        </pre>

        + Remote PC에서</br>
        <pre>
            <code>
                rosrun image_transport republish compressed in:=/raspicam_node/image raw out:=/raspicam_node/image
                rosrun camera_calibration cameracalibrator.py --size 8x6 --square 0.024 image:=/raspicam_node/image camera:=/raspicam_node
            </code>
        </pre>
        ![camera_calibration](https://user-images.githubusercontent.com/29765871/94400915-d2554500-01a4-11eb-90a8-b994f92cf59f.png)</br>
        + calibration 저장하고나서
        <pre>
            <code>
                cd /tmp
                tar -xvzf calibrationdata.tar.gz 
                mv ost.txt ost.ini
                rosrun camera_calibration_parsers convert ost.ini camera.yaml
                mv camera.yaml ~/.ros/camera_info/
            </code>
        </pre>

    + AR 마커 트래커</br>
        + Remote PC에서</br>
        <pre>
            <code>
                roscore
            </code>
        </pre>
        + ROBOT(turtlebot3에서)</br>
        <pre>
            <code>
                roslaunch turtlebot3_bringup turtlebot3_rpicamera.launch
            </code>
        </pre>
        + Remote PC에서</br>
        <pre>
            <code>
                roslaunch ar_track_alvar pr2_indiv_no_kinetic.launch
                rviz rviz
            </code>
        </pre>
        fixed frame을 카메라 이름으로 한다.
    ![ar_marker_tracking](https://user-images.githubusercontent.com/29765871/94400914-d1241800-01a4-11eb-930b-5832de80b8a0.png)</br>

    + 맵 제작</br>
        + Remote PC에서</br>
            <pre>
                <code>
                    roscore
                </code>
            </pre>
        + ROBOT(turtlebot3에서)</br>
            <pre>
            <code>
                roslaunch turtlebot3_bringup turtlebot3_robot.launch
                
            </code>
        + Remote PC에서</br>
            <pre>
                <code>
                    roslaunch turtlebot3_slam turtlebot3_slam.launch slam_methods:=cartographer
                </code>
            </pre>
            (mapping...)</br>
            ![map_design](https://user-images.githubusercontent.com/29765871/94400919-d2eddb80-01a4-11eb-9ce0-6abc67c6fc47.jpg)</br>
            <pre>
                <code>
                    rosrun map_server map_saver -f ~/map_my_kiro
                </code>
            </pre>
            ![Screenshot from 2020-09-29 01-47-44](https://user-images.githubusercontent.com/29765871/94462017-d9f10a00-01f5-11eb-8f34-c68dc19b0f67.png)


    
> ## 5.실행(operating)
+ Remote PC에서</br>
    <pre>
        <code>
            roscore
        </code>
    </pre>
+ ROBOT(turtlebot3에서)</br>
    <pre>
    <code>
        roslaunch turtlebot3_bringup turtlebot3_robot.launch
        roslaunch turtlebot3_bringup turtlebot3_rpicamera.launch
    </code>
+ Remote PC에서</br>
    <pre>
        <code>
            roslaunch behavior_controller execute.launch
        </code>
    </pre>
> ## 6.블록다이어그램
+하드웨어 블록다이어그램</br>
![하드](https://user-images.githubusercontent.com/29765871/102717848-3ca2ff00-4328-11eb-89b3-93c020a6d530.JPG)</br>
+소프트웨어 블록다이어그램</br>
![소프](https://user-images.githubusercontent.com/29765871/102717851-3dd42c00-4328-11eb-8c4d-69302c3f3ac7.JPG)</br>
+동작 알고리즘 블록다이어그램</br>
![알고](https://user-images.githubusercontent.com/29765871/102717844-3b71d200-4328-11eb-9604-5064557dd48d.JPG)</br>
> ## 7.참고자료
>   >[raspberry_pi_camera_with_turtlebot3](https://emanual.robotis.com/docs/en/platform/turtlebot3/appendix_raspi_cam/)
>   >[ar_track_alvar](http://wiki.ros.org/ar_track_alvar)</br>
>   >[teb_local_planner_tutorials](http://wiki.ros.org/teb_local_planner_tutorials)</br>
>   >[turtlebot3_application_auto_parking_vision](https://emanual.robotis.com/docs/en/platform/turtlebot3/applications/)</br>
>   >[turtlebot3_slam](https://emanual.robotis.com/docs/en/platform/turtlebot3/navigation/#run-navigation-nodes)</br>
>   >[ros_melodic_cartographer](https://aur.archlinux.org/packages/ros-melodic-cartographer-ros/)</br>
>   >[raspicam_node_too_slow](https://answers.ros.org/question/289300/very-low-image-publish-rate-from-raspicam_node-over-wifi/)</br>
roslaunch turtlebot3_slam turtlebot3_slam.launch slam_methods:=cartographer configuration_basename:=turtlebot3_lds_2d_gazebo.lua


