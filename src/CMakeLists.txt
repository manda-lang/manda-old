include(ExternalProject)
find_package(Readline)

add_library(${MANDA_LIBRARY}
        vm/Memory.cpp vm/Memory.h
        vm/VM.cpp vm/VM.h
        vm/Fiber.cpp vm/Fiber.h
        vm/Object.cpp vm/Object.h
        vm/Type.cpp vm/Type.h
        vm/Number.cpp vm/Number.h
        vm/Function.cpp vm/Function.h
        vm/Symbol.cpp vm/Symbol.h
        vm/SymbolTable.cpp vm/SymbolTable.h)
target_link_libraries(${MANDA_LIBRARY} ${SYMBOL_TABLE_CPP})

add_executable(${MANDA_EXECUTABLE} entrypoint/main.cc)

target_link_libraries(${MANDA_EXECUTABLE} ${MANDA_LIBRARY} ${Readline_LIBRARY})
set_target_properties(${MANDA_EXECUTABLE} PROPERTIES OUTPUT_NAME ${MANDA_LIBRARY})

install(TARGETS ${MANDA_LIBRARY} ${MANDA_EXECUTABLE}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)