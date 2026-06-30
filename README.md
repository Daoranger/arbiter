![](assets/arbiter_logo.png)

## Overview
**Arbiter** is a 2D game engine focused on game AI. Arbiter can be used to create NPCs using **state machines**, **behavior trees*, *utility AI*, **GOAP* and more.

## Code Style
Arbiter follows the **[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)** to maintain a consistent, readable, and maintainable codebase.

## Architecture
src/
│
├── ai/
│   ├── behavior_tree/
│   ├── blackboard/
│   ├── fsm/
│   ├── goap/
│   └── utility/
│
├── core/
│   ├── Application.cpp
│   ├── Application.h
│   ├── Input.cpp
│   ├── Input.h
│   ├── Logger.cpp
│   ├── Logger.h
│   ├── Time.cpp
│   ├── Time.h
│   ├── Window.cpp
│   └── Window.h
│
├── ecs/
│   ├── components/
│   ├── systems/
│   ├── Component.h
│   ├── Entity.h
│   ├── Registry.h
│   └── System.h
│
├── editor/
│   ├── panels/
│   ├── Editor.cpp
│   └── Editor.h
│
├── rendering/
│   ├── Camera.cpp
│   ├── Camera.h
│   ├── Renderer.cpp
│   ├── Renderer.h
│   ├── Sprite.cpp
│   ├── Sprite.h
│   ├── Texture.cpp
│   └── Texture.h
│
├── scene/
│   ├── Scene.cpp
│   ├── Scene.h
│   ├── SceneManager.cpp
│   └── SceneManager.h
│
└── main.cpp

