cmake_minimum_required(VERSION 3.22)
project(StoreAppTester)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS_DIR
        ../StoreApp/headers)
set(PROJECT_SOURCES_DIR
        ../StoreApp/sources)

set(PROJECT_HEADERS_EXCEPTIONS_DIR
        ${PROJECT_HEADERS_DIR}/exceptions)
set(PROJECT_SOURCES_EXCEPTIONS_DIR
        ${PROJECT_SOURCES_DIR}/exceptions)
include_directories(
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}
        ${PROJECT_SOURCES_EXCEPTIONS_DIR})

set(EXCEPTIONS_SOURCE_FILES
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}/DataConsistencyException.h
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/DataConsistencyException.cpp
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}/DuplicatedDataException.h
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/DuplicatedDataException.cpp
        ${PROJECT_HEADERS_EXCEPTIONS_DIR}/InvalidDataException.h
        ${PROJECT_SOURCES_EXCEPTIONS_DIR}/InvalidDataException.cpp)


set(PROJECT_HEADERS_MODEL_DIR
        ${PROJECT_HEADERS_DIR}/model)
set(PROJECT_SOURCES_MODEL_DIR
        ${PROJECT_SOURCES_DIR}/model)
include_directories(
        ${PROJECT_HEADERS_MODEL_DIR}
        ${PROJECT_SOURCES_MODEL_DIR})

set(MODEL_SOURCE_FILES
        ${PROJECT_HEADERS_MODEL_DIR}/Estabelecimento.h
        ${PROJECT_SOURCES_MODEL_DIR}/Estabelecimento.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Produto.h
        ${PROJECT_SOURCES_MODEL_DIR}/Produto.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Lojas.h
        ${PROJECT_SOURCES_MODEL_DIR}/Lojas.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Gestao.h
        ${PROJECT_SOURCES_MODEL_DIR}/Gestao.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/EstabelecimentoContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/EstabelecimentoContainer.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/ProdutoContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/ProdutoContainer.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/GestaoContainer.h
        ${PROJECT_SOURCES_MODEL_DIR}/GestaoContainer.cpp
        ${PROJECT_SOURCES_MODEL_DIR}/Preco.cpp
        ${PROJECT_HEADERS_MODEL_DIR}/Preco.h)

set(PROJECT_HEADERS_VIEWS_DIR
        ${PROJECT_HEADERS_DIR}/views)
set(PROJECT_SOURCES_VIEWS_DIR
        ${PROJECT_SOURCES_DIR}/views)
include_directories(
        ${PROJECT_HEADERS_VIEWS_DIR}
        ${PROJECT_SOURCES_VIEWS_DIR})
set(VIEWS_SOURCE_FILES
        ${PROJECT_HEADERS_VIEWS_DIR}/Utils.h
        ${PROJECT_SOURCES_VIEWS_DIR}/Utils.cpp
        ${PROJECT_HEADERS_VIEWS_DIR}/View.h
        ${PROJECT_SOURCES_VIEWS_DIR}/View.cpp
        ${PROJECT_HEADERS_VIEWS_DIR}/EstabelecimentoView.h
        ${PROJECT_SOURCES_VIEWS_DIR}/EstabelecimentoView.cpp
        ${PROJECT_HEADERS_VIEWS_DIR}/GestaoView.h
        ${PROJECT_SOURCES_VIEWS_DIR}/GestaoView.cpp
        ${PROJECT_HEADERS_VIEWS_DIR}/ProdutoView.h
        ${PROJECT_SOURCES_VIEWS_DIR}/ProdutoView.cpp)

set(GOOGLE_TEST_LIB
        ${PROJECT_SOURCE_DIR}/googleTestLib/googletest-main)
set(GOOGLE_TEST_LIB_INCLUDE
        ${GOOGLE_TEST_LIB}/googletest/include)

add_subdirectory(${GOOGLE_TEST_LIB})
include_directories(${GOOGLE_TEST_LIB_INCLUDE})


add_executable(
        StoreAppTester
        main.cpp
        estabelecimento_test.cpp
        produto_test.cpp
        ${MODEL_SOURCE_FILES}
        ${VIEW_SOURCE_FILES}
        ${EXCEPTIONS_SOURCE_FILES})

target_link_libraries(StoreAppTester gtest gtest_main)

