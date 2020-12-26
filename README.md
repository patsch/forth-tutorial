# forth-tutorial
A miniature implementation of Forth in C and an introduction to stack and dictionary data types

## Abstract

This projects implements the beginning of a stack based programming language like **Forth** using **C** - it serves as a starting point for a more full blown Forth implementation and was created to illustrate some key concepts of Forth and the **Stack** and **Dictionary** data type.

## Forth & Stacks

Forth is often used to introduce key principles of a programming language to Computer Science students because its processing mechanism is both very simple and powerful.

Forths key data type is a **stack**, in other contexts also called a **LIFO** (Last In First Out) type. I like to think of the process of emptying a dish washer - you take out a plate, place it on top of the kitchen bench, then take out the next plate and put it on top of the first plate - and so on.

You end up with a **stack** of plates, and any new plate always goes on top - that's the basic mechanism of a stack. You can either **push** a new element (plate) on top, or **pop** the topmost element off it - that's it ! Very simple, hence very fast, and very efficient for certain types of problems.

![Stack of Plates](https://github.com/patsch/forth-tutorial/blob/main/stack_of_plates.png)

The elements on a stack can really be anything, but for our Tutorial we accept either values (integer numbers), or some basic operators (like **+**).

The way Forth works is that if you push an operator on the stack, depending on the arity of the operator (i.e. whether it needs one, two or more arguments), it then pulls the required number of arguments off the stack, performs the operation, and pushes the result back onto the stack. That's the basic operating principle of Forth.

For example: If you push **1 2 +** onto the stack in Forth, the result is **3** being left on the stack.

## Dictionary

This tutorial will also implement a basic **Dictionary** data type, to hold the available **operations**. 

A dictionary, sometimes also called a **Hash**, is a very versatile collection data type. It's called a collection data type because, different to say an Integer or a Character, it manages a number of elements/objects - similar to a linked list and an Array.

In fact, a **Dictionary** can be thought of as a generalised version of an **Array**. An array allows you to look up an element by it's index (offset) - a positive integer number starting from 0.

A **dictionary** also allows you to look up an element - but your totally free on what you want to use to perform the lookup. In many cases, a **String** is used, which allows you ask a dictionary to .... **give me the element you have for the lookup string 'add'**.

We are using a dictionary in this tutorial to look up details of the available **operations** given the keyword for the operation, i.e. **+** for addition.

## Implementation

The Forth tutorial except all stack elements to be presented on the command line - you can easily change that in the code so that instead stack elements can be typed in interactively.

To start with, we initialize the **commandDictionary** with the available commands. The **commandDictionary** is internally also implemented as a stack, and the **dictionary** functionality is provided via some helper functions like dictLookup, dictAdd and dictInit. 

The elements of the command dictionary are of type **Entry** - which is a struct that contains the keyword, a description, an enum for the operation (for future use) - and a pointer to a function (a piece of code) that actually performs the operation. If you've never used function pointers here is a simple example on how they can be used.

The main method then simply goes through the parameters provided on the command line and for each of them checks if they are a valid command by performing a lookup in the command dictionary.

If the lookup is successful, we call the associated operation via the function pointer, which performs the requested function, manipulating the existing stack in the process. Each operation performs some sanity checks to make sure the stack is valid - for example, you cannot perform the **+** operation unless you have two elements on the stack you can actually add together.

If the command dictionary lookup fails, we check whether the given value is a pure number - if so, we accept it and push it onto our stack. If it is not a pure number - and we check for that by converting the given value to a number and then back to a string, then see if we end up with the same value again - then we raise an error, as the input is invalid in that case.

Once the processing of the input value is completed, the program shows the resulting stack, then exits.



