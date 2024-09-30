# Medieval Survival Game

**Medieval Survival Game** is an immersive, C++-based project developed using Unreal Engine, set in a richly detailed medieval world. Players must navigate the challenges of survival by managing resources, crafting tools, and engaging with dynamic gameplay systems.

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Gameplay Mechanics](#gameplay-mechanics)
- [Installation](#installation)
- [Usage](#usage)
- [System Requirements](#system-requirements)
- [Technologies Used](#technologies-used)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)
- [Contact](#contact)

## Project Overview

Medieval Survival Game offers players an authentic survival experience in a medieval setting. Through meticulous inventory management, crafting systems, and strategic gameplay, players must overcome environmental challenges, defend against threats, and thrive in a hostile world.

## Features

- **Comprehensive Inventory System:** Manage items efficiently with support for adding, removing, and organizing items within a dynamic inventory structure.
- **Crafting Mechanics:** Create a variety of tools, weapons, and consumables using gathered resources.
- **Gameplay Tags and Enums:** Utilize a robust tagging system combined with enums to categorize items, manage states, and facilitate dynamic interactions.
- **Server-Side Authority:** Ensure game integrity and prevent cheating through server-authoritative inventory management.
- **Dynamic Tag-Based Filtering:** Easily query and filter items using Gameplay Tags for enhanced gameplay mechanics.
- **Extensible Data Management:** Implement Data Registry for centralized and flexible data handling, enabling easy updates and scalability.
- **Modular Design:** Build upon a solid foundation with well-organized code, making future expansions and feature additions straightforward.

## Gameplay Mechanics

### Inventory Management

Players can collect and store various items, each categorized by type, rarity, and effects. The inventory system checks for available slots, ensuring efficient space utilization and preventing item duplication.

### Crafting System

Gather resources from the environment to craft essential tools and weapons. The crafting system supports multiple skills and stations, allowing players to create a wide range of items to aid in their survival.

### Item States and Effects

Items possess states such as durability, which degrade with use. Additionally, items can have various effects like healing, damage boosts, or defensive capabilities, enhancing the player's abilities and strategies.

### Server-Side Authority

All critical actions, such as adding or removing items from the inventory, are handled on the server to maintain game integrity and prevent client-side manipulation.

## Installation

### Prerequisites

- **Unreal Engine 4.27** or later.
- **Visual Studio 2019** or later (for Windows) / **Xcode** (for macOS).

### Steps

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/yourusername/medieval-survival-game.git
