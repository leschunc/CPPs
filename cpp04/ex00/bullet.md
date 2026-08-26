- a simple base class called Animal.
- It has one protected attribute: std::string type;
- a Dog class that inherits from Animal.
- a Cat class that inherits from Animal.
- These two derived classes must set their type field depending on their name.
- Then, the Dog’s type will be initialized to "Dog", and the Cat’s type will be initialized to "Cat".
- The type of the Animal class can be left empty or set to the value of your choice.
- Every animal must be able to use the member function: makeSound()
- It will print an appropriate sound (cats don’t bark).


Running this code should print the specific sounds of the Dog and Cat classes, not the Animal’s.
```
int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
...
return 0;
}
```
# - To ensure you understood how it works, implement a WrongCat class
that inherits from a WrongAnimal class. If you replace the Animal and the Cat by the wrong ones in the code above, the WrongCat should output the WrongAnimal sound.

---
- Implement and turn in more tests than the ones given above.

- For every exercise, you have to provide the most complete tests you can.
- Constructors and destructors of each class must display specific messages. Don’t use the
same message for all classes.