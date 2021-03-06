#include "inc/menugui.h"
#define XWINDOW 300
#define YWINDOW 400
#define XYSETTINGS 200
#define TIMEUPDATE 25 //Window updates every 25 milliseconds (40 fps)

MenuGUI::MenuGUI(MainWindow& _app_window, QObject *parent)
    :
      QObject(parent),
      app_window(_app_window),

      //Main window
      window(sfg::Window::Create(sfg::Window::Style::NO_STYLE)),
      box(sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 20)),
      playButton(sfg::Button::Create("Play")),
      playWithCpuButton(sfg::Button::Create( "Play with CPU" )),
      settingsButton(sfg::Button::Create( "Settings" )),
      exitButton(sfg::Button::Create( "Exit" )),

      //Settings window
      settingsWindow(sfg::Window::Create(sfg::Window::Style::BACKGROUND)),
      sharedBox(sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 15)),
      settingsBox(sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 15)),
      okBox(sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 15)),
      soundButton(sfg::Button::Create( "Music enabled" )),
      musicButton(sfg::Button::Create( "Sound enabled" )),
      okButton(sfg::Button::Create( "OK" ))

{
    app_window.resetGLStates();
    backgroundT.loadFromFile("src/menuBACK.jpg");
    background.setTexture(backgroundT);
    desktop.Add(window);
    desktop.Add(settingsWindow);


    //Main window
    window->Add(box);
    window->SetAllocation(sf::FloatRect( (app_window.getX()-XWINDOW)/2 , (app_window.getY()-YWINDOW)/2, XWINDOW, YWINDOW));

    box->Pack(playButton);
    box->Pack(playWithCpuButton);
    box->Pack(settingsButton);
    box->Pack(exitButton);


    //Settings window
    settingsWindow->Add(sharedBox);
    settingsWindow->Show(false);
    settingsWindow->SetAllocation(sf::FloatRect( (app_window.getX()-XYSETTINGS)/2 - 15, (app_window.getY()-XYSETTINGS)/2, XYSETTINGS, XYSETTINGS));
    sharedBox->Pack(settingsBox);
    sharedBox->Pack(okBox);

    settingsBox->Pack(soundButton);
    settingsBox->Pack(musicButton);
    okBox->Pack(okButton);

    //Signals
    settingsButton->GetSignal( sfg::Widget::OnLeftClick ).Connect(  std::bind( &MenuGUI::clickedSettings, this ) );
    okButton->GetSignal( sfg::Widget::OnLeftClick ).Connect(  std::bind( &MenuGUI::clickedOk, this  ) );
    playButton->GetSignal( sfg::Widget::OnLeftClick ).Connect(  std::bind( &MenuGUI::clickedButton, this, ButtonPressed::PLAY ) );
    playWithCpuButton->GetSignal( sfg::Widget::OnLeftClick ).Connect(
                std::bind( &MenuGUI::clickedButton, this, ButtonPressed::PLAY_WITH_CPU ) );
    exitButton->GetSignal( sfg::Widget::OnLeftClick ).Connect(  std::bind( &MenuGUI::clickedButton, this, ButtonPressed::EXIT ) );
    soundButton->GetSignal( sfg::Widget::OnLeftClick ).Connect(  std::bind( &MenuGUI::clickedButton, this, ButtonPressed::SOUND ) );
    musicButton->GetSignal( sfg::Widget::OnLeftClick ).Connect(  std::bind( &MenuGUI::clickedButton, this, ButtonPressed::MUSIC ) );

}

void MenuGUI::clickedSettings()
{
    settingsWindow->Show(true);
    desktop.BringToFront(settingsWindow);
    window->SetState(sfg::Widget::State::INSENSITIVE);
}
void MenuGUI::clickedOk()
{
    settingsWindow->Show(false);
    window->SetState(sfg::Widget::State::NORMAL);
}

//Connecting Buttons and Qt signals
void MenuGUI::clickedButton(ButtonPressed Button)
{
    switch (Button)
    {
        case PLAY: clickedPlay(); break;
        case PLAY_WITH_CPU: clickedPlayCPU(); break;
        case EXIT: clickedExit(); break;
        case MUSIC:clickedMusic(); break;
        case SOUND:clickedSound(); break;
    }
}

void MenuGUI::show()
{
   window->Show(true);
   timer = app_window.newTimer();
   connect(timer, SIGNAL(timeout()), this, SLOT(update()));
   timer->start(TIMEUPDATE);
}

void MenuGUI::update()
{
    static bool flag = true;

    if(app_window.isOpen())
    {
        sf::Event event;
        while(app_window.pollEvent(event))
        {
              desktop.HandleEvent(event);

            if (event.type == sf::Event::Closed)
            {
                app_window.close();
                closed();
            }
        }
        desktop.Update( 10 );
        app_window.clear();
        app_window.draw(background);
        sfgui.Display(app_window);
        app_window.display();
    }

    else if(flag)
    {
        flag = false;
        closed();
    }
}

void MenuGUI::hide()
{
    window->Show(false);
    settingsWindow->Show(false);
    desktop.Add(settingsWindow);
    app_window.deleteTimer();
    app_window.clear(sf::Color::Black);
    app_window.display();
}

void MenuGUI::setSounds(bool)
{

}

void MenuGUI::setMusic(bool)
{

}
