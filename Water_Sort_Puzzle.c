#include "raylib.h"

#define MAX_TUBES 3
#define MAX_COLORS 3
#define TUBE_WIDTH 100
#define TUBE_HEIGHT 150
#define TUBE_SPACING 150
#define TUBE_SELECTION_COLOR GRAY // Seçili tüpün çerçeve rengi
#define TUBE_SELECTION_THICKNESS 8 // Seçili tüpün çerçeve kalınlığı

#define MAX_TUBES2 5                       //oyun içinde kullanılacak tüp sayısını belirleyen bir sabittir
#define MAX_COLORS2 4                     // tüplerin içerebileceği renk sayısını belirleyen bir sabittir
#define TUBE_WIDTH2 100                  //tüpün genişliğini belirleyen bir sabittir
#define TUBE_HEIGHT2 200                //tüpün yüksekliğini belirleyen bir sabittir
#define TUBE_SPACING2 50              //tüpler arasındaki boşluğu belirleyen bir sabittir
#define TUBE_SELECTION_COLOR2 GRAY    // Seçili tüpün çerçeve rengini belirleyen bir sabittir 
#define TUBE_SELECTION_THICKNESS2 8  // Seçili tüpün çerçeve kalınlığını belirleyen bir sabittir

#define MAX_TUBES3 9                      //oyun içinde kullanılacak tüp sayısını belirleyen bir sabittir
#define MAX_COLORS3 4                     // tüplerin içerebileceği renk sayısını belirleyen bir sabittir
#define TUBE_WIDTH3 40                  //tüpün genişliğini belirleyen bir sabittir
#define TUBE_HEIGHT3 200                //tüpün yüksekliğini belirleyen bir sabittir
#define TUBE_SPACING3 20              //tüpler arasındaki boşluğu belirleyen bir sabittir
#define TUBE_SELECTION_COLOR3 GRAY    // Seçili tüpün çerçeve rengini belirleyen bir sabittir 
#define TUBE_SELECTION_THICKNESS3 6  // Seçili tüpün çerçeve kalınlığını belirleyen bir sabittir

typedef struct {        //Tube1
    Color colors[MAX_COLORS];
    int count;
    Vector2 position; // Tüpün pozisyonu
    bool selected; // Tüp seçilmiş mi?
} Tube;

typedef struct {        //Tube2
    Color colors[MAX_COLORS2];
    int count;
    Vector2 position; // Tüpün pozisyonu
    bool selected; // Tüp seçilmiş mi?
} Tube2;

typedef struct {        //Tube3
    Color colors[MAX_COLORS3];
    int count;
    Vector2 position; // Tüpün pozisyonu
    bool selected; // Tüp seçilmiş mi?
} Tube3;

Tube tubes[MAX_TUBES];
Tube2 tubes2[MAX_TUBES2];
Tube3 tubes3[MAX_TUBES3];
int selectedTubeIndex = -1; // Seçili tüpün dizinini tutar (-1: hiçbiri seçilmedi)

//********

typedef enum {
    MAIN_MENU,
    PLAY,
    HOW_TO_PLAY,
    EXIT,
    LEVEL_1,
    LEVEL_2,
    LEVEL_3
} MenuState;

MenuState currentMenuState = MAIN_MENU;

//********

bool IsTubeUniform(int tubeIndex) {
    if (tubes[tubeIndex].count == 0 || tubes[tubeIndex].count < MAX_COLORS) return false;
    Color firstColor = tubes[tubeIndex].colors[0];
    for (int i = 1; i < tubes[tubeIndex].count; i++) {
        if (tubes[tubeIndex].colors[i].r != firstColor.r ||
            tubes[tubeIndex].colors[i].g != firstColor.g ||
            tubes[tubeIndex].colors[i].b != firstColor.b) {
            return false;
        }
    }
    return true;
}

bool IsTubeUniform2(int tubeIndex) {
    if (tubes2[tubeIndex].count == 0 || tubes2[tubeIndex].count < MAX_COLORS2) return false;
    Color firstColor = tubes2[tubeIndex].colors[0];
    for (int i = 1; i < tubes2[tubeIndex].count; i++) {
        if (tubes2[tubeIndex].colors[i].r != firstColor.r ||
            tubes2[tubeIndex].colors[i].g != firstColor.g ||
            tubes2[tubeIndex].colors[i].b != firstColor.b) {
            return false;
        }
    }
    return true;
}

bool IsTubeUniform3(int tubeIndex) {
    if (tubes3[tubeIndex].count == 0 || tubes3[tubeIndex].count < MAX_COLORS3) return false;
    Color firstColor = tubes3[tubeIndex].colors[0];
    for (int i = 1; i < tubes3[tubeIndex].count; i++) {
        if (tubes3[tubeIndex].colors[i].r != firstColor.r ||
            tubes3[tubeIndex].colors[i].g != firstColor.g ||
            tubes3[tubeIndex].colors[i].b != firstColor.b) {
            return false;
        }
    }
    return true;
}

