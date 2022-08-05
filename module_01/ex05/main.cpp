#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl h;

	if (argc > 1)
		h.complain(argv[1]);

	// h.complain("DEBUG");
	// h.complain("INFO");
	// h.complain("WARNING");
	// h.complain("ERROR");

	return (0);
}
