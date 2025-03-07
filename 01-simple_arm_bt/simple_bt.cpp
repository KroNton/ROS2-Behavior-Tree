#include <iostream>
#include <chrono>
#include "behaviortree_cpp/action_node.h"
#include "behaviortree_cpp/bt_factory.h"

using namespace BT;

using namespace std::chrono_literals;

BT::NodeStatus CheckBattery();
// Example of custom SyncActionNode (synchronous action)
// without ports.
class ApproachObject : public BT::SyncActionNode
{
public:
    ApproachObject(const std::string &name) : BT::SyncActionNode(name, {})
    {
    }

    // You must override the virtual function tick()
    BT::NodeStatus tick() override
    {
        std::cout << "ApproachObject: " << this->name() << std::endl;
        std::this_thread::sleep_for(1s);
        return BT::NodeStatus::SUCCESS;
    }
};

//Simple function that return a NodeStatus
BT::NodeStatus CheckBattery()
{
    // Your logic here
    std::cout << "Checking the battery..." << std::endl;
    std::cout << "the battery is okay" << std::endl;
    return BT::NodeStatus::SUCCESS; // or FAILURE
}

// We want to wrap into an ActionNode the methods open() and close()
// We want to wrap into an ActionNode the methods open() and close()
class GripperInterface
{
public:
    GripperInterface() : _open(true) {}

    NodeStatus open()
    {
        _open = true;
        std::cout << "GripperInterface::open" << std::endl;
        return NodeStatus::SUCCESS;
    }

    NodeStatus close()
    {
        std::cout << "GripperInterface::close" << std::endl;
        _open = false;
        return NodeStatus::SUCCESS;
    }

private:
    bool _open; // shared information
};

int main(int argc, char const *argv[])
{
    BT::BehaviorTreeFactory factory;
    factory.registerNodeType<ApproachObject>("ApproachObject");
    factory.registerSimpleCondition("CheckBattery",std::bind(CheckBattery));

    
     //You can also create SimpleActionNodes using methods of a class

  GripperInterface gripper;
  factory.registerSimpleAction("OpenGripper", [&](TreeNode&){
        return gripper.open(); } );
  factory.registerSimpleAction("CloseGripper", [&](TreeNode&){
        return gripper.close(); } );


    auto tree = factory.createTreeFromFile("./../bt_tree.xml");

    tree.tickWhileRunning();
    return 0;
}
