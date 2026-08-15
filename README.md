# Module CPP 05

Ce module explore en profondeur la gestion des erreurs en C++ grâce aux **Exceptions**, ainsi que les notions de **classes abstraites** et d'héritage avancé.

## 1. Les Exceptions (`try`, `catch`, `throw`)
Avant, pour gérer une erreur, on retournait des codes spécifiques (ex: `return -1;`). 
Avec les exceptions, on peut directement "jeter" (`throw`) une erreur lorsqu'un comportement inattendu survient (comme instancier un `Bureaucrat` avec une note < 1).

**Comment ça marche ?**
- **throw** : Lève l'exception et interrompt le cours normal du programme.
- **try** : Un bloc de code que l'on essaie d'exécuter, en sachant qu'il peut "jeter" une erreur.
- **catch** : "Attrape" l'erreur levée par le bloc `try` pour la traiter proprement sans faire crasher le programme.

Dans ce module, nous avons créé des exceptions personnalisées en héritant de `std::exception` et en redéfinissant la méthode `what()` pour renvoyer un message précis (ex: `Bureaucrat::GradeTooHighException`).

## 2. Le mot-clé `const` dans les opérateurs de flux
L'opérateur d'affichage `operator<<` doit toujours prendre une référence constante de l'objet à imprimer (`const Bureaucrat& b`). 
Si l'on ne met pas `const`, le compilateur refusera d'imprimer des objets temporaires ou des objets instanciés en tant que `const` (par exemple : `std::cout << Bureaucrat("Bob", 1);`). Nous avons donc corrigé cela dans tous les exercices de ce module !

## 3. Formulaires Abstraits et Méthodes Virtuelles Pures (`ex02`)
Dans l'exercice 02, `AForm` est une classe **abstraite**. Cela signifie qu'elle sert de "moule" pour ses classes dérivées (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) mais ne peut pas être instanciée directement.
Pour la rendre abstraite, sa méthode d'exécution est déclarée purement virtuelle :
```cpp
virtual void execute(Bureaucrat const & executor) const = 0;
```

## 4. Constructeurs de Recopie et Classes Dérivées (`ex02` & `ex03`)
Une erreur très commune en C++ concerne les copies de classes enfants.
Lorsqu'on copie un objet enfant (ex: `ShrubberyCreationForm`), il faut impérativement indiquer au compilateur de copier également les variables de sa classe mère (`AForm`) !
```cpp
// Constructeur de recopie : on appelle le constructeur de recopie de AForm !
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copied): AForm(copied)
{
    this->_target = copied._target;
}

// Opérateur d'assignation : on appelle explicitement l'opérateur= de AForm !
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& base)
{
    if (this != &base)
    {
        AForm::operator=(base);
        this->_target = base._target;
    }
    return *this;
}
```
Si l'on oublie l'appel à la classe mère, alors seul l'attribut `_target` sera copié, et l'état `_isSigned` sera réinitialisé à `false` lors de la copie ! Nous avons consolidé ces appels cruciaux.
