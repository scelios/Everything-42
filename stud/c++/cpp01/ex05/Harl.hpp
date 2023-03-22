/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:41:19 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/08 16:02:52 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl {
	public:
		Harl();
		~Harl();
		void complain(std::string level );
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif
