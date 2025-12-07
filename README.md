# Fun with Video Games & UX Design (C++ Console Application)

##   Project Overview

This C++ console application explores **video game preferences and user experience (UX)** concepts through interactive user input, calculations, and formatted output.  

The program collects information about a user’s favorite video game, analyzes its value based on cost and playtime, gathers ratings for different game aspects, and produces a formatted summary report.

This project was created as part of a programming assignment focusing on:
- User input validation
- Structured programming
- Enums and structs
- File I/O
- Loops and selection statements
- Console formatting and color

---

##  Assignment Requirements Coverage

###  User Input
- Collects **mixed data types**:
  - `string` (favorite game, character, platform)
  - `int` (age, hours played, ratings)
  - `double` (game price, value per hour)
- All input is **validated using loops** to prevent invalid data.
- Inputs are gathered using a dedicated function.

---

###  Structures (Structs)
A `UserInfo` struct is used to group related user data:

```cpp
struct UserInfo {
    string videoGame;
    string favoriteCharacter;
    string gamingPlatform;
    int age;
};
