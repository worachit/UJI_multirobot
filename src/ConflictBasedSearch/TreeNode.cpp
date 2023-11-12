#include "TreeNode.h"


TreeNode::TreeNode() = default;
TreeNode::~TreeNode() = default;


std::vector<std::vector<Cell>> TreeNode::getSolution() const
{
	return solution;
}

int TreeNode::getCost() const {
	return cost;
}


std::vector<Constraint2> TreeNode::getConstraints() {
	return std::vector<Constraint2>();
}

TreeNode::TreeNode(const std::vector<Constraint2> &constraints) {
	this->constraints = constraints;
}

void TreeNode::addConstraint(const Constraint2 & constaint) {
	this->constraints.emplace_back(constaint);
}

void TreeNode::updateSolution(const Map &map) {
	LowLevelSolver solver;
	solution = solver.findOptimalPaths(constraints, map);
}

void TreeNode::updateCost() {
	auto cost = 0;
	for (auto route : solution) {
		cost += route.size();
	}
	this->cost = cost;
}
