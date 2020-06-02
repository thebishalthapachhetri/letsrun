#include "animated_texture.h"
#include "texture.h"

Animated_Texture::Animated_Texture(std::string id, std::string path, SDL_Renderer* renderer, int frame_count, Uint32 frame_duration_milliseconds)
	: Texture(id, path, renderer)
{
	_frame_count                 = frame_count;
	_current_frame               = 0;
	_frame_duration_milliseconds = frame_duration_milliseconds;
	_total_time_milliseconds     = frame_duration_milliseconds;
}

Animated_Texture::~Animated_Texture()
{
}

void Animated_Texture::update_frame(Uint32 milliseconds_to_simulate)
{
	_total_time_milliseconds += milliseconds_to_simulate;
	_current_frame           = (_total_time_milliseconds / _frame_duration_milliseconds) % _frame_count;
}

void Animated_Texture::render(SDL_Renderer* renderer, SDL_Rect*, SDL_Rect* destination, SDL_RendererFlip flip)
{
	int texture_w = 0;
	int texture_h = 0;
	const int query_texture_result = SDL_QueryTexture(data(), nullptr, nullptr, &texture_w, &texture_h);

	const int frame_w = texture_w / _frame_count;

	SDL_Rect frame_clip;
	frame_clip.x = _current_frame * frame_w;
	frame_clip.y = 0;
	frame_clip.w = frame_w;
	frame_clip.h = texture_h;

	Texture::render(renderer, &frame_clip, destination, flip);
}