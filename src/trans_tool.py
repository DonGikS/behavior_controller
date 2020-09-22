#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist
from ar_track_alvar_msgs.msg import AlvarMarkers
from geometry_msgs.msg import PoseStamped
from move_base_msgs.msg import MoveBaseActionResult
from actionlib_msgs.msg import GoalStatusArray
from actionlib_msgs.msg import GoalStatus
from std_msgs.msg import String
'''
def nav2cmd(data):
    pub = data

def trans_tool():
    
    pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
    rospy.init_node('trans_tool', anonymous=True)
    b = rospy.Subscriber("/nav_vel", Twist, nav2cmd)
    while not rospy.is_shutdown():
        hello_str = "hello world %s" % rospy.get_time()
        rospy.loginfo(hello_str)
        pub.publish(b)

if __name__ == '__main__':
    trans_tool()
'''


def callback(data):
      rospy.loginfo(data)

def listener():
      rospy.init_node('listener',anonymous=True)

      rospy.Subscriber("/nav_vel", Twist, callback)

      rospy.spin()

if __name__=='__main__':
      listener()
