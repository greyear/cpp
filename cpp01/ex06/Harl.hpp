//headers

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class	Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		void	complain( std::string level );
		int		filterLevelsAbove( std::string level );
	public:
		Harl();
		void	switchLevels( std::string level );
};

#endif