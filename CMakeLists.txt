cmake_minimum_required(VERSION 3.5)

project(obs-midi)

########################################
# find libobs                                                          #
########################################
#include(external/ObsPluginHelpers.cmake)
#include(external/FindLibObs.cmake)
#find_package(LibObs REQUIRED)

include_directories(
	/
	/rtmidi-3.0.0
#	"${LIBOBS_INCLUDE_DIR}/../UI/obs-frontend-api"
)

#set(OBS_FRONTEND_LIB "OBS_FRONTEND_LIB-NOTFOUND" CACHE FILEPATH "OBS frontend library")
#if(OBS_FRONTEND_LIB EQUAL "OBS_FRONTEND_LIB-NOTFOUND")
#	message(FATAL_ERROR "Could not find OBS Frontend API\'s library !")
#endif()

set(obs-midi_SOURCES
	obs-midi.cpp
)

add_library(obs-midi MODULE
	${obs-midi_SOURCES}
)

target_link_libraries(obs-midi
	libobs
#	"${OBS_FRONTEND_LIB}"
)

install_obs_plugin_with_data(obs-midi data)
#install_external_plugin_with_data(rematrix-filter data)