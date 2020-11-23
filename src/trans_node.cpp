#include "ros/ros.h"
#include <stdlib.h>
#include <iostream>
#include "std_msgs/Int64.h"
#include <std_msgs/Bool.h>
#include <geometry_msgs/Twist.h>
#include <ar_track_alvar_msgs/AlvarMarkers.h>
#include <actionlib_msgs/GoalStatusArray.h>
#include <actionlib_msgs/GoalStatus.h>
#include <geometry_msgs/PoseStamped.h> //move_base/simple_goal
#include <geometry_msgs/PoseWithCovarianceStamped.h> //amcl_pose 절대좌표
#include <geometry_msgs/Pose.h>

ros::Publisher trans_vel;
ros::Publisher back_to_goal;
ros::Publisher goal_checker;

std_msgs::Bool home_check;
geometry_msgs::Pose initial_Pose;
geometry_msgs::Pose current_Pose;
geometry_msgs::PoseStamped last_goal;

int link_status_list = 0;
int stat = 0;
bool marker_dec = false;
bool a = false;
bool home_goal = false;

void init_pose(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& init_po){
    if(!link_status_list && (marker_dec == true)){
        initial_Pose = init_po->pose.pose;
        marker_dec = false;
    } 
    current_Pose = init_po->pose.pose;

}
void nav2cmd_Callback(const geometry_msgs::Twist::ConstPtr& twist){
    if(link_status_list){
        if(stat == 1){
            trans_vel.publish(twist);
        }
    }
    
    
}
void doc2cmd_Callback(const geometry_msgs::Twist::ConstPtr& twist){
    if(!link_status_list){
        trans_vel.publish(twist);
        marker_dec = true;
    }else{
        if(stat == 3 && home_check.data){
            trans_vel.publish(twist);
        }
    }
    
}
void link_2_status(const actionlib_msgs::GoalStatusArray::ConstPtr& link_2_status){
    
    link_status_list = link_2_status->status_list.size();//[0]).status;
    if(link_status_list){
        stat = link_2_status->status_list[0].status;
        if(stat == 1){
            a = true;
            home_goal = false;
            home_check.data = home_goal;
            
        } 
        if(stat == 3){
            if (a){
                geometry_msgs::PoseStamped goal;
                goal.header.frame_id = "map";
                goal.pose.position.x = initial_Pose.position.x + 0.3;
                goal.pose.position.y = initial_Pose.position.y;
                goal.pose.position.z = initial_Pose.position.z;
                goal.pose.orientation.x = initial_Pose.orientation.x;
                goal.pose.orientation.y = initial_Pose.orientation.y;
                goal.pose.orientation.z = initial_Pose.orientation.z;
                goal.pose.orientation.w = initial_Pose.orientation.w;
                back_to_goal.publish(goal);
                home_goal = true;
                home_check.data = home_goal;
                a = false;
            }

        }
    }
    goal_checker.publish(home_check);
    ROS_INFO("%d",home_goal);

}
int main(int argc, char **argv){
    ros::init(argc, argv, "trans_node");
    ros::NodeHandle nh;

    ros::Subscriber status;
    ros::Subscriber doc;
    ros::Subscriber nav;

    ros::Subscriber amc;
    ros::Subscriber goa;

    trans_vel = nh.advertise<geometry_msgs::Twist>("cmd_vel",100);
    back_to_goal = nh.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal",100);
    goal_checker = nh.advertise<std_msgs::Bool>("goal_checker",1);
    amc = nh.subscribe("amcl_pose", 100, init_pose);
    goa = nh.subscribe("/move_base_simple/goal", 100, track_pose);
    status = nh.subscribe("move_base/status",100, link_2_status);   
    doc = nh.subscribe("doc_vel", 100, doc2cmd_Callback);
    nav = nh.subscribe("nav_vel", 100, nav2cmd_Callback);

    ros::spin();
}
