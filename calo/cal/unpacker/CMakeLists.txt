Set(SYSTEM_INCLUDE_DIRECTORIES 
${SYSTEM_INCLUDE_DIRECTORIES}
${BASE_INCLUDE_DIRECTORIES}
)


set(INCLUDE_DIRECTORIES
${ENSARROOT_SOURCE_DIR}/calo/cal/unpack
${ENSARROOT_SOURCE_DIR}/calo/cal/unpacker
)

include_directories( ${INCLUDE_DIRECTORIES})
include_directories(SYSTEM ${SYSTEM_INCLUDE_DIRECTORIES})

set(LINK_DIRECTORIES
${ROOT_LIBRARY_DIR}
${FAIRROOT_LIBRARY_DIR}
) 

link_directories( ${LINK_DIRECTORIES} )

#string(TOUPPER "CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE}" CMAKE_CXX_FLAGS_NAME)
#set( ${CMAKE_CXX_FLAGS_NAME} "${${CMAKE_CXX_FLAGS_NAME}} --foo")
#set(CXX_FLAGS_SAFE "${${CMAKE_CXX_FLAGS_NAME}} -std=c++1y -Wall -Wno-shadow -Wfatal-errors")

#set(OPTIONSDEF "-DM=FairRunOnline(FairLmdSource(R3BCaloUnpack),R3BCaloRawAna)")
#set( ${CMAKE_CXX_FLAGS_NAME} "${CXX_FLAGS_SAFE} ${OPTIONSDEF} " )
#MESSAGE("flags: ${CMAKE_CXX_FLAGS_NAME} = ${${CMAKE_CXX_FLAGS_NAME}} x ${CMAKE_CXX_FLAGS}")
#set( ${CMAKE_CXX_FLAGS} "${CMAKE_CXX_FLAGS_NAME}" )
add_compile_options(-std=c++1y -Wall -Wno-shadow -Wfatal-errors)
#
set(MAIN_SRCS OptionWrappers.cxx fixROOT.cxx )

add_executable(caloUnpack ${MAIN_SRCS})
target_compile_options(caloUnpack PUBLIC "-DMAIN=FairRunOnline(FairLmdSource(R3BCaloUnpack),R3BCaloRawAna)" )
target_link_libraries(caloUnpack ParBase Base R3Bbase R3BCaloCal dl ${Boost_LIBRARIES})

#add_executable(caloUnpackTest ${MAIN_SRCS})
#target_compile_options(caloUnpackTest PUBLIC 
#  "-DMAIN=FairRunOnline(FairLmdSource(R3BCaloUnpack),R3BCaloRawAna,R3BCaloCalibParFinder)" )
#target_link_libraries(caloUnpackTest ParBase Base R3Bbase R3BCaloCal dl boost_program_options)
