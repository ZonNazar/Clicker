#ifndef CLICKER_ENEMY_H
#define CLICKER_ENEMY_H
#include <iostream>

class Enemy {
private:
    int _hp;
public:
    Enemy &operator=(const Enemy &rhs);
    Enemy();
    Enemy(int hp);
  virtual ~Enemy();
};


#endif
