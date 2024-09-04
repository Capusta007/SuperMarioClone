cmake_minimum_required(VERSION 3.10)

# Название проекта
set(PROJECT_NAME "SuperMarioClone")
project(${PROJECT_NAME})

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Добавляем игру
add_subdirectory(Game)
# Добавляем редактор уровней
add_subdirectory(LevelEditor)