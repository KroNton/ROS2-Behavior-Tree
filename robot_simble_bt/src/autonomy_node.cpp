#include "autonomy_node.h"

AutonomyNode::AutonomyNode(const std::string &node_name):Node(node_name)
{

RCLCPP_INFO(get_logger(),"Initialize Node")
}

void AutonomyNode::setup()
{
//intial BT setup


}

void AutonomyNode::create_behavior_tree()
{
//create BT

}

void AutonomyNode::update_behavior_tree()
{
// tick BT when asked

}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<AutonomyNode>("autonomy_node")
  
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}