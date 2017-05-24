cmake_minimum_required(VERSION 2.8.11)

set (CMAKE_BUILD_TYPE Debug)

set(PROJECT Temp)

set (SRC 	main.cpp
			myObject/myObject.cpp
			myObject2/myObject2.cpp
			Camera.cpp
			Controller.cpp
			Event.cpp
			Input.cpp
			Object.cpp
			ObjectArray.cpp
			Position.cpp
			Printer.cpp
			Sprite.cpp
			SpriteObject.cpp)

set (HDR 	
			myObject2/myObject2.h
			myObject/myObject.h
			Camera.h
			Controller.h
			Event.h
			Input.h
			Object.h
			ObjectArray.h
			Position.h
			Printer.h
			Sprite.h
			SpriteObject.h)

add_executable(${PROJECT} ${SRC} ${HDR})

target_link_libraries(${PROJECT} ncurses pthread)
