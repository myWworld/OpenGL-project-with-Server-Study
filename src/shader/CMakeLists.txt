# 셰이더 파일들을 빌드 디렉토리로 복사
file(COPY shaders DESTINATION ${CMAKE_BINARY_DIR})


# 셰이더 라이브러리 생성
add_library(shader
    shader.cpp
    shader.h
)

# 필요한 라이브러리 링크
target_link_libraries(shader
    ${OPENGL_LIBRARIES}
    glfw
    glad
)

# shader 라이브러리의 include 디렉토리 설정
target_include_directories(shader PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)