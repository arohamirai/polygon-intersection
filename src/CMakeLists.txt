project(PolygonIntersec)
cmake_minimum_required(VERSION 2.8)

if(WIN32) # if windows, insert your opencv path.
	set(OpenCV_DIR "C:/OpenCV/opencv-2.4.9/build")
endif(WIN32)

find_package(OpenCV REQUIRED)

add_executable(polygonIntersect main.cpp polygonIntersect.cpp)
target_link_libraries(polygonIntersect ${OpenCV_LIBS})
