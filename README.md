# 📇 Contact Manager CLI (C Language)

A simple, interactive command-line Contact Manager written in C.  
This project allows users to manage an in-memory list of contacts, reinforcing foundational C concepts such as arrays, structs, string handling, and command-line interaction.

---

## 🧠 Features

- Add a new contact (name, phone, email)
- Remove an existing contact by name
- Search contacts by name (partial match supported)
- List all current contacts
- Safe, bounds-checked string handling with no dynamic memory or file I/O

---

## 🛠 Tech Stack

- Language: C
- Compilation: GCC or any C99-compatible compiler
- No external libraries

---

## 📥 Installation & Usage

### 1. Compile

```bash
gcc contacts.c -o contacts
```

### 2. Run

```bash
./contacts
```

### 3. Menu Options

```
=== Contact Manager ===
1. Add Contact
2. Remove Contact
3. Search Contact
4. List All Contacts
5. Quit
```

Follow the on-screen prompts to enter data.

---

## 🎯 Learning Goals

This project is designed to help beginners:

- Understand array and struct usage in C
- Practice interactive terminal input with `scanf`
- Safely handle strings using `strncpy` and buffer bounds
- Work with control structures and loops for menu-driven programs

---

## 📜 License

This project is released under the [MIT License](LICENSE).

---

## 🙋‍♂️ Contributing

Contributions welcome! Fork the repo and submit a PR with improvements or enhancements (e.g., dynamic memory, file-based saving, etc).

---

## 🔖 Tags

`C` `CLI` `Array` `Struct` `Beginner` `Contact Manager`