void SetupGame() {
    // Tüp başlangıç durumları
    tubes[0] = (Tube){{BLUE, RED, BLUE}, 3, {100, 300}, false};
    tubes[1] = (Tube){{RED, BLUE, RED}, 3, {300, 300}, false};
    tubes[2] = (Tube){{0}, 0, {500, 300}, false};
}

void SetupGame2() {
    tubes2[0] = (Tube2){{RED, ORANGE, RED, GREEN}, 4, {50, 350}, false};
    tubes2[1] = (Tube2){{ORANGE, ORANGE, RED, GREEN}, 4, {200, 350}, false};
    tubes2[2] = (Tube2){{RED, GREEN, ORANGE, GREEN}, 4, {350, 350}, false};
    tubes2[3] = (Tube2){{0}, 0, {500, 350}, false};
    tubes2[4] = (Tube2){{0}, 0, {650, 350}, false};
}

void SetupGame3() {
    tubes3[0] = (Tube3){{PURPLE, PINK, BLUE,YELLOW}, 4, {100, 300}, false};
    tubes3[1] = (Tube3){{PINK, YELLOW, PINK, ORANGE}, 4, {240, 300}, false};
    tubes3[2] = (Tube3){{RED, GREEN, BLUE, RED}, 4, {380, 300}, false};
    tubes3[3] = (Tube3){{YELLOW, GREEN, ORANGE, GREEN}, 4, {520, 300}, false};
    tubes3[4] = (Tube3){{BLUE, ORANGE, GREEN, RED}, 4, {660, 300}, false};
    tubes3[5] = (Tube3){{RED, YELLOW, ORANGE, BLUE}, 4, {170, 400}, false};
    tubes3[6] = (Tube3){{PINK, PURPLE, PURPLE, PURPLE}, 4, {310, 400}, false};
    tubes3[7] = (Tube3){{0}, 0, {450, 400}, false};
    tubes3[8] = (Tube3){{0}, 0, {590, 400}, false};
}

bool CheckWinCondition() {
    int emptyTubeCount = 0;
    for (int i = 0; i < MAX_TUBES; i++) {
        if (!IsTubeUniform(i)) {
            if (tubes[i].count == 0) {
                emptyTubeCount++;
            } else {
                return false;
            }
        }
    }
    return emptyTubeCount <= 1; // Tüplerden sadece birinin boş olması durumunu kabul et
}

bool CheckWinCondition2() {
    int emptyTubeCount = 0;
    for (int i = 0; i < MAX_TUBES2; i++) {
        if (!IsTubeUniform2(i)) {
            if (tubes2[i].count == 0) {
                emptyTubeCount++;
            } else {
                return false;
            }
        }
    }
    return emptyTubeCount <= 2; // Tüplerden sadece birinin boş olması durumunu kabul et
}

bool CheckWinCondition3() {
    int emptyTubeCount = 0;
    for (int i = 0; i < MAX_TUBES3; i++) {
        if (!IsTubeUniform3(i)) {
            if (tubes3[i].count == 0) {
                emptyTubeCount++;
            } else {
                return false;
            }
        }
    }
    return emptyTubeCount <= 2; // Tüplerden sadece birinin boş olması durumunu kabul et
}

int GetSameColorLiquidCount(int sourceTubeIndex) {
    Color targetColor = tubes[sourceTubeIndex].colors[tubes[sourceTubeIndex].count - 1];
    int count = 0;
    
    // Seçilen tüpteki sıvıları kontrol et
    for (int i = tubes[sourceTubeIndex].count - 1; i >= 0; i--) {
        if (tubes[sourceTubeIndex].colors[i].r == targetColor.r &&
            tubes[sourceTubeIndex].colors[i].g == targetColor.g &&
            tubes[sourceTubeIndex].colors[i].b == targetColor.b) {
            count++;
        } else {
            break; // Üst üste aynı renk değilse döngüden çık
        }
    }
    
    return count;
}

int GetSameColorLiquidCount2(int sourceTubeIndex) {
    Color targetColor = tubes2[sourceTubeIndex].colors[tubes2[sourceTubeIndex].count - 1];
    int count = 0;
    
    // Seçilen tüpteki sıvıları kontrol et
    for (int i = tubes2[sourceTubeIndex].count - 1; i >= 0; i--) {
        if (tubes2[sourceTubeIndex].colors[i].r == targetColor.r &&
            tubes2[sourceTubeIndex].colors[i].g == targetColor.g &&
            tubes2[sourceTubeIndex].colors[i].b == targetColor.b) {
            count++;
        } else {
            break; // Üst üste aynı renk değilse döngüden çık
        }
    }
    
    return count;
}

int GetSameColorLiquidCount3(int sourceTubeIndex) {
    Color targetColor = tubes3[sourceTubeIndex].colors[tubes3[sourceTubeIndex].count - 1];
    int count = 0;
    
    // Seçilen tüpteki sıvıları kontrol et
    for (int i = tubes3[sourceTubeIndex].count - 1; i >= 0; i--) {
        if (tubes3[sourceTubeIndex].colors[i].r == targetColor.r &&
            tubes3[sourceTubeIndex].colors[i].g == targetColor.g &&
            tubes3[sourceTubeIndex].colors[i].b == targetColor.b) {
            count++;
        } else {
            break; // Üst üste aynı renk değilse döngüden çık
        }
    }
    
    return count;
}

