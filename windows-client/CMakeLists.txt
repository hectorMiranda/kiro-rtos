cmake_minimum_required(VERSION 3.16)
project(SpiritOfKiroClient VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets SerialPort)

# Source files
set(SOURCES
    src/main.cpp
    src/core/application.cpp
    src/core/game_manager.cpp
    src/serial/serial_port.cpp
    src/flash/flash_manager.cpp
    src/ui/main_window.cpp
    src/ui/game_library_widget.cpp
    src/ui/device_monitor_widget.cpp
    src/utils/file_utils.cpp
)

# Header files
set(HEADERS
    include/core/application.h
    include/core/game_manager.h
    include/serial/serial_port.h
    include/flash/flash_manager.h
    include/ui/main_window.h
    include/ui/game_library_widget.h
    include/ui/device_monitor_widget.h
    include/utils/file_utils.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Link libraries
target_link_libraries(${PROJECT_NAME} 
    Qt6::Core 
    Qt6::Widgets 
    Qt6::SerialPort
)

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Copy resources
file(COPY resources DESTINATION ${CMAKE_BINARY_DIR}/bin)