#pragma once
#include <ctime>
#include "SharedEnv.h"
#include "ActionModel.h"
#include <chrono>
#include "LowLevelSolver.h"
#include "HighLevelSolver.h"

class MAPFPlanner
{
public:
    SharedEnvironment* env;

	MAPFPlanner(SharedEnvironment* env): env(env){};
    MAPFPlanner(){env = new SharedEnvironment();};
	virtual ~MAPFPlanner(){delete env;};


    virtual void initialize(int preprocess_time_limit);

    // cbs function
    void readMap();
    // void printMap(Map map);
    void setAgentInMap();
    void printSolution(std::vector<std::vector<Cell>> optimalPaths);

    // return next states for all agents
    virtual void plan(int time_limit, std::vector<Action> & plan);

    // Start kit dummy implementation
    std::list<pair<int,int>>single_agent_plan(int start,int start_direct, int end);
    int getManhattanDistance(int loc1, int loc2);
    std::list<pair<int,int>> getNeighbors(int location, int direction);
    bool validateMove(int loc,int loc2);
    bool validateCollision(int loc, int loc2);
    // int isCollide(int agent_id, std::vector<Action> )
};
