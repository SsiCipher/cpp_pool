#ifndef CLAP_HPP
# define CLAP_HPP

# include <iostream>
# include <string>

class Clap
{

	public:

		Clap();
		Clap( Clap const & src );
		~Clap();

		Clap &		operator=( Clap const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Clap const & i );

#endif /* ************************************************************ CLAP_H */
