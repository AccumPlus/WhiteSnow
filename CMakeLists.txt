cmake_minimum_required(VERSION 2.8.11)

set(PROJECT Temp)

set (SRC 	main.cpp
			Camera.cpp
			Object.cpp
			ObjectArray.cpp
			Position.cpp
			Printer.cpp
			Sprite.cpp
			SpriteSegment.cpp)

set (HDR 	Camera.h
			Object.h
			ObjectArray.h
			Position.h
			Printer.h
			Sprite.h
			SpriteSegment.h)

add_executable(${PROJECT} ${SRC} ${HDR})

target_link_libraries(${PROJECT} ncurses)
