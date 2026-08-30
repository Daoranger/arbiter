![](assets/arbiter_logo.png)

## Overview
**Arbiter** is a 2D game engine focused on game AI. Arbiter can be used to create NPCs using **state machines**, **behavior trees*, *utility AI*, **GOAP* and more.

## Arbiter Style Guides
* Classes/structs/methods: PascalCase
* Namespaces: lowercase (e.g. arbiter)
* Member variables: m_camelCase (e.g. m_window)
* Local variables/parameters: camelCase
* Headers: #pragma once
* Braces: Allman (new-line)

1. The file's own corresponding header (e.g. `Application.cpp`)
2. A blank line
3. C++ standard library headers (e.g. `<vector>`, `<iostream>`)
4. A blank line
5. Other libraries' header (e.g. `<SFML/Graphics.hpp>`)
6. A blank line
7. Arbiter's own headers (e.g. `"Arbiter/ECS/Entity.h"`)