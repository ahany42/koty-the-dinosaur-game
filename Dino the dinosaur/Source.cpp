#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Main.hpp>
#include <iostream>
using namespace std;
using namespace sf;
//Structs
struct Menu {
    Sprite spMainMenu;
    Sprite spPopupIcon;
    Sprite spOptions;
    Sprite spCredits;
    Sprite spGameover;
    Sprite spDino;
    Sprite spDino1;
    Sprite spDino2;
    Sprite spDino3;
    Sprite spPause;
    Sprite spPreset;
    Sprite spbackground1;
    Sprite spMoon;
    Sprite spbackground2[2];
    Sprite spbackground3[2];
    Sprite spbackground4[2];
    Sprite smallcactus[3];
    Sprite cactus[3];
    Sprite cloud[2];
    Sprite spBat[3];
    RectangleShape ground;
    Sound Sclick0;
    Sound Soundexit;
    Music Game;
    int finalhiscore = 0;
    int ScreenIndex = 0, GameDifficulty = 0;
    int score = 0;
    int timer = 0;
    int smallcactdist = 0;
    int timer1;
    int timer2 = 0;
    int DinoIndex = 0;
    int BatIndex = 0;
    bool grounded = false;
    bool isCrouch;
    bool isONclicked = true;
    bool isOFFclicked = false;
    bool isDefault = true;
    bool isRed = false;
    bool isBlue = false;
    bool isPurple = false;
    bool isStart = true;
    double GameVelocity;
    double background1Vel;
    double background2Vel;
    double  VelocityY = 0;
    int deadindex;
    bool isarrow = true;
    bool isws = false;
    Clock time;
    Clock time1;
    Clock time2;
    Text  scorenum;
    Text highscore;
};
struct Texs {

