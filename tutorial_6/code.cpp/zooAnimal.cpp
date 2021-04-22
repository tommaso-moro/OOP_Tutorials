#include<iostream>

template<class weightType, class cageType>
class ZooAnimal
   {
    private:
      char *name;
      cageType cageNumber;
      int weightDate;
      weightType weight;
    public:
      ZooAnimal (char*, cageType, int, weightType); // constructor function
      inline ~ZooAnimal () { delete [] name; }; // destructor function
      void changeWeight (weightType pounds);
      char* reptName ();
      weightType reptWeight ();
      int daysSinceLastWeighed (int today);

   };

   // ---------- the constructor function
   template<class weightType, class cageType>
     ZooAnimal<weightType, cageType>::ZooAnimal(char* who, cageType whichCage, int weighDay, weightType weight)
   {
    char *name = new char[20];
    strcpy (name, who);
    cageNumber = whichCage;
    weightDate = weighDay;
    this->weight = weight;
   }