cmake_minimum_required(VERSION 3.18.2)

set(BOOST_NAME boosttest)

project(${BOOST_NAME})

set(BOOST_SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/io_service_test.cpp
)
message("BOOST_SRC is ${BOOST_SRC}------------------------->")

set(BOOST_INCLUDE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/boost_1_71_0/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/openssl/include
)

set(THIRD_LIB ${CMAKE_CURRENT_SOURCE_DIR}/third_party/third_libs)

link_directories(${THIRD_LIB})

include_directories(
    ${BOOST_INCLUDE}
)
# set(CMAKE_BUILD_TYPE "Debug")
# set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
# set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


add_executable(
    ${BOOST_NAME} 
    ${BOOST_SRC}
)

target_link_libraries(
    ${BOOST_NAME}
    libboost_atomic.a     
    libboost_exception.a   
    libboost_math_c99.a   
    libboost_prg_exec_monitor.a      
    libboost_stacktrace_basic.a     
    libboost_wserialization.a
    libboost_chrono.a     
    libboost_fiber.a       
    libboost_math_c99f.a  
    libboost_program_options.a       
    libboost_stacktrace_noop.a
    libboost_container.a  
    libboost_filesystem.a  
    libboost_math_c99l.a  
    libboost_random.a                
    libboost_system.a
    libboost_context.a    
    libboost_graph.a       
    libboost_math_tr1.a   
    libboost_regex.a                 
    libboost_timer.a
    libboost_contract.a   
    libboost_iostreams.a   
    libboost_math_tr1f.a  
    libboost_serialization.a         
    libboost_unit_test_framework.a
    libboost_date_time.a  
    libboost_locale.a      
    libboost_math_tr1l.a  
    libboost_stacktrace_backtrace.a  
    libboost_wave.a
    libssl.a
    libcrypto.a
)


