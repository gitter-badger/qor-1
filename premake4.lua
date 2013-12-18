solution("qor")
    configurations {"Debug", "Release"}

    targetdir("bin")

    configuration "debug"
        defines { "DEBUG" }
        flags { "Symbols" }
    configuration "release"
        defines { "NDEBUG" }
        flags { "OptimizeSpeed" }

    project("qor")
        --uuid("")
        kind("WindowedApp")
        language("C++")
        links {
            "pthread",
            "GL",
            "GLU",
            "SDL2",
            "SDL2main",
            "GLEW",
            "assimp",
            "IL",
            "ILU",
            --"OALWrapper",
            "openal",
            "alut",
            --"ogg",
            --"vorbis",
            --"vorbisfile",
            --"ftgl",
            "boost_system",
            "boost_filesystem",
            "boost_python",
            "jsoncpp",
            "RocketCore",
            --"CEGUIBase-0",
            --"CEGUIOpenGLRenderer-0",
            --"freetype-gl++",
            --"BulletDynamics"
        }
        files {
            "src/**.h",
            "src/**.cpp"
        }
        excludes {
            "src/tests/**",
            "src/scripts/**",
            "src/shaders/**"
        }
        includedirs {
            "vendor/include/",
            "/usr/local/include/",
            --"/usr/include/cegui-0/",
            "/usr/include/bullet/",
        }
        libdirs {
            "/usr/lib/cegui-0.8/",
            "/usr/local/lib/",
            "/usr/local/lib64/",
        }
        buildoptions { "`python2-config --includes`" }
        linkoptions { "`python2-config --libs`" }
        configuration {"debug"}
            defines { "BACKWARD_HAS_BFD=1" }
            links {
                "bfd",
                "iberty"
            }
            --buildoptions { "-finstrument-functions" }
            linkoptions { "`llvm-config --libs core` `llvm-config --ldflags`" }
        configuration {}

        --configuration { "linux" }
        --    includedirs {
        --        "/usr/include/lua5.1",
        --    }
        --configuration {}

        configuration { "gmake" }
            buildoptions { "-std=c++11",  "-pedantic", "-Wall", "-Wextra" }
            configuration { "macosx" }
                buildoptions { "-U__STRICT_ANSI__", "-stdlib=libc++" }
                linkoptions { "-stdlib=libc++" }
        configuration {}
        
    project("qor_test")
        --uuid("")
        kind("ConsoleApp")
        language("C++")
        links {
            "pthread",
            "GL",
            "GLU",
            "SDL2",
            "SDL2main",
            "GLEW",
            "IL",
            "ILU",
            --"OALWrapper",
            "openal",
            "alut",
            --"ogg",
            --"vorbis",
            --"vorbisfile",
            --"ftgl",
            "boost_system",
            "boost_filesystem",
            "boost_python",
            "jsoncpp",
            "RocketCore",
            "RocketControls",
            --"CEGUIBase-0",
            --"CEGUIOpenGLRenderer-0",
            --"freetype-gl++",
            --"BulletDynamics"
        }
        files {
            "src/**.h",
            "src/**.cpp"
        }
        excludes {
            "src/Main.cpp",
            "src/scripts/**",
            "src/shaders/**"
        }
        includedirs {
            "vendor/include/",
            "/usr/local/include/",
            --"/usr/include/cegui-0/",
            "/usr/include/bullet/",
        }
        libdirs {
            --"/usr/lib/cegui-0.8/"
            "/usr/local/lib/",
            "/usr/local/lib64/",
        }
        buildoptions { "`python2-config --includes`" }
        linkoptions { "`python2-config --libs`" }
        configuration {"debug"}
            defines { "BACKWARD_HAS_BFD=1" }
            links {
                "bfd",
                "iberty"
            }
            --buildoptions { "-finstrument-functions" }
            linkoptions { "`llvm-config --libs core` `llvm-config --ldflags`" }
        configuration {}

        --configuration { "linux" }
        --    includedirs {
        --        "/usr/include/lua5.1",
        --    }
        --configuration {}

        configuration { "gmake" }
            buildoptions { "-std=c++11",  "-pedantic", "-Wall", "-Wextra" }
            configuration { "macosx" }
                buildoptions { "-U__STRICT_ANSI__", "-stdlib=libc++" }
                linkoptions { "-stdlib=libc++" }
        configuration {}

