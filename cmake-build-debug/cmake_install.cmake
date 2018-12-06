# Install script for directory: /Users/francescocolonnese/Desktop/CS/CS8 Tests/test3/flights_backend

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/simple-web-server" TYPE FILE FILES
    "/Users/francescocolonnese/Desktop/CS/CS8 Tests/test3/flights_backend/server_http.hpp"
    "/Users/francescocolonnese/Desktop/CS/CS8 Tests/test3/flights_backend/client_http.hpp"
    "/Users/francescocolonnese/Desktop/CS/CS8 Tests/test3/flights_backend/server_https.hpp"
    "/Users/francescocolonnese/Desktop/CS/CS8 Tests/test3/flights_backend/client_https.hpp"
    "/Users/francescocolonnese/Desktop/CS/CS8 Tests/test3/flights_backend/crypto.hpp"
    "/Users/francescocolonnese/Desktop/CS/CS8 Tests/test3/flights_backend/utility.hpp"
    "/Users/francescocolonnese/Desktop/CS/CS8 Tests/test3/flights_backend/status_code.hpp"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/francescocolonnese/Desktop/CS/CS8 Tests/test3/flights_backend/cmake-build-debug/tests/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/francescocolonnese/Desktop/CS/CS8 Tests/test3/flights_backend/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
