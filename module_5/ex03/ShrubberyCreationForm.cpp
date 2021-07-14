#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
	set_target("default");
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	set_target(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form(copy)
{
	set_target(copy.get_target());
}

ShrubberyCreationForm::~ShrubberyCreationForm() {};

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
		Form::operator = (copy);
		set_target(copy.get_target());
	}
	return (*this);
};

void ShrubberyCreationForm::action(void) const
{
	std::ofstream shrubbery(get_target() + "_shrubbery", std::ofstream::trunc);
	std::string tree = \
	"             \n"
"              * *    \n"
"           *    *  *\n"
"      *  *    *     *  *\n"
"     *     *    *  *    *\n"
" * *   *    *    *    *   *\n"
" *     *  *    * * .#  *   *\n"
" *   *     * #.  .# *   *\n"
"  *     #.  #: # * *    *\n"
" *   * * #. ##       *\n"
"   *       ###\n"
"             ##\n"
"              ##.\n"
"              .##:\n"
"              :###\n"
"              ;###\n"
"            ,####.\n"
"           .######.\n";
	if (shrubbery.is_open())
		shrubbery << tree;
	shrubbery.close();
}