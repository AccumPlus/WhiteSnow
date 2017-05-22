cmake_minimum_required(VERSION 2.8.11)

set (CMAKE_BUILD_TYPE Debug)

set(PROJECT Temp)

set (SRC 	main.cpp
			myObject/myObject.cpp
			myObject2/myObject2.cpp
			Controller.cpp
			Camera.cpp
			Object.cpp
			ObjectArray.cpp
			Position.cpp
			Printer.cpp
			Sprite.cpp
			SpriteSegment.cpp)

set (HDR 	Camera.h
			myObject2/myObject2.h
			Controller.h
			Object.h
			ObjectArray.h
			Position.h
			Printer.h
			Sprite.h
			SpriteSegment.h)

add_executable(${PROJECT} ${SRC} ${HDR})

target_link_libraries(${PROJECT} ncurses pthread)
