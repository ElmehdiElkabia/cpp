#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->slot[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy.slot[i] != NULL)
			this->slot[i] = copy.slot[i]->clone();
		else
			this->slot[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->slot[i] != NULL)
			{
				delete this->slot[i];
				this->slot[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (copy.slot[i] != NULL)
				this->slot[i] = copy.slot[i]->clone();
			else
				this->slot[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i] != NULL)
		{
			delete this->slot[i];
			this->slot[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i] == NULL)
		{
			this->slot[i] = m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i] != NULL && this->slot[i]->getType() == type)
			return (slot[i]->clone());
	}
	return (0);
}