# Piscine C++ rush#00 FT_RETRO, Feb 2015
>>>>> #####Shoot them up with n-curses. (group project)

#####Grade ``(TBD/125)`` ``(TBD/125)*``
--------  -----------------------

<br>

Team: [wide-aze](https://github.com/wide-aze) / [ngoguey](https://github.com/Ngoguey42).
 
### Classes tree:

```cpp
class Game
class Background
class Scheduler

class IMovIA
class AMovPatternLombric : public IMovIA
class AMovPatternDefault : public IMovIA
class AMovPatternSheep : public IMovIA

class IShootIA
class AShootPatternDefault : IShootIA

class AObject
class Shape
class Player : public AObject
class Sheep : public AObject, public AMovPatternSheep
class Fizzy : public AObject, public AMovPatternFizzy
class Lombric : public AObject, public AMovPatternLombric
class Centipede : public AObject, public AMovPatternSheep, public AShootPatternDefault
class Pig : public AObject, public AMovPatternSheep, public AShootPatternDefault
class Snake : public AObject, public AMovPatternSheep, public AShootPatternTriple
class Missile : public AObject, public AMovPatternMissile
```

<br><br><br><br><br><br><br><br>

```
*
- A grade of 85 was required to validate the project.
- A maximum grade of 125 was reachable.
- Second sessions are organised for failed projects.
```
