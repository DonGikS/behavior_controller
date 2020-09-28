# Indoor_Robot_Project

>## 프로젝트 목차

>   >#### 1. 프로젝트 목적
>   >#### 2. 프로젝트 계획표
>   >#### 3. 사용된 장비
>   >#### 4. 설치(installing)
>   >#### 5. 실행(operating)
>   >#### 6. 참고자료


> ## 1. 프로젝트 목적

>   >로봇에 카메라를 부착하고 A에서 B지점으로 찍는 실내 네비게이션 로봇을 만들어라. </br>AR마커를 이용한 도킹스테이션을 기점으로 도착지점을 찍고 다시 돌아오게 설계해야한다.

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
+터틀봇3(Turtlebot3)
![turtlebot3](https://user-images.githubusercontent.com/29765871/94400928-d3867200-01a4-11eb-8527-f40bc9f931c0.jpg)
+raspberry pi camera
![raspicamera](https://user-images.githubusercontent.com/29765871/94400925-d3867200-01a4-11eb-8a44-bfaabb81b42a.jpg)
+Linux PC(OS : ubuntu 18.04)
![ubuntu](https://user-images.githubusercontent.com/29765871/94400930-d41f0880-01a4-11eb-80d4-02589925b234.png)
+ROS 1(melodic)
![melodic](https://user-images.githubusercontent.com/29765871/94400921-d2eddb80-01a4-11eb-98b5-83e3f3dd4acb.jpeg)


![ar_marker_tracking](https://user-images.githubusercontent.com/29765871/94400914-d1241800-01a4-11eb-930b-5832de80b8a0.png)
![camera_calibration](https://user-images.githubusercontent.com/29765871/94400915-d2554500-01a4-11eb-90a8-b994f92cf59f.png)
![map_design](https://user-images.githubusercontent.com/29765871/94400919-d2eddb80-01a4-11eb-9ce0-6abc67c6fc47.jpg)

> ## 4.설치(installing)

> ## 5.실행(operating)
> ## 6.참고자료