    //Light backgrounds
    Texture txbackground1;
    Texture txbackground2;
    Texture txbackground3;
    Texture txbackground4;
    //Dark backgrounds
    Texture txbackground1dark;
    Texture txbackground2dark;
    Texture txbackground3dark;
    Texture txbackground4dark;
    //menus 
    Texture txMainMenu;
    Texture txPopupIcon;
    Texture txPopupScreen;
    Texture txPreset;
    Texture txGameover;
    Texture txPause;
    Texture txOptionsdefault;
    Texture txCredits;
    //Dino
    Texture txDino;
    Texture txDinoJump;
    Texture txDinoFall;
    Texture txDinoCrouch;
    Texture txDinoDead;
    //popup
    Texture txDinoScan;
    Texture txDinoRoar;
    Texture txDinoWalk;
    //Elements 
    Texture txMoon;
    Texture txcloud;
    Texture txcactus;
    Texture txBat;
    //Font
    Font txscore;
    //Hover
    Texture txhstart;
    Texture txhoptions;
    Texture txhexit;
    Texture txhdefault;
    Texture txhred;
    Texture txhblue;
    Texture txhpurple;
    Texture txhcredits;
    Texture txhOptionsws;
    Texture txhpreset;
    Texture txhsoundoffarrow;
    Texture txhsoundonws;
    Texture txhsoundoffws;
    //sound
    SoundBuffer SBclick0;
    SoundBuffer SBexit;
};
//Load texture function
void fnLoadTexture(Menu& resources, Texs& texture) {
    //Font
    texture.txscore.loadFromFile("ErixOutline-rvBL.ttf");
    //Main menu
    texture.txMainMenu.loadFromFile("NewMainMenuwithclouds.png");
    texture.txhstart.loadFromFile("Start-Shadows.png");
    texture.txhoptions.loadFromFile("Options-shadow.png");
    texture.txhexit.loadFromFile("Exit-shadows.png");
    texture.txhpreset.loadFromFile("Preset-shadow.png");
    texture.txhcredits.loadFromFile("credits-shadow.png");
    //Popup
    texture.txPopupIcon.loadFromFile("Icon-sprite.png");
    texture.txPopupScreen.loadFromFile("Game-description-with-blur.png");
    //Options
    texture.txOptionsdefault.loadFromFile("Options arrow sound on.png");
    texture.txhsoundoffarrow.loadFromFile("options-arrow-off-button.png");
    texture.txhsoundonws.loadFromFile("options-ws-sound-on.png");
    texture.txhsoundoffws.loadFromFile("options-ws-sound-off.png");
    //Credits
    texture.txCredits.loadFromFile("credits-with-back-button.png");
    //Preset
    texture.txPreset.loadFromFile("PresetMenu.png");
    texture.txhdefault.loadFromFile("default-skin-shadow.png");
    texture.txhred.loadFromFile("red-skin-shadow.png");
    texture.txhpurple.loadFromFile("purple-skin-shadow.png");
    texture.txhblue.loadFromFile("blue-skin-shadow.png");
    //Pause
    texture.txPause.loadFromFile("pauseedit.png");
    //Gameover
    texture.txGameover.loadFromFile("game-over1.png");
    //Dino
    texture.txDino.loadFromFile("raptor-run.png");
    texture.txDinoJump.loadFromFile("raptor-jump.png");
    texture.txDinoFall.loadFromFile("raptor-falling.png");
    texture.txDinoCrouch.loadFromFile("crouch.png");
    texture.txDinoDead.loadFromFile("DinoDead1.png");
    texture.txDinoScan.loadFromFile("raptor-scanning.png");
    texture.txDinoRoar.loadFromFile("raptor-roar.png");
    texture.txDinoWalk.loadFromFile("raptor-walk.png");
    //Moon
    texture.txMoon.loadFromFile("Moon-removebg-preview.png");
    //Clouds
    texture.txcloud.loadFromFile("clouds.png");
    //Cactus
    texture.txcactus.loadFromFile("cactus.png");
    //Bat
    texture.txBat.loadFromFile("Bat.png");
    //Light backgrounds
    texture.txbackground1.loadFromFile("DesertLayer3.png");
    texture.txbackground2.loadFromFile("DesertLayer2.png");
    texture.txbackground3.loadFromFile("DesertLayer1.png");
    texture.txbackground4.loadFromFile("DesertLayer0.png");
    //Dark backgrounds
    texture.txbackground1dark.loadFromFile("dark_mode2.png");
    texture.txbackground2dark.loadFromFile("DesertLayer2Night.png");
    texture.txbackground3dark.loadFromFile("Desertlayer1Night.png");
    texture.txbackground4dark.loadFromFile("DesertLayer0Night.png");
    //Sound effect and Music
    texture.SBexit.loadFromFile("negative_beeps-6008.wav");
    texture.SBclick0.loadFromFile("click.wav");
    resources.Game.openFromFile("DRIVE.wav");
}
//SetTexture Function
void fnSetTexture( Menu & resources, Texs& texture) {
    //Font
    resources.scorenum.setFont(texture.txscore);
    resources.scorenum.setStyle(Text::Bold);
    resources.highscore.setFont(texture.txscore);
    resources.highscore.setStyle(Text::Bold);
    //Main menu
    resources.spMainMenu.setTexture(texture.txMainMenu);
    resources.spPopupIcon.setTexture(texture.txPopupIcon);
    //Options Menu
    resources.spOptions.setTexture(texture.txOptionsdefault);
    //credits Menu
    resources.spCredits.setTexture(texture.txCredits);
    //Preset menu
    resources.spPreset.setTexture(texture.txPreset);
    //Pause menu
    resources.spPause.setTexture(texture.txPause);
    //Game over
    resources.spGameover.setTexture(texture.txGameover);
    //Dinosaur
    resources.spDino.setTexture(texture.txDino);
    //Moon
    resources.spMoon.setTexture(texture.txMoon);

    for (int i = 0; i < 2; i++) {
        //Cloud
        resources.cloud[i].setTexture(texture.txcloud);
        //Bat
        resources.spBat[i].setTexture(texture.txBat);
        //backgrounds
        resources.spbackground2[i].setTexture(texture.txbackground2);
        resources.spbackground3[i].setTexture(texture.txbackground3);
        resources.spbackground4[i].setTexture(texture.txbackground4);
    }
    //cactus
    for (int i = 0; i < 3; ++i) {
        resources.smallcactus[i].setTexture(texture.txcactus);
        resources.cactus[i].setTexture(texture.txcactus);
    }
    //Sky
    resources.spbackground1.setTexture(texture.txbackground1);
    //Sounds
    resources.Sclick0.setBuffer(texture.SBclick0);
    resources.Soundexit.setBuffer(texture.SBexit);
}
//SetPosition Function
void fnSetPosition(RenderWindow& window, Menu& resources, Texs& texture) {
    //Font
    resources.scorenum.setPosition(20, 0);
    resources.highscore.setPosition(250, 0);
    //Cloud
    resources.cloud[1].setPosition(1500, 0);
    //backgrounds
    for (int i = 0; 2 > i; ++i) {
        resources.spbackground2[1].setPosition(1280, 0);
        resources.spbackground3[1].setPosition(1280, 0);
        resources.spbackground4[1].setPosition(1280, 0);
    }
    //ground
    resources.ground.setPosition(0, 680);
}
//SetScale Function
void fnSetScale(RenderWindow& window, Menu& resources, Texs& texture) {
    //Font
    resources.scorenum.setCharacterSize(20);
    resources.highscore.setCharacterSize(20);
    //Moon
    resources.spMoon.setScale(0.9, 0.9);
    //Cactus
    for (int i = 0; 3 > i; ++i) {
        resources.smallcactus[i].setScale(0.25, 0.25);
        resources.cactus[i].setScale(0.4, 0.4);
    }
    //Bat
    for (int i = 0; 2 > i; ++i) {
        resources.spBat[i].setScale(0.2, 0.2);
    }
    //Ground
    resources.ground.setSize(Vector2f(1280, 10));
}
//Menu Functions
void fnMainMenu(RenderWindow& window, Event& event, Menu& resources, Texs& texture) {
    int SpriteIndex = 0;
    resources.spDino.setScale(0.7, 0.7);
    resources.spDino.setTexture(texture.txDino);
    resources.spDino.setPosition(resources.spDino.getPosition().x, 575);
    while (true) {

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                exit(EXIT_SUCCESS);
            }
        }
        //Animation on main menu
        resources.spDino.move(15, 0);
        if (resources.time1.getElapsedTime().asMilliseconds() >= 60) {
            ++resources.timer2;
            resources.time1.restart();
            //Animation bug fix
                if (resources.timer2 >= 1) {
                    resources.spDino.setTextureRect(IntRect(SpriteIndex * 348, 0, 348, 139));
                    SpriteIndex++;
                    SpriteIndex %= 6;
                }
        }
        //infinite run on main menu
        if (resources.spDino.getPosition().x > 1280) {
            resources.spDino.setPosition(-200, 575);
        }
        window.clear();
        window.draw(resources.spMainMenu);
        window.draw(resources.spDino);
        window.draw(resources.spPopupIcon);
        window.display();
        //Start hover
         Vector2i mousePos = Mouse::getPosition(window);
        if (mousePos.x > 440 && mousePos.x < 840 && mousePos.y>175 && mousePos.y < 270) {
            resources.spMainMenu.setTexture(texture.txhstart);
        }
        //Options hover
        else  if (mousePos.x > 440 && mousePos.x < 840 && mousePos.y>300 && mousePos.y < 400) {
            resources.spMainMenu.setTexture(texture.txhoptions);
        }
        //Exit hover
        else if (mousePos.x > 440 && mousePos.x < 840 && mousePos.y>430 && mousePos.y < 530) {
            resources.spMainMenu.setTexture(texture.txhexit);
        }
        //Credits hover
        else if (mousePos.x > 0 && mousePos.x < 263 && mousePos.y>683 && mousePos.y < 720) {
            resources.spMainMenu.setTexture(texture.txhcredits);
        }
        //Preset hover
        else if (mousePos.x > 1055 && mousePos.x < 1280 && mousePos.y>681 && mousePos.y < 720) {
            resources.spMainMenu.setTexture(texture.txhpreset);
        }
        //No hover (default)
        else
           resources.spMainMenu.setTexture(texture.txMainMenu);
        if (Mouse::isButtonPressed(Mouse::Left)) {
            Vector2i mousePos = Mouse::getPosition(window);
            // Start button
            if (mousePos.x > 440 && mousePos.x < 840 && mousePos.y>175 && mousePos.y < 270) {
                resources.isStart = true;
                resources.Sclick0.play();
                resources.ScreenIndex = 2;
                break;
            }
            // Options button
            if (mousePos.x > 440 && mousePos.x < 840 && mousePos.y>300 && mousePos.y < 400) {
                resources.Sclick0.play();
                resources.ScreenIndex = 1;
                break;
            }
            // Exit button
            if (mousePos.x > 440 && mousePos.x < 840 && mousePos.y>430 && mousePos.y < 530) {
                resources.Game.pause();
                resources.Soundexit.play();
                window.close();
            }
            // Credits button
            if (mousePos.x > 0 && mousePos.x < 263 && mousePos.y>683 && mousePos.y < 720) {
                resources.Sclick0.play();
                resources.ScreenIndex = 3;
                break;
            }
            //Preset button
            if (mousePos.x > 1055 && mousePos.x < 1280 && mousePos.y>681 && mousePos.y < 720) {
                resources.Sclick0.play();
                resources.ScreenIndex = 4;
                break;
            }
            //Dino to preset
           if(mousePos.x>resources.spDino.getPosition().x&& mousePos.x < resources.spDino.getPosition().x+resources.spDino.getGlobalBounds().width&& mousePos.y>resources.spDino.getPosition().y && mousePos.y < resources.spDino.getPosition().y+ resources.spDino.getGlobalBounds().height)
           {    resources.Sclick0.play();
                resources.ScreenIndex = 4;
                break;
            }
            //Popup button
            if (mousePos.x > 1220 && mousePos.x < 1280 && mousePos.y>0 && mousePos.y < 57) {
                resources.ScreenIndex = 5;
                break;
            }
        }
    }
}
void fnOptions(RenderWindow& window, Event& event, Menu& resources, Texs& texture) {
    while (true) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                exit(EXIT_SUCCESS);
            }
        }
        window.draw(resources.spOptions);
        window.display();
        //Escape backspace button
        if ((Keyboard::isKeyPressed(Keyboard::Escape)) || (Keyboard::isKeyPressed(Keyboard::BackSpace))) {
            if (resources.ScreenIndex == 2) {
                break;
            }
            else if (resources.ScreenIndex == 1) {
                resources.ScreenIndex = 0;
                break;
            }
        }
        Vector2i mousePos = Mouse::getPosition(window);
        if (Mouse::isButtonPressed(Mouse::Left)) {
            Vector2i mousePos = Mouse::getPosition(window);
            //Back button
            if (mousePos.x > 0 && mousePos.x < 213 && mousePos.y>0 && mousePos.y < 87) {
                if (resources.ScreenIndex == 2) {
                    resources.timer = 0;
                    resources.Sclick0.play();
                    break;
                }
                else if (resources.ScreenIndex == 1) {
                    resources.Sclick0.play();
                    resources.ScreenIndex = 0;
                    break;
                }
            }
            //Sound ON
            if (mousePos.x > 780 && mousePos.x < 1180 && mousePos.y>221 && mousePos.y < 322 && resources.isONclicked == false) {
                resources.isONclicked = true;
                resources.isOFFclicked = false;
                resources.Sclick0.play();
                resources.Game.play();
            }
            //Sound OFF
            if (mousePos.x > 780 && mousePos.x < 1180 && mousePos.y>473 && mousePos.y < 577 && resources.isOFFclicked == false) {
                resources.isOFFclicked = true;
                resources.isONclicked = false;
                resources.Sclick0.play();
                resources.Game.pause();
            }
            //Ws button 
            if (mousePos.x > 154 && mousePos.x < 388 && mousePos.y>499 && mousePos.y < 695 && resources.isws == false)
            {
                resources.isws = true;
                resources.isarrow = false;
                resources.Sclick0.play();

            }
            //Arrow button 
            if (mousePos.x > 420 && mousePos.x < 653 && mousePos.y>499 && mousePos.y < 695 && resources.isarrow == false)
            {
                resources.isws = false;
                resources.isarrow = true;
                resources.Sclick0.play();
            }
            // Options Hover conditions
            if (resources.isOFFclicked == true && resources.isws == true) {
                resources.spOptions.setTexture(texture.txhsoundoffws);
            }
            else if (resources.isONclicked == true && resources.isws == true) {
                resources.spOptions.setTexture(texture.txhsoundonws);
            }
            else if (resources.isOFFclicked == true && resources.isarrow == true) {
                resources.spOptions.setTexture(texture.txhsoundoffarrow);
            }
            else if (resources.isarrow == true && resources.isONclicked == true) {
                resources.spOptions.setTexture(texture.txOptionsdefault);
            }
        }
    }
}
void fnPauseMenu(RenderWindow& window, Event& event, Menu& resources, Texs& texture) {
    resources.timer = 0;
    while (true) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                exit(EXIT_SUCCESS);
            }
        }
        window.clear();
        window.draw(resources.spPause);
        window.display();
        // to avoid double press
        if (resources.time.getElapsedTime().asMilliseconds() >= 625) {
            ++resources.timer;
            resources.time.restart();
        }
        if ((Keyboard::isKeyPressed(Keyboard::Enter))) {
            break;
        }
        if (Mouse::isButtonPressed(Mouse::Left)) {
            Vector2i mousePos = Mouse::getPosition(window);
            //play button
            if (mousePos.x > 530 && mousePos.x < 752 && mousePos.y>250 && mousePos.y < 475) {
                resources.Sclick0.play();
                break;
            }
            //main menu
            if (mousePos.x > 0 && mousePos.x < 342 && mousePos.y>0 && mousePos.y < 90 && resources.timer >= 2) {
                resources.Sclick0.play();
                resources.ScreenIndex = 0;
                break;
            }
            //options
            if (mousePos.x > 935 && mousePos.x < 1280 && mousePos.y>0 && mousePos.y < 90) {
                resources.Sclick0.play();
                fnOptions(window, event, resources, texture);
            }
        }
    }
}
void fnCredits(RenderWindow& window, Event& event, Menu& resources) {
    while (true)
    {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                exit(EXIT_SUCCESS);
            }
        }
        window.clear();
        window.draw(resources.spCredits);
        window.display();
        if ((Keyboard::isKeyPressed(Keyboard::Escape)) || (Keyboard::isKeyPressed(Keyboard::BackSpace))) {
            resources.ScreenIndex = 0;
            break;
        }
        if (Mouse::isButtonPressed(Mouse::Left)) {
            Vector2i mousePos = Mouse::getPosition(window);
            //Back button
            if (mousePos.x > 0 && mousePos.x < 213 && mousePos.y>0 && mousePos.y < 87) {
                resources.Sclick0.play();
                resources.ScreenIndex = 0;
                break;
            }
        }
    }
}
void fnPopup(RenderWindow& window, Event& event, Menu& resources, Texs& texture) {
    int SpriteIndex1 = 0, SpriteIndex2 = 0, SpriteIndex3 = 0;
    int timer = 0, timer1 = 0, timer2 = 0;
    while (true) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                exit(EXIT_SUCCESS);
            }
        }
        //Dino1 & Dino2 & Dino3
        resources.spDino1.setTextureRect(IntRect(SpriteIndex1 * 640, 0, 640, 320));
        resources.spDino2.setTextureRect(IntRect(SpriteIndex2 * 640, 0, 640, 320));
        resources.spDino3.setTextureRect(IntRect(SpriteIndex3 * 640, 0, 640, 320));
        resources.spMainMenu.setTexture(texture.txPopupScreen);
        resources.spDino1.setPosition(515, 195);
        resources.spDino2.setPosition(300, 195);
        resources.spDino3.setPosition(735, 195);
        resources.spDino3.setScale(0.4, 0.4);
        resources.spDino2.setScale(0.4, 0.4);
        resources.spDino1.setScale(0.4, 0.4);
        resources.spDino1.setTexture(texture.txDinoScan);
        resources.spDino2.setTexture(texture.txDinoRoar);
        resources.spDino3.setTexture(texture.txDinoWalk);
        //Dino 1 animation
        if (resources.time.getElapsedTime().asMilliseconds() >= 80) {
            ++timer;
            resources.time.restart();
                if (timer > 1) {
                    resources.spDino1.setTextureRect(IntRect(SpriteIndex1 * 640, 0, 640, 320));
                    ++SpriteIndex1;
                    SpriteIndex1 %= 18;
                }
        }
        //Dino 2 animation
        if (resources.time1.getElapsedTime().asMilliseconds() >= 125) {
            ++timer1;
            resources.time1.restart();
                if (timer1 > 1) {
                    resources.spDino2.setTextureRect(IntRect(SpriteIndex2 * 640, 0, 640, 320));
                    ++SpriteIndex2;
                    SpriteIndex2 %= 6;
                }       
        }
        //Dino 3 animation
        if (resources.time2.getElapsedTime().asMilliseconds() >= 125) {
            ++timer2;
            resources.time2.restart();
            if (timer2 > 1) {
                resources.spDino3.setTextureRect(IntRect(SpriteIndex3 * 640, 0, 640, 320));
                ++SpriteIndex3;
                SpriteIndex3 %= 6;
            }
        }
        window.clear();
        window.draw(resources.spMainMenu);
        window.draw(resources.spDino1);
        window.draw(resources.spDino2);
        window.draw(resources.spDino3);
        window.display();
        if (Mouse::isButtonPressed(Mouse::Left)) {
            Vector2i mousePos = Mouse::getPosition(window);
            if (mousePos.x > 360 && mousePos.x < 925 && mousePos.y>216 && mousePos.y < 674) {
            }
            else if (mousePos.x > 360 && mousePos.x < 823 && mousePos.y>145 && mousePos.y < 300) {
            }
            else   if (mousePos.x > 1220 && mousePos.x < 1280 && mousePos.y>0 && mousePos.y < 57) {

            }
            //Exit popup
            else {
                resources.ScreenIndex = 0;
                resources.spMainMenu.setTexture(texture.txMainMenu);
                break;
            }
        }
    }
}
// Reset Game Function
void fnResetGame(RenderWindow& window, Menu& resources, bool& gameover, Texs texture) {
    resources.spDino.setScale(0.7, 0.7);
    resources.score = 0;
    resources.timer1 = 0;
    resources.timer2 = 0;
    resources.deadindex = 0;
    resources.GameDifficulty = 0;
    //intial position of cactus
    for (int i = 0; i < 3; i++) {
        resources.smallcactus[i].setPosition((i * 100) * 10 + 1200, 625);
        resources.cactus[i].setPosition(((i * 200) * 300) - 50, 590);
    }
    //intial position of bat
    for (int i = 0; i < 2; i++) {
        int randoo1 = 1 + rand() % 220;
        int randoo2 = 1 + rand() % 900;
        int randoo3 = 1 + rand() % 900;
        int randoo4 = 1 + rand() % 900;
        int randoo5 = 1 + rand() % 900;
        resources.spBat[0].setPosition(1300 + randoo1 + randoo2 + randoo3 + randoo4 + randoo5, 625);
        resources.spBat[1].setPosition(1280 + randoo1 + randoo2 + randoo3 + randoo4 + randoo5, 550);

    }
    gameover = false;
    //Reseting game velocity 
    resources.GameVelocity = 10;
    resources.background1Vel = 2;
    resources.background2Vel = 6;
    resources.VelocityY = -1;
}
//Game over Function
void fnGOcheck(RenderWindow& window, Event& event, bool& gameover, Menu& resources, Texs& texture) {
    if (gameover) {
        resources.GameVelocity = 0;
        resources.background1Vel = 0;
        resources.background2Vel = 0;
        resources.score--;
        resources.spDino.setTexture(texture.txDinoDead);
        resources.spDino.setPosition(160, 540);
        resources.spDino.setScale(1, 1);
        resources.spDino.setTextureRect(IntRect(165 * resources.deadindex, 0, 165, 139));
        ++resources.deadindex;
        window.draw(resources.spDino);
        window.draw(resources.spGameover);
        if (Mouse::isButtonPressed(Mouse::Left)) {
            Vector2i mousePos = Mouse::getPosition(window);
            //Retry button
            if (mousePos.x > 437 && mousePos.x < 840 && mousePos.y> 380 && mousePos.y < 477) {
              resources.isStart = false;  
            }
        }
        //Retry by enter
        if (Keyboard::isKeyPressed(Keyboard::Enter)) {
            resources.isStart = false;
        }
    }
    if (resources.deadindex == 4) {
        --resources.deadindex;
    }
}


