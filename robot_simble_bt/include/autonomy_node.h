#include "rclcpp/rclcpp.hpp"
#include "behaviortree_cpp_v3/bt_factory.h"
// #include "behaviortree_cpp/action_node.h"
// #include <iostream>
// #include <chrono>

class AutonomyNode : public rclcpp::Node{

    public:
    explicit AutonomyNode(const std::string &node_name)
    void setup();
    void create_behavior_tree();
    void update_behavior_tree();
    

    private:
    rclcpp::TimerBase::SharedPtr timer_;
    BT::Tree tree_;
};