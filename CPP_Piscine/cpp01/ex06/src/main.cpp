/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibault <thibault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:08:58 by thibault          #+#    #+#             */
/*   Updated: 2023/11/29 18:42:34 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << YELLOW "[Usage] " << argv[0] << " <log_level>" EOC << std::endl;
        return 1;
    }

    Harl harl;
    std::string logLevel = argv[1];
    harl.complain(logLevel);

    return 0;
}