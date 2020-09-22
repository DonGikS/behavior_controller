#include "ros/ros.h"
#include <stdlib.h>
#include <iostream>
#include "std_msgs/Int64.h"
#include <geometry_msgs/Twist.h>
#include <ar_track_alvar_msgs/AlvarMarkers.h>
#include <actionlib_msgs/GoalStatusArray.h>
#include <actionlib_msgs/GoalStatus.h>
#include <geometry_msgs/PoseStamped.h> 

ros::Publisher trans_vel;
int c = 0;
int stat = 0;
void nav2cmd_Callback(const geometry_msgs::Twist::ConstPtr& twist){
    if(c)trans_vel.publish(twist);
    
}
void doc2cmd_Callback(const geometry_msgs::Twist::ConstPtr& twist){
    if(!c)trans_vel.publish(twist);
    
}
void ad(const actionlib_msgs::GoalStatusArray::ConstPtr& ad){
    
    c = ad->status_list.size();//[0]).status;
    if(c)stat = ad->status_list[0].status;

}
int main(int argc, char **argv){
    ros::init(argc, argv, "trans_node");
    ros::NodeHandle nh;
    ros::Subscriber doc;
    ros::Subscriber nav;
    trans_vel = nh.advertise<geometry_msgs::Twist>("cmd_vel",100);
    
    ros::Subscriber status = nh.subscribe("move_base/status",100, ad);   
    doc = nh.subscribe("doc_vel", 100, doc2cmd_Callback);
    nav = nh.subscribe("nav_vel", 100, nav2cmd_Callback);
    ros::spin();
}