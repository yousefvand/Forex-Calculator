cmake_minimum_required(VERSION 3.16)

project(Forex-Calculator VERSION 0.1 LANGUAGES CXX)

# Enable automatic handling of Qt6 features
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Use C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable strict compiler warnings (optional)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find Qt6 packages in a single call
find_package(
    Qt6
    REQUIRED
    COMPONENTS
    Core
    Gui
    Widgets
    LinguistTools
)

# Translation files (optional)
set(TS_FILES translations/Forex-Calculator_en_GB.ts)

set(PROJECT_UI
    src/mainwindow.ui
    src/pip_calculator.ui
    src/margin_calculator.ui
    src/lot_size_calculator.ui
    src/profit_and_loss_calculator.ui
    src/position_size_calculator.ui
    src/risk_management_calculator.ui
    src/risk_reward_calculator.ui
    src/swap_calculator.ui
    src/currency_converter.ui
    src/fibonacci_calculator.ui
    src/volatility_calculator.ui
    src/break_even_calculator.ui
    src/compound_interest_calculator.ui
)

set(CMAKE_AUTOUIC_SEARCH_PATHS src)

set(PROJECT_SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/breakevencalculator.cpp
    src/breakevencalculator.h
    src/compoundinterestcalculator.cpp
    src/compoundinterestcalculator.h
    src/currencyconverter.cpp
    src/currencyconverter.h
    src/fibonaccicalculator.cpp
    src/fibonaccicalculator.h
    src/lotsizecalculator.cpp
    src/lotsizecalculator.h
    src/margincalculator.cpp
    src/margincalculator.h
    src/pipcalculator.cpp
    src/pipcalculator.h
    src/positionsizecalculator.cpp
    src/positionsizecalculator.h
    src/profitandlosscalculator.cpp
    src/profitandlosscalculator.h
    src/riskmanagementcalculator.cpp
    src/riskmanagementcalculator.h
    src/riskrewardcalculator.cpp
    src/riskrewardcalculator.h
    src/swapcalculator.cpp
    src/swapcalculator.h
    src/volatilitycalculator.cpp
    src/volatilitycalculator.h
    ${PROJECT_UI}
)

# Add Qt6 executable
qt_add_executable(Forex-Calculator
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

# Link Qt6 libraries
target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets
)

# Set properties for macOS/iOS and Windows
set_target_properties(Forex-Calculator PROPERTIES
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    WIN32_EXECUTABLE TRUE
)

# Installation setup
include(GNUInstallDirs)
install(TARGETS Forex-Calculator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Optional: Add translation files to target (if available)
qt_add_translation(QM_FILES ${TS_FILES})
if(QM_FILES)
    install(FILES ${QM_FILES} DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/translations)
endif()

# Finalize the Qt6 executable setup
qt_finalize_executable(Forex-Calculator)