bool CanPourLiquid(int sourceTubeIndex, int targetTubeIndex) {
    // Dökme için uygunluk koşulları
    if (sourceTubeIndex == targetTubeIndex || tubes[sourceTubeIndex].count == 0 || 
        tubes[targetTubeIndex].count == MAX_COLORS) {
        return false; // Aynı tüpe veya dolu bir tüpe dökülemez
    }

    // Hedef tüpte yeterli boşluk var mı kontrol et
    int emptySpaces = MAX_COLORS - tubes[targetTubeIndex].count;
    if (emptySpaces == 0) {
        return false; // Hedef tüpte boşluk yoksa dökülemez
    }

    // Kaynak ve hedef tüplerin renklerini kontrol et
    Color liquidColor = tubes[sourceTubeIndex].colors[tubes[sourceTubeIndex].count - 1];
    if (tubes[targetTubeIndex].count > 0) {
        Color targetColor = tubes[targetTubeIndex].colors[tubes[targetTubeIndex].count - 1];
        if (liquidColor.r != targetColor.r || liquidColor.g != targetColor.g || liquidColor.b != targetColor.b) {
            return false; // Kaynak ve hedef tüplerin renkleri eşleşmiyorsa dökülemez
        }
    }

    return true;
}

bool CanPourLiquid2(int sourceTubeIndex, int targetTubeIndex) {
    // Dökme için uygunluk koşulları
    if (sourceTubeIndex == targetTubeIndex || tubes2[sourceTubeIndex].count == 0 || 
        tubes2[targetTubeIndex].count == MAX_COLORS2) {
        return false; // Aynı tüpe veya dolu bir tüpe dökülemez
    }

    // Hedef tüpte yeterli boşluk var mı kontrol et
    int emptySpaces = MAX_COLORS2 - tubes2[targetTubeIndex].count;
    if (emptySpaces == 0) {
        return false; // Hedef tüpte boşluk yoksa dökülemez
    }

    // Kaynak ve hedef tüplerin renklerini kontrol et
    Color liquidColor = tubes2[sourceTubeIndex].colors[tubes2[sourceTubeIndex].count - 1];
    if (tubes2[targetTubeIndex].count > 0) {
        Color targetColor = tubes2[targetTubeIndex].colors[tubes2[targetTubeIndex].count - 1];
        if (liquidColor.r != targetColor.r || liquidColor.g != targetColor.g || liquidColor.b != targetColor.b) {
            return false; // Kaynak ve hedef tüplerin renkleri eşleşmiyorsa dökülemez
        }
    }

    return true;
}

bool CanPourLiquid3(int sourceTubeIndex, int targetTubeIndex) {
    // Dökme için uygunluk koşulları
    if (sourceTubeIndex == targetTubeIndex || tubes3[sourceTubeIndex].count == 0 || 
        tubes3[targetTubeIndex].count == MAX_COLORS3) {
        return false; // Aynı tüpe veya dolu bir tüpe dökülemez
    }

    // Hedef tüpte yeterli boşluk var mı kontrol et
    int emptySpaces = MAX_COLORS3 - tubes3[targetTubeIndex].count;
    if (emptySpaces == 0) {
        return false; // Hedef tüpte boşluk yoksa dökülemez
    }

    // Kaynak ve hedef tüplerin renklerini kontrol et
    Color liquidColor = tubes3[sourceTubeIndex].colors[tubes3[sourceTubeIndex].count - 1];
    if (tubes3[targetTubeIndex].count > 0) {
        Color targetColor = tubes3[targetTubeIndex].colors[tubes3[targetTubeIndex].count - 1];
        if (liquidColor.r != targetColor.r || liquidColor.g != targetColor.g || liquidColor.b != targetColor.b) {
            return false; // Kaynak ve hedef tüplerin renkleri eşleşmiyorsa dökülemez
        }
    }

    return true;
}

void PourSameColorLiquid(int sourceTubeIndex, int targetTubeIndex, int liquidCount) {
    // Önce dökme işlemi için uygunluk kontrolünü yap
    if (!CanPourLiquid(sourceTubeIndex, targetTubeIndex)) {
        return; // Eğer dökülemezse fonksiyondan çık
    }

    // Hedef tüpte kaç boşluk olduğunu hesapla
    int availableSpace = MAX_COLORS - tubes[targetTubeIndex].count;
    
    // Kaynak tüpteki üst sıvının rengini al
    Color liquidColor = tubes[sourceTubeIndex].colors[tubes[sourceTubeIndex].count - 1];

    // Aktarılacak sıvı miktarını belirle (en fazla boşluk kadar veya sıvı sayısı kadar)
    int transferAmount;
    if (availableSpace >= liquidCount) {
        transferAmount = liquidCount;
    } else {
        transferAmount = availableSpace;
    }

    // Sıvıların renklerini kontrol ederek aktar
    for (int i = 0; i < transferAmount; i++) {
        tubes[targetTubeIndex].colors[tubes[targetTubeIndex].count] = liquidColor;
        tubes[targetTubeIndex].count++;
        tubes[sourceTubeIndex].count--;
    }
}

