cmake_minimum_required(VERSION 3.20)
project(db_internals)

set(CMAKE_CXX_STANDARD 17)

# ==========================================
# PROJECT 1: FAST-LOG (Learning Phase)
# ==========================================

# Assignment 1: Text vs Binary
add_executable(01_text_vs_binary projects/fast-log/learning/01_text_vs_binary.cpp)

# Assignment 2: The Packet Writer
add_executable(02_packet_writer projects/fast-log/learning/02_packet_writer.cpp)

# Assignment 3: The Crash Recovery Reader
add_executable(03_packet_reader projects/fast-log/learning/03_packet_reader.cpp)
add_executable(04_ring_buffer projects/fast-log/learning/04_ring_buffer.cpp)
