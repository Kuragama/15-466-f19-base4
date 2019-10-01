#pragma once

#include "Mode.hpp"
#include "BirdLevel.hpp"
#include "DrawLines.hpp"

#include <memory>

struct BirdMode : Mode {
	BirdMode(BirdLevel const &level);
	virtual ~BirdMode();

	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//The (starting shape of the) level:
	BirdLevel const &start;

	//The (active, being-played) level:
	void restart();
	BirdLevel level;
	bool won = false;

	//Current control signals:
	struct {
		bool forward = false;
		bool backward = false;
		bool left = false;
		bool right = false;
		bool jump = false;
	} controls;

	//fly around for collsion debug:
	bool DEBUG_fly = false;
	bool DEBUG_show_geometry = false;
	bool DEBUG_show_collision = false;

	//some debug drawing done during update:
	std::unique_ptr< DrawLines > DEBUG_draw_lines;
};
