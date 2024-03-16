/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:04:24 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 16:41:22 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "../includes/AMateria.hpp"
#include "../includes/IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

private:

	AMateria *learnedMaterias[4];
	int numLearned;

public:

	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource();

	void learnMateria(AMateria *m);
	AMateria *createMateria(const std::string &type);

};

#endif