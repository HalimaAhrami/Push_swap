
---

# 🧮 Push_swap

## 📘 Overview

**Push_swap** is a sorting algorithm project designed to improve your understanding of algorithmic optimization and data manipulation.
You must sort a stack of integers using only a limited set of operations and achieve the **lowest possible number of moves**.

---

## 🎯 Objectives

* Understand **algorithmic complexity** and efficiency.
* Manipulate **data structures** (mainly stacks).
* Practice **problem decomposition** and **optimization**.
* Write clean, efficient, and memory-safe C code.
* Build and use **Makefiles** and **libft**.

Sorting is simple — sorting **with restrictions and minimal operations** is the real challenge.

---

## ⚙️ Program Structure

### Program Name

`push_swap`

### Turn-in Files

`Makefile`, `*.h`, `*.c`

### Compilation

* Must compile with flags: `-Wall -Wextra -Werror`
* Must not relink unnecessarily.
* Must include the rules:

  * `NAME`
  * `all`
  * `clean`
  * `fclean`
  * `re`

### Allowed External Functions

* `read`, `write`, `malloc`, `free`, `exit`
* `ft_printf` or any equivalent **you coded**
* **Libft is authorized**

### Forbidden

* Global variables
* Any functions or libraries not listed above

---

## 🧱 The Rules

* You have **two stacks**:

  * `a`: contains a list of integers (can be negative or positive, unique)
  * `b`: starts empty

* Your goal is to sort the integers in **stack a in ascending order** using a limited set of operations.

---

## 🧩 Allowed Operations

| Operation | Description                                           |
| --------- | ----------------------------------------------------- |
| `sa`      | Swap the first two elements at the top of **stack a** |
| `sb`      | Swap the first two elements at the top of **stack b** |
| `ss`      | Perform `sa` and `sb` at the same time                |
| `pa`      | Push the top element of **b** onto **a**              |
| `pb`      | Push the top element of **a** onto **b**              |
| `ra`      | Rotate **a** upward (first element becomes last)      |
| `rb`      | Rotate **b** upward                                   |
| `rr`      | Perform `ra` and `rb` at the same time                |
| `rra`     | Reverse rotate **a** (last element becomes first)     |
| `rrb`     | Reverse rotate **b**                                  |
| `rrr`     | Perform `rra` and `rrb` at the same time              |

Your program must print the list of operations (each separated by a newline) that sorts the given list with the **fewest possible moves**.

---

## 🧠 Behavior & Requirements

* The program takes the stack `a` as arguments — integers separated by spaces.
* The first argument is the **top** of the stack.
* It must output the **shortest sequence of valid operations** needed to sort the numbers.
* Each instruction must be printed followed by a `\n` (nothing else).
* If no parameters are provided, the program must display nothing and exit.
* On error, display:

  ```
  Error
  ```

  on the standard error.

### Examples of errors:

* Non-integer arguments
* Arguments outside integer range
* Duplicate numbers

---

## 🧮 Example Execution

```
$> ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

```
$> ./push_swap 0 one 2 3
Error
```

---

## 📊 Benchmarks

To fully validate the mandatory part, your program must perform efficiently according to the following benchmarks:

| Test        | Requirement               |
| ----------- | ------------------------- |
| 100 numbers | under **700 operations**  |
| 500 numbers | under **5500 operations** |

For minimal validation (≈80%):

* 100 numbers: < 1100 operations
* 500 numbers: < 8500 operations
  or
* 100 numbers: < 1300 operations
* 500 numbers: < 5500 operations

These limits are verified during evaluation.

---

## 🧩 Testing & Evaluation

During evaluation, your program will be tested using a **checker** binary to verify that your instructions correctly sort the stack.

Example:

```
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```

Outputs the number of operations.

```
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_OS $ARG
```

If the output is `OK`, your sorting is correct.
If it’s `KO`, your sequence failed to sort properly.

---

## ⚡ Error Handling Summary

| Case             | Output            |
| ---------------- | ----------------- |
| Invalid integer  | `Error`           |
| Duplicate number | `Error`           |
| Non-integer      | `Error`           |
| No argument      | *Nothing printed* |

---

## 🧾 Evaluation Tips

* Ensure **no memory leaks** — check with `valgrind`.
* **Free all mallocs** before exit.
* **No global variables.**
* Use optimized algorithms depending on input size (e.g., radix sort, chunk-based, insertion sort for small stacks).
* **Efficiency matters:** fewer operations = higher score.
* Be prepared to **explain your algorithm** during evaluation.

---

## 🧭 Summary Table

| Item              | Description                        |
| ----------------- | ---------------------------------- |
| Program name      | `push_swap`                        |
| Input             | List of integers                   |
| Output            | List of operations                 |
| Goal              | Sort stack A in ascending order    |
| Data structures   | Two stacks (`a`, `b`)              |
| Allowed functions | Standard C + libft                 |
| Error output      | `"Error\n"`                        |
| Main challenge    | Sorting with the fewest operations |

---
