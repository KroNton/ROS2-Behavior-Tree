#ifndef SIMPLE_BT_NODES_H
#define SIMPLE_BT_NODES_H

#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/action_node.h"
#include <iostream>

using namespace BT;

// Simple function that returns a NodeStatus
NodeStatus CheckBattery()
{
  std::cout << "[ Battery: OK ]" << std::endl;
  return NodeStatus::SUCCESS;
}

// GripperInterface class definition
class GripperInterface
{
public:
  GripperInterface(): _open(true) {}
    
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

// ApproachObject class definition
class ApproachObject : public SyncActionNode
{
public:
  ApproachObject(const std::string& name) :
      SyncActionNode(name, {})
  {}

  // You must override the virtual function tick()
  NodeStatus tick() override
  {
    std::cout << "ApproachObject: " << this->name() << std::endl;
    return NodeStatus::SUCCESS;
  }
};

#endif // SIMPLE_BT_NODES_H