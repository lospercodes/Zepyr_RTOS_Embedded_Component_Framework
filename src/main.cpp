#include <iostream>
#include <cstdint>

#include "component_base.hpp"
#include "main_application.hpp"

int main(void)
{
    
    static MainApplication app_main;
    app_main.start();
    return 0;
}

