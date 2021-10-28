add_rules("mode.debug", "mode.release")

add_requires("raylib =3.7.0")

target("Shoot")
    set_kind("binary")
    add_files("../Source/*.cpp")
    add_includedirs("../Header")
    add_packages("raylib")
    set_languages("c++11")
