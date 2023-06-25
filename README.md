# cpp-fun

A fun little side project I've been working on to mess aroung with graphics in C++.

Specifically I am using a functional programming style as opposed to OOP. I started out using OOP
but found it to be really annoying, and found [this article](http://sevangelatos.com/john-carmack-on/) written by John Carmack on the 
benefits of writing C++ code, especially multi-threaded game dev code, in a more functional style.

I recommend reading the entire article, but to keep it short, at the end he quips that it would be nice
> if all of the object just referenced a read only version of the world state, and we copied over the
updated version at the end of the frame.

So this is exactly what I do. Very easy for me to do/say as a single person writing in this codebase
from scratch. Probably harder to do on a team, and maybe impossible to do on a professional level.

At first it was really annoying to have to construct entire new objects instead of simply surgically
mutating the state that I needed to, but after running into a few logic errors I'm already seeing
the benefits of this functional style. The logic for my collision wasn't working originally (the
true's and false's were flipped) and since all my functions are pure I was able to write some unit
tests very easily for the buildCollisionState function, and immediately found out the problem. There
wasn't even a possibility that there was some weird threading/SFML stuff going on, I knew the issue
had to be a logical one, due to the properties of pure functions. Very nice stuff. I can only
imagine the benefits multiplying as the code becomes more complex.

## Usage

This project uses CMake. You will have to install all of the SFML dev dependencies to get this to 
work, so good luck to you. You can find what they all are in the SFML documentation.

If you really want to run this for some reason, and you have installed all of the dozen or so dev 
dependencies, then you can do this to run it: 
```
cd cpp-fun/build/
cmake ..
make
./cpp-fun
```
Or these to run the unit tests:
```
cd cpp-fun/build
cmake ..
make
./cpp-fun-tests
```
