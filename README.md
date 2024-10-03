2. **Open the Project:**
   - Launch Unreal Engine and open the `.uproject` file located in the root of the cloned repository.

3. **Install Dependencies:**
   - Ensure all required Unreal Engine plugins (such as Data Registry and Gameplay Tags) are enabled in **Edit > Plugins**.
   - Open **Visual Studio** (or **Xcode** for macOS users) and compile the project by clicking **Build** in the toolbar.

4. **Run the Game:**
   - Once the project is compiled, you can run it from within the Unreal Engine Editor or by packaging it for your target platform.

## Usage

### Inventory System
The inventory system allows players to:
- Add and remove items from their inventory.
- Organize items by category, rarity, or custom tags.
- Utilize items with effects such as healing, damage boosts, or stamina recovery.

### Crafting
- Gather resources such as wood, iron, and herbs.
- Access different crafting stations (e.g., forge, alchemy lab) to create weapons, armor, and consumables.
- Crafting recipes are dynamically loaded from the **Data Registry**, allowing for easy addition of new items without changing the game code.

### Dynamic Gameplay Tags
Gameplay tags are used to manage interactions and filters within the game:
- Items are categorized by tags (e.g., "Weapon", "Consumable", "Resource").
- Tags are used to trigger dynamic game events and behaviors (e.g., when using healing potions, equipping weapons).

## System Requirements

### Minimum Requirements
- **OS**: Windows 10 / macOS 10.14 (Mojave) or later
- **Processor**: Intel Core i5 or AMD equivalent
- **Memory**: 8 GB RAM
- **Graphics**: NVIDIA GTX 960 or equivalent
- **Storage**: 10 GB available space

### Recommended Requirements
- **OS**: Windows 10 / macOS 11 (Big Sur) or later
- **Processor**: Intel Core i7 or AMD equivalent
- **Memory**: 16 GB RAM
- **Graphics**: NVIDIA GTX 1080 or equivalent
- **Storage**: 15 GB available space

## Technologies Used

- **Unreal Engine 5**: Game engine used for development.
- **C++**: Primary programming language for game logic and systems.
- **Blueprints**: Used for rapid prototyping and UI functionality.
- **Gameplay Tags**: For item categorization and dynamic gameplay interactions.
- **Data Registry**: Centralized system for managing data-driven content such as items and crafting recipes.
- **Visual Studio / Xcode**: For code editing and compilation.

## Contributing

We welcome contributions from the community! To contribute:

1. **Fork the repository**.
2. **Create a new branch** for your feature or bug fix:
   ```bash
   git checkout -b feature/new-feature
