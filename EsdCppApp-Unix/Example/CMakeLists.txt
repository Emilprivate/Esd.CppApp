# Create example executable
add_executable(EsdCppAppExample
        Main.cpp
        )

# Link the example with EsdCppApp library
target_link_libraries(EsdCppAppExample
        PRIVATE
        EsdCppApp
        )
