/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:03:39 by thibault          #+#    #+#             */
/*   Updated: 2023/12/07 01:04:06 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "../includes/AMateria.hpp"

class IMateriaSource {

public:
	virtual ~IMateriaSource() {}

	virtual void learnMateria(AMateria *m) = 0;
	virtual AMateria *createMateria(const std::string &type) = 0;

};

#endif