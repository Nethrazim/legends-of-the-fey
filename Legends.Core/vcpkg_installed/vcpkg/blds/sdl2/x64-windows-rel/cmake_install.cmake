# Install script for directory: B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/pkgs/sdl2_x64-windows")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "OFF")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/SDL2.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/SDL2.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE OPTIONAL FILES "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/SDL2.pdb")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/SDL2main.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE OPTIONAL FILES "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/CMakeFiles/SDL2main.dir/SDL2main.pdb")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake"
         "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2Targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2Targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2Targets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets.cmake"
         "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2mainTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2mainTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/CMakeFiles/Export/272ceadb8458515b2ae4b5630a6029cc/SDL2mainTargets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/SDL2Config.cmake"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/SDL2ConfigVersion.cmake"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/cmake/sdlfind.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_assert.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_atomic.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_audio.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_bits.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_blendmode.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_clipboard.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_copying.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_cpuinfo.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_egl.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_endian.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_error.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_events.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_filesystem.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_gamecontroller.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_gesture.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_guid.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_haptic.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_hidapi.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_hints.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_joystick.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_keyboard.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_keycode.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_loadso.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_locale.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_log.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_main.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_messagebox.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_metal.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_misc.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_mouse.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_mutex.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_name.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_opengl.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_opengl_glext.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_opengles.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_opengles2.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_opengles2_gl2.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_opengles2_gl2ext.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_opengles2_gl2platform.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_opengles2_khrplatform.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_pixels.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_platform.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_power.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_quit.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_rect.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_render.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_rwops.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_scancode.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_sensor.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_shape.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_stdinc.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_surface.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_system.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_syswm.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_test.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_test_assert.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_test_common.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_test_compare.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_test_crc32.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_test_font.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_test_fuzzer.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_test_harness.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_test_images.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_test_log.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_test_md5.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_test_memory.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_test_random.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_thread.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_timer.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_touch.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_types.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_version.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_video.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/SDL_vulkan.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/begin_code.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/include/close_code.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/include/SDL2/SDL_revision.h"
    "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/include-config-release/SDL2/SDL_config.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/licenses/SDL2" TYPE FILE FILES "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/src/se-2.32.10-3b143ac573.clean/LICENSE.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/sdl2.pc")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "B:/Workspace/legends-of-the-fey/Legends.Core/vcpkg_installed/vcpkg/blds/sdl2/x64-windows-rel/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
