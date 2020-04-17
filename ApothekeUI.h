#pragma once

#include "ApothekeController.h"
#include "Medikament.h"


class ApothekeUI
{
private:
    ApothekeController controller;
    static void show_menu();
    void add_medicament();
    void remove_medicament();
    void change_med();
    void search_str();
    void less_med();
    void preis_group();

public:

	ApothekeUI();

    void startUI();
};

