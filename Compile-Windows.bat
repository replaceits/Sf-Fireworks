mingw32-g++.exe -std=c++0x -Wall -DSFML_STATIC -c Src\Explosion.cpp -o Explosion.o
mingw32-g++.exe -std=c++0x -Wall -DSFML_STATIC -c Src\Firework.cpp -o Firework.o
mingw32-g++.exe -std=c++0x -Wall -DSFML_STATIC -c Src\Main.cpp -o Main.o
mingw32-g++.exe -std=c++0x -Wall -DSFML_STATIC -c Src\Particle.cpp -o Particle.o
mingw32-g++.exe -o Sf-Fireworks.exe Explosion.o Firework.o Main.o Particle.o -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -static-libgcc -static-libstdc++ -s -mwindows
del Explosion.o
del Firework.o
del Main.o
del Particle.o