//Light Mode Function
void fnLightMode(RenderWindow& window, Event& event, Menu& resources, Texs& texture, bool gameover) {
    resources.spMoon.setPosition(480, -200);
    resources.scorenum.setFillColor(Color::Black);
    resources.highscore.setFillColor(Color::Black);
    resources.spbackground1.setTexture(texture.txbackground1);
    resources.spbackground1.setScale(1, 1);
    window.draw(resources.spbackground1);
    for (int i = 0; i < 2; i++)
    {
        window.draw(resources.cloud[i]);
    }
    for (int i = 0; 2 > i; ++i) {
        resources.spbackground2[i].setTexture(texture.txbackground2);
        window.draw(resources.spbackground2[i]);
    }
    for (int i = 0; 2 > i; ++i) {
        resources.spbackground3[i].setTexture(texture.txbackground3);
        window.draw(resources.spbackground3[i]);
    }

    for (int i = 0; 2 > i; ++i) {
        resources.spbackground4[i].setScale(1, 1);

        resources.spbackground4[i].setTexture(texture.txbackground4);

        window.draw(resources.spbackground4[i]);
    }
    //Endless Run
    if (resources.spbackground2[0].getPosition().x < -1280) {
        resources.spbackground2[0].setPosition(resources.spbackground2[1].getPosition().x + resources.spbackground2[1].getGlobalBounds().width, 0);
    }
    if (resources.spbackground2[1].getPosition().x < -1280) {
        resources.spbackground2[1].setPosition(resources.spbackground2[0].getPosition().x + resources.spbackground2[0].getGlobalBounds().width, 0);
    }
    if (resources.spbackground3[0].getPosition().x < -1280) {
        resources.spbackground3[0].setPosition(resources.spbackground3[1].getPosition().x + resources.spbackground3[1].getGlobalBounds().width, 0);

    }
    if (resources.spbackground3[1].getPosition().x < -1280) {
        resources.spbackground3[1].setPosition(resources.spbackground3[0].getPosition().x + resources.spbackground3[0].getGlobalBounds().width, 0);

    }
    if (resources.spbackground4[0].getPosition().x < -1280) {
        resources.spbackground4[0].setPosition(resources.spbackground4[1].getPosition().x + resources.spbackground4[1].getGlobalBounds().width, 0);
    }
    if (resources.spbackground4[1].getPosition().x < -1280) {
        resources.spbackground4[1].setPosition(resources.spbackground4[0].getPosition().x + resources.spbackground4[0].getGlobalBounds().width, 0);
    }
    for (int i = 0; 2 > i; ++i) {
        resources.spbackground2[i].move(-resources.background1Vel, 0);
        resources.spbackground3[i].move(-resources.background2Vel, 0);
        resources.spbackground4[i].move(-resources.GameVelocity, 0);
    }
    //cloud movement
    for (int i = 0; i < 2; i++) {
        resources.cloud[i].move(-resources.background1Vel, 0);
    }
    if (resources.cloud[0].getPosition().x < -1280) {
        resources.cloud[0].setPosition(1280 - 3, 0);
    }
    if (resources.cloud[1].getPosition().x < -1280) {
        resources.cloud[1].setPosition(1280 - 3, 0);
    }
    for (int i = 0; 3 > i; ++i) {
        window.draw(resources.smallcactus[i]);
        window.draw(resources.cactus[i]);
    }
    for (int i = 0; 2 > i; ++i) {
        window.draw(resources.spBat[i]);
    }
    window.draw(resources.scorenum);
    window.draw(resources.highscore);
    window.draw(resources.ground);
    //Gameover check
    fnGOcheck(window, event, gameover, resources, texture);
}
//Dark Mode Function
void fnDarkMode(RenderWindow& window, Event& event, Menu& resources, Texs& texture, bool gameover) {
    if (resources.spMoon.getPosition().y < 0) {
        resources.spMoon.move(0, 3);
    }
    resources.spbackground1.setTexture(texture.txbackground1dark);
    resources.spbackground1.setScale(1, 1);
    window.draw(resources.spbackground1);
    window.draw(resources.spMoon);
    for (int i = 0; 2 > i; ++i) {
        resources.spbackground2[i].setTexture(texture.txbackground2dark);
        window.draw(resources.spbackground2[i]);
    }
    for (int i = 0; i < 2; ++i) {
        resources.spbackground3[i].setTexture(texture.txbackground3dark);
        window.draw(resources.spbackground3[i]);
    }
    for (int i = 0; 2 > i; ++i) {
        resources.spbackground4[i].setTexture(texture.txbackground4dark);
        window.draw(resources.spbackground4[i]);
    }
    for (int i = 0; 3 > i; ++i) {
        window.draw(resources.smallcactus[i]);
        window.draw(resources.cactus[i]);
    }
    for (int i = 0; 2 > i; ++i) {
        window.draw(resources.spBat[i]);
    }
    //Endless Run
    if (resources.spbackground2[0].getPosition().x < -1280) {
        resources.spbackground2[0].setPosition(resources.spbackground2[1].getPosition().x + resources.spbackground2[1].getGlobalBounds().width, 0);
    }
    if (resources.spbackground2[1].getPosition().x < -1280) {
        resources.spbackground2[1].setPosition(resources.spbackground2[0].getPosition().x + resources.spbackground2[0].getGlobalBounds().width, 0);
    }
    if (resources.spbackground3[0].getPosition().x < -1280) {
        resources.spbackground3[0].setPosition(resources.spbackground3[1].getPosition().x + resources.spbackground3[1].getGlobalBounds().width, 0);

    }
    if (resources.spbackground3[1].getPosition().x < -1280) {
        resources.spbackground3[1].setPosition(resources.spbackground3[0].getPosition().x + resources.spbackground3[0].getGlobalBounds().width, 0);

    }
    if (resources.spbackground4[0].getPosition().x < -1280) {
        resources.spbackground4[0].setPosition(resources.spbackground4[1].getPosition().x + resources.spbackground4[1].getGlobalBounds().width, 0);
    }
    if (resources.spbackground4[1].getPosition().x < -1280) {
        resources.spbackground4[1].setPosition(resources.spbackground4[0].getPosition().x + resources.spbackground4[0].getGlobalBounds().width, 0);
    }
    for (int i = 0; 2 > i; ++i) {
        resources.spbackground2[i].move(-resources.background1Vel, 0);
        resources.spbackground3[i].move(-resources.background2Vel, 0);
        resources.spbackground4[i].move(-resources.GameVelocity, 0);
    }

    window.draw(resources.ground);
    resources.scorenum.setFillColor(Color::White);
    resources.highscore.setFillColor(Color::White);
    window.draw(resources.scorenum);
    window.draw(resources.highscore);
    fnGOcheck(window, event, gameover, resources, texture);
}
//Update Score Function
void fnUpdateScore(  Menu& resources,  int temphiscore, bool gameover) {
    //Score update
    resources.score++;
    resources.scorenum.setString("Score    " + to_string(resources.score));
    if (temphiscore < resources.score) {
        temphiscore = resources.score;
    }
    if (gameover)
        resources.finalhiscore = temphiscore;
    resources.highscore.setString("HI    " + to_string(temphiscore));
}
//Update Difficulty
void fnUpdateDifficulty( Menu& resources) {
    //Game difficulty
    resources.GameDifficulty++;
    if (resources.GameDifficulty >= 100) {
        resources.GameDifficulty = 0;
        ++resources.GameVelocity;
        ++resources.background1Vel;
        ++resources.background2Vel;
    }
}
//UpDown Controls function
void fnUpDownControls(Menu& resources, Texs& texture, FloatRect& DinoBounds) {
    if ((Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Up)) && resources.isCrouch == false) {
        resources.VelocityY = 25;
        resources.grounded = false;
        resources.spDino.setTexture(texture.txDinoJump);
        resources.spDino.setTextureRect(IntRect(0, 0, 348, 216));
    }
    if (Keyboard::isKeyPressed(Keyboard::Down) && resources.spDino.getTexture() != &texture.txDinoJump) {
        DinoBounds.top += 50;
        resources.spDino.setTexture(texture.txDinoCrouch);
    }
}
//WS Controls function
void fnWSControls(Menu& resources, Texs& texture, FloatRect& DinoBounds) {
    if ((Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::W)) && resources.isCrouch == false) {
        resources.VelocityY = 25;
        resources.grounded = false;
        resources.spDino.setTexture(texture.txDinoJump);
        resources.spDino.setTextureRect(IntRect(0, 0, 348, 216));
    }
    if (Keyboard::isKeyPressed(Keyboard::S) && resources.spDino.getTexture() != &texture.txDinoJump) {
        DinoBounds.top += 50;
        resources.spDino.setTexture(texture.txDinoCrouch);
    }
}
//Bat Animation
void fnBatAnimation(Menu& resources, Texs& texture, FloatRect Batbounds[]) {
    //Bat animation
    if (resources.time.getElapsedTime().asMilliseconds() >= 120) {
        ++resources.timer1;
        resources.time.restart();
        //Bat animation fix
            if (resources.timer1 > 1) {
                resources.spBat[0].setTextureRect(IntRect(resources.BatIndex * 371, 0, 371, 308));
                resources.spBat[1].setTextureRect(IntRect(resources.BatIndex * 371, 0, 371, 308));
                ++resources.BatIndex;
                resources.BatIndex %= 2;
            }
    }
    //Bug fix bat
    for (int i = 0; 2 > i; ++i) {
        Batbounds[i] = resources.spBat[i].getGlobalBounds();
        Batbounds[i].width -= 10;
    }
}
//Bat Position
void fnBatPosition(Menu& resources) {
    //Bat position
    for (int i = 0; i < 2; i++) {
        int randoo1 = 1 + rand() % 220;
        int randoo2 = 1 + rand() % 900;
        int randoo3 = 1 + rand() % 900;
        int randoo4 = 1 + rand() % 900;
        int randoo5 = 1 + rand() % 900;
        if (resources.spBat[0].getPosition().x < -1280 || abs(resources.spBat[0].getPosition().x - resources.cactus[0].getPosition().x) <= 400 || abs(resources.spBat[0].getPosition().x - resources.cactus[1].getPosition().x) <= 400 || abs(resources.spBat[0].getPosition().x - resources.cactus[2].getPosition().x) <= 400 || abs(resources.spBat[0].getPosition().x - resources.smallcactus[0].getPosition().x) <= 400 || abs(resources.spBat[0].getPosition().x - resources.smallcactus[1].getPosition().x) <= 400 || abs(resources.spBat[0].getPosition().x - resources.smallcactus[2].getPosition().x) <= 400 || abs(resources.spBat[0].getPosition().x - resources.spBat[1].getPosition().x) <= 400) {
            resources.spBat[0].setPosition(1300 + randoo1 + randoo2 + randoo3 + randoo4 + randoo5, 625);
        }
        if (resources.spBat[1].getPosition().x < -1280 || abs(resources.spBat[1].getPosition().x - resources.cactus[0].getPosition().x) <= 400 || abs(resources.spBat[1].getPosition().x - resources.cactus[1].getPosition().x) <= 400 || abs(resources.spBat[1].getPosition().x - resources.cactus[2].getPosition().x) <= 400 || abs(resources.spBat[1].getPosition().x - resources.smallcactus[0].getPosition().x) <= 400 || abs(resources.spBat[1].getPosition().x - resources.smallcactus[1].getPosition().x) <= 400 || abs(resources.spBat[1].getPosition().x - resources.smallcactus[2].getPosition().x) <= 400) {
            resources.spBat[1].setPosition(1280 + randoo1 + randoo2 + randoo3 + randoo4 + randoo5, 550);
        }
    }
}
//Cactus position
void fnCactusPosition( Menu& resources) {
    //cactus position
    for (int i = 0; i < 3; i++) {
        int randoo1 = 1 + rand() % 220;
        int randoo2 = 1 + rand() % 900;
        int randoo3 = 1 + rand() % 900;
        int randoo4 = 1 + rand() % 900;
        int randoo5 = 1 + rand() % 900;
        resources.smallcactdist += 2;
        resources.smallcactdist %= 4;
        //small cactus
        if (resources.smallcactus[i].getPosition().x < -1280)
            resources.smallcactus[i].setPosition(1800 + (resources.smallcactdist * 200), 625);
        if (resources.cactus[0].getPosition().x < -1280 || abs(resources.cactus[0].getPosition().x - resources.cactus[1].getPosition().x) <= 400 || abs(resources.cactus[0].getPosition().x - resources.cactus[2].getPosition().x) <= 400 || abs(resources.cactus[0].getPosition().x - resources.smallcactus[0].getPosition().x) <= 400 || abs(resources.cactus[0].getPosition().x - resources.smallcactus[1].getPosition().x) <= 400 || abs(resources.cactus[0].getPosition().x - resources.smallcactus[2].getPosition().x) <= 400) {
            resources.cactus[0].setPosition(1280 + randoo1 + randoo2 + randoo3 + randoo4 + randoo5, 590);
        }
        if (resources.cactus[1].getPosition().x < -1280 || abs(resources.cactus[0].getPosition().x - resources.cactus[1].getPosition().x) <= 400 || abs(resources.cactus[1].getPosition().x - resources.cactus[2].getPosition().x) <= 400 || abs(resources.cactus[1].getPosition().x - resources.smallcactus[0].getPosition().x) <= 400 || abs(resources.cactus[1].getPosition().x - resources.smallcactus[1].getPosition().x) <= 400 || abs(resources.cactus[1].getPosition().x - resources.smallcactus[2].getPosition().x) <= 400) {
            resources.cactus[1].setPosition(1280 + randoo1 + randoo2 + randoo3 + randoo4 + randoo5, 590);
        }
        if (resources.cactus[2].getPosition().x < -1280 || abs(resources.cactus[1].getPosition().x - resources.cactus[2].getPosition().x) <= 400
            || abs(resources.cactus[2].getPosition().x - resources.smallcactus[0].getPosition().x) <= 400 || abs(resources.cactus[2].getPosition().x - resources.smallcactus[1].getPosition().x) <= 400 || abs(resources.cactus[2].getPosition().x - resources.smallcactus[2].getPosition().x) <= 400) {
            resources.cactus[2].setPosition(1280 + randoo1 + randoo2 + randoo3 + randoo4 + randoo5, 590);
        }

    }
}
//Obstacles movement
void fnObstacleMove(Menu& resources) {
    //obstacles movement
    for (int i = 0; 3 > i; ++i) {
        resources.smallcactus[i].move(-resources.GameVelocity, 0);
        resources.cactus[i].move(-resources.GameVelocity, 0);
    }
    for (int i = 0; 2 > i; ++i) {
        resources.spBat[i].move(-resources.GameVelocity, 0);
    }
}
//Preset Functions
void fnDinoDefault(Menu& resources, Texs& texture) {
    texture.txDino.loadFromFile("raptor-run.png");
    texture.txDinoJump.loadFromFile("raptor-jump.png");
    texture.txDinoFall.loadFromFile("raptor-falling.png");
    texture.txDinoCrouch.loadFromFile("crouch.png");
    texture.txDinoDead.loadFromFile("DinoDead1.png");
    resources.spDino.setTexture(texture.txDino);
}
void fnDinoRed(Menu& resources, Texs& texture) {
    texture.txDino.loadFromFile("raptor-runRed.png");
    texture.txDinoJump.loadFromFile("raptor-jumpRed.png");
    texture.txDinoFall.loadFromFile("raptor-fallingRed.png");
    texture.txDinoCrouch.loadFromFile("crouchRed.png");
    texture.txDinoDead.loadFromFile("DinoDeadRed.png");
    resources.spDino.setTexture(texture.txDino);
}
void fnDinoBlue(Menu& resources, Texs& texture) {
    texture.txDino.loadFromFile("raptor-runBabyBlue.png");
    texture.txDinoJump.loadFromFile("raptor-jumpBabyBlue.png");
    texture.txDinoFall.loadFromFile("raptor-fallingBabyBlue.png");
    texture.txDinoCrouch.loadFromFile("crouchBabyBlue.png");
    texture.txDinoDead.loadFromFile("DinoDead-BabyBlue.png");
    resources.spDino.setTexture(texture.txDino);
}
void fnDinoPurple(Menu& resources, Texs& texture) {
    texture.txDino.loadFromFile("raptor-runPurple.png");
    texture.txDinoJump.loadFromFile("raptor-jumpPurple.png");
    texture.txDinoFall.loadFromFile("raptor-fallingPurple.png");
    texture.txDinoCrouch.loadFromFile("crouchpurple.png");
    texture.txDinoDead.loadFromFile("DinoDead-Purple.png");
    resources.spDino.setTexture(texture.txDino);
}
void fnPreset(RenderWindow& window, Event& event, Menu& resources, Texs& texture) {
    while (true) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                exit(EXIT_SUCCESS);
            }
        }
        window.clear();
        window.draw(resources.spPreset);
        window.display();
        if ((Keyboard::isKeyPressed(Keyboard::Escape)) || (Keyboard::isKeyPressed(Keyboard::BackSpace))) {
            resources.ScreenIndex = 0;
            break;
        }
        if (Mouse::isButtonPressed(Mouse::Left)) {
            Vector2i mousePos = Mouse::getPosition(window);
            //Back button
            if (mousePos.x > 0 && mousePos.x < 213 && mousePos.y>0 && mousePos.y < 87) {
                resources.Sclick0.play();
                resources.ScreenIndex = 0;
                break;
            }
            //Default skin
            if (mousePos.x > 552 && mousePos.x < 727 && mousePos.y>130 && mousePos.y < 273 && resources.isDefault == false) {
                resources.Sclick0.play();
                resources.isDefault = true;
                resources.isRed = false;
                resources.isBlue = false;
                resources.isPurple = false;
                fnDinoDefault(resources, texture);
                resources.spPreset.setTexture(texture.txhdefault);
            }
            //Dino Red
            if (mousePos.x > 30 && mousePos.x < 310 && mousePos.y>313 && mousePos.y < 556 && resources.isRed == false) {
                resources.isDefault = false;
                resources.isRed = true;
                resources.isBlue = false;
                resources.isPurple = false;
                resources.Sclick0.play();
                fnDinoRed(resources, texture);
                resources.spPreset.setTexture(texture.txhred);
            }
            //Dino Blue
            if (mousePos.x > 500 && mousePos.x < 780 && mousePos.y>313 && mousePos.y < 556 && resources.isBlue == false) {
                resources.isDefault = false;
                resources.isRed = false;
                resources.isBlue = true;
                resources.isPurple = false;
                resources.Sclick0.play();
                fnDinoBlue(resources, texture);
                resources.spPreset.setTexture(texture.txhblue);
            }
            //Dino Purple
            if (mousePos.x > 973 && mousePos.x < 1252 && mousePos.y>313 && mousePos.y < 556 && resources.isPurple == false) {
                resources.isDefault = false;
                resources.isRed = false;
                resources.isBlue = false;
                resources.isPurple = true;
                resources.Sclick0.play();
                fnDinoPurple(resources, texture);
            }
        }
       //skin select effect
        if (resources.isDefault)
            resources.spPreset.setTexture(texture.txhdefault);
        if (resources.isPurple)
            resources.spPreset.setTexture(texture.txhpurple);
        if (resources.isRed)
            resources.spPreset.setTexture(texture.txhred);
        if (resources.isBlue)
            resources.spPreset.setTexture(texture.txhblue);

    }
}
int main()
{
    Texs texture;
    Menu resources;
    //window resolution and game title
    RenderWindow window(VideoMode(1280, 720), "Dinosaur");
    fnLoadTexture(resources, texture);
    fnSetTexture(resources, texture);
    fnSetPosition(window, resources, texture);
    fnSetScale(window, resources, texture);
    //FPS Limit
    window.setFramerateLimit(30);
    //Music MainMenu & Options
    resources.Game.setVolume(10);
    resources.Game.play();
    resources.Game.setLoop(true);
    Event event;
    while (window.isOpen()) {
        //function to display main menu
        if (resources.ScreenIndex == 0) {
            fnMainMenu(window, event, resources, texture);
        }
        //Options
        else if (resources.ScreenIndex == 1) {
            fnOptions(window, event, resources, texture);
        }
        //Credits
        else if (resources.ScreenIndex == 3) {
            fnCredits(window, event, resources);
        }
        //Preset
        else if (resources.ScreenIndex == 4) {
            fnPreset(window, event, resources, texture);
        }
        //Popup Menu
        else if (resources.ScreenIndex == 5) {
            fnPopup(window, event, resources, texture);
        }
        //Game loop
        else if (resources.ScreenIndex == 2) {
            resources.isStart = true;
            bool gameover = false;
            fnResetGame(window, resources, gameover, texture);
            //First Fall
            resources.spDino.setPosition(100, 400);
            resources.spDino.setTexture(texture.txDinoFall);
            resources.spDino.setTextureRect(IntRect(0, 0, 348, 139));
            resources.grounded = false;
             
            int temphiscore = resources.finalhiscore;
            while (true)
            {
                while (window.pollEvent(event)) {
                    if (event.type == Event::Closed) {
                        window.close();
                        exit(EXIT_SUCCESS);
                    }
                }
                FloatRect DinoBounds = resources.spDino.getGlobalBounds();
                FloatRect cactusBounds[3], smallcactusBounds[3], Batbounds[2];
                fnBatAnimation(resources, texture, Batbounds);
                //Cactus fix
                for (int i = 0; 3 > i; ++i) {
                    cactusBounds[i] = resources.cactus[i].getGlobalBounds();
                    smallcactusBounds[i] = resources.smallcactus[i].getGlobalBounds();
                    cactusBounds[i].width -= 10;
                    smallcactusBounds[i].width -= 10;
                }
                resources.isCrouch = false;
                //crouch animation down
                if (resources.grounded && resources.spDino.getTexture() == &texture.txDinoCrouch && Keyboard::isKeyPressed(Keyboard::Down)) {
                    resources.isCrouch = true;
                    resources.spDino.setTextureRect(IntRect(0, 0, 348, 139));
                }
                //crouch animation S
                else if (resources.grounded && resources.spDino.getTexture() == &texture.txDinoCrouch && Keyboard::isKeyPressed(Keyboard::S)) {
                    resources.isCrouch = true;
                    resources.spDino.setTextureRect(IntRect(0, 0, 348, 139));
                }
                // Fall to run Bug fix
                else if (resources.grounded) {
                    resources.isCrouch = false;
                    float dy = 0;
                    if (DinoBounds.top < resources.ground.getGlobalBounds().top)
                    {
                        dy = resources.ground.getGlobalBounds().top - (DinoBounds.top + DinoBounds.height);
                    }
                    resources.spDino.move(0, dy);
                    resources.spDino.setTexture(texture.txDino);
                    //run animation
                    if (resources.time1.getElapsedTime().asMilliseconds() >= 60) {
                        ++resources.timer2;
                        resources.time1.restart();
                            if (resources.timer2 >= 1) {
                                resources.spDino.setTextureRect(IntRect(resources.DinoIndex * 348, 0, 348, 139));
                                resources.DinoIndex++;
                                resources.DinoIndex %= 6;
                            }
                    }
                    DinoBounds.width -= 30;
                }
                //Jump bounds fix and accelerate down
                else {
                    if (Keyboard::isKeyPressed(Keyboard::Down) && resources.grounded == false) {
                        resources.VelocityY -= 1;
                    }
                    else if (Keyboard::isKeyPressed(Keyboard::S) && resources.grounded == false) {
                        resources.VelocityY -= 1;
                    }
                    DinoBounds.height += 10;
                    DinoBounds.width -= 100;
                }
                //gravity and fall
                if (resources.ground.getGlobalBounds().intersects(DinoBounds)) {
                    resources.grounded = true;
                    resources.VelocityY = 0;
                    // Up and down controller
                    if (resources.isarrow == true && resources.isws == false) {
                        fnUpDownControls(resources, texture, DinoBounds);
                    }
                    //W & S controller
                    else if (resources.isarrow == false && resources.isws == true) {
                        fnWSControls(resources, texture, DinoBounds);
                    }
                }
                //Normal fall
                else {
                    resources.VelocityY -= 2;
                }
                //crouch animation down
                if (resources.grounded && resources.spDino.getTexture() == &texture.txDinoCrouch && Keyboard::isKeyPressed(Keyboard::Down)) {
                    resources.spDino.setTextureRect(IntRect(0, 0, 348, 139));
                }
                //crouch animation S
                if (resources.grounded && resources.spDino.getTexture() == &texture.txDinoCrouch && Keyboard::isKeyPressed(Keyboard::S)) {
                    resources.spDino.setTextureRect(IntRect(0, 0, 348, 139));
                }
                //fall animation
                if (resources.VelocityY < 0 && resources.spDino.getTexture() == &texture.txDinoJump) {
                    resources.spDino.setTexture(texture.txDinoFall);
                    resources.spDino.setTextureRect(IntRect(0, 0, 348, 139));
                }

                //Dino movement
               resources.spDino.move(0, -resources.VelocityY);
                window.clear();
                //Update Bat position
                fnBatPosition(resources);
                //Update Cactus Position
                fnCactusPosition(resources);
                // Game Over senarios
                for (int i = 0; 3 > i; ++i) {
                    if ((DinoBounds.intersects(cactusBounds[i]) && abs(resources.spDino.getPosition().x - resources.cactus[i].getPosition().x) > 80) || (DinoBounds.intersects(smallcactusBounds[i]) && abs(resources.spDino.getPosition().x - resources.smallcactus[i].getPosition().x) > 20)) {
                        gameover = true;
                    }
                }
                for (int i = 0; 2 > i; ++i) {
                    if (DinoBounds.intersects(Batbounds[i]) && abs(resources.spDino.getPosition().x - resources.spBat[i].getPosition().x) > 80) {
                        gameover = true;
                    }
                }
                fnUpdateScore(resources, temphiscore, gameover);
                fnUpdateDifficulty(resources);
                fnObstacleMove(resources);
                //Dark mode
                if ((resources.score / 500) % 2 != 0)
                {
                    fnDarkMode(window, event, resources, texture, gameover);
                }
                //Light mode
                else
                {
                    fnLightMode(window, event, resources, texture, gameover);
                }

                if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                    fnPauseMenu(window, event, resources, texture);
                }
                if (resources.ScreenIndex == 0) {
                    break;
                }
                //Draw 
                window.draw(resources.spDino);
                if (resources.isStart == false) {
                    break;
                }
                window.display();
            }
        }

        window.display();
    }
    return 0;
}