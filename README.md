
# CyberLab: SFML Quiz Game

A story-driven, single-window quiz game written in C++ using the SFML library. The player is an IT student trapped in a university computer lab by a rogue AI virus named **MalX**. To escape, the player must progress through a sequence of screens — a home page, a narrative story page, and three quiz levels — answering multiple-choice cybersecurity questions loaded from an external text file.

This project was built to demonstrate strong Object-Oriented Programming (OOP) principles, polymorphism, and game-loop architecture in C++.

## 🎮 Features

*   **Polymorphic Screen Management:** A robust state-machine architecture using an abstract `Level` base class to transition smoothly between the Home, Story, and Quiz screens.
*   **Dynamic Question Parsing:** The game reads multiple-choice questions dynamically from an external `questions1.txt` file, parsing blocks of text into a `QuestionBank` queue.
*   **Typewriter Text Animation:** Narrative text and questions are revealed character-by-character with synchronized looping audio, skippable by the player.
*   **Interactive UI Elements:** A custom reusable `Button` class handles hover states, mouse clicks, and UI feedback.
*   **Countdown Timer:** An 8-minute per-level countdown that turns red and pulses visually when time is running low.
*   **Custom Asset Pipeline:** A template-based asset loader handles textures, fonts, and sound buffers.

## 🛠️ Technologies Used

*   **Language:** C++
*   **Graphics & Audio:** SFML (Simple and Fast Multimedia Library)
*   **Architecture:** Object-Oriented Programming (Inheritance, Abstraction, Encapsulation)
*   **Data Structures:** `std::queue` for question progression, `std::vector` for tracking player outcomes.

## 📸 Screenshots
<img width="1280" height="694" alt="endgame" src="https://github.com/user-attachments/assets/81fa14a4-2eaa-4541-a679-a964a6159230" />
<img width="1280" height="674" alt="feedback_summary" src="https://github.com/user-attachments/assets/1a8b8e9e-6848-4c65-bba2-46bd666bbaf7" />
<img width="1280" height="700" alt="game_inprogress" src="https://github.com/user-attachments/assets/985e0721-6599-4a73-8941-bb393b0334ac" />
<img width="1280" height="698" alt="in_progress_II" src="https://github.com/user-attachments/assets/ca399d5c-e8c0-4ff5-9f55-9f03057f295c" />
<img width="1280" height="677" alt="Level_Intro" src="https://github.com/user-attachments/assets/22919aca-0eda-46f0-bac4-92b549892e59" />
<img width="1280" height="700" alt="start" src="https://github.com/user-attachments/assets/4abdb18d-7c5e-4c3e-af59-40db3ce4fd2d" />



## 🧠 Architecture & OOP Highlights

*   **Abstraction & Polymorphism:** The `Level` class declares pure virtual functions (`handleEvent`, `setSprites`), allowing the main `Game` loop to dispatch virtual calls without knowing the specific screen type.
*   **Inheritance:** Eight distinct screen classes (`Home`, `StoryPage`, `LevelOne`, etc.) inherit from the `Level` base class.
*   **Encapsulation:** The `QuestionBank::Question` is a private inner class, meaning question data can only be accessed safely through the `QuestionBank`'s public interface.
*   **Composition:** UI elements like `Button` are composed inside the `Level` classes, keeping rendering logic clean and separated.

## 🚀 How to Build and Run

### Prerequisites
To run this project, you will need:
1. A C++ compiler (Visual Studio with MSVC is recommended).
2. **SFML Library** (Graphics, Window, System, and Audio modules).
3. The required runtime assets (images, fonts, and `.wav` files) are included in the repository.

### Setup Instructions (Visual Studio)
1. Clone this repository to your local machine.
2. Open the `.sln` file (or create a new C++ project and add all `.cpp` and `.h` files).
3. Link the SFML libraries:
   *   Go to **Project Properties** > **C/C++** > **General** > **Additional Include Directories** and add the path to your SFML `include` folder.
   *   Go to **Linker** > **General** > **Additional Library Directories** and add the path to your SFML `lib` folder.
   *   Go to **Linker** > **Input** > **Additional Dependencies** and add: `sfml-graphics.lib;sfml-window.lib;sfml-system.lib;sfml-audio.lib;`
4. Make sure you copy the required SFML `.dll` files (e.g., `sfml-graphics-2.dll`, `openal32.dll`) into the same folder as your compiled `.exe`.
5. Build and run!

## 🎮 Controls

*   **Left Mouse Click:** Interact with UI buttons (Start, Next, Answer A-D).
*   **Enter Key:** Advance to the next question / skip typing animation.
*   **Escape:** Close the game window.
