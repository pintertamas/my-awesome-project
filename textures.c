#include "global.h"
#include "textures.h"

void loadImage(){

    textures[0] = LoadImage("Textures/players/spaceShip.png");                                                         // Loaded in CPU memory (RAM)
    ImageFormat(&textures[0], UNCOMPRESSED_R8G8B8A8);                                                        // Format image to RGBA 32bit (required for texture update)
    spaceShip = LoadTextureFromImage(textures[0]);                                                             // Image converted to texture, GPU memory (VRAM)

    textures[1] = LoadImage("Textures/bullets/redBullet.png");
    ImageFormat(&textures[1], UNCOMPRESSED_R8G8B8A8);
    redBullet = LoadTextureFromImage(textures[1]);

    textures[2] = LoadImage("Textures/backgrounds/background_mountains.png");
    ImageFormat(&textures[2], UNCOMPRESSED_R8G8B8A8);
    background_mountains = LoadTextureFromImage(textures[2]);

    textures[3] = LoadImage("Textures/backgrounds/background_blank.png");
    ImageFormat(&textures[3], UNCOMPRESSED_R8G8B8A8);
    menuBackground = LoadTextureFromImage(textures[3]);

    textures[4] = LoadImage("Textures/buttons/startButton_simple.png");
    ImageFormat(&textures[4], UNCOMPRESSED_R8G8B8A8);
    startButton_simple = LoadTextureFromImage(textures[4]);

    textures[5] = LoadImage("Textures/buttons/startButton_clicked.png");
    ImageFormat(&textures[5], UNCOMPRESSED_R8G8B8A8);
    startButton_clicked = LoadTextureFromImage(textures[5]);

    textures[6] = LoadImage("Textures/buttons/settingsButton_simple.png");
    ImageFormat(&textures[6], UNCOMPRESSED_R8G8B8A8);
    settingsButton_simple = LoadTextureFromImage(textures[6]);

    textures[7] = LoadImage("Textures/buttons/settingsButton_clicked.png");
    ImageFormat(&textures[7], UNCOMPRESSED_R8G8B8A8);
    settingsButton_clicked = LoadTextureFromImage(textures[7]);

    textures[8] = LoadImage("Textures/buttons/scoresButton_simple.png");
    ImageFormat(&textures[8], UNCOMPRESSED_R8G8B8A8);
    scoresButton_simple = LoadTextureFromImage(textures[8]);

    textures[9] = LoadImage("Textures/buttons/scoresButton_clicked.png");
    ImageFormat(&textures[9], UNCOMPRESSED_R8G8B8A8);
    scoresButton_clicked = LoadTextureFromImage(textures[9]);

    textures[10] = LoadImage("Textures/buttons/easyMode.png");
    ImageFormat(&textures[10], UNCOMPRESSED_R8G8B8A8);
    easyMode = LoadTextureFromImage(textures[10]);

    textures[11] = LoadImage("Textures/buttons/mediumMode.png");
    ImageFormat(&textures[11], UNCOMPRESSED_R8G8B8A8);
    mediumMode = LoadTextureFromImage(textures[11]);

    textures[12] = LoadImage("Textures/buttons/hardMode.png");
    ImageFormat(&textures[12], UNCOMPRESSED_R8G8B8A8);
    hardMode = LoadTextureFromImage(textures[12]);

    textures[13] = LoadImage("Textures/buttons/easyMode_selected.png");
    ImageFormat(&textures[13], UNCOMPRESSED_R8G8B8A8);
    easyMode_selected = LoadTextureFromImage(textures[13]);

    textures[14] = LoadImage("Textures/buttons/mediumMode_selected.png");
    ImageFormat(&textures[14], UNCOMPRESSED_R8G8B8A8);
    mediumMode_selected = LoadTextureFromImage(textures[14]);

    textures[15] = LoadImage("Textures/buttons/hardMode_selected.png");
    ImageFormat(&textures[15], UNCOMPRESSED_R8G8B8A8);
    hardMode_selected = LoadTextureFromImage(textures[15]);

    textures[16] = LoadImage("Textures/thumbnails/mountains_small.png");
    ImageFormat(&textures[16], UNCOMPRESSED_R8G8B8A8);
    mountains_small = LoadTextureFromImage(textures[16]);

    textures[17] = LoadImage("Textures/thumbnails/forest_small.png");
    ImageFormat(&textures[17], UNCOMPRESSED_R8G8B8A8);
    forest_small = LoadTextureFromImage(textures[17]);

    textures[18] = LoadImage("Textures/buttons/backButton_simple.png");
    ImageFormat(&textures[18], UNCOMPRESSED_R8G8B8A8);
    backButton_simple = LoadTextureFromImage(textures[18]);

    textures[19] = LoadImage("Textures/buttons/backButton_clicked.png");
    ImageFormat(&textures[19], UNCOMPRESSED_R8G8B8A8);
    backButton_clicked = LoadTextureFromImage(textures[19]);

    textures[20] = LoadImage("Textures/settingsLogo.png");
    ImageFormat(&textures[20], UNCOMPRESSED_R8G8B8A8);
    settingsLogo = LoadTextureFromImage(textures[20]);

    textures[21] = LoadImage("Textures/backgrounds/background_forest.png");
    ImageFormat(&textures[21], UNCOMPRESSED_R8G8B8A8);
    background_forest = LoadTextureFromImage(textures[21]);

    textures[22] = LoadImage("Textures/backgrounds/background_japan.png");
    ImageFormat(&textures[22], UNCOMPRESSED_R8G8B8A8);
    background_japan = LoadTextureFromImage(textures[22]);

    textures[23] = LoadImage("Textures/backgrounds/background_space.png");
    ImageFormat(&textures[23], UNCOMPRESSED_R8G8B8A8);
    background_space = LoadTextureFromImage(textures[23]);

    textures[24] = LoadImage("Textures/thumbnails/frame_selected.png");
    ImageFormat(&textures[24], UNCOMPRESSED_R8G8B8A8);
    frame_selected = LoadTextureFromImage(textures[24]);

    textures[25] = LoadImage("Textures/thumbnails/frame_unselected.png");
    ImageFormat(&textures[25], UNCOMPRESSED_R8G8B8A8);
    frame_unselected = LoadTextureFromImage(textures[25]);

    textures[26] = LoadImage("Textures/thumbnails/japan_small.png");
    ImageFormat(&textures[26], UNCOMPRESSED_R8G8B8A8);
    japan_small = LoadTextureFromImage(textures[26]);

    textures[27] = LoadImage("Textures/thumbnails/space_small.png");
    ImageFormat(&textures[27], UNCOMPRESSED_R8G8B8A8);
    space_small = LoadTextureFromImage(textures[27]);

    textures[28] = LoadImage("Textures/backgrounds/background_unknown.png");
    ImageFormat(&textures[28], UNCOMPRESSED_R8G8B8A8);
    background_unknown = LoadTextureFromImage(textures[28]);

    textures[29] = LoadImage("Textures/backgrounds/background_gameOver.png");
    ImageFormat(&textures[29], UNCOMPRESSED_R8G8B8A8);
    background_gameOver = LoadTextureFromImage(textures[29]);

    textures[30] = LoadImage("Textures/heart.png");
    ImageFormat(&textures[30], UNCOMPRESSED_R8G8B8A8);
    heart = LoadTextureFromImage(textures[30]);

    textures[31] = LoadImage("Textures/bullets/brownBullet.png");
    ImageFormat(&textures[31], UNCOMPRESSED_R8G8B8A8);
    brownBullet = LoadTextureFromImage(textures[31]);

    textures[32] = LoadImage("Textures/bullets/greenBullet.png");
    ImageFormat(&textures[32], UNCOMPRESSED_R8G8B8A8);
    greenBullet = LoadTextureFromImage(textures[32]);

    textures[33] = LoadImage("Textures/bullets/starBullet.png");
    ImageFormat(&textures[33], UNCOMPRESSED_R8G8B8A8);
    starBullet = LoadTextureFromImage(textures[33]);

    textures[34] = LoadImage("Textures/balls/greenBall.png");
    ImageFormat(&textures[34], UNCOMPRESSED_R8G8B8A8);
    greenBall = LoadTextureFromImage(textures[34]);

    textures[35] = LoadImage("Textures/balls/blueBall.png");
    ImageFormat(&textures[35], UNCOMPRESSED_R8G8B8A8);
    blueBall = LoadTextureFromImage(textures[35]);

    textures[36] = LoadImage("Textures/balls/orangeBall.png");
    ImageFormat(&textures[36], UNCOMPRESSED_R8G8B8A8);
    orangeBall = LoadTextureFromImage(textures[36]);

    textures[37] = LoadImage("Textures/balls/redBall.png");
    ImageFormat(&textures[37], UNCOMPRESSED_R8G8B8A8);
    redBall = LoadTextureFromImage(textures[37]);

    textures[38] = LoadImage("Textures/balls/purpleBall.png");
    ImageFormat(&textures[38], UNCOMPRESSED_R8G8B8A8);
    purpleBall = LoadTextureFromImage(textures[38]);

    textures[39] = LoadImage("Textures/icon.png");
    ImageFormat(&textures[39], UNCOMPRESSED_R8G8B8A8);
    window_icon = LoadTextureFromImage(textures[39]);

    textures[40] = LoadImage("Textures/players/car.png");
    ImageFormat(&textures[40], UNCOMPRESSED_R8G8B8A8);
    car = LoadTextureFromImage(textures[40]);

    textures[41] = LoadImage("Textures/players/ninja.png");
    ImageFormat(&textures[41], UNCOMPRESSED_R8G8B8A8);
    ninja = LoadTextureFromImage(textures[41]);

    textures[42] = LoadImage("Textures/backgrounds/logo.png");
    ImageFormat(&textures[42], UNCOMPRESSED_R8G8B8A8);
    logo = LoadTextureFromImage(textures[42]);

    textures[43] = LoadImage("Textures/scoresLogo.png");
    ImageFormat(&textures[43], UNCOMPRESSED_R8G8B8A8);
    scoresLogo = LoadTextureFromImage(textures[43]);

    textures[44] = LoadImage("Textures/crown.png");
    ImageFormat(&textures[44], UNCOMPRESSED_R8G8B8A8);
    crown = LoadTextureFromImage(textures[44]);
}