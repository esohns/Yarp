// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//

#ifndef CXX_____RPG_COMMON_XML_PARSER_BASE_H
#define CXX_____RPG_COMMON_XML_PARSER_BASE_H

#include "rpg_common_XML_types.h"

class RPG_Common_Attribute_Type_pimpl: public virtual RPG_Common_Attribute_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Common_Attribute
  post_RPG_Common_Attribute_Type ();
};

class RPG_Common_SavingThrow_Type_pimpl: public virtual RPG_Common_SavingThrow_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Common_SavingThrow
  post_RPG_Common_SavingThrow_Type ();
};

class RPG_Common_SavingThrowUnion_Type_pimpl: public virtual RPG_Common_SavingThrowUnion_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  _characters (const ::xml_schema::ro_string&);

  virtual RPG_Common_SavingThrowUnion
  post_RPG_Common_SavingThrowUnion_Type ();
};

#endif // CXX_____RPG_COMMON_XML_PARSER_BASE_H
