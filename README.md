# forth-tutorial
A miniature implementation of Forth in C and an introduction to stack and dictionary data types

## Abstract

This projects implements the beginning of a stack based programming language like **Forth** using **C** - it serves as a starting point for a more full blown Forth implementation and was created to illustrate some key concepts of Forth and the **Stack** and **Dictionary** data type.

## Forth

Forth is often used to introduce key principles of a programming language to Computer Science students because its processing mechanism is both very simple and powerful.

Forths key data type is a **stack**, in other contexts also called a **LIFO** (Last In First Out) type. I like to think of the process of emptying a dish washer - you take out a plate, place it on top of the kitchen bench, then take out the next plate and put it on top of the first plate - and so on.

You end up with a **stack** of plates, and any new plate always goes on top - that's the basic mechanism of a stack. You can either **push** a new element (plate) on top, or **pop** the topmost element off it - that's it ! Very simple, hence very fast, and very efficient for certain types of problems.

![Stack of Plates](https://github.com/patsch/forth-tutorial/blob/main/stack_of_plates.png)

The elements on a stack can really be anything, but for our Tutorial we accept either values (integer numbers), or some basic operators (like **+**).

The way Forth works is that if you push an operator on the stack, depending on the arity of the operator (i.e. whether it needs one, two or more arguments), it then pulls the required number of arguments off the stack, performs the operation, and pushes the result back onto the stack. That's the basic operating principle of Forth.

For example: If you push **1 2 +** onto the stack in Forth, the result is **3** being left on the stack.


