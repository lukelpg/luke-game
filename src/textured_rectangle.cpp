#include "texutred_rectangle.h"
#include "game_info.h"

TexturedRectangle::TexturedRectangle(SDL_Renderer* renderer, const char* file_path) {
    SDL_Surface* surface = IMG_Load(file_path);
	if (surface == nullptr) {
        std::cerr << "IMG_Load error: " << IMG_GetError() << std::endl;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    gamePositionX = 0;
    gamePositionY = 0;
}


void TexturedRectangle::setRectangleProperties(int x, int y, int w, int h){
    position.x = x;
    position.y = y;
	position.w = w;
	position.h = h;
}
    
bool TexturedRectangle::isClicked(int mouseX, int mouseY) {
    return (mouseX >= position.x && mouseX <= position.x + position.w &&
            mouseY >= position.y && mouseY <= position.y + position.h);
}


void TexturedRectangle::update(InputState* input_state) {

}


void TexturedRectangle::render(SDL_Renderer* renderer, GameInfo* gameInfo) {
    SDL_Rect screenPosition = position;

    // THE ISSUE IS HERE
    std::cout << " rrright here 1 " << std::endl;
    position.x += gameInfo->gamePositionX; 
    position.y += gameInfo->gamePositionY;
    std::cout << " rrright here 2 " << std::endl;

    SDL_RenderCopy(renderer, texture, NULL, &screenPosition);
}


TexturedRectangle::~TexturedRectangle() {
    SDL_DestroyTexture(texture);
}


