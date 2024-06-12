#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
  robot_status_t status = { 
    (robot_direction_t){ direction },
    { x, y }
  };
  return status;
}

void robot_move(robot_status_t *robot, const char *commands) 
{
  robot_status_t movements[] = {
    { (robot_direction_t){ DIRECTION_NORTH }, { 0,1 } },
    { (robot_direction_t){ DIRECTION_EAST }, { 1,0 } },
    { (robot_direction_t){ DIRECTION_SOUTH }, { 0,-1 } },
    { (robot_direction_t){ DIRECTION_WEST }, { -1,0 } }
  };
  while(commands && *commands!='\0')
  {
    int current_direction = robot->direction;
    if (*commands == 'R')
    {
      robot->direction = (current_direction + 1 + 4) % 4;
    }
    if (*commands == 'L')
    {
      robot->direction = (current_direction - 1 + 4) % 4;
    }
    if (*commands == 'A')
    {
      robot->position.x += movements[current_direction].position.x;
      robot->position.y += movements[current_direction].position.y;
    }

    commands++;
  }
}
