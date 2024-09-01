cmake_minimum_required(VERSION 3.10)

# Название проекта
set(PROJECT_NAME "SuperMarioClone")
project(${PROJECT_NAME})

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указываем путь к SFML
# Замените путь на тот, где вы распаковали SFML
set(SFML_DIR "external/SFML-2.6.1/lib/cmake/SFML")

# Подключаем SFML
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

# Указываем исполняемый файл
add_executable(
    ${PROJECT_NAME} 
    src/main.cpp
    src/game/Game.h
    src/game/Game.cpp
    src/game/Player.h
    src/game/Player.cpp
    src/game/TextLabel.h
    src/game/TextLabel.cpp
    src/engine/ResourceManager.h
    src/engine/ResourceManager.cpp
)

# Подключаем библиотеки SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

# Копирование DLL в папку с исполняемым файлом
if(WIN32)
    # Определяем путь к DLL
    set(SFML_BIN_DIR "external/SFML-2.6.1/bin")

    # Перечислите все необходимые DLL
    file(GLOB DLLS "${SFML_BIN_DIR}/*.dll")

    # Цикл для копирования DLL
    foreach(DLL ${DLLS})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${DLL}"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)
    endforeach()
endif()

# Копирование папки assets в выходную директорию
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/assets"           # Источник
    "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets"  # Целевая директория
)