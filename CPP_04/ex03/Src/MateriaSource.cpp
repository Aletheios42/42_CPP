#include "../Inc/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		_learned[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const &m)
{
	*this = m;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &m)
{
	if (this != &m)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (_learned[i])
				delete _learned[i];
			_learned[i] = m._learned[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_learned[i])
			delete _learned[i];
	}
}

void	MateriaSource::learnMateria(AMateria *a)
{
	int		check = 0;
	size_t	i;
	for (i = 0; i < 4; i++)
	{
		if (!_learned[i])
		{
			check = 1;
			break ;
		}
	}
	if (!check)
	{
		std::cout << "Memory is full!" << std::endl;
		return ;
	}
	_learned[i] = a;
}

AMateria * MateriaSource::createMateria(std::string const & type)
{
	size_t i;
	for (i = 0; i < 4; i++)
	{
		if (_learned[i]->getType() == type)
			break ;
	}
	if (i == 4)
	{
		std::cout << type << " is unknown." << std::endl;
		return NULL;
	}
	return (_learned[i]->clone());
}
