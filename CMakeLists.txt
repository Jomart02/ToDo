set(TARGET todo)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(MOC_HDRS
    mainwindow.h
    settingupdate.h

)

set(SRCS ${MOC_HDRS}
    main.cpp
    mainwindow.cpp
    settingupdate.cpp

)

set(UIS
    mainwindow.ui
)


# Сюда пишем файл(ы) ресурсов
set(QRCS style/res.qrc)



add_executable(${TARGET} ${SRCS} ${UIS} ${QRCS})

target_link_libraries(${TARGET} Qt5::Widgets)