void PourSameColorLiquid2(int sourceTubeIndex, int targetTubeIndex, int liquidCount) {
    // Önce dökme işlemi için uygunluk kontrolünü yap
    if (!CanPourLiquid2(sourceTubeIndex, targetTubeIndex)) {
        return; // Eğer dökülemezse fonksiyondan çık
    }

    // Hedef tüpte kaç boşluk olduğunu hesapla
    int availableSpace = MAX_COLORS2 - tubes2[targetTubeIndex].count;
    
    // Kaynak tüpteki üst sıvının rengini al
    Color liquidColor = tubes2[sourceTubeIndex].colors[tubes2[sourceTubeIndex].count - 1];

    // Aktarılacak sıvı miktarını belirle (en fazla boşluk kadar veya sıvı sayısı kadar)
    int transferAmount;
    if (availableSpace >= liquidCount) {
        transferAmount = liquidCount;
    } else {
        transferAmount = availableSpace;
    }

    // Sıvıların renklerini kontrol ederek aktar
    for (int i = 0; i < transferAmount; i++) {
        tubes2[targetTubeIndex].colors[tubes2[targetTubeIndex].count] = liquidColor;
        tubes2[targetTubeIndex].count++;
        tubes2[sourceTubeIndex].count--;
    }
}

void PourSameColorLiquid3(int sourceTubeIndex, int targetTubeIndex, int liquidCount) {
    // Önce dökme işlemi için uygunluk kontrolünü yap
    if (!CanPourLiquid3(sourceTubeIndex, targetTubeIndex)) {
        return; // Eğer dökülemezse fonksiyondan çık
    }

    // Hedef tüpte kaç boşluk olduğunu hesapla
    int availableSpace = MAX_COLORS3 - tubes3[targetTubeIndex].count;
    
    // Kaynak tüpteki üst sıvının rengini al
    Color liquidColor = tubes3[sourceTubeIndex].colors[tubes3[sourceTubeIndex].count - 1];

    // Aktarılacak sıvı miktarını belirle (en fazla boşluk kadar veya sıvı sayısı kadar)
    int transferAmount;
    if (availableSpace >= liquidCount) {
        transferAmount = liquidCount;
    } else {
        transferAmount = availableSpace;
    }
    
    // Sıvıların renklerini kontrol ederek aktar
    for (int i = 0; i < transferAmount; i++) {
        tubes3[targetTubeIndex].colors[tubes3[targetTubeIndex].count] = liquidColor;
        tubes3[targetTubeIndex].count++;
        tubes3[sourceTubeIndex].count--;
    }
}

int GetClickedTubeIndex(Vector2 mousePos) {
    for (int i = 0; i < MAX_TUBES; i++) {
        Rectangle tubeRect = {tubes[i].position.x, tubes[i].position.y - TUBE_HEIGHT, TUBE_WIDTH, TUBE_HEIGHT};
        if (CheckCollisionPointRec(mousePos, tubeRect) && !IsTubeUniform(i)) {
            return i;
        }
    }
    return -1;
}

int GetClickedTubeIndex2(Vector2 mousePos) {
    for (int i = 0; i < MAX_TUBES2; i++) {
        Rectangle tubeRect = {tubes2[i].position.x, tubes2[i].position.y - TUBE_HEIGHT2, TUBE_WIDTH2, TUBE_HEIGHT2};
        if (CheckCollisionPointRec(mousePos, tubeRect) && !IsTubeUniform2(i)) {
            return i;
        }
    }
    return -1;
}

