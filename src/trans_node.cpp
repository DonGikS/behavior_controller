#include "ros/ros.h"
#include <stdlib.h>
#include <iostream>
#include "std_msgs/Int64.h"
#include <geometry_msgs/Twist.h>
#include <ar_track_alvar_msgs/AlvarMarkers.h>
#include <actionlib_msgs/GoalStatusArray.h>
#include <actionlib_msgs/GoalStatus.h>
#include <geometry_msgs/PoseStamped.h> //move_base/simple_goal
#include <geometry_msgs/PoseWithCovarianceStamped.h> //amcl_pose 절대좌표
#include <geometry_msgs/Pose.h>

ros::Publisher trans_vel;
geometry_msgs::Pose initial_Pose;
int link_status_list = 0;
int stat = 0;
void init_pose(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& init_po){
    if(!link_status_list) initial_Pose = init_po->pose.pose;
    ROS_INFO("pose");
    ROS_INFO("x : %lf",initial_Pose.position.x);
    ROS_INFO("y : %lf",initial_Pose.position.y);
    ROS_INFO("z : %lf",initial_Pose.position.z);
    ROS_INFO("angle");
    ROS_INFO("x : %lf",initial_Pose.orientation.x);
    ROS_INFO("y : %lf",initial_Pose.orientation.y);
    ROS_INFO("z : %lf",initial_Pose.orientation.z);
    ROS_INFO("w : %lf",initial_Pose.orientation.w);
    
}
void nav2cmd_Callback(const geometry_msgs::Twist::ConstPtr& twist){
    if(link_status_list)trans_vel.publish(twist);
    
}
void doc2cmd_Callback(const geometry_msgs::Twist::ConstPtr& twist){
    if(!link_status_list){
        trans_vel.publish(twist);
    }
    
}
void ad(const actionlib_msgs::GoalStatusArray::ConstPtr& ad){
    
    link_status_list = ad->status_list.size();//[0]).status;
    if(link_status_list)stat = ad->status_list[0].status;

}
int main(int argc, char **argv){
    ros::init(argc, argv, "trans_node");
    ros::NodeHandle nh;

    ros::Subscriber status;
    ros::Subscriber doc;
    ros::Subscriber nav;

    ros::Subscriber amc;

    trans_vel = nh.advertise<geometry_msgs::Twist>("cmd_vel",100);
    amc = nh.subscribe("amcl_pose", 100, init_pose);
    status = nh.subscribe("move_base/status",100, ad);   
    doc = nh.subscribe("doc_vel", 100, doc2cmd_Callback);
    nav = nh.subscribe("nav_vel", 100, nav2cmd_Callback);

    ros::spin();
}