

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR})

execute_process(COMMAND
    flex -o ${CMAKE_CURRENT_BINARY_DIR}/ATPlexer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/ATPlexer.l)

execute_process(COMMAND
    bison -o ${CMAKE_CURRENT_BINARY_DIR}/ATPParser.cpp ${CMAKE_CURRENT_SOURCE_DIR}/ATPParser.y)


add_executable(ATP
    
     ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/DriveVectorAST.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/ImportBlockAST.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/PinListAST.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/ProgramAST.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/VectorBlockAST.cpp

    
    ${CMAKE_CURRENT_BINARY_DIR}/ATPParser.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/ATPlexer.cpp)

target_link_libraries(ATP PUBLIC
    -lm)