int GetClickedTubeIndex3(Vector2 mousePos) {
    for (int i = 0; i < MAX_TUBES3; i++) {
        Rectangle tubeRect = {tubes3[i].position.x, tubes3[i].position.y - TUBE_HEIGHT3, TUBE_WIDTH3, TUBE_HEIGHT3};
        if (CheckCollisionPointRec(mousePos, tubeRect) && !IsTubeUniform3(i)) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    InitWindow(800,450, "Water Sort Puzzle Game");
    SetupGame();
    SetupGame2();
    SetupGame3();
    bool gameWon = false;

    bool gameWon2 = false;

    bool gameWon3 = false;

    while (!WindowShouldClose()) {
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        switch (currentMenuState) {
            case MAIN_MENU:
            
                // Ana menü durumu
                
// Ana menü metni çizimi
DrawText("WATER SORT PUZZLE GAME",110,40,40, BLUE);

// "PLAY" butonu çizimi
DrawRectangle(250, 100, 300, 90, RED);
DrawText("PLAY", 340,135,40, RAYWHITE);

// "HOW TO PLAY" butonu çizimi
DrawRectangle(250, 210, 300, 90, RED);
DrawText("HOW TO PLAY", 300, 245, 30, RAYWHITE);

// "EXIT" butonu çizimi
DrawRectangle(250, 320, 300, 90, RED);
DrawText("EXIT", 345, 355, 40, RAYWHITE);

    // Fare tıklamalarını ve tıklama pozisyonunu al
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        
        // "PLAY" butonuna tıklama
        if (CheckCollisionPointRec(mousePos, (Rectangle){250, 100, 300, 90})) {
            currentMenuState = PLAY;
        }
        // "HOW TO PLAY" butonuna tıklama
        else if (CheckCollisionPointRec(mousePos, (Rectangle){250, 210, 300, 90})) {
            currentMenuState = HOW_TO_PLAY;
        }
        // "EXIT" butonuna tıklama
        else if (CheckCollisionPointRec(mousePos, (Rectangle){250, 320, 300, 90})) {
            currentMenuState = EXIT;
        }
    }
    break; // Ana menü durumu switch bloğundan çıkış yapmalı

       case PLAY:
    // Oyun ekranı
    
    // "BACK" butonu çizimi
    DrawRectangle(10, 10, 20, 20, RED);
    DrawText("<-",15,15, 5, RAYWHITE);       

    // "LEVEL 1" butonu çizimi
    DrawRectangle(290, 87, 220, 50, RED);
    DrawText("LEVEL 1",335,97, 30, RAYWHITE);

    // "LEVEL 2" butonu çizimi
    DrawRectangle(290, 200, 220, 50, RED);
    DrawText("LEVEL 2",335, 210, 30, RAYWHITE);

    // "LEVEL 3" butonu çizimi
    DrawRectangle(290, 310, 220, 50, RED);
    DrawText("LEVEL 3", 335, 320, 30, RAYWHITE);

    // Fare tıklamalarını ve tıklama pozisyonunu al
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();

        // "BACK" butonuna tıklama
        if (CheckCollisionPointRec(mousePos, (Rectangle){10, 10, 20, 20})) {
         currentMenuState = MAIN_MENU;  
        }
        // "LEVEL 1" butonuna tıklama
        if (CheckCollisionPointRec(mousePos, (Rectangle){290, 87, 220, 50})) {
            currentMenuState = LEVEL_1;
        }
        // "LEVEL 2" butonuna tıklama
        else if (CheckCollisionPointRec(mousePos, (Rectangle){290, 200, 220, 50})) {
            currentMenuState = LEVEL_2;
        }
        // "LEVEL 3" butonuna tıklama
        else if (CheckCollisionPointRec(mousePos, (Rectangle){290, 310, 220, 50})) {
            currentMenuState = LEVEL_3;
        }
    }

    break;

    case LEVEL_1:
    // LEVEL 1 ekranı
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
       Vector2 mousePos = GetMousePosition();                     
    if(CheckCollisionPointRec(mousePos, (Rectangle){10,10,20,20})){  //BACK butonuna basma
        currentMenuState = PLAY;
        selectedTubeIndex = -1;
        
           tubes[0] = (Tube){{BLUE, RED, BLUE}, 3, {100, 300}, false};
           tubes[1] = (Tube){{RED, BLUE, RED}, 3, {300, 300}, false};
           tubes[2] = (Tube){{0}, 0, {500, 300}, false};

        
        gameWon = false;   
    }
    }
    
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {  //
       Vector2 mousePos = GetMousePosition();                     
    if(CheckCollisionPointRec(mousePos, (Rectangle){40,10,20,20})){  //RESTART butonuna basma
        
           tubes[0] = (Tube){{BLUE, RED, BLUE}, 3, {100, 300}, false};
           tubes[1] = (Tube){{RED, BLUE, RED}, 3, {300, 300}, false};
           tubes[2] = (Tube){{0}, 0, {500, 300}, false};
    }
    }
    // "BACK" butonu çizimi
           DrawRectangle(10, 10, 20, 20, RED);
           DrawText("<-",15,15, 5, RAYWHITE);

           DrawRectangle(40,10,20,20,RED);
           DrawText("R",45,15, 5, RAYWHITE);           


        if(gameWon==false){
            DrawText("Water Sort Puzzle Game", 150, 20, 40, BLUE);
            DrawText("Episode 1", 300, 50, 40, RED);
        }
    
    // Oyun ekranı
                if (!gameWon && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    Vector2 mousePos = GetMousePosition();
                    int clickedTubeIndex = GetClickedTubeIndex(mousePos);
                    if (selectedTubeIndex == -1 && clickedTubeIndex != -1) {
                        tubes[clickedTubeIndex].selected = true;
                        selectedTubeIndex = clickedTubeIndex;
                    } 
                    else if (clickedTubeIndex != -1 && selectedTubeIndex != clickedTubeIndex) {
                        PourSameColorLiquid(selectedTubeIndex, clickedTubeIndex, GetSameColorLiquidCount(selectedTubeIndex));
                        tubes[selectedTubeIndex].selected = false;
                        selectedTubeIndex = -1;
                        if (CheckWinCondition()) {
                            gameWon = true;
                        }
                    }
                }

                if (gameWon) {
                    // Oyun kazanıldı ve geçiş ekranı
                    ClearBackground(RAYWHITE);
        
                    DrawText("Congratulations! You won!", 120, 200, 40, GREEN);
                    
                    DrawRectangle(10,10,60,30,GREEN);
                    DrawText("BACK",20,18,16,WHITE);
                                       
                     if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                            Vector2 mousePos = GetMousePosition();                 
                    if(CheckCollisionPointRec(mousePos, (Rectangle){10,10,60,30})){
                        currentMenuState = PLAY;
                        gameWon = false;
                        tubes[0] = (Tube){{BLUE, RED, BLUE}, 3, {100, 300}, false};
                        tubes[1] = (Tube){{RED, BLUE, RED}, 3, {300, 300}, false};
                        tubes[2] = (Tube){{0}, 0, {500, 300}, false};
                        }
                    }
                    
                } else {
                    // Oyun devam ederken ana oyun ekranı çiziliyor
                    for (int i = 0; i < MAX_TUBES; i++) {
                        DrawRectangleLines(100 + i *200, 150, 100, 150, BLACK);
                    }

                    // Tüplerin içine sıvıları çizme
                    for (int i = 0; i < MAX_TUBES; i++) {
                        for (int j = 0; j < tubes[i].count; j++) {
                            DrawRectangle(100 + i * 200, 300 - 50 * (j + 1), TUBE_WIDTH, 50, tubes[i].colors[j]);
                        }
                        /*if (tubes[i].count == 0) {
                            DrawRectangleLines(100 + i * 200, 150, TUBE_WIDTH, TUBE_HEIGHT, GRAY);
                        }*/
                        if (i == selectedTubeIndex) {
                            // Seçili tüpün etrafına kalın çerçeve çiz
                            DrawRectangleLinesEx((Rectangle){100 + i * 200 - 4,146, 108,158}, TUBE_SELECTION_THICKNESS, TUBE_SELECTION_COLOR);
                        }
                    }
                }
    break;        
    
    case LEVEL_2:
    
    // LEVEL 2 ekranı
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
       Vector2 mousePos = GetMousePosition();                     
    if(CheckCollisionPointRec(mousePos, (Rectangle){10,10,20,20})){
        currentMenuState = PLAY;
        selectedTubeIndex = -1;
        
    tubes2[0] = (Tube2){{RED, ORANGE, RED, GREEN}, 4, {50, 350}, false};
    tubes2[1] = (Tube2){{ORANGE, ORANGE, RED, GREEN}, 4, {200, 350}, false};
    tubes2[2] = (Tube2){{RED, GREEN, ORANGE, GREEN}, 4, {350, 350}, false};
    tubes2[3] = (Tube2){{0}, 0, {500, 350}, false};
    tubes2[4] = (Tube2){{0}, 0, {650, 350}, false};
    
        gameWon = false;   
    }
    }
    
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
       Vector2 mousePos = GetMousePosition();                     
    if(CheckCollisionPointRec(mousePos, (Rectangle){40,10,20,20})){
        
    tubes2[0] = (Tube2){{RED, ORANGE, RED, GREEN}, 4, {50, 350}, false};
    tubes2[1] = (Tube2){{ORANGE, ORANGE, RED, GREEN}, 4, {200, 350}, false};
    tubes2[2] = (Tube2){{RED, GREEN, ORANGE, GREEN}, 4, {350, 350}, false};
    tubes2[3] = (Tube2){{0}, 0, {500, 350}, false};
    tubes2[4] = (Tube2){{0}, 0, {650, 350}, false};
    
    }
    }
    // "BACK" butonu çizimi
           DrawRectangle(10, 10, 20, 20, RED);
           DrawText("<-",15,15, 5, RAYWHITE);

           DrawRectangle(40,10,20,20,RED);
           DrawText("R",45,15, 5, RAYWHITE);           


        if(gameWon2==false){
            DrawText("Water Sort Puzzle Game", 150, 20, 40, GREEN);
            DrawText("Episode 2", 300, 50, 40, ORANGE);
        }
        
        // Oyun ekranı
    if (!gameWon2 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        int clickedTubeIndex = GetClickedTubeIndex2(mousePos);
        if (selectedTubeIndex == -1 && clickedTubeIndex != -1) {
            tubes2[clickedTubeIndex].selected = true;
            selectedTubeIndex = clickedTubeIndex;
        } else if (clickedTubeIndex != -1 && selectedTubeIndex != clickedTubeIndex) {
            PourSameColorLiquid2(selectedTubeIndex, clickedTubeIndex, GetSameColorLiquidCount2(selectedTubeIndex));
            tubes2[selectedTubeIndex].selected = false;
            selectedTubeIndex = -1;
            if (CheckWinCondition2()) {
                gameWon2 = true;
            }
        }
    }

    if (gameWon2) {
        // Oyun kazanıldı ve geçiş ekranı
        ClearBackground(RAYWHITE);

        DrawText("Congratulations! You won!", 120, 200, 40, GREEN);

        DrawRectangle(10, 10, 60, 30, GREEN);
        DrawText("BACK", 20, 18, 16, WHITE);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            if (CheckCollisionPointRec(mousePos, (Rectangle){10, 10, 60, 30})) {
                currentMenuState = PLAY;
                gameWon2 = false;
                tubes2[0] = (Tube2){{RED, ORANGE, RED, GREEN}, 4, {50, 350}, false};
                tubes2[1] = (Tube2){{ORANGE, ORANGE, RED, GREEN}, 4, {200, 350}, false};
                tubes2[2] = (Tube2){{RED, GREEN, ORANGE, GREEN}, 4, {350, 350}, false};
                tubes2[3] = (Tube2){{0}, 0, {500, 350}, false};
                tubes2[4] = (Tube2){{0}, 0, {650, 350}, false};
            }
        }

    } else {
        // Oyun devam ederken ana oyun ekranı çiziliyor
        for (int i = 0; i < MAX_TUBES2; i++) {
            DrawRectangleLines(50 + i * 150, 150, TUBE_WIDTH2, TUBE_HEIGHT2, BLACK);
        }

        // Tüplerin içine sıvıları çizme
        for (int i = 0; i < MAX_TUBES2; i++) {
            for (int j = 0; j < tubes2[i].count; j++) {
                DrawRectangle(50 + i * 150, 350 - 50 * (j + 1), TUBE_WIDTH2, 50, tubes2[i].colors[j]);
            }
            if (tubes2[i].count == 0) {
                DrawRectangleLines(50 + i * 150, 150, TUBE_WIDTH2, TUBE_HEIGHT2, GRAY);
            }
            if (i == selectedTubeIndex) {
                // Seçili tüpün etrafına kalın çerçeve çiz
                DrawRectangleLinesEx((Rectangle){50 + i * 150, 146, 108, 208}, TUBE_SELECTION_THICKNESS2, TUBE_SELECTION_COLOR2);
            }
        }
    }
        
    break;
    
    case LEVEL_3:
    
   // LEVEL 3 ekranı
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
       Vector2 mousePos = GetMousePosition();                     
    if(CheckCollisionPointRec(mousePos, (Rectangle){10,10,20,20})){
        currentMenuState = PLAY;
        selectedTubeIndex = -1;
        
    tubes3[0] = (Tube3){{PURPLE, PINK, BLUE,YELLOW}, 4, {100, 300}, false};
    tubes3[1] = (Tube3){{PINK, YELLOW, PINK, ORANGE}, 4, {240, 300}, false};
    tubes3[2] = (Tube3){{RED, GREEN, BLUE, RED}, 4, {380, 300}, false};
    tubes3[3] = (Tube3){{YELLOW, GREEN, ORANGE, GREEN}, 4, {520, 300}, false};
    tubes3[4] = (Tube3){{BLUE, ORANGE, GREEN, RED}, 4, {660, 300}, false};
    tubes3[5] = (Tube3){{RED, YELLOW, ORANGE, BLUE}, 4, {170, 400}, false};
    tubes3[6] = (Tube3){{PINK, PURPLE, PURPLE, PURPLE}, 4, {310, 400}, false};
    tubes3[7] = (Tube3){{0}, 0, {450, 400}, false};
    tubes3[8] = (Tube3){{0}, 0, {590, 400}, false};
    
        gameWon = false;   
    }
    }
    
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
       Vector2 mousePos = GetMousePosition();                     
    if(CheckCollisionPointRec(mousePos, (Rectangle){40,10,20,20})){
        
    tubes3[0] = (Tube3){{PURPLE, PINK, BLUE,YELLOW}, 4, {100, 300}, false};
    tubes3[1] = (Tube3){{PINK, YELLOW, PINK, ORANGE}, 4, {240, 300}, false};
    tubes3[2] = (Tube3){{RED, GREEN, BLUE, RED}, 4, {380, 300}, false};
    tubes3[3] = (Tube3){{YELLOW, GREEN, ORANGE, GREEN}, 4, {520, 300}, false};
    tubes3[4] = (Tube3){{BLUE, ORANGE, GREEN, RED}, 4, {660, 300}, false};
    tubes3[5] = (Tube3){{RED, YELLOW, ORANGE, BLUE}, 4, {170, 400}, false};
    tubes3[6] = (Tube3){{PINK, PURPLE, PURPLE, PURPLE}, 4, {310, 400}, false};
    tubes3[7] = (Tube3){{0}, 0, {450, 400}, false};
    tubes3[8] = (Tube3){{0}, 0, {590, 400}, false};
    
    }
    }
    // "BACK" butonu çizimi
           DrawRectangle(10, 10, 20, 20, RED);
           DrawText("<-",15,15, 5, RAYWHITE);

           DrawRectangle(40,10,20,20,RED);
           DrawText("R",45,15, 5, RAYWHITE);           


        if(gameWon3==false){
            DrawText("Water Sort Puzzle Game", 150, 20, 40, PURPLE);
            DrawText("Episode 3", 300, 50, 40, PINK);
        }
        
        // Oyun ekranı
    if (!gameWon3 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        int clickedTubeIndex = GetClickedTubeIndex3(mousePos);
        if (selectedTubeIndex == -1 && clickedTubeIndex != -1) {
            tubes3[clickedTubeIndex].selected = true;
            selectedTubeIndex = clickedTubeIndex;
        } else if (clickedTubeIndex != -1 && selectedTubeIndex != clickedTubeIndex) {
            PourSameColorLiquid3(selectedTubeIndex, clickedTubeIndex, GetSameColorLiquidCount3(selectedTubeIndex));
            tubes3[selectedTubeIndex].selected = false;
            selectedTubeIndex = -1;
            if (CheckWinCondition3()) {
                gameWon3 = true;
            }
        }
    }

    if (gameWon3) {
        // Oyun kazanıldı ve geçiş ekranı
        ClearBackground(RAYWHITE);

        DrawText("Congratulations! You won!", 120, 200, 40, GREEN);

        DrawRectangle(10, 10, 60, 30, GREEN);
        DrawText("BACK", 20, 18, 16, WHITE);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            if (CheckCollisionPointRec(mousePos, (Rectangle){10, 10, 60, 30})) {
                currentMenuState = PLAY;
                gameWon3 = false;
                tubes3[0] = (Tube3){{PURPLE, PINK, BLUE,YELLOW}, 4, {100, 300}, false};
                tubes3[1] = (Tube3){{PINK, YELLOW, PINK, ORANGE}, 4, {240, 300}, false};
                tubes3[2] = (Tube3){{RED, GREEN, BLUE, RED}, 4, {380, 300}, false};
                tubes3[3] = (Tube3){{YELLOW, GREEN, ORANGE, GREEN}, 4, {520, 300}, false};
                tubes3[4] = (Tube3){{BLUE, ORANGE, GREEN, RED}, 4, {660, 300}, false};
                tubes3[5] = (Tube3){{RED, YELLOW, ORANGE, BLUE}, 4, {170, 400}, false};
                tubes3[6] = (Tube3){{PINK, PURPLE, PURPLE, PURPLE}, 4, {310, 400}, false};
                tubes3[7] = (Tube3){{0}, 0, {450, 400}, false};
                tubes3[8] = (Tube3){{0}, 0, {590, 400}, false};
            }
        }

    } else {
        // Oyun devam ederken ana oyun ekranı çiziliyor
        for (int i = 0; i < MAX_TUBES3; i++) {
            DrawRectangleLines(tubes3[i].position.x, tubes3[i].position.y - TUBE_HEIGHT3, TUBE_WIDTH3, TUBE_HEIGHT3, BLACK);
        }

        // Tüplerin içine sıvıları çizme
        for (int i = 0; i < MAX_TUBES3; i++) {
            int y = tubes3[i].position.y;
            for (int j = 0; j < tubes3[i].count; j++) {
                DrawRectangle(tubes3[i].position.x, y - 50 * (j + 1), TUBE_WIDTH3, 50, tubes3[i].colors[j]);
            }
            if (tubes3[i].count == 0) {
                DrawRectangleLines(tubes3[i].position.x, y - TUBE_HEIGHT3, TUBE_WIDTH3, TUBE_HEIGHT3, GRAY);
            }
            if (i == selectedTubeIndex) {
                // Seçili tüpün etrafına kalın çerçeve çiz
                DrawRectangleLinesEx((Rectangle){tubes3[i].position.x - 3, y - 203, 46, 206}, TUBE_SELECTION_THICKNESS3, TUBE_SELECTION_COLOR3);
            }
        }
    }
    
    break;
    
            case HOW_TO_PLAY:        // Oyun nasıl oynanır ekranı
    

        ClearBackground(RAYWHITE);

               // "BACK" butonu çizimi
                DrawRectangle(10, 10, 20, 20, RED);
                DrawText("<-",15,15, 5, RAYWHITE);
              
                DrawText("HOW TO PLAY AND RULES!",100, 20, 40, RED);
                DrawText(" It is a basic water sort puzzle game, If the player\n\n collects the same liquids in the same tube, player\n\n wins the game.", 50, 100, 27, BLACK);
                DrawText("Player click MOUSE LEFT BUTTON to select\n\n a source tube\n\nPlayer click MOUSE LEFT BUTTON to select\n\n a target tube\n\n ", 50, 200, 27, BLACK);
                DrawText("Player click R button to RESTART the level", 50, 325, 27, BLACK);
    
    
               // Fare tıklamalarını ve tıklama pozisyonunu al
               if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                  Vector2 mousePos = GetMousePosition();
    
       
              
               // "BACK" butonuna tıklama
                 if (CheckCollisionPointRec(mousePos, (Rectangle){10, 10, 20, 20})) {
                    currentMenuState = MAIN_MENU;  
                 }
               }
        
                break;
            
            case EXIT:
                // Oyundan çıkış yapılıyor
                CloseWindow();
                break;
        }
        EndDrawing();
    }
    
    return 0;
}